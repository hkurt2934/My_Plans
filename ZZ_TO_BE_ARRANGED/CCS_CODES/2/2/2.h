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
#DEFINE PWM_FAN_DRIVER_STEP_1                            550     
#DEFINE PWM_FAN_DRIVER_STEP_2                            680     
#DEFINE PWM_FAN_DRIVER_STEP_3                            1018
#DEFINE PWM_FAN_PASSENGER_STEP_0                         0
#DEFINE PWM_FAN_PASSENGER_STEP_1                         750
#DEFINE PWM_FAN_PASSENGER_STEP_2                         1000              
//*****************************************************************************************************************************TIME**POMP**VALUEs**//
#DEFINE TIME_POMP_ON                                     4000
//******************************************************************************************************************************SET**TRIS**VALUEs**//
#DEFINE VALUE_TRIS_A                                     0x70
#DEFINE VALUE_TRIS_B                                     0x18
#DEFINE VALUE_TRIS_C                                     0x11
#DEFINE VALUE_TRIS_D                                     0x08
#DEFINE VALUE_TRIS_E                                     0x07
//********************************************************************************************************************************ADDRESS**VALUEs**//
#DEFINE VALUE_ADDRESS_WINDOW                             0x01
#DEFINE VALUE_ADDRESS_FRESH_AIR                          0x03
#DEFINE VALUE_ADDRESS_VALVE_DRIVER                       0x04
#DEFINE VALUE_ADDRESS_VALVE_PASSENGER                    0x06
//**************************************************************************************************************************************LED**PINs**//
#DEFINE LED_DATA                                         PIN_D1
#DEFINE LED_SH_CP                                        PIN_C3
#DEFINE LED_ST_CP                                        PIN_D0
//*********************************************************************************************************************************BOARD**LEDLERI**//
#DEFINE LED_MAX_DEFAULT                                  0xFDFF
#DEFINE LED_MAX_ON                                       0x0200
#DEFINE LED_MAX_OFF                                      0xFDFF
#DEFINE LED_FAN_DRIVER_DEFAULT                           0xFF8F
#DEFINE LED_FAN_DRIVER_1_ON                              0x0010
#DEFINE LED_FAN_DRIVER_1_OFF                             0xFFEF
#DEFINE LED_FAN_DRIVER_2_ON                              0x0020
#DEFINE LED_FAN_DRIVER_2_OFF                             0xFFDF
#DEFINE LED_FAN_DRIVER_3_ON                              0x0040
#DEFINE LED_FAN_DRIVER_3_OFF                             0xFFBF
#DEFINE LED_FAN_PASSENGER_DEFAULT                        0xFF7E
#DEFINE LED_FAN_PASSENGER_1_ON                           0x0080
#DEFINE LED_FAN_PASSENGER_1_OFF                          0xFF7F
#DEFINE LED_FAN_PASSENGER_2_ON                           0x0001
#DEFINE LED_FAN_PASSENGER_2_OFF                          0xFFFE
#DEFINE LED_WINDOW_DEFAULT                               0xDFFF
#DEFINE LED_WINDOW_ON                                    0x2000
#DEFINE LED_WINDOW_OFF                                   0xDFFF
#DEFINE LED_FACE_DEFAULT                                 0xF7FF
#DEFINE LED_FACE_ON                                      0x0800
#DEFINE LED_FACE_OFF                                     0xF7FF
#DEFINE LED_TOGETHER_DEFAULT                             0xEFFF
#DEFINE LED_TOGETHER_ON                                  0x1000
#DEFINE LED_TOGETHER_OFF                                 0xEFFF
#DEFINE LED_FRESH_AIR_DEFAULT                            0xFBFF
#DEFINE LED_FRESH_AIR_ON                                 0x0400
#DEFINE LED_FRESH_AIR_OFF                                0xFBFF
#DEFINE LED_VALVE_DRIVER_DEFAULT                         0xFFF1
#DEFINE LED_VALVE_DRIVER_0_ON                            0x0002
#DEFINE LED_VALVE_DRIVER_0_OFF                           0xFFFD
#DEFINE LED_VALVE_DRIVER_1_ON                            0x0004
#DEFINE LED_VALVE_DRIVER_1_OFF                           0xFFFB
#DEFINE LED_VALVE_DRIVER_2_ON                            0x0008
#DEFINE LED_VALVE_DRIVER_2_OFF                           0xFFF7
#DEFINE LED_VALVE_PASSENGER_DEFAULT                      0x3EFF
#DEFINE LED_VALVE_PASSENGER_0_ON                         0x0100
#DEFINE LED_VALVE_PASSENGER_0_OFF                        0xFEFF
#DEFINE LED_VALVE_PASSENGER_1_ON                         0x4000
#DEFINE LED_VALVE_PASSENGER_1_OFF                        0xBFFF
#DEFINE LED_VALVE_PASSENGER_2_ON                         0x8000
#DEFINE LED_VALVE_PASSENGER_2_OFF                        0x7FFF
//****************************************************************************************************************************************BUTTONs**//
#DEFINE BUTTON_MAX                                       PIN_E1
#DEFINE BUTTON_FAN_DRIVER                                PIN_A6
#DEFINE BUTTON_FAN_PASSENGER                             PIN_E2
#DEFINE BUTTON_WINDOW                                    PIN_A4
#DEFINE BUTTON_FACE                                      PIN_A5
#DEFINE BUTTON_TOGETHER                                  PIN_C4
#DEFINE BUTTON_FRESH_AIR                                 PIN_E0
#DEFINE BUTTON_VALVE_DRIVER                              PIN_C0
#DEFINE BUTTON_VALVE_PASSENGER                           PIN_D3
//***********************************************************************************************************************************WINDOW**PINs**//
#DEFINE WINDOW_EN_1                                      PIN_C5
#DEFINE WINDOW_EN_2                                      PIN_B6
#DEFINE WINDOW_IN_1                                      PIN_C7
#DEFINE WINDOW_IN_2                                      PIN_B0
//*******************************************************************************************************************************FRESH**AIR**PINs**//
#DEFINE FRESH_AIR_EN_1                                   PIN_C5
#DEFINE FRESH_AIR_EN_2                                   PIN_B6
#DEFINE FRESH_AIR_IN_1                                   PIN_D7
#DEFINE FRESH_AIR_IN_2                                   PIN_D4
//****************************************************************************************************************************DRIVER**VALVE**PINs**//
#DEFINE VALVE_DRIVER_EN                                  PIN_C6
#DEFINE VALVE_DRIVER_IN_1                                PIN_D6
#DEFINE VALVE_DRIVER_IN_2                                PIN_D5
//*************************************************************************************************************************PASSENGER**VALVE**PINs**//
#DEFINE VALVE_PASSENGER_EN                               PIN_B5
#DEFINE VALVE_PASSENGER_IN_1                             PIN_B1
#DEFINE VALVE_PASSENGER_IN_2                             PIN_B2
//********************************************************************************************************************************************PWM**//
#DEFINE PWM_FAN_DRIVER                                   PIN_C1
#DEFINE PWM_FAN_PASSENGER                                PIN_C2
//*************************************************************************************************************************************PWM**SETUP**//
#DEFINE PWM_SETUP_FAN_DRIVER_ON                          SETUP_CCP2(CCP_PWM);
#DEFINE PWM_SETUP_FAN_DRIVER_OFF                         SETUP_CCP2(CCP_OFF);
#DEFINE PWM_SETUP_FAN_PASSENGER_ON                       SETUP_CCP1(CCP_PWM);
#DEFINE PWM_SETUP_FAN_PASSENGER_OFF                      SETUP_CCP1(CCP_OFF);
//*******************************************************************************************************************************CURRENT**CONTROL**//
#DEFINE CURRENT_PORT_VALVE_DRIVER                        PIN_B4
#DEFINE CURRENT_PORT_VALVE_PASSENGER                     PIN_B3
//**************************************************************************************************************************************ADC**PINs**//
#DEFINE ADC_Current_Valve_Driver                         sAN11
#DEFINE ADC_Current_Valve_Passenger                      sAN9
//***********************************************************************************************************************************ADC**CHANNEL**//
#DEFINE CHANNEL_Current_Valve_Driver                     11
#DEFINE CHANNEL_Current_Valve_Passenger                  9
//********************************************************************************************************************************CURRENT**VALUEs**//
#DEFINE VALUE_SIDE_CURRENT_KORMAS_VALVE                  50
#DEFINE VALUE_SIDE_CURRENT_KLAPE_MOTOR                   50
#DEFINE VALUE_SIDE_CURRENT_TEST                          15
//*********************************************************************************************************************************KLIMA-POMP_OUT**//
#DEFINE AIR_CONDITIONING_OUT                             PIN_D2
#DEFINE POMP_OUT                                         PIN_A7
//*************************************************************************************************************************************************//
//*******************************************************************FUNCTIONs*********************************************************************//
//*************************************************************************************************************************************************//
//********************************************************************************************************************************MAIN**FUNCTIONs**//
VOID Setting();
VOID Controller_Klape();
VOID Scan_Klape_Time();
VOID Time_Klape_Once_Window();
VOID Time_Klape_Once_Fresh_Air();
VOID Time_Klape_Once_Valve_Driver();
VOID Time_Klape_Once_Valve_Passenger();
VOID Controller_Klape_Error();
VOID Make_Default_Value();
VOID Read_Value_From_EEPROM();
VOID Work_According_To_EEPROM_Value();
//******************************************************************************************************************************BUTTON**FUNCTIONs**//
VOID Button_Controller_Fan_Driver();
VOID Button_Controller_Fan_Passenger();
VOID Button_Controller_Window();
VOID Button_Controller_Fresh_Air();
VOID Button_Controller_Valve_Driver();
VOID Button_Controller_Valve_Passenger();
VOID Button_Controller_Max();
VOID Button_Controller_Functions();
//**************************************************************************************************************************CONTROLLER**FUNCTIONs**//
VOID Controller_Klape();
VOID Controller_Klape_Error();
VOID Controller_Scan_Klape_Time();
VOID Controller_Air_Conditioning(); 
VOID Controller_Pomp();
VOID Controller_Fan_Driver();
VOID Controller_Fan_Passenger();
VOID Controller_Window();
VOID Controller_Fresh_Air();
VOID Controller_Valve_Driver();
VOID Controller_Valve_Passenger();
VOID Controller_Functions();
//*********************************************************************************************************************LED**CONTROLLER**FUNCTIONs**//
VOID Controller_Led_Fan_Driver();
VOID Controller_Led_Fan_Passenger();
VOID Controller_Led_Window();
VOID Controller_Led_Fresh_Air();
VOID Controller_Led_Valve_Driver();
VOID Controller_Led_Valve_Passenger();
VOID Controller_Led_Functions();
VOID Special_Function_For_Fan_Driver_On_Max_In_While();
//***************************************************************************************************************************READ**ADC**FUNCTIONs**//
VOID Read_Current_Valve_Driver();
VOID Read_Current_Valve_Passenger();
//*********************************************************************************************************************MOTOR**MOVEMENT**FUNCTIONs**//
VOID Turn_Right_Window();
VOID Turn_Left_Window();
VOID Stop_Window();
VOID Turn_Right_Fresh_Air();
VOID Turn_Left_Fresh_Air();
VOID Stop_Fresh_Air();
VOID Turn_Right_Valve_Driver();
VOID Turn_Left_Valve_Driver();
VOID Stop_Valve_Driver();
VOID Turn_Right_Valve_Passenger();
VOID Turn_Left_Valve_Passenger();
VOID Stop_Valve_Passenger();
//*************************************************************************************************************************DISPLAY-LED**FUNCTIONs**//
VOID ONer(INT16);
VOID OFFer(INT16);
VOID Write_Led(INT16);
//********************************************************************************************************************************TIME**FUNCTIONs**//
INT32 Ticks_Difference(INT32,INT32);
VOID Controller_Time_Pomp();
VOID Controller_Time_In_While_Window();
VOID Controller_Time_In_While_Fresh_Air();
VOID Controller_Time_In_While_Valve_Driver();
VOID Controller_Time_In_While_Valve_Passenger();
VOID Controller_Error_In_Button();
VOID Controller_Error_In_While_Loop();
VOID Button_Controller_Functions_For_Fan();
//*************************************************************************************************************************************************//
//**************************************************************INTEGER**VARIABLEs*****************************************************************//
//*************************************************************************************************************************************************//
//************************************************************************************************************************************LED**VALUEs**//
INT8 counter_write_led                                         = ALL_ZERO_8_BIT;
INT16 leds_register                                            = ALL_ZERO_16_BIT;
//***************************************************************************************************************************************COUNTERs**//
SIGNED INT8 counter_max                                        = MINUS_ONE;
SIGNED INT8 counter_fan_driver                                 = MINUS_ONE;
SIGNED INT8 counter_fan_driver_old                             = MINUS_ONE;
SIGNED INT8 counter_fan_driver_before                          = MINUS_ONE;
SIGNED INT8 counter_fan_passenger                              = MINUS_ONE;
SIGNED INT8 counter_fan_passenger_old                          = MINUS_ONE;
SIGNED INT8 counter_window                                     = MINUS_ONE; 
SIGNED INT8 counter_window_status                              = MINUS_ONE;
SIGNED INT8 counter_window_old                                 = MINUS_ONE;
SIGNED INT8 counter_window_before                              = MINUS_ONE;
SIGNED INT8 counter_fresh_air                                  = MINUS_ONE;
SIGNED INT8 counter_fresh_air_old                              = MINUS_ONE;
SIGNED INT8 counter_fresh_air_before                           = MINUS_ONE;
SIGNED INT8 counter_valve_driver                               = MINUS_ONE;
SIGNED INT8 counter_valve_driver_status                        = MINUS_ONE;
SIGNED INT8 counter_valve_driver_old                           = MINUS_ONE;
SIGNED INT8 counter_valve_driver_before                        = MINUS_ONE;
SIGNED INT8 counter_valve_passenger                            = MINUS_ONE;
SIGNED INT8 counter_valve_passenger_status                     = MINUS_ONE;
SIGNED INT8 counter_valve_passenger_old                        = MINUS_ONE;
//*************************************************************************************************************************EEPROM**ADDRESS**DATAs**//
INT8 address_window                                            = VALUE_ADDRESS_WINDOW;
INT8 address_fresh_air                                         = VALUE_ADDRESS_FRESH_AIR;
INT8 address_valve_driver                                      = VALUE_ADDRESS_VALVE_DRIVER;
INT8 address_valve_passenger                                   = VALUE_ADDRESS_VALVE_PASSENGER;
//*********************************************************************************************************************************ADC**VARIABLEs**//
INT16 value_current_valve_driver                               = ALL_ZERO_16_BIT;
INT16 value_current_valve_passenger                            = ALL_ZERO_16_BIT;
INT16 value_current_temporary                                  = ALL_ZERO_16_BIT;
INT32 register_adc                                             = ALL_ZERO_32_BIT;
//********************************************************************************************************************************TIME**VARIABLEs**//
UNSIGNED INT32 time_difference                                 = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_window_starting                            = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_window_current                             = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_window_difference                          = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_window_mid                                 = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_fresh_air_starting                         = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_fresh_air_current                          = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_fresh_air_difference                       = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_driver_starting                      = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_driver_current                       = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_driver_difference                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_driver_mid                           = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_passenger_starting                   = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_passenger_current                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_passenger_difference                 = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_valve_passenger_mid                        = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_error_window_difference                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_error_fresh_air_difference                 = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_error_valve_driver_difference              = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_error_valve_passenger_difference           = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_controller_pomp_starting                   = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_controller_pomp_current                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_controller_pomp_difference                 = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_window_starting                   = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_window_current                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_window_difference                 = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_fresh_air_starting                = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_fresh_air_current                 = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_fresh_air_difference              = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_valve_driver_starting             = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_valve_driver_current              = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_valve_driver_difference           = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_valve_passenger_starting          = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_valve_passenger_current           = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_in_while_valve_passenger_difference        = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_controller_window                          = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_controller_fresh_air                       = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_controller_valve_driver                    = ALL_ZERO_32_BIT;
UNSIGNED INT32 time_controller_valve_passenger                 = ALL_ZERO_32_BIT;
//*********************************************************************************************************************************PWM**VARIABLEs**//
INT16 value_pwm_fan_driver                                     = ALL_ZERO_16_BIT;
INT16 value_pwm_fan_passenger                                  = ALL_ZERO_16_BIT;
//************************************************************************************************************KLAPE**CONTROL**FUNCTION**VARIABLEs**//
INT16 counter_klape_window                                     = ALL_ZERO_16_BIT;
INT16 counter_klape_fresh_air                                  = ALL_ZERO_16_BIT;
INT16 counter_klape_valve_driver                               = ALL_ZERO_16_BIT;
INT16 counter_klape_valve_passenger                            = ALL_ZERO_16_BIT;
INT16 counter_controller_fan_in_while                          = ALL_ZERO_16_BIT;
//***************************************************************************************************************KLAPE**CONTROL**ERROR**VARIABLEs**//
INT32 counter_controller_klape_error_window                    = ALL_ZERO_32_BIT;
INT32 counter_controller_klape_error_fresh_air                 = ALL_ZERO_32_BIT;
INT32 counter_controller_klape_error_valve_driver              = ALL_ZERO_32_BIT;
INT32 counter_controller_klape_error_valve_passenger           = ALL_ZERO_32_BIT;
INT32 counter_controller_klape_error_inner_window              = ALL_ZERO_32_BIT;
INT32 counter_controller_klape_error_inner_fresh_air           = ALL_ZERO_32_BIT;
INT32 counter_controller_klape_error_inner_valve_driver        = ALL_ZERO_32_BIT;
INT32 counter_controller_klape_error_inner_valve_passenger     = ALL_ZERO_32_BIT;
//*************************************************************************************************************************************************//
INT16 counter_button_controller_functions                      = ALL_ZERO_16_BIT;
//*************************************************************************************************************************************************//
//*************************************************************BOOLEAN**VARIABLEs******************************************************************//
//*************************************************************************************************************************************************//
//*******************************************************************************************************************CONTROLLER**KLAPE**VARIABLEs**//
BOOLEAN state_error_window                                     = FALSE;
BOOLEAN state_error_fresh_air                                  = FALSE;
BOOLEAN state_error_valve_driver                               = FALSE;
BOOLEAN state_controller_fan_driver_for_max                    = FALSE;
BOOLEAN state_error_valve_passenger                            = FALSE;
BOOLEAN state_controller_klape_error_window                    = FALSE;
BOOLEAN state_controller_klape_error_fresh_air                 = FALSE;
BOOLEAN state_controller_klape_error_valve_driver              = FALSE;
BOOLEAN state_controller_klape_error_valve_passenger           = FALSE;
//*******************************************************************************************************************BUTON**CONTROLLER**VARIABLEs**//
BOOLEAN state_button_max                                       = FALSE;
BOOLEAN state_button_max_counter_before                        = FALSE;
BOOLEAN state_button_fan_driver                                = FALSE;
BOOLEAN state_button_fan_passenger                             = FALSE;
BOOLEAN state_button_window                                    = FALSE;
BOOLEAN state_button_face                                      = FALSE;
BOOLEAN state_button_together                                  = FALSE;
BOOLEAN state_button_fresh_air                                 = FALSE;
BOOLEAN state_button_valve_driver                              = FALSE;
BOOLEAN state_button_valve_passenger                           = FALSE;
//***************************************************************************************************************CONTROLLER**FUNCTIONS**VARIABLEs**//
BOOLEAN state_turn_complete_window                             = FALSE;
BOOLEAN state_turn_complete_fresh_air                          = FALSE;
BOOLEAN state_turn_complete_valve_driver                       = FALSE;
BOOLEAN state_turn_complete_valve_passenger                    = FALSE;
//*******************************************************************************************************************SCAN**KLAPE**TIME**VARIABLEs**//
BOOLEAN state_scan_klape_time                                  = TRUE;
//*************************************************************************************************************************************************//
BOOLEAN state_controller_error_in_button_window                = FALSE;
BOOLEAN state_controller_error_in_button_fresh_air             = FALSE;
BOOLEAN state_controller_error_in_button_valve_driver          = FALSE;
BOOLEAN state_controller_error_in_button_valve_passenger       = FALSE;
//*******************************************************************************************************************CONTROLLER**ERROR**VARIABLEs**//
BOOLEAN state_controller_error_in_while_loop_window            = FALSE;
BOOLEAN state_controller_error_in_while_loop_fresh_air         = FALSE;
BOOLEAN state_controller_error_in_while_loop_valve_driver      = FALSE;
BOOLEAN state_controller_error_in_while_loop_valve_passenger   = FALSE;
//********************************************************************************************************************************TIME**VARIABLEs**//
BOOLEAN state_time_in_while_window                             = FALSE;
BOOLEAN state_time_in_while_start_window                       = FALSE;
BOOLEAN state_time_in_while_fresh_air                          = FALSE;
BOOLEAN state_time_in_while_start_fresh_air                    = FALSE;
BOOLEAN state_time_in_while_valve_driver                       = FALSE;
BOOLEAN state_time_in_while_start_valve_driver                 = FALSE;
BOOLEAN state_time_in_while_valve_passenger                    = FALSE;
BOOLEAN state_time_in_while_start_valve_passenger              = FALSE;
//********************************************************************************************************************************POMP**VARIABLEs**//
BOOLEAN state_process_complete_pomp                            = FALSE;
BOOLEAN state_controller_pomp_on                               = FALSE;
//*************************************************************************************************************************************************//
BOOLEAN state_time_klape_once_window                           = FALSE;
BOOLEAN state_time_klape_once_fresh_air                        = FALSE;
BOOLEAN state_time_klape_once_valve_driver                     = FALSE;
BOOLEAN state_time_klape_once_valve_passenger                  = FALSE;
BOOLEAN state_time_klape_once_turn_complete_window             = FALSE;
BOOLEAN state_time_klape_once_turn_complete_fresh_air          = FALSE;
BOOLEAN state_time_klape_once_turn_complete_valve_driver       = FALSE;
BOOLEAN state_time_klape_once_turn_complete_valve_passenger    = FALSE;
//*************************************************************************************************************************************************//
BOOLEAN state_special_function_for_fan_driver_on_max_in_while  = FALSE;
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
      DELAY_US(50);
//***************************************************************************************************************************SETTING**ALL**OUTPUT**//
      SET_TRIS_A(VALUE_TRIS_A);
      SET_TRIS_B(VALUE_TRIS_B);
      SET_TRIS_C(VALUE_TRIS_C);
      SET_TRIS_D(VALUE_TRIS_D);
      SET_TRIS_E(VALUE_TRIS_E);
      OFFer(ALL_ZERO_16_BIT);
//********************************************************************************************************************************SETUP**TIMER**2**//
      SETUP_TIMER_2(T2_DIV_BY_1, 255, 1);
//******************************************************************************************************************************SETUP**OSCILLATOR**//
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
      register_adc                  = register_adc | ADC_Current_Valve_Driver;
      register_adc                  = register_adc | ADC_Current_Valve_Passenger;
      register_adc                  = register_adc | VSS_VDD;
      SETUP_ADC_PORTS(register_adc);
      SETUP_ADC(RTCC_INTERNAL|ADC_CLOCK_DIV_8);
      DELAY_US(50);
//**************************************************************************************************************************OPENNING**ALL**OUTPUT**//
      DELAY_MS(4000);
//*********************************************************************************************************************************TICKs**DEFAULT**//
      set_ticks(ALL_ZERO_32_BIT);
   }
//*************************************************************************************************************************************************//
//******************************************************************KLAPE**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Klape(){
//**********************************************************************************************************************************MAKE**DEFAULT**//
      state_error_window                                       = TRUE;
      state_error_fresh_air                                    = TRUE;
      state_error_valve_driver                                 = TRUE;
      state_error_valve_passenger                              = TRUE;
      state_time_klape_once_window                             = TRUE;
      state_time_klape_once_fresh_air                          = TRUE;
      state_time_klape_once_valve_driver                       = TRUE;
      state_time_klape_once_valve_passenger                    = TRUE;
      state_controller_klape_error_window                      = TRUE;
      state_controller_klape_error_fresh_air                   = TRUE;
      state_controller_klape_error_valve_driver                = TRUE;
      state_controller_klape_error_valve_passenger             = TRUE;
      state_controller_error_in_while_loop_window              = TRUE;
      state_controller_error_in_while_loop_fresh_air           = TRUE;
      state_controller_error_in_while_loop_valve_driver        = TRUE;
      state_controller_error_in_while_loop_valve_passenger     = TRUE;
//*****************************************************************************************************************************************WINDOW**//
      Turn_Right_Window();
      DELAY_MS(500);
      FOR(counter_klape_window = 0; counter_klape_window < 300; counter_klape_window++){
         Turn_Right_Window();
         DELAY_MS(30);
         Read_Current_Valve_Passenger();
         IF(value_current_valve_passenger > VALUE_SIDE_CURRENT_KLAPE_MOTOR){
            Stop_Window();
            state_error_window                                 = FALSE;
            state_time_klape_once_window                       = FALSE;
            state_controller_klape_error_window                = FALSE;
            state_controller_error_in_while_loop_window        = FALSE;
            counter_klape_window                               = 300;
         }
      }
      Stop_Window();
      DELAY_MS(100);
//*************************************************************************************************************************************FRESH**AIR**//
     Turn_Right_Fresh_Air();
     DELAY_MS(500);
     FOR(counter_klape_fresh_air = 0; counter_klape_fresh_air < 300; counter_klape_fresh_air++){
         Turn_Right_Fresh_Air();
         DELAY_MS(30);
         Read_Current_Valve_Driver();
         IF(value_current_valve_driver > VALUE_SIDE_CURRENT_KLAPE_MOTOR){
            Stop_Fresh_Air();
            state_error_fresh_air                              = FALSE;
            state_time_klape_once_fresh_air                    = FALSE;
            state_controller_klape_error_fresh_air             = FALSE;
            state_controller_error_in_while_loop_fresh_air     = FALSE;  
            counter_klape_fresh_air                            = 300;
         }
     }
     Stop_Fresh_Air();
     DELAY_MS(100);
//**********************************************************************************************************************************DRIVER**VALVE**//
      Turn_Right_Valve_Driver();
      DELAY_MS(500);
      FOR(counter_klape_valve_driver = 0; counter_klape_valve_driver < 300; counter_klape_valve_driver++){
         Turn_Right_Valve_Driver();
         DELAY_MS(30);
         Read_Current_Valve_Driver();
         IF(value_current_valve_driver > VALUE_SIDE_CURRENT_KORMAS_VALVE){
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
      FOR(counter_klape_valve_passenger = 0; counter_klape_valve_passenger < 300; counter_klape_valve_passenger++){
         Turn_Right_Valve_Passenger();
         DELAY_MS(30);
         Read_Current_Valve_Passenger();
         IF(value_current_valve_passenger > VALUE_SIDE_CURRENT_KORMAS_VALVE){
            Stop_Valve_Passenger();
            state_error_valve_passenger                           = FALSE;
            state_time_klape_once_valve_passenger                 = FALSE;
            state_controller_klape_error_valve_passenger          = FALSE;
            state_controller_error_in_while_loop_valve_passenger  = FALSE;
            counter_klape_valve_passenger                         = 300;
         }
      }
      Stop_Valve_Passenger();
      DELAY_MS(100);
   }
//*************************************************************************************************************************************************//
//********************************************************************SCANNING*********************************************************************//
//*************************************************************************************************************************************************//
   VOID Scan_Klape_Time(){
//*****************************************************************************************************************************************WINDOW**//
      IF(!state_error_window){
         Turn_Left_Window();
         DELAY_MS(500);
         time_window_starting                      = get_ticks();
         state_scan_klape_time                     = TRUE;
         WHILE(state_scan_klape_time){
            time_window_current                    = get_ticks();
            Turn_Left_Window();
            Read_Current_Valve_Driver();
            IF(value_current_valve_driver > VALUE_SIDE_CURRENT_KLAPE_MOTOR){
               state_scan_klape_time               = FALSE;
               Stop_Window();
            }
         }
      }
      Stop_Window();
      DELAY_MS(100);
//*****************************************************************************************************************************************WINDOW**//
      IF(!state_error_fresh_air){
         Turn_Left_Fresh_Air();
         DELAY_MS(500);
         time_fresh_air_starting                   = get_ticks();
         state_scan_klape_time                     = TRUE;
         WHILE(state_scan_klape_time){
            time_fresh_air_current                 = get_ticks();
            Turn_Left_Fresh_Air();
            Read_Current_Valve_Passenger();
            IF(value_current_valve_passenger > VALUE_SIDE_CURRENT_KLAPE_MOTOR){
               state_scan_klape_time               = FALSE;
               Stop_Fresh_Air();
            }
         }
      }
      Stop_Fresh_Air();
      DELAY_MS(100);
//**********************************************************************************************************************************DRIVER**VALVE**//
      IF(!state_error_valve_driver){
         Turn_Left_Valve_Driver();
         DELAY_MS(500);
         time_valve_driver_starting                = get_ticks();
         state_scan_klape_time                     = TRUE;
         WHILE(state_scan_klape_time){
            time_valve_driver_current              = get_ticks();
            Turn_Left_Valve_Driver();
            Read_Current_Valve_Driver();
            IF(value_current_valve_driver > VALUE_SIDE_CURRENT_KORMAS_VALVE){
               state_scan_klape_time               = FALSE;
               Stop_Valve_Driver();
            }
         }
      }
      Stop_Valve_Driver();
      DELAY_MS(100);
//*******************************************************************************************************************************PASSENGER**VALVE**//
      IF(!state_error_valve_passenger){
         Turn_Left_Valve_Passenger();
         DELAY_MS(500);
         time_valve_passenger_starting             = get_ticks();
         state_scan_klape_time                     = TRUE;
         WHILE(state_scan_klape_time){
            time_valve_passenger_current           = get_ticks();
            Turn_Left_Valve_Passenger();
            Read_Current_Valve_Passenger();
            IF(value_current_valve_passenger > VALUE_SIDE_CURRENT_KORMAS_VALVE){
               state_scan_klape_time               = FALSE;
               Stop_Valve_Passenger();
            }
         }
      }
      Stop_Valve_Passenger();
      DELAY_MS(100);
//*****************************************************************************************************************************CREATE**MID**VALUE**//
      IF(!state_error_window){
         time_window_difference = Ticks_Difference(time_window_starting, time_window_current);
         time_controller_window = (time_window_difference - 400);
         time_error_window_difference = (2 * time_window_difference);
         time_window_mid = ((time_window_difference / 2) - 800);
      }
      IF(!state_error_fresh_air){
         time_fresh_air_difference = Ticks_Difference(time_fresh_air_starting, time_fresh_air_current);
         time_controller_fresh_air = (time_fresh_air_difference - 400);
         time_error_fresh_air_difference = (2 * time_fresh_air_difference);
      }
      IF(!state_error_valve_driver){
         time_valve_driver_difference = Ticks_Difference(time_valve_driver_starting, time_valve_driver_current);
         time_controller_valve_driver = (time_valve_driver_difference - 400);
         time_error_valve_driver_difference = (2 * time_valve_driver_difference);
         time_valve_driver_mid = ((time_valve_driver_difference / 2) - 800);
      }
      IF(!state_error_valve_passenger){
         time_valve_passenger_difference = Ticks_Difference(time_valve_passenger_starting, time_valve_passenger_current);
         time_controller_valve_passenger = (time_valve_passenger_difference - 400);
         time_error_valve_passenger_difference = (2 * time_valve_passenger_difference);
         time_valve_passenger_mid = ((time_valve_passenger_difference / 2) - 800);
      }
   }
//*************************************************************************************************************************************************//
//*********************************************************CONTROL**KLAPE**MOTOR**ERROR************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Klape_Error(){
//*****************************************************************************************************************************************WINDOW**//
      WHILE(state_controller_klape_error_window){
         counter_controller_klape_error_window++;
         IF(counter_controller_klape_error_window == 10000){
            ONer(LED_WINDOW_ON);   
            OFFer(LED_FACE_OFF);
            OFFer(LED_TOGETHER_OFF);
         }
         IF(counter_controller_klape_error_window == 20000){
            counter_controller_klape_error_window = 0;
            OFFer(LED_WINDOW_OFF);
            OFFer(LED_FACE_OFF);
            OFFer(LED_TOGETHER_OFF);
         }
         counter_controller_klape_error_inner_window = 0;
         WHILE(!INPUT(BUTTON_WINDOW)){
            counter_controller_klape_error_inner_window++;
            IF(counter_controller_klape_error_inner_window == 200000){
               state_controller_klape_error_window = FALSE;
               OFFer(LED_WINDOW_OFF);
               OFFer(LED_FACE_OFF);
               OFFer(LED_TOGETHER_OFF);
            }
         }
      }
//*************************************************************************************************************************************FRESH**AIR**//
      WHILE(state_controller_klape_error_fresh_air){
         counter_controller_klape_error_fresh_air++;
         IF(counter_controller_klape_error_fresh_air == 10000){
            ONer(LED_FRESH_AIR_ON);
         }
         IF(counter_controller_klape_error_fresh_air == 20000){
            OFFer(LED_FRESH_AIR_OFF);
            counter_controller_klape_error_fresh_air = 0;
         }
         counter_controller_klape_error_inner_fresh_air = 0;
         WHILE(!INPUT(BUTTON_FRESH_AIR)){
            counter_controller_klape_error_inner_fresh_air++;
            IF(counter_controller_klape_error_inner_fresh_air == 200000){
               state_controller_klape_error_fresh_air = FALSE;
               OFFer(LED_FRESH_AIR_OFF);
            }
         }
      }
//**********************************************************************************************************************************VALVE**DRIVER**//
      WHILE(state_controller_klape_error_valve_driver){
         counter_controller_klape_error_valve_driver ++;
         IF(counter_controller_klape_error_valve_driver == 10000){
            ONer(LED_VALVE_DRIVER_0_ON);
            ONer(LED_VALVE_DRIVER_1_ON);
            ONer(LED_VALVE_DRIVER_2_ON);
         }
         IF(counter_controller_klape_error_valve_driver == 20000){
            counter_controller_klape_error_valve_driver = 0;
            OFFer(LED_VALVE_DRIVER_0_OFF);
            OFFer(LED_VALVE_DRIVER_1_OFF);
            OFFer(LED_VALVE_DRIVER_2_OFF);
         }
         counter_controller_klape_error_inner_valve_driver = 0;
         WHILE(!INPUT(BUTTON_VALVE_DRIVER)){
            counter_controller_klape_error_inner_valve_driver++;
            IF(counter_controller_klape_error_inner_valve_driver == 200000){
               state_controller_klape_error_valve_driver = FALSE;
               OFFer(LED_VALVE_DRIVER_0_OFF);
               OFFer(LED_VALVE_DRIVER_1_OFF);
               OFFer(LED_VALVE_DRIVER_2_OFF);
            }
         }
      }
//*******************************************************************************************************************************VALVE**PASSENGER**//
      WHILE(state_controller_klape_error_valve_passenger){
         counter_controller_klape_error_valve_passenger++;
         IF(counter_controller_klape_error_valve_passenger== 10000){
            ONer(LED_VALVE_PASSENGER_0_ON);
            ONer(LED_VALVE_PASSENGER_1_ON);
            ONer(LED_VALVE_PASSENGER_2_ON);
         }
         IF(counter_controller_klape_error_valve_passenger == 20000){
            counter_controller_klape_error_valve_passenger = 0;
            OFFer(LED_VALVE_PASSENGER_0_OFF);
            OFFer(LED_VALVE_PASSENGER_1_OFF);
            OFFer(LED_VALVE_PASSENGER_2_OFF);
         }
         counter_controller_klape_error_inner_valve_passenger = 0;
         WHILE(!INPUT(BUTTON_VALVE_PASSENGER)){
            counter_controller_klape_error_inner_valve_passenger++;
            IF(counter_controller_klape_error_inner_valve_passenger == 200000){
               state_controller_klape_error_valve_passenger = FALSE;
               OFFer(LED_VALVE_PASSENGER_0_OFF);
               OFFer(LED_VALVE_PASSENGER_1_OFF);
               OFFer(LED_VALVE_PASSENGER_2_OFF);
            }
         }
      }
   }
//*************************************************************************************************************************************************//
//*****************************************************MAKE**DEFAULT**VALUE**WHEN**STARTING********************************************************//
//*************************************************************************************************************************************************//
   VOID Make_Default_Value(){
      SETUP_CCP1(CCP_OFF);
      SETUP_CCP2(CCP_OFF);
      OFFer(ALL_ZERO_16_BIT);
      Stop_Window();
      Stop_Fresh_Air();
      Stop_Valve_Driver();
      Stop_Valve_Passenger();
      OUTPUT_LOW(AIR_CONDITIONING_OUT);
      OUTPUT_LOW(POMP_OUT);
      counter_max                                  = ALL_ZERO_8_BIT;
      counter_fan_driver                           = ALL_ZERO_8_BIT;
      counter_fan_driver_old                       = MINUS_ONE;
      counter_fan_passenger                        = ALL_ZERO_8_BIT;
      counter_fan_passenger_old                    = MINUS_ONE;
      counter_window_old                           = MINUS_ONE;
      counter_window_status                        = ALL_ZERO_8_BIT;
      counter_valve_driver_old                     = MINUS_ONE;
      counter_valve_driver_status                  = ALL_ZERO_8_BIT;
      counter_valve_passenger_old                  = MINUS_ONE;
      counter_valve_passenger_status               = ALL_ZERO_8_BIT;
      value_pwm_fan_driver                         = ALL_ZERO_16_BIT;
      value_pwm_fan_passenger                      = ALL_ZERO_16_BIT;
      state_turn_complete_window                   = FALSE;
      state_turn_complete_fresh_air                = FALSE;
      state_turn_complete_valve_driver             = FALSE;
      state_turn_complete_valve_passenger          = FALSE;
   }
//*************************************************************************************************************************************************//
//*************************************************READ**VALUE**WHEN**BEFORE**SHUTDOWN**FROM**EEPROM***********************************************//
//*************************************************************************************************************************************************//
   VOID Read_Value_From_EEPROM(){
      IF(!state_error_window){
         counter_window                            = READ_EEPROM(address_window);
         counter_window_status                     = 0;
      }
      ELSE{
         counter_window                            = 0;
         counter_window_status                     = 0;
      }
      IF(!state_error_fresh_air){
         counter_fresh_air                         = READ_EEPROM(address_fresh_air);
      }
      ELSE{
         counter_fresh_air                         = 0;
      }
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
      Controller_Window();
      Controller_Fresh_Air();
      Controller_Valve_Driver();
      Controller_Valve_Passenger();
      Controller_Fan_Driver();
      Controller_Fan_Passenger();
      Controller_Led_Fan_Driver();
      Controller_Led_Fan_Passenger();
      Controller_Led_Window();
      Controller_Led_Fresh_Air();
      Controller_Led_Valve_Driver();
      Controller_Led_Valve_Passenger();
      Controller_Pomp();
      Controller_Time_Pomp();
      Controller_Air_Conditioning();
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
      Controller_Air_Conditioning();
//*************************************************************************************************************************************************//
      IF(!(counter_fan_driver == counter_fan_driver_old)){
         state_controller_fan_driver_for_max             = FALSE;
         Controller_Fan_Driver();
      }
//*************************************************************************************************************************************************//
      IF(!(counter_fan_passenger == counter_fan_passenger_old)){
         Controller_Fan_Passenger();
      }
//*************************************************************************************************************************************************//
      IF(!state_error_window){
         IF(!(counter_window == counter_window_old)){
            Controller_Window();
         }
      }
//*************************************************************************************************************************************************//
      IF(!state_error_fresh_air){
         IF(!(counter_fresh_air == counter_fresh_air_old)){
            Controller_Fresh_Air();
         }
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
//***************************************************SPECIAL**FUNCTION**FOR**FAN**DRIVER**ON**MAX**IN**WHILE***************************************//
//*************************************************************************************************************************************************//
   VOID Special_Function_For_Fan_Driver_On_Max_In_While(){
      IF((state_special_function_for_fan_driver_on_max_in_while) && ((counter_max % 2) == 0)){
         state_special_function_for_fan_driver_on_max_in_while = FALSE;
         Controller_Fan_Driver();
      }
   }
//*************************************************************************************************************************************************//
//*****************************************************CONTROLLER**FUNCTIONS**IN**CONTROLLER**WHILE************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Led_Functions(){
      Controller_Error_In_Button();
//*************************************************************************************************************************************************//
      Controller_Led_Fan_Driver();
//*************************************************************************************************************************************************//
      Controller_Led_Fan_Passenger();
//*************************************************************************************************************************************************//
      IF(!state_error_window){
         Controller_Led_Window();
      }
//*************************************************************************************************************************************************//
      IF(!state_error_fresh_air){
         Controller_Led_Fresh_Air();
      }
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
//*******************************************************************************************************************WHEN**PUSH**THE**MAX**BUTTON**//
      Button_Controller_Max();
//***********************************************************************************************************WHEN**PUSH**THE**DRIVER**FAN**BUTTON**//
      Button_Controller_Fan_Driver();
//********************************************************************************************************WHEN**PUSH**THE**PASSENGER**FAN**BUTTON**//
      Button_Controller_Fan_Passenger();
//****************************************************************************************************************WHEN**PUSH**THE**WINDOW**BUTTON**//
      Button_Controller_Window();
//************************************************************************************************************WHEN**PUSH**THE**FRESH**AIR**BUTTON**//
      Button_Controller_Fresh_Air();
//*********************************************************************************************************WHEN**PUSH**THE**DRIVER**VALVE**BUTTON**//
      Button_Controller_Valve_Driver();
//******************************************************************************************************WHEN**PUSH**THE**PASSENGER**VALVE**BUTTON**//
      Button_Controller_Valve_Passenger();
   }         
//*************************************************************************************************************************************************//
//***********************************************************BUTTON**CONTROLLER**FUNCTIONs*********************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Functions_For_Fan(){
//***********************************************************************************************************WHEN**PUSH**THE**DRIVER**FAN**BUTTON**//
         Button_Controller_Fan_Driver();
//********************************************************************************************************WHEN**PUSH**THE**PASSENGER**FAN**BUTTON**//
         Button_Controller_Fan_Passenger();
//****************************************************************************************************************WHEN**PUSH**THE**WINDOW**BUTTON**//
         Button_Controller_Window();
//************************************************************************************************************WHEN**PUSH**THE**FRESH**AIR**BUTTON**//
         Button_Controller_Fresh_Air();
//*********************************************************************************************************WHEN**PUSH**THE**DRIVER**VALVE**BUTTON**//
         Button_Controller_Valve_Driver();
//******************************************************************************************************WHEN**PUSH**THE**PASSENGER**VALVE**BUTTON**//
         Button_Controller_Valve_Passenger();
//*************************************************************************************************************************************************//
         IF((counter_max % 2) == 1){
//*************************************************************************************************************************************************//
            IF((!INPUT(BUTTON_MAX)) && (state_button_max)){
               DELAY_MS(250);
               state_button_max                       = FALSE;
               counter_max++;
//********************************************************************************************************************************COUNTER**MAX**0**//
               IF((counter_max % 2) == 0){
                  OFFer(LED_MAX_DEFAULT);
                  counter_max                         = 0;
                  counter_fan_driver                  = counter_fan_driver_before;
                  counter_window                      = counter_window_before;
                  counter_fresh_air                   = counter_fresh_air_before;
                  counter_valve_driver                = counter_valve_driver_before;
                  state_button_max_counter_before     = TRUE;
                  value_pwm_fan_driver                = PWM_FAN_DRIVER_STEP_0;
                  state_controller_fan_driver_for_max = TRUE;
                  counter_fan_driver_old              = MINUS_ONE;
                  set_pwm2_duty(PWM_FAN_DRIVER_STEP_0);
                  Controller_Air_Conditioning();
               }
            }
//*************************************************************************************************************************************************//
            IF(INPUT(BUTTON_MAX)){
               state_button_max                       = TRUE;
            }
         }
         ELSE IF((counter_max % 2) == 0){
            Button_Controller_Max();
         }
   }    
//*************************************************************************************************************************************************//
//***************************************************************CONTROL**BUTTON**MAX**************************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Max(){
//*************************************************************************************************************************************************//
         IF((!INPUT(BUTTON_MAX)) && (state_button_max)){
            DELAY_MS(250);
            state_button_max                       = FALSE;
            counter_max++;
//********************************************************************************************************************************COUNTER**MAX**0**//
            IF((counter_max % 2) == 0){
               OFFer(LED_MAX_DEFAULT);
               counter_max                                           = 0;
               counter_fan_driver                                    = counter_fan_driver_before;
               counter_window                                        = counter_window_before;
               counter_fresh_air                                     = counter_fresh_air_before;
               counter_valve_driver                                  = counter_valve_driver_before;
               Controller_Air_Conditioning();
            }
//********************************************************************************************************************************COUNTER**MAX**1**//
            IF((counter_max % 2) == 1){
               ONer(LED_MAX_ON);
               state_special_function_for_fan_driver_on_max_in_while = TRUE;
               counter_fan_driver_before                             = counter_fan_driver;
               counter_window_before                                 = counter_window;
               counter_fresh_air_before                              = counter_fresh_air;
               counter_valve_driver_before                           = counter_valve_driver;
               counter_fan_driver                                    = 3;
               counter_window                                        = 0;
               counter_fresh_air                                     = 0;
               counter_valve_driver                                  = 2;
               Controller_Air_Conditioning();
            }
         }
//*************************************************************************************************************************************************//
         IF(INPUT(BUTTON_MAX)){
            state_button_max                       = TRUE;
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
//********************************************************************************************************************************COUNTER**MAX**1**//
         IF((counter_max % 2) == 1){
            OFFer(LED_MAX_DEFAULT);
            counter_max                         = 0;
            counter_fan_driver                  = counter_fan_driver_before;
            counter_window                      = counter_window_before;
            counter_fresh_air                   = counter_fresh_air_before;
            counter_valve_driver                = counter_valve_driver_before;
         }
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
//*******************************************************CONTROL**BUTTON**WINDOW**FACE**TOGETHER***************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Window(){
//*********************************************************************************************************************************BUTTON**WINDOW**//
         IF(!INPUT(BUTTON_WINDOW) && (state_button_window)){
            DELAY_MS(250);
            state_button_window                    = FALSE;
            IF(!state_error_window){
//********************************************************************************************************************************COUNTER**MAX**1**//
               IF((counter_max % 2) == 1){
                  OFFer(LED_MAX_DEFAULT);
                  counter_max                         = 0;
                  counter_fan_driver                  = counter_fan_driver_before;
                  counter_window                      = counter_window_before;
                  counter_fresh_air                   = counter_fresh_air_before;
                  counter_valve_driver                = counter_valve_driver_before;
               }
               counter_window                         = 0;
               write_eeprom(address_window , counter_window);
            }
            ELSE{
               state_controller_error_in_button_window = TRUE;
            }
         }
//*************************************************************************************************************************************************//
         IF(INPUT(BUTTON_WINDOW)){
            state_button_window                    = TRUE;
         }
//***********************************************************************************************************************************BUTTON**FACE**//
         IF(!INPUT(BUTTON_FACE) && (state_button_face)){
            DELAY_MS(250);
//*************************************************************************************************************************************************//
            state_button_face                      = FALSE;
            IF(!state_error_window){
//********************************************************************************************************************************COUNTER**MAX**1**//
               IF((counter_max % 2) == 1){
                  OFFer(LED_MAX_DEFAULT);
                  counter_max                         = 0;
                  counter_fan_driver                  = counter_fan_driver_before;
                  counter_window                      = counter_window_before;
                  counter_fresh_air                   = counter_fresh_air_before;
                  counter_valve_driver                = counter_valve_driver_before;
               }
               counter_window                         = 1;
               write_eeprom(address_window , counter_window);
            }
            ELSE{
               state_controller_error_in_button_window = TRUE;
            }
         }
//*************************************************************************************************************************************************//
         IF(INPUT(BUTTON_FACE)){
            state_button_face                      = TRUE;
         }
//*******************************************************************************************************************************BUTTON**TOGETHER**//
         IF(!INPUT(BUTTON_TOGETHER) && (state_button_together)){
            DELAY_MS(250);
//*************************************************************************************************************************************************//
            state_button_together                  = FALSE;
            IF(!state_error_window){
//********************************************************************************************************************************COUNTER**MAX**1**//
               IF((counter_max % 2) == 1){
                  OFFer(LED_MAX_DEFAULT);
                  counter_max                         = 0;
                  counter_fan_driver                  = counter_fan_driver_before;
                  counter_window                      = counter_window_before;
                  counter_fresh_air                   = counter_fresh_air_before;
                  counter_valve_driver                = counter_valve_driver_before;
               }
               counter_window                         = 2;
               write_eeprom(address_window , counter_window);
            }
            ELSE{
               state_controller_error_in_button_window = TRUE;
            }
         }
//*************************************************************************************************************************************************//
         IF(INPUT(BUTTON_TOGETHER)){
            state_button_together                  = TRUE;
         }
   }
//*************************************************************************************************************************************************//
//***********************************************************CONTROL**BUTTON**FRESH**AIR***********************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Fresh_Air(){
      IF((!INPUT(BUTTON_FRESH_AIR)) && (state_button_fresh_air)){
         DELAY_MS(250);
//*************************************************************************************************************************************************//
         state_button_fresh_air                    = FALSE;
         IF(!state_error_fresh_air){
//********************************************************************************************************************************COUNTER**MAX**1**//
            IF((counter_max % 2) == 1){
               OFFer(LED_MAX_DEFAULT);
               counter_max                         = 0;
               counter_fan_driver                  = counter_fan_driver_before;
               counter_window                      = counter_window_before;
               counter_fresh_air                   = counter_fresh_air_before;
               counter_valve_driver                = counter_valve_driver_before;
            }
            counter_fresh_air++;
            write_eeprom(address_fresh_air, counter_fresh_air);
         }
         ELSE{
            state_controller_error_in_button_fresh_air = TRUE;
         }
      }
//*************************************************************************************************************************************************//
      IF(INPUT(BUTTON_FRESH_AIR)){
         state_button_fresh_air                    = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//***********************************************************CONTROL**BUTTON**DRIVER**VALVE********************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Valve_Driver(){
      IF((!INPUT(BUTTON_VALVE_DRIVER)) && (state_button_valve_driver)){
         DELAY_MS(250);
//*************************************************************************************************************************************************//
         state_button_valve_driver              = FALSE;
         IF(!state_error_valve_driver){
//********************************************************************************************************************************COUNTER**MAX**1**//
            IF((counter_max % 2) == 1){
               OFFer(LED_MAX_DEFAULT);
               counter_max                         = 0;
               counter_fan_driver                  = counter_fan_driver_before;
               counter_window                      = counter_window_before;
               counter_fresh_air                   = counter_fresh_air_before;
               counter_valve_driver                = counter_valve_driver_before;
            }
            counter_valve_driver++;
            write_eeprom(address_valve_driver, counter_valve_driver);
         }
         ELSE{
            state_controller_error_in_button_valve_driver = TRUE;
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
         DELAY_MS(250);
//*************************************************************************************************************************************************//
         state_button_valve_passenger           = FALSE;
         IF(!state_error_valve_passenger){
            counter_valve_passenger++;
            write_eeprom(address_valve_passenger, counter_valve_passenger);
         }
         ELSE{
            state_controller_error_in_button_valve_passenger = TRUE;
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
         PWM_SETUP_FAN_DRIVER_ON;
//**********************************************************************************************************************************START**PWM**0**//
         IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_0){  
           counter_controller_fan_in_while         = 0;
           value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_0;
           WHILE((!state_controller_fan_driver_for_max) && (value_pwm_fan_driver < PWM_FAN_DRIVER_STEP_1)){
               value_pwm_fan_driver++;
               set_pwm2_duty(value_pwm_fan_driver);
               DELAY_MS(5);
               counter_controller_fan_in_while++;
               IF(counter_controller_fan_in_while > 100){ 
                  counter_controller_fan_in_while = 0;
                  Button_Controller_Functions_For_Fan(); 
                  Controller_Led_Functions();
               }
            }
         }
         ELSE{
            value_pwm_fan_driver                   = PWM_FAN_DRIVER_STEP_1;
            set_pwm2_duty(PWM_FAN_DRIVER_STEP_1);
         }
      }
//*************************************************************************************************************************************COUNTER**2**//
      IF((counter_fan_driver % 4) == 2){
         counter_fan_driver_old                    = counter_fan_driver;
         PWM_SETUP_FAN_DRIVER_ON;
//**********************************************************************************************************************************START**PWM**0**//
         IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_0){ 
            counter_controller_fan_in_while        = 0;
            value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_0;
            WHILE((!state_controller_fan_driver_for_max) && (value_pwm_fan_driver < PWM_FAN_DRIVER_STEP_2)){
               value_pwm_fan_driver++;
               set_pwm2_duty(value_pwm_fan_driver);
               DELAY_MS(5);
               counter_controller_fan_in_while++;
               IF(counter_controller_fan_in_while > 100){ 
                  counter_controller_fan_in_while = 0;
                  Button_Controller_Functions_For_Fan(); 
                  Controller_Led_Functions();
               }
            }
         }
//********************************************************************************************************************************START**PWM**600**//
         ELSE IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_1){ 
            counter_controller_fan_in_while        = 0;
            value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_1;
            WHILE((!state_controller_fan_driver_for_max) && (value_pwm_fan_driver < PWM_FAN_DRIVER_STEP_2)){
               value_pwm_fan_driver++;
               set_pwm2_duty(value_pwm_fan_driver);
               DELAY_MS(5);
               counter_controller_fan_in_while++;
               IF(counter_controller_fan_in_while > 100){ 
                  counter_controller_fan_in_while = 0;
                  Button_Controller_Functions_For_Fan(); 
                  Controller_Led_Functions();
               }
            }
         }
         ELSE{
            value_pwm_fan_driver                   = PWM_FAN_DRIVER_STEP_2 ;
            set_pwm2_duty(PWM_FAN_DRIVER_STEP_2);
         }
      }
//*************************************************************************************************************************************COUNTER**3**//
      IF((counter_fan_driver % 4) == 3){
         counter_fan_driver_old                    = counter_fan_driver;
         PWM_SETUP_FAN_DRIVER_ON;
//**********************************************************************************************************************************START**PWM**0**//
         IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_0){ 
            counter_controller_fan_in_while        = 0;
            value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_0;
            WHILE((!state_controller_fan_driver_for_max) && (value_pwm_fan_driver < PWM_FAN_DRIVER_STEP_3)){
               value_pwm_fan_driver++;
               set_pwm2_duty(value_pwm_fan_driver);
               DELAY_MS(5);
               counter_controller_fan_in_while++;
               IF(counter_controller_fan_in_while > 100){ 
                  counter_controller_fan_in_while = 0;
                  Button_Controller_Functions_For_Fan(); 
                  Controller_Led_Functions();
               }
            }
         }
//********************************************************************************************************************************START**PWM**600**//
         ELSE IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_1){ 
            counter_controller_fan_in_while        = 0;
            value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_1;
            WHILE((!state_controller_fan_driver_for_max) && (value_pwm_fan_driver < PWM_FAN_DRIVER_STEP_3)){
               value_pwm_fan_driver++;
               set_pwm2_duty(value_pwm_fan_driver);
               DELAY_MS(5);
               counter_controller_fan_in_while++;
               IF(counter_controller_fan_in_while > 100){ 
                  counter_controller_fan_in_while = 0;
                  Button_Controller_Functions_For_Fan(); 
                  Controller_Led_Functions();
               }
            }
         }
//********************************************************************************************************************************START**PWM**850**//
         ELSE IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_2){ 
            counter_controller_fan_in_while        = 0;
            value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_2;
            WHILE((!state_controller_fan_driver_for_max) && (value_pwm_fan_driver < PWM_FAN_DRIVER_STEP_3)){
               value_pwm_fan_driver++;
               set_pwm2_duty(value_pwm_fan_driver);
               DELAY_MS(5);
               counter_controller_fan_in_while++;
               IF(counter_controller_fan_in_while > 100){ 
                  counter_controller_fan_in_while = 0;
                  Button_Controller_Functions_For_Fan(); 
                  Controller_Led_Functions();
               }
            }
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
            IF((counter_max % 2) == 0){
               OFFer(LED_FAN_DRIVER_1_OFF);
               OFFer(LED_FAN_DRIVER_2_OFF);
               OFFer(LED_FAN_DRIVER_3_OFF);
            }
         }
//*************************************************************************************************************************************COUNTER**1**//
         IF((counter_fan_driver % 4) == 1){
            IF((counter_max % 2) == 0){
               ONer(LED_FAN_DRIVER_1_ON);
               OFFer(LED_FAN_DRIVER_2_OFF);
               OFFer(LED_FAN_DRIVER_3_OFF);
            }
         }       
//*************************************************************************************************************************************COUNTER**2**//
         IF((counter_fan_driver % 4) == 2){
            IF((counter_max % 2) == 0){
               ONer(LED_FAN_DRIVER_1_ON);
               ONer(LED_FAN_DRIVER_2_ON);
               OFFer(LED_FAN_DRIVER_3_OFF);
            }
         }
//*************************************************************************************************************************************COUNTER**3**//
         IF((counter_fan_driver % 4) == 3){
            IF((counter_max % 2) == 0){
               ONer(LED_FAN_DRIVER_1_ON);
               ONer(LED_FAN_DRIVER_2_ON);
               ONer(LED_FAN_DRIVER_3_ON);
            }
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
         PWM_SETUP_FAN_PASSENGER_ON;
//**********************************************************************************************************************************START**PWM**0**//
         IF(value_pwm_fan_passenger == PWM_FAN_PASSENGER_STEP_0){
            counter_controller_fan_in_while        = 0;
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
         PWM_SETUP_FAN_PASSENGER_ON;
//**********************************************************************************************************************************START**PWM**0**//
         IF(value_pwm_fan_passenger == PWM_FAN_PASSENGER_STEP_0){
            counter_controller_fan_in_while        = 0;
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
            counter_controller_fan_in_while        = 0;
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
         OFFer(LED_FAN_PASSENGER_1_OFF);
         OFFer(LED_FAN_PASSENGER_2_OFF);
      }
//*************************************************************************************************************************************COUNTER**1**//
      IF((counter_fan_passenger % 3) == 1){
         ONer(LED_FAN_PASSENGER_1_ON);
         OFFer(LED_FAN_PASSENGER_2_OFF);
      }
//*************************************************************************************************************************************COUNTER**2**//
      IF((counter_fan_passenger % 3) == 2){
         ONer(LED_FAN_PASSENGER_1_ON);
         ONer(LED_FAN_PASSENGER_2_ON);
      }
   }    
//*************************************************************************************************************************************************//
//*******************************************************************WINDOW**CONTROL***************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Window(){
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
      IF(!state_error_window){
//*******************************************************************************************************************************WINDOW**POSITION**//
         IF((counter_window % 3) == 0){
            counter_window                               = 0;
            counter_window_old                           = counter_window;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
            Turn_Left_Window();
            DELAY_MS(400);
            time_in_while_window_starting                = get_ticks();
            DELAY_MS(100);
            state_time_in_while_window                   = TRUE;
            state_time_in_while_start_window             = TRUE;
            time_window_starting                         = get_ticks();
            counter_button_controller_functions          = 0;
            state_turn_complete_window                   = FALSE;
//*************************************************************************************************************************************************//
            WHILE(!state_turn_complete_window){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions    = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
                  Special_Function_For_Fan_Driver_On_Max_In_While();
               }
               time_window_current                       = get_ticks();
               time_window_difference                    = Ticks_Difference(time_window_starting , time_window_current);
               Turn_Left_Window();
               DELAY_MS(30);
               Read_Current_Valve_Driver();
               IF(value_current_valve_driver > VALUE_SIDE_CURRENT_KLAPE_MOTOR){
                  IF(time_window_difference > time_controller_window){
                     Stop_Window();
                     DELAY_MS(100);
                     state_turn_complete_window             = TRUE;
                     state_time_in_while_window             = FALSE;
                     state_time_in_while_start_window       = FALSE;
                     counter_window_status                  = 0;
                  }
               }
               Controller_Time_In_While_Window();
            }
         }
//*********************************************************************************************************************************FACE**POSITION**//
         IF((counter_window % 3) == 1){
            counter_window_old                           = counter_window;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
            Turn_Right_Window();
            DELAY_MS(400);
            time_in_while_window_starting                = get_ticks();
            DELAY_MS(100);
            state_time_in_while_window                   = TRUE;
            state_time_in_while_start_window             = TRUE;
            time_window_starting                         = get_ticks();
            counter_button_controller_functions          = 0;
            state_turn_complete_window                   = FALSE;
//*************************************************************************************************************************************************//
            WHILE(!state_turn_complete_window){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions    = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
                  Special_Function_For_Fan_Driver_On_Max_In_While();
               }
               time_window_current                       = get_ticks();
               time_window_difference                    = Ticks_Difference(time_window_starting , time_window_current);
               Turn_Right_Window();
               DELAY_MS(30);
               Read_Current_Valve_Passenger();
               IF(value_current_valve_passenger > VALUE_SIDE_CURRENT_KLAPE_MOTOR){
                  IF(time_window_difference > time_controller_window){
                     Stop_Window();
                     DELAY_MS(100);
                     state_turn_complete_window             = TRUE;
                     state_time_in_while_window             = FALSE;
                     state_time_in_while_start_window       = FALSE;
                     counter_window_status                  = 1;
                  }
               }
               Controller_Time_In_While_Window();
            }
         }
//*****************************************************************************************************************************TOGETHER**POSITION**//
         IF((counter_window % 3) == 2){
            counter_window_old                                 = counter_window;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
//***************************************************************************************************************IF**COME**FROM**WINDOW**POSITION**//
            IF((counter_window_status % 3) == 0){
               Turn_Left_Window();
               DELAY_MS(250);
               Read_Current_Valve_Driver();
               Stop_Window();
               DELAY_MS(100);
//*************************************************************************************************************************************************//
               IF(value_current_valve_driver < VALUE_SIDE_CURRENT_TEST){
                  state_error_window                           = TRUE;
                  state_controller_error_in_while_loop_window  = TRUE;
                  state_controller_error_in_button_window      = TRUE;
               }
               ELSE{
                  state_error_window                           = FALSE;
                  state_controller_error_in_while_loop_window  = FALSE;
                  state_controller_error_in_button_window      = FALSE;
               }
               IF(!state_error_window){
                  Turn_Right_Window();
                  DELAY_MS(500);
                  time_window_starting                         = get_ticks();
                  counter_button_controller_functions          = 0;
                  state_turn_complete_window                   = FALSE;
//*************************************************************************************************************************************************//
                  WHILE(!state_turn_complete_window){
                     Turn_Right_Window();
                     DELAY_MS(1);
                     counter_button_controller_functions++;
                     IF(counter_button_controller_functions > 500){
                        counter_button_controller_functions    = 0;
                        Button_Controller_Functions(); 
                        Controller_Led_Functions();
                        Special_Function_For_Fan_Driver_On_Max_In_While();
                     }
                     time_window_current                       = get_ticks();
                     time_window_difference                    = Ticks_Difference(time_window_starting, time_window_current);
                     IF(time_window_difference > (time_window_mid + 800)){
                        Stop_Window();
                        DELAY_MS(100);
                        state_turn_complete_window             = TRUE;
                        counter_window_status                  = 2;
                     }
                  }
               }
            }
//*****************************************************************************************************************IF**COME**FROM**FACE**POSITION**//
            IF((counter_window_status % 3) == 1){
               Turn_Right_Window();
               DELAY_MS(250);
               Read_Current_Valve_Passenger();
               Stop_Window();
               DELAY_MS(100);
//*************************************************************************************************************************************************//
               IF(value_current_valve_passenger < VALUE_SIDE_CURRENT_TEST){
                  state_error_window                           = TRUE;
                  state_controller_error_in_while_loop_window  = TRUE;
                  state_controller_error_in_button_window      = TRUE;
               }
               ELSE{
                  state_error_window                           = FALSE;
                  state_controller_error_in_while_loop_window  = FALSE;
                  state_controller_error_in_button_window      = FALSE;
               }
               IF(!state_error_window){
                  Turn_Left_Window();
                  DELAY_MS(500);
                  time_window_starting                         = get_ticks();
                  counter_button_controller_functions          = 0;
                  state_turn_complete_window                   = FALSE;
//*************************************************************************************************************************************************//
                  WHILE(!state_turn_complete_window){
                     Turn_Left_Window();
                     DELAY_MS(1);
                     counter_button_controller_functions++;
                     IF(counter_button_controller_functions > 500){
                        counter_button_controller_functions = 0;
                        Button_Controller_Functions(); 
                        Controller_Led_Functions();
                        Special_Function_For_Fan_Driver_On_Max_In_While();
                     }
                     time_window_current = get_ticks();
                     time_window_difference = Ticks_Difference(time_window_starting, time_window_current);
                     IF(time_window_difference > (time_window_mid + 400)){
                        Stop_Window();
                        DELAY_MS(100);
                        state_turn_complete_window = TRUE;
                        counter_window_status = 2;
                     }
                  }
               }
            }
         }
      }
//***************************************************************************************************************************IF**THERE**IS**ERROR**//
      ELSE{
         OFFer(LED_WINDOW_OFF);
         OFFer(LED_FACE_OFF);
         OFFer(LED_TOGETHER_OFF);
      }
   }
//*************************************************************************************************************************************************//
//***************************************************************WINDOW**CONTROL**IN**WHILE********************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Led_Window(){
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
      IF(!state_error_window){
//*******************************************************************************************************************************WINDOW**POSITION**//
         IF((counter_window % 3) == 0){
            IF((counter_max % 2) == 0){
               ONer(LED_WINDOW_ON);   
               OFFer(LED_FACE_OFF);
               OFFer(LED_TOGETHER_OFF);
            }
         }
//**********************************************************************************************************************************FACE**POSITION**//
         IF((counter_window % 3) == 1){
            IF((counter_max % 2) == 0){
               OFFer(LED_WINDOW_OFF);
               ONer(LED_FACE_ON);
               OFFer(LED_TOGETHER_OFF);
            }
         }
//*****************************************************************************************************************************TOGETHER**POSITION**//
         IF((counter_window % 3) == 2){
            IF((counter_max % 2) == 0){
               OFFer(LED_WINDOW_OFF);
               OFFer(LED_FACE_OFF);
               ONer(LED_TOGETHER_ON);
            }
         }
      }
//***************************************************************************************************************************IF**THERE**IS**ERROR**//
      ELSE{
         OFFer(LED_WINDOW_OFF);
         OFFer(LED_FACE_OFF);
         OFFer(LED_TOGETHER_OFF);
      }
   }  
//*************************************************************************************************************************************************//
//*************************************************************FRESH**AIR**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Fresh_Air(){
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
      IF(!state_error_fresh_air){
//*************************************************************************************************************************************COUNTER**0**//
         IF((counter_fresh_air % 2) == 0){
            counter_fresh_air                               = 0;
            counter_fresh_air_old                           = counter_fresh_air;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
            Turn_Left_Fresh_Air();
            DELAY_MS(400);
            time_in_while_fresh_air_starting                = get_ticks();
            DELAY_MS(100);
            state_time_in_while_fresh_air                   = TRUE;
            state_time_in_while_start_fresh_air             = TRUE;
            time_fresh_air_starting                         = get_ticks();
            counter_button_controller_functions          = 0;
            state_turn_complete_fresh_air                   = FALSE;
//*************************************************************************************************************************************************//
            WHILE(!state_turn_complete_fresh_air){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions       = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
                  Special_Function_For_Fan_Driver_On_Max_In_While();
               }
               time_fresh_air_current                       = get_ticks();
               time_fresh_air_difference                    = Ticks_Difference(time_fresh_air_starting , time_fresh_air_current);
               Turn_Left_Fresh_Air();
               DELAY_MS(30);
               Read_Current_Valve_Passenger();
               IF(value_current_valve_passenger > VALUE_SIDE_CURRENT_KLAPE_MOTOR){
                  IF(time_fresh_air_difference > time_controller_fresh_air){
                     Stop_Fresh_Air();
                     DELAY_MS(100);
                     state_turn_complete_fresh_air          = TRUE;
                     state_time_in_while_fresh_air          = FALSE;
                     state_time_in_while_start_fresh_air    = FALSE;
                  }
               }
               Controller_Time_In_While_Fresh_Air();
            }
         }
//*************************************************************************************************************************************COUNTER**1**//
         IF((counter_fresh_air % 2) == 1){
            counter_fresh_air_old                           = counter_fresh_air;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
            Turn_Right_Fresh_Air();
            DELAY_MS(400);
            time_in_while_fresh_air_starting                = get_ticks();
            DELAY_MS(100);
            state_time_in_while_fresh_air                   = TRUE;
            state_time_in_while_start_fresh_air             = TRUE;
            time_fresh_air_starting                         = get_ticks();
            counter_button_controller_functions             = 0;
            state_turn_complete_fresh_air                   = FALSE;
//*************************************************************************************************************************************************//
            WHILE(!state_turn_complete_fresh_air){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions       = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
                  Special_Function_For_Fan_Driver_On_Max_In_While();
               }
               time_fresh_air_current                       = get_ticks();
               time_fresh_air_difference                    = Ticks_Difference(time_fresh_air_starting , time_fresh_air_current);
               Turn_Right_Fresh_Air();
               DELAY_MS(30);
               Read_Current_Valve_Driver();
               IF(value_current_valve_driver > VALUE_SIDE_CURRENT_KLAPE_MOTOR){
                  IF(time_fresh_air_difference > time_controller_fresh_air){
                     Stop_Fresh_Air();
                     DELAY_MS(100);
                     state_turn_complete_fresh_air          = TRUE;
                     state_time_in_while_fresh_air          = FALSE;
                     state_time_in_while_start_fresh_air    = FALSE;
                  }
               }
               Controller_Time_In_While_Fresh_Air();
            }
         }
      }
//***************************************************************************************************************************IF**THERE**IS**ERROR**//
      ELSE{
         OFFer(LED_FRESH_AIR_OFF);
      }
   }
//*************************************************************************************************************************************************//
//**********************************************************FRESH**AIR**CONTROLLER**IN**WHILE******************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Led_Fresh_Air(){
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
      IF(!state_error_fresh_air){
//*************************************************************************************************************************************COUNTER**0**//
         IF((counter_fresh_air % 2) == 0){
            IF((counter_max % 2) == 0){
               OFFer(LED_FRESH_AIR_OFF);
            }
         }
//*************************************************************************************************************************************COUNTER**1**//
         IF((counter_fresh_air % 2) == 1){
            IF((counter_max % 2) == 0){
               ONer(LED_FRESH_AIR_ON);
            }
         }
      }
//***************************************************************************************************************************IF**THERE**IS**ERROR**//
      ELSE{
         OFFer(LED_FRESH_AIR_OFF);
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
            counter_valve_driver                               = 0;
            counter_valve_driver_old                           = counter_valve_driver;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
            Turn_Left_Valve_Driver();
            DELAY_MS(400);
            time_in_while_valve_driver_starting                = get_ticks();
            DELAY_MS(100);
            state_time_in_while_valve_driver                   = TRUE;
            state_time_in_while_start_valve_driver             = TRUE;
            time_valve_driver_starting                         = get_ticks();
            counter_button_controller_functions                = 0;
            state_turn_complete_valve_driver                   = FALSE;
//*************************************************************************************************************************************************//
            WHILE(!state_turn_complete_valve_driver){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions          = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
                  Special_Function_For_Fan_Driver_On_Max_In_While();
               }
               time_valve_driver_current                       = get_ticks();
               time_valve_driver_difference                    = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
               Turn_Left_Valve_Driver();
               DELAY_MS(30);
               Read_Current_Valve_Driver();
               IF(value_current_valve_driver > VALUE_SIDE_CURRENT_KORMAS_VALVE){
                  IF(time_valve_driver_difference > time_controller_valve_driver){
                     Stop_Valve_Driver();
                     DELAY_MS(100);
                     state_turn_complete_valve_driver          = TRUE;
                     state_time_in_while_valve_driver          = FALSE;
                     state_time_in_while_start_valve_driver    = FALSE;
                     counter_valve_driver_status               = 0;
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
               Read_Current_Valve_Driver();
               Stop_Valve_Driver();
               DELAY_MS(100);
//*************************************************************************************************************************************************//
               IF(value_current_valve_driver < VALUE_SIDE_CURRENT_TEST){
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
                        Special_Function_For_Fan_Driver_On_Max_In_While();
                     }
                     time_valve_driver_current                       = get_ticks();
                     time_valve_driver_difference                    = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
                     IF(time_valve_driver_difference > (time_valve_driver_mid + 300)){
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
               Read_Current_Valve_Driver();
               Stop_Valve_Driver();
               DELAY_MS(100);
//*************************************************************************************************************************************************//
               IF(value_current_valve_driver < VALUE_SIDE_CURRENT_TEST){
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
                        Special_Function_For_Fan_Driver_On_Max_In_While();
                     }
                     time_valve_driver_current                       = get_ticks();
                     time_valve_driver_difference                    = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
                     IF(time_valve_driver_difference > (time_valve_driver_mid + 600)){
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
            counter_valve_driver_old                                 = counter_valve_driver;
            Turn_Right_Valve_Driver();
            DELAY_MS(400);
            time_in_while_valve_driver_starting                      = get_ticks();
            DELAY_MS(100);
            state_time_in_while_valve_driver                         = TRUE;
            state_time_in_while_start_valve_driver                   = TRUE;
            time_valve_driver_starting                               = get_ticks();
            counter_button_controller_functions                      = 0;
            state_turn_complete_valve_driver                         = FALSE;
//*************************************************************************************************************************************************//
            WHILE(!state_turn_complete_valve_driver){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions                = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
                  Special_Function_For_Fan_Driver_On_Max_In_While();
               }
               time_valve_driver_current                             = get_ticks();
               time_valve_driver_difference                          = Ticks_Difference(time_valve_driver_starting , time_valve_driver_current);
               Turn_Right_Valve_Driver();
               DELAY_MS(30);
               Read_Current_Valve_Driver();
               IF(value_current_valve_driver > VALUE_SIDE_CURRENT_KORMAS_VALVE){
                  IF(time_valve_driver_difference > time_controller_valve_driver){
                     Stop_Valve_Driver();
                     DELAY_MS(100);
                     state_turn_complete_valve_driver                = TRUE;
                     state_time_in_while_valve_driver                = FALSE;
                     state_time_in_while_start_valve_driver          = FALSE;
                     counter_valve_driver_status                     = 1;
                  }
               }
               Controller_Time_In_While_Valve_Driver();
            }
         }
      }
//***************************************************************************************************************************IF**THERE**IS**ERROR**//
      ELSE{
         OFFer(LED_VALVE_DRIVER_0_OFF);
         OFFer(LED_VALVE_DRIVER_1_OFF);
         OFFer(LED_VALVE_DRIVER_2_OFF);
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
            IF((counter_max % 2) == 0){
               ONer(LED_VALVE_DRIVER_0_ON);
               OFFer(LED_VALVE_DRIVER_1_OFF);
               OFFer(LED_VALVE_DRIVER_2_OFF);
            }
         }
//*************************************************************************************************************************************COUNTER**1**//
         IF((counter_valve_driver % 3) == 1){
            IF((counter_max % 2) == 0){
               OFFer(LED_VALVE_DRIVER_0_OFF);
               ONer(LED_VALVE_DRIVER_1_ON);
               OFFer(LED_VALVE_DRIVER_2_OFF);
            }
         }
//*************************************************************************************************************************************COUNTER**2**//
         IF((counter_valve_driver % 3) == 2){
            IF((counter_max % 2) == 0){
               OFFer(LED_VALVE_DRIVER_0_OFF);
               ONer(LED_VALVE_DRIVER_1_ON);
               ONer(LED_VALVE_DRIVER_2_ON);
            }
         }
      }
//***************************************************************************************************************************IF**THERE**IS**ERROR**//
      ELSE{
         OFFer(LED_VALVE_DRIVER_0_OFF);
         OFFer(LED_VALVE_DRIVER_1_OFF);
         OFFer(LED_VALVE_DRIVER_2_OFF);
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
            counter_valve_passenger                                  = 0;
            counter_valve_passenger_old                              = counter_valve_passenger;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
            Turn_Left_Valve_Passenger();
            DELAY_MS(400);
            time_in_while_valve_passenger_starting                   = get_ticks();
            DELAY_MS(100);
            state_time_in_while_valve_passenger                      = TRUE;
            state_time_in_while_start_valve_passenger                = TRUE;
            time_valve_passenger_starting                            = get_ticks();
            counter_button_controller_functions                      = 0;
            state_turn_complete_valve_passenger                      = FALSE;
//*************************************************************************************************************************************************//
            WHILE(!state_turn_complete_valve_passenger){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions                = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
                  Special_Function_For_Fan_Driver_On_Max_In_While();
               }
               time_valve_passenger_current                          = get_ticks();
               time_valve_passenger_difference                       = Ticks_Difference(time_valve_passenger_starting , time_valve_passenger_current);
               Turn_Left_Valve_Passenger();
               DELAY_MS(30);
               Read_Current_Valve_Passenger();
               IF(value_current_valve_passenger > VALUE_SIDE_CURRENT_KORMAS_VALVE){
                  IF(time_valve_passenger_difference > time_controller_valve_passenger){
                     Stop_Valve_Passenger();
                     DELAY_MS(100);
                     state_turn_complete_valve_passenger                = TRUE;
                     state_time_in_while_valve_passenger                = FALSE;
                     state_time_in_while_start_valve_passenger          = FALSE;
                     counter_valve_passenger_status                     = 0;
                  }
               }
               Controller_Time_In_While_Valve_Passenger();
            }
         }
//*************************************************************************************************************************************COUNTER**1**//
         IF((counter_valve_passenger % 3) == 1){
            counter_valve_passenger_old                                 = counter_valve_passenger;
//****************************************************************************************************************IF**COME**FROM**CLOSE**POSITION**//
            IF((counter_valve_passenger_status % 3) == 0){
               Turn_Left_Valve_Passenger();
               DELAY_MS(250);
               Read_Current_Valve_Passenger();
               Stop_Valve_Passenger();
               DELAY_MS(100);
//*************************************************************************************************************************************************//
               IF(value_current_valve_passenger < VALUE_SIDE_CURRENT_TEST){
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
                        counter_button_controller_functions          = 0;
                        Button_Controller_Functions(); 
                        Controller_Led_Functions();
                        Special_Function_For_Fan_Driver_On_Max_In_While();
                     }
                     time_valve_passenger_current                    = get_ticks();
                     time_valve_passenger_difference                 = Ticks_Difference(time_valve_passenger_starting , time_valve_passenger_current);
                     IF(time_valve_passenger_difference > (time_valve_passenger_mid + 300)){
                        Stop_Valve_Passenger();
                        DELAY_MS(100);
                        state_turn_complete_valve_passenger          = TRUE;
                        counter_valve_passenger_status               = 2;
                     }
                  }
               }
            }
//*****************************************************************************************************************IF**COME**FROM**OPEN**POSITION**//
            IF((counter_valve_passenger_status % 3) == 1){
               Turn_Right_Valve_Passenger();
               DELAY_MS(250);
               Read_Current_Valve_Passenger();
               Stop_Valve_Passenger();
               DELAY_MS(100);
//*************************************************************************************************************************************************//
               IF(value_current_valve_passenger < VALUE_SIDE_CURRENT_TEST){
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
                        Special_Function_For_Fan_Driver_On_Max_In_While();
                     }
                     time_valve_passenger_current                    = get_ticks();
                     time_valve_passenger_difference                 = Ticks_Difference(time_valve_passenger_starting , time_valve_passenger_current);
                     IF(time_valve_passenger_difference > (time_valve_passenger_mid + 600)){
                        Stop_Valve_Passenger();
                        DELAY_MS(100);
                        state_turn_complete_valve_passenger          = TRUE;
                        counter_valve_passenger_status               = 2;
                     }
                  }
               }
            }
         }
//*************************************************************************************************************************************COUNTER**2**//
         IF((counter_valve_passenger % 3) == 2){
            counter_valve_passenger_old                              = counter_valve_passenger;
            Turn_Right_Valve_Passenger();
            DELAY_MS(400);
            time_in_while_valve_passenger_starting                   = get_ticks();
            DELAY_MS(100);
            state_time_in_while_valve_passenger                      = TRUE;
            state_time_in_while_start_valve_passenger                = TRUE;
            time_valve_passenger_starting                            = get_ticks();
            counter_button_controller_functions                      = 0;
            state_turn_complete_valve_passenger                      = FALSE;
//*************************************************************************************************************************************************//
            WHILE(!state_turn_complete_valve_passenger){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions                = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
                  Special_Function_For_Fan_Driver_On_Max_In_While();
               }
               time_valve_passenger_current                          = get_ticks();
               time_valve_passenger_difference                       = Ticks_Difference(time_valve_passenger_starting , time_valve_passenger_current);
               Turn_Right_Valve_Passenger();
               DELAY_MS(30);
               Read_Current_Valve_Passenger();
               IF(value_current_valve_passenger > VALUE_SIDE_CURRENT_KORMAS_VALVE){
                  IF(time_valve_passenger_difference > time_controller_valve_passenger){
                     Stop_Valve_Passenger();
                     DELAY_MS(100);
                     state_turn_complete_valve_passenger             = TRUE;
                     state_time_in_while_valve_passenger             = FALSE;
                     state_time_in_while_start_valve_passenger       = FALSE;
                     counter_valve_passenger_status                  = 1;
                  }
               }
               Controller_Time_In_While_Valve_Passenger();
            }
         }
      }
//***************************************************************************************************************************IF**THERE**IS**ERROR**//
      ELSE{
         OFFer(LED_VALVE_PASSENGER_0_OFF);
         OFFer(LED_VALVE_PASSENGER_1_OFF);
         OFFer(LED_VALVE_PASSENGER_2_OFF);
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
            ONer(LED_VALVE_PASSENGER_0_ON);
            OFFer(LED_VALVE_PASSENGER_1_OFF);
            OFFer(LED_VALVE_PASSENGER_2_OFF);
         }
//*************************************************************************************************************************************COUNTER**1**//
         IF((counter_valve_passenger % 3) == 1){
            OFFer(LED_VALVE_PASSENGER_0_OFF);
            ONer(LED_VALVE_PASSENGER_1_ON);
            OFFer(LED_VALVE_PASSENGER_2_OFF);
         }
//*************************************************************************************************************************************COUNTER**2**//
         IF((counter_valve_passenger % 3) == 2){
            OFFer(LED_VALVE_PASSENGER_0_OFF);
            ONer(LED_VALVE_PASSENGER_1_ON);
            ONer(LED_VALVE_PASSENGER_2_ON);
         }
      }
//***************************************************************************************************************************IF**THERE**IS**ERROR**//
      ELSE{
         OFFer(LED_VALVE_PASSENGER_0_OFF);
         OFFer(LED_VALVE_PASSENGER_1_OFF);
         OFFer(LED_VALVE_PASSENGER_2_OFF);
      }
   }
//*************************************************************************************************************************************************//
//*******************************************************************ERROR**CONTROL****************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Time_In_While_Window(){
//*************************************************************************************************************************************************//
      IF(state_time_in_while_window){
         time_in_while_window_current                          = get_ticks();
         time_in_while_window_difference                       = Ticks_Difference(time_in_while_window_starting , time_in_while_window_current);
         IF((time_in_while_window_difference > time_error_window_difference) && (state_time_in_while_start_window)){
            Stop_Window();
            DELAY_MS(100);
            state_time_in_while_window                         = FALSE;
            state_error_window                                 = TRUE;
            state_turn_complete_window                         = TRUE;
            state_controller_error_in_button_window            = TRUE;
            state_controller_error_in_while_loop_window        = TRUE;
         }
      }
   }
//*************************************************************************************************************************************************//
//*******************************************************************ERROR**CONTROL****************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Time_In_While_Fresh_Air(){
//*************************************************************************************************************************************************//
      IF(state_time_in_while_fresh_air){
         time_in_while_fresh_air_current        = get_ticks();
         time_in_while_fresh_air_difference     = Ticks_Difference(time_in_while_fresh_air_starting , time_in_while_fresh_air_current);
         IF((time_in_while_fresh_air_difference > time_error_fresh_air_difference) && (state_time_in_while_start_fresh_air)){
            Stop_Fresh_Air();
            DELAY_MS(100);
            state_time_in_while_fresh_air                      = FALSE;
            state_error_fresh_air                              = TRUE;
            state_turn_complete_fresh_air                      = TRUE;
            state_controller_error_in_button_fresh_air         = TRUE;
            state_controller_error_in_while_loop_fresh_air     = TRUE;
         }
      }
   }
//*************************************************************************************************************************************************//
//*******************************************************************ERROR**CONTROL****************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Time_In_While_Valve_Driver(){
//*************************************************************************************************************************************************//
      IF(state_time_in_while_valve_driver){
         time_in_while_valve_driver_current           = get_ticks();
         time_in_while_valve_driver_difference        = Ticks_Difference(time_in_while_valve_driver_starting , time_in_while_valve_driver_current);
         IF((time_in_while_valve_driver_difference > time_error_valve_driver_difference) && (state_time_in_while_start_valve_driver)){
            Stop_Valve_Driver();
            DELAY_MS(100);
            state_time_in_while_valve_driver                         = FALSE;
            state_error_valve_driver                                 = TRUE;
            state_turn_complete_valve_driver                         = TRUE;
            state_controller_error_in_button_valve_driver            = TRUE;
            state_controller_error_in_while_loop_valve_driver        = TRUE;
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
         time_in_while_valve_passenger_difference  = Ticks_Difference(time_in_while_valve_passenger_starting, time_in_while_valve_passenger_current);
         IF((time_in_while_valve_passenger_difference > time_error_valve_passenger_difference) && (state_time_in_while_start_valve_passenger)){
            Stop_Valve_Passenger();
            DELAY_MS(100);
            state_time_in_while_valve_passenger                      = FALSE;
            state_error_valve_passenger                              = TRUE;
            state_turn_complete_valve_passenger                      = TRUE;
            state_controller_error_in_button_valve_passenger         = TRUE;
            state_controller_error_in_while_loop_valve_passenger     = TRUE;
            Controller_Pomp();
            Controller_Time_Pomp();
         }
      }
   }
//*************************************************************************************************************************************************//
//*******************************************************************ERROR**SHOWING****************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Error_In_While_Loop(){
//*****************************************************************************************************************************************WINDOW**//
      IF(state_controller_error_in_while_loop_window){
         Turn_Left_Window();
         DELAY_MS(500);
         Button_Controller_Functions(); 
         Controller_Led_Functions();
         Read_Current_Valve_Driver();
         Stop_Window();
         DELAY_MS(100);
         IF(value_current_valve_driver > VALUE_SIDE_CURRENT_KLAPE_MOTOR){
            Stop_Window();
            state_error_window                              = FALSE;
            state_controller_error_in_while_loop_window     = FALSE;
            Time_Klape_Once_Window();
            counter_window_status                           = 0;
            counter_window_before                           = 0;
            Controller_Window();
            IF((counter_max % 2) == 1){
               ONer(LED_WINDOW_ON);   
               OFFer(LED_FACE_OFF);
               OFFer(LED_TOGETHER_OFF);
            }
            ELSE{
               Controller_Led_Window();
            }
         }
      }
//*************************************************************************************************************************************FRESH**AIR**//
      IF(state_controller_error_in_while_loop_fresh_air){
         Turn_Right_Fresh_Air();
         DELAY_MS(500);
         Button_Controller_Functions(); 
         Controller_Led_Functions();
         Read_Current_Valve_Driver();
         Stop_Fresh_Air();
         DELAY_MS(100);
         IF(value_current_valve_driver > VALUE_SIDE_CURRENT_KLAPE_MOTOR){
            Stop_Fresh_Air();
            state_error_fresh_air                           = FALSE;
            state_controller_error_in_while_loop_fresh_air  = FALSE;
            Time_Klape_Once_Fresh_Air();
            counter_fresh_air_before                        = 1;
            Controller_Fresh_Air();
            IF((counter_max % 2) == 1){
               ONer(LED_FRESH_AIR_ON);
            }
            ELSE{
               Controller_Led_Fresh_Air();
            }
         }
      }
//**********************************************************************************************************************************VALVE**DRIVER**//
      IF(state_controller_error_in_while_loop_valve_driver){
         Turn_Left_Valve_Driver();
         DELAY_MS(500);
         Button_Controller_Functions(); 
         Controller_Led_Functions();
         Read_Current_Valve_Driver();
         Stop_Valve_Driver();
         DELAY_MS(100);
         IF(value_current_valve_driver > VALUE_SIDE_CURRENT_KORMAS_VALVE){
            Stop_Valve_Driver();
            state_error_valve_driver                              = FALSE;
            state_controller_error_in_while_loop_valve_driver     = FALSE;
            Time_Klape_Once_Valve_Driver();
            counter_valve_driver_status                           = 0;
            counter_valve_driver_before                           = 0;
            Controller_Valve_Driver();
            IF((counter_max % 2) == 1){
               ONer(LED_VALVE_DRIVER_0_ON);   
               OFFer(LED_VALVE_DRIVER_1_OFF);
               OFFer(LED_VALVE_DRIVER_2_OFF);
            }
            ELSE{
               Controller_Led_Valve_Driver();
            }
         }
      }
//*******************************************************************************************************************************VALVE**PASSENGER**//
      IF(state_controller_error_in_while_loop_valve_passenger){
         Turn_Left_Valve_Passenger();
         DELAY_MS(500);
         Button_Controller_Functions(); 
         Controller_Led_Functions();
         Read_Current_Valve_Passenger();
         Stop_Valve_Passenger();
         DELAY_MS(100);
         IF(value_current_valve_passenger > VALUE_SIDE_CURRENT_KORMAS_VALVE){
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
   VOID Controller_Air_Conditioning(){
      IF((!((counter_fan_driver % 4) == 0)) && ((counter_max % 2) == 0)){
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
            time_controller_pomp_current           = get_ticks();
            time_controller_pomp_difference        = Ticks_Difference(time_controller_pomp_starting , time_controller_pomp_current);
            IF(time_controller_pomp_difference > TIME_POMP_ON){
               state_process_complete_pomp         = TRUE;
               OUTPUT_HIGH(POMP_OUT);
            }
         }
      }
      ELSE{
         state_process_complete_pomp               = TRUE;
         OUTPUT_LOW(POMP_OUT);
      }
   }
//*************************************************************************************************************************************************//
//***********************************************************************LED***********************************************************************//
//*************************************************************************************************************************************************//
   VOID Write_Led(INT16 write_led_integer){
      OUTPUT_LOW(LED_ST_CP);
      FOR(counter_write_led = 0; counter_write_led < 16; counter_write_led++){
         OUTPUT_LOW(LED_SH_CP);
         if((write_led_integer << counter_write_led) & 0x8000){
            OUTPUT_HIGH(LED_DATA);
         }
         ELSE{
            OUTPUT_LOW(LED_DATA);
         }
         OUTPUT_HIGH(LED_SH_CP);
      }
      OUTPUT_HIGH(LED_ST_CP);
   }
//*************************************************************************************************************************************************//
//**************************************************************CONTROL**ERROR**IN**BUTTON*********************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Error_In_Button(){
//*************************************************************************************************************************************************//
      IF(state_controller_error_in_button_window){
         ONer(LED_WINDOW_ON);
         ONer(LED_FACE_ON);
         ONer(LED_TOGETHER_ON);
         DELAY_MS(120);
         OFFer(LED_WINDOW_OFF);
         OFFer(LED_FACE_OFF);
         OFFer(LED_TOGETHER_OFF);
         DELAY_MS(80);
         ONer(LED_WINDOW_ON);
         ONer(LED_FACE_ON);
         ONer(LED_TOGETHER_ON);
         DELAY_MS(120);
         OFFer(LED_WINDOW_OFF);
         OFFer(LED_FACE_OFF);
         OFFer(LED_TOGETHER_OFF);
         state_controller_error_in_button_window = FALSE;
      }
//*************************************************************************************************************************************************//
      IF(state_controller_error_in_button_fresh_air){
         ONer(LED_FRESH_AIR_ON);
         DELAY_MS(120);
         OFFer(LED_FRESH_AIR_OFF);
         DELAY_MS(80);
         ONer(LED_FRESH_AIR_ON);
         DELAY_MS(120);
         OFFer(LED_FRESH_AIR_OFF);
         state_controller_error_in_button_fresh_air = FALSE;
      }
//*************************************************************************************************************************************************//
      IF(state_controller_error_in_button_valve_driver){
         ONer(LED_VALVE_DRIVER_0_ON);
         ONer(LED_VALVE_DRIVER_1_ON);
         ONer(LED_VALVE_DRIVER_2_ON);
         DELAY_MS(120);
         OFFer(LED_VALVE_DRIVER_0_OFF);
         OFFer(LED_VALVE_DRIVER_1_OFF);
         OFFer(LED_VALVE_DRIVER_2_OFF);
         DELAY_MS(80);
         ONer(LED_VALVE_DRIVER_0_ON);
         ONer(LED_VALVE_DRIVER_1_ON);
         ONer(LED_VALVE_DRIVER_2_ON);
         DELAY_MS(120);
         OFFer(LED_VALVE_DRIVER_0_OFF);
         OFFer(LED_VALVE_DRIVER_1_OFF);
         OFFer(LED_VALVE_DRIVER_2_OFF);
         state_controller_error_in_button_valve_driver = FALSE;
      }
//*************************************************************************************************************************************************//
      IF(state_controller_error_in_button_valve_passenger){
         ONer(LED_VALVE_PASSENGER_0_ON);
         ONer(LED_VALVE_PASSENGER_1_ON);
         ONer(LED_VALVE_PASSENGER_2_ON);
         DELAY_MS(120);
         OFFer(LED_VALVE_PASSENGER_0_OFF);
         OFFer(LED_VALVE_PASSENGER_1_OFF);
         OFFer(LED_VALVE_PASSENGER_2_OFF);
         DELAY_MS(80);
         ONer(LED_VALVE_PASSENGER_0_ON);
         ONer(LED_VALVE_PASSENGER_1_ON);
         ONer(LED_VALVE_PASSENGER_2_ON);
         DELAY_MS(120);
         OFFer(LED_VALVE_PASSENGER_0_OFF);
         OFFer(LED_VALVE_PASSENGER_1_OFF);
         OFFer(LED_VALVE_PASSENGER_2_OFF);
         state_controller_error_in_button_valve_passenger = FALSE;
      }
   }
//*************************************************************************************************************************************************//
//******************************************************************TURN**ON**LED******************************************************************//
//*************************************************************************************************************************************************//
   VOID ONer(INT16 process_counter_1){
      leds_register                                = leds_register | process_counter_1;
      Write_Led(leds_register);
   }
//*************************************************************************************************************************************************//
//******************************************************************TURN**OFF**LED*****************************************************************//
//*************************************************************************************************************************************************//
   VOID OFFer(INT16 process_counter_2){
      leds_register                                = leds_register & process_counter_2;
      Write_Led(leds_register);
   }
//*************************************************************************************************************************************************//
//**************************************************************MEASURE**TICKs**DIFFERENCE*********************************************************//
//*************************************************************************************************************************************************//
   INT32 Ticks_Difference(INT32 time_starting, INT32 time_current){
      time_difference = (time_current - time_starting);
      RETURN time_difference;
   }
//*************************************************************************************************************************************************//
//*******************************************************************READ**MOTOR*******************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************CURRENT**DRIVER**VALVE**//
   VOID Read_Current_Valve_Driver(){
      value_current_valve_driver = 0;
      FOR(INT8 i = 0; i < 10; i++){
         SET_ADC_CHANNEL(CHANNEL_Current_Valve_Driver);
         DELAY_MS(2);
         value_current_temporary                         = READ_ADC();
         value_current_valve_driver                      = value_current_valve_driver + value_current_temporary;
      }
      value_current_valve_driver = (value_current_valve_driver / 10);
   }
//**********************************************************************************************************************CURRENT**PASSENGER**VALVE**//
   VOID Read_Current_Valve_Passenger(){
      value_current_valve_passenger = 0;
      FOR(INT8 j = 0; j < 10; j++){
         SET_ADC_CHANNEL(CHANNEL_Current_Valve_Passenger);
         DELAY_MS(2);
         value_current_temporary                         = READ_ADC();
         value_current_valve_passenger                   = value_current_valve_passenger + value_current_temporary;
      }
      value_current_valve_passenger = (value_current_valve_passenger / 10);
   }
//*************************************************************************************************************************************************//
//****************************************************************MOVEMENT**MOTOR******************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
//*****************************************************************************************************************************************WINDOW**//
//*************************************************************************************************************************************************//
//************************************************************************************************************************************TURN**RIGHT**//
   VOID Turn_Right_Window(){
      OUTPUT_LOW(WINDOW_EN_1);
      OUTPUT_LOW(WINDOW_EN_2);
      OUTPUT_LOW(WINDOW_IN_1);
      OUTPUT_HIGH(WINDOW_IN_2);
      OUTPUT_LOW(FRESH_AIR_IN_1);
      OUTPUT_LOW(FRESH_AIR_IN_2);
   }
//*************************************************************************************************************************************TURN**LEFT**//
   VOID Turn_Left_Window(){
      OUTPUT_LOW(FRESH_AIR_EN_1);
      OUTPUT_LOW(FRESH_AIR_EN_2);
      OUTPUT_LOW(FRESH_AIR_IN_1);
      OUTPUT_HIGH(FRESH_AIR_IN_2);
      OUTPUT_LOW(WINDOW_IN_1);
      OUTPUT_LOW(WINDOW_IN_2);
   }
//*******************************************************************************************************************************************STOP**//
   VOID Stop_Window(){
      OUTPUT_HIGH(WINDOW_EN_1);
      OUTPUT_HIGH(WINDOW_EN_2);
      OUTPUT_LOW(WINDOW_IN_1);
      OUTPUT_LOW(WINDOW_IN_2);
   }
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************FRESH**AIR**//
//*************************************************************************************************************************************************//
//************************************************************************************************************************************TURN**RIGHT**//
   VOID Turn_Right_Fresh_Air(){
      OUTPUT_LOW(WINDOW_EN_1);
      OUTPUT_LOW(WINDOW_EN_2);
      OUTPUT_HIGH(WINDOW_IN_1);
      OUTPUT_LOW(WINDOW_IN_2);
      OUTPUT_LOW(FRESH_AIR_IN_1);
      OUTPUT_LOW(FRESH_AIR_IN_2);
   }
//*************************************************************************************************************************************TURN**LEFT**//
   VOID Turn_Left_Fresh_Air(){
      OUTPUT_LOW(FRESH_AIR_EN_1);
      OUTPUT_LOW(FRESH_AIR_EN_2);
      OUTPUT_HIGH(FRESH_AIR_IN_1);
      OUTPUT_LOW(FRESH_AIR_IN_2);
      OUTPUT_LOW(WINDOW_IN_1);
      OUTPUT_LOW(WINDOW_IN_2);
   }
//*******************************************************************************************************************************************STOP**//
   VOID Stop_Fresh_Air(){
      OUTPUT_HIGH(FRESH_AIR_EN_1);
      OUTPUT_HIGH(FRESH_AIR_EN_2);
      OUTPUT_LOW(FRESH_AIR_IN_1);
      OUTPUT_LOW(FRESH_AIR_IN_2);
   }
//*************************************************************************************************************************************************//
//***********************************************************************************************************************************DRIVER**VANA**//
//*************************************************************************************************************************************************//
//************************************************************************************************************************************TURN**RIGHT**//
   VOID Turn_Right_Valve_DRIVER(){
      OUTPUT_LOW(VALVE_DRIVER_EN);
      OUTPUT_HIGH(VALVE_DRIVER_IN_1);
      OUTPUT_LOW(VALVE_DRIVER_IN_2);
   }
//*************************************************************************************************************************************TURN**LEFT**//
   VOID Turn_Left_Valve_DRIVER(){
      OUTPUT_LOW(VALVE_DRIVER_EN);
      OUTPUT_LOW(VALVE_DRIVER_IN_1);
      OUTPUT_HIGH(VALVE_DRIVER_IN_2);
   }
//*******************************************************************************************************************************************STOP**//
   VOID Stop_Valve_DRIVER(){
      OUTPUT_HIGH(VALVE_DRIVER_EN);
      OUTPUT_LOW(VALVE_DRIVER_IN_1);
      OUTPUT_LOW(VALVE_DRIVER_IN_2);
   }
//*************************************************************************************************************************************************//
//*******************************************************************************************************************************PASSENGER**VALVE**//
//*************************************************************************************************************************************************//
//************************************************************************************************************************************TURN**RIGHT**//
   VOID Turn_Right_Valve_Passenger(){
      OUTPUT_LOW(VALVE_PASSENGER_EN);
      OUTPUT_HIGH(VALVE_PASSENGER_IN_1);
      OUTPUT_LOW(VALVE_PASSENGER_IN_2);
   }
//*************************************************************************************************************************************TURN**LEFT**//
   VOID Turn_Left_Valve_Passenger(){
      OUTPUT_LOW(VALVE_PASSENGER_EN);
      OUTPUT_LOW(VALVE_PASSENGER_IN_1);
      OUTPUT_HIGH(VALVE_PASSENGER_IN_2);
   }
//*******************************************************************************************************************************************STOP**//
   VOID Stop_Valve_Passenger(){
      OUTPUT_HIGH(VALVE_PASSENGER_EN);
      OUTPUT_LOW(VALVE_PASSENGER_IN_1);
      OUTPUT_LOW(VALVE_PASSENGER_IN_2);
   }
//*************************************************************************************************************************************************//
//***********************************************************TIME**KLAPE**ONCE**WINDOW*************************************************************//
//*************************************************************************************************************************************************//
VOID Time_Klape_Once_Window(){
   IF(state_time_klape_once_window){
      Turn_Right_Window();
      DELAY_MS(500);
      counter_button_controller_functions                      = 0;
      state_time_klape_once_turn_complete_window               = FALSE;
      WHILE(!state_time_klape_once_turn_complete_window){
         counter_button_controller_functions++;
         IF(counter_button_controller_functions > 10){
            counter_button_controller_functions                = 0;
            Button_Controller_Functions(); 
            Controller_Led_Functions();
         }
         Turn_Right_Window();
         DELAY_MS(30);
         Read_Current_Valve_Passenger();
         IF(value_current_valve_passenger > VALUE_SIDE_CURRENT_KLAPE_MOTOR){
            state_error_window                                 = FALSE;
            state_turn_complete_window                         = FALSE;
            state_controller_klape_error_window                = FALSE;
            state_controller_error_in_while_loop_window        = FALSE;
            state_time_klape_once_window                       = FALSE;
            state_time_klape_once_turn_complete_window         = TRUE;
            Stop_Window();
            DELAY_MS(100);
         }
      }
      Turn_Left_Window();
      DELAY_MS(500);
      time_window_starting                                     = get_ticks();
      counter_button_controller_functions                      = 0;
      state_time_klape_once_turn_complete_window               = FALSE;
      WHILE(!state_time_klape_once_turn_complete_window){
         Turn_Left_Window();
         DELAY_MS(1);
         counter_button_controller_functions++;
         IF(counter_button_controller_functions > 25){
            counter_button_controller_functions                = 0;
            Button_Controller_Functions(); 
            Controller_Led_Functions();
         }
         time_window_current                                   = get_ticks();
         Read_Current_Valve_Driver();
         IF(value_current_valve_driver > VALUE_SIDE_CURRENT_KLAPE_MOTOR){
            state_time_klape_once_turn_complete_window         = TRUE;
            Stop_Window();
            DELAY_MS(100);
         }
      }
      IF(!state_error_window){
         time_window_difference           = Ticks_Difference(time_window_starting, time_window_current);
         time_controller_window           = (time_window_difference - 400);
         time_error_window_difference     = (2 * time_window_difference);
         time_window_mid                  = ((time_window_difference / 2) - 800);
      }
   }
}
//*************************************************************************************************************************************************//
//*************************************************************TIME**KLAPE**ONCE**AIR**************************************************************//
//*************************************************************************************************************************************************//
VOID Time_Klape_Once_Fresh_Air(){
   IF(state_time_klape_once_fresh_air){
      Turn_Right_Fresh_Air();
      DELAY_MS(500);
      counter_button_controller_functions                            = 0;
      state_time_klape_once_turn_complete_fresh_air                  = FALSE;
      WHILE(!state_time_klape_once_turn_complete_fresh_air){
         counter_button_controller_functions++;
         IF(counter_button_controller_functions > 10){
            counter_button_controller_functions                      = 0;
            Button_Controller_Functions(); 
            Controller_Led_Functions();
         }
         Turn_Right_Fresh_Air();
         DELAY_MS(30);
         Read_Current_Valve_Driver();
         IF(value_current_valve_driver > VALUE_SIDE_CURRENT_KLAPE_MOTOR){
            state_error_fresh_air                                    = FALSE;
            state_turn_complete_fresh_air                            = FALSE;
            state_controller_klape_error_fresh_air                   = FALSE;
            state_controller_error_in_while_loop_fresh_air           = FALSE;
            state_time_klape_once_fresh_air                          = FALSE;
            state_time_klape_once_turn_complete_fresh_air            = TRUE;
            Stop_Fresh_Air();
            DELAY_MS(100);
         }
      }
      Turn_Left_Fresh_Air();
      DELAY_MS(500);
      time_fresh_air_starting                                        = get_ticks();
      counter_button_controller_functions                            = 0;
      state_time_klape_once_turn_complete_fresh_air                  = FALSE;
      WHILE(!state_time_klape_once_turn_complete_fresh_air){
         Turn_Left_Fresh_Air();
         DELAY_MS(1);
         counter_button_controller_functions++;
         IF(counter_button_controller_functions > 25){
            counter_button_controller_functions                      = 0;
            Button_Controller_Functions(); 
            Controller_Led_Functions();
         }
         time_fresh_air_current                                      = get_ticks();
         Read_Current_Valve_Passenger();
         IF(value_current_valve_passenger > VALUE_SIDE_CURRENT_KLAPE_MOTOR){
            state_time_klape_once_turn_complete_fresh_air            = TRUE;
            Stop_Fresh_Air();
            DELAY_MS(100);
         }
      }
      IF(!state_error_fresh_air){
         time_fresh_air_difference           = Ticks_Difference(time_fresh_air_starting, time_fresh_air_current);
         time_controller_fresh_air           = (time_fresh_air_difference - 400);
         time_error_fresh_air_difference     = (2 * time_fresh_air_difference);
      }
   }
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
         Read_Current_Valve_Driver();
         IF(value_current_valve_driver > VALUE_SIDE_CURRENT_KORMAS_VALVE){
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
         Read_Current_Valve_Driver();
         IF(value_current_valve_driver > VALUE_SIDE_CURRENT_KORMAS_VALVE){
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
         Read_Current_Valve_Passenger();
         IF(value_current_valve_passenger > VALUE_SIDE_CURRENT_KORMAS_VALVE){
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
            counter_button_controller_functions = 0;
            Button_Controller_Functions(); 
            Controller_Led_Functions();
         }
         time_valve_passenger_current                                   = get_ticks();
         Read_Current_Valve_Passenger();
         IF(value_current_valve_passenger > VALUE_SIDE_CURRENT_KORMAS_VALVE){
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
