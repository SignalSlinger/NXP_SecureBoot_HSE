/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P01_D2303_ASR_REL_4_7_REV_0000_20230331
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef PLATFORM_TYPESDEF_H_
#define PLATFORM_TYPESDEF_H_

/**
 *   @file
 *
 *   @addtogroup Platform
 *   @{
 */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "StandardTypes.h"
#include "Platform_Ipw_TypesDef.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CDD_PLATFORM_TYPESDEF_VENDOR_ID                       43
#define CDD_PLATFORM_TYPESDEF_AR_RELEASE_MAJOR_VERSION        4
#define CDD_PLATFORM_TYPESDEF_AR_RELEASE_MINOR_VERSION        7
#define CDD_PLATFORM_TYPESDEF_AR_RELEASE_REVISION_VERSION     0
#define CDD_PLATFORM_TYPESDEF_SW_MAJOR_VERSION                3
#define CDD_PLATFORM_TYPESDEF_SW_MINOR_VERSION                0
#define CDD_PLATFORM_TYPESDEF_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_Ipw_TypesDef header file are of the same vendor */
#if (CDD_PLATFORM_TYPESDEF_VENDOR_ID != CDD_PLATFORM_IPW_TYPESDEF_VENDOR_ID)
    #error "Platform_TypesDef.h and Platform_Ipw_TypesDef.h have different vendor ids"
#endif
/* Check if current file and Platform_Ipw_TypesDef header file are of the same Autosar version */
#if ((CDD_PLATFORM_TYPESDEF_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_TYPESDEF_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_TYPESDEF_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_IPW_TYPESDEF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_TypesDef.h and Platform_Ipw_TypesDef.h are different"
#endif
/* Check if current file and Platform_Ipw_TypesDef header file are of the same Software version */
#if ((CDD_PLATFORM_TYPESDEF_SW_MAJOR_VERSION != CDD_PLATFORM_IPW_TYPESDEF_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_TYPESDEF_SW_MINOR_VERSION != CDD_PLATFORM_IPW_TYPESDEF_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_TYPESDEF_SW_PATCH_VERSION != CDD_PLATFORM_IPW_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_TypesDef.h and Platform_Ipw_TypesDef.h are different"
#endif

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/**
* @brief   All API's having pointers as parameters shall return this error if
*          called with with a NULL value
*
* */
#define PLATFORM_E_PARAM_POINTER                 ((uint8)0x01)

/**
* @brief   Error returned for parameters out of range
*
* */
#define PLATFORM_E_PARAM_OUT_OF_RANGE            ((uint8)0x02)


/**
* @brief    If DET error reporting is enabled, the PLATFORM will check upon each API call
*           if the requested resource is configured to be available on the current core, 
*           and in case of error will return PLATFORM_E_PARAM_CONFIG.
*
* */
#define PLATFORM_E_PARAM_CONFIG        ((uint8)0x04)

/**
* @brief API service called with wrong parameter of Channel.
*
*/
#define PLATFORM_E_PARAM_CHANNEL        ((uint8)0x05)

/**
* @brief            Service ID of Platform_Init function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_INIT_ID                         ((uint8)0x20U)

/**
* @brief            Service ID of Platform_SetIrq function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_SET_IRQ_ID                      ((uint8)0x21U)

/**
* @brief            Service ID of Platform_SetIrqPriority function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_SET_IRQ_PRIO_ID                 ((uint8)0x22U)

/**
* @brief            Service ID of Platform_GetIrqPriority function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_GET_IRQ_PRIO_ID                 ((uint8)0x23U)

/**
* @brief            Service ID of Platform_InstallIrqHandler function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_INSTALL_HANDLER_ID              ((uint8)0x24U)

/**
* @brief            Service ID of Platform_SetIrqMonitor function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_SET_IRQ_MONITOR_ID              ((uint8)0x25U)

/**
* @brief            Service ID of Platform_AckIrq function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_ACK_IRQ_ID                      ((uint8)0x26U)

/**
* @brief            Service ID of Platform_SelectMonitoredIrq function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_SELECT_MONITORED_IRQ_ID         ((uint8)0x27U)

/**
* @brief            Service ID of Platform_SetMonitoredIrqLatency function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_SET_MONITORED_IRQ_LATENCY_ID    ((uint8)0x28U)

/**
* @brief            Service ID of Platform_ResetIrqMonitorTimer function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_RESET_IRQ_MONITOR_TIMER_ID      ((uint8)0x29U)

/**
* @brief            Service ID of Platform_GetIrqMonitorStatus function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_GET_IRQ_MONITOR_STATUS_ID       ((uint8)0x2AU)

/**
* @brief            Service ID of Platform_MruTransmit function
* @details          Parameter used when raising an error/exception
*/
#define PLATFORM_MRUTRANSMIT_ID       ((uint8)0x2BU)


/*==================================================================================================
 *                              TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* @brief          Configuration structure for PLATFORM CDD.
* @implements     Platform_ConfigType_struct
*/
typedef struct
{
    /** @brief Reference to IPW structure */
    const Platform_Ipw_ConfigType *pIpwConfig;
#if (PLATFORM_MSCM_CFG == STD_ON)
    /** @brief Reference to Core Independent IPW structure */
    const Platform_Ipw_NonCoreConfigType *pIpwNonCoreConfig;
#endif
}Platform_ConfigType;

/**
* @brief          Interrupt handler type definition for PLATFORM CDD.
* @implements     Platform_IrqHandlerType_typedef
*/
typedef IntCtrl_Ip_IrqHandlerType Platform_IrqHandlerType;

#endif /* PLATFORM_TYPESDEF_H_ */

/** @} */
