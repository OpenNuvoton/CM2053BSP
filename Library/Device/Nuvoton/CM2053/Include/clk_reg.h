/**************************************************************************//**
 * @file     clk_reg.h
 * @version  V1.00
 * @brief    CLK register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __CLK_REG_H__
#define __CLK_REG_H__

#if defined ( __CC_ARM   )
    #pragma anon_unions
#endif

/**
    @addtogroup REGISTER Control Register
    @{
*/

/**
    @addtogroup CLK System Clock Controller (CLK)
    Memory Mapped Structure for CLK Controller
    @{
*/

typedef struct
{


    /**
@var CLK_T::PWRCTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">PWRCTL
</font><br><p> <font size="2">
Offset: 0x00  System Power-down Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>HXTEN</td><td><div style="word-wrap: break-word;"><b>HXT Enable Bit (Write Protect)
</b><br>
The bit default value is set by flash controller user configuration register CONFIG0 [26]
<br>
When the default clock source is from HXT, this bit is set to 1 automatically.
<br>
0 = 4~32 MHz external high speed crystal (HXT) Disabled.
<br>
1 = 4~32 MHz external high speed crystal (HXT) Enabled.
<br>
Note 1: This bit is write protected. Refer to the SYS_REGLCTL register.
<br>
Note 2: Reset by power on reset.
<br>
</div></td></tr><tr><td>
[1]</td><td>LXTEN</td><td><div style="word-wrap: break-word;"><b>LXT Enable Bit (Write Protect)
</b><br>
0 = 32.768 kHz external low speed crystal (LXT) Disabled.
<br>
1 = 32.768 kHz external low speed crystal (LXT) Enabled.
<br>
Note 1: This bit is write protected. Refer to the SYS_REGLCTL register.
<br>
Note 2: Reset by RTC power on reset.
<br>
</div></td></tr><tr><td>
[2]</td><td>HIRCEN</td><td><div style="word-wrap: break-word;"><b>HIRC Enable Bit (Write Protect)
</b><br>
0 = 48MHz internal high speed RC oscillator (HIRC) Disabled.
<br>
1 = 48 MHz internal high speed RC oscillator (HIRC) Enabled.
<br>
Note: This bit is write protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr><tr><td>
[3]</td><td>LIRCEN</td><td><div style="word-wrap: break-word;"><b>LIRC Enable Bit (Write Protect)
</b><br>
0 = 38.4 kHz internal low speed RC oscillator (LIRC) Disabled.
<br>
1 = 38.4 kHz internal low speed RC oscillator (LIRC) Enabled.
<br>
Note: This bit is write protected. Refer to the SYS_REGLCTL register.
<br>
Note : LIRC will also be forced on when
<br>
1.Power down and ~(cfg0[3] & cfg0[4] & ~cfg0[31] & cfg0[30])
<br>
2.Not power down and ~(cfg0[3] & cfg0[4] & cfg0[31])
<br>
</div></td></tr><tr><td>
[4]</td><td>PDWKDLY</td><td><div style="word-wrap: break-word;"><b>Enable the Wake-up Delay Counter (Write Protect)
</b><br>
When the chip wakes up from Power-down mode, the clock control will delay certain clock cycles to wait system clock stable.
<br>
The delayed clock cycle is 4096 clock cycles when chip works at 4~32 MHz external high speed crystal oscillator (HXT),
<br>
The delayed clock cycle is 512 clock cycles when chip works at 48 MHz internal high speed RC oscillator (HIRC)
<br>
The delayed clock cycle is 32 clock cycles when chip works at 4 MHz internal median speed RC oscillator (MIRC)
<br>
0 = Clock cycles delay Disabled.
<br>
1 = Clock cycles delay Enabled.
<br>
Note: This bit is write protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr><tr><td>
[5]</td><td>PDWKIEN</td><td><div style="word-wrap: break-word;"><b>Power-down Mode Wake-up Interrupt Enable Bit (Write Protect)
</b><br>
0 = Power-down mode wake-up interrupt Disabled.
<br>
1 = Power-down mode wake-up interrupt Enabled.
<br>
Note1: The interrupt will occur when both PDWKIF and PDWKIEN are high.
<br>
Note2: This bit is write protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr><tr><td>
[6]</td><td>PDWKIF</td><td><div style="word-wrap: break-word;"><b>Power-down Mode Wake-up Interrupt Status
</b><br>
Set by "Power-down wake-up event", it indicates that resume from Power-down mode.
<br>
The flag is set if any wake-up source is occurred. Refer Power Modes and Wake-up Sources chapter.
<br>
Note1: Write 1 to clear the bit to 0.
<br>
Note2: This bit works only if PDWKIEN (CLK_PWRCTL[5]) set to 1.
<br>
</div></td></tr><tr><td>
[7]</td><td>PDEN</td><td><div style="word-wrap: break-word;"><b>System Power-down Enable (Write Protect)
</b><br>
When this bit is set to 1, Power-down mode is enabled and chip Power-down behavior will depend on the PDWTCPU bit.
<br>
(a) If the PDWTCPU is 0, then the chip enters Power-down mode immediately after the PDEN bit set
<br>
(default)
<br>
(b) if the PDWTCPU is 1, then the chip keeps active till the CPU sleep mode is also active and then the chip enters Power-down mode.
<br>
When chip wakes up from Power-down mode, this bit is auto cleared
<br>
Users need to set this bit again for next Power-down.
<br>
In Power-down mode, HXT and the HIRC will be disabled in this mode, but LXT and LIRC are not controlled by Power-down mode.
<br>
In Power-down mode, the PLL and system clock are disabled, and ignored the clock source selection
<br>
The clocks of peripheral are not controlled by Power-down mode, if the peripheral clock source is from LXT or LIRC.
<br>
0 = Chip operating normally or chip in idle mode because of WFI command.
<br>
1 = Chip enters Power-down mode instant or wait CPU sleep command WFI.
<br>
Note: This bit is write protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr><tr><td>
[19]</td><td>MIRCEN</td><td><div style="word-wrap: break-word;"><b>MIRC Enable Bit (Write Protect)
</b><br>
0 = 4MHz internal high speed RC oscillator (MIRC) Disabled.
<br>
1 = 4 MHz internal high speed RC oscillator (MIRC) Enabled.
<br>
Note: This bit is write protected. Refer to the SYS_REGLCTL register.
<br>
Note: Will be forced on when CLKSEL0[2:0] = 0x101b.
<br>
</div></td></tr><tr><td>
[22:20]</td><td>HXTGAIN</td><td><div style="word-wrap: break-word;"><b>HXT Gain Control Bit (Write Protect)
</b><br>
This is a protected register. Please refer to open lock sequence to program it.
<br>
Gain control is used to enlarge the gain of crystal to make sure crystal work normally
<br>
If gain control is enabled, crystal will consume more power than gain control off.
<br>
000 = HXT frequency 1~4 MHz.
<br>
001 = HXT frequency 4~8 MHz.
<br>
010 = HXT frequency 8~12 MHz.
<br>
011 = HXT frequency 12~16 MHz.
<br>
100 = HXT frequency 16~24 MHz.
<br>
101 = HXT frequency 24~32 MHz.
<br>
110 = HXT frequency 24~32 MHz.
<br>
111 = HXT frequency 24~32 MHz.
<br>
Note: This bit is write protected. Refer to the SYS_REGLCTL register.
<br>
Note: Reset by power on reset
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::AHBCLK

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">AHBCLK
</font><br><p> <font size="2">
Offset: 0x04  AHB Devices Clock Enable Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[1]</td><td>PDMACKEN</td><td><div style="word-wrap: break-word;"><b>PDMA Controller Clock Enable Bit
</b><br>
0 = PDMA peripheral clock Disabled.
<br>
1 = PDMA peripheral clock Enabled.
<br>
</div></td></tr><tr><td>
[2]</td><td>ISPCKEN</td><td><div style="word-wrap: break-word;"><b>Flash ISP Controller Clock Enable Bit
</b><br>
0 = Flash ISP peripheral clock Disabled.
<br>
1 = Flash ISP peripheral clock Enabled.
<br>
</div></td></tr><tr><td>
[4]</td><td>EXSTCKEN</td><td><div style="word-wrap: break-word;"><b>External System Tick Clock Enable Bit
</b><br>
0 = External System tick clock Disabled.
<br>
1 = External System tick clock Enabled.
<br>
</div></td></tr><tr><td>
[7]</td><td>CRCCKEN</td><td><div style="word-wrap: break-word;"><b>CRC Generator Controller Clock Enable Bit
</b><br>
0 = CRC peripheral clock Disabled.
<br>
1 = CRC peripheral clock Enabled.
<br>
</div></td></tr><tr><td>
[15]</td><td>FMCIDLE</td><td><div style="word-wrap: break-word;"><b>Flash Memory Controller Clock Enable Bit in IDLE Mode
</b><br>
0 = FMC clock Disabled when chip is under IDLE mode.
<br>
1 = FMC clock Enabled when chip is under IDLE mode.
<br>
</div></td></tr><tr><td>
[23]</td><td>CANFD0CKEN</td><td><div style="word-wrap: break-word;"><b>CANFD0 Clock Enable Bit
</b><br>
0 = CANFD0 clock Disabled.
<br>
1 = CANFD0 clock Enabled.
<br>
</div></td></tr><tr><td>
[24]</td><td>GPACKEN</td><td><div style="word-wrap: break-word;"><b>GPIOA Clock Enable Bit
</b><br>
0 = GPIOA port clock Disabled.
<br>
1 = GPIOA port clock Enabled.
<br>
</div></td></tr><tr><td>
[25]</td><td>GPBCKEN</td><td><div style="word-wrap: break-word;"><b>GPIOB Clock Enable Bit
</b><br>
0 = GPIOB port clock Disabled.
<br>
1 = GPIOB port clock Enabled.
<br>
</div></td></tr><tr><td>
[26]</td><td>GPCCKEN</td><td><div style="word-wrap: break-word;"><b>GPIOC Clock Enable Bit
</b><br>
0 = GPIOC port clock Disabled.
<br>
1 = GPIOC port clock Enabled.
<br>
</div></td></tr><tr><td>
[29]</td><td>GPFCKEN</td><td><div style="word-wrap: break-word;"><b>GPIOF Clock Enable Bit
</b><br>
0 = GPIOF port clock Disabled.
<br>
1 = GPIOF port clock Enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::APBCLK0

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">APBCLK0
</font><br><p> <font size="2">
Offset: 0x08  APB Devices Clock Enable Control Register 0
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>WDTCKEN</td><td><div style="word-wrap: break-word;"><b>Watchdog Timer Clock Enable Bit (Write Protect)
</b><br>
0 = Watchdog timer clock Disabled.
<br>
1 = Watchdog timer clock Enabled.
<br>
Note 1: This bit is write protected. Refer to the SYS_REGLCTL register.
<br>
Note 2: This bit is forced  to 1 when CONFIG0[3] or CONFIG0[4] or CONFIG0[31] is 0.
<br>
Note 3: Reset by power on reset or watch dog reset or software chip reset.
<br>
</div></td></tr><tr><td>
[1]</td><td>RTCCKEN</td><td><div style="word-wrap: break-word;"><b>Real-time-clock APB Interface Clock Enable Bit
</b><br>
This bit is used to control the RTC APB clock.
<br>
0 = RTC clock Disabled.
<br>
1 = RTC clock Enabled.
<br>
</div></td></tr><tr><td>
[2]</td><td>TMR0CKEN</td><td><div style="word-wrap: break-word;"><b>Timer0 Clock Enable Bit
</b><br>
0 = Timer0 clock Disabled.
<br>
1 = Timer0 clock Enabled.
<br>
</div></td></tr><tr><td>
[3]</td><td>TMR1CKEN</td><td><div style="word-wrap: break-word;"><b>Timer1 Clock Enable Bit
</b><br>
0 = Timer1 clock Disabled.
<br>
1 = Timer1 clock Enabled.
<br>
</div></td></tr><tr><td>
[4]</td><td>TMR2CKEN</td><td><div style="word-wrap: break-word;"><b>Timer2 Clock Enable Bit
</b><br>
0 = Timer2 clock Disabled.
<br>
1 = Timer2 clock Enabled.
<br>
</div></td></tr><tr><td>
[5]</td><td>TMR3CKEN</td><td><div style="word-wrap: break-word;"><b>Timer3 Clock Enable Bit
</b><br>
0 = Timer3 clock Disabled.
<br>
1 = Timer3 clock Enabled.
<br>
</div></td></tr><tr><td>
[6]</td><td>CLKOCKEN</td><td><div style="word-wrap: break-word;"><b>CLKO Clock Enable Bit
</b><br>
0 = CLKO clock Disabled.
<br>
1 = CLKO clock Enabled.
<br>
</div></td></tr><tr><td>
[8]</td><td>I2C0CKEN</td><td><div style="word-wrap: break-word;"><b>I2C0 Clock Enable Bit
</b><br>
0 = I2C0 clock Disabled.
<br>
1 = I2C0 clock Enabled.
<br>
</div></td></tr><tr><td>
[9]</td><td>I2C1CKEN</td><td><div style="word-wrap: break-word;"><b>I2C1 Clock Enable Bit
</b><br>
0 = I2C1 clock Disabled.
<br>
1 = I2C1 clock Enabled.
<br>
</div></td></tr><tr><td>
[13]</td><td>SPI0CKEN</td><td><div style="word-wrap: break-word;"><b>SPI0 Clock Enable Bit
</b><br>
0 = SPI0 clock Disabled.
<br>
1 = SPI0 clock Enabled.
<br>
</div></td></tr><tr><td>
[16]</td><td>UART0CKEN</td><td><div style="word-wrap: break-word;"><b>UART0 Clock Enable Bit
</b><br>
0 = UART0 clock Disabled.
<br>
1 = UART0 clock Enabled.
<br>
</div></td></tr><tr><td>
[17]</td><td>UART1CKEN</td><td><div style="word-wrap: break-word;"><b>UART1 Clock Enable Bit
</b><br>
0 = UART1 clock Disabled.
<br>
1 = UART1 clock Enabled.
<br>
</div></td></tr><tr><td>
[18]</td><td>UART2CKEN</td><td><div style="word-wrap: break-word;"><b>UART2 Clock Enable Bit
</b><br>
0 = UART2 clock Disabled.
<br>
1 = UART2 clock Enabled.
<br>
</div></td></tr><tr><td>
[19]</td><td>UART3CKEN</td><td><div style="word-wrap: break-word;"><b>UART3 Clock Enable Bit
</b><br>
0 = UART3 clock Disabled.
<br>
1 = UART3 clock Enabled.
<br>
</div></td></tr><tr><td>
[20]</td><td>UART4CKEN</td><td><div style="word-wrap: break-word;"><b>UART4 Clock Enable Bit
</b><br>
0 = UART4 clock Disabled.
<br>
1 = UART4 clock Enabled.
<br>
</div></td></tr><tr><td>
[27]</td><td>USBDCKEN</td><td><div style="word-wrap: break-word;"><b>USB Device Clock Enable Bit
</b><br>
0 = USB Device clock Disabled.
<br>
1 = USB Device clock Enabled.
<br>
</div></td></tr><tr><td>
[28]</td><td>EADCCKEN</td><td><div style="word-wrap: break-word;"><b>Enhanced Analog-digital-converter (EADC) Clock Enable Bit
</b><br>
0 = EADC clock Disabled.
<br>
1 = EADC clock Enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::APBCLK1

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">APBCLK1
</font><br><p> <font size="2">
Offset: 0x0C  APB Devices Clock Enable Control Register 1
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[8]</td><td>USCI0CKEN</td><td><div style="word-wrap: break-word;"><b>USCI0 Clock Enable Bit
</b><br>
0 = USCI0 clock Disabled.
<br>
1 = USCI0 clock Enabled.
<br>
</div></td></tr><tr><td>
[18]</td><td>BPWM0CKEN</td><td><div style="word-wrap: break-word;"><b>BPWM0 Clock Enable Bit
</b><br>
0 = BPWM0 clock Disabled.
<br>
1 = BPWM0 clock Enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::CLKSEL0

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CLKSEL0
</font><br><p> <font size="2">
Offset: 0x10  Clock Source Select Control Register 0
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[2:0]</td><td>HCLKSEL</td><td><div style="word-wrap: break-word;"><b>HCLK Clock Source Selection (Write Protect)
</b><br>
Before clock switching, the related clock sources (both pre-select and new-select) must be turned on.
<br>
000 = Clock source from HXT.
<br>
001 = Clock source from LXT.
<br>
011 = Clock source from LIRC.
<br>
101= Clock source from MIRC.
<br>
111= Clock source from HIRC.
<br>
Other = Reserved.
<br>
Note 1: This bit is write protected. Refer to the SYS_REGLCTL register.
<br>
Note 2: Reset by power on reset
<br>
</div></td></tr><tr><td>
[5:3]</td><td>STCLKSEL</td><td><div style="word-wrap: break-word;"><b>Cortex-M23 SysTick Clock Source Selection (Write Protect)
</b><br>
If SYST_CTRL[2]=0, SysTick uses listed clock source below.
<br>
000 = Clock source from HXT.
<br>
001 = Clock source from LXT.
<br>
010 = Clock source from HXT/2.
<br>
011 = Clock source from HCLK/2.
<br>
111 = Clock source from HIRC/2.
<br>
Note: if SysTick clock source is not from HCLK (i.e
<br>
SYST_CTRL[2] = 0), SysTick clock source must less than or equal to HCLK/2.
<br>
Note: This bit is write protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr><tr><td>
[24]</td><td>CANFD0SEL</td><td><div style="word-wrap: break-word;"><b>CANFD0 Clock Source Selection
</b><br>
0 = Clock source from HCLK.
<br>
1 = Clock source from HXT.
<br>
<br>
ource Select Control Register 1
<br>
------------------------------------------------------------------------------
<br>
Descriptions
<br>
 :---- |
<br>
</div></td></tr><tr><td>
[1:0]</td><td>WDTSEL</td><td><div style="word-wrap: break-word;"><b>Watchdog Timer Clock Source Selection (Write Protect)
</b><br>
00 = Reserved.
<br>
01 = Clock source from 32.768 kHz external low speed crystal oscillator (LXT).
<br>
10 = Clock source from HCLK/2048.
<br>
11 = Clock source from 38.4 kHz internal low speed RC oscillator (LIRC).
<br>
Note: This bit is write protected.Refer to the SYS_REGLCTL register
<br>
Note: This bit is forced to 11 when CONFIG0[31], CONFIG0[4], CONFIG0[3] are all ones.
<br>
</div></td></tr><tr><td>
[3:2]</td><td>WWDTSEL</td><td><div style="word-wrap: break-word;"><b>Window Watchdog Timer Clock Source Selection (Write Protect)
</b><br>
10 = Clock source from HCLK/2048.
<br>
11 = Clock source from 38.4 kHz internal low speed RC oscillator (LIRC).
<br>
Others = Reserved.
<br>
</div></td></tr><tr><td>
[6:4]</td><td>CLKOSEL</td><td><div style="word-wrap: break-word;"><b>Clock Divider Clock Source Selection
</b><br>
000 = Clock source from 4~32 MHz external high speed crystal oscillator (HXT).
<br>
001 = Clock source from 32.768 kHz external low speed crystal oscillator (LXT).
<br>
010 = Clock source from HCLK.
<br>
011 = Clock source from 48 MHz internal high speed RC oscillator (HIRC).
<br>
100 = Clock source from 38.4 kHz internal low speed RC oscillator (LIRC).
<br>
101 = Clock source from 4 MHz internal medium speed RC oscillator (MIRC).
<br>
111 = Clock source from internal USB SOF.
<br>
Others = Reserved.
<br>
</div></td></tr><tr><td>
[10:8]</td><td>TMR0SEL</td><td><div style="word-wrap: break-word;"><b>TIMER0 Clock Source Selection
</b><br>
000 = Clock source from 4~32 MHz external high speed crystal oscillator (HXT).
<br>
001 = Clock source from 32.768 kHz external low speed crystal oscillator (LXT).
<br>
010 = Clock source from PCLK0.
<br>
011 = Clock source from external clock T0 pin.
<br>
101 = Clock source from 38.4 kHz internal low speed RC oscillator (LIRC).
<br>
111 = Clock source from 48 MHz internal high speed RC oscillator (HIRC).
<br>
Others = Reserved.
<br>
</div></td></tr><tr><td>
[14:12]</td><td>TMR1SEL</td><td><div style="word-wrap: break-word;"><b>TIMER1 Clock Source Selection
</b><br>
000 = Clock source from 4~32 MHz external high speed crystal oscillator (HXT).
<br>
001 = Clock source from 32.768 kHz external low speed crystal oscillator (LXT).
<br>
010 = Clock source from PCLK0.
<br>
011 = Clock source from external clock T1 pin.
<br>
101 = Clock source from 38.4 kHz internal low speed RC oscillator (LIRC).
<br>
111 = Clock source from 48 MHz internal high speed RC oscillator (HIRC).
<br>
Others = Reserved.
<br>
</div></td></tr><tr><td>
[18:16]</td><td>TMR2SEL</td><td><div style="word-wrap: break-word;"><b>TIMER2 Clock Source Selection
</b><br>
000 = Clock source from 4~32 MHz external high speed crystal oscillator (HXT).
<br>
001 = Clock source from 32.768 kHz external low speed crystal oscillator (LXT).
<br>
010 = Clock source from PCLK1.
<br>
011 = Clock source from external clock T2 pin.
<br>
101 = Clock source from 38.4 kHz internal low speed RC oscillator (LIRC).
<br>
111 = Clock source from 48 MHz internal high speed RC oscillator (HIRC).
<br>
Others = Reserved.
<br>
</div></td></tr><tr><td>
[22:20]</td><td>TMR3SEL</td><td><div style="word-wrap: break-word;"><b>TIMER3 Clock Source Selection
</b><br>
000 = Clock source from 4~32 MHz external high speed crystal oscillator (HXT).
<br>
001 = Clock source from 32.768 kHz external low speed crystal oscillator (LXT).
<br>
010 = Clock source from PCLK1.
<br>
011 = Clock source from external clock T3 pin.
<br>
101 = Clock source from 38.4 kHz internal low speed RC oscillator (LIRC).
<br>
111 = Clock source from 48 MHz internal high speed RC oscillator (HIRC).
<br>
Others = Reserved.
<br>
</div></td></tr><tr><td>
[26:24]</td><td>UART0SEL</td><td><div style="word-wrap: break-word;"><b>UART0 Clock Source Selection
</b><br>
000 = Clock source from 4~32 MHz external high speed crystal oscillator (HXT).
<br>
010 = Clock source from 32.768 kHz external low speed crystal oscillator (LXT).
<br>
011 = Clock source from 48 MHz internal high speed RC oscillator (HIRC).
<br>
100 = Clock source from PCLK0.
<br>
101 = Clock source from 38.4 kHz  internal low speed RC oscillator (LIRC).
<br>
Others = Reserved.
<br>
</div></td></tr><tr><td>
[30:28]</td><td>UART1SEL</td><td><div style="word-wrap: break-word;"><b>UART1 Clock Source Selection
</b><br>
000 = Clock source from 4~32 MHz external high speed crystal oscillator (HXT).
<br>
010 = Clock source from 32.768 kHz external low speed crystal oscillator (LXT).
<br>
011 = Clock source from 48 MHz internal high speed RC oscillator (HIRC).
<br>
100 = Clock source from PCLK1.
<br>
101 = Clock source from 38.4 kHz  internal low speed RC oscillator (LIRC).
<br>
Others = Reserved.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::CLKSEL2

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CLKSEL2
</font><br><p> <font size="2">
Offset: 0x18  Clock Source Select Control Register 2
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[5:4]</td><td>SPI0SEL</td><td><div style="word-wrap: break-word;"><b>SPI0 Clock Source Selection
</b><br>
00 = Clock source from 4~32 MHz external high speed crystal oscillator (HXT).
<br>
01 = Reserved.
<br>
10 = Clock source from PCLK1.
<br>
11 = Clock source from 48 MHz internal high speed RC oscillator (HIRC).
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::CLKSEL3

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CLKSEL3
</font><br><p> <font size="2">
Offset: 0x1C  Clock Source Select Control Register 3
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[6:4]</td><td>UART4SEL</td><td><div style="word-wrap: break-word;"><b>UART4 Clock Source Selection
</b><br>
000 = Clock source from 4~32 MHz external high speed crystal oscillator (HXT).
<br>
010 = Clock source from 32.768 kHz external low speed crystal oscillator (LXT).
<br>
011 = Clock source from  48 MHz internal high speed RC oscillator (HIRC).
<br>
100 = Clock source from PCLK0.
<br>
101 = Clock source from 38.4 kHz  internal low speed RC oscillator (LIRC).
<br>
Others = Reserved.
<br>
</div></td></tr><tr><td>
[26:24]</td><td>UART2SEL</td><td><div style="word-wrap: break-word;"><b>UART2 Clock Source Selection
</b><br>
000 = Clock source from 4~32 MHz external high speed crystal oscillator (HXT).
<br>
010 = Clock source from 32.768 kHz external low speed crystal oscillator (LXT).
<br>
011 = Clock source from  48 MHz internal high speed RC oscillator (HIRC).
<br>
100 = Clock source from PCLK0.
<br>
101 = Clock source from 38.4 kHz  internal low speed RC oscillator (LIRC).
<br>
Others = Reserved.
<br>
</div></td></tr><tr><td>
[30:28]</td><td>UART3SEL</td><td><div style="word-wrap: break-word;"><b>UART3 Clock Source Selection
</b><br>
000 = Clock source from 4~32 MHz external high speed crystal oscillator (HXT).
<br>
010 = Clock source from 32.768 kHz external low speed crystal oscillator (LXT).
<br>
011 = Clock source from  48 MHz internal high speed RC oscillator (HIRC).
<br>
100= Clock source from PCLK1.
<br>
101= Clock source from 38.4 kHz  internal low speed RC oscillator (LIRC).
<br>
Others = Reserved.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::CLKDIV0

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CLKDIV0
</font><br><p> <font size="2">
Offset: 0x20  Clock Divider Number Register 0
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[3:0]</td><td>HCLKDIV</td><td><div style="word-wrap: break-word;"><b>HCLK Clock Divide Number From HCLK Clock Source
</b><br>
HCLK clock frequency = (HCLK clock source frequency) / (HCLKDIV + 1).
<br>
</div></td></tr><tr><td>
[11:8]</td><td>UART0DIV</td><td><div style="word-wrap: break-word;"><b>UART0 Clock Divide Number From UART0 Clock Source
</b><br>
UART0 clock frequency = (UART0 clock source frequency) / (UART0DIV + 1).
<br>
</div></td></tr><tr><td>
[15:12]</td><td>UART1DIV</td><td><div style="word-wrap: break-word;"><b>UART1 Clock Divide Number From UART1 Clock Source
</b><br>
UART1 clock frequency = (UART1 clock source frequency) / (UART1DIV + 1).
<br>
</div></td></tr><tr><td>
[23:16]</td><td>EADCDIV</td><td><div style="word-wrap: break-word;"><b>EADC Clock Divide Number From EADC Clock Source
</b><br>
EADC clock frequency = (EADC clock source frequency) / (EADCDIV + 1).
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::CLKDIV4

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CLKDIV4
</font><br><p> <font size="2">
Offset: 0x30  Clock Divider Number Register 4
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[3:0]</td><td>UART2DIV</td><td><div style="word-wrap: break-word;"><b>UART2 Clock Divide Number From UART2 Clock Source
</b><br>
UART2 clock frequency = (UART2 clock source frequency) / (UART2DIV + 1).
<br>
</div></td></tr><tr><td>
[7:4]</td><td>UART3DIV</td><td><div style="word-wrap: break-word;"><b>UART3 Clock Divide Number From UART3 Clock Source
</b><br>
UART3 clock frequency = (UART3 clock source frequency) / (UART3DIV + 1).
<br>
</div></td></tr><tr><td>
[11:8]</td><td>UART4DIV</td><td><div style="word-wrap: break-word;"><b>UART4 Clock Divide Number From UART4 Clock Source
</b><br>
UART4 clock frequency = (UART4 clock source frequency) / (UART4DIV + 1).
<br>
</div></td></tr><tr><td>
[17:16]</td><td>CANFD0DIV</td><td><div style="word-wrap: break-word;"><b>CANFD0 Clock Divide Number From CANFD0 Clock Source
</b><br>
CANFD0 clock frequency = (CANFD0 clock source frequency) / (CANFD0DIV + 1).
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::PCLKDIV

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">PCLKDIV
</font><br><p> <font size="2">
Offset: 0x34  APB Clock Divider Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[2:0]</td><td>APB0DIV</td><td><div style="word-wrap: break-word;"><b>APB0 Clock DIvider
</b><br>
APB0 clock can be divided from HCLK
<br>
000: PCLK0 = HCLK.
<br>
001: PCLK0 = 1/2 HCLK.
<br>
010: PCLK0 = 1/4 HCLK.
<br>
011: PCLK0 = 1/8 HCLK.
<br>
100: PCLK0 = 1/16 HCLK.
<br>
101: PCLK0 = 1/32 HCLK.
<br>
Others: Reserved.
<br>
</div></td></tr><tr><td>
[6:4]</td><td>APB1DIV</td><td><div style="word-wrap: break-word;"><b>APB1 Clock DIvider
</b><br>
APB1 clock can be divided from HCLK
<br>
000: PCLK1 = HCLK.
<br>
001: PCLK1 = 1/2 HCLK.
<br>
010: PCLK1 = 1/4 HCLK.
<br>
011: PCLK1 = 1/8 HCLK.
<br>
100: PCLK1 = 1/16 HCLK.
<br>
101: PCLK1 = 1/32 HCLK.
<br>
Others: Reserved.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::STATUS

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">STATUS
</font><br><p> <font size="2">
Offset: 0x50  Clock Status Monitor Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>HXTSTB</td><td><div style="word-wrap: break-word;"><b>HXT Clock Source Stable Flag (Read Only)
</b><br>
0 = 4~32 MHz external high speed crystal oscillator (HXT) clock is not stable or disabled.
<br>
1 = 4~32 MHz external high speed crystal oscillator (HXT) clock is stable and enabled.
<br>
</div></td></tr><tr><td>
[1]</td><td>LXTSTB</td><td><div style="word-wrap: break-word;"><b>LXT Clock Source Stable Flag (Read Only)
</b><br>
0 = 32.768 kHz external low speed crystal oscillator (LXT) clock is not stable or disabled.
<br>
1 = 32.768 kHz external low speed crystal oscillator (LXT) clock is stabled and enabled.
<br>
</div></td></tr><tr><td>
[3]</td><td>LIRCSTB</td><td><div style="word-wrap: break-word;"><b>LIRC Clock Source Stable Flag (Read Only)
</b><br>
0 = 38.4 kHz internal low speed RC oscillator (LIRC) clock is not stable or disabled.
<br>
1 = 38.4 kHz internal low speed RC oscillator (LIRC) clock is stable and enabled.
<br>
</div></td></tr><tr><td>
[4]</td><td>HIRCSTB</td><td><div style="word-wrap: break-word;"><b>HIRC Clock Source Stable Flag (Read Only)
</b><br>
0 = 48 MHz internal high speed RC oscillator (HIRC) clock is not stable or disabled.
<br>
1 = 48 MHz internal high speed RC oscillator (HIRC) clock is stable and enabled.
<br>
</div></td></tr><tr><td>
[6]</td><td>MIRCSTB</td><td><div style="word-wrap: break-word;"><b>MIRC Clock Source Stable Flag (Read Only)
</b><br>
0 = 4 MHz internal mid speed RC oscillator (MIRC) clock is not stable or disabled.
<br>
1 = 4 MHz internal mid speed RC oscillator (MIRC) clock is stable and enabled.
<br>
</div></td></tr><tr><td>
[7]</td><td>CLKSFAIL</td><td><div style="word-wrap: break-word;"><b>Clock Switching Fail Flag (Read Only)
</b><br>
This bit is updated when software switches system clock source
<br>
If switch target clock is stable, this bit will be set to 0
<br>
If switch target clock is not stable, this bit will be set to 1.
<br>
0 = Clock switching success.
<br>
1 = Clock switching failure.
<br>
Note: Write 1 to clear the bit to 0.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::CLKOCTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CLKOCTL
</font><br><p> <font size="2">
Offset: 0x60  Clock Output Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[3:0]</td><td>FREQSEL</td><td><div style="word-wrap: break-word;"><b>Clock Output Frequency Selection
</b><br>
The formula of output frequency is
<br>
Fout = Fin/2(N+1).
<br>
Fin is the input clock frequency.
<br>
Fout is the frequency of divider output clock.
<br>
N is the 4-bit value of FREQSEL[3:0].
<br>
</div></td></tr><tr><td>
[5]</td><td>DIV1EN</td><td><div style="word-wrap: break-word;"><b>Clock Output Divide One Enable Bit
</b><br>
0 = Clock Output will output clock with source frequency divided by FREQSEL.
<br>
1 = Clock Output will output clock with source frequency.
<br>
</div></td></tr><tr><td>
[6]</td><td>CLK1HZEN</td><td><div style="word-wrap: break-word;"><b>Clock Output 1Hz Enable Bit
</b><br>
0 = 1 Hz clock output for 32.768 kHz frequency compensation Disabled.
<br>
1 = 1 Hz clock output for 32.768 kHz frequency compensation Enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::CLKDCTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CLKDCTL
</font><br><p> <font size="2">
Offset: 0x70  Clock Fail Detector Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[4]</td><td>HXTFDEN</td><td><div style="word-wrap: break-word;"><b>HXT Clock Fail Detector Enable Bit
</b><br>
0 = 4~32 MHz external high speed crystal oscillator (HXT) clock fail detector Disabled.
<br>
1 = 4~32 MHz external high speed crystal oscillator (HXT) clock fail detector Enabled.
<br>
</div></td></tr><tr><td>
[5]</td><td>HXTFIEN</td><td><div style="word-wrap: break-word;"><b>HXT Clock Fail Interrupt Enable Bit
</b><br>
0 = 4~32 MHz external high speed crystal oscillator (HXT) clock fail interrupt Disabled.
<br>
1 = 4~32 MHz external high speed crystal oscillator (HXT) clock fail interrupt Enabled.
<br>
</div></td></tr><tr><td>
[12]</td><td>LXTFDEN</td><td><div style="word-wrap: break-word;"><b>LXT Clock Fail Detector Enable Bit
</b><br>
0 = 32.768 kHz external low speed crystal oscillator (LXT) clock fail detector Disabled.
<br>
1 = 32.768 kHz external low speed crystal oscillator (LXT) clock fail detector Enabled.
<br>
</div></td></tr><tr><td>
[13]</td><td>LXTFIEN</td><td><div style="word-wrap: break-word;"><b>LXT Clock Fail Interrupt Enable Bit
</b><br>
0 = 32.768 kHz external low speed crystal oscillator (LXT) clock fail interrupt Disabled.
<br>
1 = 32.768 kHz external low speed crystal oscillator (LXT) clock fail interrupt Enabled.
<br>
</div></td></tr><tr><td>
[16]</td><td>HXTFQDEN</td><td><div style="word-wrap: break-word;"><b>HXT Clock Frequency Range Detector Enable Bit
</b><br>
0 = 4~32 MHz external high speed crystal oscillator (HXT) clock frequency range detector Disabled.
<br>
1 = 4~32 MHz external high speed crystal oscillator (HXT) clock frequency range detector Enabled.
<br>
</div></td></tr><tr><td>
[17]</td><td>HXTFQIEN</td><td><div style="word-wrap: break-word;"><b>HXT Clock Frequency Range Detector Interrupt Enable Bit
</b><br>
0 = 4~32 MHz external high speed crystal oscillator (HXT) clock frequency range detector fail interrupt Disabled.
<br>
1 = 4~32 MHz external high speed crystal oscillator (HXT) clock frequency range detector fail interrupt Enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::CLKDSTS

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CLKDSTS
</font><br><p> <font size="2">
Offset: 0x74  Clock Fail Detector Status Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>HXTFIF</td><td><div style="word-wrap: break-word;"><b>HXT Clock Fail Interrupt Flag (Write Protect)
</b><br>
0 = 4~32 MHz external high speed crystal oscillator (HXT) clock is normal.
<br>
1 = 4~32 MHz external high speed crystal oscillator (HXT) clock stops.
<br>
Note: Write 1 to clear the bit to 0.
<br>
</div></td></tr><tr><td>
[1]</td><td>LXTFIF</td><td><div style="word-wrap: break-word;"><b>LXT Clock Fail Interrupt Flag (Write Protect)
</b><br>
0 = 32.768 kHz external low speed crystal oscillator (LXT) clock is normal.
<br>
1 = 32.768 kHz external low speed crystal oscillator (LXT) stops.
<br>
Note: Write 1 to clear the bit to 0.
<br>
</div></td></tr><tr><td>
[8]</td><td>HXTFQIF</td><td><div style="word-wrap: break-word;"><b>HXT Clock Frequency Range Detector Interrupt Flag (Write Protect)
</b><br>
0 = 4~32 MHz external high speed crystal oscillator (HXT) clock frequency is normal.
<br>
1 = 4~32 MHz external high speed crystal oscillator (HXT) clock frequency is abnormal.
<br>
Note: Write 1 to clear the bit to 0.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::CDUPB

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CDUPB
</font><br><p> <font size="2">
Offset: 0x78  Clock Frequency Range Detector Upper Boundary Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[9:0]</td><td>UPERBD</td><td><div style="word-wrap: break-word;"><b>HXT Clock Frequency Range Detector Upper Boundary Value
</b><br>
The bits define the maximum value of frequency range detector window.
<br>
When HXT frequency higher than this maximum frequency value, the HXT Clock Frequency Range Detector Interrupt Flag will set to 1.
<br>
Note :Frequency out of range will be asserted when HIRC_period*512> HXT_period*CLK_DUPB or HIRC_period*512 < HXT_period*CLK_CDLOWB.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::CDLOWB

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CDLOWB
</font><br><p> <font size="2">
Offset: 0x7C  Clock Frequency Range Detector Lower Boundary Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[9:0]</td><td>LOWERBD</td><td><div style="word-wrap: break-word;"><b>HXT Clock Frequency Range Detector Lower Boundary Value
</b><br>
The bits define the minimum value of frequency range detector window.
<br>
When HXT frequency lower than this minimum frequency value, the HXT Clock Frequency Range Detector Interrupt Flag will set to 1.
<br>
Note :The frequency out of range will be asserted when HIRC_period*512> HXT_period*CLK_DUPB or HIRC_period*512 < HXT_period*CLK_CDLOWB.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::PMUCTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">PMUCTL
</font><br><p> <font size="2">
Offset: 0x90  Power Manager Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[2:0]</td><td>PDMSEL</td><td><div style="word-wrap: break-word;"><b>Power-down Mode Selection (Write Protect)
</b><br>
This is a protected register. Please refer to open lock sequence to program it.
<br>
These bits control chip power-down mode grade selection when CPU execute WFI/WFE instruction.
<br>
000 = Power-down mode is selected. (PD)
<br>
010 = fast wake up.(FWPD)
<br>
others = Reserved.
<br>
Note: This bit is write protected. Refer to the SYS_REGLCTL register.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var CLK_T::HXTFSEL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">HXTFSEL
</font><br><p> <font size="2">
Offset: 0xB4  HXT Filter Select Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>HXTFSEL</td><td><div style="word-wrap: break-word;"><b>HXT Filter Select (Write Protect)
</b><br>
0 = HXT frequency is greater than 12 MHz.
<br>
1 = HXT frequency is less than or equal to 12 MHz.
<br>
Note 1: This bit is write protected. Refer to the SYS_REGLCTL register.
<br>
Note 2: This bit should not be changed during HXT running.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly



 */
    __IO uint32_t PWRCTL;                /*!< [0x0000] System Power-down Control Register                               */
    __IO uint32_t AHBCLK;                /*!< [0x0004] AHB Devices Clock Enable Control Register                        */
    __IO uint32_t APBCLK0;               /*!< [0x0008] APB Devices Clock Enable Control Register 0                      */
    __IO uint32_t APBCLK1;               /*!< [0x000c] APB Devices Clock Enable Control Register 1                      */
    __IO uint32_t CLKSEL0;               /*!< [0x0010] Clock Source Select Control Register 0                           */
    __IO uint32_t CLKSEL1;               /*!< [0x0014] Clock Source Select Control Register 1                           */
    __IO uint32_t CLKSEL2;               /*!< [0x0018] Clock Source Select Control Register 2                           */
    __IO uint32_t CLKSEL3;               /*!< [0x001c] Clock Source Select Control Register 3                           */
    __IO uint32_t CLKDIV0;               /*!< [0x0020] Clock Divider Number Register 0                                  */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[3];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CLKDIV4;               /*!< [0x0030] Clock Divider Number Register 4                                  */
    __IO uint32_t PCLKDIV;               /*!< [0x0034] APB Clock Divider Register                                       */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[6];
    /// @endcond //HIDDEN_SYMBOLS
    __I  uint32_t STATUS;                /*!< [0x0050] Clock Status Monitor Register                                    */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE2[3];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CLKOCTL;               /*!< [0x0060] Clock Output Control Register                                    */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE3[3];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t CLKDCTL;               /*!< [0x0070] Clock Fail Detector Control Register                             */
    __IO uint32_t CLKDSTS;               /*!< [0x0074] Clock Fail Detector Status Register                              */
    __IO uint32_t CDUPB;                 /*!< [0x0078] Clock Frequency Range Detector Upper Boundary Register           */
    __IO uint32_t CDLOWB;                /*!< [0x007c] Clock Frequency Range Detector Lower Boundary Register           */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE4[4];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t PMUCTL;                /*!< [0x0090] Power Manager Control Register                                   */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE5[8];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t HXTFSEL;               /*!< [0x00b4] HXT Filter Select Control Register                               */
} CLK_T;

/**
    @addtogroup CLK_CONST CLK Bit Field Definition
    Constant Definitions for CLK Controller
@{ */

#define CLK_PWRCTL_HXTEN_Pos             (0)                                               /*!< CLK_T::PWRCTL: HXTEN Position          */
#define CLK_PWRCTL_HXTEN_Msk             (0x1ul << CLK_PWRCTL_HXTEN_Pos)                   /*!< CLK_T::PWRCTL: HXTEN Mask              */

#define CLK_PWRCTL_LXTEN_Pos             (1)                                               /*!< CLK_T::PWRCTL: LXTEN Position          */
#define CLK_PWRCTL_LXTEN_Msk             (0x1ul << CLK_PWRCTL_LXTEN_Pos)                   /*!< CLK_T::PWRCTL: LXTEN Mask              */

#define CLK_PWRCTL_HIRCEN_Pos            (2)                                               /*!< CLK_T::PWRCTL: HIRCEN Position         */
#define CLK_PWRCTL_HIRCEN_Msk            (0x1ul << CLK_PWRCTL_HIRCEN_Pos)                  /*!< CLK_T::PWRCTL: HIRCEN Mask             */

#define CLK_PWRCTL_LIRCEN_Pos            (3)                                               /*!< CLK_T::PWRCTL: LIRCEN Position         */
#define CLK_PWRCTL_LIRCEN_Msk            (0x1ul << CLK_PWRCTL_LIRCEN_Pos)                  /*!< CLK_T::PWRCTL: LIRCEN Mask             */

#define CLK_PWRCTL_PDWKDLY_Pos           (4)                                               /*!< CLK_T::PWRCTL: PDWKDLY Position        */
#define CLK_PWRCTL_PDWKDLY_Msk           (0x1ul << CLK_PWRCTL_PDWKDLY_Pos)                 /*!< CLK_T::PWRCTL: PDWKDLY Mask            */

#define CLK_PWRCTL_PDWKIEN_Pos           (5)                                               /*!< CLK_T::PWRCTL: PDWKIEN Position        */
#define CLK_PWRCTL_PDWKIEN_Msk           (0x1ul << CLK_PWRCTL_PDWKIEN_Pos)                 /*!< CLK_T::PWRCTL: PDWKIEN Mask            */

#define CLK_PWRCTL_PDWKIF_Pos            (6)                                               /*!< CLK_T::PWRCTL: PDWKIF Position         */
#define CLK_PWRCTL_PDWKIF_Msk            (0x1ul << CLK_PWRCTL_PDWKIF_Pos)                  /*!< CLK_T::PWRCTL: PDWKIF Mask             */

#define CLK_PWRCTL_PDEN_Pos              (7)                                               /*!< CLK_T::PWRCTL: PDEN Position           */
#define CLK_PWRCTL_PDEN_Msk              (0x1ul << CLK_PWRCTL_PDEN_Pos)                    /*!< CLK_T::PWRCTL: PDEN Mask               */

#define CLK_PWRCTL_MIRCEN_Pos            (19)                                              /*!< CLK_T::PWRCTL: MIRCEN Position         */
#define CLK_PWRCTL_MIRCEN_Msk            (0x1ul << CLK_PWRCTL_MIRCEN_Pos)                  /*!< CLK_T::PWRCTL: MIRCEN Mask             */

#define CLK_PWRCTL_HXTGAIN_Pos           (20)                                              /*!< CLK_T::PWRCTL: HXTGAIN Position        */
#define CLK_PWRCTL_HXTGAIN_Msk           (0x7ul << CLK_PWRCTL_HXTGAIN_Pos)                 /*!< CLK_T::PWRCTL: HXTGAIN Mask            */

#define CLK_AHBCLK_PDMACKEN_Pos          (1)                                               /*!< CLK_T::AHBCLK: PDMACKEN Position       */
#define CLK_AHBCLK_PDMACKEN_Msk          (0x1ul << CLK_AHBCLK_PDMACKEN_Pos)                /*!< CLK_T::AHBCLK: PDMACKEN Mask           */

#define CLK_AHBCLK_ISPCKEN_Pos           (2)                                               /*!< CLK_T::AHBCLK: ISPCKEN Position        */
#define CLK_AHBCLK_ISPCKEN_Msk           (0x1ul << CLK_AHBCLK_ISPCKEN_Pos)                 /*!< CLK_T::AHBCLK: ISPCKEN Mask            */

#define CLK_AHBCLK_EXSTCKEN_Pos          (4)                                               /*!< CLK_T::AHBCLK: EXSTCKEN Position       */
#define CLK_AHBCLK_EXSTCKEN_Msk          (0x1ul << CLK_AHBCLK_EXSTCKEN_Pos)                /*!< CLK_T::AHBCLK: EXSTCKEN Mask           */

#define CLK_AHBCLK_CRCCKEN_Pos           (7)                                               /*!< CLK_T::AHBCLK: CRCCKEN Position        */
#define CLK_AHBCLK_CRCCKEN_Msk           (0x1ul << CLK_AHBCLK_CRCCKEN_Pos)                 /*!< CLK_T::AHBCLK: CRCCKEN Mask            */

#define CLK_AHBCLK_FMCIDLE_Pos           (15)                                              /*!< CLK_T::AHBCLK: FMCIDLE Position        */
#define CLK_AHBCLK_FMCIDLE_Msk           (0x1ul << CLK_AHBCLK_FMCIDLE_Pos)                 /*!< CLK_T::AHBCLK: FMCIDLE Mask            */

#define CLK_AHBCLK_CANFD0CKEN_Pos         (23)                                              /*!< CLK_T::AHBCLK: CANFD0CKEN Position      */
#define CLK_AHBCLK_CANFD0CKEN_Msk         (0x1ul << CLK_AHBCLK_CANFD0CKEN_Pos)               /*!< CLK_T::AHBCLK: CANFD0CKEN Mask          */

#define CLK_AHBCLK_GPACKEN_Pos           (24)                                              /*!< CLK_T::AHBCLK: GPACKEN Position        */
#define CLK_AHBCLK_GPACKEN_Msk           (0x1ul << CLK_AHBCLK_GPACKEN_Pos)                 /*!< CLK_T::AHBCLK: GPACKEN Mask            */

#define CLK_AHBCLK_GPBCKEN_Pos           (25)                                              /*!< CLK_T::AHBCLK: GPBCKEN Position        */
#define CLK_AHBCLK_GPBCKEN_Msk           (0x1ul << CLK_AHBCLK_GPBCKEN_Pos)                 /*!< CLK_T::AHBCLK: GPBCKEN Mask            */

#define CLK_AHBCLK_GPCCKEN_Pos           (26)                                              /*!< CLK_T::AHBCLK: GPCCKEN Position        */
#define CLK_AHBCLK_GPCCKEN_Msk           (0x1ul << CLK_AHBCLK_GPCCKEN_Pos)                 /*!< CLK_T::AHBCLK: GPCCKEN Mask            */

#define CLK_AHBCLK_GPDCKEN_Pos           (27)                                              /*!< CLK_T::AHBCLK: GPDCKEN Position        */
#define CLK_AHBCLK_GPDCKEN_Msk           (0x1ul << CLK_AHBCLK_GPDCKEN_Pos)                 /*!< CLK_T::AHBCLK: GPDCKEN Mask            */

#define CLK_AHBCLK_GPECKEN_Pos           (28)                                              /*!< CLK_T::AHBCLK: GPECKEN Position        */
#define CLK_AHBCLK_GPECKEN_Msk           (0x1ul << CLK_AHBCLK_GPECKEN_Pos)                 /*!< CLK_T::AHBCLK: GPECKEN Mask            */

#define CLK_AHBCLK_GPFCKEN_Pos           (29)                                              /*!< CLK_T::AHBCLK: GPFCKEN Position        */
#define CLK_AHBCLK_GPFCKEN_Msk           (0x1ul << CLK_AHBCLK_GPFCKEN_Pos)                 /*!< CLK_T::AHBCLK: GPFCKEN Mask            */

#define CLK_APBCLK0_WDTCKEN_Pos          (0)                                               /*!< CLK_T::APBCLK0: WDTCKEN Position       */
#define CLK_APBCLK0_WDTCKEN_Msk          (0x1ul << CLK_APBCLK0_WDTCKEN_Pos)                /*!< CLK_T::APBCLK0: WDTCKEN Mask           */

#define CLK_APBCLK0_RTCCKEN_Pos          (1)                                               /*!< CLK_T::APBCLK0: RTCCKEN Position       */
#define CLK_APBCLK0_RTCCKEN_Msk          (0x1ul << CLK_APBCLK0_RTCCKEN_Pos)                /*!< CLK_T::APBCLK0: RTCCKEN Mask           */

#define CLK_APBCLK0_TMR0CKEN_Pos         (2)                                               /*!< CLK_T::APBCLK0: TMR0CKEN Position      */
#define CLK_APBCLK0_TMR0CKEN_Msk         (0x1ul << CLK_APBCLK0_TMR0CKEN_Pos)               /*!< CLK_T::APBCLK0: TMR0CKEN Mask          */

#define CLK_APBCLK0_TMR1CKEN_Pos         (3)                                               /*!< CLK_T::APBCLK0: TMR1CKEN Position      */
#define CLK_APBCLK0_TMR1CKEN_Msk         (0x1ul << CLK_APBCLK0_TMR1CKEN_Pos)               /*!< CLK_T::APBCLK0: TMR1CKEN Mask          */

#define CLK_APBCLK0_TMR2CKEN_Pos         (4)                                               /*!< CLK_T::APBCLK0: TMR2CKEN Position      */
#define CLK_APBCLK0_TMR2CKEN_Msk         (0x1ul << CLK_APBCLK0_TMR2CKEN_Pos)               /*!< CLK_T::APBCLK0: TMR2CKEN Mask          */

#define CLK_APBCLK0_TMR3CKEN_Pos         (5)                                               /*!< CLK_T::APBCLK0: TMR3CKEN Position      */
#define CLK_APBCLK0_TMR3CKEN_Msk         (0x1ul << CLK_APBCLK0_TMR3CKEN_Pos)               /*!< CLK_T::APBCLK0: TMR3CKEN Mask          */

#define CLK_APBCLK0_CLKOCKEN_Pos         (6)                                               /*!< CLK_T::APBCLK0: CLKOCKEN Position      */
#define CLK_APBCLK0_CLKOCKEN_Msk         (0x1ul << CLK_APBCLK0_CLKOCKEN_Pos)               /*!< CLK_T::APBCLK0: CLKOCKEN Mask          */

#define CLK_APBCLK0_I2C0CKEN_Pos         (8)                                               /*!< CLK_T::APBCLK0: I2C0CKEN Position      */
#define CLK_APBCLK0_I2C0CKEN_Msk         (0x1ul << CLK_APBCLK0_I2C0CKEN_Pos)               /*!< CLK_T::APBCLK0: I2C0CKEN Mask          */

#define CLK_APBCLK0_I2C1CKEN_Pos         (9)                                               /*!< CLK_T::APBCLK0: I2C1CKEN Position      */
#define CLK_APBCLK0_I2C1CKEN_Msk         (0x1ul << CLK_APBCLK0_I2C1CKEN_Pos)               /*!< CLK_T::APBCLK0: I2C1CKEN Mask          */

#define CLK_APBCLK0_SPI0CKEN_Pos         (13)                                              /*!< CLK_T::APBCLK0: SPI0CKEN Position      */
#define CLK_APBCLK0_SPI0CKEN_Msk         (0x1ul << CLK_APBCLK0_SPI0CKEN_Pos)               /*!< CLK_T::APBCLK0: SPI0CKEN Mask          */

#define CLK_APBCLK0_UART0CKEN_Pos        (16)                                              /*!< CLK_T::APBCLK0: UART0CKEN Position     */
#define CLK_APBCLK0_UART0CKEN_Msk        (0x1ul << CLK_APBCLK0_UART0CKEN_Pos)              /*!< CLK_T::APBCLK0: UART0CKEN Mask         */

#define CLK_APBCLK0_UART1CKEN_Pos        (17)                                              /*!< CLK_T::APBCLK0: UART1CKEN Position     */
#define CLK_APBCLK0_UART1CKEN_Msk        (0x1ul << CLK_APBCLK0_UART1CKEN_Pos)              /*!< CLK_T::APBCLK0: UART1CKEN Mask         */

#define CLK_APBCLK0_UART2CKEN_Pos        (18)                                              /*!< CLK_T::APBCLK0: UART2CKEN Position     */
#define CLK_APBCLK0_UART2CKEN_Msk        (0x1ul << CLK_APBCLK0_UART2CKEN_Pos)              /*!< CLK_T::APBCLK0: UART2CKEN Mask         */

#define CLK_APBCLK0_UART3CKEN_Pos        (19)                                              /*!< CLK_T::APBCLK0: UART3CKEN Position     */
#define CLK_APBCLK0_UART3CKEN_Msk        (0x1ul << CLK_APBCLK0_UART3CKEN_Pos)              /*!< CLK_T::APBCLK0: UART3CKEN Mask         */

#define CLK_APBCLK0_UART4CKEN_Pos        (20)                                              /*!< CLK_T::APBCLK0: UART4CKEN Position     */
#define CLK_APBCLK0_UART4CKEN_Msk        (0x1ul << CLK_APBCLK0_UART4CKEN_Pos)              /*!< CLK_T::APBCLK0: UART4CKEN Mask         */

#define CLK_APBCLK0_USBDCKEN_Pos         (27)                                              /*!< CLK_T::APBCLK0: USBDCKEN Position      */
#define CLK_APBCLK0_USBDCKEN_Msk         (0x1ul << CLK_APBCLK0_USBDCKEN_Pos)               /*!< CLK_T::APBCLK0: USBDCKEN Mask          */

#define CLK_APBCLK0_EADCCKEN_Pos         (28)                                              /*!< CLK_T::APBCLK0: EADCCKEN Position      */
#define CLK_APBCLK0_EADCCKEN_Msk         (0x1ul << CLK_APBCLK0_EADCCKEN_Pos)               /*!< CLK_T::APBCLK0: EADCCKEN Mask          */

#define CLK_APBCLK1_SC0CKEN_Pos          (0)                                               /*!< CLK_T::APBCLK1: SC0CKEN Position       */
#define CLK_APBCLK1_SC0CKEN_Msk          (0x1ul << CLK_APBCLK1_SC0CKEN_Pos)                /*!< CLK_T::APBCLK1: SC0CKEN Mask           */

#define CLK_APBCLK1_USCI0CKEN_Pos        (8)                                               /*!< CLK_T::APBCLK1: USCI0CKEN Position     */
#define CLK_APBCLK1_USCI0CKEN_Msk        (0x1ul << CLK_APBCLK1_USCI0CKEN_Pos)              /*!< CLK_T::APBCLK1: USCI0CKEN Mask         */

#define CLK_APBCLK1_BPWM0CKEN_Pos        (18)                                              /*!< CLK_T::APBCLK1: BPWM0CKEN Position     */
#define CLK_APBCLK1_BPWM0CKEN_Msk        (0x1ul << CLK_APBCLK1_BPWM0CKEN_Pos)              /*!< CLK_T::APBCLK1: BPWM0CKEN Mask         */

#define CLK_CLKSEL0_HCLKSEL_Pos          (0)                                               /*!< CLK_T::CLKSEL0: HCLKSEL Position       */
#define CLK_CLKSEL0_HCLKSEL_Msk          (0x7ul << CLK_CLKSEL0_HCLKSEL_Pos)                /*!< CLK_T::CLKSEL0: HCLKSEL Mask           */

#define CLK_CLKSEL0_STCLKSEL_Pos         (3)                                               /*!< CLK_T::CLKSEL0: STCLKSEL Position      */
#define CLK_CLKSEL0_STCLKSEL_Msk         (0x7ul << CLK_CLKSEL0_STCLKSEL_Pos)               /*!< CLK_T::CLKSEL0: STCLKSEL Mask          */

#define CLK_CLKSEL0_CANFD0SEL_Pos         (24)                                              /*!< CLK_T::CLKSEL0: CANFD0SEL Position      */
#define CLK_CLKSEL0_CANFD0SEL_Msk         (0x1ul << CLK_CLKSEL0_CANFD0SEL_Pos)               /*!< CLK_T::CLKSEL0: CANFD0SEL Mask          */

#define CLK_CLKSEL1_WDTSEL_Pos           (0)                                               /*!< CLK_T::CLKSEL1: WDTSEL Position        */
#define CLK_CLKSEL1_WDTSEL_Msk           (0x3ul << CLK_CLKSEL1_WDTSEL_Pos)                 /*!< CLK_T::CLKSEL1: WDTSEL Mask            */

#define CLK_CLKSEL1_WWDTSEL_Pos          (2)                                               /*!< CLK_T::CLKSEL1: WWDTSEL Position       */
#define CLK_CLKSEL1_WWDTSEL_Msk          (0x3ul << CLK_CLKSEL1_WWDTSEL_Pos)                /*!< CLK_T::CLKSEL1: WWDTSEL Mask           */

#define CLK_CLKSEL1_CLKOSEL_Pos          (4)                                               /*!< CLK_T::CLKSEL1: CLKOSEL Position       */
#define CLK_CLKSEL1_CLKOSEL_Msk          (0x7ul << CLK_CLKSEL1_CLKOSEL_Pos)                /*!< CLK_T::CLKSEL1: CLKOSEL Mask           */

#define CLK_CLKSEL1_TMR0SEL_Pos          (8)                                               /*!< CLK_T::CLKSEL1: TMR0SEL Position       */
#define CLK_CLKSEL1_TMR0SEL_Msk          (0x7ul << CLK_CLKSEL1_TMR0SEL_Pos)                /*!< CLK_T::CLKSEL1: TMR0SEL Mask           */

#define CLK_CLKSEL1_TMR1SEL_Pos          (12)                                              /*!< CLK_T::CLKSEL1: TMR1SEL Position       */
#define CLK_CLKSEL1_TMR1SEL_Msk          (0x7ul << CLK_CLKSEL1_TMR1SEL_Pos)                /*!< CLK_T::CLKSEL1: TMR1SEL Mask           */

#define CLK_CLKSEL1_TMR2SEL_Pos          (16)                                              /*!< CLK_T::CLKSEL1: TMR2SEL Position       */
#define CLK_CLKSEL1_TMR2SEL_Msk          (0x7ul << CLK_CLKSEL1_TMR2SEL_Pos)                /*!< CLK_T::CLKSEL1: TMR2SEL Mask           */

#define CLK_CLKSEL1_TMR3SEL_Pos          (20)                                              /*!< CLK_T::CLKSEL1: TMR3SEL Position       */
#define CLK_CLKSEL1_TMR3SEL_Msk          (0x7ul << CLK_CLKSEL1_TMR3SEL_Pos)                /*!< CLK_T::CLKSEL1: TMR3SEL Mask           */

#define CLK_CLKSEL1_UART0SEL_Pos         (24)                                              /*!< CLK_T::CLKSEL1: UART0SEL Position      */
#define CLK_CLKSEL1_UART0SEL_Msk         (0x7ul << CLK_CLKSEL1_UART0SEL_Pos)               /*!< CLK_T::CLKSEL1: UART0SEL Mask          */

#define CLK_CLKSEL1_UART1SEL_Pos         (28)                                              /*!< CLK_T::CLKSEL1: UART1SEL Position      */
#define CLK_CLKSEL1_UART1SEL_Msk         (0x7ul << CLK_CLKSEL1_UART1SEL_Pos)               /*!< CLK_T::CLKSEL1: UART1SEL Mask          */

#define CLK_CLKSEL2_SPI0SEL_Pos          (4)                                               /*!< CLK_T::CLKSEL2: SPI0SEL Position       */
#define CLK_CLKSEL2_SPI0SEL_Msk          (0x3ul << CLK_CLKSEL2_SPI0SEL_Pos)                /*!< CLK_T::CLKSEL2: SPI0SEL Mask           */

#define CLK_CLKSEL3_UART4SEL_Pos         (4)                                               /*!< CLK_T::CLKSEL3: UART4SEL Position      */
#define CLK_CLKSEL3_UART4SEL_Msk         (0x7ul << CLK_CLKSEL3_UART4SEL_Pos)               /*!< CLK_T::CLKSEL3: UART4SEL Mask          */

#define CLK_CLKSEL3_UART2SEL_Pos         (24)                                              /*!< CLK_T::CLKSEL3: UART2SEL Position      */
#define CLK_CLKSEL3_UART2SEL_Msk         (0x7ul << CLK_CLKSEL3_UART2SEL_Pos)               /*!< CLK_T::CLKSEL3: UART2SEL Mask          */

#define CLK_CLKSEL3_UART3SEL_Pos         (28)                                              /*!< CLK_T::CLKSEL3: UART3SEL Position      */
#define CLK_CLKSEL3_UART3SEL_Msk         (0x7ul << CLK_CLKSEL3_UART3SEL_Pos)               /*!< CLK_T::CLKSEL3: UART3SEL Mask          */

#define CLK_CLKDIV0_HCLKDIV_Pos          (0)                                               /*!< CLK_T::CLKDIV0: HCLKDIV Position       */
#define CLK_CLKDIV0_HCLKDIV_Msk          (0xful << CLK_CLKDIV0_HCLKDIV_Pos)                /*!< CLK_T::CLKDIV0: HCLKDIV Mask           */

#define CLK_CLKDIV0_UART0DIV_Pos         (8)                                               /*!< CLK_T::CLKDIV0: UART0DIV Position      */
#define CLK_CLKDIV0_UART0DIV_Msk         (0xful << CLK_CLKDIV0_UART0DIV_Pos)               /*!< CLK_T::CLKDIV0: UART0DIV Mask          */

#define CLK_CLKDIV0_UART1DIV_Pos         (12)                                              /*!< CLK_T::CLKDIV0: UART1DIV Position      */
#define CLK_CLKDIV0_UART1DIV_Msk         (0xful << CLK_CLKDIV0_UART1DIV_Pos)               /*!< CLK_T::CLKDIV0: UART1DIV Mask          */

#define CLK_CLKDIV0_EADCDIV_Pos          (16)                                              /*!< CLK_T::CLKDIV0: EADCDIV Position       */
#define CLK_CLKDIV0_EADCDIV_Msk          (0xfful << CLK_CLKDIV0_EADCDIV_Pos)               /*!< CLK_T::CLKDIV0: EADCDIV Mask           */

#define CLK_CLKDIV4_UART2DIV_Pos         (0)                                               /*!< CLK_T::CLKDIV4: UART2DIV Position      */
#define CLK_CLKDIV4_UART2DIV_Msk         (0xful << CLK_CLKDIV4_UART2DIV_Pos)               /*!< CLK_T::CLKDIV4: UART2DIV Mask          */

#define CLK_CLKDIV4_UART3DIV_Pos         (4)                                               /*!< CLK_T::CLKDIV4: UART3DIV Position      */
#define CLK_CLKDIV4_UART3DIV_Msk         (0xful << CLK_CLKDIV4_UART3DIV_Pos)               /*!< CLK_T::CLKDIV4: UART3DIV Mask          */

#define CLK_CLKDIV4_UART4DIV_Pos         (8)                                               /*!< CLK_T::CLKDIV4: UART4DIV Position      */
#define CLK_CLKDIV4_UART4DIV_Msk         (0xful << CLK_CLKDIV4_UART4DIV_Pos)               /*!< CLK_T::CLKDIV4: UART4DIV Mask          */

#define CLK_CLKDIV4_CANFD0DIV_Pos         (16)                                              /*!< CLK_T::CLKDIV4: CANFD0DIV Positin       */
#define CLK_CLKDIV4_CANFD0DIV_Msk         (0x3ul << CLK_CLKDIV4_CANFD0DIV_Pos)               /*!< CLK_T::CLKDIV4: CANFD0DIV Mask          */

#define CLK_PCLKDIV_APB0DIV_Pos          (0)                                               /*!< CLK_T::PCLKDIV: APB0DIV Position       */
#define CLK_PCLKDIV_APB0DIV_Msk          (0x7ul << CLK_PCLKDIV_APB0DIV_Pos)                /*!< CLK_T::PCLKDIV: APB0DIV Mask           */

#define CLK_PCLKDIV_APB1DIV_Pos          (4)                                               /*!< CLK_T::PCLKDIV: APB1DIV Position       */
#define CLK_PCLKDIV_APB1DIV_Msk          (0x7ul << CLK_PCLKDIV_APB1DIV_Pos)                /*!< CLK_T::PCLKDIV: APB1DIV Mask           */

#define CLK_STATUS_HXTSTB_Pos            (0)                                               /*!< CLK_T::STATUS: HXTSTB Position         */
#define CLK_STATUS_HXTSTB_Msk            (0x1ul << CLK_STATUS_HXTSTB_Pos)                  /*!< CLK_T::STATUS: HXTSTB Mask             */

#define CLK_STATUS_LXTSTB_Pos            (1)                                               /*!< CLK_T::STATUS: LXTSTB Position         */
#define CLK_STATUS_LXTSTB_Msk            (0x1ul << CLK_STATUS_LXTSTB_Pos)                  /*!< CLK_T::STATUS: LXTSTB Mask             */

#define CLK_STATUS_LIRCSTB_Pos           (3)                                               /*!< CLK_T::STATUS: LIRCSTB Position        */
#define CLK_STATUS_LIRCSTB_Msk           (0x1ul << CLK_STATUS_LIRCSTB_Pos)                 /*!< CLK_T::STATUS: LIRCSTB Mask            */

#define CLK_STATUS_HIRCSTB_Pos           (4)                                               /*!< CLK_T::STATUS: HIRCSTB Position        */
#define CLK_STATUS_HIRCSTB_Msk           (0x1ul << CLK_STATUS_HIRCSTB_Pos)                 /*!< CLK_T::STATUS: HIRCSTB Mask            */

#define CLK_STATUS_MIRCSTB_Pos           (6)                                               /*!< CLK_T::STATUS: MIRCSTB Position        */
#define CLK_STATUS_MIRCSTB_Msk           (0x1ul << CLK_STATUS_MIRCSTB_Pos)                 /*!< CLK_T::STATUS: MIRCSTB Mask            */

#define CLK_STATUS_CLKSFAIL_Pos          (7)                                               /*!< CLK_T::STATUS: CLKSFAIL Position       */
#define CLK_STATUS_CLKSFAIL_Msk          (0x1ul << CLK_STATUS_CLKSFAIL_Pos)                /*!< CLK_T::STATUS: CLKSFAIL Mask           */

#define CLK_CLKOCTL_FREQSEL_Pos          (0)                                               /*!< CLK_T::CLKOCTL: FREQSEL Position       */
#define CLK_CLKOCTL_FREQSEL_Msk          (0xful << CLK_CLKOCTL_FREQSEL_Pos)                /*!< CLK_T::CLKOCTL: FREQSEL Mask           */

#define CLK_CLKOCTL_DIV1EN_Pos           (5)                                               /*!< CLK_T::CLKOCTL: DIV1EN Position        */
#define CLK_CLKOCTL_DIV1EN_Msk           (0x1ul << CLK_CLKOCTL_DIV1EN_Pos)                 /*!< CLK_T::CLKOCTL: DIV1EN Mask            */

#define CLK_CLKOCTL_CLK1HZEN_Pos         (6)                                               /*!< CLK_T::CLKOCTL: CLK1HZEN Position      */
#define CLK_CLKOCTL_CLK1HZEN_Msk         (0x1ul << CLK_CLKOCTL_CLK1HZEN_Pos)               /*!< CLK_T::CLKOCTL: CLK1HZEN Mask          */

#define CLK_CLKDCTL_HXTFDEN_Pos          (4)                                               /*!< CLK_T::CLKDCTL: HXTFDEN Position       */
#define CLK_CLKDCTL_HXTFDEN_Msk          (0x1ul << CLK_CLKDCTL_HXTFDEN_Pos)                /*!< CLK_T::CLKDCTL: HXTFDEN Mask           */

#define CLK_CLKDCTL_HXTFIEN_Pos          (5)                                               /*!< CLK_T::CLKDCTL: HXTFIEN Position       */
#define CLK_CLKDCTL_HXTFIEN_Msk          (0x1ul << CLK_CLKDCTL_HXTFIEN_Pos)                /*!< CLK_T::CLKDCTL: HXTFIEN Mask           */

#define CLK_CLKDCTL_LXTFDEN_Pos          (12)                                              /*!< CLK_T::CLKDCTL: LXTFDEN Position       */
#define CLK_CLKDCTL_LXTFDEN_Msk          (0x1ul << CLK_CLKDCTL_LXTFDEN_Pos)                /*!< CLK_T::CLKDCTL: LXTFDEN Mask           */

#define CLK_CLKDCTL_LXTFIEN_Pos          (13)                                              /*!< CLK_T::CLKDCTL: LXTFIEN Position       */
#define CLK_CLKDCTL_LXTFIEN_Msk          (0x1ul << CLK_CLKDCTL_LXTFIEN_Pos)                /*!< CLK_T::CLKDCTL: LXTFIEN Mask           */

#define CLK_CLKDCTL_HXTFQDEN_Pos         (16)                                              /*!< CLK_T::CLKDCTL: HXTFQDEN Position      */
#define CLK_CLKDCTL_HXTFQDEN_Msk         (0x1ul << CLK_CLKDCTL_HXTFQDEN_Pos)               /*!< CLK_T::CLKDCTL: HXTFQDEN Mask          */

#define CLK_CLKDCTL_HXTFQIEN_Pos         (17)                                              /*!< CLK_T::CLKDCTL: HXTFQIEN Position      */
#define CLK_CLKDCTL_HXTFQIEN_Msk         (0x1ul << CLK_CLKDCTL_HXTFQIEN_Pos)               /*!< CLK_T::CLKDCTL: HXTFQIEN Mask          */

#define CLK_CLKDSTS_HXTFIF_Pos           (0)                                               /*!< CLK_T::CLKDSTS: HXTFIF Position        */
#define CLK_CLKDSTS_HXTFIF_Msk           (0x1ul << CLK_CLKDSTS_HXTFIF_Pos)                 /*!< CLK_T::CLKDSTS: HXTFIF Mask            */

#define CLK_CLKDSTS_LXTFIF_Pos           (1)                                               /*!< CLK_T::CLKDSTS: LXTFIF Position        */
#define CLK_CLKDSTS_LXTFIF_Msk           (0x1ul << CLK_CLKDSTS_LXTFIF_Pos)                 /*!< CLK_T::CLKDSTS: LXTFIF Mask            */

#define CLK_CLKDSTS_HXTFQIF_Pos          (8)                                               /*!< CLK_T::CLKDSTS: HXTFQIF Position       */
#define CLK_CLKDSTS_HXTFQIF_Msk          (0x1ul << CLK_CLKDSTS_HXTFQIF_Pos)                /*!< CLK_T::CLKDSTS: HXTFQIF Mask           */

#define CLK_CDUPB_UPERBD_Pos             (0)                                               /*!< CLK_T::CDUPB: UPERBD Position          */
#define CLK_CDUPB_UPERBD_Msk             (0x3fful << CLK_CDUPB_UPERBD_Pos)                 /*!< CLK_T::CDUPB: UPERBD Mask              */

#define CLK_CDLOWB_LOWERBD_Pos           (0)                                               /*!< CLK_T::CDLOWB: LOWERBD Position        */
#define CLK_CDLOWB_LOWERBD_Msk           (0x3fful << CLK_CDLOWB_LOWERBD_Pos)               /*!< CLK_T::CDLOWB: LOWERBD Mask            */

#define CLK_PMUCTL_PDMSEL_Pos            (0)                                               /*!< CLK_T::PMUCTL: PDMSEL Position         */
#define CLK_PMUCTL_PDMSEL_Msk            (0x7ul << CLK_PMUCTL_PDMSEL_Pos)                  /*!< CLK_T::PMUCTL: PDMSEL Mask             */

#define CLK_PMUCTL_WKTMREN_Pos           (8)                                               /*!< CLK_T::PMUCTL: WKTMREN Position        */
#define CLK_PMUCTL_WKTMREN_Msk           (0x1ul << CLK_PMUCTL_WKTMREN_Pos)                 /*!< CLK_T::PMUCTL: WKTMREN Mask            */

#define CLK_PMUCTL_WKTMRIS_Pos           (9)                                               /*!< CLK_T::PMUCTL: WKTMRIS Position        */
#define CLK_PMUCTL_WKTMRIS_Msk           (0x7ul << CLK_PMUCTL_WKTMRIS_Pos)                 /*!< CLK_T::PMUCTL: WKTMRIS Mask            */

#define CLK_PMUCTL_WKPINEN0_Pos          (16)                                              /*!< CLK_T::PMUCTL: WKPINEN0 Position        */
#define CLK_PMUCTL_WKPINEN0_Msk          (0x3ul << CLK_PMUCTL_WKPINEN0_Pos)                /*!< CLK_T::PMUCTL: WKPINEN0 Mask            */

#define CLK_PMUCTL_WKPINDBEN_Pos         (22)                                              /*!< CLK_T::PMUCTL: WKPINDBEN Position        */
#define CLK_PMUCTL_WKPINDBEN_Msk         (0x1ul << CLK_PMUCTL_WKPINDBEN_Pos)               /*!< CLK_T::PMUCTL: WKPINDBEN Mask            */

#define CLK_PMUCTL_RTCWKEN_Pos           (23)                                              /*!< CLK_T::PMUCTL: RTCWKEN Position        */
#define CLK_PMUCTL_RTCWKEN_Msk           (0x1ul << CLK_PMUCTL_RTCWKEN_Pos)                 /*!< CLK_T::PMUCTL: RTCWKEN Mask            */

#define CLK_PMUCTL_WKPINEN1_Pos          (24)                                              /*!< CLK_T::PMUCTL: WKPINEN1 Position        */
#define CLK_PMUCTL_WKPINEN1_Msk          (0x3ul << CLK_PMUCTL_WKPINEN1_Pos)                /*!< CLK_T::PMUCTL: WKPINEN1 Mask            */

#define CLK_PMUCTL_WKPINEN2_Pos          (26)                                              /*!< CLK_T::PMUCTL: WKPINEN2 Position        */
#define CLK_PMUCTL_WKPINEN2_Msk          (0x3ul << CLK_PMUCTL_WKPINEN2_Pos)                /*!< CLK_T::PMUCTL: WKPINEN2 Mask            */

#define CLK_PMUCTL_WKPINEN3_Pos          (28)                                              /*!< CLK_T::PMUCTL: WKPINEN3 Position        */
#define CLK_PMUCTL_WKPINEN3_Msk          (0x3ul << CLK_PMUCTL_WKPINEN3_Pos)                /*!< CLK_T::PMUCTL: WKPINEN3 Mask            */

#define CLK_PMUCTL_WKPINEN4_Pos          (30)                                              /*!< CLK_T::PMUCTL: WKPINEN4 Position        */
#define CLK_PMUCTL_WKPINEN4_Msk          (0x3ul << CLK_PMUCTL_WKPINEN4_Pos)                /*!< CLK_T::PMUCTL: WKPINEN4 Mask            */

#define CLK_HXTFSEL_HXTFSEL_Pos          (0)                                               /*!< CLK_T::HXTFSEL: HXTFSEL Position       */
#define CLK_HXTFSEL_HXTFSEL_Msk          (0x1ul << CLK_HXTFSEL_HXTFSEL_Pos)                /*!< CLK_T::HXTFSEL: HXTFSEL Mask           */

/** @} CLK_CONST */
/** @} end of CLK register group */
/** @} end of REGISTER group */

#if defined ( __CC_ARM   )
    #pragma no_anon_unions
#endif

#endif /* __CLK_REG_H__ */
