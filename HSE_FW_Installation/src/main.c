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
#include <string.h>
#include "public_key.h"
#include "signature.h"


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

    SuccessLoop();

    return 0;
}
