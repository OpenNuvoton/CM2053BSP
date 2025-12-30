/**************************************************************************//**
 * @file     i2c_reg.h
 * @version  V1.00
 * @brief    I2C register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __I2C_REG_H__
#define __I2C_REG_H__

#if defined ( __CC_ARM   )
    #pragma anon_unions
#endif

/**
    @addtogroup REGISTER Control Register
    @{
*/

/*---------------------- Inter-IC Bus Controller -------------------------*/
/**
    @addtogroup I2C Inter-IC Bus Controller (I2C)
    Memory Mapped Structure for I2C Controller
    @{
*/

typedef struct
{


    /**
@var I2C_T::CTL0

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CTL0
</font><br><p> <font size="2">
Offset: 0x00  I2C Control Register 0
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[2]</td><td>AA</td><td><div style="word-wrap: break-word;"><b>Assert Acknowledge Control
</b><br>
When AA =1 prior to address or data is received, an acknowledged (low level to SDA) will be returned during the acknowledge clock pulse on the SCL line when 1.) A slave is acknowledging the address sent from master, 2.) The receiver devices are acknowledging the data sent by transmitter
<br>
When AA=0 prior to address or data received, a Not acknowledged (high level to SDA) will be returned during the acknowledge clock pulse on the SCL line
<br>
</div></td></tr><tr><td>
[3]</td><td>SI</td><td><div style="word-wrap: break-word;"><b>I2C Interrupt Flag
</b><br>
When a new I2C state is present in the I2C_STATUS0 register, the SI flag is set by hardware
<br>
If bit INTEN (I2C_CTL0 [7]) is set, the I2C interrupt is requested
<br>
SI must be cleared by software.
<br>
Clear SI by writing 1 to this bit.
<br>
For ACKMEN is set in slave read mode, the SI flag is set in 8th clock period for user to confirm the acknowledge bit and 9th clock period for user to read the data in the data buffer.
<br>
</div></td></tr><tr><td>
[4]</td><td>STO</td><td><div style="word-wrap: break-word;"><b>I2C STOP Control
</b><br>
In Master mode, setting STO to transmit a STOP condition to bus then I2C controller will check the bus condition if a STOP condition is detected
<br>
This bit will be cleared by hardware automatically.
<br>
</div></td></tr><tr><td>
[5]</td><td>STA</td><td><div style="word-wrap: break-word;"><b>I2C START Control
</b><br>
Setting STA to logic 1 to enter Master mode, the I2C hardware sends a START or repeat START condition to bus when the bus is free.
<br>
</div></td></tr><tr><td>
[6]</td><td>I2CEN</td><td><div style="word-wrap: break-word;"><b>I2C Controller Enable Bit
</b><br>
Set to enable I2C serial function controller
<br>
When I2CEN=1 the I2C serial function enable
<br>
The multi-function pin function must set to SDA, and SCL of I2C function first.
<br>
0 = I2C controller Disabled.
<br>
1 = I2C controller Enabled.
<br>
</div></td></tr><tr><td>
[7]</td><td>INTEN</td><td><div style="word-wrap: break-word;"><b>Enable Interrupt
</b><br>
0 = I2C interrupt Disabled.
<br>
1 = I2C interrupt Enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var I2C_T::DAT

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">DAT
</font><br><p> <font size="2">
Offset: 0x08  I2C Data Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[7:0]</td><td>DAT</td><td><div style="word-wrap: break-word;"><b>I2C Data
</b><br>
Bit [7:0] is located with the 8-bit transferred/received data of I2C serial port.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var I2C_T::STATUS0

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">STATUS0
</font><br><p> <font size="2">
Offset: 0x0C  I2C Status Register 0
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[7:0]</td><td>STATUS</td><td><div style="word-wrap: break-word;"><b>I2C Status
</b><br>
The three least significant bits are always 0
<br>
The five most significant bits contain the status code
<br>
There are 28 possible status codes
<br>
When the content of I2C_STATUS0 is F8H, no serial interrupt is requested
<br>
Others I2C_STATUS0 values correspond to defined I2C states
<br>
When each of these states is entered, a status interrupt is requested (SI = 1)
<br>
A valid status code is present in I2C_STATUS0 one cycle after SI is set by hardware and is still present one cycle after SI has been reset by software
<br>
In addition, states 00H stands for a Bus Error
<br>
A Bus Error occurs when a START or STOP condition is present at an illegal position in the formation frame
<br>
Example of illegal position are during the serial transfer of an address byte, a data byte or an acknowledge bit.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var I2C_T::CLKDIV

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CLKDIV
</font><br><p> <font size="2">
Offset: 0x10  I2C Clock Divided Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[9:0]</td><td>DIVIDER</td><td><div style="word-wrap: break-word;"><b>I2C Clock Divided
</b><br>
Indicates the I2C clock rate: Data Baud Rate of I2C = (system clock) / (4x (I2C_CLKDIV+1)).
<br>
Note: The minimum value of I2C_CLKDIV is 4.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var I2C_T::TOCTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">TOCTL
</font><br><p> <font size="2">
Offset: 0x14  I2C Time-out Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>TOIF</td><td><div style="word-wrap: break-word;"><b>Time-out Flag
</b><br>
This bit is set by hardware when I2C time-out happened and it can interrupt CPU if I2C interrupt enable bit (INTEN) is set to 1.
<br>
Note: Software can write 1 to clear this bit.
<br>
</div></td></tr><tr><td>
[1]</td><td>TOCDIV4</td><td><div style="word-wrap: break-word;"><b>Time-out Counter Input Clock Divided by 4
</b><br>
When enabled, the time-out period is extended 4 times.
<br>
0 = Time-out period is extend 4 times Disabled.
<br>
1 = Time-out period is extend 4 times Enabled.
<br>
</div></td></tr><tr><td>
[2]</td><td>TOCEN</td><td><div style="word-wrap: break-word;"><b>Time-out Counter Enable Bit
</b><br>
When enabled, the 14-bit time-out counter will start counting when SI is cleared
<br>
Setting flag SI to '1' will reset counter and re-start up counting after SI is cleared.
<br>
0 = Time-out counter Disabled.
<br>
1 = Time-out counter Enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var I2C_T::ADDR0~3

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">ADDR0~3
</font><br><p> <font size="2">
Offset: 0x04/0x18/0x1x/0x20  I2C Slave Address0~3 Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>GC</td><td><div style="word-wrap: break-word;"><b>General Call Function
</b><br>
0 = General Call Function Disabled.
<br>
1 = General Call Function Enabled.
<br>
</div></td></tr><tr><td>
[10:1]</td><td>ADDR</td><td><div style="word-wrap: break-word;"><b>I2C Address
</b><br>
The content of this register is irrelevant when I2C is in Master mode
<br>
In the slave mode, the seven most significant bits must be loaded with the chip's own address
<br>
The I2C hardware will react if either of the address is matched.
<br>
Note: When software set 10'h000, the address can not be used.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var I2C_T::ADDRMSK0~3

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">ADDRMSK0~3
</font><br><p> <font size="2">
Offset: 0x24/0x28/0x2C/0x30  I2C Slave Address Mask0~3 Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[10:1]</td><td>ADDRMSK</td><td><div style="word-wrap: break-word;"><b>I2C Address Mask
</b><br>
0 = Mask Disabled (the received corresponding register bit should be exact the same as address register.).
<br>
1 = Mask Enabled (the received corresponding address bit is don't care.).
<br>
I2C bus controllers support multiple address recognition with four address mask register
<br>
When the bit in the address mask register is set to one, it means the received corresponding address bit is don't-care
<br>
If the bit is set to zero, that means the received corresponding register bit should be exact the same as address register.
<br>
Note: The wake-up function can not use address mask.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var I2C_T::WKCTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">WKCTL
</font><br><p> <font size="2">
Offset: 0x3C  I2C Wake-up Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>WKEN</td><td><div style="word-wrap: break-word;"><b>I2C Wake-up Enable Bit
</b><br>
0 = I2C wake-up function Disabled.
<br>
1 = I2C wake-up function Enabled.
<br>
</div></td></tr><tr><td>
[7]</td><td>NHDBUSEN</td><td><div style="word-wrap: break-word;"><b>I2C No Hold BUS Enable Bit
</b><br>
0 = I2C hold bus after wake-up.
<br>
1 = I2C don't hold bus after wake-up.
<br>
Note: I2C controller could response when WKIF event is not clear, it may cause error data transmitted or received
<br>
If data transmitted or received when WKIF event is not clear, user must reset I2C controller and execute the original operation again.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var I2C_T::WKSTS

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">WKSTS
</font><br><p> <font size="2">
Offset: 0x40  I2C Wake-up Status Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>WKIF</td><td><div style="word-wrap: break-word;"><b>I2C Wake-up Flag
</b><br>
When chip is woken up from Power-down mode by I2C, this bit is set to 1
<br>
Software can write 1 to clear this bit.
<br>
</div></td></tr><tr><td>
[1]</td><td>WKAKDONE</td><td><div style="word-wrap: break-word;"><b>Wakeup Address Frame Acknowledge Bit Done
</b><br>
0 = The ACK bit cycle of address match frame isn't done.
<br>
1 = The ACK bit cycle of address match frame is done in power-down.
<br>
Note: This bit can't release WKIF. Software can write 1 to clear this bit.
<br>
</div></td></tr><tr><td>
[2]</td><td>WRSTSWK</td><td><div style="word-wrap: break-word;"><b>Read/Write Status Bit in Address Wakeup Frame (Read Only)
</b><br>
0 = Write command be record on the address match wakeup frame.
<br>
1 = Read command be record on the address match wakeup frame.
<br>
Note: This bit will be cleared when software can write 1 to WKAKDONE (I2C_WKSTS[1]) bit.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var I2C_T::CTL1

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">CTL1
</font><br><p> <font size="2">
Offset: 0x44  I2C Control Register 1
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>TXPDMAEN</td><td><div style="word-wrap: break-word;"><b>PDMA Transmit Channel Available
</b><br>
0 = Transmit PDMA function Disabled.
<br>
1 = Transmit PDMA function Enabled.
<br>
</div></td></tr><tr><td>
[1]</td><td>RXPDMAEN</td><td><div style="word-wrap: break-word;"><b>PDMA Receive Channel Available
</b><br>
0 = Receive PDMA function Disabled.
<br>
1 = Receive PDMA function Enabled.
<br>
</div></td></tr><tr><td>
[2]</td><td>PDMARST</td><td><div style="word-wrap: break-word;"><b>PDMA Reset
</b><br>
0 = No effect.
<br>
1 = Reset the I2C request to PDMA.
<br>
</div></td></tr><tr><td>
[8]</td><td>PDMASTR</td><td><div style="word-wrap: break-word;"><b>PDMA Stretch Bit
</b><br>
0 = I2C send STOP automatically after PDMA transfer done. (only master TX)
<br>
1 = I2C SCL bus is stretched by hardware after PDMA transfer done if the SI is not cleared
<br>
(only master TX)
<br>
</div></td></tr><tr><td>
[9]</td><td>ADDR10EN</td><td><div style="word-wrap: break-word;"><b>Address 10-bit Function Enable Bit
</b><br>
0 = Address match 10-bit function Disabled.
<br>
1 = Address match 10-bit function Enabled.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var I2C_T::STATUS1

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">STATUS1
</font><br><p> <font size="2">
Offset: 0x48  I2C Status Register 1
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[0]</td><td>ADMAT0</td><td><div style="word-wrap: break-word;"><b>I2C Address 0 Match Status
</b><br>
When address 0 is matched, hardware will inform which address used
<br>
This bit will set to 1, and software can write 1 to clear this bit.
<br>
</div></td></tr><tr><td>
[1]</td><td>ADMAT1</td><td><div style="word-wrap: break-word;"><b>I2C Address 1 Match Status
</b><br>
When address 1 is matched, hardware will inform which address used
<br>
This bit will set to 1, and software can write 1 to clear this bit.
<br>
</div></td></tr><tr><td>
[2]</td><td>ADMAT2</td><td><div style="word-wrap: break-word;"><b>I2C Address 2 Match Status
</b><br>
When address 2 is matched, hardware will inform which address used
<br>
This bit will set to 1, and software can write 1 to clear this bit.
<br>
</div></td></tr><tr><td>
[3]</td><td>ADMAT3</td><td><div style="word-wrap: break-word;"><b>I2C Address 3 Match Status
</b><br>
When address 3 is matched, hardware will inform which address used
<br>
This bit will set to 1, and software can write 1 to clear this bit.
<br>
</div></td></tr><tr><td>
[8]</td><td>ONBUSY</td><td><div style="word-wrap: break-word;"><b>On Bus Busy (Read Only)
</b><br>
Indicates that a communication is in progress on the bus
<br>
It is set by hardware when a START condition is detected
<br>
It is cleared by hardware when a STOP condition is detected.
<br>
0 = The bus is IDLE (both SCLK and SDA High).
<br>
1 = The bus is busy.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly


@var I2C_T::TMCTL

\htmlonly

<html><table class="fixed" border="1" style="border-collapse:collapse;" borderColor=black ><col width="75px" /><col width="125px" /><col width="700px" /><caption align="left"><font size="3">TMCTL
</font><br><p> <font size="2">
Offset: 0x4C  I2C Timing Configure Control Register
</font></caption><thread><tr bgcolor="#8A0808" ><td><font color=white><b>Bits</b></font></td><td><font color=white><b>Field</b></font></td><td><font color=white><b>Descriptions</b></font></td></tr></thread><tbody>
<tr><td>
[8:0]</td><td>STCTL</td><td><div style="word-wrap: break-word;"><b>Setup Time Configure Control
</b><br>
This field is used to generate a delay timing between SDA falling edge and SCL rising edge in transmission mode.
<br>
The delay setup time is numbers of peripheral clock = STCTL x PCLK.
<br>
Note: Setup time setting should not make SCL output less than three PCLKs.
<br>
</div></td></tr><tr><td>
[24:16]</td><td>HTCTL</td><td><div style="word-wrap: break-word;"><b>Hold Time Configure Control
</b><br>
This field is used to generate the delay timing between SCL falling edge and SDA rising edge in transmission mode.
<br>
The delay hold time is numbers of peripheral clock = HTCTL x PCLK.
<br>
</div></td></tr></tbody></table></html>

\endhtmlonly



 */
    __IO uint32_t CTL0;                  /*!< [0x0000] I2C Control Register 0                                           */
    __IO uint32_t ADDR0;                 /*!< [0x0004] I2C Slave Address Register0                                      */
    __IO uint32_t DAT;                   /*!< [0x0008] I2C Data Register                                                */
    __I  uint32_t STATUS0;               /*!< [0x000c] I2C Status Register 0                                            */
    __IO uint32_t CLKDIV;                /*!< [0x0010] I2C Clock Divided Register                                       */
    __IO uint32_t TOCTL;                 /*!< [0x0014] I2C Time-out Control Register                                    */
    __IO uint32_t ADDR1;                 /*!< [0x0018] I2C Slave Address Register1                                      */
    __IO uint32_t ADDR2;                 /*!< [0x001c] I2C Slave Address Register2                                      */
    __IO uint32_t ADDR3;                 /*!< [0x0020] I2C Slave Address Register3                                      */
    __IO uint32_t ADDRMSK0;              /*!< [0x0024] I2C Slave Address Mask Register0                                 */
    __IO uint32_t ADDRMSK1;              /*!< [0x0028] I2C Slave Address Mask Register1                                 */
    __IO uint32_t ADDRMSK2;              /*!< [0x002c] I2C Slave Address Mask Register2                                 */
    __IO uint32_t ADDRMSK3;              /*!< [0x0030] I2C Slave Address Mask Register3                                 */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[2];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t WKCTL;                 /*!< [0x003c] I2C Wake-up Control Register                                     */
    __IO uint32_t WKSTS;                 /*!< [0x0040] I2C Wake-up Status Register                                      */
    __IO uint32_t CTL1;                  /*!< [0x0044] I2C Control Register 1                                           */
    __IO uint32_t STATUS1;               /*!< [0x0048] I2C Status Register 1                                            */
    __IO uint32_t TMCTL;                 /*!< [0x004c] I2C Timing Configure Control Register                            */
} I2C_T;

/**
    @addtogroup I2C_CONST I2C Bit Field Definition
    Constant Definitions for I2C Controller
@{ */

#define I2C_CTL0_AA_Pos                  (2)                                               /*!< I2C_T::CTL0: AA Position               */
#define I2C_CTL0_AA_Msk                  (0x1ul << I2C_CTL0_AA_Pos)                        /*!< I2C_T::CTL0: AA Mask                   */

#define I2C_CTL0_SI_Pos                  (3)                                               /*!< I2C_T::CTL0: SI Position               */
#define I2C_CTL0_SI_Msk                  (0x1ul << I2C_CTL0_SI_Pos)                        /*!< I2C_T::CTL0: SI Mask                   */

#define I2C_CTL0_STO_Pos                 (4)                                               /*!< I2C_T::CTL0: STO Position              */
#define I2C_CTL0_STO_Msk                 (0x1ul << I2C_CTL0_STO_Pos)                       /*!< I2C_T::CTL0: STO Mask                  */

#define I2C_CTL0_STA_Pos                 (5)                                               /*!< I2C_T::CTL0: STA Position              */
#define I2C_CTL0_STA_Msk                 (0x1ul << I2C_CTL0_STA_Pos)                       /*!< I2C_T::CTL0: STA Mask                  */

#define I2C_CTL0_I2CEN_Pos               (6)                                               /*!< I2C_T::CTL0: I2CEN Position            */
#define I2C_CTL0_I2CEN_Msk               (0x1ul << I2C_CTL0_I2CEN_Pos)                     /*!< I2C_T::CTL0: I2CEN Mask                */

#define I2C_CTL0_INTEN_Pos               (7)                                               /*!< I2C_T::CTL0: INTEN Position            */
#define I2C_CTL0_INTEN_Msk               (0x1ul << I2C_CTL0_INTEN_Pos)                     /*!< I2C_T::CTL0: INTEN Mask                */

#define I2C_ADDR0_GC_Pos                 (0)                                               /*!< I2C_T::ADDR0: GC Position              */
#define I2C_ADDR0_GC_Msk                 (0x1ul << I2C_ADDR0_GC_Pos)                       /*!< I2C_T::ADDR0: GC Mask                  */

#define I2C_ADDR0_ADDR_Pos               (1)                                               /*!< I2C_T::ADDR0: ADDR Position            */
#define I2C_ADDR0_ADDR_Msk               (0x3fful << I2C_ADDR0_ADDR_Pos)                   /*!< I2C_T::ADDR0: ADDR Mask                */

#define I2C_DAT_DAT_Pos                  (0)                                               /*!< I2C_T::DAT: DAT Position               */
#define I2C_DAT_DAT_Msk                  (0xfful << I2C_DAT_DAT_Pos)                       /*!< I2C_T::DAT: DAT Mask                   */

#define I2C_STATUS0_STATUS_Pos           (0)                                               /*!< I2C_T::STATUS0: STATUS Position        */
#define I2C_STATUS0_STATUS_Msk           (0xfful << I2C_STATUS0_STATUS_Pos)                /*!< I2C_T::STATUS0: STATUS Mask            */

#define I2C_CLKDIV_DIVIDER_Pos           (0)                                               /*!< I2C_T::CLKDIV: DIVIDER Position        */
#define I2C_CLKDIV_DIVIDER_Msk           (0x3fful << I2C_CLKDIV_DIVIDER_Pos)               /*!< I2C_T::CLKDIV: DIVIDER Mask            */

#define I2C_CLKDIV_NFCNT_Pos             (12)                                              /*!< I2C_T::CLKDIV: NFCNT Position          */
#define I2C_CLKDIV_NFCNT_Msk             (0xful << I2C_CLKDIV_NFCNT_Pos)                   /*!< I2C_T::CLKDIV: NFCNT Mask              */

#define I2C_TOCTL_TOIF_Pos               (0)                                               /*!< I2C_T::TOCTL: TOIF Position            */
#define I2C_TOCTL_TOIF_Msk               (0x1ul << I2C_TOCTL_TOIF_Pos)                     /*!< I2C_T::TOCTL: TOIF Mask                */

#define I2C_TOCTL_TOCDIV4_Pos            (1)                                               /*!< I2C_T::TOCTL: TOCDIV4 Position         */
#define I2C_TOCTL_TOCDIV4_Msk            (0x1ul << I2C_TOCTL_TOCDIV4_Pos)                  /*!< I2C_T::TOCTL: TOCDIV4 Mask             */

#define I2C_TOCTL_TOCEN_Pos              (2)                                               /*!< I2C_T::TOCTL: TOCEN Position           */
#define I2C_TOCTL_TOCEN_Msk              (0x1ul << I2C_TOCTL_TOCEN_Pos)                    /*!< I2C_T::TOCTL: TOCEN Mask               */

#define I2C_ADDR1_GC_Pos                 (0)                                               /*!< I2C_T::ADDR1: GC Position              */
#define I2C_ADDR1_GC_Msk                 (0x1ul << I2C_ADDR1_GC_Pos)                       /*!< I2C_T::ADDR1: GC Mask                  */

#define I2C_ADDR1_ADDR_Pos               (1)                                               /*!< I2C_T::ADDR1: ADDR Position            */
#define I2C_ADDR1_ADDR_Msk               (0x3fful << I2C_ADDR1_ADDR_Pos)                   /*!< I2C_T::ADDR1: ADDR Mask                */

#define I2C_ADDR2_GC_Pos                 (0)                                               /*!< I2C_T::ADDR2: GC Position              */
#define I2C_ADDR2_GC_Msk                 (0x1ul << I2C_ADDR2_GC_Pos)                       /*!< I2C_T::ADDR2: GC Mask                  */

#define I2C_ADDR2_ADDR_Pos               (1)                                               /*!< I2C_T::ADDR2: ADDR Position            */
#define I2C_ADDR2_ADDR_Msk               (0x3fful << I2C_ADDR2_ADDR_Pos)                   /*!< I2C_T::ADDR2: ADDR Mask                */

#define I2C_ADDR3_GC_Pos                 (0)                                               /*!< I2C_T::ADDR3: GC Position              */
#define I2C_ADDR3_GC_Msk                 (0x1ul << I2C_ADDR3_GC_Pos)                       /*!< I2C_T::ADDR3: GC Mask                  */

#define I2C_ADDR3_ADDR_Pos               (1)                                               /*!< I2C_T::ADDR3: ADDR Position            */
#define I2C_ADDR3_ADDR_Msk               (0x3fful << I2C_ADDR3_ADDR_Pos)                   /*!< I2C_T::ADDR3: ADDR Mask                */

#define I2C_ADDRMSK0_ADDRMSK_Pos         (1)                                               /*!< I2C_T::ADDRMSK0: ADDRMSK Position      */
#define I2C_ADDRMSK0_ADDRMSK_Msk         (0x3fful << I2C_ADDRMSK0_ADDRMSK_Pos)             /*!< I2C_T::ADDRMSK0: ADDRMSK Mask          */

#define I2C_ADDRMSK1_ADDRMSK_Pos         (1)                                               /*!< I2C_T::ADDRMSK1: ADDRMSK Position      */
#define I2C_ADDRMSK1_ADDRMSK_Msk         (0x3fful << I2C_ADDRMSK1_ADDRMSK_Pos)             /*!< I2C_T::ADDRMSK1: ADDRMSK Mask          */

#define I2C_ADDRMSK2_ADDRMSK_Pos         (1)                                               /*!< I2C_T::ADDRMSK2: ADDRMSK Position      */
#define I2C_ADDRMSK2_ADDRMSK_Msk         (0x3fful << I2C_ADDRMSK2_ADDRMSK_Pos)             /*!< I2C_T::ADDRMSK2: ADDRMSK Mask          */

#define I2C_ADDRMSK3_ADDRMSK_Pos         (1)                                               /*!< I2C_T::ADDRMSK3: ADDRMSK Position      */
#define I2C_ADDRMSK3_ADDRMSK_Msk         (0x3fful << I2C_ADDRMSK3_ADDRMSK_Pos)             /*!< I2C_T::ADDRMSK3: ADDRMSK Mask          */

#define I2C_WKCTL_WKEN_Pos               (0)                                               /*!< I2C_T::WKCTL: WKEN Position            */
#define I2C_WKCTL_WKEN_Msk               (0x1ul << I2C_WKCTL_WKEN_Pos)                     /*!< I2C_T::WKCTL: WKEN Mask                */

#define I2C_WKCTL_NHDBUSEN_Pos           (7)                                               /*!< I2C_T::WKCTL: NHDBUSEN Position        */
#define I2C_WKCTL_NHDBUSEN_Msk           (0x1ul << I2C_WKCTL_NHDBUSEN_Pos)                 /*!< I2C_T::WKCTL: NHDBUSEN Mask            */

#define I2C_WKSTS_WKIF_Pos               (0)                                               /*!< I2C_T::WKSTS: WKIF Position            */
#define I2C_WKSTS_WKIF_Msk               (0x1ul << I2C_WKSTS_WKIF_Pos)                     /*!< I2C_T::WKSTS: WKIF Mask                */

#define I2C_WKSTS_WKAKDONE_Pos           (1)                                               /*!< I2C_T::WKSTS: WKAKDONE Position        */
#define I2C_WKSTS_WKAKDONE_Msk           (0x1ul << I2C_WKSTS_WKAKDONE_Pos)                 /*!< I2C_T::WKSTS: WKAKDONE Mask            */

#define I2C_WKSTS_WRSTSWK_Pos            (2)                                               /*!< I2C_T::WKSTS: WRSTSWK Position         */
#define I2C_WKSTS_WRSTSWK_Msk            (0x1ul << I2C_WKSTS_WRSTSWK_Pos)                  /*!< I2C_T::WKSTS: WRSTSWK Mask             */

#define I2C_CTL1_TXPDMAEN_Pos            (0)                                               /*!< I2C_T::CTL1: TXPDMAEN Position         */
#define I2C_CTL1_TXPDMAEN_Msk            (0x1ul << I2C_CTL1_TXPDMAEN_Pos)                  /*!< I2C_T::CTL1: TXPDMAEN Mask             */

#define I2C_CTL1_RXPDMAEN_Pos            (1)                                               /*!< I2C_T::CTL1: RXPDMAEN Position         */
#define I2C_CTL1_RXPDMAEN_Msk            (0x1ul << I2C_CTL1_RXPDMAEN_Pos)                  /*!< I2C_T::CTL1: RXPDMAEN Mask             */

#define I2C_CTL1_PDMARST_Pos             (2)                                               /*!< I2C_T::CTL1: PDMARST Position          */
#define I2C_CTL1_PDMARST_Msk             (0x1ul << I2C_CTL1_PDMARST_Pos)                   /*!< I2C_T::CTL1: PDMARST Mask              */

#define I2C_CTL1_PDMASTR_Pos             (8)                                               /*!< I2C_T::CTL1: PDMASTR Position          */
#define I2C_CTL1_PDMASTR_Msk             (0x1ul << I2C_CTL1_PDMASTR_Pos)                   /*!< I2C_T::CTL1: PDMASTR Mask              */

#define I2C_CTL1_ADDR10EN_Pos            (9)                                               /*!< I2C_T::CTL1: ADDR10EN Position         */
#define I2C_CTL1_ADDR10EN_Msk            (0x1ul << I2C_CTL1_ADDR10EN_Pos)                  /*!< I2C_T::CTL1: ADDR10EN Mask             */

#define I2C_STATUS1_ADMAT0_Pos           (0)                                               /*!< I2C_T::STATUS1: ADMAT0 Position        */
#define I2C_STATUS1_ADMAT0_Msk           (0x1ul << I2C_STATUS1_ADMAT0_Pos)                 /*!< I2C_T::STATUS1: ADMAT0 Mask            */

#define I2C_STATUS1_ADMAT1_Pos           (1)                                               /*!< I2C_T::STATUS1: ADMAT1 Position        */
#define I2C_STATUS1_ADMAT1_Msk           (0x1ul << I2C_STATUS1_ADMAT1_Pos)                 /*!< I2C_T::STATUS1: ADMAT1 Mask            */

#define I2C_STATUS1_ADMAT2_Pos           (2)                                               /*!< I2C_T::STATUS1: ADMAT2 Position        */
#define I2C_STATUS1_ADMAT2_Msk           (0x1ul << I2C_STATUS1_ADMAT2_Pos)                 /*!< I2C_T::STATUS1: ADMAT2 Mask            */

#define I2C_STATUS1_ADMAT3_Pos           (3)                                               /*!< I2C_T::STATUS1: ADMAT3 Position        */
#define I2C_STATUS1_ADMAT3_Msk           (0x1ul << I2C_STATUS1_ADMAT3_Pos)                 /*!< I2C_T::STATUS1: ADMAT3 Mask            */

#define I2C_STATUS1_ONBUSY_Pos           (8)                                               /*!< I2C_T::STATUS1: ONBUSY Position        */
#define I2C_STATUS1_ONBUSY_Msk           (0x1ul << I2C_STATUS1_ONBUSY_Pos)                 /*!< I2C_T::STATUS1: ONBUSY Mask            */

#define I2C_TMCTL_STCTL_Pos              (0)                                               /*!< I2C_T::TMCTL: STCTL Position           */
#define I2C_TMCTL_STCTL_Msk              (0x1fful << I2C_TMCTL_STCTL_Pos)                  /*!< I2C_T::TMCTL: STCTL Mask               */

#define I2C_TMCTL_HTCTL_Pos              (16)                                              /*!< I2C_T::TMCTL: HTCTL Position           */
#define I2C_TMCTL_HTCTL_Msk              (0x1fful << I2C_TMCTL_HTCTL_Pos)                  /*!< I2C_T::TMCTL: HTCTL Mask               */

/** @} I2C_CONST */
/** @} end of I2C register group */
/** @} end of REGISTER group */

#if defined ( __CC_ARM   )
    #pragma no_anon_unions
#endif

#endif /* __I2C_REG_H__ */
