/***************************************************************************//**
 * @file
 * @brief Example Network Core Initialisation - Ethernet & Wifi Interface
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc.  Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement.  This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/
#ifndef  EX_NET_CORE_H
#define  EX_NET_CORE_H
/********************************************************************************************************
 ********************************************************************************************************
 *                                               CONFIGURATIONS
 ********************************************************************************************************
 *******************************************************************************************************/
#define NET_CORE_TASK_CFG_PRIO            30    // This priority is quite stable


/********************************************************************************************************
 ********************************************************************************************************
 *                                            INCLUDE FILES
 ********************************************************************************************************
 *******************************************************************************************************/

#include  <rtos_description.h>

#if (defined(RTOS_MODULE_NET_AVAIL))
#ifdef  RTOS_MODULE_NET_IF_ETHER_AVAIL
#include  <net/include/net_if_ether.h>
#endif
#ifdef  RTOS_MODULE_NET_IF_WIFI_AVAIL
#include  <net/include/net_if_wifi.h>
#endif
#endif

/********************************************************************************************************
 ********************************************************************************************************
 *                                          GLOBAL VARIABLES
 ********************************************************************************************************
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#if (defined(RTOS_MODULE_NET_AVAIL) \
  && defined(RTOS_MODULE_NET_IF_ETHER_AVAIL))
extern NET_IF_ETHER_CFG Ex_NetIF_CfgDflt_Ether;
#endif

#if (defined(RTOS_MODULE_NET_AVAIL) \
  && defined(RTOS_MODULE_NET_IF_WIFI_AVAIL))
extern NET_IF_BUF_CFG  Ex_NetWiFi_IF_BufCfg;
extern NET_IF_WIFI_CFG Ex_NetIF_CfgDflt_WiFi;
#endif

/********************************************************************************************************
 ********************************************************************************************************
 *                                         FUNCTION PROTOTYPES
 ********************************************************************************************************
 *******************************************************************************************************/

void Ex_Net_CoreInit(void);

void Ex_Net_CoreStartIF(void);

void Ex_Net_CoreStartEther(void);

void Ex_Net_CoreStartWiFi(void);

#ifdef __cplusplus
}
#endif

/********************************************************************************************************
 ********************************************************************************************************
 *                                             MODULE END
 ********************************************************************************************************
 *******************************************************************************************************/

#endif // EX_NET_CORE_H