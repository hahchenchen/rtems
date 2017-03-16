/**
 * @file
 * @ingroup lm32_tsmac
 * @brief LatticeMico32 TSMAC (Tri-Speed MAC) definitions
 */

/*
 *  This file contains definitions for LatticeMico32 TSMAC (Tri-Speed MAC)
 *
 *  COPYRIGHT (c) 1989-1999.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 *
 *  Jukka Pietarinen <jukka.pietarinen@mrf.fi>, 2008,
 *  Micro-Research Finland Oy
 */

#ifndef _DP83848PHY_H
#define _DP83848PHY_H

#define DEFAULT_PHY_ADDRESS   (0x01)

#define PHY_BMCR              (0x00)
#define PHY_BMCR_RESET        (1<<15)
#define PHY_BMCR_LOOPBACK     (1<<14)
#define PHY_BMCR_SPEEDSEL     (1<<13)
#define PHY_BMCR_AN_ENA       (1<<12)
#define PHY_BMCR_PWRDWN       (1<<11)
#define PHY_BMCR_ISOLATE      (1<<10)
#define PHY_BMCR_RESTART_AN   (1<<9)
#define PHY_BMCR_DUPLEX_MODE  (1<<8)
#define PHY_BMCR_COLL_TEST    (1<<7)
#define PHY_BMSR              (0x01)
#define PHY_BMSR_100_T4       (1<<15)
#define PHY_BMSR_100_TX_FD    (1<<14)
#define PHY_BMSR_100_TX_HD    (1<<13)
#define PHY_BMSR_10_T_FD      (1<<12)
#define PHY_BMSR_10_T_HD      (1<<11)
#define PHY_BMSR_PRESUP       (1<<6)
#define PHY_BMSR_AN_CMPL      (1<<5)
#define PHY_BMSR_REM_FLT      (1<<4)
#define PHY_BMSR_AN_AB        (1<<3)
#define PHY_BMSR_LINK_STAT    (1<<2)
#define PHY_BMSR_JABBDET      (1<<1)
#define PHY_BMSR_EXT_CAP      (1<<0)
#define PHY_PHYIDR1           (0x02)
#define DEFAULT_PHYIDR1       (0x2000)
#define PHY_PHYIDR2           (0x03)
#define DEFAULT_PHYIDR2       (0x5C90)
#define PHY_ANAR              (0x04)
#define PHY_ANAR_NP           (1<<15)
#define PHY_ANAR_RF           (1<<13)
#define PHY_ANAR_ASM_DIR      (1<<11)
#define PHY_ANAR_PAUSE        (1<<10)
#define PHY_ANAR_T4           (1<<9)
#define PHY_ANAR_TX_FD        (1<<8)
#define PHY_ANAR_TX           (1<<7)
#define PHY_ANAR_10_FD        (1<<6)
#define PHY_ANAR_10           (1<<5)
#define PHY_ANAR_SEL_MASK     (0x0f)
#define PHY_ANAR_SEL_SHIFT    (0)
#define PHY_ANAR_SEL_DEF      (1)
#define PHY_ANLPAR            (0x05)
#define PHY_ANLPAR_NP         (1<<15)
#define PHY_ANLPAR_ACK        (1<<14)
#define PHY_ANLPAR_RF         (1<<13)
#define PHY_ANLPAR_ASM_DIR    (1<<11)
#define PHY_ANLPAR_PAUSE      (1<<10)
#define PHY_ANLPAR_T4         (1<<9)
#define PHY_ANLPAR_TX_FD      (1<<8)
#define PHY_ANLPAR_TX         (1<<7)
#define PHY_ANLPAR_10_FD      (1<<6)
#define PHY_ANLPAR_10         (1<<5)
#define PHY_ANLPAR_SEL_MASK   (0x0f)
#define PHY_ANLPAR_SEL_SHIFT  (0)
#define PHY_ANLPARNP          (0x05)
#define PHY_ANLPARNP_NP       (1<<15)
#define PHY_ANLPARNP_ACK      (1<<14)
#define PHY_ANLPARNP_MP       (1<<13)
#define PHY_ANLPARNP_ACK2     (1<<12)
#define PHY_ANLPARNP_TOGGLE   (1<<11)
#define PHY_ANLPARNP_CDE_MASK (0x03ff)
#define PHY_ANER              (0x06)
#define PHY_ANER_PDF          (1<<4)
#define PHY_ANER_LP_NP_ABLE   (1<<3)
#define PHY_ANER_NP_ABLE      (1<<2)
#define PHY_ANER_PAGE_RX      (1<<1)
#define PHY_ANER_LP_AN_ABLE   (1<<0)
#define PHY_ANNPTR            (0x07)
#define PHY_ANNPTR_NP         (1<<15)
#define PHY_ANNPTR_MP         (1<<13)
#define PHY_ANNPTR_ACK2       (1<<12)
#define PHY_ANNPTR_TOG_TX     (1<<11)
#define PHY_ANNPTR_CDE_MASK   (0x03ff)
#define PHY_PHYSTS            (0x10)
#define PHY_PHYSTS_MDIX_MDE   (1<<14)
#define PHY_PHYSTS_RCV_ERRL   (1<<13)
#define PHY_PHYSTS_POLSTAT    (1<<12)
#define PHY_PHYSTS_FCSL       (1<<11)
#define PHY_PHYSTS_SD         (1<<10)
#define PHY_PHYSTS_DESCL      (1<<9)
#define PHY_PHYSTS_PGREC      (1<<8)
#define PHY_PHYSTS_MIIIRQ     (1<<7)
#define PHY_PHYSTS_REM_FLT    (1<<6)
#define PHY_PHYSTS_JABBDET    (1<<5)
#define PHY_PHYSTS_AN_CMP     (1<<4)
#define PHY_PHYSTS_LOOPBACK   (1<<3)
#define PHY_PHYSTS_DUPLEX     (1<<2)
#define PHY_PHYSTS_SPEED      (1<<1)
#define PHY_PHYSTS_LINK       (1<<0)
#define PHY_MICR              (0x11)
#define PHY_MICR_TINT         (1<<2)
#define PHY_MICR_INTEN        (1<<1)
#define PHY_MICR_INT_OE       (1<<0)
#define PHY_MISR              (0x12)
#define PHY_MISR_ED_INT       (1<<14)
#define PHY_MISR_LINK_INT     (1<<13)
#define PHY_MISR_SPD_INT      (1<<12)
#define PHY_MISR_DUP_INT      (1<<11)
#define PHY_MISR_ANC_INT      (1<<10)
#define PHY_MISR_FHF_INT      (1<<9)
#define PHY_MISR_RHF_INT      (1<<8)
#define PHY_MISR_ED_INT_EN    (1<<6)
#define PHY_MISR_LINK_INT_EN  (1<<5)
#define PHY_MISR_SPD_INT_EN   (1<<4)
#define PHY_MISR_DUP_INT_EN   (1<<3)
#define PHY_MISR_ANC_INT_EN   (1<<2)
#define PHY_MISR_FHF_INT_EN   (1<<1)
#define PHY_MISR_RHF_INT_EN   (1<<0)
#define PHY_FCSCR             (0x14)
#define PHY_RECR              (0x15)
#define PHY_PCSR              (0x16)
#define PHY_PCSR_TQ_EN        (1<<10)
#define PHY_PCSR_SDFPMA       (1<<9)
#define PHY_PCSR_SD_OPT       (1<<8)
#define PHY_PCSR_DESC_TIME    (1<<7)
#define PHY_PCSR_F_100_OK     (1<<5)
#define PHY_PCSR_NRZI_BYPASS  (1<<2)
#define PHY_RBR               (0x17)
#define PHY_RBR_RMII_MODE     (1<<5)
#define PHY_RBR_RMII_REV1_0   (1<<4)
#define PHY_RBR_RX_OVF_STS    (1<<3)
#define PHY_RBR_RX_UNF_STS    (1<<2)
#define PHY_RBR_ELAST_BUF1    (1<<1)
#define PHY_RBR_ELAST_BUF0    (1<<0)
#define PHY_LEDCR             (0x18)
#define PHY_LEDCR_DRV_SPDLED  (1<<5)
#define PHY_LEDCR_DRV_LNKLED  (1<<4)
#define PHY_LEDCR_DRV_ACTLED  (1<<3)
#define PHY_LEDCR_SPDLED      (1<<2)
#define PHY_LEDCR_LNKLED      (1<<1)
#define PHY_LEDCR_ACTLED      (1<<0)
#define PHY_PHYCR             (0x19)
#define PHY_PHYCR_MDIX_EN     (1<<15)
#define PHY_PHYCR_FORCE_MDIX  (1<<14)
#define PHY_PHYCR_PAUSE_RX    (1<<13)
#define PHY_PHYCR_PAUSE_TX    (1<<12)
#define PHY_PHYCR_BIST_FE     (1<<11)
#define PHY_PHYCR_PSR_15      (1<<10)
#define PHY_PHYCR_BIST_STATUS (1<<9)
#define PHY_PHYCR_BIST_START  (1<<8)
#define PHY_PHYCR_BP_STRETCH  (1<<7)
#define PHY_PHYCR_LED_CNFG1   (1<<6)
#define PHY_PHYCR_LED_CNFG0   (1<<5)
#define PHY_PHYCR_ADDR4       (1<<4)
#define PHY_PHYCR_ADDR3       (1<<3)
#define PHY_PHYCR_ADDR2       (1<<2)
#define PHY_PHYCR_ADDR1       (1<<1)
#define PHY_PHYCR_ADDR0       (1<<0)
#define PHY_10BTSCR           (0x1A)
#define PHY_10BTSCR_SERIAL    (1<<15)
#define PHY_10BTSCR_SQ_MASK   (0x07)
#define PHY_10BTSCR_SQ_SHIFT  (9)
#define PHY_10BTSCR_LP_10_DIS (1<<8)
#define PHY_10BTSCR_LP_DIS    (1<<7)
#define PHY_10BTSCR_FLINK_10  (1<<1)
#define PHY_10BTSCR_POL       (1<<4)
#define PHY_10BTSCR_HB_DIS    (1<<1)
#define PHY_10BTSCR_JAB_DIS   (1<<0)
#define PHY_CDCTRL1           (0x1B)
#define PHY_EDCR              (0x1D)

#endif /* _DP83848PHY_H */
