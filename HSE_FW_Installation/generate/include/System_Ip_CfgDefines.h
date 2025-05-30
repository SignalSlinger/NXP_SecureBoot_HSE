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

#ifndef SYSTEM_IP_CFG_DEFINES_H_
#define SYSTEM_IP_CFG_DEFINES_H_

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "StandardTypes.h"
#include "System_Ip_DeviceRegisters.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_VENDOR_ID                          43
#define CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_MAJOR_VERSION                   3
#define CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_MINOR_VERSION                   0
#define CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_PATCH_VERSION                   0
#define CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION           4
#define CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION           7
#define CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION        0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and System_Ip_DeviceRegisters header file are of the same vendor */
#if (CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_VENDOR_ID != CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_TYPES_VENDOR_ID)
    #error "System_Ip_Cfg.h and System_Ip_DeviceRegisters.h have different vendor ids"
#endif
/* Check if current file and System_Ip_CfgDefines header file are of the same Autosar version */
#if ((CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION    != CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION    != CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION != CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of System_Ip_Cfg.h and System_Ip_CfgDefines.h are different"
#endif
/* Check if current file and System_Ip_DeviceRegisters header file are of the same Software version */
#if ((CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_MAJOR_VERSION != CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_MINOR_VERSION != CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (CDD_PLATFORM_SYSTEM_IP_CFG_DEFINES_SW_PATCH_VERSION != CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of System_Ip_Cfg.h and System_Ip_DeviceRegisters.h are different"
#endif




#ifdef S32K344
        #include "S32K344_MCM_CM7.h"
#endif
#ifdef S32K342
        #include "S32K342_MCM_CM7.h"
#endif
#ifdef S32K341
        #include "S32K341_MCM_CM7.h"
#endif
#ifdef S32K324
        #include "S32K324_MCM_CM7.h"
#endif
#ifdef S32K314
        #include "S32K314_MCM_CM7.h"
#endif
#if defined(S32K311) || defined(S32K310)
        #include "S32K311_MCM_CM7.h"
#endif
#ifdef S32K312
        #include "S32K312_MCM_CM7.h"
#endif 
#ifdef S32K322
        #include "S32K322_MCM_CM7.h"
#endif
#if defined(S32K396) || defined(S32K394)
        #include "S32K39_MCM_CM7.h"
#endif
#if defined(S32K358) || defined(S32K328) || defined(S32K338) || defined(S32K348)
        #include "S32K358_MCM_CM7.h"
#endif
#ifdef S32K388
        #include "S32K388_MCM_CM7.h"
#endif
#if defined(S32M276) || defined(S32M274)
        #include "S32M27x_MCM_CM7.h"
#endif
    #define MCM_ISCR_FIDCE_SHIFT          MCM_CM7_ISCR_FIDCE_SHIFT
    #define MCM_ISCR_FIXCE_SHIFT          MCM_CM7_ISCR_FIXCE_SHIFT
    #define MCM_ISCR_FUFCE_SHIFT          MCM_CM7_ISCR_FUFCE_SHIFT
    #define MCM_ISCR_FOFCE_SHIFT          MCM_CM7_ISCR_FOFCE_SHIFT
    #define MCM_ISCR_FDZCE_SHIFT          MCM_CM7_ISCR_FDZCE_SHIFT
    #define MCM_ISCR_FIOCE_SHIFT          MCM_CM7_ISCR_FIOCE_SHIFT
    #define MCM_ISCR_WABE_SHIFT           MCM_CM7_ISCR_WABE_SHIFT 
    #define MCM_CPCR_CM7_AHBSPRI_MASK     MCM_CM7_CPCR_CM7_AHBSPRI_MASK
    #define MCM_ISCR_WABS_MASK            MCM_CM7_ISCR_WABS_MASK
    
    #define IP_MCM IP_MCM_0_CM7
    #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
    #define FPU_INEXACT_IRQ_SUPPORTED
    #define FPU_UNDERFLOW_IRQ_SUPPORTED
    #define FPU_OVERFLOW_IRQ_SUPPORTED
    #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
    #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
    #define TCM_WRITE_ABORT_IRQ_SUPPORTED
    
    #define MCM_HAS_WABS_SUPPORTED
    
    #define MCM_HAS_PLATFORM_REVISION
    /* Arm Cortex M4 */
#define SYSTEM_IP_ARM_CORTEXM                   (STD_ON)
#define SYSTEM_FPU_CFG                           (1)
#if ((SYSTEM_IP_ARM_CORTEXM == STD_ON) && (SYSTEM_FPU_CFG == STD_ON))
/**
* @brief      Enumeration listing available core-related interrupt requests
*             defined per each platform.
* @implements System_Ip_IrqType_typedef
*/    
typedef enum
{
#ifdef FPU_INPUT_DENORMAL_IRQ_SUPPORTED
    /** @brief FPU Input Denormal Interrupt */
    FPU_INPUT_DENORMAL_IRQ         = MCM_ISCR_FIDCE_SHIFT,
#endif	
#ifdef FPU_INEXACT_IRQ_SUPPORTED
    /** @brief FPU Inexact Interrupt */
    FPU_INEXACT_IRQ                = MCM_ISCR_FIXCE_SHIFT,
#endif
#ifdef FPU_UNDERFLOW_IRQ_SUPPORTED
    /** @brief FPU Underflow Interrupt */
    FPU_UNDERFLOW_IRQ              = MCM_ISCR_FUFCE_SHIFT,
#endif
#ifdef FPU_OVERFLOW_IRQ_SUPPORTED
    /** @brief FPU Overflow Interrupt */
    FPU_OVERFLOW_IRQ               = MCM_ISCR_FOFCE_SHIFT,
#endif
#ifdef FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
    /** @brief FPU Divide-by-Zero Interrupt */
    FPU_DIVIDE_BY_ZERO_IRQ         = MCM_ISCR_FDZCE_SHIFT,
#endif
#ifdef FPU_INVALID_OPERATION_IRQ_SUPPORTED
    /** @brief FPU Invalid Operation Interrupt */
    FPU_INVALID_OPERATION_IRQ      = MCM_ISCR_FIOCE_SHIFT,
#endif
#ifdef TCM_WRITE_ABORT_IRQ_SUPPORTED
    /** @brief TCM Write Abort Interrupt */
    TCM_WRITE_ABORT_IRQ            = MCM_ISCR_WABE_SHIFT,
#endif
#ifdef CACHE_WRITE_BUFFER_ERROR_SUPPORTED
    /** @brief Cache Write Buffer Error */
    CACHE_WRITE_BUFFER_ERROR       = MCM_ISCR_CWBEE_SHIFT
#endif
}System_Ip_IrqType;
#endif
#endif/* SYSTEM_IP_CFG_DEFINES_H_ */

