/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef __ODM_TYPES_H__
#define __ODM_TYPES_H__

//
// Define Different SW team support
//
#define	ODM_AP			0x01	 //BIT0
#define	ODM_ADSL		0x02	//BIT1
#define	ODM_CE			0x04	//BIT2
#define	ODM_MP			0x08	//BIT3

#define	DM_ODM_SUPPORT_TYPE			ODM_CE

#if (DM_ODM_SUPPORT_TYPE != ODM_MP)
#define		RT_PCI_INTERFACE				1
#define		RT_USB_INTERFACE				2
#define		RT_SDIO_INTERFACE				3
#endif

typedef enum _HAL_STATUS{
	HAL_STATUS_SUCCESS,
	HAL_STATUS_FAILURE,
	/*RT_STATUS_PENDING,
	RT_STATUS_RESOURCE,
	RT_STATUS_INVALID_CONTEXT,
	RT_STATUS_INVALID_PARAMETER,
	RT_STATUS_NOT_SUPPORT,
	RT_STATUS_OS_API_FAILED,*/
}HAL_STATUS,*PHAL_STATUS;

#if (DM_ODM_SUPPORT_TYPE == ODM_CE)
typedef enum _RT_SPINLOCK_TYPE{
	RT_TEMP =1,
}RT_SPINLOCK_TYPE;
#elif( (DM_ODM_SUPPORT_TYPE == ODM_AP) ||(DM_ODM_SUPPORT_TYPE == ODM_ADSL))

#define		VISTA_USB_RX_REVISE			0

//
// Declare for ODM spin lock defintion temporarily fro compile pass.
//
typedef enum _RT_SPINLOCK_TYPE{
	RT_TX_SPINLOCK = 1,
	RT_RX_SPINLOCK = 2,
	RT_RM_SPINLOCK = 3,
	RT_CAM_SPINLOCK = 4,
	RT_SCAN_SPINLOCK = 5,
	RT_LOG_SPINLOCK = 7,
	RT_BW_SPINLOCK = 8,
	RT_CHNLOP_SPINLOCK = 9,
	RT_RF_OPERATE_SPINLOCK = 10,
	RT_INITIAL_SPINLOCK = 11,
	RT_RF_STATE_SPINLOCK = 12, // For RF state. Added by Bruce, 2007-10-30.
#if VISTA_USB_RX_REVISE
	RT_USBRX_CONTEXT_SPINLOCK = 13,
	RT_USBRX_POSTPROC_SPINLOCK = 14, // protect data of Adapter->IndicateW/ IndicateR
#endif
	//Shall we define Ndis 6.2 SpinLock Here ?
	RT_PORT_SPINLOCK=16,
	RT_VNIC_SPINLOCK=17,
	RT_HVL_SPINLOCK=18,
	RT_H2C_SPINLOCK = 20, // For H2C cmd. Added by tynli. 2009.11.09.

	RT_BTData_SPINLOCK=25,

	RT_WAPI_OPTION_SPINLOCK=26,
	RT_WAPI_RX_SPINLOCK=27,

      // add for 92D CCK control issue
	RT_CCK_PAGEA_SPINLOCK = 28,
	RT_BUFFER_SPINLOCK = 29,
	RT_CHANNEL_AND_BANDWIDTH_SPINLOCK = 30,
	RT_GEN_TEMP_BUF_SPINLOCK = 31,
	RT_AWB_SPINLOCK = 32,
	RT_FW_PS_SPINLOCK = 33,
	RT_HW_TIMER_SPIN_LOCK = 34,
	RT_MPT_WI_SPINLOCK = 35
}RT_SPINLOCK_TYPE;

#endif


#if (DM_ODM_SUPPORT_TYPE == ODM_MP)
	#define	STA_INFO_T			RT_WLAN_STA
	#define	PSTA_INFO_T			PRT_WLAN_STA

	#define CONFIG_HW_ANTENNA_DIVERSITY
#define CONFIG_SW_ANTENNA_DIVERSITY

#elif (DM_ODM_SUPPORT_TYPE == ODM_AP)

	// To let ADSL/AP project compile ok; it should be removed after all conflict are solved. Added by Annie, 2011-10-07.
	#define ADSL_AP_BUILD_WORKAROUND
	#define AP_BUILD_WORKAROUND
	//

	#ifdef AP_BUILD_WORKAROUND
	#include "typedef.h"
	#else
	typedef void					VOID,*PVOID;
	typedef unsigned char			bool,*Pbool;
	typedef unsigned char			u1Byte,*pu1Byte;
	typedef unsigned short			u2Byte,*pu2Byte;
	typedef unsigned int			u4Byte,*pu4Byte;
	typedef unsigned long long		u8Byte,*pu8Byte;
	typedef char					s1Byte,*ps1Byte;
	typedef short					s2Byte,*ps2Byte;
	typedef long					s4Byte,*ps4Byte;
	typedef long long				s8Byte,*ps8Byte;
	#endif

	typedef struct rtl8192cd_priv	*prtl8192cd_priv;
	typedef struct stat_info		STA_INFO_T,*PSTA_INFO_T;
	typedef struct timer_list		RT_TIMER, *PRT_TIMER;
	typedef  void *					RT_TIMER_CALL_BACK;

	#define		DEV_BUS_TYPE		RT_PCI_INTERFACE

	#define _TRUE				1
	#define _FALSE				0

#elif (DM_ODM_SUPPORT_TYPE == ODM_ADSL)

	// To let ADSL/AP project compile ok; it should be removed after all conflict are solved. Added by Annie, 2011-10-07.
	#define ADSL_AP_BUILD_WORKAROUND
	#define ADSL_BUILD_WORKAROUND
	//

	typedef unsigned char		bool,*Pbool;
	typedef unsigned char		u1Byte,*pu1Byte;
	typedef unsigned short		u2Byte,*pu2Byte;
	typedef unsigned int			u4Byte,*pu4Byte;
	typedef unsigned long long	u8Byte,*pu8Byte;
	typedef char				s1Byte,*ps1Byte;
	typedef short				s2Byte,*ps2Byte;
	typedef long				s4Byte,*ps4Byte;
	typedef long long			s8Byte,*ps8Byte;

	typedef struct rtl8192cd_priv	*prtl8192cd_priv;
	typedef struct stat_info		STA_INFO_T,*PSTA_INFO_T;
	typedef struct timer_list		RT_TIMER, *PRT_TIMER;
	typedef  void *				RT_TIMER_CALL_BACK;

	#define DEV_BUS_TYPE	RT_PCI_INTERFACE

	#define _TRUE				1
	#define _FALSE				0

#elif (DM_ODM_SUPPORT_TYPE == ODM_CE)
	#include <basic_types.h>

#if 0
	typedef u8					u1Byte, *pu1Byte;
	typedef u16					u2Byte,*pu2Byte;
	typedef u32					u4Byte,*pu4Byte;
	typedef u64					u8Byte,*pu8Byte;
	typedef s8					s1Byte,*ps1Byte;
	typedef s16					s2Byte,*ps2Byte;
	typedef s32					s4Byte,*ps4Byte;
	typedef s64					s8Byte,*ps8Byte;
#else
	#define u1Byte		u8
	#define pu1Byte			u8*

	#define u2Byte		u16
	#define pu2Byte			u16*

	#define u4Byte		u32
	#define pu4Byte			u32*

	#define u8Byte		u64
	#define pu8Byte			u64*

	#define s1Byte		s8
	#define ps1Byte			s8*

	#define s2Byte		s16
	#define ps2Byte			s16*

	#define s4Byte		s32
	#define ps4Byte			s32*

	#define s8Byte		s64
	#define ps8Byte			s64*

#endif
	#ifdef CONFIG_USB_HCI
		#define DEV_BUS_TYPE	RT_USB_INTERFACE
	#endif

	typedef struct timer_list		RT_TIMER, *PRT_TIMER;
	typedef  void *				RT_TIMER_CALL_BACK;
	#define	STA_INFO_T			struct sta_info
	#define	PSTA_INFO_T		struct sta_info *



	#define TRUE	_TRUE
	#define FALSE	_FALSE


	#define SET_TX_DESC_ANTSEL_A_88E(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 24, 1, __Value)
	#define SET_TX_DESC_ANTSEL_B_88E(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+8, 25, 1, __Value)
	#define SET_TX_DESC_ANTSEL_C_88E(__pTxDesc, __Value) SET_BITS_TO_LE_4BYTE(__pTxDesc+28, 29, 1, __Value)

	//define useless flag to avoid compile warning
	#define	USE_WORKITEM			0
	#define		FOR_BRAZIL_PRETEST	0
	#define	BT_30_SUPPORT			0
	#define   FPGA_TWO_MAC_VERIFICATION	0
#endif


#endif // __ODM_TYPES_H__
