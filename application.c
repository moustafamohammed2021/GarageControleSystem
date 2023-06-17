/* 
 * File:   application.c
 * Author: MOUSTAFA
 *
 * Created on June 15, 2023, 3:43 PM
 */

#include "application.h"
/*
 * 
 */

int main(void) {
    /*************************Initialization Of The Modules In The System*****************/
    ADCON1bits.PCFG=0x0F;
    lcd_4bit_initialize(&Lcd_Obj);//Initialize For The Liquid Character Display
    dc_motor_initialize(&DC_Entry);//Initialize For The DC Motor of The Entry Module
    dc_motor_initialize(&DC_Exit);//Initialize For The DC Motor Of The Exit Module
    gpio_Pin_Intialize(&PinOfEntry);//Initialize For The Pin of The Entry Of the Garage
    gpio_Pin_Intialize(&PinOfExit);//Initialize For The Pin of The Exit Of the Garage
    lcd_4bit_send_string_data(&Lcd_Obj,"There Are 0 Cars");//print The At First There Is Zero Cars
    lcd_4bit_send_string_data_pos(&Lcd_Obj,2,1,"Garage Have Space");//Print At First This Message
    uint8 u8ReadEntryPin=GPIO_LOW;//Initialize The Reading Of The Pin Entry 0
    uint8 u8ReadExitPin=GPIO_LOW;//Initialize The Reading Of The Pin Entry 0
    uint8 u8Counter=0;//Initialize The Counter By Zero
    while(1){//Infinite Loop Work Forever 
        /******************This For The Entry To The Garage************************/
        gpio_Pin_Read_Logic(&PinOfEntry,&u8ReadEntryPin);//Read The Logic In The Pin Of the Entry 
        if((u8ReadEntryPin==GPIO_HIGH) && (u8Counter < 3) && (u8Counter >= 0)){
            u8Counter++;//Increment The Counter Of The Number Of Cars in the Garage
            lcd_4bit_send_char_data_pos(&Lcd_Obj,1,11,u8Counter+0x30);//Print The Number Of the Cars In The Garage
            if(u8Counter==3){//Condition If The Number Equal 3 
                lcd_4bit_send_command(&Lcd_Obj,DISPLAY_CLEAR);//Clear The Screen And Set Cursor Home
                lcd_4bit_send_string_data(&Lcd_Obj,"There Are 3 Cars");//print The At First There Is Zero Cars
                lcd_4bit_send_string_data_pos(&Lcd_Obj,2,1,"Garage Is Full");//Print At First This Message
            }
            dc_motor_move_right(&DC_Entry);//Open The Door 
            _TimerDelay_ms(1000);
            dc_motor_move_left(&DC_Entry);//Close The Door 
             _TimerDelay_ms(1000);
             dc_motor_stop(&DC_Entry);//Stop The Motor 
        }
        else {/*No Thing*/}
         /******************This For The Exit From The Garage************************/
        gpio_Pin_Read_Logic(&PinOfExit,&u8ReadExitPin);//Read The Logic In The Pin Of the Entry 
        if((u8ReadExitPin==GPIO_HIGH) && (u8Counter > 0) && (u8Counter <=3)){
            u8Counter--;//Increment The Counter Of The Number Of Cars in the Garage
            lcd_4bit_send_command(&Lcd_Obj,DISPLAY_CLEAR);//Clear The Screen And Set Cursor Home
            lcd_4bit_send_string_data(&Lcd_Obj,"There Are ");//print The At First There Is Zero Cars
            lcd_4bit_send_char_data_pos(&Lcd_Obj,1,11,u8Counter+0x30);//Print The Number Of the Cars In The Garage
            lcd_4bit_send_string_data(&Lcd_Obj," Cars");//print The At First There Is Zero Cars
            lcd_4bit_send_string_data_pos(&Lcd_Obj,2,1,"Garage Have Space");//Print At First This Message
            dc_motor_move_right(&DC_Exit);//Open The Door 
            _TimerDelay_ms(1000);
            dc_motor_move_left(&DC_Exit);//Close The Door 
             _TimerDelay_ms(1000);
             dc_motor_stop(&DC_Exit);//Stop The Motor 
        }
        else {/*No Thing*/}
        
    }
    return (EXIT_SUCCESS);
}

