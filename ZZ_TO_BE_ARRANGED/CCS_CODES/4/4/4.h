//***************************************************************************************************************************************************
//***************************************************************************************************************************************************
//*****************************************************************HEADER**FILE**********************************************************************
//***************************************************************************************************************************************************
//***************************************************************************************************************************************************
//***********************************************************CONTENTS**FOR**THIS**CODE***************************************************************
//***************************************************************************************************************************************************
//***************************                                                                                           ***************************//
//***************************                                                                                           ***************************//
//***************************                                                                                           ***************************//
//***************************           01) HEADER_FILE------------------------------------------------0003             ***************************//
//***************************           02) INCLUDE_DEVICE---------------------------------------------0077             ***************************//
//***************************           03) ADC_BIT----------------------------------------------------0080             ***************************//
//***************************           04) SETTING_FUSEs----------------------------------------------0082             ***************************//
//***************************           05) SETTING_USEs-----------------------------------------------0088             ***************************//
//***************************           06) PORT_DEFINEs-----------------------------------------------0102             ***************************//
//***************************           07) FUNCTIONs--------------------------------------------------0217             ***************************//
//***************************           08) INTEGER_VARIABLEs------------------------------------------0284             ***************************//
//***************************           09) BOOLEAN_VARIABLEs------------------------------------------0381             ***************************//
//***************************           10) SETTING()--------------------------------------------------0422             ***************************//
//***************************           11) Controller_Klape()-----------------------------------------0487             ***************************//
//***************************           12) Scan_Klape_Time()------------------------------------------0545             ***************************//
//***************************           13) Make_Default_Value()---------------------------------------0593             ***************************//
//***************************           14) Read_Value_From_EEPROM()-----------------------------------0623             ***************************//
//***************************           15) Work_According_To_EEPROM_Value()---------------------------0639             ***************************//
//***************************           16) Controller_Functions()-------------------------------------0650             ***************************//
//***************************           17) Controller_Functions_In_Controlller_While()----------------0795             ***************************//
//***************************           18) Button_Controller_Functions()------------------------------0810             ***************************//
//***************************           19) Button_Controller_Max()------------------------------------0769             ***************************//
//***************************           20) Button_Controller_On_Fan()---------------------------------0845             ***************************//
//***************************           21) Button_Controller_Arka_Fan()-------------------------------0866             ***************************//
//***************************           22) Button_Controller_Cam()------------------------------------0879             ***************************//
//***************************           23) Button_Controller_Temiz_Hava()-----------------------------0938             ***************************//
//***************************           24) Button_Controller_Vana_1()---------------------------------0960             ***************************//
//***************************           25) Button_Controller_Vana_2()---------------------------------0960             ***************************//
//***************************           26) Controller_On_Fan()----------------------------------------1073             ***************************//
//***************************           27) Controller_On_Fan_In_Controller_While()--------------------1175             ***************************//
//***************************           28) Controller_Arka_Fan()--------------------------------------1205             ***************************//
//***************************           29) Controller_Arka_Fan_In_Controller_While()------------------1265             ***************************//
//***************************           30) Controller_Cam_Yuz()---------------------------------------1286             ***************************//
//***************************           31) Controller_Cam_Yuz_In_Controller_While()-------------------1383             ***************************//
//***************************           32) Controller_Temiz_Hava()------------------------------------1407             ***************************//
//***************************           33) Controller_Temiz_Hava_In_Controller_While()----------------1453             ***************************//
//***************************           34) Controller_Vana_1()----------------------------------------1467             ***************************//
//***************************           35) Controller_Vana_1_In_Controller_While()--------------------1564             ***************************//
//***************************           36) Controller_Vana_2()----------------------------------------1467             ***************************//
//***************************           37) Controller_Vana_2_In_Controller_While()--------------------1564             ***************************//
//***************************           38) Write_Led()------------------------------------------------1812             ***************************//
//***************************           39) ONer()-----------------------------------------------------1833             ***************************//
//***************************           40) OFFer()----------------------------------------------------1840             ***************************//
//***************************           41) Ticks_Difference()-----------------------------------------1847             ***************************//
//***************************           42) Change_8_Bits_Of_16_Bit_Data()-----------------------------1854             ***************************//
//***************************           43) Read_Current_Cam_Temiz_Hava()------------------------------1875             ***************************//
//***************************           44) Read_Current_Vana()----------------------------------------1881             ***************************//
//***************************           45) Turn_Right_Cam()-------------------------------------------1891             ***************************//
//***************************           46) Turn_Left_Cam()--------------------------------------------1897             ***************************//
//***************************           47) Stop_Cam()-------------------------------------------------1903             ***************************//
//***************************           48) Turn_Right_Temiz_Hava()------------------------------------1910             ***************************//
//***************************           49) Turn_Left_Temiz_Hava()-------------------------------------1916             ***************************//
//***************************           50) Stop_Temiz_Hava()------------------------------------------1922             ***************************//
//***************************           51) Turn_Right_Vana_1()----------------------------------------1929             ***************************//
//***************************           52) Turn_Left_Vana_1()-----------------------------------------1935             ***************************//
//***************************           53) Stop_Vana_1()----------------------------------------------1941             ***************************//
//***************************           54) Turn_Right_Vana_2()----------------------------------------1929             ***************************//
//***************************           55) Turn_Left_Vana_2()-----------------------------------------1935             ***************************//
//***************************           56) Stop_Vana_2()----------------------------------------------1941             ***************************//
//***************************           57) END--------------------------------------------------------1948             ***************************//
//***************************                                                                                           ***************************//
//***************************                                                                                           ***************************//
//***************************                                                                                           ***************************//
//*************************************************************************END*********************************************************************//
//*************************************************************************************************************************************************//
//*******************************************************************INCLUDE**DEVICE***************************************************************//
//*************************************************************************************************************************************************//
#INCLUDE <16F1939.h>
//***********************************************************************ADC**BIT******************************************************************//
#DEVICE ADC = 10
//********************************************************************SETTING**FUSEs***************************************************************//
#FUSES HS
#FUSES NOWDT
#FUSES NOPROTECT
#FUSES NOBROWNOUT
#FUSES NOLVP
#FUSES NOPUT
#FUSES NOWRT
#FUSES NODEBUG
#FUSES NOCPD
#FUSES NOMCLR
//*************************************************************************************************************************************************//
//********************************************************************SETTING**USEs****************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************USE**DELAY**//
#USE DELAY(INTERNAL = 4MHZ)
//*************************************************************************************************************************************USE**TIMER**//
#USE TIMER(TIMER = 1, TICK = 1 MS, BITS = 32, NOISR)
//*************************************************************************************************************************************************//
//*****************************************************************PORT***DEFINES******************************************************************//
//*************************************************************************************************************************************************//
//**********************************************************************************************************************************BASIC**VALUEs**//
#DEFINE ALL_ZERO_8_BIT                                   0x00
#DEFINE ALL_ZERO_16_BIT                                  0x0000
#DEFINE ALL_ZERO_32_BIT                                  0x00000000
#DEFINE ALL_ONE_8_BIT                                    0xFF
#DEFINE ALL_ONE_16_BIT                                   0xFFFF
#DEFINE ALL_ONE_32_BIT                                   0xFFFFFFFF
#DEFINE MINUS_ONE                                        -1
//************************************************************************************************************************************PWM**VALUEs**//
#DEFINE PWM_FAN_DRIVER_STEP_0                            0     
#DEFINE PWM_FAN_DRIVER_STEP_1                            500     
#DEFINE PWM_FAN_DRIVER_STEP_2                            750     
#DEFINE PWM_FAN_DRIVER_STEP_3                            1023
#DEFINE PWM_FAN_PASSENGER_STEP_0                         0
#DEFINE PWM_FAN_PASSENGER_STEP_1                         700
#DEFINE PWM_FAN_PASSENGER_STEP_2                         1023
//*****************************************************************************************************************************TIME**POMP**VALUEs**//
#DEFINE TIME_POMP_ON                                     5000
//******************************************************************************************************************************SET**TRIS**VALUEs**//
#DEFINE VALUE_TRIS_A                                     0x30
#DEFINE VALUE_TRIS_B                                     0x1C
#DEFINE VALUE_TRIS_C                                     0x08
#DEFINE VALUE_TRIS_D                                     0x00
#DEFINE VALUE_TRIS_E                                     0x00
//********************************************************************************************************************************ADDRESS**VALUEs**//
#DEFINE VALUE_ADDRESS_VALVE_DRIVER                       0x01
#DEFINE VALUE_ADDRESS_VALVE_PASSENGER                    0x02
//*********************************************************************************************************************************BOARD**LEDLERI**//
#DEFINE LED_FAN_DRIVER_1                                 PIN_D7
#DEFINE LED_FAN_DRIVER_2                                 PIN_B0
#DEFINE LED_FAN_DRIVER_3                                 PIN_B1
#DEFINE LED_FAN_PASSENGER_1                              PIN_C7
#DEFINE LED_FAN_PASSENGER_2                              PIN_D4
#DEFINE LED_VALVE_DRIVER_0                               PIN_A1
#DEFINE LED_VALVE_DRIVER_1                               PIN_A2
#DEFINE LED_VALVE_DRIVER_2                               PIN_A3
#DEFINE LED_VALVE_PASSENGER_0                            PIN_C0
#DEFINE LED_VALVE_PASSENGER_1                            PIN_A6
#DEFINE LED_VALVE_PASSENGER_2                            PIN_A7
//****************************************************************************************************************************************BUTTONs**//
#DEFINE BUTTON_FAN_DRIVER                                PIN_B3
#DEFINE BUTTON_FAN_PASSENGER                             PIN_B2
#DEFINE BUTTON_VALVE_DRIVER                              PIN_A4
#DEFINE BUTTON_VALVE_PASSENGER                           PIN_A5
//****************************************************************************************************************************DRIVER**VALVE**PINs**//
#DEFINE VALVE_DRIVER_EN                                  PIN_D6
#DEFINE VALVE_DRIVER_IN_1                                PIN_B6
#DEFINE VALVE_DRIVER_IN_2                                PIN_B7
//*************************************************************************************************************************PASSENGER**VALVE**PINs**//
#DEFINE VALVE_PASSENGER_EN                               PIN_D5
#DEFINE VALVE_PASSENGER_IN_1                             PIN_B5
#DEFINE VALVE_PASSENGER_IN_2                             PIN_D1
//********************************************************************************************************************************************PWM**//
#DEFINE PWM_FAN_DRIVER                                   PIN_C1
#DEFINE PWM_FAN_PASSENGER                                PIN_C2
//*************************************************************************************************************************************PWM**SETUP**//
#DEFINE PWM_SETUP_FAN_DRIVER_ON                          SETUP_CCP2(CCP_PWM);
#DEFINE PWM_SETUP_FAN_DRIVER_OFF                         SETUP_CCP2(CCP_OFF);
#DEFINE PWM_SETUP_FAN_PASSENGER_ON                       SETUP_CCP1(CCP_PWM);
#DEFINE PWM_SETUP_FAN_PASSENGER_OFF                      SETUP_CCP1(CCP_OFF);
//*******************************************************************************************************************************CURRENT**CONTROL**//
#DEFINE CURRENT_PORT_VALVE                               PIN_B4
//**************************************************************************************************************************************ADC**PINs**//
#DEFINE ADC_Current_Valve                                sAN11
//***********************************************************************************************************************************ADC**CHANNEL**//
#DEFINE CHANNEL_Current_Valve                            11
//********************************************************************************************************************************CURRENT**VALUEs**//
#DEFINE VALUE_SIDE_CURRENT_VALVE_DRIVER                  40
#DEFINE VALUE_SIDE_CURRENT_VALVE_PASSENGER               40
#DEFINE VALUE_SIDE_CURRENT_TEST                          15
//*********************************************************************************************************************************KLIMA-POMP_OUT**//
#DEFINE AIR_CONDITIONING_OUT                             PIN_A0
#DEFINE POMP_OUT                                         PIN_E2
#DEFINE AIR_CONDITIONING_OUT_ON_INFO                     PIN_C3
//*************************************************************************************************************************************************//
//*******************************************************************FUNCTIONs*********************************************************************//
//*************************************************************************************************************************************************//
//********************************************************************************************************************************MAIN**FUNCTIONs**//
VOID Setting();
VOID Controller_Klape();
VOID Scan_Klape_Time();
VOID Time_Klape_Once_Valve_Driver();
VOID Time_Klape_Once_Valve_Passenger();
VOID Controller_Klape_Error();
VOID Make_Default_Value();
VOID Read_Value_From_EEPROM();
VOID Work_According_To_EEPROM_Value();
//******************************************************************************************************************************BUTTON**FUNCTIONs**//
VOID Button_Controller_Fan_Driver();
VOID Button_Controller_Fan_Passenger();
VOID Button_Controller_Valve_Driver();
VOID Button_Controller_Valve_Passenger();
VOID Button_Controller_Functions();
//**************************************************************************************************************************CONTROLLER**FUNCTIONs**//
VOID Controller_Pomp();
VOID Controller_Klape();
VOID Controller_Klape_Error();
VOID Controller_Scan_Klape_Time();
VOID Controller_Air_Conditioning_Out_On_Info();
VOID Controller_Fan_Driver();
VOID Controller_Fan_Passenger();
VOID Controller_Valve_Driver();
VOID Controller_Valve_Passenger();
VOID Controller_Functions();
VOID Controller_Led_Fan_Driver();
VOID Controller_Led_Fan_Passenger();
VOID Controller_Led_Valve_Driver();
VOID Controller_Led_Valve_Passenger();
VOID Controller_Led_Functions();
//***************************************************************************************************************************READ**ADC**FUNCTIONs**//
VOID Read_Current_Valve();
//*********************************************************************************************************************MOTOR**MOVEMENT**FUNCTIONs**//
VOID Turn_Right_Valve_Driver();
VOID Turn_Left_Valve_Driver();
VOID Stop_Valve_Driver();
VOID Turn_Right_Valve_Passenger();
VOID Turn_Left_Valve_Passenger();
VOID Stop_Valve_Passenger();
//********************************************************************************************************************************TIME**FUNCTIONs**//
VOID Controller_Time_Pomp();
VOID Controller_Time_In_While_Valve_Driver();
VOID Controller_Time_In_While_Valve_Passenger();
VOID Controller_Error_In_Button();
VOID Controller_Error_In_While_Loop();
VOID Controller_Air_Conditioning_Signal();
//*************************************************************************************************************************************************//
INT32 Ticks_Difference(INT32,INT32);
//*************************************************************************************************************************************************//
//**************************************************************INTEGER**VARIABLEs*****************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************EEPROM**ADDRESS**DATAs**//
INT8 address_valve_driver                                      = VALUE_ADDRESS_VALVE_DRIVER;
INT8 address_valve_passenger                                   = VALUE_ADDRESS_VALVE_PASSENGER;
//***************************************************************************************************************************************COUNTERs**//
SIGNED INT8 counter_fan_driver                                 = MINUS_ONE;
SIGNED INT8 counter_fan_driver_old                             = MINUS_ONE;
SIGNED INT8 counter_fan_passenger                              = MINUS_ONE;
SIGNED INT8 counter_fan_passenger_old                          = MINUS_ONE;
SIGNED INT8 counter_valve_driver                               = MINUS_ONE;
SIGNED INT8 counter_valve_driver_status                        = MINUS_ONE;
SIGNED INT8 counter_valve_driver_old                           = MINUS_ONE;
SIGNED INT8 counter_valve_passenger                            = MINUS_ONE;
SIGNED INT8 counter_valve_passenger_status                     = MINUS_ONE;
SIGNED INT8 counter_valve_passenger_old                        = MINUS_ONE;
//*********************************************************************************************************************************ADC**VARIABLEs**//
INT16 value_current_valve                                      = ALL_ZERO_16_BIT;
INT16 value_current_temporary                                  = ALL_ZERO_16_BIT;
//*********************************************************************************************************************************PWM**VARIABLEs**//
INT16 value_pwm_fan_driver                                     = ALL_ZERO_16_BIT;
INT16 value_pwm_fan_passenger                                  = ALL_ZERO_16_BIT;
//************************************************************************************************************KLAPE**CONTROL**FUNCTION**VARIABLEs**//
INT16 counter_klape_valve_driver                               = ALL_ZERO_16_BIT;
INT16 counter_klape_valve_passenger                            = ALL_ZERO_16_BIT;
//*************************************************************************************************************************************************//
INT16 counter_air_conditioning_out_on_info                     = ALL_ZERO_16_BIT;
//*************************************************************************************************************************************************//
INT16 counter_button_controller_functions                      = ALL_ZERO_16_BIT;
//*************************************************************************************************************************************************//
INT16 counter_controller_fan_in_while                          = ALL_ZERO_16_BIT;
//*********************************************************************************************************************************ADC**VARIABLEs**//
INT32 register_adc                                             = ALL_ZERO_32_BIT;
//***************************************************************************************************************KLAPE**CONTROL**ERROR**VARIABLEs**//
INT32 counter_controller_klape_error_valve_driver              = ALL_ZERO_32_BIT;
INT32 counter_controller_klape_error_valve_passenger           = ALL_ZERO_32_BIT;
INT32 counter_controller_klape_error_inner_valve_driver        = ALL_ZERO_32_BIT;
INT32 counter_controller_klape_error_inner_valve_passenger     = ALL_ZERO_32_BIT;
//********************************************************************************************************************************TIME**VARIABLEs**//
UNSIGNED INT32 time_difference                                 = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_driver_starting                      = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_driver_current                       = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_driver_difference                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_driver_mid                           = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_passenger_starting                   = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_passenger_current                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_passenger_difference                 = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_passenger_mid                        = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_error_valve_driver_difference              = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_error_valve_passenger_difference           = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_controller_pomp_starting                   = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_controller_pomp_current                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_controller_pomp_difference                 = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_valve_driver_starting             = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_valve_driver_current              = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_valve_driver_difference           = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_valve_passenger_starting          = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_valve_passenger_current           = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_valve_passenger_difference        = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_controller_valve_driver                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_controller_valve_passenger                 = ALL_ZERO_32_BIT;
//*************************************************************************************************************************************************//
//*************************************************************BOOLEAN**VARIABLEs******************************************************************//
//*************************************************************************************************************************************************//
//*******************************************************************************************************************CONTROLLER**KLAPE**VARIABLEs**//
BOOLEAN state_error_valve_driver                               = FALSE;
BOOLEAN state_error_valve_passenger                            = FALSE;
BOOLEAN state_controller_klape_error_valve_driver              = FALSE;
BOOLEAN state_controller_klape_error_valve_passenger           = FALSE;
//*******************************************************************************************************************BUTON**CONTROLLER**VARIABLEs**//
BOOLEAN state_button_fan_driver                                = TRUE;
BOOLEAN state_button_fan_passenger                             = TRUE;
BOOLEAN state_button_valve_driver                              = TRUE;
BOOLEAN state_button_valve_passenger                           = TRUE;
//***************************************************************************************************************CONTROLLER**FUNCTIONS**VARIABLEs**//
BOOLEAN state_turn_complete_valve_driver                       = FALSE;
BOOLEAN state_turn_complete_valve_passenger                    = FALSE;
//*******************************************************************************************************************SCAN**KLAPE**TIME**VARIABLEs**//
BOOLEAN state_scan_klape_time                                  = TRUE;
//*************************************************************************************************************************************************//
BOOLEAN state_controller_error_in_button_valve_driver          = FALSE;
BOOLEAN state_controller_error_in_button_valve_passenger       = FALSE;
//*******************************************************************************************************************CONTROLLER**ERROR**VARIABLEs**//
BOOLEAN state_controller_error_in_while_loop_valve_driver      = FALSE;
BOOLEAN state_controller_error_in_while_loop_valve_passenger   = FALSE;
//********************************************************************************************************************************TIME**VARIABLEs**//
BOOLEAN state_time_in_while_valve_driver                       = FALSE;
BOOLEAN state_time_in_while_start_valve_driver                 = FALSE;
BOOLEAN state_time_in_while_valve_passenger                    = FALSE;
BOOLEAN state_time_in_while_start_valve_passenger              = FALSE;
//********************************************************************************************************************************POMP**VARIABLEs**//
BOOLEAN state_process_complete_pomp                            = FALSE;
BOOLEAN state_controller_pomp_on                               = FALSE;
//*******************************************************************************************************************AIR**CONDITIONING**VARIABLEs**//
BOOLEAN state_air_conditioning_out_on_info                     = FALSE;
BOOLEAN state_air_conditioning_out_on_info_once                = TRUE;
//*************************************************************************************************************************************************//
BOOLEAN state_time_klape_once_valve_driver                     = FALSE;
BOOLEAN state_time_klape_once_valve_passenger                  = FALSE;
BOOLEAN state_time_klape_once_turn_complete_valve_driver       = FALSE;
BOOLEAN state_time_klape_once_turn_complete_valve_passenger    = FALSE;
//*************************************************************************************************************************************************//
//*****************************************************************SETTING*************************************************************************//
//*************************************************************************************************************************************************//
   VOID Setting(){
//***************************************************************************************************************************CLOSING**ALL**OUTPUT**//
      OUTPUT_A(ALL_ZERO_8_BIT);
      OUTPUT_B(ALL_ZERO_8_BIT);
      OUTPUT_C(ALL_ZERO_8_BIT);
      OUTPUT_D(ALL_ZERO_8_BIT);
      OUTPUT_E(ALL_ZERO_8_BIT);
//******************************************************************************************************************************************DELAY**//
      DELAY_MS(4000);
//***************************************************************************************************************************SETTING**ALL**OUTPUT**//
      SET_TRIS_A(VALUE_TRIS_A);
      SET_TRIS_B(VALUE_TRIS_B);
      SET_TRIS_C(VALUE_TRIS_C);
      SET_TRIS_D(VALUE_TRIS_D);
      SET_TRIS_E(VALUE_TRIS_E);
      OUTPUT_HIGH(LED_FAN_DRIVER_1);
      OUTPUT_HIGH(LED_FAN_DRIVER_2);
      OUTPUT_HIGH(LED_FAN_DRIVER_3);
      OUTPUT_HIGH(LED_FAN_PASSENGER_1);
      OUTPUT_HIGH(LED_FAN_PASSENGER_2);
      OUTPUT_HIGH(LED_VALVE_DRIVER_0);
      OUTPUT_HIGH(LED_VALVE_DRIVER_1);
      OUTPUT_HIGH(LED_VALVE_DRIVER_2);
      OUTPUT_HIGH(LED_VALVE_PASSENGER_0);
      OUTPUT_HIGH(LED_VALVE_PASSENGER_1);
      OUTPUT_HIGH(LED_VALVE_PASSENGER_2);
//********************************************************************************************************************************SETUP**TIMER**2**//
      SETUP_TIMER_2(T2_DIV_BY_1, 255, 1);
      SETUP_OSCILLATOR(0x7A);
//************************************************************************************************************************SETTING**PWM_DRIVER_FAN**//
      OUTPUT_LOW(PWM_FAN_DRIVER);
      SETUP_CCP1(CCP_PWM);
      SETUP_CCP1(CCP_OFF);
      DELAY_US(50);
//*********************************************************************************************************************SETTING**PWM_PASSENGER_FAN**//
      OUTPUT_LOW(PWM_FAN_PASSENGER);
      SETUP_CCP2(CCP_PWM);
      SETUP_CCP2(CCP_OFF);
      DELAY_US(50);
//****************************************************************************************************************************SETTING**ADC**PORTs**//
      register_adc                  = register_adc | ADC_Current_Valve;
      register_adc                  = register_adc | VSS_VDD;
      SETUP_ADC_PORTS(register_adc);
      SETUP_ADC(RTCC_INTERNAL|ADC_CLOCK_DIV_8);
      DELAY_US(50);
//*********************************************************************************************************************************TICKs**DEFAULT**//
      set_ticks(ALL_ZERO_32_BIT);
   }
//*************************************************************************************************************************************************//
//******************************************************************KLAPE**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Klape(){
//**********************************************************************************************************************************MAKE**DEFAULT**//
      state_error_valve_driver                                 = TRUE;
      state_error_valve_passenger                              = TRUE;
      state_time_klape_once_valve_driver                       = TRUE;
      state_time_klape_once_valve_passenger                    = TRUE;
      state_controller_klape_error_valve_driver                = TRUE;
      state_controller_klape_error_valve_passenger             = TRUE;
      state_controller_error_in_while_loop_valve_driver        = TRUE;
      state_controller_error_in_while_loop_valve_passenger     = TRUE;
//**********************************************************************************************************************************DRIVER**VALVE**//
      Turn_Right_Valve_Driver();
      DELAY_MS(500);
      FOR(counter_klape_valve_driver = 0; counter_klape_valve_driver < 300; counter_klape_valve_driver++){
         Turn_Right_Valve_Driver();
         DELAY_MS(30);
         Read_Current_Valve();
         IF(value_current_valve > VALUE_SIDE_CURRENT_VALVE_DRIVER){
            Stop_Valve_Driver();
            state_error_valve_driver                           = FALSE;
            state_time_klape_once_valve_driver                 = FALSE;
            state_controller_klape_error_valve_driver          = FALSE;
            state_controller_error_in_while_loop_valve_driver  = FALSE;
            counter_klape_valve_driver                         = 300;
         }
      }
      Stop_Valve_Driver();
      DELAY_MS(100);
//*******************************************************************************************************************************PASSENGER**VALVE**//
      Turn_Right_Valve_Passenger();
      DELAY_MS(500);
      FOR(counter_klape_valve_passenger = 0; counter_klape_valve_passenger < 1200; counter_klape_valve_passenger++){
         Turn_Right_Valve_Passenger();
         DELAY_MS(30);
         Read_Current_Valve();
         IF(value_current_valve > VALUE_SIDE_CURRENT_VALVE_PASSENGER){
            Stop_Valve_Passenger();
            state_error_valve_passenger                           = FALSE;
            state_time_klape_once_valve_passenger                 = FALSE;
            state_controller_klape_error_valve_passenger          = FALSE;
            state_controller_error_in_while_loop_valve_passenger  = FALSE;
            counter_klape_valve_passenger                         = 1200;
         }
      }
      Stop_Valve_Passenger();
      DELAY_MS(100);
   }
//*************************************************************************************************************************************************//
//********************************************************************SCANNING*********************************************************************//
//*************************************************************************************************************************************************//
   VOID Scan_Klape_Time(){
//**********************************************************************************************************************************DRIVER**VALVE**//
      IF(!state_error_valve_driver){
         state_scan_klape_time                     = TRUE;
         Turn_Left_Valve_Driver();
         DELAY_MS(500);
         time_valve_driver_starting                = get_ticks();
         WHILE(state_scan_klape_time){
            time_valve_driver_current              = get_ticks();
            Turn_Left_Valve_Driver();
            Read_Current_Valve();
            IF(value_current_valve > VALUE_SIDE_CURRENT_VALVE_DRIVER){
               state_scan_klape_time               = FALSE;
               Stop_Valve_Driver();
            }
         }
      }
      Stop_Valve_Driver();
      DELAY_MS(100);
//*******************************************************************************************************************************PASSENGER**VALVE**//
      IF(!state_error_valve_passenger){
         state_scan_klape_time                     = TRUE;
         Turn_Left_Valve_Passenger();
         DELAY_MS(500);
         time_valve_passenger_starting             = get_ticks();
         WHILE(state_scan_klape_time){
            time_valve_passenger_current           = get_ticks();
            Turn_Left_Valve_Passenger();
            Read_Current_Valve();
            IF(value_current_valve > VALUE_SIDE_CURRENT_VALVE_PASSENGER){
               state_scan_klape_time               = FALSE;
               Stop_Valve_Passenger();
            }
         }
      }
      Stop_Valve_Passenger();
      DELAY_MS(100);
//*****************************************************************************************************************************CREATE**MID**VALUE**//
      IF(!state_error_valve_driver){
         time_valve_driver_difference              = Ticks_Difference(time_valve_driver_starting, time_valve_driver_current);
         time_controller_valve_driver              = (time_valve_driver_difference - 400);
         time_error_valve_driver_difference        = (2 * time_valve_driver_difference);
         time_valve_driver_mid                     = ((time_valve_driver_difference / 2) - 400);
      }
      IF(!state_error_valve_passenger){
         time_valve_passenger_difference           = Ticks_Difference(time_valve_passenger_starting, time_valve_passenger_current);
         time_controller_valve_passenger           = (time_valve_passenger_difference - 400);
         time_error_valve_passenger_difference     = (2 * time_valve_passenger_difference);
         time_valve_passenger_mid                  = ((time_valve_passenger_difference / 2) - 400);
      }
   }
//*************************************************************************************************************************************************//
//*********************************************************CONTROL**KLAPE**MOTOR**ERROR************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Klape_Error(){
//**********************************************************************************************************************************VALVE**DRIVER**//
      WHILE(state_controller_klape_error_valve_driver){
         counter_controller_klape_error_valve_driver ++;
         IF(counter_controller_klape_error_valve_driver == 10000){
            OUTPUT_HIGH(LED_VALVE_DRIVER_0);
            OUTPUT_HIGH(LED_VALVE_DRIVER_1);
            OUTPUT_HIGH(LED_VALVE_DRIVER_2);
         }
         IF(counter_controller_klape_error_valve_driver == 20000){
            counter_controller_klape_error_valve_driver        = 0;
            OUTPUT_LOW(LED_VALVE_DRIVER_0);
            OUTPUT_LOW(LED_VALVE_DRIVER_1);
            OUTPUT_LOW(LED_VALVE_DRIVER_2);
         }
         counter_controller_klape_error_inner_valve_driver     = 0;
         WHILE(!INPUT(BUTTON_VALVE_DRIVER)){
            counter_controller_klape_error_inner_valve_driver++;
            IF(counter_controller_klape_error_inner_valve_driver == 200000){
               state_controller_klape_error_valve_driver       = FALSE;
               OUTPUT_LOW(LED_VALVE_DRIVER_0);
               OUTPUT_LOW(LED_VALVE_DRIVER_1);
               OUTPUT_LOW(LED_VALVE_DRIVER_2);
            }
         }
      }
//*******************************************************************************************************************************VALVE**PASSENGER**//
      WHILE(state_controller_klape_error_valve_passenger){
         counter_controller_klape_error_valve_passenger++;
         IF(counter_controller_klape_error_valve_passenger== 10000){
            OUTPUT_HIGH(LED_VALVE_PASSENGER_0);
            OUTPUT_HIGH(LED_VALVE_PASSENGER_1);
            OUTPUT_HIGH(LED_VALVE_PASSENGER_2);
         }
         IF(counter_controller_klape_error_valve_passenger == 20000){
            counter_controller_klape_error_valve_passenger     = 0;
            OUTPUT_LOW(LED_VALVE_PASSENGER_0);
            OUTPUT_LOW(LED_VALVE_PASSENGER_1);
            OUTPUT_LOW(LED_VALVE_PASSENGER_2);
         }
         counter_controller_klape_error_inner_valve_passenger  = 0;
         WHILE(!INPUT(BUTTON_VALVE_PASSENGER)){
            counter_controller_klape_error_inner_valve_passenger++;
            IF(counter_controller_klape_error_inner_valve_passenger == 200000){
               state_controller_klape_error_valve_passenger    = FALSE;
               OUTPUT_LOW(LED_VALVE_PASSENGER_0);
               OUTPUT_LOW(LED_VALVE_PASSENGER_1);
               OUTPUT_LOW(LED_VALVE_PASSENGER_2);
            }
         }
      }
   }
//*************************************************************************************************************************************************//
//*****************************************************MAKE**DEFAULT**VALUE**WHEN**STARTING********************************************************//
//*************************************************************************************************************************************************//
   VOID Make_Default_Value(){
      OUTPUT_LOW(LED_FAN_DRIVER_1);
      OUTPUT_LOW(LED_FAN_DRIVER_2);
      OUTPUT_LOW(LED_FAN_DRIVER_3);
      OUTPUT_LOW(LED_FAN_PASSENGER_1);
      OUTPUT_LOW(LED_FAN_PASSENGER_2);
      OUTPUT_LOW(LED_VALVE_DRIVER_0);
      OUTPUT_LOW(LED_VALVE_DRIVER_1);
      OUTPUT_LOW(LED_VALVE_DRIVER_2);
      OUTPUT_LOW(LED_VALVE_PASSENGER_0);
      OUTPUT_LOW(LED_VALVE_PASSENGER_1);
      OUTPUT_LOW(LED_VALVE_PASSENGER_2);
      SETUP_CCP1(CCP_OFF);
      SETUP_CCP2(CCP_OFF);
      Stop_Valve_Driver();
      Stop_Valve_Passenger();
      OUTPUT_LOW(AIR_CONDITIONING_OUT);
      OUTPUT_LOW(POMP_OUT);
      counter_fan_driver                           = ALL_ZERO_8_BIT;
      counter_fan_passenger                        = ALL_ZERO_8_BIT;
      counter_valve_driver_status                  = ALL_ZERO_8_BIT;
      counter_valve_passenger_status               = ALL_ZERO_8_BIT;
      value_pwm_fan_driver                         = ALL_ZERO_16_BIT;
      value_pwm_fan_passenger                      = ALL_ZERO_16_BIT;
      state_turn_complete_valve_driver             = FALSE;
      state_turn_complete_valve_passenger          = FALSE;
   }
//*************************************************************************************************************************************************//
//*************************************************READ**VALUE**WHEN**BEFORE**SHUTDOWN**FROM**EEPROM***********************************************//
//*************************************************************************************************************************************************//
   VOID Read_Value_From_EEPROM(){
      IF(!state_error_valve_driver){
         counter_valve_driver                      = READ_EEPROM(address_valve_driver);
         counter_valve_driver_status               = 0;
      }
      ELSE{
         counter_valve_driver                      = 0;
         counter_valve_driver_status               = 0;
      }
      IF(!state_error_valve_passenger){
         counter_valve_passenger                   = READ_EEPROM(address_valve_passenger);
         counter_valve_passenger_status            = 0;
      }
      ELSE{
         counter_valve_passenger                   = 0;
         counter_valve_passenger_status            = 0;
      }
   }
//*************************************************************************************************************************************************//
//*****************************************************START**WORKING**ACCORDING**TO**EEPROM**VALUE************************************************//
//*************************************************************************************************************************************************//
   VOID Work_According_To_EEPROM_Value(){
      Controller_Valve_Driver();
      Controller_Valve_Passenger();
      Controller_Fan_Driver();
      Controller_Fan_Passenger();
      Controller_Led_Fan_Driver();
      Controller_Led_Fan_Passenger();
      Controller_Led_Valve_Driver();
      Controller_Led_Valve_Passenger();
      Controller_Pomp();
      Controller_Time_Pomp();
      Controller_Air_Conditioning_Out_On_Info();
      Controller_Air_Conditioning_Signal();
   }
//*************************************************************************************************************************************************//
//***************************************************************CONTROLLER**FUNCTIONS*************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Functions(){
//*************************************************************************************************************************************************//
      Controller_Error_In_Button();
      Controller_Error_In_While_Loop();
      Controller_Pomp();
      Controller_Time_Pomp();
      Controller_Air_Conditioning_Out_On_Info();
      Controller_Air_Conditioning_Signal();
//*************************************************************************************************************************************************//
      IF(!(counter_fan_driver == counter_fan_driver_old)){
         Controller_Fan_Driver();
      }
//*************************************************************************************************************************************************//
      IF(!(counter_fan_passenger == counter_fan_passenger_old)){
         Controller_Fan_Passenger();
      }
//*************************************************************************************************************************************************//
      IF(!state_error_valve_driver){
         IF(!(counter_valve_driver == counter_valve_driver_old)){
            Controller_Valve_Driver();
         }
      }
//*************************************************************************************************************************************************//
      IF(!state_error_valve_passenger){
         IF(!(counter_valve_passenger == counter_valve_passenger_old)){
            Controller_Valve_Passenger();
         }
      }
   }
//*************************************************************************************************************************************************//
//*****************************************************CONTROLLER**FUNCTIONS**IN**CONTROLLER**WHILE************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Led_Functions(){
//*************************************************************************************************************************************************//
      Controller_Error_In_Button();
      Controller_Air_Conditioning_Out_On_Info();
      Controller_Air_Conditioning_Signal();
//*************************************************************************************************************************************************//
      Controller_Error_In_Button();
//*************************************************************************************************************************************************//
      Controller_Led_Fan_Driver();
//*************************************************************************************************************************************************//
      Controller_Led_Fan_Passenger();
//*************************************************************************************************************************************************//
      IF(!state_error_valve_driver){
         Controller_Led_Valve_Driver();
      }
//*************************************************************************************************************************************************//
      IF(!state_error_valve_passenger){
         Controller_Led_Valve_Passenger();
      }
   }     
//*************************************************************************************************************************************************//
//***********************************************************BUTTON**CONTROLLER**FUNCTIONs*********************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Functions(){
//***********************************************************************************************************WHEN**PUSH**THE**DRIVER**FAN**BUTTON**//
      Button_Controller_Fan_Driver();
//********************************************************************************************************WHEN**PUSH**THE**PASSENGER**FAN**BUTTON**//
      Button_Controller_Fan_Passenger();
//*************************************************************************************************************************************************//
      IF(!state_air_conditioning_out_on_info){
//*********************************************************************************************************WHEN**PUSH**THE**DRIVER**VALVE**BUTTON**//
         Button_Controller_Valve_Driver();
//******************************************************************************************************WHEN**PUSH**THE**PASSENGER**VALVE**BUTTON**//
         Button_Controller_Valve_Passenger();
      }
   }
//*************************************************************************************************************************************************//
//***********************************************************CONTROL**BUTTON**DRIVER**FAN**********************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Fan_Driver(){
//*************************************************************************************************************************************************//
      IF((!INPUT(BUTTON_FAN_DRIVER)) && (state_button_fan_driver)){
         DELAY_MS(250);
         state_button_fan_driver                = FALSE;
         counter_fan_driver++;
      }
//*************************************************************************************************************************************************//
      IF(INPUT(BUTTON_FAN_DRIVER)){
         state_button_fan_driver                = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//**********************************************************CONTROL**BUTTON**PASSENGER**FAN********************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Fan_Passenger(){
//*************************************************************************************************************************************************//
      IF((!INPUT(BUTTON_FAN_PASSENGER)) && (state_button_fan_passenger)){
         DELAY_MS(250);
         state_button_fan_passenger             = FALSE;
         counter_fan_passenger++;
      }
//*************************************************************************************************************************************************//
      IF(INPUT(BUTTON_FAN_PASSENGER)){
         state_button_fan_passenger             = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//***********************************************************CONTROL**BUTTON**DRIVER**VALVE********************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Valve_Driver(){
      IF((!INPUT(BUTTON_VALVE_DRIVER)) && (state_button_valve_driver)){
//*************************************************************************************************************************************************//
         DELAY_MS(250);
         state_button_valve_driver              = FALSE;
         IF(!state_error_valve_driver){
            counter_valve_driver++;
            write_eeprom(address_valve_driver, counter_valve_driver);
         }
         ELSE{
            state_controller_error_in_button_valve_driver      = TRUE;
            Controller_Pomp();
            Controller_Time_Pomp();
         }
      }
//*************************************************************************************************************************************************//
      IF(INPUT(BUTTON_VALVE_DRIVER)){
         state_button_valve_driver              = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//*********************************************************CONTROL**BUTTON**PASSENGER**VALVE*******************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Valve_Passenger(){
      IF((!INPUT(BUTTON_VALVE_PASSENGER)) && (state_button_valve_passenger)){
//*************************************************************************************************************************************************//
         DELAY_MS(250);
         state_button_valve_passenger           = FALSE;
         IF(!state_error_valve_passenger){
            counter_valve_passenger++;
            write_eeprom(address_valve_passenger, counter_valve_passenger);
         }
         ELSE{
            state_controller_error_in_button_valve_passenger   = TRUE;
            Controller_Pomp();
            Controller_Time_Pomp();
         }
      }
//*************************************************************************************************************************************************//
      IF(INPUT(BUTTON_VALVE_PASSENGER)){
         state_button_valve_passenger           = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//**************************************************************DRIVER**FAN**CONTROLLER************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Fan_Driver(){
//*************************************************************************************************************************************COUNTER**O**//
      IF((counter_fan_driver % 4) == 0){
         counter_fan_driver                        = 0;
         counter_fan_driver_old                    = counter_fan_driver;
         value_pwm_fan_driver                      = PWM_FAN_DRIVER_STEP_0;
         set_pwm2_duty(PWM_FAN_DRIVER_STEP_0);
         PWM_SETUP_FAN_DRIVER_OFF;
      }
//*************************************************************************************************************************************COUNTER**1**//
      IF((counter_fan_driver % 4) == 1){
         counter_fan_driver_old                    = counter_fan_driver;
         counter_controller_fan_in_while           = 0;
         PWM_SETUP_FAN_DRIVER_ON;
//**********************************************************************************************************************************START**PWM**0**//
         IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_0){   
           FOR(value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_0 ; value_pwm_fan_driver <= PWM_FAN_DRIVER_STEP_1 ; value_pwm_fan_driver++){
               set_pwm2_duty(value_pwm_fan_driver);
               DELAY_MS(5);
               counter_controller_fan_in_while++;
               IF(counter_controller_fan_in_while > 100){ 
                  counter_controller_fan_in_while = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
               }
            }
            value_pwm_fan_driver                   = PWM_FAN_DRIVER_STEP_1 ;
            set_pwm2_duty(PWM_FAN_DRIVER_STEP_1);
         }
         ELSE{
            value_pwm_fan_driver                   = PWM_FAN_DRIVER_STEP_1;
            set_pwm2_duty(PWM_FAN_DRIVER_STEP_1);
         }
      }
//*************************************************************************************************************************************COUNTER**2**//
      IF((counter_fan_driver % 4) == 2){
         counter_fan_driver_old                    = counter_fan_driver;
         counter_controller_fan_in_while           = 0;
         PWM_SETUP_FAN_DRIVER_ON;
//**********************************************************************************************************************************START**PWM**0**//
         IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_0){
            FOR(value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_0 ; value_pwm_fan_driver <= PWM_FAN_DRIVER_STEP_2 ; value_pwm_fan_driver++){
               set_pwm2_duty(value_pwm_fan_driver);
               DELAY_MS(5);
               counter_controller_fan_in_while++;
               IF(counter_controller_fan_in_while > 100){ 
                  counter_controller_fan_in_while = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
               }
            }
            value_pwm_fan_driver                   = PWM_FAN_DRIVER_STEP_2 ;
            set_pwm2_duty(PWM_FAN_DRIVER_STEP_2);
         }
//********************************************************************************************************************************START**PWM**600**//
         ELSE IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_1){
            FOR(value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_1 ; value_pwm_fan_driver <= PWM_FAN_DRIVER_STEP_2 ; value_pwm_fan_driver++){
               set_pwm2_duty(value_pwm_fan_driver);
               DELAY_MS(5);
               counter_controller_fan_in_while++;
               IF(counter_controller_fan_in_while > 100){ 
                  counter_controller_fan_in_while = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
               }
            }
            value_pwm_fan_driver                   = PWM_FAN_DRIVER_STEP_2 ;
            set_pwm2_duty(PWM_FAN_DRIVER_STEP_2);
         }
         ELSE{
            value_pwm_fan_driver                   = PWM_FAN_DRIVER_STEP_2 ;
            set_pwm2_duty(PWM_FAN_DRIVER_STEP_2);
         }
      }
//*************************************************************************************************************************************COUNTER**3**//
      IF((counter_fan_driver % 4) == 3){
         counter_fan_driver_old                    = counter_fan_driver;
         counter_controller_fan_in_while           = 0;
         PWM_SETUP_FAN_DRIVER_ON;
//**********************************************************************************************************************************START**PWM**0**//
         IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_0){
            FOR(value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_0 ; value_pwm_fan_driver <= PWM_FAN_DRIVER_STEP_3 ; value_pwm_fan_driver++){
               set_pwm2_duty(value_pwm_fan_driver);
               DELAY_MS(5);
               counter_controller_fan_in_while++;
               IF(counter_controller_fan_in_while > 100){ 
                  counter_controller_fan_in_while = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
               }
            }
            value_pwm_fan_driver                   = PWM_FAN_DRIVER_STEP_3 ;
            set_pwm2_duty(PWM_FAN_DRIVER_STEP_3);
         }
//********************************************************************************************************************************START**PWM**600**//
         ELSE IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_1){
            FOR(value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_1 ; value_pwm_fan_driver <= PWM_FAN_DRIVER_STEP_3 ; value_pwm_fan_driver++){
               set_pwm2_duty(value_pwm_fan_driver);
               DELAY_MS(5);
               counter_controller_fan_in_while++;
               IF(counter_controller_fan_in_while > 100){ 
                  counter_controller_fan_in_while = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
               }
            }
            value_pwm_fan_driver                   = PWM_FAN_DRIVER_STEP_3 ;
            set_pwm2_duty(PWM_FAN_DRIVER_STEP_3);
         }
//********************************************************************************************************************************START**PWM**850**//
         ELSE IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_2){
            FOR(value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_2 ; value_pwm_fan_driver <= PWM_FAN_DRIVER_STEP_3 ; value_pwm_fan_driver++){
               set_pwm2_duty(value_pwm_fan_driver);
               DELAY_MS(5);
               counter_controller_fan_in_while++;
               IF(counter_controller_fan_in_while > 100){ 
                  counter_controller_fan_in_while = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
               }
            }
            value_pwm_fan_driver                   = PWM_FAN_DRIVER_STEP_3 ;
            set_pwm2_duty(PWM_FAN_DRIVER_STEP_3);
         }
         ELSE{
            value_pwm_fan_driver                   = PWM_FAN_DRIVER_STEP_3 ;
            set_pwm2_duty(PWM_FAN_DRIVER_STEP_3);
         }
      }
   }
//*************************************************************************************************************************************************//
//**********************************************************DRIVER**FAN**CONTROLLER**IN**WHILE*****************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Led_Fan_Driver(){
//*************************************************************************************************************************************COUNTER**O**//
      IF((counter_fan_driver % 4) == 0){
         OUTPUT_LOW(LED_FAN_DRIVER_1);
         OUTPUT_LOW(LED_FAN_DRIVER_2);
         OUTPUT_LOW(LED_FAN_DRIVER_3);
      }
//*************************************************************************************************************************************COUNTER**1**//
      IF((counter_fan_driver % 4) == 1){
         OUTPUT_HIGH(LED_FAN_DRIVER_1);
         OUTPUT_LOW(LED_FAN_DRIVER_2);
         OUTPUT_LOW(LED_FAN_DRIVER_3);
      }       
//*************************************************************************************************************************************COUNTER**2**//
      IF((counter_fan_driver % 4) == 2){
         OUTPUT_HIGH(LED_FAN_DRIVER_1);
         OUTPUT_HIGH(LED_FAN_DRIVER_2);
         OUTPUT_LOW(LED_FAN_DRIVER_3);
      }
//*************************************************************************************************************************************COUNTER**3**//
      IF((counter_fan_driver % 4) == 3){
         OUTPUT_HIGH(LED_FAN_DRIVER_1);
         OUTPUT_HIGH(LED_FAN_DRIVER_2);
         OUTPUT_HIGH(LED_FAN_DRIVER_3);
      }
   }    
//*************************************************************************************************************************************************//
//*************************************************************PASSENGER**FAN**CONTROLLER**********************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Fan_Passenger(){
//*************************************************************************************************************************************COUNTER**O**//
      IF((counter_fan_passenger % 3) == 0){
         counter_fan_passenger                     = 0;
         counter_fan_passenger_old                 = counter_fan_passenger;
         value_pwm_fan_passenger                   = PWM_FAN_PASSENGER_STEP_0 ;
         set_pwm1_duty(PWM_FAN_PASSENGER_STEP_0);
         PWM_SETUP_FAN_PASSENGER_OFF;
      }
//*************************************************************************************************************************************COUNTER**1**//
      IF((counter_fan_passenger % 3) == 1){
         counter_fan_passenger_old                 = counter_fan_passenger;
         counter_controller_fan_in_while           = 0;
         PWM_SETUP_FAN_PASSENGER_ON;
//**********************************************************************************************************************************START**PWM**0**//
         IF(value_pwm_fan_passenger == PWM_FAN_PASSENGER_STEP_0){
            FOR(value_pwm_fan_passenger = PWM_FAN_PASSENGER_STEP_0 ; value_pwm_fan_passenger <= PWM_FAN_PASSENGER_STEP_1 ; value_pwm_fan_passenger++){
               set_pwm1_duty(value_pwm_fan_passenger);
               DELAY_MS(5);
               counter_controller_fan_in_while++;
               IF(counter_controller_fan_in_while > 100){ 
                  counter_controller_fan_in_while = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
               }
            }
            value_pwm_fan_passenger                = PWM_FAN_PASSENGER_STEP_1 ;
            set_pwm1_duty(PWM_FAN_PASSENGER_STEP_1);
         }
         ELSE{
            value_pwm_fan_passenger                = PWM_FAN_PASSENGER_STEP_1 ;
            set_pwm1_duty(PWM_FAN_PASSENGER_STEP_1);
         }
      }
//*************************************************************************************************************************************COUNTER**2**//
      IF((counter_fan_passenger % 3) == 2){
         counter_fan_passenger_old                 = counter_fan_passenger;
         counter_controller_fan_in_while           = 0;
         PWM_SETUP_FAN_PASSENGER_ON;
//**********************************************************************************************************************************START**PWM**0**//
         IF(value_pwm_fan_passenger == PWM_FAN_PASSENGER_STEP_0){
            FOR(value_pwm_fan_passenger = PWM_FAN_PASSENGER_STEP_0 ; value_pwm_fan_passenger <= PWM_FAN_PASSENGER_STEP_2 ; value_pwm_fan_passenger++){
               set_pwm1_duty(value_pwm_fan_passenger);
               DELAY_MS(5);
               counter_controller_fan_in_while++;
               IF(counter_controller_fan_in_while > 100){ 
                  counter_controller_fan_in_while = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
               }
            }
            value_pwm_fan_passenger                = PWM_FAN_PASSENGER_STEP_2 ;
            set_pwm1_duty(PWM_FAN_PASSENGER_STEP_2);
         }
//********************************************************************************************************************************START**PWM**700**//
         ELSE IF(value_pwm_fan_passenger == PWM_FAN_PASSENGER_STEP_1){
            FOR(value_pwm_fan_passenger = PWM_FAN_PASSENGER_STEP_1 ; value_pwm_fan_passenger <= PWM_FAN_PASSENGER_STEP_2 ; value_pwm_fan_passenger++){
               set_pwm1_duty(value_pwm_fan_passenger);
               DELAY_MS(5);
               counter_controller_fan_in_while++;
               IF(counter_controller_fan_in_while > 100){ 
                  counter_controller_fan_in_while = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
               }
            }
            value_pwm_fan_passenger                = PWM_FAN_PASSENGER_STEP_2 ;
            set_pwm1_duty(PWM_FAN_PASSENGER_STEP_2);
         }
         ELSE{
            value_pwm_fan_passenger                = PWM_FAN_PASSENGER_STEP_2 ;
            set_pwm1_duty(PWM_FAN_PASSENGER_STEP_2);
         }
      }
   }
//*************************************************************************************************************************************************//
//********************************************************PASSENGER**FAN**CONTROLLER**IN**WHILE****************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Led_Fan_Passenger(){
//*************************************************************************************************************************************COUNTER**O**//
      IF((counter_fan_passenger % 3) == 0){
         OUTPUT_LOW(LED_FAN_PASSENGER_1);
         OUTPUT_LOW(LED_FAN_PASSENGER_2);
      }
//*************************************************************************************************************************************COUNTER**1**//
      IF((counter_fan_passenger % 3) == 1){
         OUTPUT_HIGH(LED_FAN_PASSENGER_1);
         OUTPUT_LOW(LED_FAN_PASSENGER_2);
      }
//*************************************************************************************************************************************COUNTER**2**//
      IF((counter_fan_passenger % 3) == 2){
         OUTPUT_HIGH(LED_FAN_PASSENGER_1);
         OUTPUT_HIGH(LED_FAN_PASSENGER_2);
      }
   }
//*************************************************************************************************************************************************//
//*************************************************************DRIVER**VALVE**CONTROLLER***********************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Valve_Driver(){
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
      IF(!state_error_valve_driver){
//*************************************************************************************************************************************COUNTER**0**//
         IF((counter_valve_driver % 3) == 0){
            counter_valve_driver                                  = 0;
            counter_valve_driver_old                              = counter_valve_driver;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
            Turn_Left_Valve_Driver();
            DELAY_MS(400);
            time_in_while_valve_driver_starting                   = get_ticks();
            DELAY_MS(100);
            state_time_in_while_valve_driver                      = TRUE;
            state_time_in_while_start_valve_driver                = TRUE;
            time_valve_driver_starting                            = get_ticks();
            counter_button_controller_functions                   = 0;
            state_turn_complete_valve_driver                      = FALSE;
//*************************************************************************************************************************************************//
            WHILE(!state_turn_complete_valve_driver){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions             = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
               }
               time_valve_driver_current                          = get_ticks();
               time_valve_driver_difference                       = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
               Turn_Left_Valve_Driver();
               DELAY_MS(30);
               Read_Current_Valve();
               IF(value_current_valve > VALUE_SIDE_CURRENT_VALVE_DRIVER){
                  IF(time_valve_driver_difference > time_controller_valve_driver){
                     Stop_Valve_Driver();
                     DELAY_MS(100);
                     state_turn_complete_valve_driver             = TRUE;
                     state_time_in_while_valve_driver             = FALSE;
                     state_time_in_while_start_valve_driver       = FALSE;
                     counter_valve_driver_status                  = 0;
                  }
               }
               Controller_Time_In_While_Valve_Driver();
            }
         }
//*************************************************************************************************************************************COUNTER**1**//
         IF((counter_valve_driver % 3) == 1){
            counter_valve_driver_old                                 = counter_valve_driver;
//****************************************************************************************************************IF**COME**FROM**CLOSE**POSITION**//
            IF((counter_valve_driver_status % 3) == 0){
               Turn_Left_Valve_Driver();
               DELAY_MS(250);
               Read_Current_Valve();
               Stop_Valve_Driver();
               DELAY_MS(100);
//*************************************************************************************************************************************************//
               IF(value_current_valve < VALUE_SIDE_CURRENT_TEST){
                  state_error_valve_driver                           = TRUE;
                  state_controller_error_in_while_loop_valve_driver  = TRUE;
                  state_controller_error_in_button_valve_driver      = TRUE;
               }
               ELSE{
                  state_error_valve_driver                           = FALSE;
                  state_controller_error_in_while_loop_valve_driver  = FALSE;
                  state_controller_error_in_button_valve_driver      = FALSE;
               }
               IF(!state_error_valve_driver){
                  Turn_Right_Valve_Driver();
                  DELAY_MS(500);
                  time_valve_driver_starting                         = get_ticks();
                  counter_button_controller_functions                = 0;
                  state_turn_complete_valve_driver                   = FALSE;
//*************************************************************************************************************************************************//
                  WHILE(!state_turn_complete_valve_driver){
                     Turn_Right_Valve_Driver();
                     DELAY_MS(1);
                     counter_button_controller_functions++;
                     IF(counter_button_controller_functions > 500){
                        counter_button_controller_functions          = 0;
                        Button_Controller_Functions(); 
                        Controller_Led_Functions();
                     }
                     time_valve_driver_current                       = get_ticks();
                     time_valve_driver_difference                    = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
                     IF(time_valve_driver_difference > time_valve_driver_mid){
                        Stop_Valve_Driver();
                        DELAY_MS(100);
                        state_turn_complete_valve_driver             = TRUE;
                        counter_valve_driver_status                  = 2;
                     }
                  }
               }
            }
//*****************************************************************************************************************IF**COME**FROM**OPEN**POSITION**//
            IF((counter_valve_driver_status % 3) == 1){
               Turn_Right_Valve_Driver();
               DELAY_MS(250);
               Read_Current_Valve();
               Stop_Valve_Driver();
               DELAY_MS(100);
//*************************************************************************************************************************************************//
               IF(value_current_valve < VALUE_SIDE_CURRENT_TEST){
                  Stop_Valve_Driver();
                  state_error_valve_driver                           = TRUE;
                  state_controller_error_in_while_loop_valve_driver  = TRUE;
                  state_controller_error_in_button_valve_driver      = TRUE;
               }
               ELSE{
                  state_error_valve_driver                           = FALSE;
                  state_controller_error_in_while_loop_valve_driver  = FALSE;
                  state_controller_error_in_button_valve_driver      = FALSE;
               }
               IF(!state_error_valve_driver){
                  Turn_Left_Valve_Driver();
                  DELAY_MS(500);
                  time_valve_driver_starting                         = get_ticks();
                  counter_button_controller_functions                = 0;
                  state_turn_complete_valve_driver                   = FALSE;
//*************************************************************************************************************************************************//
                  WHILE(!state_turn_complete_valve_driver){
                     Turn_Left_Valve_Driver();
                     DELAY_MS(1);
                     counter_button_controller_functions++;
                     IF(counter_button_controller_functions > 500){
                        counter_button_controller_functions          = 0;
                        Button_Controller_Functions(); 
                        Controller_Led_Functions();
                     }
                     time_valve_driver_current                       = get_ticks();
                     time_valve_driver_difference                    = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
                     IF(time_valve_driver_difference > time_valve_driver_mid){
                        Stop_Valve_Driver();
                        DELAY_MS(100);
                        state_turn_complete_valve_driver             = TRUE;
                        counter_valve_driver_status                  = 2;
                     }
                  }
               }
            }
         }
//*************************************************************************************************************************************COUNTER**2**//
         IF((counter_valve_driver % 3) == 2){
            counter_valve_driver_old                              = counter_valve_driver;
            Turn_Right_Valve_Driver();
            DELAY_MS(400);
            time_in_while_valve_driver_starting                   = get_ticks();
            DELAY_MS(100);
            state_time_in_while_valve_driver                      = TRUE;
            state_time_in_while_start_valve_driver                = TRUE;
            time_valve_driver_starting                            = get_ticks();
            counter_button_controller_functions                   = 0;
            state_turn_complete_valve_driver                      = FALSE;
//*************************************************************************************************************************************************//
            WHILE(!state_turn_complete_valve_driver){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions             = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
               }
               time_valve_driver_current                          = get_ticks();
               time_valve_driver_difference                       = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
               Turn_Right_Valve_Driver();
               DELAY_MS(30);
               Read_Current_Valve();
               IF(value_current_valve > VALUE_SIDE_CURRENT_VALVE_DRIVER){
                  IF(time_valve_driver_difference > time_controller_valve_driver){
                     Stop_Valve_Driver();
                     DELAY_MS(100);
                     state_turn_complete_valve_driver             = TRUE;
                     state_time_in_while_valve_driver             = FALSE;
                     state_time_in_while_start_valve_driver       = FALSE;
                     counter_valve_driver_status                  = 1;
                  }
               }
               Controller_Time_In_While_Valve_Driver();
            }
         }
      }
//***************************************************************************************************************************IF**THERE**IS**ERROR**//
      ELSE{
         OUTPUT_LOW(LED_VALVE_DRIVER_0);
         OUTPUT_LOW(LED_VALVE_DRIVER_1);
         OUTPUT_LOW(LED_VALVE_DRIVER_2);
      }
   }
//*************************************************************************************************************************************************//
//***********************************************************DRIVER**VALVE**CONTROLLER**IN**WHILE**************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Led_Valve_Driver(){
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
      IF(!state_error_valve_driver){
//*************************************************************************************************************************************COUNTER**0**//
         IF((counter_valve_driver % 3) == 0){
            OUTPUT_HIGH(LED_VALVE_DRIVER_0);
            OUTPUT_LOW(LED_VALVE_DRIVER_1);
            OUTPUT_LOW(LED_VALVE_DRIVER_2);
         }
//*************************************************************************************************************************************COUNTER**1**//
         IF((counter_valve_driver % 3) == 1){
            OUTPUT_LOW(LED_VALVE_DRIVER_0);
            OUTPUT_HIGH(LED_VALVE_DRIVER_1);
            OUTPUT_LOW(LED_VALVE_DRIVER_2);
         }
//*************************************************************************************************************************************COUNTER**2**//
         IF((counter_valve_driver % 3) == 2){
            OUTPUT_LOW(LED_VALVE_DRIVER_0);
            OUTPUT_HIGH(LED_VALVE_DRIVER_1);
            OUTPUT_HIGH(LED_VALVE_DRIVER_2);
         }
      }
//***************************************************************************************************************************IF**THERE**IS**ERROR**//
      ELSE{
         OUTPUT_LOW(LED_VALVE_DRIVER_0);
         OUTPUT_LOW(LED_VALVE_DRIVER_1);
         OUTPUT_LOW(LED_VALVE_DRIVER_2);
      }
   }     
//*************************************************************************************************************************************************//
//***************************************************************PASSENGER**VALVE**CONTROLLER******************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Valve_Passenger(){
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
      IF(!state_error_valve_passenger){
//*************************************************************************************************************************************COUNTER**0**//
         IF((counter_valve_passenger % 3) == 0){
            counter_valve_passenger                               = 0;
            counter_valve_passenger_old                           = counter_valve_passenger;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
            Turn_Left_Valve_Passenger();
            DELAY_MS(400);
            time_in_while_valve_passenger_starting                = get_ticks();
            DELAY_MS(100);
            state_time_in_while_valve_passenger                   = TRUE;
            state_time_in_while_start_valve_passenger             = TRUE;
            time_valve_passenger_starting                         = get_ticks();
            counter_button_controller_functions                   = 0;
            state_turn_complete_valve_passenger                   = FALSE;
//*************************************************************************************************************************************************//
            WHILE(!state_turn_complete_valve_passenger){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions             = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
               }
               time_valve_passenger_current                       = get_ticks();
               time_valve_passenger_difference                    = Ticks_Difference(time_valve_passenger_starting , time_valve_passenger_current);
               Turn_Left_Valve_Passenger();
               DELAY_MS(30);
               Read_Current_Valve();
               IF(value_current_valve > VALUE_SIDE_CURRENT_VALVE_PASSENGER){
                  IF(time_valve_passenger_difference > time_controller_valve_passenger){
                     Stop_Valve_Passenger();
                     DELAY_MS(100);
                     state_turn_complete_valve_passenger          = TRUE;
                     state_time_in_while_valve_passenger          = FALSE;
                     state_time_in_while_start_valve_passenger    = FALSE;
                     counter_valve_passenger_status               = 0;
                  }
               }
               Controller_Time_In_While_Valve_Passenger();
            }
         }
//*************************************************************************************************************************************COUNTER**1**//
         IF((counter_valve_passenger % 3) == 1){
            counter_valve_passenger_old                           = counter_valve_passenger;
//****************************************************************************************************************IF**COME**FROM**CLOSE**POSITION**//
            IF((counter_valve_passenger_status % 3) == 0){
               Turn_Left_Valve_Passenger();
               DELAY_MS(250);
               Read_Current_Valve();
               Stop_Valve_Passenger();
               DELAY_MS(100);
//*************************************************************************************************************************************************//
               IF(value_current_valve < VALUE_SIDE_CURRENT_TEST){
                  state_error_valve_passenger                           = TRUE;
                  state_controller_error_in_while_loop_valve_passenger  = TRUE;
                  state_controller_error_in_button_valve_passenger      = TRUE;
               }
               ELSE{
                  state_error_valve_passenger                           = FALSE;
                  state_controller_error_in_while_loop_valve_passenger  = FALSE;
                  state_controller_error_in_button_valve_passenger      = FALSE;
               }
               IF(!state_error_valve_passenger){
                  Turn_Right_Valve_Passenger();
                  DELAY_MS(500);
                  time_valve_passenger_starting                         = get_ticks();
                  counter_button_controller_functions                   = 0;
                  state_turn_complete_valve_passenger                   = FALSE;
//*************************************************************************************************************************************************//
                  WHILE(!state_turn_complete_valve_passenger){
                     Turn_Right_Valve_Passenger();
                     DELAY_MS(1);
                     counter_button_controller_functions++;
                     IF(counter_button_controller_functions > 500){
                        counter_button_controller_functions             = 0;
                        Button_Controller_Functions(); 
                        Controller_Led_Functions();
                     }
                     time_valve_passenger_current                       = get_ticks();
                     time_valve_passenger_difference                    = Ticks_Difference(time_valve_passenger_starting , time_valve_passenger_current);
                     IF(time_valve_passenger_difference > time_valve_passenger_mid){
                        Stop_Valve_Passenger();
                        DELAY_MS(100);
                        state_turn_complete_valve_passenger             = TRUE;
                        counter_valve_passenger_status                  = 2;
                     }
                  }
               }
            }
//*****************************************************************************************************************IF**COME**FROM**OPEN**POSITION**//
            IF((counter_valve_passenger_status % 3) == 1){
               Turn_Right_Valve_Passenger();
               DELAY_MS(250);
               Read_Current_Valve();
               Stop_Valve_Passenger();
               DELAY_MS(100);
//*************************************************************************************************************************************************//
               IF(value_current_valve < VALUE_SIDE_CURRENT_TEST){
                  state_error_valve_passenger                           = TRUE;
                  state_controller_error_in_while_loop_valve_passenger  = TRUE;
                  state_controller_error_in_button_valve_passenger      = TRUE;
               }
               ELSE{
                  state_error_valve_passenger                           = FALSE;
                  state_controller_error_in_while_loop_valve_passenger  = FALSE;
                  state_controller_error_in_button_valve_passenger      = FALSE;
               }
               IF(!state_error_valve_passenger){
                  Turn_Left_Valve_Passenger();
                  DELAY_MS(500);
                  time_valve_passenger_starting                         = get_ticks();
                  counter_button_controller_functions                   = 0;
                  state_turn_complete_valve_passenger                   = FALSE;
//*************************************************************************************************************************************************//
                  WHILE(!state_turn_complete_valve_passenger){
                     Turn_Left_Valve_Passenger();
                     DELAY_MS(1);
                     counter_button_controller_functions++;
                     IF(counter_button_controller_functions > 500){
                        counter_button_controller_functions             = 0;
                        Button_Controller_Functions(); 
                        Controller_Led_Functions();
                     }
                     time_valve_passenger_current                       = get_ticks();
                     time_valve_passenger_difference                    = Ticks_Difference(time_valve_passenger_starting , time_valve_passenger_current);
                     IF(time_valve_passenger_difference > time_valve_passenger_mid){
                        Stop_Valve_Passenger();
                        DELAY_MS(100);
                        state_turn_complete_valve_passenger             = TRUE;
                        counter_valve_passenger_status                  = 2;
                     }
                  }
               }
            }
         }
//*************************************************************************************************************************************COUNTER**2**//
         IF((counter_valve_passenger % 3) == 2){
            counter_valve_passenger_old                           = counter_valve_passenger;
            Turn_Right_Valve_Passenger();
            DELAY_MS(400);
            time_in_while_valve_passenger_starting                = get_ticks();
            time_valve_passenger_starting                         = get_ticks();
            DELAY_MS(100);
            state_time_in_while_valve_passenger                   = TRUE;
            state_time_in_while_start_valve_passenger             = TRUE;
            counter_button_controller_functions                   = 0;
            state_turn_complete_valve_passenger                   = FALSE;
//*************************************************************************************************************************************************//
            WHILE(!state_turn_complete_valve_passenger){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions             = 0;
                  Button_Controller_Functions();
                  Controller_Led_Functions();
               }
               time_valve_passenger_current                       = get_ticks();
               time_valve_passenger_difference                    = Ticks_Difference(time_valve_passenger_starting , time_valve_passenger_current);
               Turn_Right_Valve_Passenger();
               DELAY_MS(30);
               Read_Current_Valve();
               IF(value_current_valve > VALUE_SIDE_CURRENT_VALVE_PASSENGER){
                  IF(time_valve_passenger_difference > time_controller_valve_passenger){
                     Stop_Valve_Passenger();
                     DELAY_MS(100);
                     state_turn_complete_valve_passenger          = TRUE;
                     state_time_in_while_valve_passenger          = FALSE;
                     state_time_in_while_start_valve_passenger    = FALSE;
                     counter_valve_passenger_status               = 1;
                  }
               }
               Controller_Time_In_While_Valve_Passenger();
            }
         }
      }
//***************************************************************************************************************************IF**THERE**IS**ERROR**//
      ELSE{
         OUTPUT_LOW(LED_VALVE_PASSENGER_0);
         OUTPUT_LOW(LED_VALVE_PASSENGER_1);
         OUTPUT_LOW(LED_VALVE_PASSENGER_2);
      }
   }
//*************************************************************************************************************************************************//
//********************************************************PASSENGER**VALVE**CONTROLLER**IN**WHILE**************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Led_Valve_Passenger(){
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
      IF(!state_error_valve_passenger){
//*************************************************************************************************************************************COUNTER**0**//
         IF((counter_valve_passenger % 3) == 0){
            OUTPUT_HIGH(LED_VALVE_PASSENGER_0);
            OUTPUT_LOW(LED_VALVE_PASSENGER_1);
            OUTPUT_LOW(LED_VALVE_PASSENGER_2);
         }
//*************************************************************************************************************************************COUNTER**1**//
         IF((counter_valve_passenger % 3) == 1){
            OUTPUT_LOW(LED_VALVE_PASSENGER_0);
            OUTPUT_HIGH(LED_VALVE_PASSENGER_1);
            OUTPUT_LOW(LED_VALVE_PASSENGER_2);
         }
//*************************************************************************************************************************************COUNTER**2**//
         IF((counter_valve_passenger % 3) == 2){
            OUTPUT_LOW(LED_VALVE_PASSENGER_0);
            OUTPUT_HIGH(LED_VALVE_PASSENGER_1);
            OUTPUT_HIGH(LED_VALVE_PASSENGER_2);
         }
      }
//***************************************************************************************************************************IF**THERE**IS**ERROR**//
      ELSE{
         OUTPUT_LOW(LED_VALVE_PASSENGER_0);
         OUTPUT_LOW(LED_VALVE_PASSENGER_1);
         OUTPUT_LOW(LED_VALVE_PASSENGER_2);
      }
   }
//*************************************************************************************************************************************************//
//*******************************************************************ERROR**CONTROL****************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Time_In_While_Valve_Driver(){
//*************************************************************************************************************************************************//
      IF(state_time_in_while_valve_driver){
         time_in_while_valve_driver_current                    = get_ticks();
         time_in_while_valve_driver_difference                 = Ticks_Difference(time_in_while_valve_driver_starting , time_in_while_valve_driver_current);
         IF((time_in_while_valve_driver_difference > time_error_valve_driver_difference) && (state_time_in_while_start_valve_driver)){
            Stop_Valve_Driver();
            DELAY_MS(100);
            state_time_in_while_valve_driver                   = FALSE;
            state_controller_error_in_while_loop_valve_driver  = TRUE;
            state_turn_complete_valve_driver                   = TRUE;
            state_error_valve_driver                           = TRUE;
            state_controller_error_in_button_valve_driver      = TRUE;
            Controller_Pomp();
            Controller_Time_Pomp();
         }
      }
   }
//*************************************************************************************************************************************************//
//*******************************************************************ERROR**CONTROL****************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Time_In_While_Valve_Passenger(){
//*************************************************************************************************************************************************//
      IF(state_time_in_while_valve_passenger){
         time_in_while_valve_passenger_current     = get_ticks();
         time_in_while_valve_passenger_difference  = Ticks_Difference(time_in_while_valve_passenger_starting , time_in_while_valve_passenger_current);
         IF((time_in_while_valve_passenger_difference > time_error_valve_passenger_difference) && (state_time_in_while_start_valve_passenger)){
            Stop_Valve_Passenger();
            DELAY_MS(100);
            state_time_in_while_valve_passenger                      = FALSE;
            state_controller_error_in_while_loop_valve_passenger     = TRUE;
            state_turn_complete_valve_passenger                      = TRUE;
            state_error_valve_passenger                              = TRUE;
            state_controller_error_in_button_valve_passenger         = TRUE;
            Controller_Pomp();
            Controller_Time_Pomp();
         }
      }
   }
//*************************************************************************************************************************************************//
//*******************************************************************ERROR**SHOWING****************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Error_In_While_Loop(){
//**********************************************************************************************************************************VALVE**DRIVER**//
      IF(state_controller_error_in_while_loop_valve_driver){
         Turn_Left_Valve_Driver();
         DELAY_MS(500);
         Button_Controller_Functions(); 
         Controller_Led_Functions();
         Read_Current_Valve();
         Stop_Valve_Driver();
         DELAY_MS(100);
         IF(value_current_valve > VALUE_SIDE_CURRENT_VALVE_DRIVER){
            Stop_Valve_Driver();
            state_error_valve_driver                              = FALSE;
            state_controller_error_in_while_loop_valve_driver     = FALSE;
            Time_Klape_Once_Valve_Driver();
            counter_valve_driver_status                           = 0;
            Controller_Valve_Driver();
            Controller_Led_Valve_Driver();
         }
      }
//*******************************************************************************************************************************VALVE**PASSENGER**//
      IF(state_controller_error_in_while_loop_valve_passenger){
         Turn_Left_Valve_Passenger();
         DELAY_MS(500);
         Button_Controller_Functions(); 
         Controller_Led_Functions();
         Read_Current_Valve();
         Stop_Valve_Passenger();
         DELAY_MS(100);
         IF(value_current_valve > VALUE_SIDE_CURRENT_VALVE_PASSENGER){
            Stop_Valve_Passenger();
            state_error_valve_passenger                              = FALSE;
            state_controller_error_in_while_loop_valve_passenger     = FALSE;
            Time_Klape_Once_Valve_Passenger();
            counter_valve_passenger_status                           = 0;
            Controller_Valve_Passenger();
            Controller_Led_Valve_Passenger();
         }
      }
   }
//*************************************************************************************************************************************************//
//**********************************************************************KLIMA**********************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Air_Conditioning_Out_On_Info(){
         IF(INPUT(AIR_CONDITIONING_OUT_ON_INFO)){
            IF(state_air_conditioning_out_on_info_once){
               state_air_conditioning_out_on_info              = TRUE;
               state_controller_pomp_on                        = FALSE;
               counter_valve_driver                            = 0;
               counter_valve_passenger                         = 0;
               Controller_Pomp();
               Controller_Time_Pomp();
               state_air_conditioning_out_on_info_once         = FALSE;
            }
         }
         IF(!INPUT(AIR_CONDITIONING_OUT_ON_INFO)){
            state_air_conditioning_out_on_info                 = FALSE;
            state_air_conditioning_out_on_info_once            = TRUE;
         }
   }
//*************************************************************************************************************************************************//
//**********************************************************************KLIMA**********************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Air_Conditioning_Signal(){
      IF((state_air_conditioning_out_on_info) && !((counter_fan_driver % 4) == 0)){
         OUTPUT_HIGH(AIR_CONDITIONING_OUT);
      }
      ELSE{
         OUTPUT_LOW(AIR_CONDITIONING_OUT);
      }
   }
//*************************************************************************************************************************************************//
//**********************************************************************POMP***********************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Pomp(){
//*************************************************************************************************************************************************//
      IF((state_error_valve_driver) && (state_error_valve_passenger)){
         state_controller_pomp_on               = FALSE;
      }
//*************************************************************************************************************************************************//
      ELSE IF((!state_error_valve_driver) && (state_error_valve_passenger)){
         IF((counter_valve_driver % 3) == 0){
            state_controller_pomp_on            = FALSE;
         }
         ELSE{
            state_controller_pomp_on            = TRUE;
            IF(state_process_complete_pomp){
               state_process_complete_pomp      = FALSE;
               time_controller_pomp_starting    = get_ticks();
            }
         }
      }
//*************************************************************************************************************************************************//
      ELSE IF((state_error_valve_driver) && (!state_error_valve_passenger)){
         IF((counter_valve_passenger % 3) == 0){
            state_controller_pomp_on            = FALSE;
         }
         ELSE{
            state_controller_pomp_on            = TRUE;
            IF(state_process_complete_pomp){
               state_process_complete_pomp      = FALSE;
               time_controller_pomp_starting    = get_ticks();
            }
         }
      }
//*************************************************************************************************************************************************//
      ELSE IF((!state_error_valve_driver) && (!state_error_valve_passenger)){
         IF(((counter_valve_driver % 3) == 0) && ((counter_valve_passenger % 3) == 0)){
            state_controller_pomp_on            = FALSE;
         }
         ELSE{
            state_controller_pomp_on            = TRUE;
            IF(state_process_complete_pomp){
               state_process_complete_pomp      = FALSE;
               time_controller_pomp_starting    = get_ticks();
            }
         }
      }
   }
//*************************************************************************************************************************************************//
//**********************************************************************POMP***********************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Time_Pomp(){
      IF(state_controller_pomp_on){
         IF(!state_process_complete_pomp){
            time_controller_pomp_current                       = get_ticks();
            time_controller_pomp_difference                    = Ticks_Difference(time_controller_pomp_starting , time_controller_pomp_current);
            IF(time_controller_pomp_difference > TIME_POMP_ON){
               state_process_complete_pomp                     = TRUE;
               OUTPUT_HIGH(POMP_OUT);
            }
         }
      }
      ELSE{
         state_process_complete_pomp                           = TRUE;
         OUTPUT_LOW(POMP_OUT);
      }
   }
//*************************************************************************************************************************************************//
//**************************************************************CONTROL**ERROR**IN**BUTTON*********************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Error_In_Button(){
//*************************************************************************************************************************************************//
      IF(state_controller_error_in_button_valve_driver){
         OUTPUT_HIGH(LED_VALVE_DRIVER_0);   
         OUTPUT_HIGH(LED_VALVE_DRIVER_1);
         OUTPUT_HIGH(LED_VALVE_DRIVER_2);
         DELAY_MS(120);
         OUTPUT_LOW(LED_VALVE_DRIVER_0); 
         OUTPUT_LOW(LED_VALVE_DRIVER_1);
         OUTPUT_LOW(LED_VALVE_DRIVER_2);
         DELAY_MS(80);
         OUTPUT_HIGH(LED_VALVE_DRIVER_0);
         OUTPUT_HIGH(LED_VALVE_DRIVER_1);
         OUTPUT_HIGH(LED_VALVE_DRIVER_2);
         DELAY_MS(120);
         OUTPUT_LOW(LED_VALVE_DRIVER_0); 
         OUTPUT_LOW(LED_VALVE_DRIVER_1);
         OUTPUT_LOW(LED_VALVE_DRIVER_2);
         state_controller_error_in_button_valve_driver         = FALSE;
      }
//*************************************************************************************************************************************************//
      IF(state_controller_error_in_button_valve_passenger){
         OUTPUT_HIGH(LED_VALVE_PASSENGER_0);
         OUTPUT_HIGH(LED_VALVE_PASSENGER_1);
         OUTPUT_HIGH(LED_VALVE_PASSENGER_2);
         DELAY_MS(120);
         OUTPUT_LOW(LED_VALVE_PASSENGER_0);
         OUTPUT_LOW(LED_VALVE_PASSENGER_1);
         OUTPUT_LOW(LED_VALVE_PASSENGER_2);
         DELAY_MS(80);
         OUTPUT_HIGH(LED_VALVE_PASSENGER_0);
         OUTPUT_HIGH(LED_VALVE_PASSENGER_1);
         OUTPUT_HIGH(LED_VALVE_PASSENGER_2);
         DELAY_MS(120);
         OUTPUT_LOW(LED_VALVE_PASSENGER_0);
         OUTPUT_LOW(LED_VALVE_PASSENGER_1);
         OUTPUT_LOW(LED_VALVE_PASSENGER_2);
         state_controller_error_in_button_valve_passenger      = FALSE;
      }
   }
//*************************************************************************************************************************************************//
//**************************************************************MEASURE**TICKs**DIFFERENCE*********************************************************//
//*************************************************************************************************************************************************//
   INT32 Ticks_Difference(INT32 time_starting, INT32 time_current){
      time_difference                                          = (time_current - time_starting);
      RETURN time_difference;
   }
//*************************************************************************************************************************************************//
//*******************************************************************READ**MOTOR*******************************************************************//
//*************************************************************************************************************************************************//
//*********************************************************************************************************************************CURRENT**VALVE**//
   VOID Read_Current_Valve(){
      value_current_valve                                      = 0;
      FOR(INT8 i = 0; i < 10; i++){
         SET_ADC_CHANNEL(CHANNEL_Current_Valve);
         DELAY_MS(2);
         value_current_temporary                               = READ_ADC();
         value_current_valve                                   = value_current_valve + value_current_temporary;
      }
      value_current_valve                                      = (value_current_valve / 10);
   }
//*************************************************************************************************************************************************//
//****************************************************************MOVEMENT**MOTOR******************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
//***********************************************************************************************************************************DRIVER**VANA**//
//*************************************************************************************************************************************************//
//************************************************************************************************************************************TURN**RIGHT**//
   VOID Turn_Right_Valve_DRIVER(){
      OUTPUT_HIGH(VALVE_DRIVER_EN);
      OUTPUT_LOW(VALVE_DRIVER_IN_1);
      OUTPUT_HIGH(VALVE_DRIVER_IN_2);
   }
//*************************************************************************************************************************************TURN**LEFT**//
   VOID Turn_Left_Valve_DRIVER(){
      OUTPUT_HIGH(VALVE_DRIVER_EN);
      OUTPUT_HIGH(VALVE_DRIVER_IN_1);
      OUTPUT_LOW(VALVE_DRIVER_IN_2);
   }
//*******************************************************************************************************************************************STOP**//
   VOID Stop_Valve_DRIVER(){
      OUTPUT_LOW(VALVE_DRIVER_EN);
      OUTPUT_LOW(VALVE_DRIVER_IN_1);
      OUTPUT_LOW(VALVE_DRIVER_IN_2);
   }
//*************************************************************************************************************************************************//
//*******************************************************************************************************************************PASSENGER**VALVE**//
//*************************************************************************************************************************************************//
//************************************************************************************************************************************TURN**RIGHT**//
   VOID Turn_Right_Valve_Passenger(){
      OUTPUT_HIGH(VALVE_PASSENGER_EN);
      OUTPUT_LOW(VALVE_PASSENGER_IN_1);
      OUTPUT_HIGH(VALVE_PASSENGER_IN_2);
   }
//*************************************************************************************************************************************TURN**LEFT**//
   VOID Turn_Left_Valve_Passenger(){
      OUTPUT_HIGH(VALVE_PASSENGER_EN);
      OUTPUT_HIGH(VALVE_PASSENGER_IN_1);
      OUTPUT_LOW(VALVE_PASSENGER_IN_2);
   }
//*******************************************************************************************************************************************STOP**//
   VOID Stop_Valve_Passenger(){
      OUTPUT_LOW(VALVE_PASSENGER_EN);
      OUTPUT_LOW(VALVE_PASSENGER_IN_1);
      OUTPUT_LOW(VALVE_PASSENGER_IN_2);
   }
//*************************************************************************************************************************************************//
//********************************************************TIME**KLAPE**ONCE**VALVE**DRIVER*********************************************************//
//*************************************************************************************************************************************************//
VOID Time_Klape_Once_Valve_Driver(){
   IF(state_time_klape_once_valve_driver){
      Turn_Right_Valve_Driver();
      DELAY_MS(500);
      counter_button_controller_functions                            = 0;
      state_time_klape_once_turn_complete_valve_driver               = FALSE;
      WHILE(!state_time_klape_once_turn_complete_valve_driver){
         counter_button_controller_functions++;
         IF(counter_button_controller_functions > 10){
            counter_button_controller_functions                      = 0;
            Button_Controller_Functions(); 
            Controller_Led_Functions();
         }
         Turn_Right_Valve_Driver();
         DELAY_MS(30);
         Read_Current_Valve();
         IF(value_current_valve > VALUE_SIDE_CURRENT_VALVE_DRIVER){
            state_error_valve_driver                                 = FALSE;
            state_turn_complete_valve_driver                         = FALSE;
            state_controller_klape_error_valve_driver                = FALSE;
            state_controller_error_in_while_loop_valve_driver        = FALSE;
            state_time_klape_once_valve_driver                       = FALSE;
            state_time_klape_once_turn_complete_valve_driver         = TRUE;
            Stop_Valve_Driver();
            DELAY_MS(100);
         }
      }
      Turn_Left_Valve_Driver();
      DELAY_MS(500);
      time_valve_driver_starting                                     = get_ticks();
      counter_button_controller_functions                            = 0;
      state_time_klape_once_turn_complete_valve_driver               = FALSE;
      WHILE(!state_time_klape_once_turn_complete_valve_driver){
         Turn_Left_Valve_Driver();
         DELAY_MS(1);
         counter_button_controller_functions++;
         IF(counter_button_controller_functions > 25){
            counter_button_controller_functions                      = 0;
            Button_Controller_Functions(); 
            Controller_Led_Functions();
         }
         time_valve_driver_current                                   = get_ticks();
         Read_Current_Valve();
         IF(value_current_valve > VALUE_SIDE_CURRENT_VALVE_DRIVER){
            state_time_klape_once_turn_complete_valve_driver         = TRUE;
            Stop_Valve_Driver();
            DELAY_MS(100);
         }
      }
      IF(!state_error_valve_driver){
         time_valve_driver_difference           = Ticks_Difference(time_valve_driver_starting, time_valve_driver_current);
         time_controller_valve_driver           = (time_valve_driver_difference - 400);
         time_error_valve_driver_difference     = (2 * time_valve_driver_difference);
         time_valve_driver_mid                  = ((time_valve_driver_difference / 2) - 800);
      }
   }
}
//*************************************************************************************************************************************************//
//********************************************************TIME**KLAPE**ONCE**VALVE**PASSENGER******************************************************//
//*************************************************************************************************************************************************//
VOID Time_Klape_Once_Valve_Passenger(){
   IF(state_time_klape_once_valve_passenger){
      Turn_Right_Valve_Passenger();
      DELAY_MS(500);
      counter_button_controller_functions                               = 0;
      state_time_klape_once_turn_complete_valve_passenger               = FALSE;
      WHILE(!state_time_klape_once_turn_complete_valve_passenger){
         counter_button_controller_functions++;
         IF(counter_button_controller_functions > 10){
            counter_button_controller_functions                         = 0;
            Button_Controller_Functions();
            Controller_Led_Functions();
         }
         Turn_Right_Valve_Passenger();
         DELAY_MS(30);
         Read_Current_Valve();
         IF(value_current_valve > VALUE_SIDE_CURRENT_VALVE_PASSENGER){
            state_error_valve_passenger                                 = FALSE;
            state_turn_complete_valve_passenger                         = FALSE;
            state_controller_klape_error_valve_passenger                = FALSE;
            state_controller_error_in_while_loop_valve_passenger        = FALSE;
            state_time_klape_once_valve_passenger                       = FALSE;
            state_time_klape_once_turn_complete_valve_passenger         = TRUE;
            Stop_Valve_Passenger();
            DELAY_MS(100);
         }
      }
      Turn_Left_Valve_Passenger();
      DELAY_MS(500);
      time_valve_passenger_starting                                     = get_ticks();
      counter_button_controller_functions                               = 0;
      state_time_klape_once_turn_complete_valve_passenger               = FALSE;
      WHILE(!state_time_klape_once_turn_complete_valve_passenger){
         Turn_Left_Valve_Passenger();
         DELAY_MS(1);
         counter_button_controller_functions++;
         IF(counter_button_controller_functions > 25){
            counter_button_controller_functions                         = 0;
            Button_Controller_Functions(); 
            Controller_Led_Functions();
         }
         time_valve_passenger_current                                   = get_ticks();
         Read_Current_Valve();
         IF(value_current_valve > VALUE_SIDE_CURRENT_VALVE_PASSENGER){
            state_time_klape_once_turn_complete_valve_passenger         = TRUE;
            Stop_Valve_Passenger();
            DELAY_MS(100);
         }
      }
      IF(!state_error_valve_passenger){
         time_valve_passenger_difference           = Ticks_Difference(time_valve_passenger_starting, time_valve_passenger_current);
         time_controller_valve_passenger           = (time_valve_passenger_difference - 400);
         time_error_valve_passenger_difference     = (2 * time_valve_passenger_difference);
         time_valve_passenger_mid                  = ((time_valve_passenger_difference / 2) - 800);
      }
   }
}
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
//***********************************************************************END***********************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
