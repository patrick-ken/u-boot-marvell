/*******************************************************************************
Copyright (C) Marvell International Ltd. and its affiliates

This software file (the "File") is owned and distributed by Marvell
International Ltd. and/or its affiliates ("Marvell") under the following
alternative licensing terms.  Once you have made an election to distribute the
File under one of the following license alternatives, please (i) delete this
introductory statement regarding license alternatives, (ii) delete the two
license alternatives that you have not elected to use and (iii) preserve the
Marvell copyright notice above.

********************************************************************************
Marvell Commercial License Option

If you received this File from Marvell and you have entered into a commercial
license agreement (a "Commercial License") with Marvell, the File is licensed
to you under the terms of the applicable Commercial License.

********************************************************************************
Marvell GPL License Option

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File in accordance with the terms and conditions of the General
Public License Version 2, June 1991 (the "GPL License"), a copy of which is
available along with the File in the license.txt file or by writing to the Free
Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 or
on the worldwide web at http://www.gnu.org/licenses/gpl.txt.

THE FILE IS DISTRIBUTED AS-IS, WITHOUT WARRANTY OF ANY KIND, AND THE IMPLIED
WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY
DISCLAIMED.  The GPL License provides additional details about this warranty
disclaimer.
********************************************************************************
Marvell BSD License Option

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File under the following licensing terms.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    *   Redistributions of source code must retain the above copyright notice,
	this list of conditions and the following disclaimer.

    *   Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions and the following disclaimer in the
	documentation and/or other materials provided with the distribution.

    *   Neither the name of Marvell nor the names of its contributors may be
	used to endorse or promote products derived from this software without
	specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/

#ifndef __INCmvCtrlEnvSpech
#define __INCmvCtrlEnvSpech

#include "mvDeviceId.h"
#include "mvSysHwConfig.h"

#include "ctrlEnv/sys/mvCpuIfRegs.h"

#define MAX_TARGETS	(mvCtrlDevFamilyIdGet(0) == MV_78460_DEV_ID ? \
			 MAX_TARGETS_AXP : MAX_TARGETS_MSYS)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define MV_ARM_SOC
#if defined CONFIG_ALLEYCAT3
#define SOC_NAME_PREFIX				"Alleycat3"
#elif defined CONFIG_BOBCAT2
#define SOC_NAME_PREFIX				"Bobcat2"
#else
#define SOC_NAME_PREFIX				"BobK"
#endif
/*
 * Bobcat2/AXP Units Address decoding
 */
#define MV_DRAM_REGS_OFFSET			(0x0)
#define MV_AURORA_L2_REGS_OFFSET		(0x8000)
#define MV_RTC_REGS_OFFSET			(0x10300)
#define MV_DEV_BUS_REGS_OFFSET			(0x10400)
#define MV_SPI_REGS_OFFSET(unit)		(0x10600 + (unit * 0x80))
#define MV_TWSI_SLAVE_REGS_OFFSET(chanNum)	(0x11000 + (chanNum * 0x100))

#define MV_UART_REGS_OFFSET(chanNum)		(0x12000 + (chanNum * 0x100))
#define MV_RUNIT_PMU_REGS_OFFSET		(0x1C000)

#define MV_MPP_REGS_OFFSET			(0x18000)
#define MV_GPP_REGS_OFFSET(unit)		(0x18100 + ((unit) * 0x80))
#define MV_GPP_REGS_OFFSET_AXP(unit)		(0x18100 + ((unit) * 0x40))

#define MV_MISC_REGS_OFFSET			(0x18200)
#define MV_CLK_CMPLX_REGS_OFFSET		(0x18700)
#define MV_MBUS_REGS_OFFSET			(0x20000)
#define MV_COHERENCY_FABRIC_OFFSET		(0x20200)
#define MV_COHERENCY_FABRIC_CTRL_REG		(MV_COHERENCY_FABRIC_OFFSET + 0x0)
#define MV_COHERENCY_FABRIC_CFG_REG		(MV_COHERENCY_FABRIC_OFFSET + 0x4)
#define MV_CIB_CTRL_STATUS_OFFSET		(0x20280)
#define MV_CNTMR_REGS_OFFSET			(0x20300)
#define MV_CPUIF_LOCAL_REGS_OFFSET		(0x21000)
#define MV_CPUIF_REGS_OFFSET(cpu)		(0x21800 + (cpu) * 0x100)
#define MV_PMU_NFABRIC_UNIT_SERV_OFFSET		(0x22000)
#define MV_CPU_PMU_UNIT_SERV_OFFSET(cpu)	(0x22100 + (cpu) * 0x100)
#define MV_CPU_HW_SEM_OFFSET			(0x20500)
#define MV_ETH_BASE_ADDR			(0x70000)
#define MV_ETH_REGS_OFFSET(port)		(MV_ETH_BASE_ADDR - ((port) / 2) * 0x40000 + ((port) % 2) * 0x4000)
#define MV_PEX_IF_REGS_OFFSET(pexIf)\
			(pexIf < 8 ? (0x40000 + ((pexIf) / 4) * 0x40000 + ((pexIf) % 4) * 0x4000)\
	: (0X42000 + ((pexIf) % 8) * 0x40000))
#define MV_USB_REGS_OFFSET(dev)			(0x50000 + (dev * 0x1000))
#define MV_USB2_USB3_REGS_OFFSET(unitType, dev) (MV_USB_REGS_OFFSET(dev))
#define MV_XOR_REGS_OFFSET(unit)		(0xF0800)
#define MV_XOR_REGS_OFFSET_AXP(unit)		(unit ? 0xF0900 : 0x60900)
#if defined(MV_INCLUDE_IDMA)
#define MV_IDMA_REGS_OFFSET			(0x60800)
#endif
#define MV_CESA_TDMA_REGS_OFFSET(chanNum)	(0x90000 + (chanNum * 0x2000))
#define MV_CESA_REGS_OFFSET(chanNum)		(0x9D000 + (chanNum * 0x2000))
#define MV_SATA_REGS_OFFSET			(0xA0000)
#define MV_COMM_UNIT_REGS_OFFSET		(0xB0000)
#define MV_NFC_REGS_OFFSET			(0xD0000)
#define MV_BM_REGS_OFFSET			(0xC0000)
#define MV_PNC_REGS_OFFSET			(0xC8000)
#define MV_SDMMC_REGS_OFFSET			(0xD4000)

#define MV_USB2_CAPLENGTH_OFFSET(index)		(INTER_REGS_BASE + MV_USB_REGS_OFFSET(index) + 0x100)
#define MV_ETH_SMI_PORT   0

#define MV_PP_SMI_BASE(n) (0x54000000 + 0x01000000*n)
#define MV_PP_ETH_SMI_PORT 0

/*
 * Miscellanuous Controller Configurations
 */

#define AVS_CONTROL2_REG			0x20868
#define AVS_LOW_VDD_LIMIT			0x20860

#define INTER_REGS_SIZE				_1M

/* This define describes the TWSI interrupt bit and location */
#define TWSI_CPU_MAIN_INT_CAUSE_REG(cpu)	CPU_MAIN_INT_CAUSE_REG(1, (cpu))
#define TWSI0_CPU_MAIN_INT_BIT(ch)		((ch) + 3)
#define TWSI_SPEED				100000

#define MV_GPP_MAX_PINS				68
#define MV_GPP_MAX_GROUP    			2 	/* group == configuration register? */
#define MV_GPP_MAX_GROUP_AXP			3
#define MV_CNTMR_MAX_COUNTER 			8 	/* 4 global + 1 global WD + 2 current private CPU + 1 private CPU WD*/

#define MV_UART_MAX_CHAN			2

#define MV_XOR_MAX_UNIT				2 /* XOR unit == XOR engine */
#define MV_XOR_MAX_CHAN				4 /* total channels for all units together*/
#define MV_XOR_MAX_CHAN_PER_UNIT		2 /* channels for units */

#define MV_MPP_MAX_GROUP			5
#define MV_MPP_MAX_GROUP_AXP			9

#define MV_DRAM_MAX_CS				4
#define MV_SPI_MAX_CS				8
/* This define describes the maximum number of supported PCI\PCIX Interfaces */
#ifdef MV_INCLUDE_PCI
 #define MV_PCI_MAX_IF				1
 #define MV_PCI_START_IF			0
 #define PCI_HOST_BUS_NUM(pciIf)               (pciIf)
 #define PCI_HOST_DEV_NUM(pciIf)               0
#else
 #define MV_PCI_MAX_IF				0
 #define MV_PCI_START_IF			0
#endif

/* This define describes the maximum number of supported PEX Interfaces */
#define MV_PEX_MAX_IF				10	/* 1 for MSYS */
#define MV_PEX_MAX_UNIT				4	/* 1 for MSYS */
#ifdef MV_INCLUDE_PEX
#define MV_INCLUDE_PEX0
#define MV_DISABLE_PEX_DEVICE_BAR

#define MV_PEX_START_IF				MV_PCI_MAX_IF
 #define PEX_HOST_BUS_NUM(pciIf)               (pciIf)
 #define PEX_HOST_DEV_NUM(pciIf)               0
#else
 #undef MV_INCLUDE_PEX0
#endif

#define PCI_IO(pciIf)				(PEX0_IO + 2 * (pciIf))
#define PCI_MEM(pciIf, memNum)			(PEX0_MEM0 + 2 * (pciIf))
/* This define describes the maximum number of supported PCI Interfaces 	*/
#define MV_DEVICE_MAX_CS      			4

/* CESA version #3: One channel, 2KB SRAM, TDMA, CHAIN Mode support */
#define MV_CESA_VERSION				3
#define MV_CESA_SRAM_SIZE			(2 * 1024)

#ifdef MV_USB
#define MV_USB_MAX_PORTS 1
#else
#define MV_USB_MAX_PORTS 0
#endif
#define MV_USB3_MAX_HOST_PORTS 0

/* This define describes the maximum number of supported Ethernet ports */
/* TODO - verify all these numbers */
#define MV_ETH_VERSION 				4 /* for Legacy mode */
#define MV_NETA_VERSION				1 /* for NETA mode */
#define MV_ETH_MAX_PORTS			4
#define MV_ETH_MAX_RXQ              		8
#define MV_ETH_MAX_TXQ              		8
#define MV_ETH_TX_CSUM_MAX_SIZE 		9800
#define MV_ETH_TX_CSUM_MIN_SIZE			2048
#define MV_PNC_TCAM_LINES			1024	/* TCAM num of entries */
#define BOARD_ETH_SWITCH_PORT_NUM		2

/* New GMAC module is used */
#define MV_ETH_GMAC_NEW
/* New WRR/EJP module is used */
#define MV_ETH_WRR_NEW
/* IPv6 parsing support for Legacy parser */
#define MV_ETH_LEGACY_PARSER_IPV6

#define MV_MV_98DX_ETH_MAX_PORT			2

#define MV_SPI_VERSION				2

#define MV_INCLUDE_SDRAM_CS0
#define MV_INCLUDE_SDRAM_CS1
#define MV_INCLUDE_SDRAM_CS2
#define MV_INCLUDE_SDRAM_CS3

#define MV_INCLUDE_DEVICE_CS0
#define MV_INCLUDE_DEVICE_CS1
#define MV_INCLUDE_DEVICE_CS2
#define MV_INCLUDE_DEVICE_CS3

#ifndef MV_ASMLANGUAGE

#define TBL_UNUSED	0	/* Used to mark unused entry */


/* This enumerator defines the Marvell Units ID      */
typedef enum _mvUnitId {
	DRAM_UNIT_ID,
	PEX_UNIT_ID,
	ETH_GIG_UNIT_ID,
	XOR_UNIT_ID,
	UART_UNIT_ID,
	SPI_UNIT_ID,
	SDIO_UNIT_ID,
	I2C_UNIT_ID,
	USB_UNIT_ID,
	USB3_UNIT_ID,
	NAND_UNIT_ID,
	DEVBUS_UNIT_ID,
	IDMA_UNIT_ID,
	SATA_UNIT_ID,
	TDM_UNIT_ID,
	CESA_UNIT_ID,
	AUDIO_UNIT_ID,
	TS_UNIT_ID,
	XPON_UNIT_ID,
	BM_UNIT_ID,
	PNC_UNIT_ID,
	MAX_UNITS_ID
} MV_UNIT_ID;

/* This enumerator describes the Marvell controller possible devices that   */
/* can be connected to its device interface.                                */
typedef enum _mvDevice {
#if defined(MV_INCLUDE_DEVICE_CS0)
	DEV_CS0 = 0,    /* Device connected to dev CS[0]    */
#endif
#if defined(MV_INCLUDE_DEVICE_CS1)
	DEV_CS1 = 1,        /* Device connected to dev CS[1]    */
#endif
#if defined(MV_INCLUDE_DEVICE_CS2)
	DEV_CS2 = 2,        /* Device connected to dev CS[2]    */
#endif
#if defined(MV_INCLUDE_DEVICE_CS3)
	DEV_CS3 = 3,        /* Device connected to dev CS[2]    */
#endif
	BOOT_CS,        /* Device connected to BOOT dev    */
	MV_DEV_MAX_CS = MV_DEVICE_MAX_CS
} MV_DEVICE;

/* This enumerator described the possible Controller paripheral targets.    */
/* Controller peripherals are designated memory/IO address spaces that the  */
/* controller can access. They are also refered as "targets"                */
typedef enum _mvTarget {
	TBL_TERM = -1, 	/* none valid target, used as targets list terminator*/
	SDRAM_CS0,	/*  0 SDRAM chip select 0	*/
	SDRAM_CS1,	/*  1 SDRAM chip select 1	*/
	SDRAM_CS2,	/*  2 SDRAM chip select 2	*/
	SDRAM_CS3,	/*  3 SDRAM chip select 3	*/
	DEVICE_CS0,	/*  4 Device chip select 0	*/
	DEVICE_CS1,	/*  5 Device chip select 1	*/
	DEVICE_CS2,	/*  6 Device chip select 2	*/
	DEVICE_CS3,	/*  7 Device chip select 3	*/
	PEX0_MEM,	/*  8 PCI Express 0 Memory	*/
	PEX0_IO,	/*  9 PCI Express 0 IO		*/
	INTER_REGS,	/* 10 Internal registers	*/
	DFX_REGS,	/* 11 DFX Internal registers	*/
	SWITCH,		/* 12 SWITCH			*/
	DMA_UART,	/* 13 DMA based UART request	*/
	SPI_CS0,	/* 14 SPI_CS0			*/
	SPI_CS1,	/* 15 SPI_CS1			*/
	SPI_CS2,	/* 16 SPI_CS2			*/
	SPI_CS3,	/* 17 SPI_CS3			*/
	SPI_CS4,	/* 18 SPI_CS4			*/
	SPI_CS5,	/* 19 SPI_CS5			*/
	SPI_CS6,	/* 20 SPI_CS6			*/
	SPI_CS7,	/* 21 SPI_CS7			*/
	BOOT_ROM_CS,	/* 22 BOOT_ROM_CS		*/
	DEV_BOOCS,	/* 23 DEV_BOOCS			*/
	USB_REGS,	/* 24 USB Internal registers	*/
	DRAGONITE,	/* 25 Dragonite co-processor	*/
	MAX_TARGETS_MSYS
} MV_TARGET;

enum _mvTarget_axp {
	SDRAM_CS0_AXP,	/*0 SDRAM chip select 0		*/
	SDRAM_CS1_AXP,	/*1 SDRAM chip select 1		*/
	SDRAM_CS2_AXP,	/*2 SDRAM chip select 2		*/
	SDRAM_CS3_AXP,	/*3 SDRAM chip select 3		*/
	DEVICE_CS0_AXP,	/*4 Device chip select 0	*/
	DEVICE_CS1_AXP,	/*5 Device chip select 1	*/
	DEVICE_CS2_AXP,	/*6 Device chip select 2	*/
	DEVICE_CS3_AXP,	/*7 Device chip select 3	*/
	PEX0_MEM_AXP,	/*8 PCI Express 0 Memory	*/
	PEX0_IO_AXP,	/*9 PCI Express 0 IO		*/
	PEX1_MEM,	/*10 PCI Express 1 Memory	*/
	PEX1_IO,	/*11 PCI Express 1 IO		*/
	PEX2_MEM,	/*12 PCI Express 2 Memory	*/
	PEX2_IO,	/*13 PCI Express 2 IO		*/
	PEX3_MEM,	/*14 PCI Express 3 Memory	*/
	PEX3_IO,	/*15 PCI Express 3 IO		*/
	PEX4_MEM,	/*16 PCI Express 4 Memory	*/
	PEX4_IO,	/*17 PCI Express 4 IO		*/
	PEX5_MEM,	/*18 PCI Express 5 Memory	*/
	PEX5_IO,	/*19 PCI Express 5 IO		*/
	PEX6_MEM,	/*20 PCI Express 6 Memory	*/
	PEX6_IO,	/*21 PCI Express 6 IO		*/
	PEX7_MEM,	/*22 PCI Express 7 Memory	*/
	PEX7_IO,	/*23 PCI Express 7 IO		*/
	PEX8_MEM,	/*24 PCI Express 8 Memory	*/
	PEX8_IO,	/*25 PCI Express 8 IO		*/
	PEX9_MEM,	/*26 PCI Express 9 Memory	*/
	PEX9_IO,	/*27 PCI Express 9 IO		*/
	INTER_REGS_AXP,	/*28 Internal registers		*/
	DMA_UART_AXP,	/*29 DMA based UART request	*/
	SPI_CS0_AXP,	/*30 SPI_CS0			*/
	SPI_CS1_AXP,	/*31 SPI_CS1			*/
	SPI_CS2_AXP,	/*32 SPI_CS2			*/
	SPI_CS3_AXP,	/*33 SPI_CS3			*/
	SPI_CS4_AXP,	/*34 SPI_CS4			*/
	SPI_CS5_AXP,	/*35 SPI_CS5			*/
	SPI_CS6_AXP,	/*36 SPI_CS6			*/
	SPI_CS7_AXP,	/*37 SPI_CS7			*/
	BOOT_ROM_CS_AXP, /*38 BOOT_ROM_CS		*/
	DEV_BOOCS_AXP,	/*39 DEV_BOOCS			*/
	PMU_SCRATCHPAD,	/*40 PMU Scratchpad		*/
	CRYPT0_ENG,	/* 41 Crypto0 Engine		*/
	CRYPT1_ENG,	/* 42 Crypto1 Engine		*/
	PNC_BM,		/* 43 PNC + BM			*/
	MAX_TARGETS_AXP
};

#ifdef AURORA_IO_CACHE_COHERENCY
#define DRAM_CS0_ATTR		0x1E
#define DRAM_CS1_ATTR		0x1D
#define DRAM_CS2_ATTR		0x1B
#define DRAM_CS3_ATTR		0x17
#else
#define DRAM_CS0_ATTR		0x0E
#define DRAM_CS1_ATTR		0x0D
#define DRAM_CS2_ATTR		0x0B
#define DRAM_CS3_ATTR		0x07
#endif

#define TARGETS_DEF_ARRAY	{			\
	{DRAM_CS0_ATTR, DRAM_TARGET_ID	},	/*  0 SDRAM_CS0 */	\
	{DRAM_CS1_ATTR, DRAM_TARGET_ID	},	/*  1 SDRAM_CS1 */	\
	{DRAM_CS2_ATTR, DRAM_TARGET_ID	},	/*  2 SDRAM_CS0 */	\
	{DRAM_CS3_ATTR, DRAM_TARGET_ID	},	/*  3 SDRAM_CS1 */	\
	{0x3E, DEV_TARGET_ID	},		/*  4 DEVICE_CS0 */	\
	{0x3D, DEV_TARGET_ID	},		/*  5 DEVICE_CS1 */	\
	{0x3B, DEV_TARGET_ID	},		/*  6 DEVICE_CS2 */	\
	{0x37, DEV_TARGET_ID	},		/*  7 DEVICE_CS3 */	\
	{0xE8, PEX0_TARGET_ID	},		/*  8 PEX0_LANE0_MEM */	\
	{0xE0, PEX0_TARGET_ID	},		/*  9 PEX0_LANE0_IO */	\
	{0xFF, 0xFF		},		/* 10 INTER_REGS */	\
	{0x00, DFX_TARGET_ID	},		/* 11 DFX_INTER_REGS */	\
	{0x00, SWITCH_TARGET_ID	},		/* 12 SWITCH_TARGET_REGS */\
	{0x01, DEV_TARGET_ID	},		/* 13 DMA_UART */	\
	{0x1E, DEV_TARGET_ID	},		/* 14 SPI_CS0 */	\
	{0x5E, DEV_TARGET_ID	},		/* 15 SPI_CS1 */	\
	{0x9E, DEV_TARGET_ID	},		/* 16 SPI_CS2 */	\
	{0xDE, DEV_TARGET_ID	},		/* 17 SPI_CS3 */	\
	{0x1F, DEV_TARGET_ID	},		/* 18 SPI_CS4 */	\
	{0x5F, DEV_TARGET_ID	},		/* 19 SPI_CS5 */	\
	{0x9F, DEV_TARGET_ID	},		/* 20 SPI_CS6 */	\
	{0xDF, DEV_TARGET_ID	},		/* 21 SPI_CS7 */	\
	{0x1D, DEV_TARGET_ID	},		/* 22 BOOT_ROM_CS (Main Boot device )*/	\
	{0x2F, DEV_TARGET_ID	},		/* 23 DEV_BOOT_CS (Secondary Boot device,)*/	\
	{0x00, USB_TARGET_ID	},		/* 24 USB_TARGET_REGS */\
	{0x00, DRAGONITE_TARGET_ID },		/* 25 DRAGONITE */	\
}

#define TARGETS_NAME_ARRAY	{			\
	"SDRAM_CS0",		/*  0 SDRAM_CS0 */	\
	"SDRAM_CS1",		/*  1 SDRAM_CS1 */	\
	"SDRAM_CS2",		/*  2 SDRAM_CS1 */	\
	"SDRAM_CS3",		/*  3 SDRAM_CS1 */	\
	"DEVICE_CS0",		/*  4 DEVICE_CS0 */	\
	"DEVICE_CS1",		/*  5 DEVICE_CS1 */	\
	"DEVICE_CS2",		/*  6 DEVICE_CS2 */	\
	"DEVICE_CS3",		/*  7 DEVICE_CS3 */	\
	"PEX0_MEM",		/*  8 PEX0_MEM */	\
	"PEX0_IO",		/*  9 PEX0_IO */	\
	"INTER_REGS",		/* 10 INTER_REGS */	\
	"DFX_INTER_REGS",	/* 11 DFX_REGS */	\
	"SWITCH_REGS",		/* 12 SWITCH_REGS */	\
	"DMA_UART",		/* 13 DMA_UART */	\
	"SPI_CS0",		/* 14 SPI_CS0 */	\
	"SPI_CS1",		/* 15 SPI_CS1 */	\
	"SPI_CS2",		/* 16 SPI_CS2 */	\
	"SPI_CS3",		/* 17 SPI_CS3 */	\
	"SPI_CS4",		/* 18 SPI_CS4 */	\
	"SPI_CS5",		/* 19 SPI_CS5 */	\
	"SPI_CS6",		/* 20 SPI_CS6 */	\
	"SPI_CS7",		/* 21 SPI_CS7 */	\
	"BOOT_ROM_CS",		/* 22 BOOT_ROM_CS */	\
	"DEV_BOOTCS",		/* 23 DEV_BOOCS */	\
	"USB_REGS",		/* 24 USB_REGS */	\
	"DRAGONITE",		/* 25 DRAGONITE*/	\
}




#define TARGETS_DEF_ARRAY_AXP	{			\
	{DRAM_CS0_ATTR, DRAM_TARGET_ID	}, /* SDRAM_CS0 */	\
	{DRAM_CS1_ATTR, DRAM_TARGET_ID	}, /* SDRAM_CS1 */	\
	{DRAM_CS2_ATTR, DRAM_TARGET_ID	}, /* SDRAM_CS0 */	\
	{DRAM_CS3_ATTR, DRAM_TARGET_ID	}, /* SDRAM_CS1 */	\
	{0x3E, DEV_TARGET_ID	}, /* DEVICE_CS0 */	\
	{0x3D, DEV_TARGET_ID	}, /* DEVICE_CS1 */	\
	{0x3B, DEV_TARGET_ID	}, /* DEVICE_CS2 */	\
	{0x37, DEV_TARGET_ID	}, /* DEVICE_CS3 */	\
	{0xE8, PEX0_TARGET_ID	}, /* PEX0_LANE0_MEM */	\
	{0xE0, PEX0_TARGET_ID	}, /* PEX0_LANE0_IO */	\
	{0xD8, PEX0_TARGET_ID	}, /* PEX0_LANE1_MEM */	\
	{0xD0, PEX0_TARGET_ID	}, /* PEX0_LANE1_IO */	\
	{0xB8, PEX0_TARGET_ID	}, /* PEX0_LANE2_MEM */	\
	{0xB0, PEX0_TARGET_ID	}, /* PEX0_LANE2_IO */	\
	{0x78, PEX0_TARGET_ID	}, /* PEX0_LANE3_MEM */	\
	{0x70, PEX0_TARGET_ID	}, /* PEX0_LANE3_IO */	\
	{0xE8, DFX_TARGET_ID	}, /* PEX1_LANE0_MEM */	\
	{0xE0, DFX_TARGET_ID	}, /* PEX1_LANE0_IO */	\
	{0xD8, DFX_TARGET_ID	}, /* PEX1_LANE1_MEM */	\
	{0xD0, DFX_TARGET_ID	}, /* PEX1_LANE1_IO */	\
	{0xB8, DFX_TARGET_ID	}, /* PEX1_LANE2_MEM */	\
	{0xB0, DFX_TARGET_ID	}, /* PEX1_LANE2_IO */	\
	{0x78, DFX_TARGET_ID	}, /* PEX1_LANE3_MEM */	\
	{0x70, DFX_TARGET_ID	}, /* PEX1_LANE3_IO */	\
	{0xF8, PEX0_TARGET_ID	}, /* PEX2_LANE0_MEM */	\
	{0xF0, PEX0_TARGET_ID	}, /* PEX2_LANE0_IO */	\
	{0xF8, DFX_TARGET_ID	}, /* PEX3_LANE0_MEM */	\
	{0xF0, DFX_TARGET_ID	}, /* PEX3_LANE0_IO */	\
	{0xFF, 0xFF		}, /* INTER_REGS */	\
	{0x01, DEV_TARGET_ID	}, /* DMA_UART */	\
	{0x1E, DEV_TARGET_ID	}, /* SPI_CS0 */	\
	{0x5E, DEV_TARGET_ID	}, /* SPI_CS1 */	\
	{0x9E, DEV_TARGET_ID	}, /* SPI_CS2 */	\
	{0xDE, DEV_TARGET_ID	}, /* SPI_CS3 */	\
	{0x1F, DEV_TARGET_ID	}, /* SPI_CS4 */	\
	{0x5F, DEV_TARGET_ID	}, /* SPI_CS5 */	\
	{0x9F, DEV_TARGET_ID	}, /* SPI_CS6 */	\
	{0xDF, DEV_TARGET_ID	}, /* SPI_CS7 */	\
	{0x1D, DEV_TARGET_ID	}, /* Main Boot device */	\
	{0x2F, DEV_TARGET_ID	}, /* Secondary Boot device, */	\
	{0x2D, DEV_TARGET_ID	}, /* PMU_SCRATCHPAD */	\
	{0x09, CRYPT_TARGET_ID	}, /* CRYPT_ENG0 */	\
	{0x05, CRYPT_TARGET_ID	}, /* CRYPT_ENG1 */     \
	{0x00, PNC_BM_TARGET_ID	}, /* PNC_BM */		\
}

#define TARGETS_NAME_ARRAY_AXP	{		\
	"SDRAM_CS0",	/* SDRAM_CS0 */		\
	"SDRAM_CS1",	/* SDRAM_CS1 */		\
	"SDRAM_CS2",	/* SDRAM_CS1 */		\
	"SDRAM_CS3",	/* SDRAM_CS1 */		\
	"DEVICE_CS0",	/* DEVICE_CS0 */	\
	"DEVICE_CS1",	/* DEVICE_CS1 */	\
	"DEVICE_CS2",	/* DEVICE_CS2 */	\
	"DEVICE_CS3",	/* DEVICE_CS3 */	\
	"PEX0_MEM",	/* PEX0_MEM */		\
	"PEX0_IO",	/* PEX0_IO */		\
	"PEX1_MEM",	/* PEX1_MEM */		\
	"PEX1_IO",	/* PEX1_IO */		\
	"PEX2_MEM",	/* PEX2_MEM */		\
	"PEX2_IO",	/* PEX2_IO */		\
	"PEX3_MEM",	/* PEX3_MEM */		\
	"PEX3_IO",	/* PEX3_IO */		\
	"PEX4_MEM",	/* PEX4_MEM */		\
	"PEX4_IO",	/* PEX4_IO */		\
	"PEX5_MEM",	/* PEX5_MEM */		\
	"PEX5_IO",	/* PEX5_IO */		\
	"PEX6_MEM",	/* PEX6_MEM */		\
	"PEX6_IO",	/* PEX6_IO */		\
	"PEX7_MEM",	/* PEX7_MEM */		\
	"PEX7_IO",	/* PEX7_IO */		\
	"PEX8_MEM",	/* PEX8_MEM */		\
	"PEX8_IO",	/* PEX8_IO */		\
	"PEX9_MEM",	/* PEX9_MEM */		\
	"PEX9_IO",	/* PEX9_IO */		\
	"INTER_REGS",	/* INTER_REGS */	\
	"DMA_UART",	/* DMA_UART */		\
	"SPI_CS0",	/* SPI_CS0 */		\
	"SPI_CS1",	/* SPI_CS1 */		\
	"SPI_CS2",	/* SPI_CS2 */		\
	"SPI_CS3",	/* SPI_CS3 */		\
	"SPI_CS4",	/* SPI_CS4 */		\
	"SPI_CS5",	/* SPI_CS5 */		\
	"SPI_CS6",	/* SPI_CS6 */		\
	"SPI_CS7",	/* SPI_CS7 */		\
	"BOOT_ROM_CS",	/* BOOT_ROM_CS */	\
	"DEV_BOOTCS",	/* DEV_BOOCS */		\
	"PMU_SCRATCHPAD",/* PMU_SCRATCHPAD */	\
	"CRYPT1_ENG",	/* CRYPT1_ENG */	\
	"CRYPT2_ENG",	/* CRYPT2_ENG */	\
	"PNC_BM"	/* PNC_BM */		\
}

#endif /* MV_ASMLANGUAGE */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCmvCtrlEnvSpech */
