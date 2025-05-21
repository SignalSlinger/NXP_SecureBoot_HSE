/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : S32K3XX
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   Copyright 2020 - 2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file main.c
*
*   @addtogroup main_module main module documentation
*   @{
*/

#include "Mcal.h"
#include "Siul2_Port_Ip.h" // For port initialization
#include "Siul2_Dio_Ip.h"  // For LED control
#include "hse_mu.h"
#include "hse_status_and_errors.h"
#include "hse_host_attrs.h"
#include "hse_common_types.h"
#include "hse_host.h"
#include "hse_host_boot.h"
#include "hse_demo_app_services.h"
#include "hse_host_flashSrv.h"
#include <string.h>
#include "flash.h"
#include "pflash.h"
#include "public_key.h"
#include "signature.h"

// Application image region from linker script
extern const uint8_t __APP_IMAGE_START[];
extern const uint8_t __APP_IMAGE_END[];

const uint8_t* pAppBL;
uint32_t AppBL_codeLength;

#define TAG_LENGTH          28U
#define APP_HEADER_LENGTH   0x40U
uint8_t temp_addr_of_app_image[32] = {0};

volatile uint32_t delay = 0;

void ErrorLoop(void)
{
    while (1)
    {
        Siul2_Dio_Ip_TogglePins(LED_RED_PORT, (1U << LED_RED_PIN));
        for (delay = 0; delay < 100000; delay++) {}
    }
}

void SuccessLoop(void)
{
    while (1)
    {
        Siul2_Dio_Ip_TogglePins(LED_GREEN_PORT, (1U << LED_GREEN_PIN));
        for (delay = 0; delay < 1000000; delay++) {}
    }
}

int main(void)
{
    hseSrvResponse_t srvResponse;
    tFLASH_STATUS status;

    // Assign image region from linker script at runtime
    pAppBL = __APP_IMAGE_START;
    AppBL_codeLength = (uint32_t)(__APP_IMAGE_END - __APP_IMAGE_START);

    // Debug: Verify region (remove or set breakpoint for release)
    volatile uint32_t app_start_addr = (uint32_t)pAppBL;
    volatile uint32_t app_end_addr = (uint32_t)__APP_IMAGE_END;
    volatile uint32_t app_len = AppBL_codeLength;

    // Initialize I/O pins (including LEDs)
    Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

    // Wait for HSE to be ready, else RED error blink
    while((HSE_STATUS_INIT_OK & HSE_MU_GetHseStatus(0)) == 0)
    {
        ErrorLoop();
    }

    // Step 1: Generate secure boot tag
    srvResponse = HSE_SignBootImage(pAppBL, TAG_LENGTH, temp_addr_of_app_image);
    if (srvResponse != HSE_SRV_RSP_OK)
    {
        ErrorLoop();
    }

    // Step 2: Write tag to Flash after app image+header
    PFLASH_Unlock(PFLASH_BL1, PFLASH_SS0, PFLASH_S0);
    status = FLASH_Write((uint32_t)pAppBL + APP_HEADER_LENGTH + AppBL_codeLength,
                          temp_addr_of_app_image,
                          TAG_LENGTH);
    if ((status & FLASH_PEG_ST) == 0)
    {
        ErrorLoop();
    }

    // Step 3: Verify tag
    srvResponse = HSE_VerifyBootImage(pAppBL);
    if (srvResponse != HSE_SRV_RSP_OK)
    {
        ErrorLoop();
    }

    // Step 4: Indicate success
    SuccessLoop();

    return 0;
}
