/**************************************************************************//**
 * @file     eadc_reg.h
 * @version  V1.00
 * @brief    EADC register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __EADC_REG_H__
#define __EADC_REG_H__

#if defined ( __CC_ARM   )
    #pragma anon_unions
#endif

/**
    @addtogroup REGISTER Control Register
    @{
*/

/**
    @addtogroup EADC Enhanced Analog to Digital Converter (EADC)
    Memory Mapped Structure for EADC Controller
    @{
*/

typedef struct
{


    /**
@var EADC_T::DAT[19]

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">DAT[19]
</font><br><p> <font size="2">
Offset: 0x00~0x48  A/D Data Register 0~18 for Sample Module 0~18.
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
 :---- |
<br>
<tr><td>
[15:0]</td><td>RESULT</td><td><div style="word-wrap: break-word;"><b>A/D Conversion Result
</b><br>
This field contains 12 bits conversion result.
<br>
</div></td></tr><tr><td>
[16]</td><td>OV</td><td><div style="word-wrap: break-word;"><b>Overrun Flag
</b><br>
If converted data in RESULT[11:0] has not been read before new conversion result is loaded to this register, OV is set to 1.
<br>
0 = Data in RESULT[11:0] is recent conversion result.
<br>
1 = Data in RESULT[11:0] is overwrite.
<br>
Note: It is cleared by hardware after EADC_DAT register is read.
<br>
</div></td></tr><tr><td>
[17]</td><td>VALID</td><td><div style="word-wrap: break-word;"><b>Valid Flag
</b><br>
This bit is set to 1 when corresponding sample module channel analog input conversion is completed and cleared by hardware after EADC_DAT register is read.
<br>
0 = Data in RESULT[11:0] bits is not valid.
<br>
1 = Data in RESULT[11:0] bits is valid.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::CURDAT

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CURDAT
</font><br><p> <font size="2">
Offset: 0x4C  EADC PDMA Current Transfer Data Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[18:0]</td><td>CURDAT</td><td><div style="word-wrap: break-word;"><b>ADC PDMA Current Transfer Data (Read Only)
</b><br>
This register is a shadow register of EADC_DATn (n=0~3,16,17) for PDMA support.
<br>
This is a read only register.
<br>
NOTE: After PDMA read this register, the VAILD of the shadow EADC_DAT register will be automatically cleared.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::CTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CTL
</font><br><p> <font size="2">
Offset: 0x50  A/D Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>ADCEN</td><td><div style="word-wrap: break-word;"><b>A/D Converter Enable Bit
</b><br>
0 = ADC Disabled.
<br>
1 = ADC Enabled.
<br>
Note: Before starting A/D conversion function, this bit should be set to 1
<br>
Clear it to 0 to disable A/D converter analog circuit power consumption.
<br>
</div></td></tr><tr><td>
[1]</td><td>ADCRST</td><td><div style="word-wrap: break-word;"><b>ADC A/D Converter Control Circuits Reset
</b><br>
0 = No effect.
<br>
1 = Cause ADC control circuits reset to initial state, but not change the ADC registers value.
<br>
Note: ADCRST bit remains 1 during ADC reset, when ADC reset end, the ADCRST bit is automatically cleared to 0.
<br>
</div></td></tr><tr><td>
[2]</td><td>ADCIEN0</td><td><div style="word-wrap: break-word;"><b>Specific Sample Module A/D ADINT0 Interrupt Enable Bit
</b><br>
The A/D converter generates a conversion end ADIF0 (EADC_STATUS2[0]) upon the end of specific sample module A/D conversion
<br>
If ADCIEN0 bit is set then conversion end interrupt request ADINT0 is generated.
<br>
0 = Specific sample module A/D ADINT0 interrupt function Disabled.
<br>
1 = Specific sample module A/D ADINT0 interrupt function Enabled.
<br>
</div></td></tr><tr><td>
[3]</td><td>ADCIEN1</td><td><div style="word-wrap: break-word;"><b>Specific Sample Module A/D ADINT1 Interrupt Enable Bit
</b><br>
The A/D converter generates a conversion end ADIF1 (EADC_STATUS2[1]) upon the end of specific sample module A/D conversion
<br>
If ADCIEN1 bit is set then conversion end interrupt request ADINT1 is generated.
<br>
0 = Specific sample module A/D ADINT1 interrupt function Disabled.
<br>
1 = Specific sample module A/D ADINT1 interrupt function Enabled.
<br>
</div></td></tr><tr><td>
[4]</td><td>ADCIEN2</td><td><div style="word-wrap: break-word;"><b>Specific Sample Module A/D ADINT2 Interrupt Enable Bit
</b><br>
The A/D converter generates a conversion end ADIF2 (EADC_STATUS2[2]) upon the end of specific sample module A/D conversion
<br>
If ADCIEN2 bit is set then conversion end interrupt request ADINT2 is generated.
<br>
0 = Specific sample module A/D ADINT2 interrupt function Disabled.
<br>
1 = Specific sample module A/D ADINT2 interrupt function Enabled.
<br>
</div></td></tr><tr><td>
[5]</td><td>ADCIEN3</td><td><div style="word-wrap: break-word;"><b>Specific Sample Module A/D ADINT3 Interrupt Enable Bit
</b><br>
The A/D converter generates a conversion end ADIF3 (EADC_STATUS2[3]) upon the end of specific sample module A/D conversion
<br>
If ADCIEN3 bit is set then conversion end interrupt request ADINT3 is generated.
<br>
0 = Specific sample module A/D ADINT3 interrupt function Disabled.
<br>
1 = Specific sample module A/D ADINT3 interrupt function Enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::SWTRG

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">SWTRG
</font><br><p> <font size="2">
Offset: 0x54  A/D Sample Module Software Start Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[18:0]</td><td>SWTRG</td><td><div style="word-wrap: break-word;"><b>A/D Sample Module 0~3,16,17 Software Force to Start ADC Conversion
</b><br>
0 = No effect.
<br>
1 = Cause an ADC conversion when the priority is given to sample module.
<br>
Note: After writing this register to start ADC conversion, the EADC_PENDSTS register will show which sample module will conversion
<br>
If user want to disable the conversion of the sample module, user can write EADC_PENDSTS register to clear it.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::PENDSTS

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">PENDSTS
</font><br><p> <font size="2">
Offset: 0x58  A/D Start of Conversion Pending Flag Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[18:0]</td><td>STPF</td><td><div style="word-wrap: break-word;"><b>A/D Sample Module 0~3,16,17 Start of Conversion Pending Flag
</b><br>
Read:
<br>
0 = There is no pending conversion for sample module.
<br>
1 = Sample module ADC start of conversion is pending.
<br>
Write:
<br>
1 = Clear pending flag and stop conversion for corresponding sample module.
<br>
Note1: This bit remains 1 during pending state, when the respective ADC conversion is end, the STPFn (n=0~3,16,17) bit is automatically cleared to 0.
<br>
Note2: After stopping current conversion, the corresponding EADC_DATn (n=0~18) keeps its original value
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::OVSTS

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">OVSTS
</font><br><p> <font size="2">
Offset: 0x5C  A/D Sample Module Start of Conversion Overrun Flag Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[18:0]</td><td>SPOVF</td><td><div style="word-wrap: break-word;"><b>A/D SAMPLE0~18 Overrun Flag
</b><br>
0 = No sample module event overrun.
<br>
1 = Indicates a new sample module event is generated while an old one event is pending.
<br>
Note: This bit is cleared by writing 1 to it.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::SCTL[16]

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">SCTL[16]
</font><br><p> <font size="2">
Offset: 0x80~0xBC  A/D Sample Module 0 ~ 15 Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
 :---- |
<br>
<tr><td>
[3:0]</td><td>CHSEL</td><td><div style="word-wrap: break-word;"><b>A/D Sample Module Channel Selection
</b><br>
00H = EADC_CH0.
<br>
01H = EADC_CH1.
<br>
02H = EADC_CH2.
<br>
03H = EADC_CH3.
<br>
04H = EADC_CH4.
<br>
05H = EADC_CH5.
<br>
06H = EADC_CH6.
<br>
07H = EADC_CH7.
<br>
08H = Reserved.
<br>
09H = Reserved.
<br>
0AH = Reserved.
<br>
0BH = Reserved.
<br>
0CH = EADC_CH12.
<br>
0DH = EADC_CH13.
<br>
0EH = EADC_CH14.
<br>
0FH = EADC_CH15.
<br>
Note: when internal ADC channel16, 17 or 18 is selected, EADC_CH15 is useless.
<br>
</div></td></tr><tr><td>
[4]</td><td>EXTREN</td><td><div style="word-wrap: break-word;"><b>A/D External Trigger Rising Edge Enable Bit
</b><br>
0 = Rising edge Disabled when A/D selects EADC0_ST as trigger source.
<br>
1 = Rising edge Enabled when A/D selects EADC0_ST trigger source.
<br>
</div></td></tr><tr><td>
[5]</td><td>EXTFEN</td><td><div style="word-wrap: break-word;"><b>A/D External Trigger Falling Edge Enable Bit
</b><br>
0 = Falling edge Disabled when A/D selects EADC0_ST as trigger source.
<br>
1 = Falling edge Enabled when A/D selects EADC0_ST as trigger source.
<br>
</div></td></tr><tr><td>
[7:6]</td><td>TRGDLYDIV</td><td><div style="word-wrap: break-word;"><b>A/D Sample Module Start of Conversion Trigger Delay Clock Divider Selection
</b><br>
Trigger delay clock frequency:
<br>
00 = ADC_CLK/1.
<br>
01 = ADC_CLK/2.
<br>
10 = ADC_CLK/4.
<br>
11 = ADC_CLK/16.
<br>
</div></td></tr><tr><td>
[15:8]</td><td>TRGDLYCNT</td><td><div style="word-wrap: break-word;"><b>A/D Sample Module Start of Conversion Trigger Delay Time
</b><br>
Trigger delay time = TRGDLYCNT x ADC_CLK x n (n=1,2,4,16 from TRGDLYDIV setting).
<br>
Note: If TRGDLYCNT is set to 1, Trigger delay time is actually the same as TRGDLYCNT is set to 2 for hardware operation.
<br>
</div></td></tr><tr><td>
[20:16]</td><td>TRGSEL</td><td><div style="word-wrap: break-word;"><b>A/D Sample Module Start of Conversion Trigger Source Selection
</b><br>
0H = Disable trigger.
<br>
1H = External trigger from EADC0_ST pin input.
<br>
2H = ADC ADINT0 interrupt EOC (End of conversion) pulse trigger.
<br>
3H = ADC ADINT1 interrupt EOC (End of conversion) pulse trigger.
<br>
4H = Timer0 overflow pulse trigger.
<br>
5H = Timer1 overflow pulse trigger.
<br>
6H = Timer2 overflow pulse trigger.
<br>
7H = Timer3 overflow pulse trigger.
<br>
8H = Reserved.
<br>
9H = Reserved.
<br>
AH = Reserved.
<br>
BH = Reserved.
<br>
CH = Reserved.
<br>
DH = Reserved.
<br>
EH = Reserved.
<br>
FH = Reserved.
<br>
10H = Reserved.
<br>
11H = Reserved.
<br>
12H = Reserved.
<br>
13H = Reserved.
<br>
14H =BPWM0TG.
<br>
15H =BPWM1TG.
<br>
other = Reserved.
<br>
NOTE: Refer PWM_EADCTS0, PWM_EADCTS1, BPWM_EADCTS0, BPWM_ EADCTS1 and TIMERn_CTL (n=0~3) to get more information for PWM, BPWM trigger and timer trigger.
<br>
</div></td></tr><tr><td>
[22]</td><td>INTPOS</td><td><div style="word-wrap: break-word;"><b>Interrupt Flag Position Select
</b><br>
0 = Set ADIFn (EADC_STATUS2[n], n=0~3) at A/D end of conversion.
<br>
1 = Set ADIFn (EADC_STATUS2[n], n=0~3) at A/D start of conversion.
<br>
</div></td></tr><tr><td>
[31:24]</td><td>EXTSMPT</td><td><div style="word-wrap: break-word;"><b>ADC Sampling Time Extend
</b><br>
When A/D converting at high conversion rate, the sampling time of analog input voltage may not enough if input channel loading is heavy, user can extend A/D sampling time after trigger source is coming to get enough sampling time
<br>
EXTSMPT can be set from 0~8'd251.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::SCTL0[3]

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">SCTL0[3]
</font><br><p> <font size="2">
Offset: 0xc0~0xC8  A/D Sample Module 16 ~ 18 Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
 :---- |
<br>
<tr><td>
[0]</td><td>PDMAEN</td><td><div style="word-wrap: break-word;"><b>PDMA Transfer Enable Bit
</b><br>
When ADC conversion is completed, the converted data is loaded into EADC_DATn (n: 16 ~ 18) register, user can enable this bit to generate a PDMA data transfer request.
<br>
0 = PDMA data transfer Disabled.
<br>
1 = PDMA data transfer Enabled.
<br>
Note: When set this bit field to 1, user must set ADCIENn (EADC_CTL[5:2], n=0~3) = 0 to disable interrupt.
<br>
</div></td></tr><tr><td>
[31:24]</td><td>EXTSMPT</td><td><div style="word-wrap: break-word;"><b>ADC Sampling Time Extend
</b><br>
When A/D converting at high conversion rate, the sampling time of analog input voltage may not enough if input channel loading is heavy, user can extend A/D sampling time after trigger source is coming to get enough sampling time
<br>
EXTSMPT can be set from 0~8'd251.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::INTSRC[4]

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">INTSRC[4]
</font><br><p> <font size="2">
Offset: 0xD0~0xDC  ADC Interrupt 0~4 Source Enable Control Register.
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>SPLIE0</td><td><div style="word-wrap: break-word;"><b>Sample Module 0 Interrupt Enable Bit
</b><br>
0 = Sample Module 0 interrupt Disabled.
<br>
1 = Sample Module 0 interrupt Enabled.
<br>
</div></td></tr><tr><td>
[1]</td><td>SPLIE1</td><td><div style="word-wrap: break-word;"><b>Sample Module 1 Interrupt Enable Bit
</b><br>
0 = Sample Module 1 interrupt Disabled.
<br>
1 = Sample Module 1 interrupt Enabled.
<br>
</div></td></tr><tr><td>
[2]</td><td>SPLIE2</td><td><div style="word-wrap: break-word;"><b>Sample Module 2 Interrupt Enable Bit
</b><br>
0 = Sample Module 2 interrupt Disabled.
<br>
1 = Sample Module 2 interrupt Enabled.
<br>
</div></td></tr><tr><td>
[3]</td><td>SPLIE3</td><td><div style="word-wrap: break-word;"><b>Sample Module 3 Interrupt Enable Bit
</b><br>
0 = Sample Module 3 interrupt Disabled.
<br>
1 = Sample Module 3 interrupt Enabled.
<br>
</div></td></tr><tr><td>
[16]</td><td>SPLIE16</td><td><div style="word-wrap: break-word;"><b>Sample Module 16 Interrupt Enable Bit
</b><br>
0 = Sample Module 16 interrupt Disabled.
<br>
1 = Sample Module 16 interrupt Enabled.
<br>
</div></td></tr><tr><td>
[17]</td><td>SPLIE17</td><td><div style="word-wrap: break-word;"><b>Sample Module 17 Interrupt Enable Bit
</b><br>
0 = Sample Module 17 interrupt Disabled.
<br>
1 = Sample Module 17 interrupt Enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::CMP[4]

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CMP[4]
</font><br><p> <font size="2">
Offset: 0xE0~0xEC  A/D Result Compare Register 0 ~ 3
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>ADCMPEN</td><td><div style="word-wrap: break-word;"><b>A/D Result Compare Enable Bit
</b><br>
0 = Compare Disabled.
<br>
1 = Compare Enabled.
<br>
Set this bit to 1 to enable compare CMPDAT (EADC_CMPn[27:16], n=0~3) with specified sample module conversion result when converted data is loaded into EADC_DAT register.
<br>
</div></td></tr><tr><td>
[1]</td><td>ADCMPIE</td><td><div style="word-wrap: break-word;"><b>A/D Result Compare Interrupt Enable Bit
</b><br>
0 = Compare function interrupt Disabled.
<br>
1 = Compare function interrupt Enabled.
<br>
If the compare function is enabled and the compare condition matches the setting of CMPCOND (EADC_CMPn[2], n=0~3) and CMPMCNT (EADC_CMPn[11:8], n=0~3), ADCMPFn (EADC_STATUS2[7:4], n=0~3) will be asserted, in the meanwhile, if ADCMPIE is set to 1, a compare interrupt request is generated.
<br>
</div></td></tr><tr><td>
[2]</td><td>CMPCOND</td><td><div style="word-wrap: break-word;"><b>Compare Condition
</b><br>
0= Set the compare condition as that when a 12-bit A/D conversion result is less than the 12-bit CMPDAT (EADC_CMPn [27:16]), the internal match counter will increase one.
<br>
1= Set the compare condition as that when a 12-bit A/D conversion result is greater or equal to the 12-bit CMPDAT (EADC_CMPn [27:16]), the internal match counter will increase one.
<br>
Note: When the internal counter reaches the value to (CMPMCNT (EADC_CMPn[11:8], n=0~3) +1), the ADCMPFn bit will be set.
<br>
</div></td></tr><tr><td>
[7:3]</td><td>CMPSPL</td><td><div style="word-wrap: break-word;"><b>Compare Sample Module Selection
</b><br>
00000 = Sample Module 0 conversion result EADC_DAT0 is selected to be compared.
<br>
00001 = Sample Module 1 conversion result EADC_DAT1 is selected to be compared.
<br>
00010 = Sample Module 2 conversion result EADC_DAT2 is selected to be compared.
<br>
00011 = Sample Module 3 conversion result EADC_DAT3 is selected to be compared.
<br>
10000 = Sample Module 16 conversion result EADC_DAT16 is selected to be compared.
<br>
10001 = Sample Module 17 conversion result EADC_DAT17 is selected to be compared.
<br>
</div></td></tr><tr><td>
[11:8]</td><td>CMPMCNT</td><td><div style="word-wrap: break-word;"><b>Compare Match Count
</b><br>
When the specified A/D sample module analog conversion result matches the compare condition defined by CMPCOND (EADC_CMPn[2], n=0~3), the internal match counter will increase 1
<br>
If the compare result does not meet the compare condition, the internal compare match counter will reset to 0
<br>
When the internal counter reaches the value to (CMPMCNT +1), the ADCMPFn (EADC_STATUS2[7:4], n=0~3) will be set.
<br>
</div></td></tr><tr><td>
[15]</td><td>CMPWEN</td><td><div style="word-wrap: break-word;"><b>Compare Window Mode Enable Bit
</b><br>
0 = ADCMPF0 (EADC_STATUS2[4]) will be set when EADC_CMP0 compared condition matched
<br>
ADCMPF2 (EADC_STATUS2[6]) will be set when EADC_CMP2 compared condition matched
<br>
1 = ADCMPF0 (EADC_STATUS2[4]) will be set when both EADC_CMP0 and EADC_CMP1 compared condition matched
<br>
ADCMPF2 (EADC_STATUS2[6]) will be set when both EADC_CMP2 and EADC_CMP3 compared condition matched.
<br>
Note: This bit is only present in EADC_CMP0 and EADC_CMP2 register.
<br>
</div></td></tr><tr><td>
[27:16]</td><td>CMPDAT</td><td><div style="word-wrap: break-word;"><b>Comparison Data
</b><br>
The 12 bits data is used to compare with conversion result of specified sample module
<br>
User can use it to monitor the external analog input pin voltage transition without imposing a load on software.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::STATUS0

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">STATUS0
</font><br><p> <font size="2">
Offset: 0xF0  A/D Status Register 0
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[15:0]</td><td>VALID</td><td><div style="word-wrap: break-word;"><b>EADC_DAT0~3 Data Valid Flag
</b><br>
It is a mirror of VALID bit in sample module A/D result data register EADC_DATn. (n=0~3).
<br>
</div></td></tr><tr><td>
[31:16]</td><td>OV</td><td><div style="word-wrap: break-word;"><b>EADC_DAT0~3 Overrun Flag
</b><br>
It is a mirror to OV bit in sample module A/D result data register EADC_DATn. (n=0~3).
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::STATUS1

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">STATUS1
</font><br><p> <font size="2">
Offset: 0xF4  A/D Status Register 1
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[2:0]</td><td>VALID</td><td><div style="word-wrap: break-word;"><b>EADC_DAT16~17 Data Valid Flag
</b><br>
It is a mirror of VALID bit in sample module A/D result data register EADC_DATn. (n=16~17).
<br>
</div></td></tr><tr><td>
[18:16]</td><td>OV</td><td><div style="word-wrap: break-word;"><b>EADC_DAT16~17 Overrun Flag
</b><br>
It is a mirror to OV bit in sample module A/D result data register EADC_DATn. (n=16~17).
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::STATUS2

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">STATUS2
</font><br><p> <font size="2">
Offset: 0xF8  A/D Status Register 2
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>ADIF0</td><td><div style="word-wrap: break-word;"><b>A/D ADINT0 Interrupt Flag
</b><br>
0 = No ADINT0 interrupt pulse received.
<br>
1 = ADINT0 interrupt pulse has been received.
<br>
Note1: This bit is cleared by writing 1 to it.
<br>
Note2:This bit indicates whether an A/D conversion of specific sample module has been completed
<br>
</div></td></tr><tr><td>
[1]</td><td>ADIF1</td><td><div style="word-wrap: break-word;"><b>A/D ADINT1 Interrupt Flag
</b><br>
0 = No ADINT1 interrupt pulse received.
<br>
1 = ADINT1 interrupt pulse has been received.
<br>
Note1: This bit is cleared by writing 1 to it.
<br>
Note2:This bit indicates whether an A/D conversion of specific sample module has been completed
<br>
</div></td></tr><tr><td>
[2]</td><td>ADIF2</td><td><div style="word-wrap: break-word;"><b>A/D ADINT2 Interrupt Flag
</b><br>
0 = No ADINT2 interrupt pulse received.
<br>
1 = ADINT2 interrupt pulse has been received.
<br>
Note1: This bit is cleared by writing 1 to it.
<br>
Note2:This bit indicates whether an A/D conversion of specific sample module has been completed
<br>
</div></td></tr><tr><td>
[3]</td><td>ADIF3</td><td><div style="word-wrap: break-word;"><b>A/D ADINT3 Interrupt Flag
</b><br>
0 = No ADINT3 interrupt pulse received.
<br>
1 = ADINT3 interrupt pulse has been received.
<br>
Note1: This bit is cleared by writing 1 to it.
<br>
Note2:This bit indicates whether an A/D conversion of specific sample module has been completed
<br>
</div></td></tr><tr><td>
[4]</td><td>ADCMPF0</td><td><div style="word-wrap: break-word;"><b>ADC Compare 0 Flag
</b><br>
When the specific sample module A/D conversion result meets setting condition in EADC_CMP0 then this bit is set to 1.
<br>
0 = Conversion result in EADC_DAT does not meet EADC_CMP0 register setting.
<br>
1 = Conversion result in EADC_DAT meets EADC_CMP0 register setting.
<br>
Note: This bit is cleared by writing 1 to it.
<br>
</div></td></tr><tr><td>
[5]</td><td>ADCMPF1</td><td><div style="word-wrap: break-word;"><b>ADC Compare 1 Flag
</b><br>
When the specific sample module A/D conversion result meets setting condition in EADC_CMP1 then this bit is set to 1.
<br>
0 = Conversion result in EADC_DAT does not meet EADC_CMP1 register setting.
<br>
1 = Conversion result in EADC_DAT meets EADC_CMP1 register setting.
<br>
Note: This bit is cleared by writing 1 to it.
<br>
</div></td></tr><tr><td>
[6]</td><td>ADCMPF2</td><td><div style="word-wrap: break-word;"><b>ADC Compare 2 Flag
</b><br>
When the specific sample module A/D conversion result meets setting condition in EADC_CMP2 then this bit is set to 1.
<br>
0 = Conversion result in EADC_DAT does not meet EADC_CMP2 register setting.
<br>
1 = Conversion result in EADC_DAT meets EADC_CMP2 register setting.
<br>
Note: This bit is cleared by writing 1 to it.
<br>
</div></td></tr><tr><td>
[7]</td><td>ADCMPF3</td><td><div style="word-wrap: break-word;"><b>ADC Compare 3 Flag
</b><br>
When the specific sample module A/D conversion result meets setting condition in EADC_CMP3 then this bit is set to 1.
<br>
0 = Conversion result in EADC_DAT does not meet EADC_CMP3 register setting.
<br>
1 = Conversion result in EADC_DAT meets EADC_CMP3 register setting.
<br>
Note: This bit is cleared by writing 1 to it.
<br>
</div></td></tr><tr><td>
[8]</td><td>ADOVIF0</td><td><div style="word-wrap: break-word;"><b>A/D ADINT0 Interrupt Flag Overrun
</b><br>
0 = ADINT0 interrupt flag is not overwritten to 1.
<br>
1 = ADINT0 interrupt flag is overwritten to 1.
<br>
Note: This bit is cleared by writing 1 to it.
<br>
</div></td></tr><tr><td>
[9]</td><td>ADOVIF1</td><td><div style="word-wrap: break-word;"><b>A/D ADINT1 Interrupt Flag Overrun
</b><br>
0 = ADINT1 interrupt flag is not overwritten to 1.
<br>
1 = ADINT1 interrupt flag is overwritten to 1.
<br>
Note: This bit is cleared by writing 1 to it.
<br>
</div></td></tr><tr><td>
[10]</td><td>ADOVIF2</td><td><div style="word-wrap: break-word;"><b>A/D ADINT2 Interrupt Flag Overrun
</b><br>
0 = ADINT2 interrupt flag is not overwritten to 1.
<br>
1 = ADINT2 interrupt flag is overwritten to 1.
<br>
Note: This bit is cleared by writing 1 to it.
<br>
</div></td></tr><tr><td>
[11]</td><td>ADOVIF3</td><td><div style="word-wrap: break-word;"><b>A/D ADINT3 Interrupt Flag Overrun
</b><br>
0 = ADINT3 interrupt flag is not overwritten to 1.
<br>
1 = ADINT3 interrupt flag is overwritten to 1.
<br>
Note: This bit is cleared by writing 1 to it.
<br>
</div></td></tr><tr><td>
[12]</td><td>ADCMPO0</td><td><div style="word-wrap: break-word;"><b>ADC Compare 0 Output Status
</b><br>
The 12 bits compare0 data CMPDAT0 (EADC_CMP0[27:16]) is used to compare with conversion result of specified sample module
<br>
User can use it to monitor the external analog input pin voltage status.
<br>
0 = Conversion result in EADC_DAT less than CMPDAT0 setting.
<br>
1 = Conversion result in EADC_DAT great than or equal CMPDAT0 setting.
<br>
</div></td></tr><tr><td>
[13]</td><td>ADCMPO1</td><td><div style="word-wrap: break-word;"><b>ADC Compare 1 Output Status
</b><br>
The 12 bits compare1 data CMPDAT1 (EADC_CMP1[27:16]) is used to compare with conversion result of specified sample module
<br>
User can use it to monitor the external analog input pin voltage status.
<br>
0 = Conversion result in EADC_DAT less than CMPDAT1 setting.
<br>
1 = Conversion result in EADC_DAT great than or equal CMPDAT1 setting.
<br>
</div></td></tr><tr><td>
[14]</td><td>ADCMPO2</td><td><div style="word-wrap: break-word;"><b>ADC Compare 2 Output Status
</b><br>
The 12 bits compare2 data CMPDAT2 (EADC_CMP2[27:16]) is used to compare with conversion result of specified sample module
<br>
User can use it to monitor the external analog input pin voltage status.
<br>
0 = Conversion result in EADC_DAT less than CMPDAT2 setting.
<br>
1 = Conversion result in EADC_DAT great than or equal CMPDAT2 setting.
<br>
</div></td></tr><tr><td>
[15]</td><td>ADCMPO3</td><td><div style="word-wrap: break-word;"><b>ADC Compare 3 Output Status
</b><br>
The 12 bits compare3 data CMPDAT3 (EADC_CMP3[27:16]) is used to compare with conversion result of specified sample module
<br>
User can use it to monitor the external analog input pin voltage status.
<br>
0 = Conversion result in EADC_DAT less than CMPDAT3 setting.
<br>
1 = Conversion result in EADC_DAT great than or equal CMPDAT3 setting.
<br>
</div></td></tr><tr><td>
[20:16]</td><td>CHANNEL</td><td><div style="word-wrap: break-word;"><b>Current Conversion Channel
</b><br>
This filed reflects ADC current conversion channel when BUSY=1.
<br>
It is read only.
<br>
00H = EADC_CH0.
<br>
01H = EADC_CH1.
<br>
02H = EADC_CH2.
<br>
03H = EADC_CH3.
<br>
04H = EADC_CH4.
<br>
05H = EADC_CH5.
<br>
06H = EADC_CH6.
<br>
07H = EADC_CH7.
<br>
08H = Reserved.
<br>
09H = Reserved.
<br>
0AH = Reserved.
<br>
0BH = Reserved.
<br>
0CH = EADC_CH12.
<br>
0DH = EADC_CH13.
<br>
0EH = EADC_CH14.
<br>
0FH = EADC_CH15.
<br>
10H = VBG.
<br>
11H = VTEMP.
<br>
Note: These bit are read only.
<br>
</div></td></tr><tr><td>
[23]</td><td>BUSY</td><td><div style="word-wrap: break-word;"><b>A/D Conveter Busy/Idle Status
</b><br>
0 = EADC is in idle state.
<br>
1 = EADC is busy for sample or conversion.
<br>
Note: This bit is read only
<br>
Once trigger source is coming, it must wait 2 ADC_CLK synchronization then the BUSY status will be high
<br>
This status will be high to low when the current conversion done.
<br>
</div></td></tr><tr><td>
[24]</td><td>ADOVIF</td><td><div style="word-wrap: break-word;"><b>All A/D Interrupt Flag Overrun Bits Check
</b><br>
n=0~3.
<br>
0 = None of ADINT interrupt flag ADOVIFn (EADC_STATUS2[11:8]) is overwritten to 1.
<br>
1 = Any one of ADINT interrupt flag ADOVIFn (EADC_STATUS2[11:8]) is overwritten to 1.
<br>
Note: This bit will keep 1 when any ADOVIFn Flag is equal to 1.
<br>
</div></td></tr><tr><td>
[25]</td><td>STOVF</td><td><div style="word-wrap: break-word;"><b>for All A/D Sample Module Start of Conversion Overrun Flags Check
</b><br>
n=0~18.
<br>
0 = None of sample module event overrun flag SPOVFn (EADC_OVSTS[n]) is set to 1.
<br>
1 = Any one of sample module event overrun flag SPOVFn (EADC_OVSTS[n]) is set to 1.
<br>
Note: This bit will keep 1 when any SPOVFn Flag is equal to 1.
<br>
</div></td></tr><tr><td>
[26]</td><td>AVALID</td><td><div style="word-wrap: break-word;"><b>for All Sample Module A/D Result Data Register EADC_DAT Data Valid Flag Check
</b><br>
n=0~18.
<br>
0 = None of sample module data register valid flag VALIDn (EADC_DATn[17]) is set to 1.
<br>
1 = Any one of sample module data register valid flag VALIDn (EADC_DATn[17]) is set to 1.
<br>
Note: This bit will keep 1 when any VALIDn Flag is equal to 1.
<br>
</div></td></tr><tr><td>
[27]</td><td>AOV</td><td><div style="word-wrap: break-word;"><b>for All Sample Module A/D Result Data Register Overrun Flags Check
</b><br>
n=0~18.
<br>
0 = None of sample module data register overrun flag OVn (EADC_DATn[16]) is set to 1.
<br>
1 = Any one of sample module data register overrun flag OVn (EADC_DATn[16]) is set to 1.
<br>
Note: This bit will keep 1 when any OVn Flag is equal to 1.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::STATUS3

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">STATUS3
</font><br><p> <font size="2">
Offset: 0xFC  A/D Status Register 3
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[4:0]</td><td>CURSPL</td><td><div style="word-wrap: break-word;"><b>ADC Current Sample Module
</b><br>
This register show the current ADC is controlled by which sample module control logic modules.
<br>
If the ADC is Idle, this bit filed will set to 0x1F.
<br>
Note: This is a read only register.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::PWRCTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">PWRCTL
</font><br><p> <font size="2">
Offset: 0x110  ADC Power Management Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>READY</td><td><div style="word-wrap: break-word;"><b>ADC Start-up Completely and Ready for Conversion (Read Only)
</b><br>
0 = Power-on sequence is still in progress.
<br>
1 = ADC is ready for conversion.
<br>
</div></td></tr><tr><td>
[5]</td><td>AUTOFF</td><td><div style="word-wrap: break-word;"><b>Auto Off Mode
</b><br>
0 = Function of auto off disabled.
<br>
1 = Function of auto off enabled
<br>
When AUTOFF is set to 1, ADC will be power off automatically to save power
<br>
</div></td></tr><tr><td>
[19:8]</td><td>STUPT</td><td><div style="word-wrap: break-word;"><b>ADC Start-up Time
</b><br>
Set this bit fields to adjust start-up time. The minimum start-up time of ADC is 10us.
<br>
ADC start-up time = (1/ADC_CLK) x STUPT.
<br>
</div></td></tr><tr><td>
[23:20]</td><td>AUTOPDTHT</td><td><div style="word-wrap: break-word;"><b>Auto Power Down Threshold Time
</b><br>
Auto Power Down Threshold Time = (1/ADC_CLK) x AUTOPDTHT.
<br>
0111 = 8 ADC clock for power down threshold time.
<br>
1000 = 16 ADC clock for power down threshold time.
<br>
1001 = 32 ADC clock for power down threshold time.
<br>
1010 = 64 ADC clock for power down threshold time.
<br>
1011 = 128 ADC clock for power down threshold time.
<br>
1100 = 256 ADC clock for power down threshold time.
<br>
Others = 256 ADC clock for power down threshold time.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::PDMACTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">PDMACTL
</font><br><p> <font size="2">
Offset: 0x130  ADC PDMA Control Rgister
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[18:0]</td><td>PDMATEN</td><td><div style="word-wrap: break-word;"><b>PDMA Transfer Enable Bit
</b><br>
When ADC conversion is completed, the converted data is loaded into EADC_DATn (n: 0 ~ 3, 16, 17) register, user can enable this bit to generate a PDMA data transfer request.
<br>
0 = PDMA data transfer Disabled.
<br>
1 = PDMA data transfer Enabled.
<br>
Note: When set this bit field to 1, user must set ADCIENn (EADC_CTL[5:2], n=0~3) = 0 to disable interrupt.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var EADC_T::MCTL1[16]

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">MCTL1[16]
</font><br><p> <font size="2">
Offset: 0x140~0x17C  A/D Sample Module 0~15 Control Register 1
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>ALIGN</td><td><div style="word-wrap: break-word;"><b>Alignment Selection
</b><br>
0 = The conversion result will be right aligned in data register.
<br>
1 = The conversion result will be left aligned in data register.
<br>
</div></td></tr><tr><td>
[1]</td><td>AVG</td><td><div style="word-wrap: break-word;"><b>Average Mode Selection
</b><br>
0 = Conversion results will be stored in data register without averaging.
<br>
1 = Conversion results in data register will be averaged.
<br>
This bit needs to work with ACU (EADC_MnCTL1[7:4], n=0~15).
<br>
</div></td></tr><tr><td>
[7:4]</td><td>ACU</td><td><div style="word-wrap: break-word;"><b>Number of Accumulated Conversion Results Selection
</b><br>
0H = 1 conversion result will be accumulated.
<br>
1H = 2 conversion result will be accumulated.
<br>
2H = 4 conversion result will be accumulated.
<br>
3H = 8 conversion result will be accumulated.
<br>
4H = 16 conversion result will be accumulated.
<br>
5H = 32 conversion result will be accumulated.
<br>
6H = 64 conversion result will be accumulated.
<br>
7H = 128 conversion result will be accumulated.
<br>
8H = 256 conversion result will be accumulated.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly



 */
    __I  uint32_t DAT[19];               /*!< [0x0000~0x0048] A/D Data Register n for Sample Module n,  n=0~3, 16,17    */
    __I  uint32_t CURDAT;                /*!< [0x004c] EADC PDMA Current Transfer Data Register                         */
    __IO uint32_t CTL;                   /*!< [0x0050] A/D Control Register                                             */
    __O  uint32_t SWTRG;                 /*!< [0x0054] A/D Sample Module Software Start Register                        */
    __IO uint32_t PENDSTS;               /*!< [0x0058] A/D Start of Conversion Pending Flag Register                    */
    __IO uint32_t OVSTS;                 /*!< [0x005c] A/D Sample Module Start of Conversion Overrun Flag Register      */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[8];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t SCTL[16];              /*!< [0x0080~0x00bc] A/D Sample Module n Control Register n=0~3                */
    __IO uint32_t SCTL0[3];              /*!< [0x00c0~0x00c8] A/D Sample Module n Control Register n=16~17              */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE1[1];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t INTSRC[4];             /*!< [0x00d0~0x00dc] ADC Interrupt n Source Enable Control Register. n=0~3     */
    __IO uint32_t CMP[4];                /*!< [0x00e0~0x00ec] A/D Result Compare Register n, n=0~3                      */
    __I  uint32_t STATUS0;               /*!< [0x00f0] A/D Status Register 0                                            */
    __I  uint32_t STATUS1;               /*!< [0x00f4] A/D Status Register 1                                            */
    __IO uint32_t STATUS2;               /*!< [0x00f8] A/D Status Register 2                                            */
    __I  uint32_t STATUS3;               /*!< [0x00fc] A/D Status Register 3                                            */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE2[4];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t PWRCTL;                /*!< [0x0110] ADC Power Management Control Register                            */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE3[7];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t PDMACTL;               /*!< [0x0130] ADC PDMA Control Rgister                                         */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE4[3];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t MCTL1[16];             /*!< [0x0140~0x017c] A/D Sample Module n Control Register 1, n=0~3             */
} EADC_T;

/**
    @addtogroup EADC_CONST EADC Bit Field Definition
    Constant Definitions for EADC Controller
@{ */

#define EADC_DAT_RESULT_Pos              (0)                                               /*!< EADC_T::DATn: RESULT Position          */
#define EADC_DAT_RESULT_Msk              (0xfffful << EADC_DAT_RESULT_Pos)                 /*!< EADC_T::DATn: RESULT Mask              */

#define EADC_DAT_OV_Pos                  (16)                                              /*!< EADC_T::DATn: OV Position              */
#define EADC_DAT_OV_Msk                  (0x1ul << EADC_DAT_OV_Pos)                        /*!< EADC_T::DATn: OV Mask                  */

#define EADC_DAT_VALID_Pos               (17)                                              /*!< EADC_T::DATn: VALID Position           */
#define EADC_DAT_VALID_Msk               (0x1ul << EADC_DAT_VALID_Pos)                     /*!< EADC_T::DATn: VALID Mask               */

#define EADC_CURDAT_CURDAT_Pos           (0)                                               /*!< EADC_T::CURDAT: CURDAT Position        */
#define EADC_CURDAT_CURDAT_Msk           (0x3fffful << EADC_CURDAT_CURDAT_Pos)             /*!< EADC_T::CURDAT: CURDAT Mask            */

#define EADC_CTL_ADCEN_Pos               (0)                                               /*!< EADC_T::CTL: ADCEN Position            */
#define EADC_CTL_ADCEN_Msk               (0x1ul << EADC_CTL_ADCEN_Pos)                     /*!< EADC_T::CTL: ADCEN Mask                */

#define EADC_CTL_ADCRST_Pos              (1)                                               /*!< EADC_T::CTL: ADCRST Position           */
#define EADC_CTL_ADCRST_Msk              (0x1ul << EADC_CTL_ADCRST_Pos)                    /*!< EADC_T::CTL: ADCRST Mask               */

#define EADC_CTL_ADCIEN0_Pos             (2)                                               /*!< EADC_T::CTL: ADCIEN0 Position          */
#define EADC_CTL_ADCIEN0_Msk             (0x1ul << EADC_CTL_ADCIEN0_Pos)                   /*!< EADC_T::CTL: ADCIEN0 Mask              */

#define EADC_CTL_ADCIEN1_Pos             (3)                                               /*!< EADC_T::CTL: ADCIEN1 Position          */
#define EADC_CTL_ADCIEN1_Msk             (0x1ul << EADC_CTL_ADCIEN1_Pos)                   /*!< EADC_T::CTL: ADCIEN1 Mask              */

#define EADC_CTL_ADCIEN2_Pos             (4)                                               /*!< EADC_T::CTL: ADCIEN2 Position          */
#define EADC_CTL_ADCIEN2_Msk             (0x1ul << EADC_CTL_ADCIEN2_Pos)                   /*!< EADC_T::CTL: ADCIEN2 Mask              */

#define EADC_CTL_ADCIEN3_Pos             (5)                                               /*!< EADC_T::CTL: ADCIEN3 Position          */
#define EADC_CTL_ADCIEN3_Msk             (0x1ul << EADC_CTL_ADCIEN3_Pos)                   /*!< EADC_T::CTL: ADCIEN3 Mask              */

#define EADC_SWTRG_SWTRG_Pos             (0)                                               /*!< EADC_T::SWTRG: SWTRG Position          */
#define EADC_SWTRG_SWTRG_Msk             (0x7fffful << EADC_SWTRG_SWTRG_Pos)               /*!< EADC_T::SWTRG: SWTRG Mask              */

#define EADC_PENDSTS_STPF_Pos            (0)                                               /*!< EADC_T::PENDSTS: STPF Position         */
#define EADC_PENDSTS_STPF_Msk            (0x7fffful << EADC_PENDSTS_STPF_Pos)              /*!< EADC_T::PENDSTS: STPF Mask             */

#define EADC_OVSTS_SPOVF_Pos             (0)                                               /*!< EADC_T::OVSTS: SPOVF Position          */
#define EADC_OVSTS_SPOVF_Msk             (0x7fffful << EADC_OVSTS_SPOVF_Pos)               /*!< EADC_T::OVSTS: SPOVF Mask              */

#define EADC_SCTL_CHSEL_Pos              (0)                                               /*!< EADC_T::SCTLn: CHSEL Position          */
#define EADC_SCTL_CHSEL_Msk              (0xful << EADC_SCTL_CHSEL_Pos)                    /*!< EADC_T::SCTLn: CHSEL Mask              */

#define EADC_SCTL_EXTREN_Pos             (4)                                               /*!< EADC_T::SCTLn: EXTREN Position         */
#define EADC_SCTL_EXTREN_Msk             (0x1ul << EADC_SCTL_EXTREN_Pos)                   /*!< EADC_T::SCTLn: EXTREN Mask             */

#define EADC_SCTL_EXTFEN_Pos             (5)                                               /*!< EADC_T::SCTLn: EXTFEN Position         */
#define EADC_SCTL_EXTFEN_Msk             (0x1ul << EADC_SCTL_EXTFEN_Pos)                   /*!< EADC_T::SCTLn: EXTFEN Mask             */

#define EADC_SCTL_TRGDLYDIV_Pos          (6)                                               /*!< EADC_T::SCTLn: TRGDLYDIV Position      */
#define EADC_SCTL_TRGDLYDIV_Msk          (0x3ul << EADC_SCTL_TRGDLYDIV_Pos)                /*!< EADC_T::SCTLn: TRGDLYDIV Mask          */

#define EADC_SCTL_TRGDLYCNT_Pos          (8)                                               /*!< EADC_T::SCTLn: TRGDLYCNT Position      */
#define EADC_SCTL_TRGDLYCNT_Msk          (0xfful << EADC_SCTL_TRGDLYCNT_Pos)               /*!< EADC_T::SCTLn: TRGDLYCNT Mask          */

#define EADC_SCTL_TRGSEL_Pos             (16)                                              /*!< EADC_T::SCTLn: TRGSEL Position         */
#define EADC_SCTL_TRGSEL_Msk             (0x1ful << EADC_SCTL_TRGSEL_Pos)                  /*!< EADC_T::SCTLn: TRGSEL Mask             */

#define EADC_SCTL_INTPOS_Pos             (22)                                              /*!< EADC_T::SCTLn: INTPOS Position         */
#define EADC_SCTL_INTPOS_Msk             (0x1ul << EADC_SCTL_INTPOS_Pos)                   /*!< EADC_T::SCTLn: INTPOS Mask             */

#define EADC_SCTL_EXTSMPT_Pos            (24)                                              /*!< EADC_T::SCTLn: EXTSMPT Position        */
#define EADC_SCTL_EXTSMPT_Msk            (0xfful << EADC_SCTL_EXTSMPT_Pos)                 /*!< EADC_T::SCTLn: EXTSMPT Mask            */

#define EADC_SCTL0_EXTSMPT_Pos           (24)                                              /*!< EADC_T::SCTL0n: EXTSMPT Position       */
#define EADC_SCTL0_EXTSMPT_Msk           (0xfful << EADC_SCTL0_EXTSMPT_Pos)                /*!< EADC_T::SCTL0n: EXTSMPT Mask           */

#define EADC_INTSRC_SPLIE0_Pos           (0)                                               /*!< EADC_T::INTSRCn: SPLIE0 Position       */
#define EADC_INTSRC_SPLIE0_Msk           (0x1ul << EADC_INTSRC_SPLIE0_Pos)                 /*!< EADC_T::INTSRCn: SPLIE0 Mask           */

#define EADC_INTSRC_SPLIE1_Pos           (1)                                               /*!< EADC_T::INTSRCn: SPLIE1 Position       */
#define EADC_INTSRC_SPLIE1_Msk           (0x1ul << EADC_INTSRC_SPLIE1_Pos)                 /*!< EADC_T::INTSRCn: SPLIE1 Mask           */

#define EADC_INTSRC_SPLIE2_Pos           (2)                                               /*!< EADC_T::INTSRCn: SPLIE2 Position       */
#define EADC_INTSRC_SPLIE2_Msk           (0x1ul << EADC_INTSRC_SPLIE2_Pos)                 /*!< EADC_T::INTSRCn: SPLIE2 Mask           */

#define EADC_INTSRC_SPLIE3_Pos           (3)                                               /*!< EADC_T::INTSRCn: SPLIE3 Position       */
#define EADC_INTSRC_SPLIE3_Msk           (0x1ul << EADC_INTSRC_SPLIE3_Pos)                 /*!< EADC_T::INTSRCn: SPLIE3 Mask           */

#define EADC_INTSRC_SPLIE16_Pos          (16)                                              /*!< EADC_T::INTSRCn: SPLIE16 Position      */
#define EADC_INTSRC_SPLIE16_Msk          (0x1ul << EADC_INTSRC_SPLIE16_Pos)                /*!< EADC_T::INTSRCn: SPLIE16 Mask          */

#define EADC_INTSRC_SPLIE17_Pos          (17)                                              /*!< EADC_T::INTSRCn: SPLIE17 Position      */
#define EADC_INTSRC_SPLIE17_Msk          (0x1ul << EADC_INTSRC_SPLIE17_Pos)                /*!< EADC_T::INTSRCn: SPLIE17 Mask          */

#define EADC_CMP_ADCMPEN_Pos             (0)                                               /*!< EADC_T::CMPn: ADCMPEN Position         */
#define EADC_CMP_ADCMPEN_Msk             (0x1ul << EADC_CMP_ADCMPEN_Pos)                   /*!< EADC_T::CMPn: ADCMPEN Mask             */

#define EADC_CMP_ADCMPIE_Pos             (1)                                               /*!< EADC_T::CMPn: ADCMPIE Position         */
#define EADC_CMP_ADCMPIE_Msk             (0x1ul << EADC_CMP_ADCMPIE_Pos)                   /*!< EADC_T::CMPn: ADCMPIE Mask             */

#define EADC_CMP_CMPCOND_Pos             (2)                                               /*!< EADC_T::CMPn: CMPCOND Position         */
#define EADC_CMP_CMPCOND_Msk             (0x1ul << EADC_CMP_CMPCOND_Pos)                   /*!< EADC_T::CMPn: CMPCOND Mask             */

#define EADC_CMP_CMPSPL_Pos              (3)                                               /*!< EADC_T::CMPn: CMPSPL Position          */
#define EADC_CMP_CMPSPL_Msk              (0x1ful << EADC_CMP_CMPSPL_Pos)                   /*!< EADC_T::CMPn: CMPSPL Mask              */

#define EADC_CMP_CMPMCNT_Pos             (8)                                               /*!< EADC_T::CMPn: CMPMCNT Position         */
#define EADC_CMP_CMPMCNT_Msk             (0xful << EADC_CMP_CMPMCNT_Pos)                   /*!< EADC_T::CMPn: CMPMCNT Mask             */

#define EADC_CMP_CMPWEN_Pos              (15)                                              /*!< EADC_T::CMPn: CMPWEN Position          */
#define EADC_CMP_CMPWEN_Msk              (0x1ul << EADC_CMP_CMPWEN_Pos)                    /*!< EADC_T::CMPn: CMPWEN Mask              */

#define EADC_CMP_CMPDAT_Pos              (16)                                              /*!< EADC_T::CMPn: CMPDAT Position          */
#define EADC_CMP_CMPDAT_Msk              (0xffful << EADC_CMP_CMPDAT_Pos)                  /*!< EADC_T::CMPn: CMPDAT Mask              */

#define EADC_STATUS0_VALID_Pos           (0)                                               /*!< EADC_T::STATUS0: VALID Position        */
#define EADC_STATUS0_VALID_Msk           (0xfffful << EADC_STATUS0_VALID_Pos)              /*!< EADC_T::STATUS0: VALID Mask            */

#define EADC_STATUS0_OV_Pos              (16)                                              /*!< EADC_T::STATUS0: OV Position           */
#define EADC_STATUS0_OV_Msk              (0xfffful << EADC_STATUS0_OV_Pos)                 /*!< EADC_T::STATUS0: OV Mask               */

#define EADC_STATUS1_VALID_Pos           (0)                                               /*!< EADC_T::STATUS1: VALID Position        */
#define EADC_STATUS1_VALID_Msk           (0x7ul << EADC_STATUS1_VALID_Pos)                 /*!< EADC_T::STATUS1: VALID Mask            */

#define EADC_STATUS1_OV_Pos              (16)                                              /*!< EADC_T::STATUS1: OV Position           */
#define EADC_STATUS1_OV_Msk              (0x7ul << EADC_STATUS1_OV_Pos)                    /*!< EADC_T::STATUS1: OV Mask               */

#define EADC_STATUS2_ADIF0_Pos           (0)                                               /*!< EADC_T::STATUS2: ADIF0 Position        */
#define EADC_STATUS2_ADIF0_Msk           (0x1ul << EADC_STATUS2_ADIF0_Pos)                 /*!< EADC_T::STATUS2: ADIF0 Mask            */

#define EADC_STATUS2_ADIF1_Pos           (1)                                               /*!< EADC_T::STATUS2: ADIF1 Position        */
#define EADC_STATUS2_ADIF1_Msk           (0x1ul << EADC_STATUS2_ADIF1_Pos)                 /*!< EADC_T::STATUS2: ADIF1 Mask            */

#define EADC_STATUS2_ADIF2_Pos           (2)                                               /*!< EADC_T::STATUS2: ADIF2 Position        */
#define EADC_STATUS2_ADIF2_Msk           (0x1ul << EADC_STATUS2_ADIF2_Pos)                 /*!< EADC_T::STATUS2: ADIF2 Mask            */

#define EADC_STATUS2_ADIF3_Pos           (3)                                               /*!< EADC_T::STATUS2: ADIF3 Position        */
#define EADC_STATUS2_ADIF3_Msk           (0x1ul << EADC_STATUS2_ADIF3_Pos)                 /*!< EADC_T::STATUS2: ADIF3 Mask            */

#define EADC_STATUS2_ADCMPF0_Pos         (4)                                               /*!< EADC_T::STATUS2: ADCMPF0 Position      */
#define EADC_STATUS2_ADCMPF0_Msk         (0x1ul << EADC_STATUS2_ADCMPF0_Pos)               /*!< EADC_T::STATUS2: ADCMPF0 Mask          */

#define EADC_STATUS2_ADCMPF1_Pos         (5)                                               /*!< EADC_T::STATUS2: ADCMPF1 Position      */
#define EADC_STATUS2_ADCMPF1_Msk         (0x1ul << EADC_STATUS2_ADCMPF1_Pos)               /*!< EADC_T::STATUS2: ADCMPF1 Mask          */

#define EADC_STATUS2_ADCMPF2_Pos         (6)                                               /*!< EADC_T::STATUS2: ADCMPF2 Position      */
#define EADC_STATUS2_ADCMPF2_Msk         (0x1ul << EADC_STATUS2_ADCMPF2_Pos)               /*!< EADC_T::STATUS2: ADCMPF2 Mask          */

#define EADC_STATUS2_ADCMPF3_Pos         (7)                                               /*!< EADC_T::STATUS2: ADCMPF3 Position      */
#define EADC_STATUS2_ADCMPF3_Msk         (0x1ul << EADC_STATUS2_ADCMPF3_Pos)               /*!< EADC_T::STATUS2: ADCMPF3 Mask          */

#define EADC_STATUS2_ADOVIF0_Pos         (8)                                               /*!< EADC_T::STATUS2: ADOVIF0 Position      */
#define EADC_STATUS2_ADOVIF0_Msk         (0x1ul << EADC_STATUS2_ADOVIF0_Pos)               /*!< EADC_T::STATUS2: ADOVIF0 Mask          */

#define EADC_STATUS2_ADOVIF1_Pos         (9)                                               /*!< EADC_T::STATUS2: ADOVIF1 Position      */
#define EADC_STATUS2_ADOVIF1_Msk         (0x1ul << EADC_STATUS2_ADOVIF1_Pos)               /*!< EADC_T::STATUS2: ADOVIF1 Mask          */

#define EADC_STATUS2_ADOVIF2_Pos         (10)                                              /*!< EADC_T::STATUS2: ADOVIF2 Position      */
#define EADC_STATUS2_ADOVIF2_Msk         (0x1ul << EADC_STATUS2_ADOVIF2_Pos)               /*!< EADC_T::STATUS2: ADOVIF2 Mask          */

#define EADC_STATUS2_ADOVIF3_Pos         (11)                                              /*!< EADC_T::STATUS2: ADOVIF3 Position      */
#define EADC_STATUS2_ADOVIF3_Msk         (0x1ul << EADC_STATUS2_ADOVIF3_Pos)               /*!< EADC_T::STATUS2: ADOVIF3 Mask          */

#define EADC_STATUS2_ADCMPO0_Pos         (12)                                              /*!< EADC_T::STATUS2: ADCMPO0 Position      */
#define EADC_STATUS2_ADCMPO0_Msk         (0x1ul << EADC_STATUS2_ADCMPO0_Pos)               /*!< EADC_T::STATUS2: ADCMPO0 Mask          */

#define EADC_STATUS2_ADCMPO1_Pos         (13)                                              /*!< EADC_T::STATUS2: ADCMPO1 Position      */
#define EADC_STATUS2_ADCMPO1_Msk         (0x1ul << EADC_STATUS2_ADCMPO1_Pos)               /*!< EADC_T::STATUS2: ADCMPO1 Mask          */

#define EADC_STATUS2_ADCMPO2_Pos         (14)                                              /*!< EADC_T::STATUS2: ADCMPO2 Position      */
#define EADC_STATUS2_ADCMPO2_Msk         (0x1ul << EADC_STATUS2_ADCMPO2_Pos)               /*!< EADC_T::STATUS2: ADCMPO2 Mask          */

#define EADC_STATUS2_ADCMPO3_Pos         (15)                                              /*!< EADC_T::STATUS2: ADCMPO3 Position      */
#define EADC_STATUS2_ADCMPO3_Msk         (0x1ul << EADC_STATUS2_ADCMPO3_Pos)               /*!< EADC_T::STATUS2: ADCMPO3 Mask          */

#define EADC_STATUS2_CHANNEL_Pos         (16)                                              /*!< EADC_T::STATUS2: CHANNEL Position      */
#define EADC_STATUS2_CHANNEL_Msk         (0x1ful << EADC_STATUS2_CHANNEL_Pos)              /*!< EADC_T::STATUS2: CHANNEL Mask          */

#define EADC_STATUS2_BUSY_Pos            (23)                                              /*!< EADC_T::STATUS2: BUSY Position         */
#define EADC_STATUS2_BUSY_Msk            (0x1ul << EADC_STATUS2_BUSY_Pos)                  /*!< EADC_T::STATUS2: BUSY Mask             */

#define EADC_STATUS2_ADOVIF_Pos          (24)                                              /*!< EADC_T::STATUS2: ADOVIF Position       */
#define EADC_STATUS2_ADOVIF_Msk          (0x1ul << EADC_STATUS2_ADOVIF_Pos)                /*!< EADC_T::STATUS2: ADOVIF Mask           */

#define EADC_STATUS2_STOVF_Pos           (25)                                              /*!< EADC_T::STATUS2: STOVF Position        */
#define EADC_STATUS2_STOVF_Msk           (0x1ul << EADC_STATUS2_STOVF_Pos)                 /*!< EADC_T::STATUS2: STOVF Mask            */

#define EADC_STATUS2_AVALID_Pos          (26)                                              /*!< EADC_T::STATUS2: AVALID Position       */
#define EADC_STATUS2_AVALID_Msk          (0x1ul << EADC_STATUS2_AVALID_Pos)                /*!< EADC_T::STATUS2: AVALID Mask           */

#define EADC_STATUS2_AOV_Pos             (27)                                              /*!< EADC_T::STATUS2: AOV Position          */
#define EADC_STATUS2_AOV_Msk             (0x1ul << EADC_STATUS2_AOV_Pos)                   /*!< EADC_T::STATUS2: AOV Mask              */

#define EADC_STATUS3_CURSPL_Pos          (0)                                               /*!< EADC_T::STATUS3: CURSPL Position       */
#define EADC_STATUS3_CURSPL_Msk          (0x1ful << EADC_STATUS3_CURSPL_Pos)               /*!< EADC_T::STATUS3: CURSPL Mask           */

#define EADC_MCTL1_ALIGN_Pos             (0)                                               /*!< EADC_T::MnCTL1: ALIGN Position         */
#define EADC_MCTL1_ALIGN_Msk             (0x1ul << EADC_MCTL1_ALIGN_Pos)                   /*!< EADC_T::MnCTL1: ALIGN Mask             */

#define EADC_MCTL1_AVG_Pos               (1)                                               /*!< EADC_T::MnCTL1: AVG Position           */
#define EADC_MCTL1_AVG_Msk               (0x1ul << EADC_MCTL1_AVG_Pos)                     /*!< EADC_T::MnCTL1: AVG Mask               */

#define EADC_MCTL1_ACU_Pos               (4)                                               /*!< EADC_T::MnCTL1: ACU Position           */
#define EADC_MCTL1_ACU_Msk               (0xful << EADC_MCTL1_ACU_Pos)                     /*!< EADC_T::MnCTL1: ACU Mask               */

#define EADC_PWRCTL_READY_Pos            (0)                                               /*!< EADC_T::PWRCTL: READY Position         */
#define EADC_PWRCTL_READY_Msk            (0x1ul << EADC_PWRCTL_READY_Pos)                  /*!< EADC_T::PWRCTL: READY Mask             */

#define EADC_PWRCTL_AUTOFF_Pos           (5)                                               /*!< EADC_T::PWRCTL: AUTOFF Position        */
#define EADC_PWRCTL_AUTOFF_Msk           (0x1ul << EADC_PWRCTL_AUTOFF_Pos)                 /*!< EADC_T::PWRCTL: AUTOFF Mask            */

#define EADC_PWRCTL_STUPT_Pos            (8)                                               /*!< EADC_T::PWRCTL: STUPT Position         */
#define EADC_PWRCTL_STUPT_Msk            (0xffful << EADC_PWRCTL_STUPT_Pos)                /*!< EADC_T::PWRCTL: STUPT Mask             */

#define EADC_PWRCTL_AUTOPDTHT_Pos        (20)                                              /*!< EADC_T::PWRCTL: AUTOPDTHT Position     */
#define EADC_PWRCTL_AUTOPDTHT_Msk        (0xful << EADC_PWRCTL_AUTOPDTHT_Pos)              /*!< EADC_T::PWRCTL: AUTOPDTHT Mask         */

#define EADC_PDMACTL_PDMATEN_Pos         (0)                                               /*!< EADC_T::PDMACTL: PDMATEN Position      */
#define EADC_PDMACTL_PDMATEN_Msk         (0x7fffful << EADC_PDMACTL_PDMATEN_Pos)           /*!< EADC_T::PDMACTL: PDMATEN Mask          */

/** @} EADC_CONST */
/** @} end of EADC register group */
/** @} end of REGISTER group */

#if defined ( __CC_ARM   )
    #pragma no_anon_unions
#endif

#endif /* __EADC_REG_H__ */
