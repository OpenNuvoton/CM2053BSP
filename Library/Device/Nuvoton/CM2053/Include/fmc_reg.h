/**************************************************************************//**
 * @file     fmc_reg.h
 * @version  V1.00
 * @brief    FMC register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __FMC_REG_H__
#define __FMC_REG_H__

#if defined ( __CC_ARM   )
    #pragma anon_unions
#endif

/**
    @addtogroup REGISTER Control Register
    @{
*/

/**
    @addtogroup FMC Flash Memory Controller (FMC)
    Memory Mapped Structure for FMC Controller
    @{
*/

typedef struct
{


    /**
@var FMC_T::ISPCTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">ISPCTL
</font><br><p> <font size="2">
Offset: 0x00  ISP Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>ISPEN</td><td><div style="word-wrap: break-word;"><b>ISP Enable Bit (Write Protect)
</b><br>
ISP function enable bit. Set this bit to enable ISP function.
<br>
0 = ISP function Disabled.
<br>
1 = ISP function Enabled.
<br>
Note: This bit is write-protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr><tr><td>
[1]</td><td>BS</td><td><div style="word-wrap: break-word;"><b>Boot Select (Write Protect)
</b><br>
Set/clear this bit to select next booting from LDROM/APROM, respectively
<br>
This bit also functions as chip booting status flag, which can be used to check where chip booted from
<br>
This bit is initiated with the inversed value of CBS[1] (CONFIG0[7]) after any reset is happened except CPU reset (CPU is 1) or system reset (SYS) is happened
<br>
0 = Booting from APROM.
<br>
1 = Booting from LDROM.
<br>
Note: This bit is write-protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr><tr><td>
[3]</td><td>APUEN</td><td><div style="word-wrap: break-word;"><b>APROM Update Enable Bit (Write Protect)
</b><br>
0 = APROM cannot be updated when the chip runs in APROM.
<br>
1 = APROM can be updated when the chip runs in APROM.
<br>
Note: This bit is write-protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr><tr><td>
[4]</td><td>CFGUEN</td><td><div style="word-wrap: break-word;"><b>CONFIG Update Enable Bit (Write Protect)
</b><br>
0 = CONFIG cannot be updated.
<br>
1 = CONFIG can be updated.
<br>
Note: This bit is write-protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr><tr><td>
[5]</td><td>LDUEN</td><td><div style="word-wrap: break-word;"><b>LDROM Update Enable Bit (Write Protect)
</b><br>
LDROM update enable bit.
<br>
0 = LDROM cannot be updated.
<br>
1 = LDROM can be updated.
<br>
Note: This bit is write-protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr><tr><td>
[6]</td><td>ISPFF</td><td><div style="word-wrap: break-word;"><b>ISP Fail Flag (Write Protect)
</b><br>
This bit is set by hardware when a triggered ISP meets any of the following conditions:
<br>
This bit needs to be cleared by writing 1 to it.
<br>
(1) APROM writes to itself if APUEN is set to 0.
<br>
(2) LDROM writes to itself if LDUEN is set to 0.
<br>
(3) CONFIG is erased/programmed if CFGUEN is set to 0.
<br>
(4) Page Erase command at LOCK mode with ICE connection
<br>
(5) Erase or Program command at brown-out detected
<br>
(6) Destination address is illegal, such as over an available range.
<br>
(7) Invalid ISP commands
<br>
(8) ISP CMD in XOM region, except mass erase, page erase and chksum command
<br>
(9) The wrong setting of page erase ISP CMD in XOM
<br>
(10) Violate XOM setting one time protection
<br>
Note: This bit is write-protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::ISPADDR

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">ISPADDR
</font><br><p> <font size="2">
Offset: 0x04  ISP Address Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[31:0]</td><td>ISPADDR</td><td><div style="word-wrap: break-word;"><b>ISP Address
</b><br>
For Checksum Calculation command, this field is the Flash starting address for checksum calculation, 512 bytes alignment is necessary for checksum calculation.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::ISPDAT

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">ISPDAT
</font><br><p> <font size="2">
Offset: 0x08  ISP Data Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[31:0]</td><td>ISPDAT</td><td><div style="word-wrap: break-word;"><b>ISP Data
</b><br>
Write data to this register before ISP program operation.
<br>
Read data from this register after ISP read operation.
<br>
For Run Checksum Calculation command, ISPDAT is the memory size (byte) and 512 bytes alignment
<br>
For ISP Read Checksum command, ISPDAT is the checksum result
<br>
If ISPDAT = 0x0000_0000, it means that (1) the checksum calculation is in progress, (2) the memory range for checksum calculation is incorrect.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::ISPCMD

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">ISPCMD
</font><br><p> <font size="2">
Offset: 0x0C  ISP CMD Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[6:0]</td><td>CMD</td><td><div style="word-wrap: break-word;"><b>ISP CMD
</b><br>
ISP command table is shown below:
<br>
0x00= FLASH Read.
<br>
0x04= Read Unique ID.
<br>
0x0B= Read Company ID.
<br>
0x0C= Read Device ID.
<br>
0x0D= Read Checksum.
<br>
0x21= FLASH 32-bit Program.
<br>
0x22= FLASH Page Erase.
<br>
0x27= FLASH Multi-Word Program.
<br>
0x28= Run Flash All-One Verification.
<br>
0x2D= Run Checksum Calculation.
<br>
0x2E= Vector Remap.
<br>
The other commands are invalid.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::ISPTRG

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">ISPTRG
</font><br><p> <font size="2">
Offset: 0x10  ISP Trigger Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>ISPGO</td><td><div style="word-wrap: break-word;"><b>ISP Start Trigger (Write Protect)
</b><br>
Write 1 to start ISP operation and this bit will be cleared to 0 by hardware automatically when ISP operation is finished.
<br>
0 = ISP operation is finished.
<br>
1 = ISP is progressed.
<br>
Note: This bit is write-protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::FTCTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">FTCTL
</font><br><p> <font size="2">
Offset: 0x18  Flash Access Time Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[9]</td><td>CACHEINV</td><td><div style="word-wrap: break-word;"><b>Flash Cache Invalidation (Write Protect)
</b><br>
Write 1 to start cache invalidation. The value will be change to 0 once the process finishes.
<br>
0 = Flash Cache Invalidation.(default)
<br>
1 = Flash Cache Invalidation.
<br>
Note: This bit is write-protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::ISPSTS

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">ISPSTS
</font><br><p> <font size="2">
Offset: 0x40  ISP Status Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>ISPBUSY</td><td><div style="word-wrap: break-word;"><b>ISP Busy Flag (Read Only)
</b><br>
Write 1 to start ISP operation and this bit will be cleared to 0 by hardware automatically when ISP operation is finished.
<br>
This bit is the mirror of ISPGO(FMC_ISPTRG[0]).
<br>
0 = ISP operation is finished.
<br>
1 = ISP is progressed.
<br>
</div></td></tr><tr><td>
[2:1]</td><td>CBS</td><td><div style="word-wrap: break-word;"><b>Boot Selection of CONFIG (Read Only)
</b><br>
This bit is initiated with the CBS (CONFIG0[7:6]) after any reset is happened except CPU reset (CPU is 1) or system reset (SYS) is happened.
<br>
00 = LDROM with IAP mode.
<br>
01 = LDROM without IAP mode.
<br>
10 = APROM with IAP mode.
<br>
11 = APROM without IAP mode.
<br>
</div></td></tr><tr><td>
[5]</td><td>PGFF</td><td><div style="word-wrap: break-word;"><b>Flash Program with Fast Verification Flag (Read Only)
</b><br>
This bit is set if data is mismatched at ISP programming verification
<br>
This bit is clear by performing ISP Flash erase or ISP read CID operation
<br>
0 = Flash Program is success.
<br>
1 = Flash Program is fail. Program data is different with data in the Flash memory
<br>
</div></td></tr><tr><td>
[6]</td><td>ISPFF</td><td><div style="word-wrap: break-word;"><b>ISP Fail Flag (Write Protect)
</b><br>
This bit is the mirror of ISPFF (FMC_ISPCTL[6]), it needs to be cleared by writing 1 to FMC_ISPCTL[6] or FMC_ISPSTS[6]
<br>
This bit is set by hardware when a triggered ISP meets any of the following conditions:
<br>
(1) APROM writes to itself if APUEN is set to 0.
<br>
(2) LDROM writes to itself if LDUEN is set to 0.
<br>
(3) CONFIG is erased/programmed if CFGUEN is set to 0.
<br>
(4) Page Erase command at LOCK mode with ICE connection
<br>
(5) Erase or Program command at brown-out detected
<br>
(6) Destination address is illegal, such as over an available range.
<br>
(7) Invalid ISP commands
<br>
(8) ISP CMD in XOM region, except mass erase, page erase and chksum command
<br>
(9) The wrong setting of page erase ISP CMD in XOM
<br>
(10) Violate XOM setting one time protection
<br>
Note: This bit is write-protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr><tr><td>
[7]</td><td>ALLONE</td><td><div style="word-wrap: break-word;"><b>Flash All-one Verification Flag
</b><br>
This bit is set by hardware if all of Flash bits are 1, and clear if Flash bits are not all 1 after "Run Flash All-One Verification" complete; this bit also can be clear by writing 1
<br>
0 = Flash bits are not all 1 after "Run Flash All-One Verification" complete.
<br>
1 = All of Flash bits are 1 after "Run Flash All-One Verification" complete.
<br>
</div></td></tr><tr><td>
[29:9]</td><td>VECMAP</td><td><div style="word-wrap: break-word;"><b>Vector Page Mapping Address (Read Only)
</b><br>
All access to 0x0000_0000~0x0000_01FF is remapped to the Flash memory or SRAM address {VECMAP[20:0], 9'h000} ~ {VECMAP[20:0], 9'h1FF}.
<br>
VECMAP [20:19] = 00 system vector address is mapped to Flash memory.
<br>
VECMAP [20:19] = 10 system vector address is mapped to SRAM memory.
<br>
VECMAP [18:12] should be 0.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::CYCCTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CYCCTL
</font><br><p> <font size="2">
Offset: 0x4C  Flash Access Cycle Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[3:0]</td><td>CYCLE</td><td><div style="word-wrap: break-word;"><b>Flash Access Cycle Control (Write Protect)
</b><br>
0001 = CPU access with zero wait cycle ; Flash access cycle is 1;.
<br>
The HCLK working frequency range is <19MHz; Cache is disabled by hardware.
<br>
0010 = CPU access with one wait cycles if cache miss; Flash access cycle is 2;.
<br>
 The optimized HCLK working frequency range is 18~33 MHz
<br>
0011 = CPU access with two wait cycles if cahce miss; Flash access cycle is 3;.
<br>
 The optimized HCLK working frequency range is 33~50 MHz
<br>
Note: This bit is write protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::MPDAT0

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">MPDAT0
</font><br><p> <font size="2">
Offset: 0x80  ISP Data0 Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[31:0]</td><td>ISPDAT0</td><td><div style="word-wrap: break-word;"><b>ISP Data 0
</b><br>
This register is the first 32-bit data for 32-bit/64-bit/multi-word programming, and it is also the mirror of FMC_ISPDAT, both registers keep the same data
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::MPDAT1

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">MPDAT1
</font><br><p> <font size="2">
Offset: 0x84  ISP Data1 Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[31:0]</td><td>ISPDAT1</td><td><div style="word-wrap: break-word;"><b>ISP Data 1
</b><br>
This register is the second 32-bit data for 64-bit/multi-word programming.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::MPDAT2

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">MPDAT2
</font><br><p> <font size="2">
Offset: 0x88  ISP Data2 Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[31:0]</td><td>ISPDAT2</td><td><div style="word-wrap: break-word;"><b>ISP Data 2
</b><br>
This register is the third 32-bit data for multi-word programming.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::MPDAT3

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">MPDAT3
</font><br><p> <font size="2">
Offset: 0x8C  ISP Data3 Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[31:0]</td><td>ISPDAT3</td><td><div style="word-wrap: break-word;"><b>ISP Data 3
</b><br>
This register is the fourth 32-bit data for multi-word programming.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::MPSTS

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">MPSTS
</font><br><p> <font size="2">
Offset: 0xC0  ISP Multi-program Status Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>MPBUSY</td><td><div style="word-wrap: break-word;"><b>ISP Multi-word Program Busy Flag (Read Only)
</b><br>
Write 1 to start ISP Multi-Word program operation and this bit will be cleared to 0 by hardware automatically when ISP Multi-Word program operation is finished.
<br>
This bit is the mirror of ISPGO(FMC_ISPTRG[0]).
<br>
0 = ISP Multi-Word program operation is finished.
<br>
1 = ISP Multi-Word program operation is progressed.
<br>
</div></td></tr><tr><td>
[1]</td><td>PPGO</td><td><div style="word-wrap: break-word;"><b>ISP Multi-program Status (Read Only)
</b><br>
0 = ISP multi-word program operation is not active.
<br>
1 = ISP multi-word program operation is in progress.
<br>
</div></td></tr><tr><td>
[2]</td><td>ISPFF</td><td><div style="word-wrap: break-word;"><b>ISP Fail Flag (Read Only)
</b><br>
This bit is the mirror of ISPFF (FMC_ISPCTL[6]), it needs to be cleared by writing 1 to FMC_ISPCTL[6] or FMC_ISPSTS[6]
<br>
This bit is set by hardware when a triggered ISP meets any of the following conditions:
<br>
(1) APROM writes to itself if APUEN is set to 0.
<br>
(2) LDROM writes to itself if LDUEN is set to 0.
<br>
(3) CONFIG is erased/programmed if CFGUEN is set to 0.
<br>
(4) Page Erase command at LOCK mode with ICE connection
<br>
(5) Erase or Program command at brown-out detected
<br>
(6) Destination address is illegal, such as over an available range.
<br>
(7) Invalid ISP commands
<br>
</div></td></tr><tr><td>
[4]</td><td>D0</td><td><div style="word-wrap: break-word;"><b>ISP DATA 0 Flag (Read Only)
</b><br>
This bit is set when FMC_MPDAT0 is written and auto-clear to 0 when the FMC_MPDAT0 data is programmed to Flash complete.
<br>
0 = FMC_MPDAT0 register is empty, or program to Flash complete.
<br>
1 = FMC_MPDAT0 register has been written, and not program to Flash complete.
<br>
</div></td></tr><tr><td>
[5]</td><td>D1</td><td><div style="word-wrap: break-word;"><b>ISP DATA 1 Flag (Read Only)
</b><br>
This bit is set when FMC_MPDAT1 is written and auto-clear to 0 when the FMC_MPDAT1 data is programmed to Flash complete.
<br>
0 = FMC_MPDAT1 register is empty, or program to Flash complete.
<br>
1 = FMC_MPDAT1 register has been written, and not program to Flash complete.
<br>
</div></td></tr><tr><td>
[6]</td><td>D2</td><td><div style="word-wrap: break-word;"><b>ISP DATA 2 Flag (Read Only)
</b><br>
This bit is set when FMC_MPDAT2 is written and auto-clear to 0 when the FMC_MPDAT2 data is programmed to Flash complete.
<br>
0 = FMC_MPDAT2 register is empty, or program to Flash complete.
<br>
1 = FMC_MPDAT2 register has been written, and not program to Flash complete.
<br>
</div></td></tr><tr><td>
[7]</td><td>D3</td><td><div style="word-wrap: break-word;"><b>ISP DATA 3 Flag (Read Only)
</b><br>
This bit is set when FMC_MPDAT3 is written and auto-clear to 0 when the FMC_MPDAT3 data is programmed to Flash complete.
<br>
0 = FMC_MPDAT3 register is empty, or program to Flash complete.
<br>
1 = FMC_MPDAT3 register has been written, and not program to Flash complete.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::MPADDR

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">MPADDR
</font><br><p> <font size="2">
Offset: 0xC4  ISP Multi-program Address Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[31:0]</td><td>MPADDR</td><td><div style="word-wrap: break-word;"><b>ISP Multi-word Program Address
</b><br>
MPADDR is the address of ISP multi-word program operation when ISPGO flag is 1.
<br>
MPADDR will keep the final ISP address when ISP multi-word program is complete.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::XOMR0STS0

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">XOMR0STS0
</font><br><p> <font size="2">
Offset: 0xD0  XOM Region 0 Status Register 0
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[23:0]</td><td>BASE</td><td><div style="word-wrap: break-word;"><b>XOM Region 0 Base Address (Page-aligned)
</b><br>
BASE is the base address of XOM Region 0.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::XOMR0STS1

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">XOMR0STS1
</font><br><p> <font size="2">
Offset: 0xD4  XOM Region 0 Status Register 1
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[8:0]</td><td>SIZE</td><td><div style="word-wrap: break-word;"><b>XOM Region 0 Size (Page-aligned)
</b><br>
SIZE is the page number of XOM Region 0.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var FMC_T::XOMSTS

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">XOMSTS
</font><br><p> <font size="2">
Offset: 0xE0  XOM Status Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>XOMR0ON</td><td><div style="word-wrap: break-word;"><b>XOM Region 0 On
</b><br>
XOM Region 0 active status.
<br>
0 = No active.
<br>
1 = XOM region 0 is active.
<br>
</div></td></tr><tr><td>
[4]</td><td>XOMPEF</td><td><div style="word-wrap: break-word;"><b>XOM Page Erase Function Fail
</b><br>
XOM page erase function status. If XOMPEF is set to 1, user needs to erase XOM region again.
<br>
0 = Sucess.
<br>
1 = Fail.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly



 */
    __IO uint32_t ISPCTL;                /*!< [0x0000] ISP Control Register                                             */
    __IO uint32_t ISPADDR;               /*!< [0x0004] ISP Address Register                                             */
    __IO uint32_t ISPDAT;                /*!< [0x0008] ISP Data Register                                                */
    __IO uint32_t ISPCMD;                /*!< [0x000c] ISP CMD Register                                                 */
    __IO uint32_t ISPTRG;                /*!< [0x0010] ISP Trigger Control Register                                     */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0;
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t FTCTL;                 /*!< [0x0018] Flash Access Time Control Register                               */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[9];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t ISPSTS;                /*!< [0x0040] ISP Status Register                                              */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE2[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CYCCTL;                /*!< [0x004c] Flash Access Cycle Control Register                              */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE3[12];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t MPDAT0;                /*!< [0x0080] ISP Data0 Register                                               */
    __IO uint32_t MPDAT1;                /*!< [0x0084] ISP Data1 Register                                               */
    __IO uint32_t MPDAT2;                /*!< [0x0088] ISP Data2 Register                                               */
    __IO uint32_t MPDAT3;                /*!< [0x008c] ISP Data3 Register                                               */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE4[12];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t MPSTS;                 /*!< [0x00c0] ISP Multi-program Status Register                                */
    __I  uint32_t MPADDR;                /*!< [0x00c4] ISP Multi-program Address Register                               */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE5[2];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t XOMR0STS0;             /*!< [0x00d0] XOM Region 0 Status Register 0                                   */
    __I  uint32_t XOMR0STS1;             /*!< [0x00d4] XOM Region 0 Status Register 1                                   */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE6[2];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t XOMSTS;                /*!< [0x00e0] XOM Status Register                                              */
} FMC_T;

/**
    @addtogroup FMC_CONST FMC Bit Field Definition
    Constant Definitions for FMC Controller
@{ */

#define FMC_ISPCTL_ISPEN_Pos             (0)                                               /*!< FMC_T::ISPCTL: ISPEN Position          */
#define FMC_ISPCTL_ISPEN_Msk             (0x1ul << FMC_ISPCTL_ISPEN_Pos)                   /*!< FMC_T::ISPCTL: ISPEN Mask              */

#define FMC_ISPCTL_BS_Pos                (1)                                               /*!< FMC_T::ISPCTL: BS Position             */
#define FMC_ISPCTL_BS_Msk                (0x1ul << FMC_ISPCTL_BS_Pos)                      /*!< FMC_T::ISPCTL: BS Mask                 */

#define FMC_ISPCTL_APUEN_Pos             (3)                                               /*!< FMC_T::ISPCTL: APUEN Position          */
#define FMC_ISPCTL_APUEN_Msk             (0x1ul << FMC_ISPCTL_APUEN_Pos)                   /*!< FMC_T::ISPCTL: APUEN Mask              */

#define FMC_ISPCTL_CFGUEN_Pos            (4)                                               /*!< FMC_T::ISPCTL: CFGUEN Position         */
#define FMC_ISPCTL_CFGUEN_Msk            (0x1ul << FMC_ISPCTL_CFGUEN_Pos)                  /*!< FMC_T::ISPCTL: CFGUEN Mask             */

#define FMC_ISPCTL_LDUEN_Pos             (5)                                               /*!< FMC_T::ISPCTL: LDUEN Position          */
#define FMC_ISPCTL_LDUEN_Msk             (0x1ul << FMC_ISPCTL_LDUEN_Pos)                   /*!< FMC_T::ISPCTL: LDUEN Mask              */

#define FMC_ISPCTL_ISPFF_Pos             (6)                                               /*!< FMC_T::ISPCTL: ISPFF Position          */
#define FMC_ISPCTL_ISPFF_Msk             (0x1ul << FMC_ISPCTL_ISPFF_Pos)                   /*!< FMC_T::ISPCTL: ISPFF Mask              */

#define FMC_ISPADDR_ISPADDR_Pos          (0)                                               /*!< FMC_T::ISPADDR: ISPADDR Position       */
#define FMC_ISPADDR_ISPADDR_Msk          (0xfffffffful << FMC_ISPADDR_ISPADDR_Pos)         /*!< FMC_T::ISPADDR: ISPADDR Mask           */

#define FMC_ISPDAT_ISPDAT_Pos            (0)                                               /*!< FMC_T::ISPDAT: ISPDAT Position         */
#define FMC_ISPDAT_ISPDAT_Msk            (0xfffffffful << FMC_ISPDAT_ISPDAT_Pos)           /*!< FMC_T::ISPDAT: ISPDAT Mask             */

#define FMC_ISPCMD_CMD_Pos               (0)                                               /*!< FMC_T::ISPCMD: CMD Position            */
#define FMC_ISPCMD_CMD_Msk               (0x7ful << FMC_ISPCMD_CMD_Pos)                    /*!< FMC_T::ISPCMD: CMD Mask                */

#define FMC_ISPTRG_ISPGO_Pos             (0)                                               /*!< FMC_T::ISPTRG: ISPGO Position          */
#define FMC_ISPTRG_ISPGO_Msk             (0x1ul << FMC_ISPTRG_ISPGO_Pos)                   /*!< FMC_T::ISPTRG: ISPGO Mask              */

#define FMC_FTCTL_CACHEINV_Pos           (9)                                               /*!< FMC_T::FTCTL: CACHEINV Position        */
#define FMC_FTCTL_CACHEINV_Msk           (0x1ul << FMC_FTCTL_CACHEINV_Pos)                 /*!< FMC_T::FTCTL: CACHEINV Mask            */

#define FMC_ISPSTS_ISPBUSY_Pos           (0)                                               /*!< FMC_T::ISPSTS: ISPBUSY Position        */
#define FMC_ISPSTS_ISPBUSY_Msk           (0x1ul << FMC_ISPSTS_ISPBUSY_Pos)                 /*!< FMC_T::ISPSTS: ISPBUSY Mask            */

#define FMC_ISPSTS_CBS_Pos               (1)                                               /*!< FMC_T::ISPSTS: CBS Position            */
#define FMC_ISPSTS_CBS_Msk               (0x3ul << FMC_ISPSTS_CBS_Pos)                     /*!< FMC_T::ISPSTS: CBS Mask                */

#define FMC_ISPSTS_PGFF_Pos              (5)                                               /*!< FMC_T::ISPSTS: PGFF Position           */
#define FMC_ISPSTS_PGFF_Msk              (0x1ul << FMC_ISPSTS_PGFF_Pos)                    /*!< FMC_T::ISPSTS: PGFF Mask               */

#define FMC_ISPSTS_ISPFF_Pos             (6)                                               /*!< FMC_T::ISPSTS: ISPFF Position          */
#define FMC_ISPSTS_ISPFF_Msk             (0x1ul << FMC_ISPSTS_ISPFF_Pos)                   /*!< FMC_T::ISPSTS: ISPFF Mask              */

#define FMC_ISPSTS_ALLONE_Pos            (7)                                               /*!< FMC_T::ISPSTS: ALLONE Position         */
#define FMC_ISPSTS_ALLONE_Msk            (0x1ul << FMC_ISPSTS_ALLONE_Pos)                  /*!< FMC_T::ISPSTS: ALLONE Mask             */

#define FMC_ISPSTS_VECMAP_Pos            (9)                                               /*!< FMC_T::ISPSTS: VECMAP Position         */
#define FMC_ISPSTS_VECMAP_Msk            (0x1ffffful << FMC_ISPSTS_VECMAP_Pos)             /*!< FMC_T::ISPSTS: VECMAP Mask             */

#define FMC_CYCCTL_CYCLE_Pos             (0)                                               /*!< FMC_T::CYCCTL: CYCLE Position          */
#define FMC_CYCCTL_CYCLE_Msk             (0xful << FMC_CYCCTL_CYCLE_Pos)                   /*!< FMC_T::CYCCTL: CYCLE Mask              */

#define FMC_MPDAT0_ISPDAT0_Pos           (0)                                               /*!< FMC_T::MPDAT0: ISPDAT0 Position        */
#define FMC_MPDAT0_ISPDAT0_Msk           (0xfffffffful << FMC_MPDAT0_ISPDAT0_Pos)          /*!< FMC_T::MPDAT0: ISPDAT0 Mask            */

#define FMC_MPDAT1_ISPDAT1_Pos           (0)                                               /*!< FMC_T::MPDAT1: ISPDAT1 Position        */
#define FMC_MPDAT1_ISPDAT1_Msk           (0xfffffffful << FMC_MPDAT1_ISPDAT1_Pos)          /*!< FMC_T::MPDAT1: ISPDAT1 Mask            */

#define FMC_MPDAT2_ISPDAT2_Pos           (0)                                               /*!< FMC_T::MPDAT2: ISPDAT2 Position        */
#define FMC_MPDAT2_ISPDAT2_Msk           (0xfffffffful << FMC_MPDAT2_ISPDAT2_Pos)          /*!< FMC_T::MPDAT2: ISPDAT2 Mask            */

#define FMC_MPDAT3_ISPDAT3_Pos           (0)                                               /*!< FMC_T::MPDAT3: ISPDAT3 Position        */
#define FMC_MPDAT3_ISPDAT3_Msk           (0xfffffffful << FMC_MPDAT3_ISPDAT3_Pos)          /*!< FMC_T::MPDAT3: ISPDAT3 Mask            */

#define FMC_MPSTS_MPBUSY_Pos             (0)                                               /*!< FMC_T::MPSTS: MPBUSY Position          */
#define FMC_MPSTS_MPBUSY_Msk             (0x1ul << FMC_MPSTS_MPBUSY_Pos)                   /*!< FMC_T::MPSTS: MPBUSY Mask              */

#define FMC_MPSTS_PPGO_Pos               (1)                                               /*!< FMC_T::MPSTS: PPGO Position            */
#define FMC_MPSTS_PPGO_Msk               (0x1ul << FMC_MPSTS_PPGO_Pos)                     /*!< FMC_T::MPSTS: PPGO Mask                */

#define FMC_MPSTS_ISPFF_Pos              (2)                                               /*!< FMC_T::MPSTS: ISPFF Position           */
#define FMC_MPSTS_ISPFF_Msk              (0x1ul << FMC_MPSTS_ISPFF_Pos)                    /*!< FMC_T::MPSTS: ISPFF Mask               */

#define FMC_MPSTS_D0_Pos                 (4)                                               /*!< FMC_T::MPSTS: D0 Position              */
#define FMC_MPSTS_D0_Msk                 (0x1ul << FMC_MPSTS_D0_Pos)                       /*!< FMC_T::MPSTS: D0 Mask                  */

#define FMC_MPSTS_D1_Pos                 (5)                                               /*!< FMC_T::MPSTS: D1 Position              */
#define FMC_MPSTS_D1_Msk                 (0x1ul << FMC_MPSTS_D1_Pos)                       /*!< FMC_T::MPSTS: D1 Mask                  */

#define FMC_MPSTS_D2_Pos                 (6)                                               /*!< FMC_T::MPSTS: D2 Position              */
#define FMC_MPSTS_D2_Msk                 (0x1ul << FMC_MPSTS_D2_Pos)                       /*!< FMC_T::MPSTS: D2 Mask                  */

#define FMC_MPSTS_D3_Pos                 (7)                                               /*!< FMC_T::MPSTS: D3 Position              */
#define FMC_MPSTS_D3_Msk                 (0x1ul << FMC_MPSTS_D3_Pos)                       /*!< FMC_T::MPSTS: D3 Mask                  */

#define FMC_MPADDR_MPADDR_Pos            (0)                                               /*!< FMC_T::MPADDR: MPADDR Position         */
#define FMC_MPADDR_MPADDR_Msk            (0xfffffffful << FMC_MPADDR_MPADDR_Pos)           /*!< FMC_T::MPADDR: MPADDR Mask             */

#define FMC_XOMR0STS0_BASE_Pos           (0)                                               /*!< FMC_T::XOMR0STS0: BASE Position        */
#define FMC_XOMR0STS0_BASE_Msk           (0xfffffful << FMC_XOMR0STS0_BASE_Pos)            /*!< FMC_T::XOMR0STS0: BASE Mask            */

#define FMC_XOMR0STS1_SIZE_Pos           (0)                                               /*!< FMC_T::XOMR0STS1: SIZE Position        */
#define FMC_XOMR0STS1_SIZE_Msk           (0x1fful << FMC_XOMR0STS1_SIZE_Pos)               /*!< FMC_T::XOMR0STS1: SIZE Mask            */

#define FMC_XOMSTS_XOMR0ON_Pos           (0)                                               /*!< FMC_T::XOMSTS: XOMR0ON Position        */
#define FMC_XOMSTS_XOMR0ON_Msk           (0x1ul << FMC_XOMSTS_XOMR0ON_Pos)                 /*!< FMC_T::XOMSTS: XOMR0ON Mask            */

#define FMC_XOMSTS_XOMPEF_Pos            (4)                                               /*!< FMC_T::XOMSTS: XOMPEF Position         */
#define FMC_XOMSTS_XOMPEF_Msk            (0x1ul << FMC_XOMSTS_XOMPEF_Pos)                  /*!< FMC_T::XOMSTS: XOMPEF Mask             */

/** @} FMC_CONST */
/** @} end of FMC register group */
/** @} end of REGISTER group */

#if defined ( __CC_ARM   )
    #pragma no_anon_unions
#endif

#endif /* __FMC_REG_H__ */
