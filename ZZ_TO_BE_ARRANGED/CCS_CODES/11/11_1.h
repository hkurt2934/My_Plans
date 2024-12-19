//*************************************************************************************************************************************************//
//******************************************************************HEADER**FILE*******************************************************************//
//*************************************************************************************************************************************************//
#INCLUDE <16F1939.h>
//*************************************************************************************************************************************************//
#DEVICE ADC = 10
//*************************************************************************************************************************************************//
#FUSES HS
#FUSES NOWDT
#FUSES NOLVP
#FUSES NOPUT
#FUSES NOWRT          
#FUSES NOCPD
#FUSES NOMCLR
#FUSES NODEBUG
#FUSES PROTECT
#FUSES NOBROWNOUT
//*************************************************************************************************************************************************//
#USE DELAY(INTERNAL = 4000000)
//*************************************************************************************************************************************USE**TIMER**//
#USE TIMER(TIMER = 1, TICK = 1 US, BITS = 32, NOISR)
//*************************************************************************************************************************************USE**RS232**//
#USE RS232(BAUD = 9600 , XMIT = PIN_C6 , RCV = PIN_C7 , PARITY = N , STOP = 1)
//*************************************************************************************************************************************************//
//******************************************************************PIN***DEFINES******************************************************************//
//*************************************************************************************************************************************************//
//**********************************************************************************************************************************BASIC**VALUEs**//
#DEFINE ALL_ZERO_8_BIT                                         0x00
#DEFINE ALL_ZERO_16_BIT                                        0x0000
#DEFINE ALL_ZERO_32_BIT                                        0x00000000
#DEFINE ALL_ONE_8_BIT                                          0xFF
#DEFINE ALL_ONE_16_BIT                                         0xFFFF
#DEFINE ALL_ONE_32_BIT                                         0xFFFFFFFF
#DEFINE MINUS_ONE                                              -1
//******************************************************************************************************************************SET**TRIS**VALUEs**//
#DEFINE VALUE_TRIS_A                                           0x28
#DEFINE VALUE_TRIS_B                                           0xE8
#DEFINE VALUE_TRIS_C                                           0xC1
#DEFINE VALUE_TRIS_D                                           0x00
#DEFINE VALUE_TRIS_E                                           0x08
//********************************************************************************************************************************ADDRESS**VALUEs**//
#DEFINE VALUE_ADDRESS_WINDOW                                   0x01
#DEFINE VALUE_ADDRESS_AIR                                      0x03
#DEFINE VALUE_ADDRESS_VALVE_DRIVER                             0x04
//***********************************************************************************************************************************RS232**DATAs**//
#DEFINE DATA_CHECK                                             0x00
#DEFINE DATA_CONTROL_START                                     0x01
#DEFINE DATA_CONFIRM_CONTROL_START                             0x02
#DEFINE DATA_CONTROL_FINISH                                    0x03
#DEFINE DATA_CONFIRM_CONTROL_FINISH                            0x04
#DEFINE DATA_ERROR_WINDOW                                      0x05
#DEFINE DATA_NO_ERROR_WINDOW                                   0x06
#DEFINE DATA_CONFIRM_ERROR_WINDOW                              0x07
#DEFINE DATA_ERROR_AIR                                         0x08
#DEFINE DATA_NO_ERROR_AIR                                      0x09
#DEFINE DATA_CONFIRM_ERROR_AIR                                 0x10
#DEFINE DATA_ERROR_VALVE_DRIVER                                0x11
#DEFINE DATA_NO_ERROR_VALVE_DRIVER                             0x12
#DEFINE DATA_CONFIRM_ERROR_VALVE_DRIVER                        0x13
#DEFINE DATA_SHOW_ERROR_FINISH                                 0x14
#DEFINE DATA_CONFIRM_SHOW_ERROR_FINISH                         0x15
#DEFINE DATA_EEPROM_READ_START                                 0x16
#DEFINE DATA_CONFIRM_EEPROM_READ_START                         0x17
#DEFINE DATA_EEPROM_READ_FINISH                                0x18
#DEFINE DATA_CONFIRM_EEPROM_READ_FINISH                        0x19
#DEFINE DATA_CONFIRM_EEPROM_MAX                                0x20
#DEFINE DATA_CONFIRM_EEPROM_FAN_DRIVER                         0x21
#DEFINE DATA_CONFIRM_EEPROM_WINDOW                             0x22
#DEFINE DATA_CONFIRM_EEPROM_WINDOW_STATUS                      0x23
#DEFINE DATA_CONFIRM_EEPROM_AIR                                0x24
#DEFINE DATA_CONFIRM_EEPROM_VALVE_DRIVER                       0x25
#DEFINE DATA_CONFIRM_EEPROM_VALVE_DRIVER_STATUS                0x26
#DEFINE DATA_MAX_OFF                                           0x31
#DEFINE DATA_MAX_ON                                            0x32
#DEFINE DATA_FAN_DRIVER_0                                      0x33
#DEFINE DATA_FAN_DRIVER_1                                      0x34
#DEFINE DATA_FAN_DRIVER_2                                      0x35
#DEFINE DATA_FAN_DRIVER_3                                      0x36
#DEFINE DATA_WINDOW                                            0x37
#DEFINE DATA_FACE                                              0x38
#DEFINE DATA_TOGETHER                                          0x39
#DEFINE DATA_AIR_0                                             0x3D
#DEFINE DATA_AIR_1                                             0x3E
#DEFINE DATA_VALVE_DRIVER_0                                    0x3F
#DEFINE DATA_VALVE_DRIVER_1                                    0x40
#DEFINE DATA_VALVE_DRIVER_2                                    0x41
#DEFINE DATA_VALVE_DRIVER_3                                    0x42
#DEFINE DATA_CONFIRM_MAX_OFF                                   0x51
#DEFINE DATA_CONFIRM_MAX_ON                                    0x52
#DEFINE DATA_CONFIRM_FAN_DRIVER_0                              0x53
#DEFINE DATA_CONFIRM_FAN_DRIVER_1                              0x54
#DEFINE DATA_CONFIRM_FAN_DRIVER_2                              0x55
#DEFINE DATA_CONFIRM_FAN_DRIVER_3                              0x56
#DEFINE DATA_CONFIRM_WINDOW                                    0x57
#DEFINE DATA_CONFIRM_FACE                                      0x58
#DEFINE DATA_CONFIRM_TOGETHER                                  0x59
#DEFINE DATA_CONFIRM_AIR_0                                     0x60
#DEFINE DATA_CONFIRM_AIR_1                                     0x61
#DEFINE DATA_CONFIRM_VALVE_DRIVER_0                            0x62
#DEFINE DATA_CONFIRM_VALVE_DRIVER_1                            0x63
#DEFINE DATA_CONFIRM_VALVE_DRIVER_2                            0x64
#DEFINE DATA_CONFIRM_VALVE_DRIVER_3                            0x65
#DEFINE DATA_RUN_TIME_FIX_WINDOW                               0x81
#DEFINE DATA_RUN_TIME_FIX_AIR                                  0x82
#DEFINE DATA_RUN_TIME_FIX_VALVE_DRIVER                         0x83
#DEFINE DATA_CONFIRM_RUN_TIME_FIX_WINDOW                       0x84
#DEFINE DATA_CONFIRM_RUN_TIME_FIX_AIR                          0x85
#DEFINE DATA_CONFIRM_RUN_TIME_FIX_VALVE_DRIVER                 0x86
#DEFINE DATA_RUN_TIME_ERROR_WINDOW                             0x91
#DEFINE DATA_RUN_TIME_ERROR_AIR                                0x92
#DEFINE DATA_RUN_TIME_ERROR_VALVE_DRIVER                       0x93
#DEFINE DATA_CONFIRM_RUN_TIME_ERROR_WINDOW                     0x94
#DEFINE DATA_CONFIRM_RUN_TIME_ERROR_AIR                        0x95
#DEFINE DATA_CONFIRM_RUN_TIME_ERROR_VALVE_DRIVER               0x96
//****************************************************************************************************************************************BUTTONs**//
#DEFINE BUTTON_MAX                                             PIN_C4
#DEFINE BUTTON_FAN_DRIVER                                      PIN_C0
#DEFINE BUTTON_WINDOW                                          PIN_B3
#DEFINE BUTTON_FACE                                            PIN_A5
#DEFINE BUTTON_TOGETHER                                        PIN_A3
#DEFINE BUTTON_VALVE_DRIVER                                    PIN_B5
#DEFINE BUTTON_AIR                                             PIN_C5
//*******************************************************************************************************************************************LEDs**//
#DEFINE LED_MAX                                                PIN_D3
#DEFINE LED_FAN_DRIVER_1                                       PIN_D0
#DEFINE LED_FAN_DRIVER_2                                       PIN_D1
#DEFINE LED_FAN_DRIVER_3                                       PIN_D2
#DEFINE LED_WINDOW                                             PIN_B2
#DEFINE LED_FACE                                               PIN_A4
#DEFINE LED_TOGETHER                                           PIN_A2
#DEFINE LED_VALVE_DRIVER_0                                     PIN_E0
#DEFINE LED_VALVE_DRIVER_1                                     PIN_E1
#DEFINE LED_VALVE_DRIVER_2                                     PIN_E2
#DEFINE LED_AIR                                                PIN_D7
//*************************************************************************************************************************************************//
//*******************************************************************FUNCTIONs*********************************************************************//
//*************************************************************************************************************************************************//
//********************************************************************************************************************************MAIN**FUNCTIONs**//
VOID Setting();
VOID Make_Default_Value();
VOID Read_Value_From_EEPROM();
VOID Controller_Leds_Starting();
VOID Controller_Error();
VOID Show_Error();
VOID Send_EEPROM_Data();
//*****************************************************************************************************************************SEND-RECEIVE**DATA**//
VOID Data_Receiver();
VOID Data_Receiver_Controller_Error();
VOID Data_Sender(INT8);
//************************************************************************************************ASSIGN**CONTROLLER**ACCORDING**TO**COMING**DATA**//
VOID Assign_Controller_Counter_According_To_Coming_Data();
VOID Assign_Controller_Error_According_To_Coming_Data();
//******************************************************************************************************************BUTTON**CONTROLLER**FUNCTIONs**//
VOID Button_Controller_Max();
VOID Button_Controller_Fan_Driver();
VOID Button_Controller_Window();
VOID Button_Controller_Air();
VOID Button_Controller_Valve_Driver();
//**************************************************************************************************************************CONTROLLER**FUNCTIONs**//
VOID Controller_Max();
VOID Controller_Fan_Driver();
VOID Controller_Window();
VOID Controller_Air();
VOID Controller_Valve_Driver();
VOID Controller_Error_In_Button();
//************************************************************************************************************************************TIME**DELAY**//
VOID Time_Delay(INT32);
VOID Time_Delay_Controller_Error(INT32);
//*******************************************************************************************************************************TICK**DIFFERENCE**//
INT32 Ticks_Difference(INT32,INT32);
//*************************************************************************************************************************************************//
//*******************************************************************VARIABLEs*********************************************************************//
//*************************************************************************************************************************************************//
//*****************************************************************************************************************************COUNTER**VARIABLEs**//
INT8 counter_max                                               = ALL_ZERO_8_BIT;
INT8 counter_fan_driver                                        = ALL_ZERO_8_BIT;
INT8 counter_window                                            = ALL_ZERO_8_BIT;
INT8 counter_air                                               = ALL_ZERO_8_BIT;
INT8 counter_valve_driver                                      = ALL_ZERO_8_BIT;
//*****************************************************************************************************************************COUNTER**VARIABLEs**//
INT8 counter_fan_driver_before                                 = ALL_ZERO_8_BIT;
INT8 counter_window_before                                     = ALL_ZERO_8_BIT;
INT8 counter_air_before                                        = ALL_ZERO_8_BIT;
INT8 counter_valve_driver_before                               = ALL_ZERO_8_BIT;
//*****************************************************************************************************************************COUNTER**VARIABLEs**//
INT8 counter_max_old                                           = ALL_ZERO_8_BIT;
INT8 counter_fan_driver_old                                    = MINUS_ONE;
INT8 counter_window_old                                        = MINUS_ONE;
INT8 counter_air_old                                           = MINUS_ONE;
INT8 counter_valve_driver_old                                  = MINUS_ONE;
//********************************************************************************************************************************DATA**VARIABLEs**//
INT8 data_send                                                 = ALL_ZERO_8_BIT;
INT8 data_receive                                              = ALL_ZERO_8_BIT;
//*****************************************************************************************************************************ADDRESS**VARIABLEs**//
INT8 address_window                                            = VALUE_ADDRESS_WINDOW;
INT8 address_air                                               = VALUE_ADDRESS_AIR;
INT8 address_valve_driver                                      = VALUE_ADDRESS_VALVE_DRIVER;
//**********************************************************************************************************************COUNTER**ERROR**VARIABLEs**//
UNSIGNED INT32 counter_error_window                            = ALL_ZERO_32_BIT;
UNSIGNED INT32 counter_error_window_inner                      = ALL_ZERO_32_BIT;
UNSIGNED INT32 counter_error_air                               = ALL_ZERO_32_BIT;
UNSIGNED INT32 counter_error_air_inner                         = ALL_ZERO_32_BIT;
UNSIGNED INT32 counter_error_valve_driver                      = ALL_ZERO_32_BIT;
UNSIGNED INT32 counter_error_valve_driver_inner                = ALL_ZERO_32_BIT;
//********************************************************************************************************************************TIME**VARIABLEs**//
UNSIGNED INT32 time_delay_starting                             = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_delay_current                              = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_delay_difference                           = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_difference                                 = ALL_ZERO_32_BIT;
//**********************************************************************************************************************************BUTTON**STATE**//
BOOLEAN state_button_max                                       = FALSE;
BOOLEAN state_button_fan_driver                                = FALSE;
BOOLEAN state_button_window                                    = FALSE;
BOOLEAN state_button_face                                      = FALSE;
BOOLEAN state_button_together                                  = FALSE;
BOOLEAN state_button_air                                       = FALSE;
BOOLEAN state_button_valve_driver                              = FALSE;
//***************************************************************************************************************************DATA**CONFIRM**STATE**//
BOOLEAN state_confirm_max_off                                  = FALSE;
BOOLEAN state_confirm_max_on                                   = FALSE;
BOOLEAN state_confirm_fan_driver_0                             = FALSE;
BOOLEAN state_confirm_fan_driver_1                             = FALSE;
BOOLEAN state_confirm_fan_driver_2                             = FALSE;
BOOLEAN state_confirm_fan_driver_3                             = FALSE;
BOOLEAN state_confirm_window                                   = FALSE;
BOOLEAN state_confirm_face                                     = FALSE;
BOOLEAN state_confirm_together                                 = FALSE;
BOOLEAN state_confirm_air_0                                    = FALSE;
BOOLEAN state_confirm_air_1                                    = FALSE;
BOOLEAN state_confirm_valve_driver_0                           = FALSE;
BOOLEAN state_confirm_valve_driver_1                           = FALSE;
BOOLEAN state_confirm_valve_driver_2                           = FALSE;
BOOLEAN state_confirm_valve_driver_3                           = FALSE;
//***********************************************************************************************************************************ERROR**STATE**//
BOOLEAN state_error_window                                     = FALSE;
BOOLEAN state_error_air                                        = FALSE;
BOOLEAN state_error_valve_driver                               = FALSE;
BOOLEAN state_show_error_window                                = FALSE;
BOOLEAN state_show_error_air                                   = FALSE;
BOOLEAN state_show_error_valve_driver                          = FALSE;
//***************************************************************************************************************************COMMUNICATION**STATE**//
BOOLEAN state_communication_control_start                      = FALSE;
BOOLEAN state_communication_window                             = FALSE;
BOOLEAN state_communication_air                                = FALSE;
BOOLEAN state_communication_valve_driver                       = FALSE;
BOOLEAN state_communication_control_finish                     = FALSE;
BOOLEAN state_communication_show_error_finish                  = FALSE;
//*************************************************************************************************************************************************//
BOOLEAN state_controller_error_in_button_window                = FALSE;
BOOLEAN state_controller_error_in_button_air                   = FALSE;
BOOLEAN state_controller_error_in_button_valve_driver          = FALSE;
//*************************************************************************************************************************************************//
BOOLEAN state_confirm_eeprom_read_start                        = FALSE;
BOOLEAN state_confirm_eeprom_read_finish                       = FALSE;
BOOLEAN state_confirm_eeprom_max                               = FALSE;
BOOLEAN state_confirm_eeprom_fan_driver                        = FALSE;
BOOLEAN state_confirm_eeprom_window                            = FALSE;
BOOLEAN state_confirm_eeprom_air                               = FALSE;
BOOLEAN state_confirm_eeprom_valve_driver                      = FALSE;
//*************************************************************************************************************************************************//
BOOLEAN state_fan_driver_in_max                                = FALSE;
//*************************************************************************************************************************************************//
//*******************************************************************SETTING***********************************************************************//
//*************************************************************************************************************************************************//
VOID Setting(){
//***************************************************************************************************************************CLOSING**ALL**OUTPUT**//
   OUTPUT_A(0x00);
   OUTPUT_B(0x00);
   OUTPUT_C(0x00);
   OUTPUT_D(0x00);
   OUTPUT_E(0x00);
//*********************************************************************************************************************************SETTING**DELAY**//
   DELAY_MS(1000);
//****************************************************************************************************************************SETTING**I/O**PORTs**//
   SET_TRIS_A(VALUE_TRIS_A);
   SET_TRIS_B(VALUE_TRIS_B);
   SET_TRIS_C(VALUE_TRIS_C);
   SET_TRIS_D(VALUE_TRIS_D);
   SET_TRIS_E(VALUE_TRIS_E);
   DELAY_MS(2);
//*************************************************************************************************************************************************//
   set_ticks(0);
}
//*************************************************************************************************************************************************//
//***************************************************************MAKE**DEFAULT**VALUE**************************************************************//
//*************************************************************************************************************************************************//
VOID Make_Default_Value(){
//*************************************************************************************************************************************************//
   data_send                        = ALL_ZERO_8_BIT;
   data_receive                     = ALL_ZERO_8_BIT;
   counter_max                      = ALL_ZERO_8_BIT;
   counter_fan_driver               = ALL_ZERO_8_BIT;
   counter_window                   = ALL_ZERO_8_BIT;
   counter_air                      = ALL_ZERO_8_BIT;
   counter_valve_driver             = ALL_ZERO_8_BIT;
   counter_fan_driver_old           = MINUS_ONE;
   counter_window_old               = MINUS_ONE;
   counter_air_old                  = MINUS_ONE;
   counter_valve_driver_old         = MINUS_ONE;
}
//*************************************************************************************************************************************************//
//*************************************************READ**VALUE**WHEN**BEFORE**SHUTDOWN**FROM**EEPROM***********************************************//
//*************************************************************************************************************************************************//
VOID Read_Value_From_EEPROM(){
   IF(!state_error_window){
      counter_window                   = READ_EEPROM(address_window);
   }
   ELSE{
      counter_window                   = 0;
   }
   IF(!state_error_air){
      counter_air                      = READ_EEPROM(address_air);
   }
   ELSE{
      counter_air                      = 0;
   }
   IF(!state_error_valve_driver){
      counter_valve_driver             = READ_EEPROM(address_valve_driver);
   }
   ELSE{
      counter_valve_driver             = 0;
   }
}
//*************************************************************************************************************************************************//
//*****************************************************************CONTROLLLING**LEDS**************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Leds_Starting(){
//***********************************************************************************************************************************MAX**CONTROL**//
   Button_Controller_Max();
//***************************************************************************************************************************DRIVER**FAN**CONTROL**//
   Button_Controller_Fan_Driver();
//********************************************************************************************************************************WINDOW**CONTROL**//
   Button_Controller_Window(); 
//***********************************************************************************************************************************AIR**CONTROL**//
   Button_Controller_Air(); 
//*************************************************************************************************************************DRIVER**VALVE**CONTROL**//
   Button_Controller_Valve_Driver();
//*************************************************************************************************************************************************//
   IF(!state_fan_driver_in_max){
//***************************************************************************************************************DRIVER**FAN**CONTROL**COUNTER**0**//
      IF((counter_fan_driver % 4) == 0){
         OUTPUT_LOW(LED_FAN_DRIVER_1);
         OUTPUT_LOW(LED_FAN_DRIVER_2);
         OUTPUT_LOW(LED_FAN_DRIVER_3);
      }
//***************************************************************************************************************DRIVER**FAN**CONTROL**COUNTER**1**//
      IF((counter_fan_driver % 4) == 1){
         OUTPUT_HIGH(LED_FAN_DRIVER_1);
         OUTPUT_LOW(LED_FAN_DRIVER_2);
         OUTPUT_LOW(LED_FAN_DRIVER_3);
      }
//***************************************************************************************************************DRIVER**FAN**CONTROL**COUNTER**2**//
      IF((counter_fan_driver % 4) == 2){
         OUTPUT_HIGH(LED_FAN_DRIVER_1);
         OUTPUT_HIGH(LED_FAN_DRIVER_2);
         OUTPUT_LOW(LED_FAN_DRIVER_3);
      }
//***************************************************************************************************************DRIVER**FAN**CONTROL**COUNTER**3**//
      IF((counter_fan_driver % 4) == 3){
         OUTPUT_HIGH(LED_FAN_DRIVER_1);
         OUTPUT_HIGH(LED_FAN_DRIVER_2);
         OUTPUT_HIGH(LED_FAN_DRIVER_3);
      }
   }
//***********************************************************************************************************************MAX**CONTROL**COUNTER**0**//
   IF((counter_max % 2) == 0){
      OUTPUT_LOW(LED_MAX);
//**************************************************************************************************************WINDOW**CONTROL**WINDOW**POSITION**//
      IF((counter_window % 3) == 0){
         OUTPUT_HIGH(LED_WINDOW);
         OUTPUT_LOW(LED_FACE);
         OUTPUT_LOW(LED_TOGETHER);
      }
//****************************************************************************************************************WINDOW**CONTROL**FACE**POSITION**//
      IF((counter_window % 3) == 1){
         OUTPUT_LOW(LED_WINDOW);
         OUTPUT_HIGH(LED_FACE);
         OUTPUT_LOW(LED_TOGETHER);
      }
//************************************************************************************************************WINDOW**CONTROL**TOGETHER**POSITION**//
      IF((counter_window % 3) == 2){
         OUTPUT_LOW(LED_WINDOW);
         OUTPUT_LOW(LED_FACE);
         OUTPUT_HIGH(LED_TOGETHER);
      }
//***********************************************************************************************************************AIR**CONTROL**COUNTER**0**//
      IF((counter_air % 2) == 0){
         OUTPUT_LOW(LED_AIR);
      }
//***********************************************************************************************************************AIR**CONTROL**COUNTER**1**//
      IF((counter_air % 2) == 1){
         OUTPUT_HIGH(LED_AIR);
      }
//*************************************************************************************************************VALVE**DRIVER**CONTROL**COUNTER**0**//
      IF((counter_valve_driver % 4) == 0){
         OUTPUT_HIGH(LED_VALVE_DRIVER_0);
         OUTPUT_LOW(LED_VALVE_DRIVER_1);
         OUTPUT_LOW(LED_VALVE_DRIVER_2);
      }
//*************************************************************************************************************VALVE**DRIVER**CONTROL**COUNTER**1**//
      IF((counter_valve_driver % 4) == 1){
         OUTPUT_LOW(LED_VALVE_DRIVER_0);
         OUTPUT_HIGH(LED_VALVE_DRIVER_1);
         OUTPUT_LOW(LED_VALVE_DRIVER_2);
      }
//*************************************************************************************************************VALVE**DRIVER**CONTROL**COUNTER**2**//
      IF((counter_valve_driver % 4) == 2){
         OUTPUT_LOW(LED_VALVE_DRIVER_0);
         OUTPUT_LOW(LED_VALVE_DRIVER_1);
         OUTPUT_HIGH(LED_VALVE_DRIVER_2);
      }
//*************************************************************************************************************VALVE**DRIVER**CONTROL**COUNTER**3**//
      IF((counter_valve_driver % 4) == 3){
         OUTPUT_LOW(LED_VALVE_DRIVER_0);
         OUTPUT_HIGH(LED_VALVE_DRIVER_1);
         OUTPUT_HIGH(LED_VALVE_DRIVER_2);
      }
   }
//***********************************************************************************************************************MAX**CONTROL**COUNTER**1**//
   IF((counter_max % 2) == 1){
      OUTPUT_HIGH(LED_MAX);
   }
}
//*************************************************************************************************************************************************//
//****************************************************************CONTROLLLING**ERROR**************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Error(){
//**************************************************************************************************************************CONTROL**ERROR**START**//
   state_communication_control_start = TRUE;
   WHILE(state_communication_control_start){
      Controller_Leds_Starting();
      Time_Delay_Controller_Error(100);
   }
//*************************************************************************************************************************CONTROL**ERROR**WINDOW**//
   state_communication_window = TRUE;
   WHILE(state_communication_window){
      Controller_Leds_Starting();
      Data_Sender(DATA_CONFIRM_CONTROL_START);
      Time_Delay_Controller_Error(100);
   }
//****************************************************************************************************************************CONTROL**ERROR**AIR**//
   state_communication_air = TRUE;
   WHILE(state_communication_air){
      Controller_Leds_Starting();
      Data_Sender(DATA_CONFIRM_ERROR_WINDOW);
      Time_Delay_Controller_Error(100);
   }
//******************************************************************************************************************CONTROL**ERROR**DRIVER**VALVE**//
   state_communication_valve_driver = TRUE;
   WHILE(state_communication_valve_driver){
      Controller_Leds_Starting();
      Data_Sender(DATA_CONFIRM_ERROR_AIR);
      Time_Delay_Controller_Error(100);
   }
//*************************************************************************************************************************CONTROL**ERROR**FINISH**//
   state_communication_control_finish = TRUE;
   WHILE(state_communication_control_finish){
      Controller_Leds_Starting();
      Data_Sender(DATA_CONFIRM_ERROR_VALVE_DRIVER);
      Time_Delay_Controller_Error(100);
   }
   Data_Sender(DATA_CONFIRM_CONTROL_FINISH);
}
//*************************************************************************************************************************************************//
//*********************************************************************SHOW**ERROR*****************************************************************//
//*************************************************************************************************************************************************//
VOID Show_Error(){
//*************************************************************************************************************************CONTROL**ERROR**WINDOW**//
   WHILE(state_show_error_window){
      counter_error_window++;
      IF(counter_error_window == 2500){
         OUTPUT_HIGH(LED_WINDOW);
         OUTPUT_LOW(LED_FACE);
         OUTPUT_LOW(LED_TOGETHER);
      }
      IF(counter_error_window == 5000){
         counter_error_window = 0;
         OUTPUT_LOW(LED_WINDOW);
         OUTPUT_LOW(LED_FACE);
         OUTPUT_LOW(LED_TOGETHER);
      }
      counter_error_window_inner = 0;
      WHILE(!INPUT(BUTTON_WINDOW)){
         counter_error_window_inner++;
         IF(counter_error_window_inner == 50000){
            counter_error_window_inner = 0;
            state_show_error_window = FALSE;
            OUTPUT_LOW(LED_WINDOW);
            OUTPUT_LOW(LED_FACE);
            OUTPUT_LOW(LED_TOGETHER);
            Time_Delay_Controller_Error(50);
         }
      }
   }
//****************************************************************************************************************************CONTROL**ERROR**AIR**//
   WHILE(state_show_error_air){
      counter_error_air++;
      IF(counter_error_air == 2500){
         OUTPUT_HIGH(LED_AIR);
      }
      IF(counter_error_air == 5000){
         counter_error_air = 0;
         OUTPUT_LOW(LED_AIR);
      }
      counter_error_air_inner = 0;
      WHILE(!INPUT(BUTTON_AIR)){
         counter_error_air_inner++;
         IF(counter_error_air_inner == 50000){
            counter_error_air_inner = 0;
            state_show_error_air = FALSE;
            OUTPUT_LOW(LED_AIR);
            Time_Delay_Controller_Error(50);
         }
      }
   }
//******************************************************************************************************************CONTROL**ERROR**DRIVER**VALVE**//
   WHILE(state_show_error_valve_driver){
      counter_error_valve_driver++;
      IF(counter_error_valve_driver == 2500){
         OUTPUT_HIGH(LED_VALVE_DRIVER_0);
         OUTPUT_HIGH(LED_VALVE_DRIVER_1);
         OUTPUT_HIGH(LED_VALVE_DRIVER_2);
      }
      IF(counter_error_valve_driver == 5000){
         counter_error_valve_driver = 0;
         OUTPUT_LOW(LED_VALVE_DRIVER_0);
         OUTPUT_LOW(LED_VALVE_DRIVER_1);
         OUTPUT_LOW(LED_VALVE_DRIVER_2);
      }
      counter_error_valve_driver_inner = 0;
      WHILE(!INPUT(BUTTON_VALVE_DRIVER)){
         counter_error_valve_driver_inner++;
         IF(counter_error_valve_driver_inner == 50000){
            counter_error_valve_driver_inner = 0;
            state_show_error_valve_driver = FALSE;
            OUTPUT_LOW(LED_VALVE_DRIVER_0);
            OUTPUT_LOW(LED_VALVE_DRIVER_1);
            OUTPUT_LOW(LED_VALVE_DRIVER_2);
            Time_Delay_Controller_Error(50);
         }
      }
   }
//*************************************************************************************************************************CONTROL**ERROR**FINISH**//
   state_communication_show_error_finish = TRUE;
   WHILE(state_communication_show_error_finish){
      Data_Sender(DATA_SHOW_ERROR_FINISH);
      Time_Delay_Controller_Error(50);
   }
}
//*************************************************************************************************************************************************//
//**********************************************************WORK**ACCORDING**TO**EEPROM**VALUE*****************************************************//
//*************************************************************************************************************************************************//
VOID Send_EEPROM_Data(){
//******************************************************************************************************************************************START**//
   Time_Delay_Controller_Error(100);
   state_confirm_eeprom_read_start                 = FALSE;
   WHILE(!state_confirm_eeprom_read_start){
      Data_Sender(DATA_EEPROM_READ_START);
      Time_Delay_Controller_Error(50);
   }
//********************************************************************************************************************************************MAX**//
   state_confirm_eeprom_max                        = FALSE;
   WHILE(!state_confirm_eeprom_max){
      Data_Sender(DATA_MAX_OFF);
      Time_Delay_Controller_Error(50);
   }
//************************************************************************************************************************************FAN**DRIVER**//
   state_confirm_eeprom_fan_driver                 = FALSE;
   WHILE(!state_confirm_eeprom_fan_driver){
      Data_Sender(DATA_FAN_DRIVER_0);
      Time_Delay_Controller_Error(50);
   }
//*****************************************************************************************************************************************WINDOW**//
   IF((counter_window % 3) == 0){
      data_send = DATA_WINDOW;
   }
   IF((counter_window % 3) == 1){
      data_send = DATA_FACE;
   }
   IF((counter_window % 3) == 2){
      data_send = DATA_TOGETHER;
   }
   state_confirm_eeprom_window = FALSE;
   WHILE(!state_confirm_eeprom_window){
      Data_Sender(data_send);
      Time_Delay_Controller_Error(50);
   }
//********************************************************************************************************************************************AIR**//
   IF((counter_air % 2) == 0){
      data_send = DATA_AIR_0;
   }
   IF((counter_air % 2) == 1){
      data_send = DATA_AIR_1;
   }
   state_confirm_eeprom_air = FALSE;
   WHILE(!state_confirm_eeprom_air){
      Data_Sender(data_send);
      Time_Delay_Controller_Error(50);
   }
//**********************************************************************************************************************************VALVE**DRIVER**//
   IF((counter_valve_driver % 4) == 0){
      data_send = DATA_VALVE_DRIVER_0;
   }
   IF((counter_valve_driver % 4) == 1){
      data_send = DATA_VALVE_DRIVER_1;
   }
   IF((counter_valve_driver % 4) == 2){
      data_send = DATA_VALVE_DRIVER_2;
   }
   IF((counter_valve_driver % 4) == 3){
      data_send = DATA_VALVE_DRIVER_3;
   }
   state_confirm_eeprom_valve_driver = FALSE;
   WHILE(!state_confirm_eeprom_valve_driver){
      Data_Sender(data_send);
      Time_Delay_Controller_Error(50);
   }
//*****************************************************************************************************************************************FINISH**//
   state_confirm_eeprom_read_finish = FALSE;
   WHILE(!state_confirm_eeprom_read_finish){
      Data_Sender(DATA_EEPROM_READ_FINISH);
      Time_Delay_Controller_Error(50);
   }
//*************************************************************************************************************************************************//
}
//*************************************************************************************************************************************************//
//**************************************************************MAX**BUTTON**CONTROL***************************************************************//
//*************************************************************************************************************************************************//
VOID Button_Controller_Max(){
   IF(!INPUT(BUTTON_MAX) && (state_button_max)){
      state_button_max                             = FALSE;
      Time_Delay(100);
      counter_max++;
//********************************************************************************************************************************COUNTER**MAX**0**//
      IF((counter_max % 2) == 0){
         counter_max                               = 0;
         state_fan_driver_in_max                   = FALSE;
         counter_fan_driver                        = counter_fan_driver_before;
         counter_window                            = counter_window_before;
         counter_air                               = counter_air_before;
         counter_valve_driver                      = counter_valve_driver_before;
      }
//********************************************************************************************************************************COUNTER**MAX**1**//
      IF((counter_max % 2) == 1){
         counter_max                               = 1;
         state_fan_driver_in_max                   = TRUE;
         counter_fan_driver_before                 = counter_fan_driver;
         counter_window_before                     = counter_window;
         counter_air_before                        = counter_air;
         counter_valve_driver_before               = counter_valve_driver;
         counter_fan_driver                        = 3;
         counter_window                            = 0;
         counter_air                               = 0;
         counter_valve_driver                      = 0;
      }
   }
   IF(INPUT(BUTTON_MAX)){
      state_button_max                             = TRUE;
   }
}
//*************************************************************************************************************************************************//
//**********************************************************DRIVER**FAN**BUTTON**CONTROL***********************************************************//
//*************************************************************************************************************************************************//
VOID Button_Controller_Fan_Driver(){
   IF(!INPUT(BUTTON_FAN_DRIVER) && (state_button_fan_driver)){
      Time_Delay(100);
      state_button_fan_driver                      = FALSE;
//********************************************************************************************************************************COUNTER**MAX**1**//
      IF(state_fan_driver_in_max){
         state_fan_driver_in_max                   = FALSE;
         counter_fan_driver                        = counter_fan_driver_before;
      }
      counter_fan_driver++;
      IF(((counter_max % 2) == 1) && ((counter_fan_driver % 4) == 0)){
         counter_max                               = 0;
         counter_window                            = counter_window_before;
         counter_air                               = counter_air_before;
         counter_valve_driver                      = counter_valve_driver_before;
      }
   }
   IF(INPUT(BUTTON_FAN_DRIVER)){
      state_button_fan_driver                      = TRUE;
   }
}
//*************************************************************************************************************************************************//
//***************************************************************WINDOW**BUTTON**CONTROL***********************************************************//
//*************************************************************************************************************************************************//
//*****************************************************************************************************************************************WINDOW**//
VOID Button_Controller_Window(){
   IF(!INPUT(BUTTON_WINDOW) && (state_button_window)){
      IF(!state_error_window){
         Time_Delay(100);
         state_button_window                       = FALSE;
//********************************************************************************************************************************COUNTER**MAX**1**//
         IF((counter_max % 2) == 1){
            counter_max                            = 0;
            counter_fan_driver                     = counter_fan_driver_before;
            counter_window                         = counter_window_before;
            counter_air                            = counter_air_before;
            counter_valve_driver                   = counter_valve_driver_before;
         }
         counter_window                            = 0;
      }
      ELSE{
         state_controller_error_in_button_window   = TRUE;
      }
   }
   IF(INPUT(BUTTON_WINDOW)){
      state_button_window                          = TRUE;
   }
//*******************************************************************************************************************************************FACE**//
   IF(!INPUT(BUTTON_FACE) && (state_button_face)){
      IF(!state_error_window){
         Time_Delay(100);
         state_button_face                         = FALSE;
//********************************************************************************************************************************COUNTER**MAX**1**//
         IF((counter_max % 2) == 1){
            counter_max                            = 0;
            counter_fan_driver                     = counter_fan_driver_before;
            counter_window                         = counter_window_before;
            counter_air                            = counter_air_before;
            counter_valve_driver                   = counter_valve_driver_before;
         }
         counter_window                            = 1;
      }
      ELSE{
         state_controller_error_in_button_window   = TRUE;
      }
   }
   IF(INPUT(BUTTON_FACE)){
      state_button_face                            = TRUE;
   }
//***************************************************************************************************************************************TOGETHER**//
   IF(!INPUT(BUTTON_TOGETHER) && (state_button_together)){
      IF(!state_error_window){
         Time_Delay(100);
         state_button_together                     = FALSE;
//********************************************************************************************************************************COUNTER**MAX**1**//
         IF((counter_max % 2) == 1){
            counter_max                            = 0;
            counter_fan_driver                     = counter_fan_driver_before;
            counter_window                         = counter_window_before;
            counter_air                            = counter_air_before;
            counter_valve_driver                   = counter_valve_driver_before;
         }
         counter_window                            = 2;
      }
      ELSE{
         state_controller_error_in_button_window   = TRUE;
      }
   }
   IF(INPUT(BUTTON_TOGETHER)){
      state_button_together                        = TRUE;
   }
}
//*************************************************************************************************************************************************//
//*****************************************************************AIR**BUTTON**CONTROL************************************************************//
//*************************************************************************************************************************************************//
VOID Button_Controller_Air(){
   IF(!INPUT(BUTTON_AIR) && (state_button_air)){
      IF(!state_error_air){
         Time_Delay(100);
         state_button_air                          = FALSE;
//********************************************************************************************************************************COUNTER**MAX**1**//
         IF((counter_max % 2) == 1){
            counter_max                            = 0;
            counter_fan_driver                     = counter_fan_driver_before;
            counter_window                         = counter_window_before;
            counter_air                            = counter_air_before;
            counter_valve_driver                   = counter_valve_driver_before;
         }
         counter_air++;
      }
      ELSE{
         state_controller_error_in_button_air      = TRUE;
      }
   }
   IF(INPUT(BUTTON_AIR)){
      state_button_air                             = TRUE;
   }
}
//*************************************************************************************************************************************************//
//*************************************************************DRIVER**VALVE**BUTTON**CONTROL******************************************************//
//*************************************************************************************************************************************************//
VOID Button_Controller_Valve_Driver(){
   IF(!INPUT(BUTTON_VALVE_DRIVER) && (state_button_valve_driver)){
      IF(!state_error_valve_driver){
         Time_Delay(100);
         state_button_valve_driver                 = FALSE;
//********************************************************************************************************************************COUNTER**MAX**1**//
         IF((counter_max % 2) == 1){
            counter_max                            = 0;
            counter_fan_driver                     = counter_fan_driver_before;
            counter_window                         = counter_window_before;
            counter_air                            = counter_air_before;
            counter_valve_driver                   = counter_valve_driver_before;
         }
         counter_valve_driver++;
      }
      ELSE{
         state_controller_error_in_button_valve_driver = TRUE;
      }
   }
   IF(INPUT(BUTTON_VALVE_DRIVER)){
      state_button_valve_driver                    = TRUE;
   }
}
//*************************************************************************************************************************************************//
//***************************************************************CONTROLLER**FUNCTIONS*************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Functions(){
   Controller_Error_In_Button();
   IF(!(counter_max == counter_max_old)){
      Controller_Max();
   }
   IF(!(counter_fan_driver == counter_fan_driver_old)){
      Controller_Fan_Driver();
   }
   IF(!state_error_window){
      IF(!(counter_window == counter_window_old)){
         Controller_Window();
      }
   }
   IF(!state_error_air){
      IF(!(counter_air == counter_air_old)){
         Controller_Air();
      }
   }
   IF(!state_error_valve_driver){
      IF(!(counter_valve_driver == counter_valve_driver_old)){
         Controller_Valve_Driver();
      }
   }
}
//*************************************************************************************************************************************************//
//*********************************************************************LED**CONTROL****************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Leds(){
   IF(!state_fan_driver_in_max){
//***************************************************************************************************************DRIVER**FAN**CONTROL**COUNTER**0**//
      IF((counter_fan_driver % 4) == 0){
         OUTPUT_LOW(LED_FAN_DRIVER_1);
         OUTPUT_LOW(LED_FAN_DRIVER_2);
         OUTPUT_LOW(LED_FAN_DRIVER_3);
      }
//***************************************************************************************************************DRIVER**FAN**CONTROL**COUNTER**1**//
      IF((counter_fan_driver % 4) == 1){
         OUTPUT_HIGH(LED_FAN_DRIVER_1);
         OUTPUT_LOW(LED_FAN_DRIVER_2);
         OUTPUT_LOW(LED_FAN_DRIVER_3);
      }
//***************************************************************************************************************DRIVER**FAN**CONTROL**COUNTER**2**//
      IF((counter_fan_driver % 4) == 2){
         OUTPUT_HIGH(LED_FAN_DRIVER_1);
         OUTPUT_HIGH(LED_FAN_DRIVER_2);
         OUTPUT_LOW(LED_FAN_DRIVER_3);
      }
//***************************************************************************************************************DRIVER**FAN**CONTROL**COUNTER**3**//
      IF((counter_fan_driver % 4) == 3){
         OUTPUT_HIGH(LED_FAN_DRIVER_1);
         OUTPUT_HIGH(LED_FAN_DRIVER_2);
         OUTPUT_HIGH(LED_FAN_DRIVER_3);
      }
   }
//***********************************************************************************************************************MAX**CONTROL**COUNTER**0**//
   IF((counter_max % 2) == 0){
      OUTPUT_LOW(LED_MAX);
//**************************************************************************************************************WINDOW**CONTROL**WINDOW**POSITION**//
      IF((counter_window % 3) == 0){
         OUTPUT_HIGH(LED_WINDOW);
         OUTPUT_LOW(LED_FACE);
         OUTPUT_LOW(LED_TOGETHER);
      }
//****************************************************************************************************************WINDOW**CONTROL**FACE**POSITION**//
      IF((counter_window % 3) == 1){
         OUTPUT_LOW(LED_WINDOW);
         OUTPUT_HIGH(LED_FACE);
         OUTPUT_LOW(LED_TOGETHER);
      }
//************************************************************************************************************WINDOW**CONTROL**TOGETHER**POSITION**//
      IF((counter_window % 3) == 2){
         OUTPUT_LOW(LED_WINDOW);
         OUTPUT_LOW(LED_FACE);
         OUTPUT_HIGH(LED_TOGETHER);
      }
//***********************************************************************************************************************AIR**CONTROL**COUNTER**0**//
      IF((counter_air % 2) == 0){
         OUTPUT_LOW(LED_AIR);
      }
//***********************************************************************************************************************AIR**CONTROL**COUNTER**1**//
      IF((counter_air % 2) == 1){
         OUTPUT_HIGH(LED_AIR);
      }
//*************************************************************************************************************VALVE**DRIVER**CONTROL**COUNTER**0**//
      IF((counter_valve_driver % 4) == 0){
         OUTPUT_HIGH(LED_VALVE_DRIVER_0);
         OUTPUT_LOW(LED_VALVE_DRIVER_1);
         OUTPUT_LOW(LED_VALVE_DRIVER_2);
      }
//*************************************************************************************************************VALVE**DRIVER**CONTROL**COUNTER**1**//
      IF((counter_valve_driver % 4) == 1){
         OUTPUT_LOW(LED_VALVE_DRIVER_0);
         OUTPUT_HIGH(LED_VALVE_DRIVER_1);
         OUTPUT_LOW(LED_VALVE_DRIVER_2);
      }
//*************************************************************************************************************VALVE**DRIVER**CONTROL**COUNTER**2**//
      IF((counter_valve_driver % 4) == 2){
         OUTPUT_LOW(LED_VALVE_DRIVER_0);
         OUTPUT_LOW(LED_VALVE_DRIVER_1);
         OUTPUT_HIGH(LED_VALVE_DRIVER_2);
      }
//*************************************************************************************************************VALVE**DRIVER**CONTROL**COUNTER**3**//
      IF((counter_valve_driver % 4) == 3){
         OUTPUT_LOW(LED_VALVE_DRIVER_0);
         OUTPUT_HIGH(LED_VALVE_DRIVER_1);
         OUTPUT_HIGH(LED_VALVE_DRIVER_2);
      }
   }
//***********************************************************************************************************************MAX**CONTROL**COUNTER**1**//
   IF((counter_max % 2) == 1){
      OUTPUT_HIGH(LED_MAX);
   }
}
//*************************************************************************************************************************************************//
//*********************************************************************MAX**CONTROL****************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Max(){
   IF((counter_max % 2) == 0){
      counter_max                                  = 0;
      counter_max_old                              = counter_max;
      state_confirm_max_off                        = FALSE;
      WHILE(!state_confirm_max_off){
         Data_Sender(DATA_MAX_OFF);
         Time_Delay(50);
      }
   }
   IF((counter_max % 2) == 1){
      counter_max_old                              = counter_max;
      state_confirm_max_on                         = FALSE;
      WHILE(!state_confirm_max_on){
         Data_Sender(DATA_MAX_ON);
         Time_Delay(50);
      }
   }
}
//*************************************************************************************************************************************************//
//***************************************************************DRIVER**FAN**CONTROL**************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Fan_Driver(){
   IF((counter_fan_driver % 4) == 0){
      counter_fan_driver               = 0;
      counter_fan_driver_old           = counter_fan_driver;
      state_confirm_fan_driver_0       = FALSE;
      WHILE(!state_confirm_fan_driver_0){
         Data_Sender(DATA_FAN_DRIVER_0);
         Time_Delay(50);
      }
   }
   IF((counter_fan_driver % 4) == 1){
      counter_fan_driver_old           = counter_fan_driver;
      state_confirm_fan_driver_1       = FALSE;
      WHILE(!state_confirm_fan_driver_1){
         Data_Sender(DATA_FAN_DRIVER_1);
         Time_Delay(50);
      }
   }
   IF((counter_fan_driver % 4) == 2){
      counter_fan_driver_old           = counter_fan_driver;
      state_confirm_fan_driver_2       = FALSE;
      WHILE(!state_confirm_fan_driver_2){
         Data_Sender(DATA_FAN_DRIVER_2);
         Time_Delay(50);
      }
   }
   IF((counter_fan_driver % 4) == 3){
      counter_fan_driver_old           = counter_fan_driver;
      state_confirm_fan_driver_3       = FALSE;
      WHILE(!state_confirm_fan_driver_3){
         Data_Sender(DATA_FAN_DRIVER_3);
         Time_Delay(50);
      }
   }
}
//*************************************************************************************************************************************************//
//*******************************************************************WINDOW**CONTROL***************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Window(){
   IF(!state_error_window){
      IF((counter_window % 3) == 0){
         counter_window                = 0;
         counter_window_old            = counter_window;
         state_confirm_window          = FALSE;
         WHILE(!state_confirm_window){
            Data_Sender(DATA_WINDOW);
            Time_Delay(50);
         }
         WRITE_EEPROM(address_window , counter_window);
      }
      IF((counter_window % 3) == 1){
         counter_window                = 1;
         counter_window_old            = counter_window;
         state_confirm_face            = FALSE;
         WHILE(!state_confirm_face){
            Data_Sender(DATA_FACE);
            Time_Delay(50);
         }
         WRITE_EEPROM(address_window , counter_window);
      }
      IF((counter_window % 3) == 2){
         counter_window                = 2;
         counter_window_old            = counter_window;
         state_confirm_together        = FALSE;
         WHILE(!state_confirm_together){
            Data_Sender(DATA_TOGETHER);
            Time_Delay(50);
         }
         WRITE_EEPROM(address_window , counter_window);
      }
   }
   ELSE{
      OUTPUT_LOW(LED_WINDOW);
      OUTPUT_LOW(LED_FACE);
      OUTPUT_LOW(LED_TOGETHER);
   }
}
//*************************************************************************************************************************************************//
//********************************************************************AIR**CONTROL*****************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Air(){
   IF(!state_error_air){
      IF((counter_air % 2) == 0){
         counter_air                   = 0;
         counter_air_old               = counter_air;
         state_confirm_air_0           = FALSE;
         WHILE(!state_confirm_air_0){
            Data_Sender(DATA_AIR_0);
            Time_Delay(50);
         }
         WRITE_EEPROM(address_air , counter_air);
      }
      IF((counter_air % 2) == 1){
         counter_air_old               = counter_air;
         state_confirm_air_1           = FALSE;
         WHILE(!state_confirm_air_1){
            Data_Sender(DATA_AIR_1);
            Time_Delay(50);
         }
         WRITE_EEPROM(address_air , counter_air);
      }
   }
   ELSE{
      OUTPUT_LOW(LED_AIR);
   }
}
//*************************************************************************************************************************************************//
//******************************************************************VANA**CONTROL******************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Valve_Driver(){
   IF(!state_error_valve_driver){
      IF((counter_valve_driver % 4) == 0){
         counter_valve_driver          = 0;
         counter_valve_driver_old      = counter_valve_driver;
         state_confirm_valve_driver_0  = FALSE;
         WHILE(! state_confirm_valve_driver_0){
            Data_Sender(DATA_VALVE_DRIVER_0);
            Time_Delay(50);
         }
         WRITE_EEPROM(address_valve_driver , counter_valve_driver);
      }
      IF((counter_valve_driver % 4) == 1){
         counter_valve_driver          = 1;
         counter_valve_driver_old      = counter_valve_driver;
         state_confirm_valve_driver_1  = FALSE;
         WHILE(! state_confirm_valve_driver_1){
            Data_Sender(DATA_VALVE_DRIVER_1);
            Time_Delay(50);
         }
         WRITE_EEPROM(address_valve_driver , counter_valve_driver);
      }
      IF((counter_valve_driver % 4) == 2){
         counter_valve_driver          = 2;
         counter_valve_driver_old      = counter_valve_driver;
         state_confirm_valve_driver_2  = FALSE;
         WHILE(! state_confirm_valve_driver_2){
            Data_Sender(DATA_VALVE_DRIVER_2);
            Time_Delay(50);
         }
         WRITE_EEPROM(address_valve_driver , counter_valve_driver);
      }
      IF((counter_valve_driver % 4) == 3){
         counter_valve_driver          = 3;
         counter_valve_driver_old      = counter_valve_driver;
         state_confirm_valve_driver_3  = FALSE;
         WHILE(! state_confirm_valve_driver_3){
            Data_Sender(DATA_VALVE_DRIVER_3);
            Time_Delay(50);
         }
         WRITE_EEPROM(address_valve_driver , counter_valve_driver);
      }
   }
   ELSE{
      OUTPUT_LOW(LED_VALVE_DRIVER_0);
      OUTPUT_LOW(LED_VALVE_DRIVER_1);
      OUTPUT_LOW(LED_VALVE_DRIVER_2);
   }
}
//*************************************************************************************************************************************************//
//******************************************************************SEND**DATA*********************************************************************//
//*************************************************************************************************************************************************//
VOID Data_Sender(INT8 data_sender){
   putc(data_sender);
}
//*************************************************************************************************************************************************//
//****************************************************************RECEIVE**DATA********************************************************************//
//*************************************************************************************************************************************************//
VOID Data_Receiver(){
   IF(kbhit()){
      data_receive = getc();
      Assign_Controller_Counter_According_To_Coming_Data();
   }
}
//*************************************************************************************************************************************************//
//****************************************************ASSIGN**CONTROLLER**ACCORDING**TO**COMING**DATA**********************************************//
//*************************************************************************************************************************************************//
VOID Assign_Controller_Counter_According_To_Coming_Data(){
//********************************************************************************************************************************MAX**COUNTER**0**//
   IF(data_receive == DATA_CONFIRM_MAX_OFF){
      state_confirm_max_off                        = TRUE;
   }
//********************************************************************************************************************************MAX**COUNTER**1**//
   IF(data_receive == DATA_CONFIRM_MAX_ON){
      state_confirm_max_on                         = TRUE;
   }
//************************************************************************************************************************DRIVER**FAN**COUNTER**0**//
   IF(data_receive == DATA_CONFIRM_FAN_DRIVER_0){
      state_confirm_fan_driver_0                   = TRUE;
   }
//************************************************************************************************************************DRIVER**FAN**COUNTER**1**//
   IF(data_receive == DATA_CONFIRM_FAN_DRIVER_1){
      state_confirm_fan_driver_1                   = TRUE;
   }
//************************************************************************************************************************DRIVER**FAN**COUNTER**2**//
   IF(data_receive == DATA_CONFIRM_FAN_DRIVER_2){
      state_confirm_fan_driver_2                   = TRUE;
   }
//************************************************************************************************************************DRIVER**FAN**COUNTER**3**//
   IF(data_receive == DATA_CONFIRM_FAN_DRIVER_3){
      state_confirm_fan_driver_3                   = TRUE;
   }
//*****************************************************************************************************************************WINDOW**COUNTER**0**//
   IF(data_receive == DATA_CONFIRM_WINDOW){
      state_confirm_window                         = TRUE;
   }
//*******************************************************************************************************************************FACE**COUNTER**1**//
   IF(data_receive == DATA_CONFIRM_FACE){
      state_confirm_face                           = TRUE;
   }
//***************************************************************************************************************************TOGETHER**COUNTER**2**//
   IF(data_receive == DATA_CONFIRM_TOGETHER){
      state_confirm_together                       = TRUE;
   }
//********************************************************************************************************************************AIR**COUNTER**0**//
   IF(data_receive == DATA_CONFIRM_AIR_0){
      state_confirm_air_0                          = TRUE;
   }
//********************************************************************************************************************************AIR**COUNTER**1**//
   IF(data_receive == DATA_CONFIRM_AIR_1){
      state_confirm_air_1                          = TRUE;
   }
//**********************************************************************************************************************DRIVER**VALVE**COUNTER**0**//
   IF(data_receive == DATA_CONFIRM_VALVE_DRIVER_0){
      state_confirm_valve_driver_0                 = TRUE;
   }
//**********************************************************************************************************************DRIVER**VALVE**COUNTER**1**//
   IF(data_receive == DATA_CONFIRM_VALVE_DRIVER_1){
      state_confirm_valve_driver_1                 = TRUE;
   }
//**********************************************************************************************************************DRIVER**VALVE**COUNTER**2**//
   IF(data_receive == DATA_CONFIRM_VALVE_DRIVER_2){
      state_confirm_valve_driver_2                 = TRUE;
   }
//**********************************************************************************************************************DRIVER**VALVE**COUNTER**2**//
   IF(data_receive == DATA_CONFIRM_VALVE_DRIVER_3){
      state_confirm_valve_driver_3                 = TRUE;
   }
//**********************************************************************************************************************************ERROR**WINDOW**//
   IF(data_receive == DATA_RUN_TIME_ERROR_WINDOW){
      state_error_window                           = TRUE;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_RUN_TIME_ERROR_WINDOW);
      data_receive                                 = DATA_CHECK;
      state_controller_error_in_button_window      = TRUE;
   }
//*************************************************************************************************************************************ERROR**AIR**//
   IF(data_receive == DATA_RUN_TIME_ERROR_AIR){
      state_error_air                              = TRUE;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_RUN_TIME_ERROR_AIR);
      data_receive                                 = DATA_CHECK;
      state_controller_error_in_button_air         = TRUE;
   }
//***************************************************************************************************************************ERROR**VALVE**DRIVER**//
   IF(data_receive == DATA_RUN_TIME_ERROR_VALVE_DRIVER){
      state_error_valve_driver                     = TRUE;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_RUN_TIME_ERROR_VALVE_DRIVER);
      data_receive                                 = DATA_CHECK;
      state_controller_error_in_button_valve_driver = TRUE;
   }
//*****************************************************************************************************************************CORRECTION**WINDOW**//
   IF(data_receive == DATA_RUN_TIME_FIX_WINDOW){
      state_error_window                           = FALSE;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_RUN_TIME_FIX_WINDOW);
      data_receive                                 = DATA_CHECK;
      counter_window_old                           = MINUS_ONE;
   }
//********************************************************************************************************************************CORRECTION**AIR**//
   IF(data_receive == DATA_RUN_TIME_FIX_AIR){
      state_error_air                              = FALSE;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_RUN_TIME_FIX_AIR);
      data_receive                                 = DATA_CHECK;
      counter_air_old                              = MINUS_ONE;
   }
//**********************************************************************************************************************CORRECTION**VALVE**DRIVER**//
   IF(data_receive == DATA_RUN_TIME_FIX_VALVE_DRIVER){
      state_error_valve_driver                     = FALSE;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_RUN_TIME_FIX_VALVE_DRIVER);
      data_receive                                 = DATA_CHECK;
      counter_valve_driver_old                     = MINUS_ONE;
   }
}
//*************************************************************************************************************************************************//
//********************************************************************MAKE**A**DELAY***************************************************************//
//*************************************************************************************************************************************************//
//**********************************************************************EXPLANATION****************************************************************//
//*************************************************************************************************************************************************//
//************************************************************TIME_DELAY(1)**=**DELAY_MS(1)********************************************************//
//*************************************************************************************************************************************************//
VOID Time_Delay(INT32 value_time_delay){
   value_time_delay                                = (value_time_delay * 1000);
   time_delay_starting                             = get_ticks();
   time_delay_current                              = (get_ticks() + 10);
   time_delay_difference                           = Ticks_Difference(time_delay_starting , time_delay_current);
   WHILE(value_time_delay > time_delay_difference){
      time_delay_current                           = get_ticks();
      time_delay_difference                        = Ticks_Difference(time_delay_starting , time_delay_current);
      Data_Receiver();
   }
}
//*************************************************************************************************************************************************//
//***************************************************************RECEIVE**DATA**FOR**ERROR*********************************************************//
//*************************************************************************************************************************************************//
VOID Data_Receiver_Controller_Error(){
   IF(kbhit()){
      data_receive                                 = getc();
      Assign_Controller_Error_According_To_Coming_Data();
   }
}
//*************************************************************************************************************************************************//
//************************************************ASSIGN**CONTROLLER**ACCORDING**TO**COMING**DATA**FOR**ERROR**************************************//
//*************************************************************************************************************************************************//
VOID Assign_Controller_Error_According_To_Coming_Data(){
   IF(data_receive == DATA_CONTROL_START){
      state_communication_control_start            = FALSE;
   }
   IF(data_receive == DATA_ERROR_WINDOW){
      state_error_window                           = TRUE;
      state_show_error_window                      = TRUE;
      state_communication_window                   = FALSE;
   }
   IF(data_receive == DATA_NO_ERROR_WINDOW){
      state_error_window                           = FALSE;
      state_show_error_window                      = FALSE;
      state_communication_window                   = FALSE;
   }
   IF(data_receive == DATA_ERROR_AIR){
      state_error_air                              = TRUE;
      state_show_error_air                         = TRUE;
      state_communication_air                      = FALSE;
   }
   IF(data_receive == DATA_NO_ERROR_AIR){
      state_error_air                              = FALSE;
      state_show_error_air                         = FALSE;
      state_communication_air                      = FALSE;
   }
   IF(data_receive == DATA_ERROR_VALVE_DRIVER){
      state_error_valve_driver                     = TRUE;
      state_show_error_valve_driver                = TRUE;
      state_communication_valve_driver             = FALSE;
   }
   IF(data_receive == DATA_NO_ERROR_VALVE_DRIVER){
      state_error_valve_driver                     = FALSE;
      state_show_error_valve_driver                = FALSE;
      state_communication_valve_driver             = FALSE;
   }
   IF(data_receive == DATA_CONTROL_FINISH){
      state_communication_control_finish           = FALSE;
   }
   IF(data_receive == DATA_CONFIRM_SHOW_ERROR_FINISH){
      state_communication_show_error_finish        = FALSE;
   }
   IF(data_receive == DATA_CONFIRM_EEPROM_READ_START){
      state_confirm_eeprom_read_start              = TRUE;
   }
   IF(data_receive == DATA_CONFIRM_EEPROM_READ_FINISH){
      state_confirm_eeprom_read_finish             = TRUE;
   }
   IF(data_receive == DATA_CONFIRM_EEPROM_MAX){
      state_confirm_eeprom_max                     = TRUE;
   }
   IF(data_receive == DATA_CONFIRM_EEPROM_FAN_DRIVER){
      state_confirm_eeprom_fan_driver              = TRUE;
   }
   IF(data_receive == DATA_CONFIRM_EEPROM_WINDOW){
      state_confirm_eeprom_window                  = TRUE;
   }
   IF(data_receive == DATA_CONFIRM_EEPROM_AIR){
      state_confirm_eeprom_air                     = TRUE;
   }
   IF(data_receive == DATA_CONFIRM_EEPROM_VALVE_DRIVER){
      state_confirm_eeprom_valve_driver            = TRUE;
   }
}
//*************************************************************************************************************************************************//
//********************************************************************MAKE**A**DELAY***************************************************************//
//*************************************************************************************************************************************************//
//**********************************************************************EXPLANATION****************************************************************//
//*************************************************************************************************************************************************//
//************************************************************TIME_DELAY(1)**=**DELAY_MS(1)********************************************************//
//*************************************************************************************************************************************************//
VOID Time_Delay_Controller_Error(INT32 value_time_delay_controller_error){
   value_time_delay_controller_error = (value_time_delay_controller_error * 1000);
   time_delay_starting = get_ticks();
   time_delay_current = (get_ticks() + 10);
   time_delay_difference = Ticks_Difference(time_delay_starting , time_delay_current);
   WHILE(value_time_delay_controller_error > time_delay_difference){
      time_delay_current = get_ticks();
      time_delay_difference = Ticks_Difference(time_delay_starting , time_delay_current);
      Data_Receiver_Controller_Error();
   }
}
//*************************************************************************************************************************************************//
//**************************************************************MEASURE**TICKs**DIFFERENCE*********************************************************//
//*************************************************************************************************************************************************//
INT32 Ticks_Difference(INT32 time_starting, INT32 time_current){
   time_difference = (time_current - time_starting);
   RETURN time_difference;
}
//*************************************************************************************************************************************************//
//**************************************************************CONTROL**ERROR**IN**BUTTON*********************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Error_In_Button(){
//*************************************************************************************************************************************************//
      IF(state_controller_error_in_button_window){
         OUTPUT_HIGH(LED_WINDOW);
         OUTPUT_HIGH(LED_FACE);
         OUTPUT_HIGH(LED_TOGETHER);
         Time_Delay(40);
         OUTPUT_LOW(LED_WINDOW);
         OUTPUT_LOW(LED_FACE);
         OUTPUT_LOW(LED_TOGETHER);
         Time_Delay(20);
         OUTPUT_HIGH(LED_WINDOW);
         OUTPUT_HIGH(LED_FACE);
         OUTPUT_HIGH(LED_TOGETHER);
         Time_Delay(40);
         OUTPUT_LOW(LED_WINDOW);
         OUTPUT_LOW(LED_FACE);
         OUTPUT_LOW(LED_TOGETHER);
         state_controller_error_in_button_window = FALSE;
      }
//*************************************************************************************************************************************************//
      IF(state_controller_error_in_button_air){
         OUTPUT_HIGH(LED_AIR);
         Time_Delay(40);
         OUTPUT_LOW(LED_AIR);
         Time_Delay(20);
         OUTPUT_HIGH(LED_AIR);
         Time_Delay(40);
         OUTPUT_LOW(LED_AIR);
         state_controller_error_in_button_air = FALSE;
      }
//*************************************************************************************************************************************************//
      IF(state_controller_error_in_button_valve_driver){
         OUTPUT_HIGH(LED_VALVE_DRIVER_0);
         OUTPUT_HIGH(LED_VALVE_DRIVER_1);
         OUTPUT_HIGH(LED_VALVE_DRIVER_2);
         Time_Delay(40);
         OUTPUT_LOW(LED_VALVE_DRIVER_0);
         OUTPUT_LOW(LED_VALVE_DRIVER_1);
         OUTPUT_LOW(LED_VALVE_DRIVER_2);
         Time_Delay(20);
         OUTPUT_HIGH(LED_VALVE_DRIVER_0);
         OUTPUT_HIGH(LED_VALVE_DRIVER_1);
         OUTPUT_HIGH(LED_VALVE_DRIVER_2);
         Time_Delay(40);
         OUTPUT_LOW(LED_VALVE_DRIVER_0);
         OUTPUT_LOW(LED_VALVE_DRIVER_1);
         OUTPUT_LOW(LED_VALVE_DRIVER_2);
         state_controller_error_in_button_valve_driver = FALSE;
      }
   }
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
//*********************************************************************END*************************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
