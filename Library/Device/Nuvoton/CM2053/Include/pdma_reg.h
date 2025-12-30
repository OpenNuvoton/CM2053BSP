/**************************************************************************//**
 * @file     pdma_reg.h
 * @version  V1.00
 * @brief    PDMA register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __PDMA_REG_H__
#define __PDMA_REG_H__

#if defined ( __CC_ARM   )
    #pragma anon_unions
#endif

/**
    @addtogroup REGISTER Control Register
    @{
*/

/**
    @addtogroup PDMA Peripheral Direct Memory Access Controller (PDMA)
    Memory Mapped Structure for PDMA Controller
    @{
*/

typedef struct
{
    /**
@var DSCT_T::CTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CTL
</font><br><p> <font size="2">
Offset: 0x00  Descriptor Table Control Register of PDMA Channel n
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[1:0]</td><td>OPMODE</td><td><div style="word-wrap: break-word;"><b>PDMA Operation Mode Selection
</b><br>
00 = Idle state: Channel is stopped or this table is complete, when PDMA finish channel table task, OPMODE will be cleared to idle state automatically.
<br>
01 = Basic mode: The descriptor table only has one task
<br>
When this task is finished, the PDMA_INTSTS[n] will be asserted.
<br>
10 = Scatter-Gather mode: When operating in this mode, user must give the next descriptor table address in PDMA_DSCT_NEXT register; PDMA controller will ignore this task, then load the next task to execute.
<br>
11 = Reserved.
<br>
Note: Before filling transfer task in the Descriptor Table, user must check if the descriptor table is complete.
<br>
</div></td></tr><tr><td>
[2]</td><td>TXTYPE</td><td><div style="word-wrap: break-word;"><b>Transfer Type
</b><br>
0 = Burst transfer type.
<br>
1 = Single transfer type.
<br>
</div></td></tr><tr><td>
[6:4]</td><td>BURSIZE</td><td><div style="word-wrap: break-word;"><b>Burst Size
</b><br>
This field is used for peripheral to determine the burst size or used for determine the re-arbitration size.
<br>
000 = 128 Transfers.
<br>
001 = 64 Transfers.
<br>
010 = 32 Transfers.
<br>
011 = 16 Transfers.
<br>
100 = 8 Transfers.
<br>
101 = 4 Transfers.
<br>
110 = 2 Transfers.
<br>
111 = 1 Transfers.
<br>
Note: This field is only useful in burst transfer type.
<br>
</div></td></tr><tr><td>
[7]</td><td>TBINTDIS</td><td><div style="word-wrap: break-word;"><b>Table Interrupt Disable Bit
</b><br>
This field can be used to decide whether to enable table interrupt or not
<br>
If the TBINTDIS bit is enabled when PDMA controller finishes transfer task, it will not generates transfer done interrupt.
<br>
0 = Table interrupt Enabled.
<br>
1 = Table interrupt Disabled.
<br>
</div></td></tr><tr><td>
[9:8]</td><td>SAINC</td><td><div style="word-wrap: break-word;"><b>Source Address Increment
</b><br>
This field is used to set the source address increment size.
<br>
11 = No increment (fixed address).
<br>
Others = Increment and size is depended on TXWIDTH selection.
<br>
</div></td></tr><tr><td>
[11:10]</td><td>DAINC</td><td><div style="word-wrap: break-word;"><b>Destination Address Increment
</b><br>
This field is used to set the destination address increment size.
<br>
11 = No increment (fixed address).
<br>
Others = Increment and size is depended on TXWIDTH selection.
<br>
</div></td></tr><tr><td>
[13:12]</td><td>TXWIDTH</td><td><div style="word-wrap: break-word;"><b>Transfer Width Selection
</b><br>
This field is used for transfer width.
<br>
00 = One byte (8 bit) is transferred for every operation.
<br>
01= One half-word (16 bit) is transferred for every operation.
<br>
10 = One word (32-bit) is transferred for every operation.
<br>
11 = Reserved.
<br>
Note: The PDMA transfer source address (PDMA_DSCT_SA) and PDMA transfer destination address (PDMA_DSCT_DA) should be alignment under the TXWIDTH selection
<br>
</div></td></tr><tr><td>
[14]</td><td>TXACK</td><td><div style="word-wrap: break-word;"><b>Transfer Acknowledge Selection
</b><br>
0 = transfer ack when transfer done.
<br>
1 = transfer ack when PDMA get transfer data.
<br>
Note: This function only support UART_RX and SPI_RX.
<br>
</div></td></tr><tr><td>
[31:16]</td><td>TXCNT</td><td><div style="word-wrap: break-word;"><b>Transfer Count
</b><br>
The TXCNT represents the required number of PDMA transfer, the real transfer count is (TXCNT + 1); The maximum transfer count is 65536, every transfer may be byte, half-word or word that is dependent on TXWIDTH field.
<br>
Note: When PDMA finish each transfer data, this field will be decrease immediately.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var DSCT_T::SA

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">SA
</font><br><p> <font size="2">
Offset: 0x04  Source Address Register of PDMA Channel n
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[31:0]</td><td>SA</td><td><div style="word-wrap: break-word;"><b>PDMA Transfer Source Address
</b><br>
This field indicates a 32-bit source address of PDMA controller.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var DSCT_T::DA

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">DA
</font><br><p> <font size="2">
Offset: 0x08  Destination Address Register of PDMA Channel n
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[31:0]</td><td>DA</td><td><div style="word-wrap: break-word;"><b>PDMA Transfer Destination Address
</b><br>
This field indicates a 32-bit destination address of PDMA controller.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var DSCT_T::NEXT

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">NEXT
</font><br><p> <font size="2">
Offset: 0x0C  Next Scatter-gather Descriptor Table Offset Address of PDMA Channel n
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[15:0]</td><td>NEXT</td><td><div style="word-wrap: break-word;"><b>PDMA Next Descriptor Table Offset
</b><br>
This field indicates the offset of the next descriptor table address in system memory.
<br>
Write Operation:
<br>
If the system memory based address is 0x2000_0000 (PDMA_SCATBA), and the next descriptor table is start from 0x2000_0100, then this field must fill in 0x0100.
<br>
Read Operation:
<br>
When operating in scatter-gather mode, the last two bits NEXT[1:0] will become reserved, and indicate the first next address of system memory.
<br>
When operating in scatter-gather mode, the last two bits NEXT[1:0] will become scatter-gather mode control indicator as below.
<br>
0 = Idle mode.
<br>
1 = operating in the basic mode (final scatter-gather table).
<br>
2 = loading scatter-gather table from SRAM.
<br>
3 = operating in the scatter-gather mode.
<br>
Note1: The descriptor table address must be word boundary.
<br>
Note2: Before filled transfer task in the descriptor table, user must check if the descriptor table is complete.
<br>
</div></td></tr><tr><td>
[31:16]</td><td>EXENEXT</td><td><div style="word-wrap: break-word;"><b>PDMA Execution Next Descriptor Table Offset
</b><br>
This field indicates the offset of next descriptor table address of current execution descriptor table in system memory.
<br>
Note: write operation is useless in this field.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly



 */
    __IO uint32_t CTL;      /*!< [0x0000] Descriptor Table Control Register of PDMA Channel n.              */
    __IO uint32_t SA;       /*!< [0x0004] Source Address Register of PDMA Channel n                        */
    __IO uint32_t DA;       /*!< [0x0008] Destination Address Register of PDMA Channel n                   */
    __IO uint32_t NEXT;     /*!< [0x000c] First Scatter-Gather Descriptor Table Offset Address of PDMA Channel n */

} DSCT_T;

typedef struct
{
    /**
@var PDMA_T::CURSCAT

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CURSCAT
</font><br><p> <font size="2">
Offset: 0x100  Current Scatter-gather Descriptor Table Address of PDMA Channel n
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[31:0]</td><td>CURADDR</td><td><div style="word-wrap: break-word;"><b>PDMA Current Description Address (Read Only)
</b><br>
This field indicates a 32-bit current external description address of PDMA controller.
<br>
Note: This field is read only and used for Scatter-Gather mode only to indicate the current external description address.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::CHCTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CHCTL
</font><br><p> <font size="2">
Offset: 0x400  PDMA Channel Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[4:0]</td><td>CHENn</td><td><div style="word-wrap: break-word;"><b>PDMA Channel Enable Bits
</b><br>
Set this bit to 1 to enable PDMAn operation. Channel cannot be active if it is not set as enabled.
<br>
0 = PDMA channel [n] Disabled.
<br>
1 = PDMA channel [n] Enabled.
<br>
Note: Setting the corresponding bit of PDMA_PAUSE or PDMA_CHRST register will also clear this bit.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::PAUSE

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">PAUSE
</font><br><p> <font size="2">
Offset: 0x404  PDMA Transfer Pause Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[4:0]</td><td>PAUSEn</td><td><div style="word-wrap: break-word;"><b>PDMA Channel N Transfer Pause Control (Write Only)
</b><br>
User can set PAUSEn bit field to pause the PDMA transfer
<br>
When user sets PAUSEn bit, the PDMA controller will pause the on-going transfer, then clear the channel enable bit CHEN(PDMA_CHCTL [n], n=0,1..7) and clear request active flag
<br>
If the paused channel is re-enabled again, the remaining transfers will be processed.
<br>
0 = No effect.
<br>
1 = Pause PDMA channel n transfer.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::SWREQ

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">SWREQ
</font><br><p> <font size="2">
Offset: 0x408  PDMA Software Request Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[4:0]</td><td>SWREQn</td><td><div style="word-wrap: break-word;"><b>PDMA Software Request (Write Only)
</b><br>
Set this bit to 1 to generate a software request to PDMA [n].
<br>
0 = No effect.
<br>
1 = Generate a software request.
<br>
Note1: User can read PDMA_TRGSTS register to know which channel is on active
<br>
Active flag may be triggered by software request or peripheral request.
<br>
Note2: If user does not enable corresponding PDMA channel, the software request will be ignored.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::TRGSTS

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">TRGSTS
</font><br><p> <font size="2">
Offset: 0x40C  PDMA Channel Request Status Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[4:0]</td><td>REQSTSn</td><td><div style="word-wrap: break-word;"><b>PDMA Channel Request Status (Read Only)
</b><br>
This flag indicates whether channel[n] have a request or not, no matter request from software or peripheral
<br>
When PDMA controller finishes channel transfer, this bit will be cleared automatically.
<br>
0 = PDMA Channel n has no request.
<br>
1 = PDMA Channel n has a request.
<br>
Note: If user pauses or resets each PDMA transfer by setting PDMA_PAUSE or PDMA_CHRST register respectively, this bit will be cleared automatically after finishing the current transfer.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::PRISET

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">PRISET
</font><br><p> <font size="2">
Offset: 0x410  PDMA Fixed Priority Setting Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[4:0]</td><td>FPRISETn</td><td><div style="word-wrap: break-word;"><b>PDMA Fixed Priority Setting
</b><br>
Set this bit to 1 to enable fixed priority level.
<br>
Write Operation:
<br>
0 = No effect.
<br>
1 = Set PDMA channel [n] to fixed priority channel.
<br>
Read Operation:
<br>
0 = Corresponding PDMA channel is round-robin priority.
<br>
1 = Corresponding PDMA channel is fixed priority.
<br>
Note: This field only set to fixed priority, clear fixed priority use PDMA_PRICLR register.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::PRICLR

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">PRICLR
</font><br><p> <font size="2">
Offset: 0x414  PDMA Fixed Priority Clear Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[4:0]</td><td>FPRICLRn</td><td><div style="word-wrap: break-word;"><b>PDMA Fixed Priority Clear Bits (Write Only)
</b><br>
Set this bit to 1 to clear fixed priority level.
<br>
0 = No effect.
<br>
1 = Clear PDMA channel [n] fixed priority setting.
<br>
Note: User can read PDMA_PRISET register to know the channel priority.
<br>
<br>
nterrupt Enable Register
<br>
------------------------------------------------------------------------------
<br>
Descriptions
<br>
 :---- |
<br>
</div></td></tr><tr><td>
[4:0]</td><td>INTENn</td><td><div style="word-wrap: break-word;"><b>PDMA Interrupt Enable Bits
</b><br>
This field is used to enable PDMA channel[n] interrupt.
<br>
0 = PDMA channel n interrupt Disabled.
<br>
1 = PDMA channel n interrupt Enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::INTSTS

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">INTSTS
</font><br><p> <font size="2">
Offset: 0x41C  PDMA Interrupt Status Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>ABTIF</td><td><div style="word-wrap: break-word;"><b>PDMA Read/Write Target Abort Interrupt Flag (Read Only)
</b><br>
This bit indicates that PDMA has target abort error; Software can read PDMA_ABTSTS register to find which channel has target abort error.
<br>
0 = No AHB bus ERROR response received.
<br>
1 = AHB bus ERROR response received.
<br>
</div></td></tr><tr><td>
[1]</td><td>TDIF</td><td><div style="word-wrap: break-word;"><b>Transfer Done Interrupt Flag (Read Only)
</b><br>
This bit indicates that PDMA controller has finished transmission; User can read PDMA_TDSTS register to indicate which channel finished transfer.
<br>
0 = Not finished yet.
<br>
1 = PDMA channel has finished transmission.
<br>
</div></td></tr><tr><td>
[2]</td><td>ALIGNF</td><td><div style="word-wrap: break-word;"><b>Transfer Alignment Interrupt Flag (Read Only)
</b><br>
0 = PDMA channel source address and destination address both follow transfer width setting.
<br>
1 = PDMA channel source address or destination address is not follow transfer width setting.
<br>
</div></td></tr><tr><td>
[8]</td><td>REQTOF0</td><td><div style="word-wrap: break-word;"><b>Request Time-out Flag for Channel 0
</b><br>
This flag indicates that PDMA controller has waited peripheral request for a period defined by PDMA_TOC0, user can write 1 to clear these bits.
<br>
0 = No request time-out.
<br>
1 = Peripheral request time-out.
<br>
</div></td></tr><tr><td>
[9]</td><td>REQTOF1</td><td><div style="word-wrap: break-word;"><b>Request Time-out Flag for Channel 1
</b><br>
This flag indicates that PDMA controller has waited peripheral request for a period defined by PDMA_TOC1, user can write 1 to clear these bits.
<br>
0 = No request time-out.
<br>
1 = Peripheral request time-out.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::ABTSTS

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">ABTSTS
</font><br><p> <font size="2">
Offset: 0x420  PDMA Channel Read/Write Target Abort Flag Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[4:0]</td><td>ABTIFn</td><td><div style="word-wrap: break-word;"><b>PDMA Read/Write Target Abort Interrupt Status Flag
</b><br>
This bit indicates which PDMA controller has target abort error; User can write 1 to clear these bits.
<br>
0 = No AHB bus ERROR response received when channel n transfer.
<br>
1 = AHB bus ERROR response received when channel n transfer.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::TDSTS

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">TDSTS
</font><br><p> <font size="2">
Offset: 0x424  PDMA Channel Transfer Done Flag Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[4:0]</td><td>TDIF0</td><td><div style="word-wrap: break-word;"><b>Transfer Done Flag
</b><br>
This bit indicates whether PDMA controller channel transfer has been finished or not, user can write 1 to clear these bits.
<br>
0 = PDMA channel transfer has not finished.
<br>
1 = PDMA channel has finished transmission.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::ALIGN

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">ALIGN
</font><br><p> <font size="2">
Offset: 0x428  PDMA Transfer Alignment Status Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[4:0]</td><td>ALIGNn</td><td><div style="word-wrap: break-word;"><b>Transfer Alignment Flag
</b><br>
0 = PDMA channel source address and destination address both follow transfer width setting.
<br>
1 = PDMA channel source address or destination address is not follow transfer width setting.
<br>
<br>
ransfer Active Flag Register
<br>
------------------------------------------------------------------------------
<br>
Descriptions
<br>
 :---- |
<br>
</div></td></tr><tr><td>
[4:0]</td><td>TXACTFn</td><td><div style="word-wrap: break-word;"><b>Transfer on Active Flag (Read Only)
</b><br>
This bit indicates which PDMA channel is in active.
<br>
0 = PDMA channel is not finished.
<br>
1 = PDMA channel is active.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::TOUTPSC

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">TOUTPSC
</font><br><p> <font size="2">
Offset: 0x430  PDMA Time-out Prescaler Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[2:0]</td><td>TOUTPSC0</td><td><div style="word-wrap: break-word;"><b>PDMA Channel 0 Time-out Clock Source Prescaler Bits
</b><br>
000 = PDMA channel 0 time-out clock source is HCLK/2^8.
<br>
001 = PDMA channel 0 time-out clock source is HCLK/2^9.
<br>
010 = PDMA channel 0 time-out clock source is HCLK/2^10.
<br>
011 = PDMA channel 0 time-out clock source is HCLK/2^11.
<br>
100 = PDMA channel 0 time-out clock source is HCLK/2^12.
<br>
101 = PDMA channel 0 time-out clock source is HCLK/2^13.
<br>
110 = PDMA channel 0 time-out clock source is HCLK/2^14.
<br>
111 = PDMA channel 0 time-out clock source is HCLK/2^15.
<br>
</div></td></tr><tr><td>
[6:4]</td><td>TOUTPSC1</td><td><div style="word-wrap: break-word;"><b>PDMA Channel 1 Time-out Clock Source Prescaler Bits
</b><br>
000 = PDMA channel 1 time-out clock source is HCLK/2^8.
<br>
001 = PDMA channel 1 time-out clock source is HCLK/2^9.
<br>
010 = PDMA channel 1 time-out clock source is HCLK/2^10.
<br>
011 = PDMA channel 1 time-out clock source is HCLK/2^11.
<br>
100 = PDMA channel 1 time-out clock source is HCLK/2^12.
<br>
101 = PDMA channel 1 time-out clock source is HCLK/2^13.
<br>
110 = PDMA channel 1 time-out clock source is HCLK/2^14.
<br>
111 = PDMA channel 1 time-out clock source is HCLK/2^15.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::TOUTEN

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">TOUTEN
</font><br><p> <font size="2">
Offset: 0x434  PDMA Time-out Enable Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[1:0]</td><td>TOUTENn</td><td><div style="word-wrap: break-word;"><b>PDMA Time-out Enable Bits
</b><br>
0 = PDMA Channel n time-out function Disabled.
<br>
1 = PDMA Channel n time-out function Enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::TOUTIEN

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">TOUTIEN
</font><br><p> <font size="2">
Offset: 0x438  PDMA Time-out Interrupt Enable Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[1:0]</td><td>TOUTIENn</td><td><div style="word-wrap: break-word;"><b>PDMA Time-out Interrupt Enable Bits
</b><br>
0 = PDMA Channel n time-out interrupt Disabled.
<br>
1 = PDMA Channel n time-out interrupt Enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::SCATBA

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">SCATBA
</font><br><p> <font size="2">
Offset: 0x43C  PDMA Scatter-gather Descriptor Table Base Address Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[31:16]</td><td>SCATBA</td><td><div style="word-wrap: break-word;"><b>PDMA Scatter-gather Descriptor Table Address
</b><br>
In Scatter-Gather mode, this is the base address for calculating the next link - list address
<br>
The next link address equation is
<br>
Next Link Address = PDMA_SCATBA + PDMA_DSCT_NEXT.
<br>
Note: Only useful in Scatter-Gather mode.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::TOC0_1

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">TOC0_1
</font><br><p> <font size="2">
Offset: 0x440  PDMA Time-out Counter Ch1 and Ch0 Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[15:0]</td><td>TOC0</td><td><div style="word-wrap: break-word;"><b>Time-out Counter for Channel 0
</b><br>
This controls the period of time-out function for channel 0
<br>
The calculation unit is based on 10 kHz clock.
<br>
</div></td></tr><tr><td>
[31:16]</td><td>TOC1</td><td><div style="word-wrap: break-word;"><b>Time-out Counter for Channel 1
</b><br>
This controls the period of time-out function for channel 1
<br>
The calculation unit is based on 10 kHz clock.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::CHRST

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CHRST
</font><br><p> <font size="2">
Offset: 0x460  PDMA Channel Reset Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[4:0]</td><td>CHnRST</td><td><div style="word-wrap: break-word;"><b>Channel N Reset
</b><br>
0 = corresponding channel n is not reset.
<br>
1 = corresponding channel n is reset.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::REQSEL0_3

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">REQSEL0_3
</font><br><p> <font size="2">
Offset: 0x480  PDMA Request Source Select Register 0
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[6:0]</td><td>REQSRC0</td><td><div style="word-wrap: break-word;"><b>Channel 0 Request Source Selection
</b><br>
This filed defines which peripheral is connected to PDMA channel 0
<br>
User can configure the peripheral by setting REQSRC0.
<br>
0 = Disable PDMA peripheral request.
<br>
1 = Reserved.
<br>
2 = Reserved.
<br>
3 = Reserved.
<br>
4 = Channel connects to UART0_TX.
<br>
5 = Channel connects to UART0_RX.
<br>
6 = Channel connects to UART1_TX.
<br>
7 = Channel connects to UART1_RX.
<br>
8 = Channel connects to UART2_TX.
<br>
9 = Channel connects to UART2_RX.
<br>
10 = Channel connects to UART3_TX.
<br>
11 = Channel connects to UART3_RX.
<br>
12 = Channel connects to UART4_TX.
<br>
13 = Channel connects to UART4_RX.
<br>
14 = Reserved.
<br>
15 = Reserved.
<br>
16 = Channel connects to USCI0_TX.
<br>
17 = Channel connects to USCI0_RX.
<br>
18 = Reserved.
<br>
19 = Reserved.
<br>
20 = Reserved.
<br>
21 = Reserved.
<br>
22 = Channel connects to SPI0_TX.
<br>
23 = Channel connects to SPI0_RX.
<br>
24 = Reserved.
<br>
25 = Reserved.
<br>
26 = Reserved.
<br>
27 = Reserved.
<br>
28 = Reserved.
<br>
29 = Reserved.
<br>
30 = Reserved.
<br>
31 = Reserved.
<br>
32 = Reserved.
<br>
33 = Reserved.
<br>
34 = Reserved.
<br>
35 = Reserved.
<br>
36 = Reserved.
<br>
37 = Reserved.
<br>
38 = Channel connects to I2C0_TX.
<br>
39 = Channel connects to I2C0_RX.
<br>
40 = Channel connects to I2C1_TX.
<br>
41 = Channel connects to I2C1_RX.
<br>
42 = Reserved.
<br>
43 = Reserved.
<br>
44 = Reserved.
<br>
45 = Reserved.
<br>
46 = Channel connects to TMR0.
<br>
47 = Channel connects to TMR1.
<br>
48 = Channel connects to TMR2.
<br>
49 = Channel connects to TMR3.
<br>
50 = Channel connects to ADC_RX.
<br>
51 = Reserved.
<br>
52 = Reserved.
<br>
53 = Reserved.
<br>
54 = Reserved.
<br>
55 = Reserved.
<br>
56 = Reserved.
<br>
57 = Reserved.
<br>
58 = Reserved.
<br>
59 = Reserved.
<br>
60 = Reserved.
<br>
61 = Reserved.
<br>
62 = Reserved.
<br>
63 = Reserved.
<br>
64 = Reserved.
<br>
65 = Reserved.
<br>
Others = Reserved.
<br>
Note 1: A peripheral cannot be assigned to two channels at the same time.
<br>
Note 2: This field is useless when transfer between memory and memory.
<br>
</div></td></tr><tr><td>
[14:8]</td><td>REQSRC1</td><td><div style="word-wrap: break-word;"><b>Channel 1 Request Source Selection
</b><br>
This filed defines which peripheral is connected to PDMA channel 1
<br>
User can configure the peripheral setting by REQSRC1.
<br>
Note: The channel configuration is the same as REQSRC0 field
<br>
Please refer to the explanation of REQSRC0.
<br>
</div></td></tr><tr><td>
[22:16]</td><td>REQSRC2</td><td><div style="word-wrap: break-word;"><b>Channel 2 Request Source Selection
</b><br>
This filed defines which peripheral is connected to PDMA channel 2
<br>
User can configure the peripheral setting by REQSRC2.
<br>
Note: The channel configuration is the same as REQSRC0 field
<br>
Please refer to the explanation of REQSRC0.
<br>
</div></td></tr><tr><td>
[30:24]</td><td>REQSRC3</td><td><div style="word-wrap: break-word;"><b>Channel 3 Request Source Selection
</b><br>
This filed defines which peripheral is connected to PDMA channel 3
<br>
User can configure the peripheral setting by REQSRC3.
<br>
Note: The channel configuration is the same as REQSRC0 field
<br>
Please refer to the explanation of REQSRC0.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var PDMA_T::REQSEL4_7

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">REQSEL4_7
</font><br><p> <font size="2">
Offset: 0x484  PDMA Request Source Select Register 1
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[6:0]</td><td>REQSRC4</td><td><div style="word-wrap: break-word;"><b>Channel 4 Request Source Selection
</b><br>
This filed defines which peripheral is connected to PDMA channel 4
<br>
User can configure the peripheral setting by REQSRC4.
<br>
Note: The channel configuration is the same as REQSRC0 field
<br>
Please refer to the explanation of REQSRC0.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly



 */
    DSCT_T        DSCT[5];               /*!< [0x0000 ~ 0x005C] Control Register of PDMA Channel 0 ~ 7                  */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[44];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t CURSCAT[5];            /*!< [0x0100 ~ 0x110] Current Scatter-gather Descriptor Table Address of PDMA Channel n */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[187];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CHCTL;                 /*!< [0x0400] PDMA Channel Control Register                                    */
    __O  uint32_t PAUSE;                 /*!< [0x0404] PDMA Transfer Pause Control Register                             */
    __O  uint32_t SWREQ;                 /*!< [0x0408] PDMA Software Request Register                                   */
    __I  uint32_t TRGSTS;                /*!< [0x040c] PDMA Channel Request Status Register                             */
    __IO uint32_t PRISET;                /*!< [0x0410] PDMA Fixed Priority Setting Register                             */
    __O  uint32_t PRICLR;                /*!< [0x0414] PDMA Fixed Priority Clear Register                               */
    __IO uint32_t INTEN;                 /*!< [0x0418] PDMA Interrupt Enable Register                                   */
    __IO uint32_t INTSTS;                /*!< [0x041c] PDMA Interrupt Status Register                                   */
    __IO uint32_t ABTSTS;                /*!< [0x0420] PDMA Channel Read/Write Target Abort Flag Register               */
    __IO uint32_t TDSTS;                 /*!< [0x0424] PDMA Channel Transfer Done Flag Register                         */
    __IO uint32_t ALIGN;                 /*!< [0x0428] PDMA Transfer Alignment Status Register                          */
    __I  uint32_t TACTSTS;               /*!< [0x042c] PDMA Transfer Active Flag Register                               */
    __IO uint32_t TOUTPSC;               /*!< [0x0430] PDMA Time-out Prescaler Register                                 */
    __IO uint32_t TOUTEN;                /*!< [0x0434] PDMA Time-out Enable Register                                    */
    __IO uint32_t TOUTIEN;               /*!< [0x0438] PDMA Time-out Interrupt Enable Register                          */
    __IO uint32_t SCATBA;                /*!< [0x043c] PDMA Scatter-gather Descriptor Table Base Address Register       */
    __IO uint32_t TOC0_1;                /*!< [0x0440] PDMA Time-out Counter Ch1 and Ch0 Register                       */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE2[7];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CHRST;                 /*!< [0x0460] PDMA Channel Reset Register                                      */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE3[7];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t REQSEL0_3;             /*!< [0x0480] PDMA Request Source Select Register 0                            */
    __IO uint32_t REQSEL4_7;             /*!< [0x0484] PDMA Request Source Select Register 1                            */
} PDMA_T;

/**
    @addtogroup PDMA_CONST PDMA Bit Field Definition
    Constant Definitions for PDMA Controller
@{ */

#define PDMA_DSCT_CTL_OPMODE_Pos         (0)                                               /*!< PDMA_T::DSCT_CTL: OPMODE Position      */
#define PDMA_DSCT_CTL_OPMODE_Msk         (0x3ul << PDMA_DSCT_CTL_OPMODE_Pos)               /*!< PDMA_T::DSCT_CTL: OPMODE Mask          */

#define PDMA_DSCT_CTL_TXTYPE_Pos         (2)                                               /*!< PDMA_T::DSCT_CTL: TXTYPE Position      */
#define PDMA_DSCT_CTL_TXTYPE_Msk         (0x1ul << PDMA_DSCT_CTL_TXTYPE_Pos)               /*!< PDMA_T::DSCT_CTL: TXTYPE Mask          */

#define PDMA_DSCT_CTL_BURSIZE_Pos        (4)                                               /*!< PDMA_T::DSCT_CTL: BURSIZE Position     */
#define PDMA_DSCT_CTL_BURSIZE_Msk        (0x7ul << PDMA_DSCT_CTL_BURSIZE_Pos)              /*!< PDMA_T::DSCT_CTL: BURSIZE Mask         */

#define PDMA_DSCT_CTL_TBINTDIS_Pos       (7)                                               /*!< PDMA_T::DSCT_CTL: TBINTDIS Position    */
#define PDMA_DSCT_CTL_TBINTDIS_Msk       (0x1ul << PDMA_DSCT_CTL_TBINTDIS_Pos)             /*!< PDMA_T::DSCT_CTL: TBINTDIS Mask        */

#define PDMA_DSCT_CTL_SAINC_Pos          (8)                                               /*!< PDMA_T::DSCT_CTL: SAINC Position       */
#define PDMA_DSCT_CTL_SAINC_Msk          (0x3ul << PDMA_DSCT_CTL_SAINC_Pos)                /*!< PDMA_T::DSCT_CTL: SAINC Mask           */

#define PDMA_DSCT_CTL_DAINC_Pos          (10)                                              /*!< PDMA_T::DSCT_CTL: DAINC Position       */
#define PDMA_DSCT_CTL_DAINC_Msk          (0x3ul << PDMA_DSCT_CTL_DAINC_Pos)                /*!< PDMA_T::DSCT_CTL: DAINC Mask           */

#define PDMA_DSCT_CTL_TXWIDTH_Pos        (12)                                              /*!< PDMA_T::DSCT_CTL: TXWIDTH Position     */
#define PDMA_DSCT_CTL_TXWIDTH_Msk        (0x3ul << PDMA_DSCT_CTL_TXWIDTH_Pos)              /*!< PDMA_T::DSCT_CTL: TXWIDTH Mask         */

#define PDMA_DSCT_CTL_TXACK_Pos          (14)                                              /*!< PDMA_T::DSCT_CTL: TXACK Position       */
#define PDMA_DSCT_CTL_TXACK_Msk          (0x1ul << PDMA_DSCT_CTL_TXACK_Pos)                /*!< PDMA_T::DSCT_CTL: TXACK Mask           */

#define PDMA_DSCT_CTL_TXCNT_Pos          (16)                                              /*!< PDMA_T::DSCT_CTL: TXCNT Position       */
#define PDMA_DSCT_CTL_TXCNT_Msk          (0xfffful << PDMA_DSCT_CTL_TXCNT_Pos)             /*!< PDMA_T::DSCT_CTL: TXCNT Mask           */

#define PDMA_DSCT_SA_SA_Pos              (0)                                               /*!< PDMA_T::DSCT_SA: SA Position           */
#define PDMA_DSCT_SA_SA_Msk              (0xfffffffful << PDMA_DSCT_SA_SA_Pos)             /*!< PDMA_T::DSCT_SA: SA Mask               */

#define PDMA_DSCT_DA_DA_Pos              (0)                                               /*!< PDMA_T::DSCT_DA: DA Position           */
#define PDMA_DSCT_DA_DA_Msk              (0xfffffffful << PDMA_DSCT_DA_DA_Pos)             /*!< PDMA_T::DSCT_DA: DA Mask               */

#define PDMA_DSCT_NEXT_NEXT_Pos          (0)                                               /*!< PDMA_T::DSCT_NEXT: NEXT Position       */
#define PDMA_DSCT_NEXT_NEXT_Msk          (0xfffful << PDMA_DSCT_NEXT_NEXT_Pos)             /*!< PDMA_T::DSCT_NEXT: NEXT Mask           */

#define PDMA_DSCT_NEXT_EXENEXT_Pos       (16)                                              /*!< PDMA_T::DSCT_NEXT: EXENEXT Position    */
#define PDMA_DSCT_NEXT_EXENEXT_Msk       (0xfffful << PDMA_DSCT0_NEXT_EXENEXT_Pos)         /*!< PDMA_T::DSCT_NEXT: EXENEXT Mask        */

#define PDMA_CURSCAT_CURADDR_Pos         (0)                                               /*!< PDMA_T::CURSCAT: CURADDR Position      */
#define PDMA_CURSCAT_CURADDR_Msk         (0xfffffffful << PDMA_CURSCAT_CURADDR_Pos)        /*!< PDMA_T::CURSCAT: CURADDR Mask          */

#define PDMA_CHCTL_CHENn_Pos             (0)                                               /*!< PDMA_T::CHCTL: CHENn Position          */
#define PDMA_CHCTL_CHENn_Msk             (0x1ful << PDMA_CHCTL_CHENn_Pos)                /*!< PDMA_T::CHCTL: CHENn Mask              */

#define PDMA_PAUSE_PAUSEn_Pos            (0)                                               /*!< PDMA_T::PAUSE: PAUSEn Position           */
#define PDMA_PAUSE_PAUSEn_Msk            (0x1ful << PDMA_PAUSE_PAUSEn_Pos)              /*!< PDMA_T::PAUSE: PAUSEn Mask               */

#define PDMA_SWREQ_SWREQn_Pos            (0)                                               /*!< PDMA_T::SWREQ: SWREQn Position         */
#define PDMA_SWREQ_SWREQn_Msk            (0x1ful << PDMA_SWREQ_SWREQn_Pos)               /*!< PDMA_T::SWREQ: SWREQn Mask             */

#define PDMA_TRGSTS_REQSTSn_Pos          (0)                                               /*!< PDMA_T::TRGSTS: REQSTSn Position       */
#define PDMA_TRGSTS_REQSTSn_Msk          (0x1ful << PDMA_TRGSTS_REQSTSn_Pos)             /*!< PDMA_T::TRGSTS: REQSTSn Mask           */

#define PDMA_PRISET_FPRISETn_Pos         (0)                                               /*!< PDMA_T::PRISET: FPRISETn Position      */
#define PDMA_PRISET_FPRISETn_Msk         (0x1ful << PDMA_PRISET_FPRISETn_Pos)            /*!< PDMA_T::PRISET: FPRISETn Mask          */

#define PDMA_PRICLR_FPRICLRn_Pos         (0)                                               /*!< PDMA_T::PRICLR: FPRICLRn Position      */
#define PDMA_PRICLR_FPRICLRn_Msk         (0x1ful << PDMA_PRICLR_FPRICLRn_Pos)            /*!< PDMA_T::PRICLR: FPRICLRn Mask          */

#define PDMA_INTEN_INTENn_Pos            (0)                                               /*!< PDMA_T::INTEN: INTENn Position         */
#define PDMA_INTEN_INTENn_Msk            (0x1ful << PDMA_INTEN_INTENn_Pos)               /*!< PDMA_T::INTEN: INTENn Mask             */

#define PDMA_INTSTS_ABTIF_Pos            (0)                                               /*!< PDMA_T::INTSTS: ABTIF Position         */
#define PDMA_INTSTS_ABTIF_Msk            (0x1ul << PDMA_INTSTS_ABTIF_Pos)                  /*!< PDMA_T::INTSTS: ABTIF Mask             */

#define PDMA_INTSTS_TDIF_Pos             (1)                                               /*!< PDMA_T::INTSTS: TDIF Position          */
#define PDMA_INTSTS_TDIF_Msk             (0x1ul << PDMA_INTSTS_TDIF_Pos)                   /*!< PDMA_T::INTSTS: TDIF Mask              */

#define PDMA_INTSTS_ALIGNF_Pos           (2)                                               /*!< PDMA_T::INTSTS: ALIGNF Position        */
#define PDMA_INTSTS_ALIGNF_Msk           (0x1ul << PDMA_INTSTS_ALIGNF_Pos)                 /*!< PDMA_T::INTSTS: ALIGNF Mask            */

#define PDMA_INTSTS_REQTOF0_Pos          (8)                                               /*!< PDMA_T::INTSTS: REQTOF0 Position       */
#define PDMA_INTSTS_REQTOF0_Msk          (0x1ul << PDMA_INTSTS_REQTOF0_Pos)                /*!< PDMA_T::INTSTS: REQTOF0 Mask           */

#define PDMA_INTSTS_REQTOF1_Pos          (9)                                               /*!< PDMA_T::INTSTS: REQTOF1 Position       */
#define PDMA_INTSTS_REQTOF1_Msk          (0x1ul << PDMA_INTSTS_REQTOF1_Pos)                /*!< PDMA_T::INTSTS: REQTOF1 Mask           */

#define PDMA_ABTSTS_ABTIF0_Pos           (0)                                               /*!< PDMA_T::ABTSTS: ABTIF0 Position        */
#define PDMA_ABTSTS_ABTIF0_Msk           (0x1ul << PDMA_ABTSTS_ABTIF0_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF0 Mask            */

#define PDMA_ABTSTS_ABTIF1_Pos           (1)                                               /*!< PDMA_T::ABTSTS: ABTIF1 Position        */
#define PDMA_ABTSTS_ABTIF1_Msk           (0x1ul << PDMA_ABTSTS_ABTIF1_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF1 Mask            */

#define PDMA_ABTSTS_ABTIF2_Pos           (2)                                               /*!< PDMA_T::ABTSTS: ABTIF2 Position        */
#define PDMA_ABTSTS_ABTIF2_Msk           (0x1ul << PDMA_ABTSTS_ABTIF2_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF2 Mask            */

#define PDMA_ABTSTS_ABTIF3_Pos           (3)                                               /*!< PDMA_T::ABTSTS: ABTIF3 Position        */
#define PDMA_ABTSTS_ABTIF3_Msk           (0x1ul << PDMA_ABTSTS_ABTIF3_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF3 Mask            */

#define PDMA_ABTSTS_ABTIF4_Pos           (4)                                               /*!< PDMA_T::ABTSTS: ABTIF4 Position        */
#define PDMA_ABTSTS_ABTIF4_Msk           (0x1ul << PDMA_ABTSTS_ABTIF4_Pos)                 /*!< PDMA_T::ABTSTS: ABTIF4 Mask            */

#define PDMA_TDSTS_TDIF0_Pos             (0)                                               /*!< PDMA_T::TDSTS: TDIF0 Position          */
#define PDMA_TDSTS_TDIF0_Msk             (0x1ul << PDMA_TDSTS_TDIF0_Pos)                   /*!< PDMA_T::TDSTS: TDIF0 Mask              */

#define PDMA_TDSTS_TDIF1_Pos             (1)                                               /*!< PDMA_T::TDSTS: TDIF1 Position          */
#define PDMA_TDSTS_TDIF1_Msk             (0x1ul << PDMA_TDSTS_TDIF1_Pos)                   /*!< PDMA_T::TDSTS: TDIF1 Mask              */

#define PDMA_TDSTS_TDIF2_Pos             (2)                                               /*!< PDMA_T::TDSTS: TDIF2 Position          */
#define PDMA_TDSTS_TDIF2_Msk             (0x1ul << PDMA_TDSTS_TDIF2_Pos)                   /*!< PDMA_T::TDSTS: TDIF2 Mask              */

#define PDMA_TDSTS_TDIF3_Pos             (3)                                               /*!< PDMA_T::TDSTS: TDIF3 Position          */
#define PDMA_TDSTS_TDIF3_Msk             (0x1ul << PDMA_TDSTS_TDIF3_Pos)                   /*!< PDMA_T::TDSTS: TDIF3 Mask              */

#define PDMA_TDSTS_TDIF4_Pos             (4)                                               /*!< PDMA_T::TDSTS: TDIF4 Position          */
#define PDMA_TDSTS_TDIF4_Msk             (0x1ul << PDMA_TDSTS_TDIF4_Pos)                   /*!< PDMA_T::TDSTS: TDIF4 Mask              */

#define PDMA_ALIGN_ALIGNn_Pos            (0)                                               /*!< PDMA_T::ALIGN: ALIGNn Position        */
#define PDMA_ALIGN_ALIGNn_Msk            (0x1ful << PDMA_ALIGN_ALIGNn_Pos)                 /*!< PDMA_T::ALIGN: ALIGNn Mask            */

#define PDMA_TACTSTS_TXACTFn_Pos         (0)                                               /*!< PDMA_T::TACTSTS: TXACTFn Position      */
#define PDMA_TACTSTS_TXACTFn_Msk         (0x1ful << PDMA_TACTSTS_TXACTFn_Pos)              /*!< PDMA_T::TACTSTS: TXACTFn Mask          */

#define PDMA_TOUTPSC_TOUTPSC0_Pos        (0)                                               /*!< PDMA_T::TOUTPSC: TOUTPSC0 Position     */
#define PDMA_TOUTPSC_TOUTPSC0_Msk        (0x7ul << PDMA_TOUTPSC_TOUTPSC0_Pos)              /*!< PDMA_T::TOUTPSC: TOUTPSC0 Mask         */

#define PDMA_TOUTPSC_TOUTPSC1_Pos        (4)                                               /*!< PDMA_T::TOUTPSC: TOUTPSC1 Position     */
#define PDMA_TOUTPSC_TOUTPSC1_Msk        (0x7ul << PDMA_TOUTPSC_TOUTPSC1_Pos)              /*!< PDMA_T::TOUTPSC: TOUTPSC1 Mask         */

#define PDMA_TOUTEN_TOUTENn_Pos          (0)                                               /*!< PDMA_T::TOUTEN: TOUTENn Position       */
#define PDMA_TOUTEN_TOUTENn_Msk          (0x3ul << PDMA_TOUTEN_TOUTENn_Pos)                /*!< PDMA_T::TOUTEN: TOUTENn Mask           */

#define PDMA_TOUTIEN_TOUTIENn_Pos        (0)                                               /*!< PDMA_T::TOUTIEN: TOUTIENn Position     */
#define PDMA_TOUTIEN_TOUTIENn_Msk        (0x3ul << PDMA_TOUTIEN_TOUTIENn_Pos)              /*!< PDMA_T::TOUTIEN: TOUTIENn Mask         */

#define PDMA_SCATBA_SCATBA_Pos           (16)                                              /*!< PDMA_T::SCATBA: SCATBA Position        */
#define PDMA_SCATBA_SCATBA_Msk           (0xfffful << PDMA_SCATBA_SCATBA_Pos)              /*!< PDMA_T::SCATBA: SCATBA Mask            */

#define PDMA_TOC0_1_TOC0_Pos             (0)                                               /*!< PDMA_T::TOC0_1: TOC0 Position          */
#define PDMA_TOC0_1_TOC0_Msk             (0xfffful << PDMA_TOC0_1_TOC0_Pos)                /*!< PDMA_T::TOC0_1: TOC0 Mask              */

#define PDMA_TOC0_1_TOC1_Pos             (16)                                              /*!< PDMA_T::TOC0_1: TOC1 Position          */
#define PDMA_TOC0_1_TOC1_Msk             (0xfffful << PDMA_TOC0_1_TOC1_Pos)                /*!< PDMA_T::TOC0_1: TOC1 Mask              */

#define PDMA_CHRST_CHnRST_Pos            (0)                                               /*!< PDMA_T::CHRST: CHnRST Position         */
#define PDMA_CHRST_CHnRST_Msk            (0x1ful << PDMA_CHRST_CHnRST_Pos)               /*!< PDMA_T::CHRST: CHnRST Mask             */

#define PDMA_REQSEL0_3_REQSRC0_Pos       (0)                                               /*!< PDMA_T::REQSEL0_3: REQSRC0 Position    */
#define PDMA_REQSEL0_3_REQSRC0_Msk       (0x7ful << PDMA_REQSEL0_3_REQSRC0_Pos)            /*!< PDMA_T::REQSEL0_3: REQSRC0 Mask        */

#define PDMA_REQSEL0_3_REQSRC1_Pos       (8)                                               /*!< PDMA_T::REQSEL0_3: REQSRC1 Position    */
#define PDMA_REQSEL0_3_REQSRC1_Msk       (0x7ful << PDMA_REQSEL0_3_REQSRC1_Pos)            /*!< PDMA_T::REQSEL0_3: REQSRC1 Mask        */

#define PDMA_REQSEL0_3_REQSRC2_Pos       (16)                                              /*!< PDMA_T::REQSEL0_3: REQSRC2 Position    */
#define PDMA_REQSEL0_3_REQSRC2_Msk       (0x7ful << PDMA_REQSEL0_3_REQSRC2_Pos)            /*!< PDMA_T::REQSEL0_3: REQSRC2 Mask        */

#define PDMA_REQSEL0_3_REQSRC3_Pos       (24)                                              /*!< PDMA_T::REQSEL0_3: REQSRC3 Position    */
#define PDMA_REQSEL0_3_REQSRC3_Msk       (0x7ful << PDMA_REQSEL0_3_REQSRC3_Pos)            /*!< PDMA_T::REQSEL0_3: REQSRC3 Mask        */

#define PDMA_REQSEL4_7_REQSRC4_Pos       (0)                                               /*!< PDMA_T::REQSEL4_7: REQSRC4 Position    */
#define PDMA_REQSEL4_7_REQSRC4_Msk       (0x7ful << PDMA_REQSEL4_7_REQSRC4_Pos)            /*!< PDMA_T::REQSEL4_7: REQSRC4 Mask        */

/** @} PDMA_CONST */
/** @} end of PDMA register group */
/** @} end of REGISTER group */

#if defined ( __CC_ARM   )
    #pragma no_anon_unions
#endif

#endif /* __PDMA_REG_H__ */
