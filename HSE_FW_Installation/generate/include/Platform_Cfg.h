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

#ifndef PLATFORM_CFG_H_
#define PLATFORM_CFG_H_

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Platform_TypesDef.h"
#include "Platform_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_CFG_VENDOR_ID                     43
#define CDD_PLATFORM_CFG_AR_RELEASE_MAJOR_VERSION      4
#define CDD_PLATFORM_CFG_AR_RELEASE_MINOR_VERSION      7
#define CDD_PLATFORM_CFG_AR_RELEASE_REVISION_VERSION   0
#define CDD_PLATFORM_CFG_SW_MAJOR_VERSION              3
#define CDD_PLATFORM_CFG_SW_MINOR_VERSION              0
#define CDD_PLATFORM_CFG_SW_PATCH_VERSION              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_TypesDef header file are of the same vendor */
#if (CDD_PLATFORM_CFG_VENDOR_ID != CDD_PLATFORM_TYPESDEF_VENDOR_ID)
    #error "Platform_Cfg.h and Platform_TypesDef.h have different vendor ids"
#endif
/* Check if current file and Platform_TypesDef header file are of the same Autosar version */
#if ((CDD_PLATFORM_CFG_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_CFG_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_CFG_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_TYPESDEF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Cfg.h and Platform_TypesDef.h are different"
#endif
/* Check if current file and Platform_TypesDef header file are of the same Software version */
#if ((CDD_PLATFORM_CFG_SW_MAJOR_VERSION != CDD_PLATFORM_TYPESDEF_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_CFG_SW_MINOR_VERSION != CDD_PLATFORM_TYPESDEF_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_CFG_SW_PATCH_VERSION != CDD_PLATFORM_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Cfg.h and Platform_TypesDef.h are different"
#endif


#if (CDD_PLATFORM_CFG_VENDOR_ID != CDD_PLATFORM_CFGDEFINES_VENDOR_ID)
    #error "Platform_Cfg.h and Platform_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and Platform_CfgDefines header file are of the same Autosar version */
#if ((CDD_PLATFORM_CFG_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_CFG_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_CFG_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_CFGDEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Cfg.h and Platform_CfgDefines.h are different"
#endif
/* Check if current file and Platform_CfgDefines header file are of the same Software version */
#if ((CDD_PLATFORM_CFG_SW_MAJOR_VERSION != CDD_PLATFORM_CFGDEFINES_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_CFG_SW_MINOR_VERSION != CDD_PLATFORM_CFGDEFINES_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_CFG_SW_PATCH_VERSION != CDD_PLATFORM_CFGDEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Cfg.h and Platform_CfgDefines.h are different"
#endif

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

 /**
*   @brief Platform Intm Channel symbolic names
*   @details Get All Symbolic Names from configuration tool
*
*   @{
*/

#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#endif /* PLATFORM_CFG_H_ */

