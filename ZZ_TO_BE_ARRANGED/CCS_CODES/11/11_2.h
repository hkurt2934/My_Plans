////***********************************************************************************************************************************************//
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
#DEFINE VALUE_TRIS_A                                           0x20
#DEFINE VALUE_TRIS_B                                           0xC0
#DEFINE VALUE_TRIS_C                                           0x80
#DEFINE VALUE_TRIS_D                                           0x00
#DEFINE VALUE_TRIS_E                                           0x08
//********************************************************************************************************************************ADDRESS**VALUEs**//
#DEFINE VALUE_ADDRESS_WINDOW                                   0x01
#DEFINE VALUE_ADDRESS_AIR                                      0x02
#DEFINE VALUE_ADDRESS_VALVE_DRIVER                             0x03
//********************************************************************************************************************************CURRENT**VALUEs**//
#DEFINE VALUE_SIDE_CURRENT_WINDOW                              40
#DEFINE VALUE_SIDE_CURRENT_AIR                                 40
#DEFINE VALUE_SIDE_CURRENT_VALVE_DRIVER                        40
#DEFINE VALUE_SIDE_CURRENT_TEST                                15
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
//******************************************************************************************************************************FAN**DRIVER**PINs**//
#DEFINE FAN_DRIVER_STEP_1                                      PIN_B2
#DEFINE FAN_DRIVER_STEP_2                                      PIN_B0
#DEFINE FAN_DRIVER_STEP_3                                      PIN_B1
//**************************************************************************************************************************************CAM**Pins**//
#DEFINE WINDOW_EN                                              PIN_C5
#DEFINE WINDOW_IN_1                                            PIN_D3
#DEFINE WINDOW_IN_2                                            PIN_C4
//******************************************************************************************************************************Temiz**Hava**Pins**//
#DEFINE AIR_EN_1                                               PIN_C5
#DEFINE AIR_EN_2                                               PIN_D2
#DEFINE AIR_IN_1_1                                             PIN_C4
#DEFINE AIR_IN_1_2                                             PIN_D3
#DEFINE AIR_IN_2_1                                             PIN_D1
#DEFINE AIR_IN_2_2                                             PIN_D0
//*************************************************************************************************************************************VANA**Pins**//
#DEFINE VALVE_DRIVER_EN                                        PIN_D2
#DEFINE VALVE_DRIVER_IN_1                                      PIN_D0
#DEFINE VALVE_DRIVER_IN_2                                      PIN_D1
//*******************************************************************************************************************************CURRENT**CONTROL**//
#DEFINE CURRENT_PORT_VALVE_DRIVER                              PIN_A5
//**************************************************************************************************************************************ADC**Pins**//
#DEFINE CURRENT_ADC_L293DD                                     sAN4
//***********************************************************************************************************************************ADC**Channel**//
#DEFINE CURRENT_CHANNEL_L293DD                                 4
//********************************************************************************************************************************POMP-KLIMA**OUT**//
#DEFINE POMP_OUT                                               PIN_B5
//*****************************************************************************************************************************TIME**POMP**VALUEs**//
#DEFINE TIME_POMP_ON                                           (2000 * 1000)
//*************************************************************************************************************************************************//
//*******************************************************************FUNCTIONs*********************************************************************//
//*************************************************************************************************************************************************//
//********************************************************************************************************************************MAIN**FUNCTIONs**//
VOID Setting();
VOID Controller_Klape();
VOID Controller_Klape_Error();
VOID Time_Klape_Once_Window();
VOID Time_Klape_Once_Air();
VOID Time_Klape_Once_Valve_Driver();
VOID Make_Default_Values();
VOID Receive_EEPROM_Data();
VOID Work_According_To_EEPROM();
//*****************************************************************************************************************************RECEIVE-SEND**DATA**//
VOID Data_Receiver();
VOID Data_Receiver_Controller_Klape_Error();
VOID Data_Sender(INT8);
//************************************************************************************************ASSIGN**CONTROLLER**ACCORDING**TO**COMING**DATA**//
VOID Assign_Controller_Counter_According_To_Coming_Data();
VOID Assign_Controller_Klape_Error_According_To_Coming_Data();
//**************************************************************************************************************************CONTROLLER**FUNCTIONs**//
VOID Controller_Error();
VOID Controller_Functions_1();
VOID Controller_Functions_2();
VOID Controller_Fan_Driver();
VOID Controller_Window();
VOID Controller_Air();
VOID Controller_Valve_Driver();
VOID Controller_Pomp();
VOID Controller_Time_Pomp();
VOID Controller_Time_In_While_Window();
VOID Controller_Time_In_While_Air();
VOID Controller_Time_In_While_Valve_Driver();
//**************************************************************************************************************************************READ**ADC**//
VOID Read_Current_L293DD();
//*************************************************************************************************************************TURN**MOTOR**FUNCTIONs**//
VOID Turn_Left_Window();
VOID Turn_Right_Window();
VOID Stop_Window();
VOID Turn_Left_Air();
VOID Turn_Right_Air();
VOID Stop_Air();
VOID Turn_Left_Valve_Driver();
VOID Turn_Right_Valve_Driver();
VOID Stop_Valve_Driver();
//************************************************************************************************************************************TIME**DELAY**//
VOID Time_Delay(INT32);
VOID Time_Delay_Controller_Klape_Error(INT32);
//*******************************************************************************************************************************TICK**DIFFERENCE**//
INT32 Ticks_Difference(INT32,INT32);
//*************************************************************************************************************************************************//
//*******************************************************************VARIABLEs*********************************************************************//
//*************************************************************************************************************************************************//
//********************************************************************************************************************************DATA**VARIABLEs**//
SIGNED INT8 data_receive                                       = ALL_ZERO_8_BIT;
//***************************************************************************************************************************************COUNTERs**//
SIGNED INT8 counter_max                                        = ALL_ZERO_8_BIT;
SIGNED INT8 counter_fan_driver                                 = ALL_ZERO_8_BIT;
SIGNED INT8 counter_window                                     = ALL_ZERO_8_BIT;  
SIGNED INT8 counter_air                                        = ALL_ZERO_8_BIT;
SIGNED INT8 counter_valve_driver                               = ALL_ZERO_8_BIT; 
//**********************************************************************************************************************************OLD**COUNTERs**//
SIGNED INT8 counter_fan_driver_old                             = MINUS_ONE;
SIGNED INT8 counter_window_old                                 = MINUS_ONE;
SIGNED INT8 counter_air_old                                    = MINUS_ONE;
SIGNED INT8 counter_valve_driver_old                           = MINUS_ONE;
//*******************************************************************************************************************************STATUS**COUNTERs**//
SIGNED INT8 counter_window_status                              = ALL_ZERO_8_BIT;
SIGNED INT8 counter_valve_driver_status                        = ALL_ZERO_8_BIT;
//***************************************************************************************************************************************COUNTERs**//
SIGNED INT8 counter_temporary                                  = ALL_ZERO_8_BIT;
SIGNED INT8 counter_temporary_2                                = ALL_ZERO_8_BIT;
//*****************************************************************************************************************************COUNTER**VARIABLEs**//
INT16 counter_klape_window                                     = ALL_ZERO_16_BIT;
INT16 counter_klape_air                                        = ALL_ZERO_16_BIT;
INT16 counter_klape_valve_driver                               = ALL_ZERO_16_BIT;
//*********************************************************************************************************************************ADC**VARIABLEs**//
INT16 value_current_l293dd                                     = ALL_ZERO_16_BIT;
INT16 value_current_temporary                                  = ALL_ZERO_16_BIT;
//********************************************************************************************************************************TIME**VARIABLEs**//
UNSIGNED INT32 time_difference                                 = ALL_ZERO_32_BIT;
//********************************************************************************************************************************TIME**VARIABLEs**//
UNSIGNED INT32 time_window_starting                            = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_window_current                             = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_window_difference                          = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_window_difference_error                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_window_controller                          = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_window_mid                                 = ALL_ZERO_32_BIT;
//********************************************************************************************************************************TIME**VARIABLEs**//
UNSIGNED INT32 time_air_starting                               = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_air_current                                = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_air_difference                             = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_air_difference_error                       = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_air_controller                             = ALL_ZERO_32_BIT;
//********************************************************************************************************************************TIME**VARIABLEs**//
UNSIGNED INT32 time_valve_driver_starting                      = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_driver_current                       = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_driver_difference                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_driver_difference_error              = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_driver_controller                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_driver_mid_50                        = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_driver_mid_75                        = ALL_ZERO_32_BIT;
//********************************************************************************************************************************TIME**VARIABLEs**//
UNSIGNED INT32 time_delay_starting                             = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_delay_current                              = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_delay_difference                           = ALL_ZERO_32_BIT;
//********************************************************************************************************************************TIME**VARIABLEs**//
UNSIGNED INT32 time_in_while_window_starting                   = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_window_current                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_window_difference                 = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_air_starting                      = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_air_current                       = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_air_difference                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_valve_driver_starting             = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_valve_driver_current              = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_valve_driver_difference           = ALL_ZERO_32_BIT;
//********************************************************************************************************************************TIME**VARIABLEs**//
UNSIGNED INT32 time_controller_pomp_starting                   = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_controller_pomp_current                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_controller_pomp_difference                 = ALL_ZERO_32_BIT;
//*************************************************************************************************************************************************//
//*************************************************************BOOLEAN**VARIABLEs******************************************************************//
//*************************************************************************************************************************************************//
//************************************************************************************************************CONTROLLER**KLAPE**VARIABLEs**STATE**//
BOOLEAN state_error_window                                     = FALSE;
BOOLEAN state_error_air                                        = FALSE;
BOOLEAN state_error_valve_driver                               = FALSE;
//************************************************************************************************************CONTROLLER**KLAPE**VARIABLEs**STATE**//
BOOLEAN state_controller_klape_error_window                    = FALSE;
BOOLEAN state_controller_klape_error_air                       = FALSE;
BOOLEAN state_controller_klape_error_valve_driver              = FALSE;
//*******************************************************************************************************************SCAN**KLAPE**TIME**VARIABLEs**//
BOOLEAN state_scan_klape_time                                  = TRUE;
//*************************************************************************************************************************************************//
BOOLEAN state_time_klape_once_window                           = FALSE;
BOOLEAN state_time_klape_once_air                              = FALSE;
BOOLEAN state_time_klape_once_valve_driver                     = FALSE;
//*************************************************************************************************************************************************//
BOOLEAN state_time_klape_once_turn_complete_window             = FALSE;
BOOLEAN state_time_klape_once_turn_complete_air                = FALSE;
BOOLEAN state_time_klape_once_turn_complete_valve_driver       = FALSE;
//*************************************************************************************************************************************************//
BOOLEAN state_communication_control_start                      = FALSE;
BOOLEAN state_communication_window                             = FALSE;
BOOLEAN state_communication_air                                = FALSE;
BOOLEAN state_communication_valve_driver                       = FALSE;
BOOLEAN state_communication_control_finish                     = FALSE;
BOOLEAN state_communication_show_error_finish                  = FALSE;
//********************************************************************************************************CONTROLLER**FUNCTIONS**VARIABLEs**STATE**//
BOOLEAN state_turn_complete_window                             = FALSE;
BOOLEAN state_turn_complete_air                                = FALSE;
BOOLEAN state_turn_complete_valve_driver                       = FALSE;
//*******************************************************************************************************************CONTROLLER**ERROR**VARIABLEs**//
BOOLEAN state_controller_error_in_while_loop_window            = FALSE;
BOOLEAN state_controller_error_in_while_loop_air               = FALSE;
BOOLEAN state_controller_error_in_while_loop_valve_driver      = FALSE;
//********************************************************************************************************************************TIME**VARIABLEs**//
BOOLEAN state_time_in_while_window                             = FALSE;
BOOLEAN state_time_in_while_start_window                       = FALSE;
BOOLEAN state_time_in_while_air                                = FALSE;
BOOLEAN state_time_in_while_start_air                          = FALSE;
BOOLEAN state_time_in_while_valve_driver                       = FALSE;
BOOLEAN state_time_in_while_start_valve_driver                 = FALSE;
//********************************************************************************************************************************POMP**VARIABLEs**//
BOOLEAN state_process_complete_pomp                            = FALSE;
BOOLEAN state_controller_pomp_on                               = FALSE;
//*************************************************************************************************************************************************//
BOOLEAN state_confirm_run_time_fix_window                      = FALSE;
BOOLEAN state_confirm_run_time_fix_air                         = FALSE;
BOOLEAN state_confirm_run_time_fix_valve_driver                = FALSE;
//*************************************************************************************************************************************************//
BOOLEAN state_confirm_run_time_error_window                    = FALSE;
BOOLEAN state_confirm_run_time_error_air                       = FALSE;
BOOLEAN state_confirm_run_time_error_valve_driver              = FALSE;
//*************************************************************************************************************************************************//
BOOLEAN state_eeprom_read_start                                = FALSE;
BOOLEAN state_eeprom_read_finish                               = FALSE;
//*************************************************************************************************************************************************//
BOOLEAN state_error_valve_driver_in_status                     = FALSE;
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
//****************************************************************************************************************************SETTING**ADC**PORTs**//
   SETUP_ADC_PORTS(CURRENT_ADC_L293DD | VSS_VDD);
   SETUP_ADC(RTCC_INTERNAL | ADC_CLOCK_DIV_8);
   DELAY_MS(2);
//*********************************************************************************************************************************TICKs**DEFAULT**//
   set_ticks(0);
}
//*************************************************************************************************************************************************//
//******************************************************************KLAPE**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Klape(){
//**********************************************************************************************************************************MAKE**DEFAULT**//
   state_error_window                                       = TRUE;
   state_error_air                                          = TRUE;
   state_error_valve_driver                                 = TRUE;
   state_time_klape_once_window                             = TRUE;
   state_time_klape_once_air                                = TRUE;
   state_time_klape_once_valve_driver                       = TRUE;
   state_controller_klape_error_window                      = TRUE;
   state_controller_klape_error_air                         = TRUE;
   state_controller_klape_error_valve_driver                = TRUE;
   state_controller_error_in_while_loop_window              = TRUE;
   state_controller_error_in_while_loop_air                 = TRUE;
   state_controller_error_in_while_loop_valve_driver        = TRUE;
//**********************************************************************************************************************************WINDOW**ERROR**//
   Turn_Right_Window();
   DELAY_MS(250);
   FOR(counter_klape_window = 0; counter_klape_window < 300; counter_klape_window++){
      Turn_Right_Window();
      DELAY_MS(20);
      Read_Current_L293DD();
      IF(value_current_l293dd > VALUE_SIDE_CURRENT_WINDOW){
         state_error_window                                 = FALSE;
         state_turn_complete_window                         = FALSE;
         state_controller_klape_error_window                = FALSE;
         state_controller_error_in_while_loop_window        = FALSE;
         state_time_klape_once_window                       = FALSE;
         counter_klape_window                               = 300;
         Stop_Window();
         DELAY_MS(20);
      }
   }
//***********************************************************************************************************************************WINDOW**TIME**//
   IF(!state_error_window){
      Turn_Left_Window();
      DELAY_MS(250);
      time_window_starting                                  = get_ticks();
      state_scan_klape_time                                 = TRUE;
      WHILE(state_scan_klape_time){
         time_window_current                                = get_ticks();
         Turn_Left_Window();
         Read_Current_L293DD();
         IF(value_current_l293dd > VALUE_SIDE_CURRENT_WINDOW){
            state_scan_klape_time                           = FALSE;
            Stop_Window();
            DELAY_MS(20);
         }
      }
   }
//*****************************************************************************************************************************MID**VALUE**WINDOW**//
   IF(!state_error_window){
      time_window_difference                    = Ticks_Difference(time_window_starting , time_window_current);
      time_window_controller                    = (abs(time_window_difference - (200 * 1000)));
      time_window_difference_error              = (2 * time_window_difference);
      time_window_mid                           = (abs((time_window_difference / 2) - (300 * 1000)));
   }
//*************************************************************************************************************************************AIR**ERROR**//
   Turn_Right_Air();
   DELAY_MS(250);
   FOR(counter_klape_air = 0; counter_klape_air < 300; counter_klape_air++){
      Turn_Right_Air();
      DELAY_MS(20);
      Read_Current_L293DD();
      IF(value_current_l293dd > VALUE_SIDE_CURRENT_AIR){
         state_error_air                                    = FALSE;
         state_turn_complete_air                            = FALSE;
         state_controller_klape_error_air                   = FALSE;
         state_controller_error_in_while_loop_air           = FALSE;
         state_time_klape_once_air                          = FALSE;
         counter_klape_air                                  = 300;
         Stop_Air();
         DELAY_MS(20);
      }
   }
//**************************************************************************************************************************************AIR**TIME**//
   IF(!state_error_air){
      state_scan_klape_time                                 = TRUE;
      Turn_Left_Air();
      DELAY_MS(250);
      time_air_starting                                     = get_ticks();
      WHILE(state_scan_klape_time){
         time_air_current                                   = get_ticks();
         Turn_Left_Air();
         Read_Current_L293DD();
         IF(value_current_l293dd > VALUE_SIDE_CURRENT_AIR){
            state_scan_klape_time                           = FALSE;
            Stop_Air();
            DELAY_MS(20);
         }
      }
   }
//********************************************************************************************************************************MID**VALUE**AIR**//
   IF(!state_error_air){
      time_air_difference                       = Ticks_Difference(time_air_starting , time_air_current);
      time_air_controller                       = (abs(time_air_difference - (200 * 1000)));
      time_air_difference_error                 = (2 * time_air_difference);
   }
//***************************************************************************************************************************DRIVER**VALVE**ERROR**//
   Turn_Right_Valve_Driver();
   DELAY_MS(250);
   FOR(counter_klape_valve_driver = 0; counter_klape_valve_driver < 300; counter_klape_valve_driver++){
      Turn_Right_Valve_Driver();
      DELAY_MS(20);
      Read_Current_L293DD();
      IF(value_current_l293dd > VALUE_SIDE_CURRENT_VALVE_DRIVER){
         state_error_valve_driver                           = FALSE;
         state_turn_complete_valve_driver                   = FALSE;
         state_controller_klape_error_valve_driver          = FALSE;
         state_controller_error_in_while_loop_valve_driver  = FALSE;
         state_time_klape_once_valve_driver                 = FALSE;
         counter_klape_valve_driver                         = 300;
         Stop_Valve_Driver();
         DELAY_MS(20);
      }
   }
//****************************************************************************************************************************VALVE**DRIVER**TIME**//
   IF(!state_error_valve_driver){
      state_scan_klape_time                                 = TRUE;
      Turn_Left_Valve_Driver();
      DELAY_MS(250);
      time_valve_driver_starting                            = get_ticks();
      WHILE(state_scan_klape_time){
         time_valve_driver_current                          = get_ticks();
         Turn_Left_Valve_Driver();
         Read_Current_L293DD();
         IF(value_current_l293dd > VALUE_SIDE_CURRENT_VALVE_DRIVER){
            state_scan_klape_time                           = FALSE;
            Stop_Valve_Driver();
            DELAY_MS(20);
         }
      }
   }
//**********************************************************************************************************************MID**VALUE**VALVE**DRIVER**//
   IF(!state_error_valve_driver){
      time_valve_driver_difference              = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
      time_valve_driver_controller              = (abs(time_valve_driver_difference - (200 * 1000)));
      time_valve_driver_difference_error        = (2 * time_valve_driver_difference);
      time_valve_driver_mid_50                  = (time_valve_driver_difference / 2);
      time_valve_driver_mid_75                  = ((time_valve_driver_difference / 4) * 3);
   }
}
//*************************************************************************************************************************************************//
//***********************************************************CONTROLLER**KLAPE**ERROR**************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Klape_Error(){
//*****************************************************************************************************SEND**DATA**THAT**CONROLLING**IS**STARTING**//
   state_communication_control_start = TRUE;
   WHILE(state_communication_control_start){
      Data_Sender(DATA_CONTROL_START);
      Time_Delay_Controller_Klape_Error(50);
   }
//****************************************************************************************************************************CONTROL**CAM**ERROR**//
   state_communication_window = TRUE;
   WHILE(state_communication_window){
      IF(state_error_window){
         Data_Sender(DATA_ERROR_WINDOW);
      }
      IF(!state_error_window){
         Data_Sender(DATA_NO_ERROR_WINDOW);
      }
      Time_Delay_Controller_Klape_Error(50);
   }
//********************************************************************************************************************CONTROL**TEMIZ**HAVA**ERROR**//
   state_communication_air = TRUE;
   WHILE(state_communication_air){
      IF(state_error_air){
         Data_Sender(DATA_ERROR_AIR);
      }
      IF(!state_error_air){
         Data_Sender(DATA_NO_ERROR_AIR);
      }
      Time_Delay_Controller_Klape_Error(50);
   }
//***************************************************************************************************************************CONTROL**VANA**ERROR**//
   state_communication_valve_driver = TRUE;
   WHILE(state_communication_valve_driver){
      IF(state_error_valve_driver){
         Data_Sender(DATA_ERROR_VALVE_DRIVER);
      }
      IF(!state_error_valve_driver){
         Data_Sender(DATA_NO_ERROR_VALVE_DRIVER);
      }
      Time_Delay_Controller_Klape_Error(50);
   }
//*****************************************************************************************************SEND**DATA**THAT**CONROLLING**IS**FINISHED**//
   state_communication_control_finish = TRUE;
   WHILE(state_communication_control_finish){
      Data_Sender(DATA_CONTROL_FINISH);
      Time_Delay_Controller_Klape_Error(50);
   }
//*********************************************************************************************************************************START**PROGRAM**//
   state_communication_show_error_finish = TRUE;
   WHILE(state_communication_show_error_finish){
      Time_Delay_Controller_Klape_Error(50);
   }
   Data_Sender(DATA_CONFIRM_SHOW_ERROR_FINISH);
}
//*************************************************************************************************************************************************//
//***************************************************************MAKE**DEFAULT**VALUES*************************************************************//
//*************************************************************************************************************************************************//
VOID Make_Default_Values(){
   counter_max                      = ALL_ZERO_8_BIT;
   counter_fan_driver               = ALL_ZERO_8_BIT;
   counter_window                   = ALL_ZERO_8_BIT;
   counter_air                      = ALL_ZERO_8_BIT;
   counter_valve_driver             = ALL_ZERO_8_BIT;
   counter_window_status            = ALL_ZERO_8_BIT;
   counter_valve_driver_status      = ALL_ZERO_8_BIT;
   counter_fan_driver_old           = MINUS_ONE;
   counter_window_old               = MINUS_ONE;
   counter_air_old                  = MINUS_ONE;
   counter_valve_driver_old         = MINUS_ONE;
}
//*************************************************************************************************************************************************//
//***************************************************************RECEIVE**EEPROM**DATA*************************************************************//
//*************************************************************************************************************************************************//
VOID Receive_EEPROM_Data(){
   state_eeprom_read_start = FALSE;
   WHILE(!state_eeprom_read_start){
      Data_Receiver_Controller_Klape_Error();
   }
   state_eeprom_read_finish = FALSE;
   WHILE(!state_eeprom_read_finish){
      Data_Receiver_Controller_Klape_Error();
   }
}
//*************************************************************************************************************************************************//
//************************************************************WORK**ACCORDING**TO**EEPROM**********************************************************//
//*************************************************************************************************************************************************//
VOID Work_According_To_EEPROM(){
//*************************************************************************************************************************************************//
   Controller_Error();
//*************************************************************************************************************************************************//
   Controller_Fan_Driver();
//*************************************************************************************************************************************************//
   Controller_Window();
//*************************************************************************************************************************************************//
   Controller_Air();
//*************************************************************************************************************************************************//
   Controller_Valve_Driver();
//*************************************************************************************************************************************************//
   Controller_Pomp();
   Controller_Time_Pomp();
//*************************************************************************************************************************************************//
}
//*************************************************************************************************************************************************//
//**************************************************************CONTROLLER**FUNCTIONS**1***********************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Functions_1(){
//*************************************************************************************************************************************************//
   Controller_Error();
//************************************************************************************************************************************DRIVER**FAN**//
   IF(!(counter_fan_driver == counter_fan_driver_old)){
      Controller_Fan_Driver();
   }
}
//*************************************************************************************************************************************************//
//**************************************************************CONTROLLER**FUNCTIONS**2***********************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Functions_2(){
//****************************************************************************************************************************************WINDOIW**//
   IF(!state_error_window){
      IF(!(counter_window == counter_window_old)){
         Controller_Window();
      }
   }
//********************************************************************************************************************************************AIR**//
   IF(!state_error_air){
      IF(!(counter_air == counter_air_old)){
         Controller_Air();
      }
   }
//*************************************************************************************************************************************************//
   Controller_Pomp();
   Controller_Time_Pomp();
//**********************************************************************************************************************************VALVE**DRIVER**//
   IF(!state_error_valve_driver){
      IF(!(counter_valve_driver == counter_valve_driver_old)){
         Controller_Valve_Driver();
      }
   }
}
//*************************************************************************************************************************************************//
//**************************************************************DRIVER**FAN**CONTROLLER************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Fan_Driver(){
//*************************************************************************************************************************************COUNTER**0**//
   IF((counter_fan_driver % 4) == 0){
      counter_fan_driver            = 0;
      counter_fan_driver_old        = counter_fan_driver;
      OUTPUT_LOW(FAN_DRIVER_STEP_1);
      OUTPUT_LOW(FAN_DRIVER_STEP_2);
      OUTPUT_LOW(FAN_DRIVER_STEP_3);
   }
//*************************************************************************************************************************************COUNTER**1**//
   IF((counter_fan_driver % 4) == 1){
      counter_fan_driver_old        = counter_fan_driver;
      OUTPUT_HIGH(FAN_DRIVER_STEP_1);
      OUTPUT_LOW(FAN_DRIVER_STEP_2);
      OUTPUT_LOW(FAN_DRIVER_STEP_3);
   }
//*************************************************************************************************************************************COUNTER**2**//
   IF((counter_fan_driver % 4) == 2){
      counter_fan_driver_old        = counter_fan_driver;
      OUTPUT_HIGH(FAN_DRIVER_STEP_1);
      Time_Delay(500);
      OUTPUT_HIGH(FAN_DRIVER_STEP_2);
      OUTPUT_LOW(FAN_DRIVER_STEP_3);
   }
//*************************************************************************************************************************************COUNTER**3**//
   IF((counter_fan_driver % 4) == 3){
      counter_fan_driver_old        = counter_fan_driver;
      OUTPUT_HIGH(FAN_DRIVER_STEP_1);
      Time_Delay(500);
      OUTPUT_HIGH(FAN_DRIVER_STEP_2);
      Time_Delay(500);
      OUTPUT_HIGH(FAN_DRIVER_STEP_3);
   }
}
//*************************************************************************************************************************************************//
//******************************************************************WINDOW**CONTROLLER*************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Window(){
//*******************************************************************************************************************************WINDOW**POSITION**//
   IF((counter_window % 3) == 0){
      counter_window                                           = 0;
      counter_window_old                                       = counter_window;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
      IF(!state_error_window){
         Turn_Left_Window();
         Time_Delay(200);
         time_in_while_window_starting                         = get_ticks();
         Time_Delay(50);
         state_time_in_while_window                            = TRUE;
         state_time_in_while_start_window                      = TRUE;
         time_window_starting                                  = get_ticks();
         state_turn_complete_window                            = FALSE;
         WHILE(!state_turn_complete_window){
            time_window_current                                = get_ticks();
            time_window_difference                             = Ticks_Difference(time_window_starting , time_window_current);
            Turn_Left_Window();
            Time_Delay(20);
            Read_Current_L293DD();
            IF(value_current_l293dd > VALUE_SIDE_CURRENT_WINDOW){
               IF(time_window_difference > time_window_controller){
                  Stop_Window();
                  Time_Delay(20);
                  state_turn_complete_window                   = TRUE;
                  state_time_in_while_window                   = FALSE;
                  state_time_in_while_start_window             = FALSE;
                  counter_window_status                        = 0;
               }
            }
            Controller_Time_In_While_Window();
         }
      }
   }
//************************************************************************************************************************************YUZ**KONUMU**//
   IF((counter_window % 3) == 1){
      counter_window_old                                       = counter_window;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
      IF(!state_error_window){
         Turn_Right_Window();
         Time_Delay(200);
         time_in_while_window_starting                         = get_ticks();
         Time_Delay(50);
         state_time_in_while_window                            = TRUE;
         state_time_in_while_start_window                      = TRUE;
         time_window_starting                                  = get_ticks();
         state_turn_complete_window                            = FALSE;
         WHILE(!state_turn_complete_window){
            time_window_current                                = get_ticks();
            time_window_difference                             = Ticks_Difference(time_window_starting , time_window_current);
            Turn_Right_Window();
            Time_Delay(20);
            Read_Current_L293DD();
            IF(value_current_l293dd > VALUE_SIDE_CURRENT_WINDOW){
               IF(time_window_difference > time_window_controller){
                  Stop_Window();
                  Time_Delay(20);
                  state_turn_complete_window                   = TRUE;
                  state_time_in_while_window                   = FALSE;
                  state_time_in_while_start_window             = FALSE;
                  counter_window_status                        = 1;
               }
            }
            Controller_Time_In_While_Window();
         }
      }
   }
//********************************************************************************************************************************BERABER**KONUMU**//
   IF((counter_window % 3) == 2){
      counter_window_old                                       = counter_window;
//***************************************************************************************************************IF**COME**FROM**WINDOW**POSITION**//
      IF((counter_window_status % 3) == 0){
         Turn_Left_Window();
         Time_Delay(250);
         Read_Current_L293DD();
         Stop_Window();
         Time_Delay(20);
//*************************************************************************************************************************************************//
         IF(value_current_l293dd < VALUE_SIDE_CURRENT_TEST){
            state_error_window                                 = TRUE;
            state_controller_error_in_while_loop_window        = TRUE;
//*************************************************************************************************************************************************//
            state_confirm_run_time_error_window                = FALSE;
            WHILE(!state_confirm_run_time_error_window){
               Data_Sender(DATA_RUN_TIME_ERROR_WINDOW);
               Time_Delay(50);
            }
         }
         ELSE{
            state_error_window                                 = FALSE;
            state_controller_error_in_while_loop_window        = FALSE;
         }
         IF(!state_error_window){
            Turn_Right_Window();
            Time_Delay(250);
            time_window_starting                               = get_ticks();
            state_turn_complete_window                         = FALSE;
            WHILE(!state_turn_complete_window){
               Data_Receiver();
               time_window_current                             = get_ticks();
               time_window_difference                          = Ticks_Difference(time_window_starting , time_window_current);
               Turn_Right_Window();
               IF(time_window_difference > (time_window_mid)){
                  Stop_Window();
                  Time_Delay(20);
                  state_turn_complete_window                   = TRUE;
                  counter_window_status                        = 2;
               }
            }
         }
      }
//*****************************************************************************************************************IF**COME**FROM**FACE**POSITION**//
      IF((counter_window_status % 3) == 1){
         Turn_Right_Window();
         Time_Delay(250);
         Read_Current_L293DD();
         Stop_Window();
         Time_Delay(20);
//*************************************************************************************************************************************************//
         IF(value_current_l293dd < VALUE_SIDE_CURRENT_TEST){
            state_error_window                                 = TRUE;
            state_controller_error_in_while_loop_window        = TRUE;
//*************************************************************************************************************************************************//
            state_confirm_run_time_error_window                = FALSE;
            WHILE(!state_confirm_run_time_error_window){
               Data_Sender(DATA_RUN_TIME_ERROR_WINDOW);
               Time_Delay(50);
            }
         }
         ELSE{
            state_error_window                                 = FALSE;
            state_controller_error_in_while_loop_window        = FALSE;
         }
         IF(!state_error_window){
            Turn_Left_Window();
            Time_Delay(250);
            time_window_starting                               = get_ticks();
            state_turn_complete_window                         = FALSE;
            WHILE(!state_turn_complete_window){
               Data_Receiver();
               time_window_current                             = get_ticks();
               time_window_difference                          = Ticks_Difference(time_window_starting , time_window_current);
               Turn_Left_Window();
               IF(time_window_difference > (time_window_mid)){
                  Stop_Window();
                  Time_Delay(20);
                  state_turn_complete_window                   = TRUE;
                  counter_window_status                        = 2;
               }
            }
         }
      }
   }
}
//*************************************************************************************************************************************************//
//************************************************************TEMIZ**HAVA**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Air(){
//*************************************************************************************************************************************COUNTER**0**//
   IF((counter_air % 2) == 0){
      counter_air                                              = 0;
      counter_air_old                                          = counter_air;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
      IF(!state_error_air){
         Turn_Left_Air();
         Time_Delay(200);
         time_in_while_air_starting                            = get_ticks();
         Time_Delay(50);
         state_time_in_while_air                               = TRUE;
         state_time_in_while_start_air                         = TRUE;
         time_air_starting                                     = get_ticks();
         state_turn_complete_air                               = FALSE;
         WHILE(!state_turn_complete_air){
            time_air_current                                   = get_ticks();
            time_air_difference                                = Ticks_Difference(time_air_starting , time_air_current);
            Turn_Left_Air();
            Time_Delay(20);
            Read_Current_L293DD();
            IF(value_current_l293dd > VALUE_SIDE_CURRENT_AIR){
               IF(time_air_difference > time_air_controller){
                  Stop_Air();
                  Time_Delay(20);
                  state_turn_complete_air                      = TRUE;
                  state_time_in_while_air                      = FALSE;
                  state_time_in_while_start_air                = FALSE;
               }
            }
            Controller_Time_In_While_Air();
         }
      }
   }
//*************************************************************************************************************************************COUNTER**1**//
   IF((counter_air % 2) == 1){
      counter_air_old                                          = counter_air;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
      IF(!state_error_air){
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
         Turn_Right_Air();
         Time_Delay(200);
         time_in_while_air_starting                            = get_ticks();
         Time_Delay(50);
         state_time_in_while_air                               = TRUE;
         state_time_in_while_start_air                         = TRUE;
         time_air_starting                                     = get_ticks();
         state_turn_complete_air                               = FALSE;
         WHILE(!state_turn_complete_air){
            time_air_current                                   = get_ticks();
            time_air_difference                                = Ticks_Difference(time_air_starting , time_air_current);
            Turn_Right_Air();
            Time_Delay(20);
            Read_Current_L293DD();
            IF(value_current_l293dd > VALUE_SIDE_CURRENT_AIR){
               IF(time_air_difference > time_air_controller){
                  Stop_Air();
                  Time_Delay(20);
                  state_turn_complete_air                      = TRUE;
                  state_time_in_while_air                      = FALSE;
                  state_time_in_while_start_air                = FALSE;
               }
            }
            Controller_Time_In_While_Air();
         }
      }
   }
}
//*************************************************************************************************************************************************//
//******************************************************************VANA**CONTROLLER***************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Valve_Driver(){
//*************************************************************************************************************************************COUNTER**0**//
      IF((counter_valve_driver % 4) == 0){
         counter_valve_driver                                     = 0;
         counter_valve_driver_old                                 = counter_valve_driver;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
         IF(!state_error_valve_driver){
            Turn_Left_Valve_Driver();
            Time_Delay(250);
            time_in_while_valve_driver_starting                   = get_ticks();
            Time_Delay(50);
            state_time_in_while_valve_driver                      = TRUE;
            state_time_in_while_start_valve_driver                = TRUE;
            time_valve_driver_starting                            = get_ticks();
            state_turn_complete_valve_driver                      = FALSE;
            WHILE(!state_turn_complete_valve_driver){
               time_valve_driver_current                          = get_ticks();
               time_valve_driver_difference                       = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
               Turn_Left_Valve_Driver();
               Time_Delay(20);
               Read_Current_L293DD();
               IF(value_current_l293dd > VALUE_SIDE_CURRENT_VALVE_DRIVER){
                  IF(time_valve_driver_difference > time_valve_driver_controller){
                     Stop_Valve_Driver();
                     Time_Delay(20);
                     state_turn_complete_valve_driver             = TRUE;
                     state_time_in_while_valve_driver             = FALSE;
                     state_time_in_while_start_valve_driver       = FALSE;
                     counter_valve_driver_status                  = 0;
                  }
               }
               Controller_Time_In_While_Valve_Driver();
            }
         }
      }
//*************************************************************************************************************************************COUNTER**1**//
      IF((counter_valve_driver % 4) == 1){
         counter_valve_driver_old                                 = counter_valve_driver;
//****************************************************************************************************************IF**COME**FROM**CLOSE**POSITION**//
         IF((counter_valve_driver_status % 4) == 0){
            Turn_Left_Valve_Driver();
            Time_Delay(250);
            Read_Current_L293DD();
            Stop_Valve_Driver();
            Time_Delay(20);
//*************************************************************************************************************************************************//
            IF(value_current_l293dd < VALUE_SIDE_CURRENT_TEST){
               state_error_valve_driver                           = TRUE;
               state_controller_error_in_while_loop_valve_driver  = TRUE;
//*************************************************************************************************************************************************//
               state_confirm_run_time_error_valve_driver          = FALSE;
               WHILE(!state_confirm_run_time_error_valve_driver){
                  Data_Sender(DATA_RUN_TIME_ERROR_VALVE_DRIVER);
                  Time_Delay(50);
               }
            }
            ELSE{
               state_error_valve_driver                           = FALSE;
               state_controller_error_in_while_loop_valve_driver  = FALSE;
            }
            IF(!state_error_valve_driver){
               Turn_Right_Valve_Driver();
               Time_Delay(250);
               time_valve_driver_starting                         = get_ticks();
               state_turn_complete_valve_driver                   = FALSE;
               WHILE(!state_turn_complete_valve_driver){
                  Data_Receiver();
                  time_valve_driver_current                       = get_ticks();
                  time_valve_driver_difference                    = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
                  Turn_Right_Valve_Driver();
                  IF(time_valve_driver_difference > (abs(time_valve_driver_mid_50 - (250 * 1000)))){
                     Stop_Valve_Driver();
                     Time_Delay(20);
                     state_turn_complete_valve_driver             = TRUE;
                     counter_valve_driver_status                  = 1;
                  }
               }
            }
         }
//*****************************************************************************************************************IF**COME**FROM**OPEN**POSITION**//
         IF((counter_valve_driver_status % 4) == 2){
            state_error_valve_driver_in_status     = TRUE;
            counter_temporary_2                    = 0;
            Turn_Right_Valve_Driver();
            WHILE((counter_temporary_2 < 6) && (state_error_valve_driver_in_status)){
               counter_temporary_2++;
               Read_Current_L293DD();
               IF(value_current_l293dd > VALUE_SIDE_CURRENT_TEST){
                  state_error_valve_driver_in_status = FALSE;
               }
            }
            Stop_Valve_Driver();
            Time_Delay(20);
//*************************************************************************************************************************************************//
            IF(state_error_valve_driver_in_status){
               state_error_valve_driver                           = TRUE;
               state_controller_error_in_while_loop_valve_driver  = TRUE;
//*************************************************************************************************************************************************//
               state_confirm_run_time_error_valve_driver          = FALSE;
               WHILE(!state_confirm_run_time_error_valve_driver){
                  Data_Sender(DATA_RUN_TIME_ERROR_VALVE_DRIVER);
                  Time_Delay(50);
               }
            }
            ELSE{
               state_error_valve_driver                           = FALSE;
               state_controller_error_in_while_loop_valve_driver  = FALSE;
            }
            IF(!state_error_valve_driver){
               Turn_Left_Valve_Driver();
               Time_Delay(250);
               time_valve_driver_starting                            = get_ticks();
               state_turn_complete_valve_driver                      = FALSE;
               WHILE(!state_turn_complete_valve_driver){
                  Data_Receiver();
                  time_valve_driver_current                          = get_ticks();
                  time_valve_driver_difference                       = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
                  Turn_Left_Valve_Driver();
                  IF(time_valve_driver_difference > (abs((time_valve_driver_mid_75 - time_valve_driver_mid_50) - (250 * 1000)))){
                     Stop_Valve_Driver();
                     Time_Delay(20);
                     state_turn_complete_valve_driver                = TRUE;
                     counter_valve_driver_status                     = 1;
                  }
               }
            }
         }
//*****************************************************************************************************************IF**COME**FROM**OPEN**POSITION**//
         IF((counter_valve_driver_status % 4) == 3){
            Turn_Right_Valve_Driver();
            Time_Delay(250);
            Read_Current_L293DD();
            Stop_Valve_Driver();
            Time_Delay(20);
//*************************************************************************************************************************************************//
            IF(value_current_l293dd < VALUE_SIDE_CURRENT_TEST){
               state_error_valve_driver                           = TRUE;
               state_controller_error_in_while_loop_valve_driver  = TRUE;
//*************************************************************************************************************************************************//
               state_confirm_run_time_error_valve_driver          = FALSE;
               WHILE(!state_confirm_run_time_error_valve_driver){
                  Data_Sender(DATA_RUN_TIME_ERROR_VALVE_DRIVER);
                  Time_Delay(50);
               }
            }
            ELSE{
               state_error_valve_driver                           = FALSE;
               state_controller_error_in_while_loop_valve_driver  = FALSE;
            }
            IF(!state_error_valve_driver){
               Turn_Left_Valve_Driver();
               Time_Delay(250);
               time_valve_driver_starting                            = get_ticks();
               state_turn_complete_valve_driver                      = FALSE;
               WHILE(!state_turn_complete_valve_driver){
                  Data_Receiver();
                  time_valve_driver_current                          = get_ticks();
                  time_valve_driver_difference                       = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
                  Turn_Left_Valve_Driver();
                  IF(time_valve_driver_difference > (abs(time_valve_driver_mid_50 - (250 * 1000)))){
                     Stop_Valve_Driver();
                     Time_Delay(20);
                     state_turn_complete_valve_driver                = TRUE;
                     counter_valve_driver_status                     = 1;
                  }
               }
            }
         }
      }
//*************************************************************************************************************************************COUNTER**1**//
      IF((counter_valve_driver % 4) == 2){
         counter_valve_driver_old                                 = counter_valve_driver;
//****************************************************************************************************************IF**COME**FROM**CLOSE**POSITION**//
         IF((counter_valve_driver_status % 4) == 0){
            Turn_Left_Valve_Driver();
            Time_Delay(250);
            Read_Current_L293DD();
            Stop_Valve_Driver();
            Time_Delay(20);
//*************************************************************************************************************************************************//
            IF(value_current_l293dd < VALUE_SIDE_CURRENT_TEST){
               state_error_valve_driver                           = TRUE;
               state_controller_error_in_while_loop_valve_driver  = TRUE;
//*************************************************************************************************************************************************//
               state_confirm_run_time_error_valve_driver          = FALSE;
               WHILE(!state_confirm_run_time_error_valve_driver){
                  Data_Sender(DATA_RUN_TIME_ERROR_VALVE_DRIVER);
                  Time_Delay(50);
               }
            }
            ELSE{
               state_error_valve_driver                           = FALSE;
               state_controller_error_in_while_loop_valve_driver  = FALSE;
            }
            IF(!state_error_valve_driver){
               Turn_Right_Valve_Driver();
               Time_Delay(250);
               time_valve_driver_starting                         = get_ticks();
               state_turn_complete_valve_driver                   = FALSE;
               WHILE(!state_turn_complete_valve_driver){
                  Data_Receiver();
                  time_valve_driver_current                       = get_ticks();
                  time_valve_driver_difference                    = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
                  Turn_Right_Valve_Driver();
                  IF(time_valve_driver_difference > (abs(time_valve_driver_mid_75 - (250 * 1000)))){
                     Stop_Valve_Driver();
                     Time_Delay(20);
                     state_turn_complete_valve_driver             = TRUE;
                     counter_valve_driver_status                  = 2;
                  }
               }
            }
         }
//*****************************************************************************************************************IF**COME**FROM**OPEN**POSITION**//
         IF((counter_valve_driver_status % 4) == 1){
            state_error_valve_driver_in_status     = TRUE;
            counter_temporary_2                    = 0;
            Turn_Left_Valve_Driver();
            WHILE((counter_temporary_2 < 6) && (state_error_valve_driver_in_status)){
               counter_temporary_2++;
               Read_Current_L293DD();
               IF(value_current_l293dd > VALUE_SIDE_CURRENT_TEST){
                  state_error_valve_driver_in_status = FALSE;
               }
            }
            Read_Current_L293DD();
            Stop_Valve_Driver();
            Time_Delay(20);
//*************************************************************************************************************************************************//
            IF(state_error_valve_driver_in_status){
               state_error_valve_driver                           = TRUE;
               state_controller_error_in_while_loop_valve_driver  = TRUE;
//*************************************************************************************************************************************************//
               state_confirm_run_time_error_valve_driver          = FALSE;
               WHILE(!state_confirm_run_time_error_valve_driver){
                  Data_Sender(DATA_RUN_TIME_ERROR_VALVE_DRIVER);
                  Time_Delay(50);
               }
            }
            ELSE{
               state_error_valve_driver                           = FALSE;
               state_controller_error_in_while_loop_valve_driver  = FALSE;
            }
            IF(!state_error_valve_driver){
               Turn_Right_Valve_Driver();
               Time_Delay(250);
               time_valve_driver_starting                            = get_ticks();
               state_turn_complete_valve_driver                      = FALSE;
               WHILE(!state_turn_complete_valve_driver){
                  Data_Receiver();
                  time_valve_driver_current                          = get_ticks();
                  time_valve_driver_difference                       = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
                  Turn_Right_Valve_Driver();
                  IF(time_valve_driver_difference > (abs((time_valve_driver_mid_75 - time_valve_driver_mid_50) - (250 * 1000)))){
                     Stop_Valve_Driver();
                     Time_Delay(20);
                     state_turn_complete_valve_driver                = TRUE;
                     counter_valve_driver_status                     = 2;
                  }
               }
            }
         }
//*****************************************************************************************************************IF**COME**FROM**OPEN**POSITION**//
         IF((counter_valve_driver_status % 4) == 3){
            Turn_Right_Valve_Driver();
            Time_Delay(250);
            Read_Current_L293DD();
            Stop_Valve_Driver();
            Time_Delay(20);
//*************************************************************************************************************************************************//
            IF(value_current_l293dd < VALUE_SIDE_CURRENT_TEST){
               state_error_valve_driver                           = TRUE;
               state_controller_error_in_while_loop_valve_driver  = TRUE;
//*************************************************************************************************************************************************//
               state_confirm_run_time_error_valve_driver          = FALSE;
               WHILE(!state_confirm_run_time_error_valve_driver){
                  Data_Sender(DATA_RUN_TIME_ERROR_VALVE_DRIVER);
                  Time_Delay(50);
               }
            }
            ELSE{
               state_error_valve_driver                           = FALSE;
               state_controller_error_in_while_loop_valve_driver  = FALSE;
            }
            IF(!state_error_valve_driver){
               Turn_Left_Valve_Driver();
               Time_Delay(250);
               time_valve_driver_starting                            = get_ticks();
               state_turn_complete_valve_driver                      = FALSE;
               WHILE(!state_turn_complete_valve_driver){
                  Data_Receiver();
                  time_valve_driver_current                          = get_ticks();
                  time_valve_driver_difference                       = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
                  Turn_Left_Valve_Driver();
                  IF(time_valve_driver_difference > (abs((time_valve_driver_mid_75 - time_valve_driver_mid_50) - (150 * 1000)))){
                     Stop_Valve_Driver();
                     Time_Delay(20);
                     state_turn_complete_valve_driver                = TRUE;
                     counter_valve_driver_status                     = 2;
                  }
               }
            }
         }
      }
//*************************************************************************************************************************************COUNTER**2**//
      IF((counter_valve_driver % 4) == 3){
         counter_valve_driver_old                                 = counter_valve_driver;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
         IF(!state_error_valve_driver){
            Turn_Right_Valve_Driver();
            Time_Delay(250);
            time_in_while_valve_driver_starting                   = get_ticks();
            Time_Delay(50);
            state_time_in_while_valve_driver                      = TRUE;
            state_time_in_while_start_valve_driver                = TRUE;
            time_valve_driver_starting                            = get_ticks();
            state_turn_complete_valve_driver                      = FALSE;
            WHILE(!state_turn_complete_valve_driver){
               time_valve_driver_current                          = get_ticks();
               time_valve_driver_difference                       = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
               Turn_Right_Valve_Driver();
               Time_Delay(20);
               Read_Current_L293DD();
               IF(value_current_l293dd > VALUE_SIDE_CURRENT_VALVE_DRIVER){
                  IF(time_valve_driver_difference > time_valve_driver_controller){
                     Stop_Valve_Driver();
                     Time_Delay(20);
                     state_turn_complete_valve_driver             = TRUE;
                     state_time_in_while_valve_driver             = FALSE;
                     state_time_in_while_start_valve_driver       = FALSE;
                     counter_valve_driver_status                  = 3;
                  }
               }
               Controller_Time_In_While_Valve_Driver();
            }
         }
      }
   }
//*************************************************************************************************************************************************//
//******************************************************CONTROLLER**TIME**IN**WHILE**WINDOW********************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Time_In_While_Window(){
//*************************************************************************************************************************************************//
   time_in_while_window_current = get_ticks();
   time_in_while_window_difference = Ticks_Difference(time_in_while_window_starting , time_in_while_window_current);
   IF((time_in_while_window_difference > time_window_difference_error) && (state_time_in_while_start_window)){
      Stop_Window();
      Time_Delay(20);
      state_error_window                                 = TRUE;
      state_turn_complete_window                         = TRUE;
      state_controller_error_in_while_loop_window        = TRUE;
//*************************************************************************************************************************************************//
      state_confirm_run_time_error_window                = FALSE;
      WHILE(!state_confirm_run_time_error_window){
         Data_Sender(DATA_RUN_TIME_ERROR_WINDOW);
         Time_Delay(50);
      }
   }
}
//*************************************************************************************************************************************************//
//********************************************************CONTROLLER**TIME**IN**WHILE**AIR*********************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Time_In_While_Air(){
   time_in_while_air_current = get_ticks();
   time_in_while_air_difference = Ticks_Difference(time_in_while_air_starting , time_in_while_air_current);
   IF((time_in_while_air_difference > time_air_difference_error) && (state_time_in_while_start_air)){
      Stop_Air();
      Time_Delay(20);
      state_error_air                                    = TRUE;
      state_turn_complete_air                            = TRUE;
      state_controller_error_in_while_loop_air           = TRUE;
//*************************************************************************************************************************************************//
      state_confirm_run_time_error_air                   = FALSE;
      WHILE(!state_confirm_run_time_error_air){
         Data_Sender(DATA_RUN_TIME_ERROR_AIR);
         Time_Delay(50);
      }
   }
}
//*************************************************************************************************************************************************//
//***************************************************CONTROLLER**TIME**IN**WHILE**VALVE*DRIVER*****************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Time_In_While_Valve_Driver(){
   time_in_while_valve_driver_current = get_ticks();
   time_in_while_valve_driver_difference = Ticks_Difference(time_in_while_valve_driver_starting , time_in_while_valve_driver_current);
   IF((time_in_while_valve_driver_difference > time_valve_driver_difference_error) && (state_time_in_while_start_valve_driver)){
      Stop_Valve_Driver();
      Time_Delay(20);
      state_error_valve_driver                                 = TRUE;
      state_turn_complete_valve_driver                         = TRUE;
      state_controller_error_in_while_loop_valve_driver        = TRUE;
      Controller_Pomp();
      Controller_Time_Pomp();
//*************************************************************************************************************************************************//
      state_confirm_run_time_error_valve_driver                = FALSE;
      WHILE(!state_confirm_run_time_error_valve_driver){
         Data_Sender(DATA_RUN_TIME_ERROR_VALVE_DRIVER);
         Time_Delay(50);
      }
   }
}
//*************************************************************************************************************************************************//
//*******************************************************************ERROR**SHOWING****************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Error(){
//*****************************************************************************************************************************************WINDOW**//
   IF(state_controller_error_in_while_loop_window){
      Turn_Left_Window();
      Time_Delay(250);
      Read_Current_L293DD();
      Stop_Window();
      Time_Delay(20);
      IF(value_current_l293dd > VALUE_SIDE_CURRENT_WINDOW){
         state_error_window                              = FALSE;
         state_controller_error_in_while_loop_window     = FALSE;
         counter_window_old                              = MINUS_ONE;
         counter_window_status                           = 0;
//*************************************************************************************************************************************************//
         state_confirm_run_time_fix_window               = FALSE;
         WHILE(!state_confirm_run_time_fix_window){
            Data_Sender(DATA_RUN_TIME_FIX_WINDOW);
            Time_Delay(50);
         }
         Time_Delay(100);
         Time_Klape_Once_Window();
      }
   }
//********************************************************************************************************************************************AIR**//
   IF(state_controller_error_in_while_loop_air){
      Turn_Right_Air();
      Time_Delay(250);
      Read_Current_L293DD();
      Stop_Air();
      Time_Delay(20);
      IF(value_current_l293dd > VALUE_SIDE_CURRENT_AIR){
         state_error_air                                 = FALSE;
         state_controller_error_in_while_loop_air        = FALSE;
         counter_air_old                                 = MINUS_ONE;
//*************************************************************************************************************************************************//
         state_confirm_run_time_fix_air                  = FALSE;
         WHILE(!state_confirm_run_time_fix_air){
            Data_Sender(DATA_RUN_TIME_FIX_AIR);
            Time_Delay(50);
         }
         Time_Delay(100);
         Time_Klape_Once_Air();
      }
   }
//**********************************************************************************************************************************VALVE**DRIVER**//
   IF(state_controller_error_in_while_loop_valve_driver){
      Turn_Left_Valve_Driver();
      Time_Delay(250);
      Read_Current_L293DD();
      Stop_Valve_Driver();
      Time_Delay(20);
      IF(value_current_l293dd > VALUE_SIDE_CURRENT_VALVE_DRIVER){
         state_error_valve_driver                              = FALSE;
         state_controller_error_in_while_loop_valve_driver     = FALSE;
         counter_valve_driver_old                              = MINUS_ONE;
         counter_valve_driver_status                           = 0;
//*************************************************************************************************************************************************//
         state_confirm_run_time_fix_valve_driver               = FALSE;
         WHILE(!state_confirm_run_time_fix_valve_driver){
            Data_Sender(DATA_RUN_TIME_FIX_VALVE_DRIVER);
            Time_Delay(50);
         }
         Time_Delay(100);
         Time_Klape_Once_Valve_Driver();
      }
   }
}
//*************************************************************************************************************************************************//
//******************************************************************SEND**DATA*********************************************************************//
//*************************************************************************************************************************************************//
VOID Data_Sender(INT8 data_send){
   putc(data_send);
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
   IF(data_receive == DATA_MAX_OFF){
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_MAX_OFF);
   }
//********************************************************************************************************************************MAX**COUNTER**1**//
   IF(data_receive == DATA_MAX_ON){
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_MAX_ON);
   }
//************************************************************************************************************************DRIVER**FAN**COUNTER**0**//
   IF(data_receive == DATA_FAN_DRIVER_0){
      counter_fan_driver = 0;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_FAN_DRIVER_0);
      data_receive = DATA_CHECK;
   }
//************************************************************************************************************************DRIVER**FAN**COUNTER**1**//
   IF(data_receive == DATA_FAN_DRIVER_1){
      counter_fan_driver = 1;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_FAN_DRIVER_1);
      data_receive = DATA_CHECK;
   }
//************************************************************************************************************************DRIVER**FAN**COUNTER**2**//
   IF(data_receive == DATA_FAN_DRIVER_2){
      counter_fan_driver = 2;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_FAN_DRIVER_2);
      data_receive = DATA_CHECK;
   }
//************************************************************************************************************************DRIVER**FAN**COUNTER**3**//
   IF(data_receive == DATA_FAN_DRIVER_3){
      counter_fan_driver = 3;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_FAN_DRIVER_3);
      data_receive = DATA_CHECK;
   }
//****************************************************************************************************************************WINDOW**COUNTER**0**//
   IF(data_receive == DATA_WINDOW){
      counter_window = 0;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_WINDOW);
      data_receive = DATA_CHECK;
   }
//*******************************************************************************************************************************FACE**COUNTER**1**//
   IF(data_receive == DATA_FACE){
      counter_window = 1;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_FACE);
      data_receive = DATA_CHECK;
   }
//***************************************************************************************************************************TOGETHER**COUNTER**2**//
   IF(data_receive == DATA_TOGETHER){
      counter_window = 2;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_TOGETHER);
      data_receive = DATA_CHECK;
   }
//********************************************************************************************************************************AIR**COUNTER**0**//
   IF(data_receive == DATA_AIR_0){
      counter_air = 0;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_AIR_0);
      data_receive = DATA_CHECK;
   }
//********************************************************************************************************************************AIR**COUNTER**1**//
   IF(data_receive == DATA_AIR_1){
      counter_air = 1;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_AIR_1);
      data_receive = DATA_CHECK;
   }
//**********************************************************************************************************************DRIVER**VALVE**COUNTER**0**//
   IF(data_receive == DATA_VALVE_DRIVER_0){
      counter_valve_driver = 0;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_VALVE_DRIVER_0);
      data_receive = DATA_CHECK;
      Controller_Pomp();
      Controller_Time_Pomp();
   }
//**********************************************************************************************************************DRIVER**VALVE**COUNTER**1**//
   IF(data_receive == DATA_VALVE_DRIVER_1){
      counter_valve_driver = 1;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_VALVE_DRIVER_1);
      data_receive = DATA_CHECK;
   }
//**********************************************************************************************************************DRIVER**VALVE**COUNTER**2**//
   IF(data_receive == DATA_VALVE_DRIVER_2){
      counter_valve_driver = 2;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_VALVE_DRIVER_2);
      data_receive = DATA_CHECK;
   }
//**********************************************************************************************************************DRIVER**VALVE**COUNTER**3**//
   IF(data_receive == DATA_VALVE_DRIVER_3){
      counter_valve_driver = 3;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_VALVE_DRIVER_3);
      data_receive = DATA_CHECK;
   }
//*****************************************************************************************************************************WHEN**OCCUR**ERROR**//
   IF(data_receive == DATA_CONFIRM_RUN_TIME_ERROR_WINDOW){
      state_confirm_run_time_error_window = TRUE;
   }
   IF(data_receive == DATA_CONFIRM_RUN_TIME_ERROR_AIR){
      state_confirm_run_time_error_air = TRUE;
   }
   IF(data_receive == DATA_CONFIRM_RUN_TIME_ERROR_VALVE_DRIVER){
      state_confirm_run_time_error_valve_driver = TRUE;
   }
//*****************************************************************************************************************************WHEN**FIX**ERROR****//
   IF(data_receive == DATA_CONFIRM_RUN_TIME_FIX_WINDOW){
      state_confirm_run_time_fix_window = TRUE;
   }
   IF(data_receive == DATA_CONFIRM_RUN_TIME_FIX_AIR){
      state_confirm_run_time_fix_air = TRUE;
   }
   IF(data_receive == DATA_CONFIRM_RUN_TIME_FIX_VALVE_DRIVER){
      state_confirm_run_time_fix_valve_driver = TRUE;
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
   value_time_delay = (value_time_delay * 1000);
   time_delay_starting = get_ticks();
   time_delay_current = (get_ticks() + 10);
   time_delay_difference = Ticks_Difference(time_delay_starting , time_delay_current);
   WHILE(value_time_delay > time_delay_difference){
      time_delay_current = get_ticks();
      time_delay_difference = Ticks_Difference(time_delay_starting , time_delay_current);
      Data_Receiver();
   }
}
//*************************************************************************************************************************************************//
//***************************************************************RECEIVE**DATA**FOR**ERROR*********************************************************//
//*************************************************************************************************************************************************//
VOID Data_Receiver_Controller_Klape_Error(){
   IF(kbhit()){
      data_receive = getc();
      Assign_Controller_Klape_Error_According_To_Coming_Data();
   }
}
//*************************************************************************************************************************************************//
//************************************************ASSIGN**CONTROLLER**ACCORDING**TO**COMING**DATA**FOR**ERROR**************************************//
//*************************************************************************************************************************************************//
VOID Assign_Controller_Klape_Error_According_To_Coming_Data(){
   IF(data_receive == DATA_CONFIRM_CONTROL_START){
      state_communication_control_start = FALSE;
   }
   IF(data_receive == DATA_CONFIRM_ERROR_WINDOW){
      state_communication_window = FALSE;
   }
   IF(data_receive == DATA_CONFIRM_ERROR_AIR){
      state_communication_air = FALSE;
   }
   IF(data_receive == DATA_CONFIRM_ERROR_VALVE_DRIVER){
      state_communication_valve_driver = FALSE;
   }
   IF(data_receive == DATA_CONFIRM_CONTROL_FINISH){
      state_communication_control_finish = FALSE;
   }
   IF(data_receive == DATA_SHOW_ERROR_FINISH){
      state_communication_show_error_finish = FALSE;
   }
   IF(data_receive == DATA_EEPROM_READ_START){
      state_eeprom_read_start = TRUE;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_EEPROM_READ_START);
   }
   IF(data_receive == DATA_EEPROM_READ_FINISH){
      state_eeprom_read_finish = TRUE;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_EEPROM_READ_FINISH);
   }
   IF(data_receive == DATA_FAN_DRIVER_0){
      counter_fan_driver = 0;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_EEPROM_FAN_DRIVER);
      data_receive = DATA_CHECK;
   }
   IF(data_receive == DATA_MAX_OFF){
      counter_max = 0;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_EEPROM_MAX);
      data_receive = DATA_CHECK;
   }
   IF(data_receive == DATA_WINDOW){
      counter_window = 0;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_EEPROM_WINDOW);
      data_receive = DATA_CHECK;
   }
   IF(data_receive == DATA_FACE){
      counter_window = 1;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_EEPROM_WINDOW);
      data_receive = DATA_CHECK;
   }
   IF(data_receive == DATA_TOGETHER){
      counter_window = 2;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_EEPROM_WINDOW);
      data_receive = DATA_CHECK;
   }
   IF(data_receive == DATA_AIR_0){
      counter_air = 0;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_EEPROM_AIR);
      data_receive = DATA_CHECK;
   }
   IF(data_receive == DATA_AIR_1){
      counter_air = 1;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_EEPROM_AIR);
      data_receive = DATA_CHECK;
   }
   IF(data_receive == DATA_VALVE_DRIVER_0){
      counter_valve_driver = 0;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_EEPROM_VALVE_DRIVER);
      data_receive = DATA_CHECK;
   }
   IF(data_receive == DATA_VALVE_DRIVER_1){
      counter_valve_driver = 1;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_EEPROM_VALVE_DRIVER);
      data_receive = DATA_CHECK;
   }
   IF(data_receive == DATA_VALVE_DRIVER_2){
      counter_valve_driver = 2;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_EEPROM_VALVE_DRIVER);
      data_receive = DATA_CHECK;
   }
   IF(data_receive == DATA_VALVE_DRIVER_3){
      counter_valve_driver = 3;
      DELAY_MS(20);
      Data_Sender(DATA_CONFIRM_EEPROM_VALVE_DRIVER);
      data_receive = DATA_CHECK;
   }
}
//*************************************************************************************************************************************************//
//********************************************************************MAKE**A**DELAY***************************************************************//
//*************************************************************************************************************************************************//
//**********************************************************************EXPLANATION****************************************************************//
//*************************************************************************************************************************************************//
//************************************************************TIME_DELAY(1)**=**DELAY_MS(1)********************************************************//
//*************************************************************************************************************************************************//
VOID Time_Delay_Controller_Klape_Error(INT32 value_time_delay_controller_klape_error){
   value_time_delay_controller_klape_error = (value_time_delay_controller_klape_error * 1000);
   time_delay_starting = get_ticks();
   time_delay_current = (get_ticks() + 10);
   time_delay_difference = Ticks_Difference(time_delay_starting , time_delay_current);
   WHILE(value_time_delay_controller_klape_error > time_delay_difference){
      time_delay_current = get_ticks();
      time_delay_difference = Ticks_Difference(time_delay_starting , time_delay_current);
      Data_Receiver_Controller_Klape_Error();
   }
}
//*************************************************************************************************************************************************//
//**********************************************************************POMP***********************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Pomp(){
//*************************************************************************************************************************************************//
   IF(!state_error_valve_driver){
      IF(!((counter_valve_driver % 4) == 0) && !((counter_fan_driver % 4) == 0)){
         state_controller_pomp_on            = TRUE;
         IF(state_process_complete_pomp){
            state_process_complete_pomp      = FALSE;
            time_controller_pomp_starting    = get_ticks();
         }
      }
      ELSE{
         state_controller_pomp_on            = FALSE;
      }
   }
//*************************************************************************************************************************************************//
   ELSE{
      state_controller_pomp_on               = FALSE;
   }
}
//*************************************************************************************************************************************************//
//**********************************************************************POMP***********************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Time_Pomp(){
   IF(state_controller_pomp_on){
      IF(!state_process_complete_pomp){
         time_controller_pomp_current     = get_ticks();
         time_controller_pomp_difference  = Ticks_Difference(time_controller_pomp_starting , time_controller_pomp_current);
         IF(time_controller_pomp_difference > TIME_POMP_ON){
            state_process_complete_pomp = TRUE;
            OUTPUT_HIGH(POMP_OUT);
         }
      }
   }
   ELSE{
      state_process_complete_pomp = TRUE;
      OUTPUT_LOW(POMP_OUT);
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
//******************************************************************READ**MOTOR********************************************************************//
//*************************************************************************************************************************************************//
//********************************************************************************************************************************CURRENT**L293DD**//
VOID Read_Current_L293DD(){
   SET_ADC_CHANNEL(CURRENT_CHANNEL_L293DD);
   value_current_temporary = 0;
   FOR(counter_temporary = 0; counter_temporary < 10; counter_temporary++){
      DELAY_MS(2);
      Data_Receiver();
      value_current_l293dd = READ_ADC();
      value_current_temporary = value_current_l293dd + value_current_temporary;
   }
   value_current_l293dd = (value_current_temporary / 10);
}
//*************************************************************************************************************************************************//
//******************************************************************MOVE**MOTOR********************************************************************//
//*************************************************************************************************************************************************//
//********************************************************************************************************************************************CAM**//
VOID Turn_Right_Window(){
   OUTPUT_HIGH(WINDOW_EN);
   OUTPUT_LOW(VALVE_DRIVER_EN);
   OUTPUT_HIGH(WINDOW_IN_1);
   OUTPUT_LOW(WINDOW_IN_2);
}
VOID Turn_Left_Window(){
   OUTPUT_HIGH(WINDOW_EN);
   OUTPUT_LOW(VALVE_DRIVER_EN);
   OUTPUT_LOW(WINDOW_IN_1);
   OUTPUT_HIGH(WINDOW_IN_2);
}
VOID Stop_Window(){
   OUTPUT_LOW(WINDOW_EN);
   OUTPUT_LOW(WINDOW_IN_1);
   OUTPUT_LOW(WINDOW_IN_2);
}
//************************************************************************************************************************************TEMIZ**HAVA**//
VOID Turn_Right_Air(){
   OUTPUT_HIGH(AIR_EN_1);
   OUTPUT_HIGH(AIR_EN_2);
   OUTPUT_HIGH(AIR_IN_1_1);
   OUTPUT_HIGH(AIR_IN_1_2);
   OUTPUT_LOW(AIR_IN_2_1);
   OUTPUT_LOW(AIR_IN_2_2);
}
VOID Turn_Left_Air(){
   OUTPUT_HIGH(AIR_EN_1);
   OUTPUT_HIGH(AIR_EN_2);
   OUTPUT_LOW(AIR_IN_1_1);
   OUTPUT_LOW(AIR_IN_1_2);
   OUTPUT_HIGH(AIR_IN_2_1);
   OUTPUT_HIGH(AIR_IN_2_2);
}
VOID Stop_Air(){
   OUTPUT_LOW(AIR_EN_1);
   OUTPUT_LOW(AIR_EN_2);
   OUTPUT_LOW(AIR_IN_1_1);
   OUTPUT_LOW(AIR_IN_1_2);
   OUTPUT_LOW(AIR_IN_2_1);
   OUTPUT_LOW(AIR_IN_2_2);
}
//*******************************************************************************************************************************************VANA**//
VOID Turn_Right_Valve_Driver(){
   OUTPUT_HIGH(VALVE_DRIVER_EN);
   OUTPUT_LOW(WINDOW_EN);
   OUTPUT_HIGH(VALVE_DRIVER_IN_1);
   OUTPUT_LOW(VALVE_DRIVER_IN_2);
}
VOID Turn_Left_Valve_Driver(){
   OUTPUT_HIGH(VALVE_DRIVER_EN);
   OUTPUT_LOW(WINDOW_EN);
   OUTPUT_LOW(VALVE_DRIVER_IN_1);
   OUTPUT_HIGH(VALVE_DRIVER_IN_2);
}
VOID Stop_Valve_Driver(){
   OUTPUT_LOW(VALVE_DRIVER_EN);
   OUTPUT_LOW(VALVE_DRIVER_IN_1);
   OUTPUT_LOW(VALVE_DRIVER_IN_2);
}
//*************************************************************************************************************************************************//
//***********************************************************TIME**KLAPE**ONCE**WINDOW*************************************************************//
//*************************************************************************************************************************************************//
VOID Time_Klape_Once_Window(){
   IF(state_time_klape_once_window){
      Turn_Right_Window();
      Time_Delay(250);
      state_time_klape_once_turn_complete_window               = FALSE;
      WHILE(!state_time_klape_once_turn_complete_window){
         Turn_Right_Window();
         Time_Delay(20);
         Read_Current_L293DD();
         IF(value_current_l293dd > VALUE_SIDE_CURRENT_WINDOW){
            state_error_window                                 = FALSE;
            state_turn_complete_window                         = FALSE;
            state_controller_klape_error_window                = FALSE;
            state_controller_error_in_while_loop_window        = FALSE;
            state_time_klape_once_window                       = FALSE;
            state_time_klape_once_turn_complete_window         = TRUE;
            Stop_Window();
            Time_Delay(20);
         }
      }
      Turn_Left_Window();
      Time_Delay(250);
      time_window_starting                                     = get_ticks();
      state_time_klape_once_turn_complete_window               = FALSE;
      WHILE(!state_time_klape_once_turn_complete_window){
         Turn_Left_Window();
         time_window_current                                   = get_ticks();
         Read_Current_L293DD();
         IF(value_current_l293dd > VALUE_SIDE_CURRENT_WINDOW){
            state_time_klape_once_turn_complete_window         = TRUE;
            Stop_Window();
            Time_Delay(20);
         }
      }
      IF(!state_error_window){
         time_window_difference                    = Ticks_Difference(time_window_starting , time_window_current);
         time_window_controller                    = (abs(time_window_difference - (200 * 1000)));
         time_window_difference_error              = (2 * time_window_difference);
         time_window_mid                           = (abs((time_window_difference / 2) - (300 * 1000)));
      }
   }
}
//*************************************************************************************************************************************************//
//*************************************************************TIME**KLAPE**ONCE**AIR**************************************************************//
//*************************************************************************************************************************************************//
VOID Time_Klape_Once_Air(){
   IF(state_time_klape_once_air){
      Turn_Right_Air();
      Time_Delay(250);
      state_time_klape_once_turn_complete_air                  = FALSE;
      WHILE(!state_time_klape_once_turn_complete_air){
         Turn_Right_Air();
         Time_Delay(20);
         Read_Current_L293DD();
         IF(value_current_l293dd > VALUE_SIDE_CURRENT_AIR){
            state_error_air                                    = FALSE;
            state_turn_complete_air                            = FALSE;
            state_controller_klape_error_air                   = FALSE;
            state_controller_error_in_while_loop_air           = FALSE;
            state_time_klape_once_air                          = FALSE;
            state_time_klape_once_turn_complete_air            = TRUE;
            Stop_Air();
            Time_Delay(20);
         }
      }
      Turn_Left_Air();
      Time_Delay(250);
      time_air_starting                                        = get_ticks();
      state_time_klape_once_turn_complete_air                  = FALSE;
      WHILE(!state_time_klape_once_turn_complete_air){
         Turn_Left_Air();
         time_air_current                                      = get_ticks();
         Read_Current_L293DD();
         IF(value_current_l293dd > VALUE_SIDE_CURRENT_AIR){
            state_time_klape_once_turn_complete_air            = TRUE;
            Stop_Air();
            Time_Delay(20);
         }
      }
      IF(!state_error_air){
         time_air_difference                       = Ticks_Difference(time_air_starting , time_air_current);
         time_air_controller                       = (abs(time_air_difference - (200 * 1000)));
         time_air_difference_error                 = (2 * time_air_difference);
      }
   }
}
//*************************************************************************************************************************************************//
//********************************************************TIME**KLAPE**ONCE**VALVE**DRIVER*********************************************************//
//*************************************************************************************************************************************************//
VOID Time_Klape_Once_Valve_Driver(){
   IF(state_time_klape_once_valve_driver){
      Turn_Right_Valve_Driver();
      Time_Delay(250);
      state_time_klape_once_turn_complete_valve_driver               = FALSE;
      WHILE(!state_time_klape_once_turn_complete_valve_driver){
         Turn_Right_Valve_Driver();
         Time_Delay(20);
         Read_Current_L293DD();
         IF(value_current_l293dd > VALUE_SIDE_CURRENT_VALVE_DRIVER){
            state_error_valve_driver                                 = FALSE;
            state_turn_complete_valve_driver                         = FALSE;
            state_controller_klape_error_valve_driver                = FALSE;
            state_controller_error_in_while_loop_valve_driver        = FALSE;
            state_time_klape_once_valve_driver                       = FALSE;
            state_time_klape_once_turn_complete_valve_driver         = TRUE;
            Stop_Valve_Driver();
            Time_Delay(20);
         }
      }
      Turn_Left_Valve_Driver();
      Time_Delay(250);
      time_valve_driver_starting                                     = get_ticks();
      state_time_klape_once_turn_complete_valve_driver               = FALSE;
      WHILE(!state_time_klape_once_turn_complete_valve_driver){
         Turn_Left_Valve_Driver();
         time_valve_driver_current                                   = get_ticks();
         Read_Current_L293DD();
         IF(value_current_l293dd > VALUE_SIDE_CURRENT_VALVE_DRIVER){
            state_time_klape_once_turn_complete_valve_driver         = TRUE;
            Stop_Valve_Driver();
            Time_Delay(20);
         }
      }
      IF(!state_error_valve_driver){
         time_valve_driver_difference              = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
         time_valve_driver_controller              = (abs(time_valve_driver_difference - (200 * 1000)));
         time_valve_driver_difference_error        = (2 * time_valve_driver_difference);
         time_valve_driver_mid_50                  = (time_valve_driver_difference / 2);
         time_valve_driver_mid_75                  = ((time_valve_driver_difference / 4) * 3);
      }
   }
}
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
//********************************************************************END**************************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
