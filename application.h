/* 
 * File:   application.h
 * Author: MOUSTAFA
 *
 * Created on June 15, 2023, 3:43 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section: Includes */
#include "MCAL_LAYER/GPIO/hal_gpio.h"
#include "MCAL_LAYER/Delay/M_Delay.h"
#include "ECUAL_LAYER/DC_Motor/ecu_dc_motor.h"
#include "ECUAL_LAYER/char_lcd/ecu_char_lcd.h"
/* Section : Macros Declarations  */

/* Section : macros Function Declarations */

/* Data types Declarations */
/********Structure Of The DC Motor Definition ******************/
dc_motor_t DC_Entry={.dc_motor_pin[0].port=PORTD_INDEX,.dc_motor_pin[0].pin=GPIO_PIN0,
                   .dc_motor_pin[0].direction=GPIO_DIRECTION_OUTPUT,
                   .dc_motor_pin[1].port=PORTD_INDEX,.dc_motor_pin[1].pin=GPIO_PIN1,
                   .dc_motor_pin[1].direction=GPIO_DIRECTION_OUTPUT};
dc_motor_t DC_Exit={.dc_motor_pin[0].port=PORTD_INDEX,.dc_motor_pin[0].pin=GPIO_PIN2,
                   .dc_motor_pin[0].direction=GPIO_DIRECTION_OUTPUT,
                   .dc_motor_pin[1].port=PORTD_INDEX,.dc_motor_pin[1].pin=GPIO_PIN3,
                   .dc_motor_pin[1].direction=GPIO_DIRECTION_OUTPUT};

pin_config_t PinOfEntry={.port=PORTB_INDEX,.pin=GPIO_PIN0,.direction=GPIO_DIRECTION_INPUT};//Definition Of The PIN Of The Entry
pin_config_t PinOfExit={.port=PORTB_INDEX,.pin=GPIO_PIN1,.direction=GPIO_DIRECTION_INPUT};//Definition Of The PIN Of The Exit

/************Structure Of The LCD Module Definition ******************/
lcd_4bit_mode_t Lcd_Obj={.lcd_rs.port=PORTC_INDEX,.lcd_rs.pin=GPIO_PIN0,.lcd_rs.direction=GPIO_DIRECTION_OUTPUT,
                         .lcd_en.port=PORTC_INDEX,.lcd_en.pin=GPIO_PIN1,.lcd_rs.direction=GPIO_DIRECTION_OUTPUT,
                         .lcd_data[0].port=PORTC_INDEX,.lcd_data[0].pin=GPIO_PIN2,.lcd_data[0].direction=GPIO_DIRECTION_OUTPUT,
                         .lcd_data[1].port=PORTC_INDEX,.lcd_data[1].pin=GPIO_PIN3,.lcd_data[1].direction=GPIO_DIRECTION_OUTPUT,
                         .lcd_data[2].port=PORTC_INDEX,.lcd_data[2].pin=GPIO_PIN4,.lcd_data[2].direction=GPIO_DIRECTION_OUTPUT,
                         .lcd_data[3].port=PORTC_INDEX,.lcd_data[3].pin=GPIO_PIN5,.lcd_data[3].direction=GPIO_DIRECTION_OUTPUT};
/* Function Declarations*/
#endif	/* APPLICATION_H */

