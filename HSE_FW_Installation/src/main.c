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

/* Including necessary configuration files. */
#include "Mcal.h"

volatile int exit_code = 0;
/* Variable to count delay cycles */
volatile uint32_t delay;

/* User includes */
#include "Siul2_Port_Ip.h" // For Port initialization
#include "Siul2_Dio_Ip.h"  // For LED control
#include "hse_mu.h"
#include "hse_status_and_errors.h"
#include "hse_host_attrs.h"
#include "hse_common_types.h"


hseSrvResponse_t HSE_GetVersion_Example( hseAttrFwVersion_t *pHseFwVersion );
hseSrvResponse_t HSE_GetVersion_Example(hseAttrFwVersion_t *gHseFwVersion);

/* Variable to store HSE FW version details */
hseAttrFwVersion_t gHseFwVersion = {0U};


/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    /* Write your code here */
	Siul2_Port_Ip_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);

	/* Initialize HSE for secure boot */
	while((HSE_STATUS_INIT_OK & HSE_MU_GetHseStatus(0)) == 0)
	{
		/* HSE initialization failed - enter error state with rapid blinking */
		for (;;)
		{
			/* Fast LED toggle to indicate error */
			Siul2_Dio_Ip_TogglePins(LED_RED_PORT, (1U << LED_RED_PIN));

			/* Short delay for fast blinking */
			for (delay = 0; delay < 100000; delay++)
			{
			}
		}
	}


	/* HSE initialization successful - normal operation */
    for(;;)
    {
    	Siul2_Dio_Ip_TogglePins(LED_GREEN_PORT, (1U << LED_GREEN_PIN));
		/* Simple delay loop */
		for (delay = 0; delay < 1000000; delay++) {}
    }
    return exit_code;
}

/******************************************************************************
 * Function:    HSE_GetVersion_Example
 * Description: Example of HSE service - get FW version
******************************************************************************/
hseSrvResponse_t HSE_GetVersion_Example( hseAttrFwVersion_t *pHseFwVersion )
{
    hseSrvResponse_t srvResponse;
    srvResponse = GetAttr(
            HSE_FW_VERSION_ATTR_ID,
            sizeof(hseAttrFwVersion_t),
            pHseFwVersion );
  //  ASSERT(HSE_SRV_RSP_OK == srvResponse);
    return srvResponse;
}
