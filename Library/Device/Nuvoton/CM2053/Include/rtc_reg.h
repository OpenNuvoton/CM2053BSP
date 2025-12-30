/**************************************************************************//**
 * @file     rtc_reg.h
 * @version  V1.00
 * @brief    RTC register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __RTC_REG_H__
#define __RTC_REG_H__

#if defined ( __CC_ARM   )
    #pragma anon_unions
#endif

/**
    @addtogroup REGISTER Control Register
    @{
*/

/**
    @addtogroup RTC Real Time Clock Controller (RTC)
    Memory Mapped Structure for RTC Controller
    @{
*/

typedef struct
{


    /**
@var RTC_T::INIT

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">INIT
</font><br><p> <font size="2">
Offset: 0x00  RTC Initiation Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>ACTIVE</td><td><div style="word-wrap: break-word;"><b>RTC Active Status (Read Only)
</b><br>
|0 = RTC is at reset state.
<br>
|1 = RTC is at normal active state.
<br>
</div></td></tr><tr><td>
[31:1]</td><td>INIT</td><td><div style="word-wrap: break-word;"><b>RTC Initiation (Write Only)
</b><br>
|When RTC block is powered on, RTC is at reset state.
<br>
|User has to write a number (0xa5eb1357) to INIT to make RTC leave reset state.
<br>
|Once the INIT is written as 0xa5eb1357, the RTC will be in un-reset state permanently.
<br>
|The INIT is a write-only field and read value will be always 0.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var RTC_T::FREQADJ

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">FREQADJ
</font><br><p> <font size="2">
Offset: 0x08  RTC Frequency Compensation Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[5:0]</td><td>FRACTION</td><td><div style="word-wrap: break-word;"><b>Fraction Part
</b><br>
|Formula: FRACTION = (fraction part of detected value) X 64.
<br>
|Note: Digit in FCR must be expressed as hexadecimal number.
<br>
</div></td></tr><tr><td>
[12:8]</td><td>INTEGER</td><td><div style="word-wrap: break-word;"><b>Integer Part
</b><br>
|00000 = Integer part of detected value is 32752.
<br>
|00001 = Integer part of detected value is 32753.
<br>
|00010 = Integer part of detected value is 32754.
<br>
|00011 = Integer part of detected value is 32755.
<br>
|00100 = Integer part of detected value is 32756.
<br>
|00101 = Integer part of detected value is 32757.
<br>
|00110 = Integer part of detected value is 32758.
<br>
|00111 = Integer part of detected value is 32759.
<br>
|01000 = Integer part of detected value is 32760.
<br>
|01001 = Integer part of detected value is 32761.
<br>
|01010 = Integer part of detected value is 32762.
<br>
|01011 = Integer part of detected value is 32763.
<br>
|01100 = Integer part of detected value is 32764.
<br>
|01101 = Integer part of detected value is 32765.
<br>
|01110 = Integer part of detected value is 32766.
<br>
|01111 = Integer part of detected value is 32767.
<br>
|10000 = Integer part of detected value is 32768.
<br>
|10001 = Integer part of detected value is 32769.
<br>
|10010 = Integer part of detected value is 32770.
<br>
|10011 = Integer part of detected value is 32771.
<br>
|10100 = Integer part of detected value is 32772.
<br>
|10101 = Integer part of detected value is 32773.
<br>
|10110 = Integer part of detected value is 32774.
<br>
|10111 = Integer part of detected value is 32775.
<br>
|11000 = Integer part of detected value is 32776.
<br>
|11001 = Integer part of detected value is 32777.
<br>
|11010 = Integer part of detected value is 32778.
<br>
|11011 = Integer part of detected value is 32779.
<br>
|11100 = Integer part of detected value is 32780.
<br>
|11101 = Integer part of detected value is 32781.
<br>
|11110 = Integer part of detected value is 32782.
<br>
|11111 = Integer part of detected value is 32783.
<br>
</div></td></tr><tr><td>
[31]</td><td>FCRBUSY</td><td><div style="word-wrap: break-word;"><b>Frequency Compensation Register Write Operation Busy (Read Only)
</b><br>
|0 = The new register write operation is acceptable.
<br>
|1 = The last write operation is in progress and new register write operation prohibited.
<br>
|Note: This bit is only used when DCOMPEN(RTC_CLKFMT[16]) enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var RTC_T::TIME

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">TIME
</font><br><p> <font size="2">
Offset: 0x0C  RTC Time Loading Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[3:0]</td><td>SEC</td><td><div style="word-wrap: break-word;"><b>1-Sec Time Digit (0~9)
</b><br>
</div></td></tr><tr><td>
[6:4]</td><td>TENSEC</td><td><div style="word-wrap: break-word;"><b>10-Sec Time Digit (0~5)
</b><br>
</div></td></tr><tr><td>
[11:8]</td><td>MIN</td><td><div style="word-wrap: break-word;"><b>1-Min Time Digit (0~9)
</b><br>
</div></td></tr><tr><td>
[14:12]</td><td>TENMIN</td><td><div style="word-wrap: break-word;"><b>10-Min Time Digit (0~5)
</b><br>
</div></td></tr><tr><td>
[19:16]</td><td>HR</td><td><div style="word-wrap: break-word;"><b>1-Hour Time Digit (0~9)
</b><br>
</div></td></tr><tr><td>
[21:20]</td><td>TENHR</td><td><div style="word-wrap: break-word;"><b>10-Hour Time Digit (0~2)
</b><br>
|When RTC runs as 12-hour time scale mode, RTC_TIME[21] (the high bit of TENHR[1:0])
<br>
|means AM/PM indication (If RTC_TIME[21] is 1, it indicates PM time message.)
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var RTC_T::CAL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CAL
</font><br><p> <font size="2">
Offset: 0x10  RTC Calendar Loading Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[3:0]</td><td>DAY</td><td><div style="word-wrap: break-word;"><b>1-Day Calendar Digit (0~9)
</b><br>
</div></td></tr><tr><td>
[5:4]</td><td>TENDAY</td><td><div style="word-wrap: break-word;"><b>10-Day Calendar Digit (0~3)
</b><br>
</div></td></tr><tr><td>
[11:8]</td><td>MON</td><td><div style="word-wrap: break-word;"><b>1-Month Calendar Digit (0~9)
</b><br>
</div></td></tr><tr><td>
[12]</td><td>TENMON</td><td><div style="word-wrap: break-word;"><b>10-Month Calendar Digit (0~1)
</b><br>
</div></td></tr><tr><td>
[19:16]</td><td>YEAR</td><td><div style="word-wrap: break-word;"><b>1-Year Calendar Digit (0~9)
</b><br>
</div></td></tr><tr><td>
[23:20]</td><td>TENYEAR</td><td><div style="word-wrap: break-word;"><b>10-Year Calendar Digit (0~9)
</b><br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var RTC_T::CLKFMT

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CLKFMT
</font><br><p> <font size="2">
Offset: 0x14  RTC Time Scale Selection Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>24HEN</td><td><div style="word-wrap: break-word;"><b>24-hour / 12-hour Time Scale Selection
</b><br>
|Indicates that RTC_TIME and RTC_TALM are in 24-hour time scale or 12-hour time scale.
<br>
|0 = 12-hour time scale with AM and PM indication selected.
<br>
|1 = 24-hour time scale selected.
<br>
</div></td></tr><tr><td>
[16]</td><td>DCOMPEN</td><td><div style="word-wrap: break-word;"><b>Dynamic Compensation Enable Bit
</b><br>
|0 = Dynamic Compensation Disabled.
<br>
|1 = Dynamic Compensation Enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var RTC_T::WEEKDAY

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">WEEKDAY
</font><br><p> <font size="2">
Offset: 0x18  RTC Day of the Week Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[2:0]</td><td>WEEKDAY</td><td><div style="word-wrap: break-word;"><b>Day of the Week Register
</b><br>
|000 = Sunday.
<br>
|001 = Monday.
<br>
|010 = Tuesday.
<br>
|011 = Wednesday.
<br>
|100 = Thursday.
<br>
|101 = Friday.
<br>
|110 = Saturday.
<br>
|111 = Reserved.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var RTC_T::TALM

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">TALM
</font><br><p> <font size="2">
Offset: 0x1C  RTC Time Alarm Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[3:0]</td><td>SEC</td><td><div style="word-wrap: break-word;"><b>1-Sec Time Digit of Alarm Setting (0~9)
</b><br>
</div></td></tr><tr><td>
[6:4]</td><td>TENSEC</td><td><div style="word-wrap: break-word;"><b>10-Sec Time Digit of Alarm Setting (0~5)
</b><br>
</div></td></tr><tr><td>
[11:8]</td><td>MIN</td><td><div style="word-wrap: break-word;"><b>1-Min Time Digit of Alarm Setting (0~9)
</b><br>
</div></td></tr><tr><td>
[14:12]</td><td>TENMIN</td><td><div style="word-wrap: break-word;"><b>10-Min Time Digit of Alarm Setting (0~5)
</b><br>
</div></td></tr><tr><td>
[19:16]</td><td>HR</td><td><div style="word-wrap: break-word;"><b>1-Hour Time Digit of Alarm Setting (0~9)
</b><br>
</div></td></tr><tr><td>
[21:20]</td><td>TENHR</td><td><div style="word-wrap: break-word;"><b>10-Hour Time Digit of Alarm Setting (0~2)
</b><br>
|When RTC runs as 12-hour time scale mode, RTC_TIME[21] (the high bit of TENHR[1:0])
<br>
|means AM/PM indication (If RTC_TIME[21] is 1, it indicates PM time message.)
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var RTC_T::CALM

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CALM
</font><br><p> <font size="2">
Offset: 0x20  RTC Calendar Alarm Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[3:0]</td><td>DAY</td><td><div style="word-wrap: break-word;"><b>1-Day Calendar Digit of Alarm Setting (0~9)
</b><br>
</div></td></tr><tr><td>
[5:4]</td><td>TENDAY</td><td><div style="word-wrap: break-word;"><b>10-Day Calendar Digit of Alarm Setting (0~3)
</b><br>
</div></td></tr><tr><td>
[11:8]</td><td>MON</td><td><div style="word-wrap: break-word;"><b>1-Month Calendar Digit of Alarm Setting (0~9)
</b><br>
</div></td></tr><tr><td>
[12]</td><td>TENMON</td><td><div style="word-wrap: break-word;"><b>10-Month Calendar Digit of Alarm Setting (0~1)
</b><br>
</div></td></tr><tr><td>
[19:16]</td><td>YEAR</td><td><div style="word-wrap: break-word;"><b>1-Year Calendar Digit of Alarm Setting (0~9)
</b><br>
</div></td></tr><tr><td>
[23:20]</td><td>TENYEAR</td><td><div style="word-wrap: break-word;"><b>10-Year Calendar Digit of Alarm Setting (0~9)
</b><br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var RTC_T::LEAPYEAR

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">LEAPYEAR
</font><br><p> <font size="2">
Offset: 0x24  RTC Leap Year Indicator Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>LEAPYEAR</td><td><div style="word-wrap: break-word;"><b>Leap Year Indication Register (Read Only)
</b><br>
|0 = This year is not a leap year.
<br>
|1 = This year is leap year.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var RTC_T::INTEN

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">INTEN
</font><br><p> <font size="2">
Offset: 0x28  RTC Interrupt Enable Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>ALMIEN</td><td><div style="word-wrap: break-word;"><b>Alarm Interrupt Enable Bit
</b><br>
|Set ALMIEN to 1 can also enable chip wake-up function when RTC alarm interrupt event is generated.
<br>
|0 = RTC Alarm interrupt Disabled.
<br>
|1 = RTC Alarm interrupt Enabled.
<br>
</div></td></tr><tr><td>
[1]</td><td>TICKIEN</td><td><div style="word-wrap: break-word;"><b>Time Tick Interrupt Enable Bit
</b><br>
|Set TICKIEN to 1 can also enable chip wake-up function when RTC tick interrupt event is generated.
<br>
|0 = RTC Time Tick interrupt Disabled.
<br>
|1 = RTC Time Tick interrupt Enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var RTC_T::INTSTS

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">INTSTS
</font><br><p> <font size="2">
Offset: 0x2C  RTC Interrupt Status Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>ALMIF</td><td><div style="word-wrap: break-word;"><b>RTC Alarm Interrupt Flag
</b><br>
|0 = Alarm condition is not matched.
<br>
|1 = Alarm condition is matched.
<br>
|Note: Write 1 to clear this bit.
<br>
</div></td></tr><tr><td>
[1]</td><td>TICKIF</td><td><div style="word-wrap: break-word;"><b>RTC Time Tick Interrupt Flag
</b><br>
|0 = Tick condition does not occur.
<br>
|1 = Tick condition occur.
<br>
|Note: Write 1 to clear this bit.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var RTC_T::TICK

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">TICK
</font><br><p> <font size="2">
Offset: 0x30  RTC Time Tick Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[2:0]</td><td>TICK</td><td><div style="word-wrap: break-word;"><b>Time Tick Register
</b><br>
|These bits are used to select RTC time tick period for Periodic Time Tick Interrupt request.
<br>
|000 = Time tick is 1 second.
<br>
|001 = Time tick is 1/2 second.
<br>
|010 = Time tick is 1/4 second.
<br>
|011 = Time tick is 1/8 second.
<br>
|100 = Time tick is 1/16 second.
<br>
|101 = Time tick is 1/32 second.
<br>
|110 = Time tick is 1/64 second.
<br>
|111 = Time tick is 1/128 second.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var RTC_T::TAMSK

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">TAMSK
</font><br><p> <font size="2">
Offset: 0x34  RTC Time Alarm Mask Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>MSEC</td><td><div style="word-wrap: break-word;"><b>Mask 1-Sec Time Digit of Alarm Setting (0~9)
</b><br>
</div></td></tr><tr><td>
[1]</td><td>MTENSEC</td><td><div style="word-wrap: break-word;"><b>Mask 10-Sec Time Digit of Alarm Setting (0~5)
</b><br>
</div></td></tr><tr><td>
[2]</td><td>MMIN</td><td><div style="word-wrap: break-word;"><b>Mask 1-Min Time Digit of Alarm Setting (0~9)
</b><br>
</div></td></tr><tr><td>
[3]</td><td>MTENMIN</td><td><div style="word-wrap: break-word;"><b>Mask 10-Min Time Digit of Alarm Setting (0~5)
</b><br>
</div></td></tr><tr><td>
[4]</td><td>MHR</td><td><div style="word-wrap: break-word;"><b>Mask 1-Hour Time Digit of Alarm Setting (0~9)
</b><br>
</div></td></tr><tr><td>
[5]</td><td>MTENHR</td><td><div style="word-wrap: break-word;"><b>Mask 10-Hour Time Digit of Alarm Setting (0~2)
</b><br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var RTC_T::CAMSK

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CAMSK
</font><br><p> <font size="2">
Offset: 0x38  RTC Calendar Alarm Mask Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>MDAY</td><td><div style="word-wrap: break-word;"><b>Mask 1-Day Calendar Digit of Alarm Setting (0~9)
</b><br>
</div></td></tr><tr><td>
[1]</td><td>MTENDAY</td><td><div style="word-wrap: break-word;"><b>Mask 10-Day Calendar Digit of Alarm Setting (0~3)
</b><br>
</div></td></tr><tr><td>
[2]</td><td>MMON</td><td><div style="word-wrap: break-word;"><b>Mask 1-Month Calendar Digit of Alarm Setting (0~9)
</b><br>
</div></td></tr><tr><td>
[3]</td><td>MTENMON</td><td><div style="word-wrap: break-word;"><b>Mask 10-Month Calendar Digit of Alarm Setting (0~1)
</b><br>
</div></td></tr><tr><td>
[4]</td><td>MYEAR</td><td><div style="word-wrap: break-word;"><b>Mask 1-Year Calendar Digit of Alarm Setting (0~9)
</b><br>
</div></td></tr><tr><td>
[5]</td><td>MTENYEAR</td><td><div style="word-wrap: break-word;"><b>Mask 10-Year Calendar Digit of Alarm Setting (0~9)
</b><br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var RTC_T::LXTCTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">LXTCTL
</font><br><p> <font size="2">
Offset: 0x100  RTC 32KHz Oscillator Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[3:1]</td><td>GAIN</td><td><div style="word-wrap: break-word;"><b>Oscillator Gain Option
</b><br>
|User can select oscillator gain according to crystal external loading and operating temperature range.
<br>
|The larger gain value corresponding to stronger driving capability and higher power consumption.
<br>
|000 = L0 mode.
<br>
|001 = L1 mode.
<br>
|010 = L2 mode.
<br>
|011 = L3 mode.
<br>
</div></td></tr><tr><td>
[7]</td><td>C32KS</td><td><div style="word-wrap: break-word;"><b>RTC Clock 32K Source Selection:
</b><br>
|0 = Internal RTC clock is from 32K crystal .
<br>
|1 = Internal RTC clock is from LIRC.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var RTC_T::DSTCTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">DSTCTL
</font><br><p> <font size="2">
Offset: 0x110  RTC Daylight Saving Time Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>ADDHR</td><td><div style="word-wrap: break-word;"><b>Add 1 Hour
</b><br>
|0 = No effect.
<br>
|1 = RTC hour digit has been added one hour for summer time change.
<br>
</div></td></tr><tr><td>
[1]</td><td>SUBHR</td><td><div style="word-wrap: break-word;"><b>Subtract 1 Hour
</b><br>
|0 = No effect.
<br>
|1 = RTC hour digit has been subtracted one hour for winter time change.
<br>
</div></td></tr><tr><td>
[2]</td><td>DSBAK</td><td><div style="word-wrap: break-word;"><b>Daylight Saving Back
</b><br>
|0= Normal mode.
<br>
|1= Daylight saving mode.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly



 */
    __IO uint32_t INIT;                  /*!< [0x0000] RTC Initiation Register                                          */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t FREQADJ;               /*!< [0x0008] RTC Frequency Compensation Register                              */
    __IO uint32_t TIME;                  /*!< [0x000c] RTC Time Loading Register                                        */
    __IO uint32_t CAL;                   /*!< [0x0010] RTC Calendar Loading Register                                    */
    __IO uint32_t CLKFMT;                /*!< [0x0014] RTC Time Scale Selection Register                                */
    __IO uint32_t WEEKDAY;               /*!< [0x0018] RTC Day of the Week Register                                     */
    __IO uint32_t TALM;                  /*!< [0x001c] RTC Time Alarm Register                                          */
    __IO uint32_t CALM;                  /*!< [0x0020] RTC Calendar Alarm Register                                      */
    __I  uint32_t LEAPYEAR;              /*!< [0x0024] RTC Leap Year Indicator Register                                 */
    __IO uint32_t INTEN;                 /*!< [0x0028] RTC Interrupt Enable Register                                    */
    __IO uint32_t INTSTS;                /*!< [0x002c] RTC Interrupt Status Register                                    */
    __IO uint32_t TICK;                  /*!< [0x0030] RTC Time Tick Register                                           */
    __IO uint32_t TAMSK;                 /*!< [0x0034] RTC Time Alarm Mask Register                                     */
    __IO uint32_t CAMSK;                 /*!< [0x0038] RTC Calendar Alarm Mask Register                                 */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[49];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t LXTCTL;                /*!< [0x0100] RTC 32KHz Oscillator Control Register                            */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE2[3];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t DSTCTL;                /*!< [0x0110] RTC Daylight Saving Time Control Register                        */
} RTC_T;

/**
    @addtogroup RTC_CONST RTC Bit Field Definition
    Constant Definitions for RTC Controller
@{ */

#define RTC_INIT_ACTIVE_Pos              (0)                                               /*!< RTC_T::INIT: INIT_ACTIVE Position      */
#define RTC_INIT_ACTIVE_Msk              (0x1ul << RTC_INIT_ACTIVE_Pos)                    /*!< RTC_T::INIT: INIT_ACTIVE Mask          */

#define RTC_FREQADJ_FRACTION_Pos         (0)                                               /*!< RTC_T::FREQADJ: FRACTION Position      */
#define RTC_FREQADJ_FRACTION_Msk         (0x3ful << RTC_FREQADJ_FRACTION_Pos)              /*!< RTC_T::FREQADJ: FRACTION Mask          */

#define RTC_FREQADJ_INTEGER_Pos          (8)                                               /*!< RTC_T::FREQADJ: INTEGER Position       */
#define RTC_FREQADJ_INTEGER_Msk          (0x1ful << RTC_FREQADJ_INTEGER_Pos)               /*!< RTC_T::FREQADJ: INTEGER Mask           */

#define RTC_FREQADJ_FCRBUSY_Pos          (31)                                              /*!< RTC_T::FREQADJ: FCRBUSY Position       */
#define RTC_FREQADJ_FCRBUSY_Msk          (0x1ful << RTC_FREQADJ_FCRBUSY_Pos)               /*!< RTC_T::FREQADJ: FCRBUSY Mask           */

#define RTC_TIME_SEC_Pos                 (0)                                               /*!< RTC_T::TIME: SEC Position              */
#define RTC_TIME_SEC_Msk                 (0xful << RTC_TIME_SEC_Pos)                       /*!< RTC_T::TIME: SEC Mask                  */

#define RTC_TIME_TENSEC_Pos              (4)                                               /*!< RTC_T::TIME: TENSEC Position           */
#define RTC_TIME_TENSEC_Msk              (0x7ul << RTC_TIME_TENSEC_Pos)                    /*!< RTC_T::TIME: TENSEC Mask               */

#define RTC_TIME_MIN_Pos                 (8)                                               /*!< RTC_T::TIME: MIN Position              */
#define RTC_TIME_MIN_Msk                 (0xful << RTC_TIME_MIN_Pos)                       /*!< RTC_T::TIME: MIN Mask                  */

#define RTC_TIME_TENMIN_Pos              (12)                                              /*!< RTC_T::TIME: TENMIN Position           */
#define RTC_TIME_TENMIN_Msk              (0x7ul << RTC_TIME_TENMIN_Pos)                    /*!< RTC_T::TIME: TENMIN Mask               */

#define RTC_TIME_HR_Pos                  (16)                                              /*!< RTC_T::TIME: HR Position               */
#define RTC_TIME_HR_Msk                  (0xful << RTC_TIME_HR_Pos)                        /*!< RTC_T::TIME: HR Mask                   */

#define RTC_TIME_TENHR_Pos               (20)                                              /*!< RTC_T::TIME: TENHR Position            */
#define RTC_TIME_TENHR_Msk               (0x3ul << RTC_TIME_TENHR_Pos)                     /*!< RTC_T::TIME: TENHR Mask                */

#define RTC_CAL_DAY_Pos                  (0)                                               /*!< RTC_T::CAL: DAY Position               */
#define RTC_CAL_DAY_Msk                  (0xful << RTC_CAL_DAY_Pos)                        /*!< RTC_T::CAL: DAY Mask                   */

#define RTC_CAL_TENDAY_Pos               (4)                                               /*!< RTC_T::CAL: TENDAY Position            */
#define RTC_CAL_TENDAY_Msk               (0x3ul << RTC_CAL_TENDAY_Pos)                     /*!< RTC_T::CAL: TENDAY Mask                */

#define RTC_CAL_MON_Pos                  (8)                                               /*!< RTC_T::CAL: MON Position               */
#define RTC_CAL_MON_Msk                  (0xful << RTC_CAL_MON_Pos)                        /*!< RTC_T::CAL: MON Mask                   */

#define RTC_CAL_TENMON_Pos               (12)                                              /*!< RTC_T::CAL: TENMON Position            */
#define RTC_CAL_TENMON_Msk               (0x1ul << RTC_CAL_TENMON_Pos)                     /*!< RTC_T::CAL: TENMON Mask                */

#define RTC_CAL_YEAR_Pos                 (16)                                              /*!< RTC_T::CAL: YEAR Position              */
#define RTC_CAL_YEAR_Msk                 (0xful << RTC_CAL_YEAR_Pos)                       /*!< RTC_T::CAL: YEAR Mask                  */

#define RTC_CAL_TENYEAR_Pos              (20)                                              /*!< RTC_T::CAL: TENYEAR Position           */
#define RTC_CAL_TENYEAR_Msk              (0xful << RTC_CAL_TENYEAR_Pos)                    /*!< RTC_T::CAL: TENYEAR Mask               */

#define RTC_CLKFMT_24HEN_Pos             (0)                                               /*!< RTC_T::CLKFMT: 24HEN Position          */
#define RTC_CLKFMT_24HEN_Msk             (0x1ul << RTC_CLKFMT_24HEN_Pos)                   /*!< RTC_T::CLKFMT: 24HEN Mask              */

#define RTC_CLKFMT_DCOMPEN_Pos           (8)                                               /*!< RTC_T::CLKFMT: DCOMPEN Position        */
#define RTC_CLKFMT_DCOMPEN_Msk           (0x1ul << RTC_CLKFMT_DCOMPEN_Pos)                 /*!< RTC_T::CLKFMT: DCOMPEN Mask            */

#define RTC_WEEKDAY_WEEKDAY_Pos          (0)                                               /*!< RTC_T::WEEKDAY: WEEKDAY Position       */
#define RTC_WEEKDAY_WEEKDAY_Msk          (0x7ul << RTC_WEEKDAY_WEEKDAY_Pos)                /*!< RTC_T::WEEKDAY: WEEKDAY Mask           */

#define RTC_TALM_SEC_Pos                 (0)                                               /*!< RTC_T::TALM: SEC Position              */
#define RTC_TALM_SEC_Msk                 (0xful << RTC_TALM_SEC_Pos)                       /*!< RTC_T::TALM: SEC Mask                  */

#define RTC_TALM_TENSEC_Pos              (4)                                               /*!< RTC_T::TALM: TENSEC Position           */
#define RTC_TALM_TENSEC_Msk              (0x7ul << RTC_TALM_TENSEC_Pos)                    /*!< RTC_T::TALM: TENSEC Mask               */

#define RTC_TALM_MIN_Pos                 (8)                                               /*!< RTC_T::TALM: MIN Position              */
#define RTC_TALM_MIN_Msk                 (0xful << RTC_TALM_MIN_Pos)                       /*!< RTC_T::TALM: MIN Mask                  */

#define RTC_TALM_TENMIN_Pos              (12)                                              /*!< RTC_T::TALM: TENMIN Position           */
#define RTC_TALM_TENMIN_Msk              (0x7ul << RTC_TALM_TENMIN_Pos)                    /*!< RTC_T::TALM: TENMIN Mask               */

#define RTC_TALM_HR_Pos                  (16)                                              /*!< RTC_T::TALM: HR Position               */
#define RTC_TALM_HR_Msk                  (0xful << RTC_TALM_HR_Pos)                        /*!< RTC_T::TALM: HR Mask                   */

#define RTC_TALM_TENHR_Pos               (20)                                              /*!< RTC_T::TALM: TENHR Position            */
#define RTC_TALM_TENHR_Msk               (0x3ul << RTC_TALM_TENHR_Pos)                     /*!< RTC_T::TALM: TENHR Mask                */

#define RTC_CALM_DAY_Pos                 (0)                                               /*!< RTC_T::CALM: DAY Position              */
#define RTC_CALM_DAY_Msk                 (0xful << RTC_CALM_DAY_Pos)                       /*!< RTC_T::CALM: DAY Mask                  */

#define RTC_CALM_TENDAY_Pos              (4)                                               /*!< RTC_T::CALM: TENDAY Position           */
#define RTC_CALM_TENDAY_Msk              (0x3ul << RTC_CALM_TENDAY_Pos)                    /*!< RTC_T::CALM: TENDAY Mask               */

#define RTC_CALM_MON_Pos                 (8)                                               /*!< RTC_T::CALM: MON Position              */
#define RTC_CALM_MON_Msk                 (0xful << RTC_CALM_MON_Pos)                       /*!< RTC_T::CALM: MON Mask                  */

#define RTC_CALM_TENMON_Pos              (12)                                              /*!< RTC_T::CALM: TENMON Position           */
#define RTC_CALM_TENMON_Msk              (0x1ul << RTC_CALM_TENMON_Pos)                    /*!< RTC_T::CALM: TENMON Mask               */

#define RTC_CALM_YEAR_Pos                (16)                                              /*!< RTC_T::CALM: YEAR Position             */
#define RTC_CALM_YEAR_Msk                (0xful << RTC_CALM_YEAR_Pos)                      /*!< RTC_T::CALM: YEAR Mask                 */

#define RTC_CALM_TENYEAR_Pos             (20)                                              /*!< RTC_T::CALM: TENYEAR Position          */
#define RTC_CALM_TENYEAR_Msk             (0xful << RTC_CALM_TENYEAR_Pos)                   /*!< RTC_T::CALM: TENYEAR Mask              */

#define RTC_LEAPYEAR_LEAPYEAR_Pos        (0)                                               /*!< RTC_T::LEAPYEAR: LEAPYEAR Position     */
#define RTC_LEAPYEAR_LEAPYEAR_Msk        (0x1ul << RTC_LEAPYEAR_LEAPYEAR_Pos)              /*!< RTC_T::LEAPYEAR: LEAPYEAR Mask         */

#define RTC_INTEN_ALMIEN_Pos             (0)                                               /*!< RTC_T::INTEN: ALMIEN Position          */
#define RTC_INTEN_ALMIEN_Msk             (0x1ul << RTC_INTEN_ALMIEN_Pos)                   /*!< RTC_T::INTEN: ALMIEN Mask              */

#define RTC_INTEN_TICKIEN_Pos            (1)                                               /*!< RTC_T::INTEN: TICKIEN Position         */
#define RTC_INTEN_TICKIEN_Msk            (0x1ul << RTC_INTEN_TICKIEN_Pos)                  /*!< RTC_T::INTEN: TICKIEN Mask             */

#define RTC_INTSTS_ALMIF_Pos             (0)                                               /*!< RTC_T::INTSTS: ALMIF Position          */
#define RTC_INTSTS_ALMIF_Msk             (0x1ul << RTC_INTSTS_ALMIF_Pos)                   /*!< RTC_T::INTSTS: ALMIF Mask              */

#define RTC_INTSTS_TICKIF_Pos            (1)                                               /*!< RTC_T::INTSTS: TICKIF Position         */
#define RTC_INTSTS_TICKIF_Msk            (0x1ul << RTC_INTSTS_TICKIF_Pos)                  /*!< RTC_T::INTSTS: TICKIF Mask             */

#define RTC_TICK_TICK_Pos                (0)                                               /*!< RTC_T::TICK: TICK Position             */
#define RTC_TICK_TICK_Msk                (0x7ul << RTC_TICK_TICK_Pos)                      /*!< RTC_T::TICK: TICK Mask                 */

#define RTC_TAMSK_MSEC_Pos               (0)                                               /*!< RTC_T::TAMSK: MSEC Position            */
#define RTC_TAMSK_MSEC_Msk               (0x1ul << RTC_TAMSK_MSEC_Pos)                     /*!< RTC_T::TAMSK: MSEC Mask                */

#define RTC_TAMSK_MTENSEC_Pos            (1)                                               /*!< RTC_T::TAMSK: MTENSEC Position         */
#define RTC_TAMSK_MTENSEC_Msk            (0x1ul << RTC_TAMSK_MTENSEC_Pos)                  /*!< RTC_T::TAMSK: MTENSEC Mask             */

#define RTC_TAMSK_MMIN_Pos               (2)                                               /*!< RTC_T::TAMSK: MMIN Position            */
#define RTC_TAMSK_MMIN_Msk               (0x1ul << RTC_TAMSK_MMIN_Pos)                     /*!< RTC_T::TAMSK: MMIN Mask                */

#define RTC_TAMSK_MTENMIN_Pos            (3)                                               /*!< RTC_T::TAMSK: MTENMIN Position         */
#define RTC_TAMSK_MTENMIN_Msk            (0x1ul << RTC_TAMSK_MTENMIN_Pos)                  /*!< RTC_T::TAMSK: MTENMIN Mask             */

#define RTC_TAMSK_MHR_Pos                (4)                                               /*!< RTC_T::TAMSK: MHR Position             */
#define RTC_TAMSK_MHR_Msk                (0x1ul << RTC_TAMSK_MHR_Pos)                      /*!< RTC_T::TAMSK: MHR Mask                 */

#define RTC_TAMSK_MTENHR_Pos             (5)                                               /*!< RTC_T::TAMSK: MTENHR Position          */
#define RTC_TAMSK_MTENHR_Msk             (0x1ul << RTC_TAMSK_MTENHR_Pos)                   /*!< RTC_T::TAMSK: MTENHR Mask              */

#define RTC_CAMSK_MDAY_Pos               (0)                                               /*!< RTC_T::CAMSK: MDAY Position            */
#define RTC_CAMSK_MDAY_Msk               (0x1ul << RTC_CAMSK_MDAY_Pos)                     /*!< RTC_T::CAMSK: MDAY Mask                */

#define RTC_CAMSK_MTENDAY_Pos            (1)                                               /*!< RTC_T::CAMSK: MTENDAY Position         */
#define RTC_CAMSK_MTENDAY_Msk            (0x1ul << RTC_CAMSK_MTENDAY_Pos)                  /*!< RTC_T::CAMSK: MTENDAY Mask             */

#define RTC_CAMSK_MMON_Pos               (2)                                               /*!< RTC_T::CAMSK: MMON Position            */
#define RTC_CAMSK_MMON_Msk               (0x1ul << RTC_CAMSK_MMON_Pos)                     /*!< RTC_T::CAMSK: MMON Mask                */

#define RTC_CAMSK_MTENMON_Pos            (3)                                               /*!< RTC_T::CAMSK: MTENMON Position         */
#define RTC_CAMSK_MTENMON_Msk            (0x1ul << RTC_CAMSK_MTENMON_Pos)                  /*!< RTC_T::CAMSK: MTENMON Mask             */

#define RTC_CAMSK_MYEAR_Pos              (4)                                               /*!< RTC_T::CAMSK: MYEAR Position           */
#define RTC_CAMSK_MYEAR_Msk              (0x1ul << RTC_CAMSK_MYEAR_Pos)                    /*!< RTC_T::CAMSK: MYEAR Mask               */

#define RTC_CAMSK_MTENYEAR_Pos           (5)                                               /*!< RTC_T::CAMSK: MTENYEAR Position        */
#define RTC_CAMSK_MTENYEAR_Msk           (0x1ul << RTC_CAMSK_MTENYEAR_Pos)                 /*!< RTC_T::CAMSK: MTENYEAR Mask            */

#define RTC_LXTCTL_GAIN_Pos              (1)                                               /*!< RTC_T::LXTCTL: GAIN Position           */
#define RTC_LXTCTL_GAIN_Msk              (0x7ul << RTC_LXTCTL_GAIN_Pos)                    /*!< RTC_T::LXTCTL: GAIN Mask               */

#define RTC_LXTCTL_C32KS_Pos             (7)                                               /*!< RTC_T::LXTCTL: C32KS Position          */
#define RTC_LXTCTL_C32KS_Msk             (0x1ul << RTC_LXTCTL_C32KS_Pos)                   /*!< RTC_T::LXTCTL: C32KS Mask              */

#define RTC_DSTCTL_ADDHR_Pos             (0)                                               /*!< RTC_T::DSTCTL: ADDHR Position          */
#define RTC_DSTCTL_ADDHR_Msk             (0x1ul << RTC_DSTCTL_ADDHR_Pos)                   /*!< RTC_T::DSTCTL: ADDHR Mask              */

#define RTC_DSTCTL_SUBHR_Pos             (1)                                               /*!< RTC_T::DSTCTL: SUBHR Position          */
#define RTC_DSTCTL_SUBHR_Msk             (0x1ul << RTC_DSTCTL_SUBHR_Pos)                   /*!< RTC_T::DSTCTL: SUBHR Mask              */

#define RTC_DSTCTL_DSBAK_Pos             (2)                                               /*!< RTC_T::DSTCTL: DSBAK Position          */
#define RTC_DSTCTL_DSBAK_Msk             (0x1ul << RTC_DSTCTL_DSBAK_Pos)                   /*!< RTC_T::DSTCTL: DSBAK Mask              */


/** @} RTC_CONST */
/** @} end of RTC register group */
/** @} end of REGISTER group */

#if defined ( __CC_ARM   )
    #pragma no_anon_unions
#endif

#endif /* __RTC_REG_H__ */
