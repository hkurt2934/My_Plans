//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
//****************************************************************HEADER**FILE*********************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
//**********************************************************CONTENTS**FOR**THIS**CODE**************************************************************//
//*************************************************************************************************************************************************//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                    01) HEADER_FILE------------------------------------------------0003                                      **//
//**                                    02) INCLUDE_DEVICE---------------------------------------------0077                                      **//
//**                                    03) ADC_BIT----------------------------------------------------0080                                      **//
//**                                    04) SETTING_FUSEs----------------------------------------------0082                                      **//
//**                                    05) SETTING_USEs-----------------------------------------------0088                                      **//
//**                                    06) PIN_DEFINEs------------------------------------------------0102                                      **//
//**                                    07) FUNCTIONs--------------------------------------------------0217                                      **//
//**                                    08) INTEGER_VARIABLEs------------------------------------------0284                                      **//
//**                                    09) BOOLEAN_VARIABLEs------------------------------------------0381                                      **//
//**                                    10) SETTING()--------------------------------------------------0422                                      **//
//**                                    11) Controller_Klape()-----------------------------------------0487                                      **//
//**                                    12) Scan_Klape_Time()------------------------------------------0545                                      **//
//**                                    13) Make_Default_Value()---------------------------------------0593                                      **//
//**                                    14) Read_Value_From_EEPROM()-----------------------------------0623                                      **//
//**                                    15) Work_According_To_EEPROM_Value()---------------------------0639                                      **//
//**                                    16) Controller_Functions()-------------------------------------0650                                      **//
//**                                    17) Controller_Functions_In_Controlller_While()----------------0795                                      **//
//**                                    18) Button_Controller_AC()-------------------------------------0724                                      **//
//**                                    19) Button_Controller_Max()------------------------------------0769                                      **//
//**                                    20) Button_Controller_Functions()------------------------------0810                                      **//
//**                                    21) Button_Controller_Klima_Fan()------------------------------0827                                      **//
//**                                    22) Button_Controller_On_Fan()---------------------------------0845                                      **//
//**                                    23) Button_Controller_Arka_Fan()-------------------------------0866                                      **//
//**                                    24) Button_Controller_Cam()------------------------------------0879                                      **//
//**                                    25) Button_Controller_Temiz_Hava()-----------------------------0938                                      **//
//**                                    26) Button_Controller_Vana_1()---------------------------------0960                                      **//
//**                                    27) Button_Controller_Increase_Decrease()----------------------0992                                      **//
//**                                    28) Controller_Klima_Fan()-------------------------------------1023                                      **//
//**                                    29) Controller_On_Fan()----------------------------------------1073                                      **//
//**                                    30) Controller_On_Fan_In_Controller_While()--------------------1175                                      **//
//**                                    31) Controller_Arka_Fan()--------------------------------------1205                                      **//
//**                                    32) Controller_Arka_Fan_In_Controller_While()------------------1265                                      **//
//**                                    33) Controller_Cam_Yuz()---------------------------------------1286                                      **//
//**                                    34) Controller_Cam_Yuz_In_Controller_While()-------------------1383                                      **//
//**                                    35) Controller_Temiz_Hava()------------------------------------1407                                      **//
//**                                    36) Controller_Temiz_Hava_In_Controller_While()----------------1453                                      **//
//**                                    37) Controller_Vana_1()----------------------------------------1467                                      **//
//**                                    38) Controller_Vana_1_In_Controller_While()--------------------1564                                      **//
//**                                    39) Controller_Klima()-----------------------------------------1591                                      **//
//**                                    40) Controller_And_Compare_Temp_And_Set_Temp()-----------------1651                                      **//
//**                                    41) Controller_Error_And_Temperature()-------------------------1673                                      **//
//**                                    42) Write_Error()----------------------------------------------1733                                      **//
//**                                    43) Write_Display()--------------------------------------------1791                                      **//
//**                                    44) Write_Led()------------------------------------------------1812                                      **//
//**                                    45) ONer()-----------------------------------------------------1833                                      **//
//**                                    46) OFFer()----------------------------------------------------1840                                      **//
//**                                    47) Ticks_Difference()-----------------------------------------1847                                      **//
//**                                    48) Change_8_Bits_Of_16_Bit_Data()-----------------------------1854                                      **//
//**                                    49) ORer_Two_Numbers()-----------------------------------------1863                                      **//
//**                                    50) Read_Current_Temiz_Hava_Cam()------------------------------1875                                      **//
//**                                    51) Read_Current_Vana()----------------------------------------1881                                      **//
//**                                    52) Turn_Right_Cam()-------------------------------------------1891                                      **//
//**                                    53) Turn_Left_Cam()--------------------------------------------1897                                      **//
//**                                    54) Stop_Cam()-------------------------------------------------1903                                      **//
//**                                    55) Turn_Right_Temiz_Hava()------------------------------------1910                                      **//
//**                                    56) Turn_Left_Temiz_Hava()-------------------------------------1916                                      **//
//**                                    57) Stop_Temiz_Hava()------------------------------------------1922                                      **//
//**                                    58) Turn_Right_Vana_1()----------------------------------------1929                                      **//
//**                                    59) Turn_Left_Vana_1()-----------------------------------------1935                                      **//
//**                                    60) Stop_Vana_1()----------------------------------------------1941                                      **//
//**                                    61) END--------------------------------------------------------1948                                      **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//*************************************************************************END*********************************************************************//
//*************************************************************************************************************************************************//
//******************************************************************INCLUDE**DEVICE****************************************************************//
//*************************************************************************************************************************************************//
#INCLUDE <16F1947.h>
//**********************************************************************ADC**BIT*******************************************************************//
#DEVICE ADC = 10
//*******************************************************************SETTING**FUSEs****************************************************************//
#FUSES NOWDT
#FUSES NOLVP
#FUSES NOMCLR
#FUSES NOBROWNOUT
//*************************************************************************************************************************************************//
//*******************************************************************SETTING**USEs*****************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************USE**DELAY**//
#USE DELAY(INTERNAL = 4MHZ)
//*********************************************************************************************************************************USE**FAST**I-O**//
#USE FAST_IO(A)
#USE FAST_IO(B)
#USE FAST_IO(C)
#USE FAST_IO(D)
#USE FAST_IO(E)
#USE FAST_IO(G)
//*************************************************************************************************************************************USE**TIMER**//
#USE TIMER(TIMER = 1, TICK = 1 MS, BITS = 32, NOISR)
//*************************************************************************************************************************************************//
//******************************************************************PIN***DEFINES******************************************************************//
//*************************************************************************************************************************************************//
//**********************************************************************************************************************************DSIPLAY**PINs**//
#DEFINE DATA_DISPLAY                                     PIN_D5
#DEFINE SH_CP_DISPLAY                                    PIN_D6
#DEFINE ST_CP_DISPLAY                                    PIN_D7
//**************************************************************************************************************************************LED**PINs**//
#DEFINE DATA_LED                                         PIN_D2
#DEFINE SH_CP_LED                                        PIN_D0
#DEFINE ST_CP_LED                                        PIN_D1                                         
//*******************************************************************************************************************************DISPLAY**NUMBERs**//
#DEFINE N_0                                              0x3F
#DEFINE N_1                                              0x06
#DEFINE N_2                                              0x5B
#DEFINE N_3                                              0x4F
#DEFINE N_4                                              0x66
#DEFINE N_5                                              0x6D
#DEFINE N_6                                              0x7D
#DEFINE N_7                                              0x07
#DEFINE N_8                                              0x7F
#DEFINE N_9                                              0x6F
#DEFINE N_E                                              0x79
#DEFINE N_r                                              0x50
#DEFINE N_EMPTY                                          0x00 
//******************************************************************************************************************************BILDIRIM**LEDLERI**//
#DEFINE KLIMA_FAN_DEFAULT                                0xFFFC
#DEFINE KLIMA_FAN_1_ON                                   0x0002
#DEFINE KLIMA_FAN_1_OFF                                  0xFFFD
#DEFINE KLIMA_FAN_2_ON                                   0x0001
#DEFINE KLIMA_FAN_2_OFF                                  0xFFFE
#DEFINE KLIMA_FAN_3_ON                                   PIN_D4
#DEFINE ON_FAN_DEFAULT                                   0xFF1F
#DEFINE ON_FAN_1_ON                                      0x0080
#DEFINE ON_FAN_1_OFF                                     0xFF7F
#DEFINE ON_FAN_2_ON                                      0x0040
#DEFINE ON_FAN_2_OFF                                     0xFFBF
#DEFINE ON_FAN_3_ON                                      0x0020
#DEFINE ON_FAN_3_OFF                                     0xFFDF
#DEFINE ARKA_FAN_DEFAULT                                 0xF9FF
#DEFINE ARKA_FAN_1_ON                                    0x0200
#DEFINE ARKA_FAN_1_OFF                                   0xFDFF
#DEFINE ARKA_FAN_2_ON                                    0x0400
#DEFINE ARKA_FAN_2_OFF                                   0xFBFF
#DEFINE CAM_DEFAULT                                      0xBFF7
#DEFINE CAM_ON                                           0x0008
#DEFINE CAM_OFF                                          0xFFF7
#DEFINE YUZ_LED                                          PIN_F0
#DEFINE BERABER_ON                                       0x4000
#DEFINE BERABER_OFF                                      0xBFFF
#DEFINE MAX_DEFAULT                                      0xFFEF
#DEFINE MAX_ON                                           0x0010
#DEFINE MAX_OFF                                          0xFFEF
#DEFINE TEMIZ_HAVA_DEFAULT                               0xDFFF
#DEFINE TEMIZ_HAVA_ON                                    0x2000
#DEFINE TEMIZ_HAVA_OFF                                   0xDFFF
#DEFINE VANA_1_DEFAULT                                   0x67FF
#DEFINE VANA_1_1_ON                                      0x0800
#DEFINE VANA_1_1_OFF                                     0xF7FF
#DEFINE VANA_1_2_ON                                      0x1000
#DEFINE VANA_1_2_OFF                                     0xEFFF
#DEFINE VANA_1_3_ON                                      0x8000
#DEFINE VANA_1_3_OFF                                     0x7FFF
#DEFINE AC_DEFAULT                                       0xFEFF
#DEFINE AC_ON                                            0x0100
//**************************************************************************************************************************************ADC**PINs**//
#DEFINE ADC_Sensor_2                                     sAN10
#DEFINE ADC_CURRENT_L293DD                               sAN15
//***********************************************************************************************************************************ADC**CHANNEL**//
#DEFINE CHANNEL_Sensor_2                                 10
#DEFINE CHANNEL_CURRENT_L293DD                           15
//****************************************************************************************************************************************BUTTONs**//
#DEFINE BUTTON_AC                                        PIN_E3
#DEFINE BUTTON_KLIMA_FAN                                 PIN_D3
#DEFINE BUTTON_ON_FAN                                    PIN_E7
#DEFINE BUTTON_ARKA_FAN                                  PIN_G0
#DEFINE BUTTON_MAX                                       PIN_E6
#DEFINE BUTTON_CAM                                       PIN_E5
#DEFINE BUTTON_YUZ                                       PIN_E4
#DEFINE BUTTON_BERABER                                   PIN_E1
#DEFINE BUTTON_TEMIZ_HAVA                                PIN_E2
#DEFINE BUTTON_VANA_1                                    PIN_E0
#DEFINE BUTTON_INCREASE                                  PIN_B0
#DEFINE BUTTON_DECREASE                                  PIN_A4
//**************************************************************************************************************************************CAM**PINs**//
#DEFINE CAM_EN                                           PIN_B4
#DEFINE CAM_IN_1                                         PIN_B5
#DEFINE CAM_IN_2                                         PIN_A6
//******************************************************************************************************************************TEMIZ**HAVA**PINs**//
#DEFINE TEMIZ_HAVA_EN_1                                  PIN_B4
#DEFINE TEMIZ_HAVA_EN_2                                  PIN_C5
#DEFINE TEMIZ_HAVA_IN_1_1                                PIN_B5
#DEFINE TEMIZ_HAVA_IN_1_2                                PIN_A6
#DEFINE TEMIZ_HAVA_IN_2_1                                PIN_C4
#DEFINE TEMIZ_HAVA_IN_2_2                                PIN_C3
//**********************************************************************************************************************************VANA**1**PINs**//
#DEFINE VANA_1_EN                                        PIN_C5
#DEFINE VANA_1_IN_1                                      PIN_C4
#DEFINE VANA_1_IN_2                                      PIN_C3
//********************************************************************************************************************************************PWM**//
#DEFINE PWM_FAN_DRIVER                                   PIN_G3
#DEFINE PWM_FAN_PASSENGER                                PIN_G4
#DEFINE PWM_FAN_DRIVER_STEP_0                            0
#DEFINE PWM_FAN_DRIVER_STEP_1                            570
#DEFINE PWM_FAN_DRIVER_STEP_2                            800
#DEFINE PWM_FAN_DRIVER_STEP_3                            1023
#DEFINE PWM_FAN_PASSENGER_STEP_0                         0
#DEFINE PWM_FAN_PASSENGER_STEP_1                         680
#DEFINE PWM_FAN_PASSENGER_STEP_2                         1023
//*******************************************************************************************************************************CURRENT**CONTROL**//
#DEFINE CURRENT_L293DD                                   PIN_G1
//*****************************************************************************************************************************************SENSOR**//
#DEFINE CURRENT_SENSOR_2                                 PIN_F5
//******************************************************************************************************************************************KLIMA**//
#DEFINE KLIMA_FAN_1                                      PIN_B1
#DEFINE KLIMA_FAN_2                                      PIN_F2
#DEFINE KLIMA_FAN_3                                      PIN_F7
//************************************************************************************************************************************ERROR**PINs**//
#DEFINE ERROR                                            PIN_B3
//****************************************************************************************************************************KOMPRESOR-KONDANSER**//
#DEFINE KOMPRESSOR                                       PIN_A7
#DEFINE AIR_CONDITIONING_SIGNAL                          PIN_F3
#DEFINE KONDANSER                                        PIN_G2
//*************************************************************************************************************************************************//
//******************************************************************FUNCTIONs**********************************************************************//
//*************************************************************************************************************************************************//
//********************************************************************************************************************************MAIN**FUNCTIONs**//
VOID Setting();
VOID Controller_Klape();
VOID Scan_Klape_Time();
VOID Controller_Klape_Error();
VOID Make_Default_Value();
VOID Read_Value_From_EEPROM();
VOID Work_According_To_EEPROM_Value();
//******************************************************************************************************************************BUTTON**FUNCTIONs**//
VOID Button_Controller_Klima_Fan();
VOID Button_Controller_On_Fan();
VOID Button_Controller_Arka_Fan();
VOID Button_Controller_Cam();
VOID Button_Controller_Temiz_Hava();
VOID Button_Controller_Vana_1();
VOID Button_Controller_Max();
VOID Button_Controller_AC();
VOID Button_Controller_Increase_Decrease();
VOID Button_Controller_Functions();
//**************************************************************************************************************************CONTROLLER**FUNCTIONs**//
VOID Controller_Klape();
VOID Controller_Klape_Error();
VOID Controller_Klima_Fan();
VOID Controller_On_Fan();
VOID Controller_Arka_Fan();
VOID Controller_Cam_Yuz();
VOID Controller_Temiz_Hava();
VOID Controller_Vana_1();
VOID Controller_Auto_Mode();
VOID Controller_Auto_Mode_In_Sensor_Error();
VOID Controller_Error_And_Temperature();
VOID Controller_Temperature_Starting();
VOID Controller_Functions();
VOID Controller_Led_Klima_Fan();
VOID Controller_Led_On_Fan();
VOID Controller_Led_Arka_Fan();
VOID Controller_Led_Cam_Yuz();
VOID Controller_Led_Temiz_Hava();
VOID Controller_Led_Vana_1();
VOID Controller_Led_Functions();
VOID Controller_Klima();
VOID Controller_Air_Conditioning_Signal();
VOID Controller_And_Compare_Temp_And_Set_Temp();
VOID Show_Temperature_Starting();
//***************************************************************************************************************************READ**ADC**FUNCTIONs**//
VOID Read_Current_L293DD();
//*********************************************************************************************************************MOTOR**MOVEMENT**FUNCTIONs**//
VOID Turn_Right_Cam();
VOID Turn_Left_Cam();
VOID Stop_Cam();
VOID Turn_Right_Temiz_Hava();
VOID Turn_Left_Temiz_Hava();
VOID Stop_Temiz_Hava();
VOID Turn_Right_Vana_1();
VOID Turn_Left_Vana_1();
VOID Stop_Vana_1();
//*************************************************************************************************************************DISPLAY-LED**FUNCTIONs**//
VOID ONer(INT16);
VOID OFFer(INT16);
VOID Write_Led(INT16);
VOID Write_Display(INT16);
VOID Write_Error();
VOID Write_Display_Error();
INT16 ORer_Two_Number(INT8,INT8);
INT16 Change_8_Bits_Of_16_Bit_Data(INT16);
//********************************************************************************************************************************TIME**FUNCTIONs**//
INT32 Ticks_Difference(INT32,INT32);
//*************************************************************************************************************************************************//
//*************************************************************INTEGER**VARIABLEs******************************************************************//
//*************************************************************************************************************************************************//
//************************************************************************************************************************************LED**VALUEs**//
INT8 numbers[]           = {N_0,N_1,N_2,N_3,N_4,N_5,N_6,N_7,N_8,N_9,N_E,N_r,N_EMPTY};
int8 digit_1                                             = 0;
INT8 digit_10                                            = 0;
INT8 counter_write_display                               = 0;
INT8 counter_write_led                                   = 0;
INT16 leds_register                                      = 0x0000;
INT16 display_register                                   = 0x0000;
INT16 orrer_digit_1                                      = 0x0000;
INT16 orrer_digit_10                                     = 0x0000;
INT16 orrer_result                                       = 0x0000;
INT16 _16_bit_data_temporary                             = 0x0000;
//***************************************************************************************************************************************COUNTERs**//
SIGNED INT8 counter_klima                                = 0;
SIGNED INT8 counter_ac                                   = 0;
SIGNED INT8 counter_max                                  = 0;
SIGNED INT8 counter_klima_old                            = 0;
SIGNED INT8 counter_klima_fan                            = 0;
SIGNED INT8 counter_klima_fan_old                        = 0;
SIGNED INT8 counter_klima_fan_before                     = 0;
SIGNED INT8 counter_on_fan                               = 0;
SIGNED INT8 counter_on_fan_old                           = 0;
SIGNED INT8 counter_on_fan_before                        = 0;
SIGNED INT8 counter_arka_fan                             = 0;
SIGNED INT8 counter_arka_fan_old                         = 0;
SIGNED INT8 counter_cam                                  = 0;  
SIGNED INT8 counter_status_cam                           = 0;
SIGNED INT8 counter_cam_old                              = 0;
SIGNED INT8 counter_cam_before                           = 0;
SIGNED INT8 counter_temiz_hava                           = 1;
SIGNED INT8 counter_temiz_hava_old                       = 1;
SIGNED INT8 counter_temiz_hava_before                    = 1;
SIGNED INT8 counter_vana_1                               = 0; 
SIGNED INT8 counter_status_vana_1                        = 0;
SIGNED INT8 counter_vana_1_old                           = 0;
SIGNED INT8 counter_vana_1_before                        = 0;
SIGNED INT32 counter_button_increase_decrease            = 0;
//***************************************************************************************************************************CONTROLLER**COUNTERs**//
INT16 counter_controller_vana_1                          = 0;
INT16 counter_controller_error_input                     = 0;
INT16 counter_controller_sensor                          = 0;
INT16 counter_controller_cam                             = 0;
INT16 counter_controller_temiz_hava                      = 0;
//*************************************************************************************************************************EEPROM**ADDRESS**DATAs**//
INT8 address_cam                                         = 1;
INT8 address_temiz_hava                                  = 2;
INT8 address_vana_1                                      = 3;
INT8 address_set_temp                                    = 4;
//*************************************************************************************************************************TEMPERATURE**VARIABLEs**//
SIGNED INT16 temp                                        = 0;
SIGNED INT16 set_temp                                    = 24;
SIGNED INT16 temp_1                                      = -12;
SIGNED INT16 temp_2                                      = 0;
//*********************************************************************************************************************************ADC**VARIABLEs**//
INT16 value_current_l293dd                               = 0;
INT16 value_current_temporary                            = 0;
INT32 register_adc                                       = 0x00000000;
//********************************************************************************************************************************TIME**VARIABLEs**//
UNSIGNED INT32 time_starting_klima                       = 0x00000000;
UNSIGNED INT32 time_current_klima                        = 0x00000000;
UNSIGNED INT32 time_difference_klima                     = 0x00000000;
UNSIGNED INT32 time_difference                           = 0x00000000;
UNSIGNED INT32 time_starting_cam                         = 0x00000000;
UNSIGNED INT32 time_current_cam                          = 0x00000000;
UNSIGNED INT32 time_difference_cam                       = 0x00000000;
UNSIGNED INT32 time_mid_cam                              = 0x00000000;
UNSIGNED INT32 time_starting_temiz_hava                  = 0x00000000;
UNSIGNED INT32 time_current_temiz_hava                   = 0x00000000;
UNSIGNED INT32 time_difference_temiz_hava                = 0x00000000;
UNSIGNED INT32 time_starting_vana_1                      = 0x00000000;
UNSIGNED INT32 time_current_vana_1                       = 0x00000000;
UNSIGNED INT32 time_difference_vana_1                    = 0x00000000;
UNSIGNED INT32 time_mid_vana_1                           = 0x00000000;
UNSIGNED INT32 time_starting_ac                          = 0x00000000;
UNSIGNED INT32 time_current_ac                           = 0x00000000;
UNSIGNED INT32 time_difference_ac                        = 0x00000000;
UNSIGNED INT32 time_controller_cam                       = 0x00000000;
UNSIGNED INT32 time_controller_temiz_hava                = 0x00000000;
UNSIGNED INT32 time_controller_vana_1                    = 0x00000000;
UNSIGNED INT32 time_controller_error_starting            = 0x00000000;
UNSIGNED INT32 time_controller_error_current             = 0x00000000;
UNSIGNED INT32 time_controller_error_difference          = 0x00000000;
//*********************************************************************************************************************************PWM**VARIABLEs**//
INT16 value_pwm_fan_driver                               = 0;
INT16 value_pwm_fan_passenger                            = 0;
//************************************************************************************************************KLAPE**CONTROL**FUNCTION**VARIABLEs**//
INT16 counter_klape_cam                                  = 0;
INT16 counter_klape_temiz_hava                           = 0;
INT16 counter_klape_vana_1                               = 0;
//*******************************************************************************************************************CONTROLLER**ERROR**VARIABLEs**//
INT8 counter_error_constant_temporary                    = 0;
INT8 counter_error_temporary                             = 0;
INT16 counter_controller_error                           = 0;
INT16 counter_write_display_error                        = 0;
INT16 counter_error_constant                             = 0;
INT16 counter_write_error                                = 0;
INT16 counter_button_controller_functions                = 0;
//*************************************************************************************************************************************************//
//*************************************************************BOOLEAN**VARIABLEs******************************************************************//
//*************************************************************************************************************************************************//
//*******************************************************************************************************************CONTROLLER**KLAPE**VARIABLEs**//
BOOLEAN state_error_cam                                  = FALSE;
BOOLEAN state_error_temiz_hava                           = FALSE;
BOOLEAN state_error_vana_1                               = FALSE;
BOOLEAN state_controller_klape_error_cam                 = FALSE;
BOOLEAN state_controller_klape_error_temiz_hava          = FALSE;
BOOLEAN state_controller_klape_error_vana_1              = FALSE;
//*******************************************************************************************************************BUTON**CONTROLLER**VARIABLEs**//
BOOLEAN state_time_is_up_ac                              = FALSE;
BOOLEAN state_button_ac                                  = FALSE;
BOOLEAN state_button_max                                 = FALSE;
BOOLEAN state_button_max_counter_before                  = TRUE;
BOOLEAN state_button_klima_fan                           = FALSE;
BOOLEAN state_button_on_fan                              = FALSE;
BOOLEAN state_button_arka_fan                            = FALSE;
BOOLEAN state_button_cam                                 = FALSE;
BOOLEAN state_button_yuz                                 = FALSE;
BOOLEAN state_button_beraber                             = FALSE;
BOOLEAN state_button_temiz_hava                          = FALSE;
BOOLEAN state_button_vana_1                              = FALSE;
BOOLEAN state_button_increase                            = FALSE;
BOOLEAN state_button_decrease                            = FALSE;
//*******************************************************************************************************************ERROR**CONTROLLER**VARIABLEs**//
BOOLEAN state_error_sensor_1                             = FALSE;
BOOLEAN state_error_yuksek_basinc                        = FALSE;
BOOLEAN state_write_klima_error                          = FALSE;
//************************************************************************************************************************TEMPERATURE**VARIABLEs**//
BOOLEAN state_display_set_temp                           = FALSE;
//***************************************************************************************************************CONTROLLER**FUNCTIONS**VARIABLEs**//
BOOLEAN state_turn_complete_cam                          = FALSE;
BOOLEAN state_turn_complete_temiz_hava                   = FALSE;
BOOLEAN state_turn_complete_vana_1                       = FALSE;
//*******************************************************************************************************************SCAN**KLAPE**TIME**VARIABLEs**//
BOOLEAN state_scan_klape_time                                  = TRUE;
BOOLEAN state_time_starting_klima_on                           = TRUE;
BOOLEAN state_time_starting_klima_off                          = TRUE;
BOOLEAN state_time_starting_klima_quickly_off                  = TRUE;
BOOLEAN state_controller_and_compare_temp_and_set_temp         = FALSE;
BOOLEAN state_prosses_complete_klima                           = FALSE;
BOOLEAN state_special_function_for_fan_driver_on_max_in_while  = FALSE;
//*************************************************************************************************************************************************//
BOOLEAN state_error_control_in_while                           = FALSE;
//*************************************************************************************************************************************************//
//*****************************************************************SETTING*************************************************************************//
//*************************************************************************************************************************************************//
   VOID Setting(){
//***************************************************************************************************************************CLOSING**ALL**OUTPUT**//
      OUTPUT_A(0x00);
      OUTPUT_B(0x00);
      OUTPUT_C(0x00);
      OUTPUT_D(0x00);
      OUTPUT_E(0x00);
      OUTPUT_F(0x00);
      OUTPUT_G(0x00);
//**************************************************************************************************************************OPENNING**ALL**OUTPUT**//
      DELAY_MS(50);
//***************************************************************************************************************************SETTING**ALL**OUTPUT**//
      SET_TRIS_A(0x10);
      SET_TRIS_B(0x09);
      SET_TRIS_C(0x00);
      SET_TRIS_D(0x08);
      SET_TRIS_E(0xFF);
      SET_TRIS_F(0x20);
      SET_TRIS_G(0x03);
      OFFer(0x0000);
      Write_Display(0xFFFF);
//**************************************************************************************************************************OPENNING**ALL**OUTPUT**//
      DELAY_MS(1000);
//********************************************************************************************************************************SETUP**TIMER**2**//
      SETUP_TIMER_2(T2_DIV_BY_1, 255, 1);
//******************************************************************************************************************************SETUP**OSCILLATOR**//
      SETUP_OSCILLATOR(0x7A);
//*********************************************************************************************************************************SETTING**PWM_2**//
      OUTPUT_LOW(PWM_FAN_DRIVER);
      SETUP_CCP2(CCP_PWM);
      SETUP_CCP2(CCP_OFF);
      DELAY_US(50);
//*********************************************************************************************************************************SETTING**PWM_1**//
      OUTPUT_LOW(PWM_FAN_PASSENGER);
      SETUP_CCP1(CCP_PWM);
      SETUP_CCP1(CCP_OFF);
      DELAY_US(50);
//****************************************************************************************************************************SETTING**ADC**PORTs**//
      register_adc                  = register_adc | ADC_CURRENT_L293DD;
      register_adc                  = register_adc | ADC_SENSOR_2;
      register_adc                  = register_adc | VSS_VDD;
      SETUP_ADC_PORTS(register_adc);
      SETUP_ADC(RTCC_INTERNAL|ADC_CLOCK_DIV_8);
      DELAY_US(50);
//*************************************************************************************************************************MAKING**DEFAULT**VALUE**//
      Make_Default_Value();
//**********************************************************************************************************************READ**VALUE**FROM**EEPROM**//
      Read_Value_From_EEPROM();
      Controller_Led_Klima_Fan();
      Controller_Led_On_Fan();
      Controller_Led_Arka_Fan();
      Controller_Led_Cam_Yuz();
      Controller_Led_Temiz_Hava();
      Controller_Led_Vana_1();
//**************************************************************************************************************************OPENNING**ALL**OUTPUT**//
      DELAY_MS(2000);
//****************************************************************************************************************************USING**STANDART**IO**//
      #USE STANDARD_IO(A)
      #USE STANDARD_IO(B)
      #USE STANDARD_IO(C)
      #USE STANDARD_IO(D)
      #USE STANDARD_IO(E)
      #USE STANDARD_IO(F)
      #USE STANDARD_IO(G)
//*********************************************************************************************************************************TICKs**DEFAULT**//
      set_ticks(0);
   }
//*************************************************************************************************************************************************//
//******************************************************************KLAPE**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Klape(){
      Write_Display(0x4040);
//**********************************************************************************************************************************MAKE**DEFAULT**//
      state_error_cam                              = TRUE;
      state_controller_klape_error_cam             = TRUE;
      state_error_temiz_hava                       = TRUE;
      state_controller_klape_error_temiz_hava      = TRUE;
      state_error_vana_1                           = TRUE;
      state_controller_klape_error_vana_1          = TRUE;
//********************************************************************************************************************************************CAM**//
      Turn_Right_Cam();
      DELAY_MS(500);
      FOR(counter_klape_cam = 0; counter_klape_cam < 300; counter_klape_cam++){
         Turn_Right_Cam();
         DELAY_MS(30);
         Read_Current_L293DD();
         IF(value_current_l293dd > 50){
            Stop_Cam();
            state_error_cam                        = FALSE;
            state_controller_klape_error_cam       = FALSE;
            counter_klape_cam                      = 300;
         }
      }
      Stop_Cam();
      DELAY_MS(100);
//************************************************************************************************************************************TEMIZ**HAVA**//
     Turn_Right_Temiz_Hava();
     DELAY_MS(500);
     FOR(counter_klape_temiz_hava = 0; counter_klape_temiz_hava < 300; counter_klape_temiz_hava++){
         Turn_Right_Temiz_Hava();
         DELAY_MS(30);
         Read_Current_L293DD();
         IF(value_current_l293dd > 50){
            state_error_temiz_hava                    = FALSE;
            state_controller_klape_error_temiz_hava   = FALSE;
            counter_klape_temiz_hava                  = 300;
         }
     }
     Stop_Temiz_Hava();
     DELAY_MS(100);
//****************************************************************************************************************************************VANA**1**//
      Turn_Right_Vana_1();
      DELAY_MS(500);
      FOR(counter_klape_vana_1 = 0; counter_klape_vana_1 < 300; counter_klape_vana_1++){
         Turn_Right_Vana_1();
         DELAY_MS(30);
         Read_Current_L293DD();
         IF(value_current_l293dd > 50){
            state_error_vana_1                     = FALSE;
            state_controller_klape_error_vana_1    = FALSE;
            counter_klape_vana_1                   = 300;
         }
      }
      Stop_Vana_1();
      DELAY_MS(100);
   }
//*************************************************************************************************************************************************//
//********************************************************************SCANNING*********************************************************************//
//*************************************************************************************************************************************************//
   VOID Scan_Klape_Time(){
//********************************************************************************************************************************************CAM**//
      IF(!state_error_cam){
         state_scan_klape_time = TRUE;
         Turn_Left_Cam();
         DELAY_MS(500);
         time_starting_cam = get_ticks();
         WHILE(state_scan_klape_time){
            time_current_cam = get_ticks();
            Turn_Left_Cam();
            Read_Current_L293DD();
            IF(value_current_l293dd > 50){
               state_scan_klape_time = FALSE;
               Stop_Cam();
            }
         }
      }
      Stop_Cam();
      DELAY_MS(100);
//************************************************************************************************************************************TEMIZ**HAVA**//
      IF(!state_error_temiz_hava){
         state_scan_klape_time = TRUE;
         Turn_Left_Temiz_Hava();
         DELAY_MS(500);
         time_starting_temiz_hava = get_ticks();
         WHILE(state_scan_klape_time){
            time_current_temiz_hava = get_ticks();
            Turn_Left_Temiz_Hava();
            Read_Current_L293DD();
            IF(value_current_l293dd > 50){
               state_scan_klape_time = FALSE;
               Stop_Temiz_Hava();
            }
         }
      }
      Stop_Temiz_Hava();
      DELAY_MS(100);
//****************************************************************************************************************************************VANA**1**//
      IF(!state_error_vana_1){
         state_scan_klape_time = TRUE;
         Turn_Left_Vana_1();
         DELAY_MS(500);
         time_starting_vana_1 = get_ticks();
         WHILE(state_scan_klape_time){
            time_current_vana_1 = get_ticks();
            Turn_Left_Vana_1();
            Read_Current_L293DD();
            IF(value_current_l293dd > 50){
               state_scan_klape_time = FALSE;
               Stop_Vana_1();
            }
         }
      }
      Stop_Vana_1();
      DELAY_MS(100);
//*****************************************************************************************************************************CREATE**MID**VALUE**//
      IF(!state_error_cam){
         time_difference_cam  = Ticks_Difference(time_starting_cam, time_current_cam);
         time_controller_cam  = (abs(time_difference_cam - 400));
         time_mid_cam         = (abs((time_difference_cam / 2) - 800));
      }
      IF(!state_error_temiz_hava){
         time_difference_temiz_hava = Ticks_Difference(time_starting_temiz_hava, time_current_temiz_hava);
         time_controller_temiz_hava = (abs(time_difference_temiz_hava - 400));
      }
      IF(!state_error_vana_1){
         time_difference_vana_1  = Ticks_Difference(time_starting_vana_1, time_current_vana_1);
         time_controller_vana_1  = (abs(time_difference_vana_1 - 400));
         time_mid_vana_1         = (abs((time_difference_vana_1 / 2) - 400));
      }
   }
//*************************************************************************************************************************************************//
//*****************************************************MAKE**DEFAULT**VALUE**WHEN**STARTING********************************************************//
//*************************************************************************************************************************************************//
   VOID Make_Default_Value(){
      SETUP_CCP1(CCP_OFF);
      SETUP_CCP2(CCP_OFF);
      OFFer(0x0000);
      OUTPUT_LOW(VANA_1_1_ON);
      OUTPUT_LOW(VANA_1_2_ON);
      OUTPUT_LOW(KLIMA_FAN_3_ON);
      OUTPUT_LOW(KLIMA_FAN_1);
      OUTPUT_LOW(KLIMA_FAN_2);
      OUTPUT_LOW(KLIMA_FAN_3);
      OUTPUT_LOW(KOMPRESSOR);
      OUTPUT_LOW(AIR_CONDITIONING_SIGNAL);
      OUTPUT_LOW(KONDANSER);
      Stop_Cam();
      Stop_Temiz_Hava();
      Stop_Vana_1();
      counter_klima                                = 0;
      counter_ac                                   = 0;
      counter_max                                  = 0;
      counter_write_display_error                  = 0;
      counter_klima_fan                            = 0;
      counter_on_fan                               = 0;
      counter_arka_fan                             = 0;
      value_pwm_fan_driver                         = 0;
      value_pwm_fan_passenger                      = 0;
      counter_status_cam                           = 0;
      counter_status_vana_1                        = 0;
      state_turn_complete_cam                      = FALSE;
      state_turn_complete_temiz_hava               = FALSE;
      state_turn_complete_vana_1                   = FALSE;
      time_starting_ac                             = get_ticks();
   }
//*************************************************************************************************************************************************//
//*************************************************READ**VALUE**WHEN**BEFORE**SHUTDOWN**FROM**EEPROM***********************************************//
//*************************************************************************************************************************************************//
   VOID Read_Value_From_EEPROM(){
      IF(!state_error_cam){
         counter_cam                               = READ_EEPROM(address_cam);
         counter_status_cam                        = 0;
      }
      ELSE{
         counter_cam                               = 0;
         counter_status_cam                        = 0;
      }
      IF(!state_error_temiz_hava){
         counter_temiz_hava                        = READ_EEPROM(address_temiz_hava);
      }
      ELSE{
         counter_temiz_hava                        = 0;
      }
      IF(!state_error_vana_1){
         counter_vana_1                            = READ_EEPROM(address_vana_1);
         counter_status_vana_1                     = 0;
      }
      ELSE{
         counter_vana_1                            = 0;
         counter_status_vana_1                     = 0;
      }
      set_temp                                     = READ_EEPROM(address_set_temp);
   }
//*************************************************************************************************************************************************//
//**************************************************************SHOW**TEMPERATURE**STARTING********************************************************//
//*************************************************************************************************************************************************//
VOID Show_Temperature_Starting(){
   SET_ADC_CHANNEL(CHANNEL_SENSOR_2);
   DELAY_US(50);
   temp_1                                          = READ_ADC();
   IF(temp_1 < 50){
      state_error_sensor_1                         = TRUE;
      display_register                             = ORer_Two_Number(numbers[10],numbers[1]);
      Write_Display(display_register);
   }
   ELSE{
      state_error_sensor_1                         = FALSE;
      temp                                         = ((temp_1 - 290) / (11));
      temp_2                                       = temp_1;
      digit_10                                     = (temp / 10);
      digit_1                                      = (temp % 10);
      display_register                             = ORer_Two_Number(numbers[digit_10], numbers[digit_1]);
      Write_Display(display_register);
   }
}
//*************************************************************************************************************************************************//
//*****************************************************START**WORKING**ACCORDING**TO**EEPROM**VALUE************************************************//
//*************************************************************************************************************************************************//
   VOID Work_According_To_EEPROM_Value(){
      Controller_Klima_Fan();
      Controller_On_Fan();
      Controller_Arka_Fan();
      Controller_Cam_Yuz();
      Controller_Temiz_Hava();
      Controller_Vana_1();
      Controller_Led_Klima_Fan();
      Controller_Led_On_Fan();
      Controller_Led_Arka_Fan();
      Controller_Led_Cam_Yuz();
      Controller_Led_Temiz_Hava();
      Controller_Led_Vana_1();
      Controller_Klima();
      Controller_Air_Conditioning_Signal();
   }
//*************************************************************************************************************************************************//
//***************************************************************CONTROLLER**FUNCTIONS*************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Functions(){
      IF(!(counter_klima_fan == counter_klima_fan_old)){
         Controller_Klima_Fan();
      }
      IF(!(counter_on_fan == counter_on_fan_old)){
         Controller_On_Fan();
      }
      IF(!(counter_arka_fan == counter_arka_fan_old)){
         Controller_Arka_Fan();
      }
      IF(!state_error_cam){
         IF(!(counter_cam == counter_cam_old)){
            Controller_Cam_Yuz();
         }
      }
      IF(!state_error_temiz_hava){
         IF(!(counter_temiz_hava == counter_temiz_hava_old)){
            Controller_Temiz_Hava();
         }
      }
      IF(!state_error_vana_1){
         IF(!(counter_vana_1 == counter_vana_1_old)){
            Controller_Vana_1();
         }
      }
      IF((counter_klima == counter_klima_old)){
         state_prosses_complete_klima              = FALSE;
      }
      IF(!state_prosses_complete_klima){
         Controller_Klima();
      }
      Controller_Air_Conditioning_Signal();
   }
//*************************************************************************************************************************************************//
//*****************************************************CONTROLLER**FUNCTIONS**IN**CONTROLLER**WHILE************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Led_Functions(){
//******************************************************READ**AND**CONTROL**KLAPEs**EVERY**TIME****************************************************//
      Controller_Error_And_Temperature();
      Controller_Led_Klima_Fan();
      Controller_Led_On_Fan();
      Controller_Led_Arka_Fan();
      Controller_Led_Cam_Yuz();
      Controller_Led_Temiz_Hava();
      Controller_Led_Vana_1();
   }     
//*************************************************************************************************************************************************//
//***************************************************SPECIAL**FUNCTION**FOR**FAN**DRIVER**ON**MAX**IN**WHILE***************************************//
//*************************************************************************************************************************************************//
   VOID Special_Function_For_Fan_Driver_On_Max_In_While(){
      IF((state_special_function_for_fan_driver_on_max_in_while) && ((counter_max % 2) == 0)){
         state_special_function_for_fan_driver_on_max_in_while = FALSE;
         Controller_On_Fan();
      }
   }
//*************************************************************************************************************************************************//
//***********************************************************BUTTON**CONTROLLER**FUNCTIONs*********************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Functions(){
//********************************************************************************************************************WHEN**PUSH**THE**AC**BUTTON**//
         Button_Controller_AC();
//*******************************************************************************************************************WHEN**PUSH**THE**MAX**BUTTON**//
         Button_Controller_Max();
//************************************************************************************************************WHEN**PUSH**THE**KLIMA**FAN**BUTTON**//
         Button_Controller_Klima_Fan();
//***************************************************************************************************************WHEN**PUSH**THE**ON**FAN**BUTTON**//
         Button_Controller_On_Fan();
//*************************************************************************************************************WHEN**PUSH**THE**ARKA**FAN**BUTTON**//
         Button_Controller_Arka_Fan();
//***********************************************************************************************************WHEN**PUSH**THE**TEMIZ**HAVA**BUTTON**//
         Button_Controller_Cam();
//***********************************************************************************************************WHEN**PUSH**THE**TEMIZ**HAVA**BUTTON**//
         Button_Controller_Temiz_Hava();
//****************************************************************************************************************WHEN**PUSH**THE**VANA_1**BUTTON**//
         Button_Controller_Vana_1();
   } 
//*************************************************************************************************************************************************//
//***************************************************************CONTROL**BUTTON**AC***************************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_AC(){
      IF(!state_time_is_up_ac){
         time_current_ac = get_ticks();
         time_difference_ac = Ticks_Difference(time_starting_ac, time_current_ac);
         IF(time_difference_ac > 12000){
            state_time_is_up_ac = TRUE;
         }
      }
      IF(state_time_is_up_ac){
         IF((!INPUT(BUTTON_AC)) && (state_button_ac)){
            DELAY_MS(250);
            state_button_ac                        = FALSE;
            counter_ac++;
//*************************************************************************************************************************COUNTER**AUTO**MODE**0**//
            IF((counter_ac % 2) == 0){
               OFFer(AC_DEFAULT);
               counter_ac                          = 0;
//************************************************************************************************************COOLER**NOT**WORK**IN**MANUEL**MODE**//
//********************************************************************************************************SO**KOMPRESSOR**AND**KLIMA_SINYALI**OFF**//
               counter_klima                       = 0;
               state_write_klima_error             = FALSE;
               counter_klima_fan                   = 0;
            }
//*************************************************************************************************************************COUNTER**AUTO**MODE**1**//
            IF((counter_ac % 2) == 1){
               ONer(AC_ON);
               counter_vana_1 = 0;
               counter_klima_fan = 3;
            }
//********************************************************************************************************************************COUNTER**MAX**1**//
            IF((counter_max % 2) == 1){
               OFFer(MAX_DEFAULT);
               counter_max                         = 0;
               counter_on_fan                      = counter_on_fan_before;
               counter_cam                         = counter_cam_before;
               counter_temiz_hava                  = counter_temiz_hava_before;
               counter_vana_1                      = counter_vana_1_before;
            }
         }
      }
      IF(INPUT(BUTTON_AC)){
         state_button_ac                        = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//***************************************************************CONTROL**BUTTON**MAX**************************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Max(){
         IF((!INPUT(BUTTON_MAX)) && (state_button_max)){
            DELAY_MS(250);
            state_button_max                       = FALSE;
            counter_max++;
//********************************************************************************************************************************COUNTER**MAX**0**//
            IF((counter_max % 2) == 0){
               OFFer(MAX_DEFAULT);
               counter_max                         = 0;
               counter_on_fan                      = counter_on_fan_before;
               counter_cam                         = counter_cam_before;
               counter_temiz_hava                  = counter_temiz_hava_before;
               counter_vana_1                      = counter_vana_1_before;
               state_button_max_counter_before     = TRUE;
            }
//********************************************************************************************************************************COUNTER**MAX**1**//
            IF((counter_max % 2) == 1){
               ONer(MAX_ON);
               OFFer(AC_DEFAULT);
               state_special_function_for_fan_driver_on_max_in_while = TRUE;
               counter_klima_fan_before            = counter_klima_fan;
               counter_on_fan_before               = counter_on_fan;
               counter_cam_before                  = counter_cam;
               counter_temiz_hava_before           = counter_temiz_hava;
               counter_vana_1_before               = counter_vana_1;
               counter_ac                          = 0;
               counter_klima_fan                   = 0;
               counter_on_fan                      = 3;
               counter_cam                         = 0;
               counter_temiz_hava                  = 0;
               counter_vana_1                      = 2;
               Controller_Klima();
            }
         }
         IF(INPUT(BUTTON_MAX)){
            state_button_max                       = TRUE;
         }
   }
//*************************************************************************************************************************************************//
//***********************************************************CONTROL**BUTTON**KLIMA**FAN***********************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Klima_Fan(){
      IF((!INPUT(BUTTON_KLIMA_FAN)) && (state_button_klima_fan)){
         DELAY_MS(250);
         state_button_klima_fan = FALSE;
            counter_klima_fan++;
//*************************************************************************************************************************COUNTER**AUTO**MODE**1**//
         IF((counter_ac % 2) == 1){
            IF((counter_klima_fan % 4) == 0){
               counter_klima_fan = 1;
            }
         }
      }
      IF(INPUT(BUTTON_KLIMA_FAN)){
         state_button_klima_fan                    = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//*************************************************************CONTROL**BUTTON**ON**FAN************************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_On_Fan(){
      IF((!INPUT(BUTTON_ON_FAN)) && (state_button_on_fan)){
         DELAY_MS(250);
         state_button_on_fan                       = FALSE;
//********************************************************************************************************************************COUNTER**MAX**1**//
         IF((counter_max % 2) == 1){
            OFFer(MAX_DEFAULT);
            counter_max                         = 0;
            counter_on_fan                      = counter_on_fan_before;
            counter_cam                         = counter_cam_before;
            counter_temiz_hava                  = counter_temiz_hava_before;
            counter_vana_1                      = counter_vana_1_before;
         }
         counter_on_fan++;
      }
      IF(INPUT(BUTTON_ON_FAN)){
         state_button_on_fan                       = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//************************************************************CONTROL**BUTTON**ARKA**FAN***********************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Arka_Fan(){
      IF((!INPUT(BUTTON_ARKA_FAN)) && (state_button_arka_fan)){
         DELAY_MS(250);
         state_button_arka_fan = FALSE;
//*************************************************************************************************************************COUNTER**AUTO**MODE**0**//
         counter_arka_fan++;
      }
      IF(INPUT(BUTTON_ARKA_FAN)){
         state_button_arka_fan                     = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//*********************************************************CONTROL**BUTTON**CAM**YUZ**BERABER******************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Cam(){
//************************************************************************************************************************************BUTTON**CAM**//
      IF(!INPUT(BUTTON_CAM) && (state_button_cam)){
         DELAY_MS(250);
         state_button_cam                       = FALSE;
//********************************************************************************************************************************COUNTER**MAX**1**//
         IF((counter_max % 2) == 1){
            OFFer(MAX_DEFAULT);
            counter_max                         = 0;
            counter_on_fan                      = counter_on_fan_before;
            counter_cam                         = counter_cam_before;
            counter_temiz_hava                  = counter_temiz_hava_before;
            counter_vana_1                      = counter_vana_1_before;
         }
         counter_cam                            = 0;
         write_eeprom(address_cam, counter_cam);
      }
      IF(INPUT(BUTTON_CAM)){
         state_button_cam                       = TRUE;
      }
//************************************************************************************************************************************BUTTON**YUZ**//
      IF(!INPUT(BUTTON_YUZ) && (state_button_yuz)){
         DELAY_MS(250);
         state_button_yuz                       = FALSE;
//********************************************************************************************************************************COUNTER**MAX**1**//
         IF((counter_max % 2) == 1){
            OFFer(MAX_DEFAULT);
            counter_max                         = 0;
            counter_on_fan                      = counter_on_fan_before;
            counter_cam                         = counter_cam_before;
            counter_temiz_hava                  = counter_temiz_hava_before;
            counter_vana_1                      = counter_vana_1_before;
         }
         counter_cam                            = 1;
         write_eeprom(address_cam, counter_cam);
      }
      IF(INPUT(BUTTON_YUZ)){
         state_button_yuz                       = TRUE;
      }
//********************************************************************************************************************************BUTTON**BERABER**//
      IF(!INPUT(BUTTON_BERABER) && (state_button_beraber)){
         DELAY_MS(250);
         state_button_beraber                   = FALSE;
//********************************************************************************************************************************COUNTER**MAX**1**//
         IF((counter_max % 2) == 1){
            OFFer(MAX_DEFAULT);
            counter_max                         = 0;
            counter_on_fan                      = counter_on_fan_before;
            counter_cam                         = counter_cam_before;
            counter_temiz_hava                  = counter_temiz_hava_before;
            counter_vana_1                      = counter_vana_1_before;
         }
         counter_cam                            = 2;
         write_eeprom(address_cam, counter_cam);
      }
      IF(INPUT(BUTTON_BERABER)){
         state_button_beraber                   = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//***********************************************************CONTROL**BUTTON**TEMIZ**HAVA**********************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Temiz_Hava(){
      IF((!INPUT(BUTTON_TEMIZ_HAVA)) && (state_button_temiz_hava)){
         DELAY_MS(250);
         state_button_temiz_hava                   = FALSE;
//********************************************************************************************************************************COUNTER**MAX**1**//
            IF((counter_max % 2) == 1){
               OFFer(MAX_DEFAULT);
               counter_max                         = 0;
               counter_on_fan                      = counter_on_fan_before;
               counter_cam                         = counter_cam_before;
               counter_temiz_hava                  = counter_temiz_hava_before;
               counter_vana_1                      = counter_vana_1_before;
            }
         counter_temiz_hava++;
         write_eeprom(address_temiz_hava, counter_temiz_hava);
      }
      IF(INPUT(BUTTON_TEMIZ_HAVA)){
         state_button_temiz_hava                   = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//**************************************************************CONTROL**BUTTON**VANA_1************************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Vana_1(){
      IF((!INPUT(BUTTON_VANA_1)) && (state_button_vana_1)){
         DELAY_MS(250);
         state_button_vana_1                    = FALSE;
//*************************************************************************************************************************COUNTER**AUTO**MODE**0**//
         IF((counter_ac % 2) == 0){
//********************************************************************************************************************************COUNTER**MAX**1**//
            IF((counter_max % 2) == 1){
               OFFer(MAX_DEFAULT);
               counter_max                      = 0;
               counter_on_fan                   = counter_on_fan_before;
               counter_cam                      = counter_cam_before;
               counter_temiz_hava               = counter_temiz_hava_before;
               counter_vana_1                   = counter_vana_1_before;
            }
            counter_vana_1++;
         }
//*************************************************************************************************************************COUNTER**AUTO**MODE**1**//
         IF((counter_ac % 2) == 1){
            counter_vana_1 = 0;
         }
         write_eeprom(address_vana_1, counter_vana_1);
      }
      IF(INPUT(BUTTON_VANA_1)){
         state_button_vana_1                    = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//************************************************************BUTTON**INCREASE**DECREASE***********************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Increase_Decrease(){
//*******************************************************************************************************************************BUTTON**INCREASE**//
      IF(!INPUT(BUTTON_INCREASE) && (state_button_increase)){
         DELAY_MS(250);
         counter_button_increase_decrease = 0;
         state_button_increase                  = FALSE;
         state_display_set_temp                 = TRUE;
         set_temp++;
         IF(set_temp > 28){
            set_temp                            = 28;
         } 
      }
      IF(INPUT(BUTTON_INCREASE)){
         state_button_increase                  = TRUE;
      }
//*******************************************************************************************************************************BUTTON**DECREASE**//
      IF((!INPUT(BUTTON_DECREASE)) && (state_button_decrease)){
         DELAY_MS(250);
         counter_button_increase_decrease = 0;
         state_button_decrease                  = FALSE;
         state_display_set_temp                 = TRUE;
         set_temp--;
         IF(set_temp < 18){
            set_temp                            = 18;
         }
      }
      IF(INPUT(BUTTON_DECREASE)){
         state_button_decrease                  = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//**************************************************************KLIMA**FAN**CONTROLLER*************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Klima_Fan(){
//*************************************************************************************************************************************COUNTER**O**//
      IF((counter_klima_fan % 4) == 0){
         counter_klima_fan                         = 0;
         counter_klima_fan_old                     = counter_klima_fan;
//*****************************************************************************************************************************KLIMA**FAN**OUTPUT**//
         OUTPUT_LOW(KLIMA_FAN_1);
         OUTPUT_LOW(KLIMA_FAN_2);
         OUTPUT_LOW(KLIMA_FAN_3);
      }
//*************************************************************************************************************************************COUNTER**1**//
      IF((counter_klima_fan % 4) == 1){
         counter_klima_fan_old                     = counter_klima_fan;
//*****************************************************************************************************************************KLIMA**FAN**OUTPUT**//
         OUTPUT_HIGH(KLIMA_FAN_1);
         OUTPUT_LOW(KLIMA_FAN_2);
         OUTPUT_LOW(KLIMA_FAN_3);
      }
//*************************************************************************************************************************************COUNTER**2**//
      IF((counter_klima_fan % 4) == 2){
         counter_klima_fan_old                     = counter_klima_fan;
//*****************************************************************************************************************************KLIMA**FAN**OUTPUT**//
         OUTPUT_LOW(KLIMA_FAN_1);
         OUTPUT_HIGH(KLIMA_FAN_2);
         OUTPUT_LOW(KLIMA_FAN_3);
      }
//*************************************************************************************************************************************COUNTER**3**//
      IF((counter_klima_fan % 4) == 3){
         counter_klima_fan_old                     = counter_klima_fan;
//*****************************************************************************************************************************KLIMA**FAN**OUTPUT**//
         OUTPUT_LOW(KLIMA_FAN_1);
         OUTPUT_LOW(KLIMA_FAN_2);
         OUTPUT_HIGH(KLIMA_FAN_3);
      }
   }
//*************************************************************************************************************************************************//
//**************************************************************KLIMA**FAN**CONTROLLER*************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Led_Klima_Fan(){
//*************************************************************************************************************************************COUNTER**O**//
      IF((counter_klima_fan % 4) == 0){
//********************************************************************************************************************************KLIMA**FAN*LEDs**//
         OFFer(KLIMA_FAN_1_OFF);
         OFFer(KLIMA_FAN_2_OFF);
         OUTPUT_LOW(KLIMA_FAN_3_ON);
      }
//*************************************************************************************************************************************COUNTER**1**//
      IF((counter_klima_fan % 4) == 1){
//********************************************************************************************************************************KLIMA**FAN*LEDs**//
         ONer(KLIMA_FAN_1_ON);
         OFFer(KLIMA_FAN_2_OFF);
         OUTPUT_LOW(KLIMA_FAN_3_ON);
      }
//*************************************************************************************************************************************COUNTER**2**//
      IF((counter_klima_fan % 4) == 2){
//********************************************************************************************************************************KLIMA**FAN*LEDs**//
         OFFer(KLIMA_FAN_1_OFF);
         ONer(KLIMA_FAN_2_ON);
         OUTPUT_LOW(KLIMA_FAN_3_ON);
      }
//*************************************************************************************************************************************COUNTER**3**//
      IF((counter_klima_fan % 4) == 3){
//********************************************************************************************************************************KLIMA**FAN*LEDs**//
         OFFer(KLIMA_FAN_1_OFF);
         OFFer(KLIMA_FAN_2_OFF);
         OUTPUT_HIGH(KLIMA_FAN_3_ON);
      }
   }
//*************************************************************************************************************************************************//
//****************************************************************ON**FAN**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_On_Fan(){
//*************************************************************************************************************************************COUNTER**O**//
      IF((counter_on_fan % 4) == 0){
         counter_on_fan                            = 0;
         counter_on_fan_old                        = counter_on_fan;
         value_pwm_fan_driver                      = 0;
         set_pwm4_duty(PWM_FAN_DRIVER_STEP_0);
         SETUP_CCP4(CCP_OFF);
      }
//*************************************************************************************************************************************COUNTER**1**//
      IF((counter_on_fan % 4) == 1){
         counter_on_fan_old                        = counter_on_fan;
         SETUP_CCP4(CCP_PWM);
//**********************************************************************************************************************************START**PWM**0**//
         IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_0){
           FOR(value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_0; value_pwm_fan_driver <= PWM_FAN_DRIVER_STEP_1; value_pwm_fan_driver++){
               set_pwm4_duty(value_pwm_fan_driver);
               DELAY_MS(1);
            }
            value_pwm_fan_driver                             = PWM_FAN_DRIVER_STEP_1;
            set_pwm4_duty(PWM_FAN_DRIVER_STEP_1);
         }
         ELSE{
            value_pwm_fan_driver                             = PWM_FAN_DRIVER_STEP_1;
            set_pwm4_duty(PWM_FAN_DRIVER_STEP_1);
         }
      }
//*************************************************************************************************************************************COUNTER**2**//
      IF((counter_on_fan % 4) == 2){
         counter_on_fan_old                        = counter_on_fan;
         SETUP_CCP4(CCP_PWM);
//**********************************************************************************************************************************START**PWM**0**//
         IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_0){
            FOR(value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_0; value_pwm_fan_driver <= PWM_FAN_DRIVER_STEP_2; value_pwm_fan_driver++){
               set_pwm4_duty(value_pwm_fan_driver);
               DELAY_MS(1);
            }
            value_pwm_fan_driver                             = PWM_FAN_DRIVER_STEP_2;
            set_pwm4_duty(PWM_FAN_DRIVER_STEP_2);
         }
//********************************************************************************************************************************START**PWM**600**//
         ELSE IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_1){
            FOR(value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_1; value_pwm_fan_driver <= PWM_FAN_DRIVER_STEP_2; value_pwm_fan_driver++){
               set_pwm4_duty(value_pwm_fan_driver);
               DELAY_MS(1);
            }
            value_pwm_fan_driver                             = PWM_FAN_DRIVER_STEP_2;
            set_pwm4_duty(PWM_FAN_DRIVER_STEP_2);
         }
         ELSE{
            value_pwm_fan_driver                             = PWM_FAN_DRIVER_STEP_2;
            set_pwm4_duty(PWM_FAN_DRIVER_STEP_2);
         }
      }
//*************************************************************************************************************************************COUNTER**3**//
      IF((counter_on_fan % 4) == 3){
         counter_on_fan_old                        = counter_on_fan;
         SETUP_CCP4(CCP_PWM);
//**********************************************************************************************************************************START**PWM**0**//
         IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_0){
            FOR(value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_0; value_pwm_fan_driver <= PWM_FAN_DRIVER_STEP_3; value_pwm_fan_driver++){
               set_pwm4_duty(value_pwm_fan_driver);
               DELAY_MS(1);
            }
            value_pwm_fan_driver                             = PWM_FAN_DRIVER_STEP_3;
            set_pwm4_duty(PWM_FAN_DRIVER_STEP_3);
         }
//********************************************************************************************************************************START**PWM**600**//
         ELSE IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_1){
            FOR(value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_1; value_pwm_fan_driver <= PWM_FAN_DRIVER_STEP_3; value_pwm_fan_driver++){
               set_pwm4_duty(value_pwm_fan_driver);
               DELAY_MS(1);
            }
            value_pwm_fan_driver                             = PWM_FAN_DRIVER_STEP_3;
            set_pwm4_duty(PWM_FAN_DRIVER_STEP_3);
         }
//********************************************************************************************************************************START**PWM**850**//
         ELSE IF(value_pwm_fan_driver == PWM_FAN_DRIVER_STEP_2){
            FOR(value_pwm_fan_driver = PWM_FAN_DRIVER_STEP_2; value_pwm_fan_driver <= PWM_FAN_DRIVER_STEP_3; value_pwm_fan_driver++){
               set_pwm4_duty(value_pwm_fan_driver);
               DELAY_MS(1);
            }
            value_pwm_fan_driver                             = PWM_FAN_DRIVER_STEP_3;
            set_pwm4_duty(PWM_FAN_DRIVER_STEP_3);
         }
         ELSE{
            value_pwm_fan_driver                             = PWM_FAN_DRIVER_STEP_3;
            set_pwm4_duty(PWM_FAN_DRIVER_STEP_3);
         }
      }
   }
//*************************************************************************************************************************************************//
//****************************************************************ON**FAN**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Led_On_Fan(){
//*************************************************************************************************************************************COUNTER**O**//
      IF((counter_on_fan % 4) == 0){
         OFFer(ON_FAN_1_OFF);
         OFFer(ON_FAN_2_OFF);
         OFFer(ON_FAN_3_OFF);
      }
//*************************************************************************************************************************************COUNTER**1**//
      IF((counter_on_fan % 4) == 1){
         ONer(ON_FAN_1_ON);
         OFFer(ON_FAN_2_OFF);
         OFFer(ON_FAN_3_OFF);
      }
//*************************************************************************************************************************************COUNTER**2**//
      IF((counter_on_fan % 4) == 2){
         OFFer(ON_FAN_1_OFF);
         ONer(ON_FAN_2_ON);
         OFFer(ON_FAN_3_OFF);
      }
//*************************************************************************************************************************************COUNTER**3**//
      IF((counter_on_fan % 4) == 3){
         OFFer(ON_FAN_1_OFF);
         OFFer(ON_FAN_2_OFF);
         ONer(ON_FAN_3_ON);
      }
   }
//*************************************************************************************************************************************************//
//***************************************************************ARKA**FAN**CONTROLLER*************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Arka_Fan(){
//*************************************************************************************************************************************COUNTER**O**//
      IF((counter_arka_fan % 3) == 0){
         counter_arka_fan                          = 0;
         counter_arka_fan_old                      = counter_arka_fan;
         value_pwm_fan_passenger                    = PWM_FAN_PASSENGER_STEP_0;
         SETUP_CCP5(CCP_OFF);
      }
//*************************************************************************************************************************************COUNTER**1**//
      IF((counter_arka_fan % 3) == 1){
         counter_arka_fan_old                      = counter_arka_fan;
         SETUP_CCP5(CCP_PWM);
//**********************************************************************************************************************************START**PWM**0**//
         IF(value_pwm_fan_passenger == PWM_FAN_PASSENGER_STEP_0){
            FOR(value_pwm_fan_passenger = PWM_FAN_PASSENGER_STEP_0; value_pwm_fan_passenger <= PWM_FAN_PASSENGER_STEP_1; value_pwm_fan_passenger++){
               set_pwm5_duty(value_pwm_fan_passenger);
               DELAY_MS(1);
            }
            value_pwm_fan_passenger                             = PWM_FAN_PASSENGER_STEP_1;
            set_pwm5_duty(PWM_FAN_PASSENGER_STEP_1);
         }
         ELSE{
            value_pwm_fan_passenger                             = PWM_FAN_PASSENGER_STEP_1;
            set_pwm5_duty(PWM_FAN_PASSENGER_STEP_1);
         }
      }
//*************************************************************************************************************************************COUNTER**2**//
      IF((counter_arka_fan % 3) == 2){
         counter_arka_fan_old                      = counter_arka_fan;
         SETUP_CCP5(CCP_PWM);
//**********************************************************************************************************************************START**PWM**0**//
         IF(value_pwm_fan_passenger == PWM_FAN_PASSENGER_STEP_0){
            FOR(value_pwm_fan_passenger = PWM_FAN_PASSENGER_STEP_0; value_pwm_fan_passenger <= PWM_FAN_PASSENGER_STEP_2; value_pwm_fan_passenger++){
               set_pwm5_duty(value_pwm_fan_passenger);
               DELAY_MS(1);
            }
            value_pwm_fan_passenger                             = PWM_FAN_PASSENGER_STEP_2;
            set_pwm5_duty(PWM_FAN_PASSENGER_STEP_2);
         }
//********************************************************************************************************************************START**PWM**700**//
         ELSE IF(value_pwm_fan_passenger == PWM_FAN_PASSENGER_STEP_1){
            FOR(value_pwm_fan_passenger = PWM_FAN_PASSENGER_STEP_1; value_pwm_fan_passenger <= PWM_FAN_PASSENGER_STEP_2; value_pwm_fan_passenger++){
               set_pwm5_duty(value_pwm_fan_passenger);
               DELAY_MS(1);
            }
            value_pwm_fan_passenger                             = PWM_FAN_PASSENGER_STEP_2;
            set_pwm5_duty(PWM_FAN_PASSENGER_STEP_2);
         }
         ELSE{
            value_pwm_fan_passenger                             = PWM_FAN_PASSENGER_STEP_2;
            set_pwm5_duty(PWM_FAN_PASSENGER_STEP_2);
         }
      }
   }
//*************************************************************************************************************************************************//
//***************************************************************ARKA**FAN**CONTROLLER*************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Led_Arka_Fan(){
//*************************************************************************************************************************************COUNTER**O**//
      IF((counter_arka_fan % 3) == 0){
         OFFer(ARKA_FAN_1_OFF);
         OFFer(ARKA_FAN_2_OFF);
      }
//*************************************************************************************************************************************COUNTER**1**//
      IF((counter_arka_fan % 3) == 1){
         ONer(ARKA_FAN_1_ON);
         OFFer(ARKA_FAN_2_OFF);
      }
//*************************************************************************************************************************************COUNTER**2**//
      IF((counter_arka_fan % 3) == 2){
         OFFer(ARKA_FAN_1_OFF);
         ONer(ARKA_FAN_2_ON);
      }
   }
//*************************************************************************************************************************************************//
//*******************************************************************CAM**CONTROL******************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Cam_Yuz(){
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
      IF(!state_error_cam){
//************************************************************************************************************************************CAM**KONUMU**//
         IF((counter_cam % 3) == 0){
            counter_cam                                  = 0;
            counter_cam_old                              = counter_cam;
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
            Turn_Left_Cam();
            DELAY_MS(400);
            time_starting_cam                            = get_ticks();
            DELAY_MS(100);
            counter_button_controller_functions          = 0;
            state_turn_complete_cam                      = FALSE;
            WHILE(!state_turn_complete_cam){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions    = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
                  Special_Function_For_Fan_Driver_On_Max_In_While();
               }
               time_current_cam = get_ticks();
               time_difference_cam = Ticks_Difference(time_starting_cam , time_current_cam);
               Turn_Left_Cam();
               DELAY_MS(30);
               Read_Current_L293DD();
               IF(time_difference_cam > time_controller_cam){
                  state_error_control_in_while           = TRUE;
                  time_controller_error_starting         = get_ticks();
                  time_controller_error_current          = get_ticks();
                  time_controller_error_difference       = Ticks_Difference(time_controller_error_starting , time_controller_error_current);
                  WHILE((time_controller_error_difference < 2000) && (state_error_control_in_while)){
                     time_controller_error_current          = get_ticks();
                     time_controller_error_difference       = Ticks_Difference(time_controller_error_starting , time_controller_error_current);
                     Read_Current_L293DD();
                     IF(value_current_l293dd > 50){
                        Stop_Cam();
                        DELAY_MS(100);
                        state_turn_complete_cam             = TRUE;
                        state_error_cam                     = FALSE;
                        state_error_control_in_while        = FALSE;
                        counter_status_cam                  = 0;
                     }
                  }
                  IF(state_error_control_in_while){
                     Stop_Cam();
                     DELAY_MS(100);
                     state_turn_complete_cam                = TRUE;
                     state_error_cam                        = TRUE;
                     state_error_control_in_while           = FALSE;
                     counter_status_cam                     = 0;
                  }
               }
            }
         }
//************************************************************************************************************************************YUZ**KONUMU**//
         IF((counter_cam % 3) == 1){
            counter_cam_old                              = counter_cam;
            Turn_Right_Cam();
            DELAY_MS(400);
            time_starting_cam                            = get_ticks();
            DELAY_MS(100);
            counter_button_controller_functions          = 0;
            state_turn_complete_cam                      = FALSE;
            WHILE(!state_turn_complete_cam){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions    = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
                  Special_Function_For_Fan_Driver_On_Max_In_While();
               }
               time_current_cam = get_ticks();
               time_difference_cam = Ticks_Difference(time_starting_cam , time_current_cam);
               Turn_Right_Cam();
               DELAY_MS(30);
               Read_Current_L293DD();
               IF(time_difference_cam > time_controller_cam){
                  state_error_control_in_while           = TRUE;
                  time_controller_error_starting         = get_ticks();
                  time_controller_error_current          = get_ticks();
                  time_controller_error_difference       = Ticks_Difference(time_controller_error_starting , time_controller_error_current);
                  WHILE((time_controller_error_difference < 2000) && (state_error_control_in_while)){
                     time_controller_error_current          = get_ticks();
                     time_controller_error_difference       = Ticks_Difference(time_controller_error_starting , time_controller_error_current);
                     Read_Current_L293DD();
                     IF(value_current_l293dd > 50){
                        Stop_Cam();
                        DELAY_MS(100);
                        state_turn_complete_cam             = TRUE;
                        state_error_cam                     = FALSE;
                        state_error_control_in_while        = FALSE;
                        counter_status_cam                  = 1;
                     }
                  }
                  IF(state_error_control_in_while){
                     Stop_Cam();
                     DELAY_MS(100);
                     state_turn_complete_cam                = TRUE;
                     state_error_cam                        = TRUE;
                     state_error_control_in_while           = FALSE;
                     counter_status_cam                     = 1;
                  }
               }
            }
         }
//********************************************************************************************************************************BERABER**KONUMU**//
         IF((counter_cam % 3) == 2){
            counter_cam_old                                 = counter_cam;
//********************************************************************************************************************IF**COME**FROM**YUZ**KONUMU**//
            IF((counter_status_cam % 3) == 0){
               Turn_Right_Cam();
               DELAY_MS(400);
               time_starting_cam                            = get_ticks();
               DELAY_MS(100);
               counter_button_controller_functions          = 0;
               state_turn_complete_cam                      = FALSE;
               WHILE(!state_turn_complete_cam){
                  Turn_Right_Cam();
                  DELAY_MS(1);
                  counter_button_controller_functions++;
                  IF(counter_button_controller_functions > 500){
                     counter_button_controller_functions    = 0;
                     Button_Controller_Functions(); 
                     Controller_Led_Functions();
                     Special_Function_For_Fan_Driver_On_Max_In_While();
                  }
                  time_current_cam                          = get_ticks();
                  time_difference_cam                       = Ticks_Difference(time_starting_cam, time_current_cam);
                  IF(time_difference_cam > (abs(time_mid_cam - 2000))){
                     Stop_Cam();
                     DELAY_MS(100);
                     state_turn_complete_cam                = TRUE;
                     counter_status_cam                     = 2;
                  }
               }
            }
//********************************************************************************************************************IF**COME**FROM**CAM**KONUMU**//
            IF((counter_status_cam % 3) == 1){
               Turn_Left_Cam();
               DELAY_MS(400);
               time_starting_cam                            = get_ticks();
               DELAY_MS(100);
               counter_button_controller_functions          = 0;
               state_turn_complete_cam                      = FALSE;
               WHILE(!state_turn_complete_cam){
                  Turn_Left_Cam();
                  DELAY_MS(1);
                  counter_button_controller_functions++;
                  IF(counter_button_controller_functions > 500){
                     counter_button_controller_functions    = 0;
                     Button_Controller_Functions(); 
                     Controller_Led_Functions();
                     Special_Function_For_Fan_Driver_On_Max_In_While();
                  }
                  time_current_cam                          = get_ticks();
                  time_difference_cam                       = Ticks_Difference(time_starting_cam, time_current_cam);
                  IF(time_difference_cam > (time_mid_cam + 3000)){
                     Stop_Cam();
                     DELAY_MS(100);
                     state_turn_complete_cam                = TRUE;
                     counter_status_cam                     = 2;
                  }
               }
            }
         }
      }
   }
//*************************************************************************************************************************************************//
//*******************************************************************CAM**CONTROL******************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Led_Cam_Yuz(){
//************************************************************************************************************************************CAM**KONUMU**//
      IF((counter_cam % 3) == 0){
         ONer(CAM_ON);
         OUTPUT_LOW(YUZ_LED);
         OFFer(BERABER_OFF);
      }
//************************************************************************************************************************************YUZ**KONUMU**//
      IF((counter_cam % 3) == 1){
         OFFer(CAM_OFF);
         OUTPUT_HIGH(YUZ_LED);
         OFFer(BERABER_OFF);
      }
//********************************************************************************************************************************BERABER**KONUMU**//
      IF((counter_cam % 3) == 2){
         OFFer(CAM_OFF);
         OUTPUT_LOW(YUZ_LED);
         ONer(BERABER_ON);
      }
   }    
//*************************************************************************************************************************************************//
//************************************************************TEMIZ**HAVA**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Temiz_Hava(){
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
      IF(!state_error_temiz_hava){
//*************************************************************************************************************************************COUNTER**0**//
         IF((counter_temiz_hava % 2) == 0){
            counter_temiz_hava                              = 0;
            counter_temiz_hava_old                          = counter_temiz_hava;
            Turn_Left_Temiz_Hava();
            DELAY_MS(400);
            time_starting_temiz_hava                     = get_ticks();
            DELAY_MS(100);
            counter_button_controller_functions          = 0;
            state_turn_complete_temiz_hava               = FALSE;
            WHILE(!state_turn_complete_temiz_hava){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions    = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
                  Special_Function_For_Fan_Driver_On_Max_In_While();
               }
               time_current_temiz_hava                   = get_ticks();
               time_difference_temiz_hava                = Ticks_Difference(time_starting_temiz_hava , time_current_temiz_hava);
               Turn_Left_Temiz_Hava();
               DELAY_MS(30);
               Read_Current_L293DD();
               IF(time_difference_temiz_hava > time_controller_temiz_hava){
                  state_error_control_in_while           = TRUE;
                  time_controller_error_starting         = get_ticks();
                  time_controller_error_current          = get_ticks();
                  time_controller_error_difference       = Ticks_Difference(time_controller_error_starting , time_controller_error_current);
                  WHILE((time_controller_error_difference < 2000) && (state_error_control_in_while)){
                     time_controller_error_current          = get_ticks();
                     time_controller_error_difference       = Ticks_Difference(time_controller_error_starting , time_controller_error_current);
                     Read_Current_L293DD();
                     IF(value_current_l293dd > 50){
                        Stop_Temiz_Hava();
                        DELAY_MS(100);
                        state_turn_complete_temiz_hava      = TRUE;
                        state_error_control_in_while        = FALSE;
                        state_error_temiz_hava              = FALSE;
                     }
                  }
                  IF(state_error_control_in_while){
                     Stop_Temiz_Hava();
                     DELAY_MS(100);
                     state_turn_complete_temiz_hava         = TRUE;
                     state_error_temiz_hava                 = TRUE;
                     state_error_control_in_while           = FALSE;
                  }
               }
            }
         }
//*************************************************************************************************************************************COUNTER**1**//
         IF((counter_temiz_hava % 2) == 1){
            counter_temiz_hava_old                          = counter_temiz_hava;
            Turn_Right_Temiz_Hava();
            DELAY_MS(400);
            time_starting_temiz_hava                     = get_ticks();
            DELAY_MS(100);
            counter_button_controller_functions          = 0;
            state_turn_complete_temiz_hava               = FALSE;
            WHILE(!state_turn_complete_temiz_hava){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions    = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
                  Special_Function_For_Fan_Driver_On_Max_In_While();
               }
               time_current_temiz_hava = get_ticks();
               time_difference_temiz_hava = Ticks_Difference(time_starting_temiz_hava , time_current_temiz_hava);
               Turn_Right_Temiz_Hava();
               DELAY_MS(30);
               Read_Current_L293DD();
               IF(time_difference_temiz_hava > time_controller_temiz_hava){
                  state_error_control_in_while           = TRUE;
                  time_controller_error_starting         = get_ticks();
                  time_controller_error_current          = get_ticks();
                  time_controller_error_difference       = Ticks_Difference(time_controller_error_starting , time_controller_error_current);
                  WHILE((time_controller_error_difference < 2000) && (state_error_control_in_while)){
                     time_controller_error_current          = get_ticks();
                     time_controller_error_difference       = Ticks_Difference(time_controller_error_starting , time_controller_error_current);
                     Read_Current_L293DD();
                     IF(value_current_l293dd > 50){
                        Stop_Temiz_Hava();
                        DELAY_MS(100);
                        state_turn_complete_temiz_hava      = TRUE;
                        state_error_control_in_while        = FALSE;
                        state_error_temiz_hava              = FALSE;
                     }
                  }
                  IF(state_error_control_in_while){
                     Stop_Temiz_Hava();
                     DELAY_MS(100);
                     state_turn_complete_temiz_hava         = TRUE;
                     state_error_temiz_hava                 = TRUE;
                     state_error_control_in_while           = FALSE;
                  }
               }
            }
         }
      }
   }
//*************************************************************************************************************************************************//
//************************************************************TEMIZ**HAVA**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Led_Temiz_Hava(){
//*************************************************************************************************************************************COUNTER**0**//
      IF((counter_temiz_hava % 2) == 0){
         OFFer(TEMIZ_HAVA_OFF);
      }
//*************************************************************************************************************************************COUNTER**1**//
      IF((counter_temiz_hava % 2) == 1){
         ONer(TEMIZ_HAVA_ON);
      }
   }     
//*************************************************************************************************************************************************//
//****************************************************************VANA**1**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Vana_1(){
//***********************************************************************************************************************IF**THERE**IS**NO**ERROR**//
      IF(!state_error_vana_1){
//*************************************************************************************************************************************COUNTER**0**//
         IF((counter_vana_1 % 3) == 0){
            counter_vana_1                            = 0;
            counter_vana_1_old                        = counter_vana_1;
            Turn_Left_Vana_1();
            DELAY_MS(400);
            time_starting_vana_1                   = get_ticks();
            DELAY_MS(100);
            counter_button_controller_functions    = 0;
            state_turn_complete_vana_1             = FALSE;
            WHILE(!state_turn_complete_vana_1){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions    = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
                  Special_Function_For_Fan_Driver_On_Max_In_While();
               }
               time_current_vana_1 = get_ticks();
               time_difference_vana_1 = Ticks_Difference(time_starting_vana_1 , time_current_vana_1);
               Turn_Left_Vana_1();
               DELAY_MS(30);
               Read_Current_L293DD();
               IF(time_difference_vana_1 > time_controller_vana_1){
                  state_error_control_in_while        = TRUE;
                  time_controller_error_starting         = get_ticks();
                  time_controller_error_current          = get_ticks();
                  time_controller_error_difference       = Ticks_Difference(time_controller_error_starting , time_controller_error_current);
                  WHILE((time_controller_error_difference < 2000) && (state_error_control_in_while)){
                     time_controller_error_current          = get_ticks();
                     time_controller_error_difference       = Ticks_Difference(time_controller_error_starting , time_controller_error_current);
                     Read_Current_L293DD();
                     IF(value_current_l293dd > 50){
                        Stop_Vana_1();
                        DELAY_MS(100);
                        state_turn_complete_vana_1          = TRUE;
                        state_error_vana_1                  = FALSE;
                        state_error_control_in_while        = FALSE;
                        counter_status_vana_1               = 0;
                     }
                  }
                  IF(state_error_control_in_while){
                     Stop_Vana_1();
                     DELAY_MS(100);
                     state_turn_complete_vana_1             = TRUE;
                     state_error_vana_1                     = TRUE;
                     state_error_control_in_while           = FALSE;
                     counter_status_vana_1                  = 0;
                  }
               }
            }
         }
//*************************************************************************************************************************************COUNTER**1**//
         IF((counter_vana_1 % 3) == 1){
            counter_vana_1_old                           = counter_vana_1;
//******************************************************************************************************************IF**COME**FROM**CLOSE**KONUMU**//
            IF((counter_status_vana_1 % 3) == 0){
               Turn_Right_Vana_1();
               DELAY_MS(400);
               time_starting_vana_1                         = get_ticks();
               DELAY_MS(100);
               counter_button_controller_functions          = 0;
               state_turn_complete_vana_1                   = FALSE;
               WHILE(!state_turn_complete_vana_1){
                  Turn_Right_Vana_1();
                  DELAY_MS(1);
                  counter_button_controller_functions++;
                  IF(counter_button_controller_functions > 500){
                     counter_button_controller_functions    = 0;
                     Button_Controller_Functions(); 
                     Controller_Led_Functions();
                     Special_Function_For_Fan_Driver_On_Max_In_While();
                  }
                  time_current_vana_1                       = get_ticks();
                  time_difference_vana_1                    = Ticks_Difference(time_starting_vana_1,time_current_vana_1);
                  IF(time_difference_vana_1 > time_mid_vana_1){
                     Stop_Vana_1();
                     DELAY_MS(100);
                     state_turn_complete_vana_1             = TRUE;
                     counter_status_vana_1                  = 2;
                  }
               }
            }
//*******************************************************************************************************************IF**COME**FROM**OPEN**KONUMU**//
            IF((counter_status_vana_1 % 3) == 1){
               Turn_Left_Vana_1();
               DELAY_MS(400);
               time_starting_vana_1                   = get_ticks();
               DELAY_MS(100);
               counter_button_controller_functions    = 0;
               state_turn_complete_vana_1             = FALSE;
               WHILE(!state_turn_complete_vana_1){
                  Turn_Left_Vana_1();
                  DELAY_MS(100);
                  counter_button_controller_functions++;
                  IF(counter_button_controller_functions > 10){
                     counter_button_controller_functions    = 0;
                     Button_Controller_Functions(); 
                     Controller_Led_Functions();
                     Special_Function_For_Fan_Driver_On_Max_In_While();
                  }
                  time_current_vana_1                 = get_ticks();
                  time_difference_vana_1              = Ticks_Difference(time_starting_vana_1,time_current_vana_1);
                  IF(time_difference_vana_1 > time_mid_vana_1){
                     Stop_Vana_1();
                     DELAY_MS(100);
                     state_turn_complete_vana_1       = TRUE;
                     counter_status_vana_1            = 2;
                  }
               }
            }
         }
//*************************************************************************************************************************************COUNTER**2**//
         IF((counter_vana_1 % 3) == 2){
            counter_vana_1_old                        = counter_vana_1;
            Turn_Right_Vana_1();
            DELAY_MS(400);
            time_starting_vana_1                   = get_ticks();
            DELAY_MS(100);
            counter_button_controller_functions    = 0;
            state_turn_complete_vana_1             = FALSE;
            WHILE(!state_turn_complete_vana_1){
               counter_button_controller_functions++;
               IF(counter_button_controller_functions > 10){
                  counter_button_controller_functions    = 0;
                  Button_Controller_Functions(); 
                  Controller_Led_Functions();
                  Special_Function_For_Fan_Driver_On_Max_In_While();
               }
               time_current_vana_1                 = get_ticks();
               time_difference_vana_1              = Ticks_Difference(time_starting_vana_1 , time_current_vana_1);
               Turn_Right_Vana_1();
               DELAY_MS(30);
               Read_Current_L293DD();
               IF(time_difference_vana_1 > time_controller_vana_1){
                  state_error_control_in_while        = TRUE;
                  time_controller_error_starting         = get_ticks();
                  time_controller_error_current          = get_ticks();
                  time_controller_error_difference       = Ticks_Difference(time_controller_error_starting , time_controller_error_current);
                  WHILE((time_controller_error_difference < 2000) && (state_error_control_in_while)){
                     time_controller_error_current          = get_ticks();
                     time_controller_error_difference       = Ticks_Difference(time_controller_error_starting , time_controller_error_current);
                     Read_Current_L293DD();
                     IF(value_current_l293dd > 50){
                        Stop_Vana_1();
                        DELAY_MS(100);
                        state_turn_complete_vana_1          = TRUE;
                        state_error_vana_1                  = FALSE;
                        state_error_control_in_while        = FALSE;
                        counter_status_vana_1               = 1;
                     }
                  }
                  IF(state_error_control_in_while){
                     Stop_Vana_1();
                     DELAY_MS(100);
                     state_turn_complete_vana_1             = TRUE;
                     state_error_vana_1                     = TRUE;
                     state_error_control_in_while           = FALSE;
                     counter_status_vana_1                  = 1;
                  }
               }
            }
         }
      }
   }
//*************************************************************************************************************************************************//
//****************************************************************VANA**1**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Led_Vana_1(){
//*************************************************************************************************************************************COUNTER**0**//
      IF((counter_vana_1 % 3) == 0){
         ONer(VANA_1_1_ON);
         OFFer(VANA_1_2_OFF);
         OFFer(VANA_1_3_OFF);
      }
//*************************************************************************************************************************************COUNTER**1**//
      IF((counter_vana_1 % 3) == 1){
         OFFer(VANA_1_1_OFF);
         ONer(VANA_1_2_ON);
         OFFer(VANA_1_3_OFF);
      }
//*************************************************************************************************************************************COUNTER**2**//
      IF((counter_vana_1 % 3) == 2){
         OFFer(VANA_1_1_OFF);
         OFFer(VANA_1_2_OFF);
         ONer(VANA_1_3_ON);
      }
   }  
//*************************************************************************************************************************************************//
//*********************************************************CONTROL**KOMPRESSOR**AND**KONDANSER*****************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Klima(){
//********************************************************************************************************************************************OFF**//
      IF((counter_klima % 3) == 0){
         counter_klima_old                         = counter_klima;
         state_time_starting_klima_on              = TRUE;
         state_time_starting_klima_quickly_off     = TRUE;
         IF(state_time_starting_klima_off){
            time_starting_klima                    = get_ticks();
            state_time_starting_klima_off          = FALSE;
         }
         time_current_klima                        = get_ticks();
         time_difference_klima                     = Ticks_Difference(time_starting_klima,time_current_klima);
         IF(time_difference_klima > 2000){
            OUTPUT_LOW(KOMPRESSOR);
         }
         IF(time_difference_klima > 10000){
            OUTPUT_LOW(KONDANSER);
            state_prosses_complete_klima           = TRUE;
            state_time_starting_klima_off          = TRUE;
         }
      }
//*********************************************************************************************************************************************ON**//
      IF((counter_klima % 3) == 1){
         counter_klima_old                         = counter_klima;
         state_time_starting_klima_off             = TRUE;
         state_time_starting_klima_quickly_off     = TRUE;
         IF(state_time_starting_klima_on){
            time_starting_klima                    = get_ticks();
            state_time_starting_klima_on           = FALSE;
         }
         time_current_klima                        = get_ticks();
         time_difference_klima                     = Ticks_Difference(time_starting_klima,time_current_klima);
         IF(time_difference_klima > 2000){
            OUTPUT_HIGH(KONDANSER);
         }
         IF(time_difference_klima > 10000){
            OUTPUT_HIGH(KOMPRESSOR);
            state_prosses_complete_klima           = TRUE;
            state_time_starting_klima_on           = TRUE;
         }
      }
//***********************************************************************************************************************************QUICKLY**OFF**//
      IF((counter_klima % 3) == 2){
         counter_klima_old                         = counter_klima;
         state_time_starting_klima_on              = TRUE;
         state_time_starting_klima_off             = TRUE;
         IF(state_time_starting_klima_quickly_off){
            time_starting_klima                    = get_ticks();
            state_time_starting_klima_quickly_off  = FALSE;
         }
         time_current_klima                        = get_ticks();
         time_difference_klima                     = Ticks_Difference(time_starting_klima,time_current_klima);
         IF(time_difference_klima > 1000){
            OUTPUT_LOW(KOMPRESSOR);
            OUTPUT_LOW(KONDANSER);
            state_prosses_complete_klima           = TRUE;
            state_time_starting_klima_quickly_off  = TRUE;
         }
      }
   }
//*************************************************************************************************************************************************//
//******************************************************CONTROL**COMPARE**AND**TEMP**AND**SET**TEMP************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Air_Conditioning_Signal(){
   IF((counter_ac % 2) == 0){
      OUTPUT_LOW(AIR_CONDITIONING_SIGNAL);
   }
   IF((counter_ac % 2) == 1){
      OUTPUT_HIGH(AIR_CONDITIONING_SIGNAL);
   }
}
//*************************************************************************************************************************************************//
//******************************************************CONTROL**COMPARE**AND**TEMP**AND**SET**TEMP************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_And_Compare_Temp_And_Set_Temp(){
      IF((counter_ac % 2) == 1){
         IF((!state_error_sensor_1) && (!state_error_yuksek_basinc)){
            IF((temp - set_temp) >= 2){
               counter_klima  = 1;
               state_controller_and_compare_temp_and_set_temp = TRUE;
            }
            IF(state_controller_and_compare_temp_and_set_temp){
               IF((set_temp - temp) >= 0){
                  counter_klima  = 0;
                  state_controller_and_compare_temp_and_set_temp = FALSE;
               }
            }
         }
         IF((state_error_sensor_1) || (state_error_yuksek_basinc)){
            counter_klima = 2;
         }
         Write_Display_Error();
      }
   }
//*************************************************************************************************************************************************//
//*****************************************************************ERROR**CONTROLLER***************************************************************//
//*************************************************************************************************************************************************//
   VOID Write_Display_Error(){
      IF(((temp - set_temp) >= 2) && (state_error_yuksek_basinc)){
         state_write_klima_error = TRUE;
      }
      IF(((set_temp - temp) >= 0) || (!state_error_yuksek_basinc)){
         state_write_klima_error = FALSE;
      }
   }   
//*************************************************************************************************************************************************//
//*****************************************************************ERROR**CONTROLLER***************************************************************//
//*************************************************************************************************************************************************//
//**                                                                                                                                             **//
//**                                                    300 DEGERINDE YAKALADI. 1000 DEGERI IDEAL.                                               **//
//**                                                            50000 DEGERI KULLANILDI                                                          **//
//*************************************************************************************************************************************************//
   VOID Controller_Error_And_Temperature(){
      counter_controller_error++;
//*********************************************************************************************************************************CONTROL**ERROR**//
      IF((counter_controller_error % 501) == 1){
         counter_controller_error                  = 0;
         counter_error_constant_temporary          = 0;
         counter_error_temporary                   = 0;
         SET_ADC_CHANNEL(CHANNEL_SENSOR_2);
         DELAY_US(50);
         temp_1                                    = READ_ADC();
         IF(temp_1 < 50){
            state_error_sensor_1                   = TRUE;
         }
         ELSE{
            state_error_sensor_1                   = FALSE;
            IF(abs(temp_1 - temp_2) > 9){
               temp                                = ((temp_1 - 290) / (11));
               temp_2                              = temp_1;
            }
         }
         IF(!INPUT(ERROR)){
            state_error_yuksek_basinc = TRUE;
         }
         ELSE{
            state_error_yuksek_basinc              = FALSE;
         }
         counter_error_temporary++;
         counter_error_constant_temporary++;
         counter_controller_sensor = (counter_error_temporary * 1000);
         IF(state_error_cam){
            counter_error_temporary++;
            counter_error_constant_temporary++;
            counter_controller_cam = (counter_error_temporary * 1000);
         }
         IF(state_error_vana_1){
            counter_error_temporary++;
            counter_error_constant_temporary++;
            counter_controller_vana_1 = (counter_error_temporary * 1000);
         }
         IF(state_error_temiz_hava){
            counter_error_temporary++;
            counter_error_constant_temporary++;
            counter_controller_temiz_hava = (counter_error_temporary * 1000);
         }
         IF(state_write_klima_error){
            counter_error_temporary++;
            counter_error_constant_temporary++;
            counter_controller_error_input = (counter_error_temporary * 1000);
         }
            counter_error_constant = ((counter_error_constant_temporary * 1000) + 1);
      }
      Write_Error();
   }
//*************************************************************************************************************************************************//
//********************************************************************WRITE**ERROR*****************************************************************//
//*************************************************************************************************************************************************//
   VOID Write_Error(){
      IF(!state_display_set_temp){
         counter_write_error++;
         IF(state_error_sensor_1){
            IF((counter_write_error % counter_error_constant) == counter_controller_sensor){
               display_register                                = ORer_Two_Number(numbers[10],numbers[1]);
               Write_Display(display_register);
            }
         }
         IF(!state_error_sensor_1){
            IF((counter_write_error % counter_error_constant) == counter_controller_sensor){
               digit_10                                        = (temp / 10);
               digit_1                                         = (temp % 10);
               display_register                                = ORer_Two_Number(numbers[digit_10], numbers[digit_1]);
               Write_Display(display_register);
            }
         }
         IF(state_error_cam){
            IF((counter_write_error % counter_error_constant) == counter_controller_cam){
               display_register                                = ORer_Two_Number(numbers[10],numbers[2]);
               Write_Display(display_register);
            }
         }
         IF(state_error_vana_1){
            IF((counter_write_error % counter_error_constant) == counter_controller_vana_1){
               display_register                                = ORer_Two_Number(numbers[10],numbers[3]);
               Write_Display(display_register);
            }
         }
         IF(state_error_temiz_hava){
            IF((counter_write_error % counter_error_constant) == counter_controller_temiz_hava){
               display_register                                = ORer_Two_Number(numbers[10],numbers[4]);
               Write_Display(display_register);
            }
         }
         IF(state_write_klima_error){
            IF((counter_write_error % counter_error_constant) == counter_controller_error_input){
               display_register                                = ORer_Two_Number(numbers[10],numbers[5]);
               Write_Display(display_register);
            }
         }
      }
//************************************************************************************SHOW**SET*TEMP**WHEN**PUSH**THE**BUTTON**INCREASE**DECREASE**//
      IF(state_display_set_temp){
         counter_button_increase_decrease++;
         digit_10                               = (set_temp / 10);
         digit_1                                = (set_temp % 10);
         display_register     = ORer_Two_Number(numbers[(digit_10)], numbers[(digit_1)]);
         Write_Display(display_register);
         write_eeprom(address_set_temp, set_temp);
         IF(counter_button_increase_decrease == 600){
            state_display_set_temp = FALSE;
         }
      }
   }
//*************************************************************************************************************************************************//
//********************************************************************DISPLAY**********************************************************************//
//*************************************************************************************************************************************************//
   VOID Write_Display(INT16 write_display_integer){
      write_display_integer         = Change_8_Bits_Of_16_Bit_Data(write_display_integer);
      OUTPUT_LOW(ST_CP_DISPLAY);
      
      FOR(counter_write_display = 0; counter_write_display < 16; counter_write_display++){
      
         OUTPUT_LOW(SH_CP_DISPLAY);
         
         if((write_display_integer << counter_write_display) & 0x8000){
            OUTPUT_HIGH(DATA_DISPLAY);
         }
         ELSE{
            OUTPUT_LOW(DATA_DISPLAY);
         }
         OUTPUT_HIGH(SH_CP_DISPLAY);
      }
      OUTPUT_HIGH(ST_CP_DISPLAY);
   }
//*************************************************************************************************************************************************//
//***********************************************************************LED***********************************************************************//
//*************************************************************************************************************************************************//
   VOID Write_Led(INT16 write_led_integer){

      OUTPUT_LOW(ST_CP_LED);
      
      FOR(counter_write_led = 0; counter_write_led < 16; counter_write_led++){
      
         OUTPUT_LOW(SH_CP_LED);
         
         if((write_led_integer << counter_write_led) & 0x8000){
            OUTPUT_HIGH(DATA_LED);
         }
         ELSE{
            OUTPUT_LOW(DATA_LED);
         }
         OUTPUT_HIGH(SH_CP_LED);
      }
      OUTPUT_HIGH(ST_CP_LED);
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
//****************************************************CHANGE**PLACE**OF**8**BIT**OF**16**BIT**DATA*************************************************//
//*************************************************************************************************************************************************//
   INT16 Change_8_Bits_Of_16_Bit_Data(INT16 _16_bit_data_will_changed){
      _16_bit_data_temporary        = _16_bit_data_will_changed << 8;
      _16_bit_data_will_changed     = _16_bit_data_will_changed >> 8;
      _16_bit_data_will_changed     = _16_bit_data_will_changed | _16_bit_data_temporary;
      RETURN _16_bit_data_will_changed;
   }
//*************************************************************************************************************************************************//
//*********************************************************************ORRER***********************************************************************//
//*************************************************************************************************************************************************//
   INT16 ORer_Two_Number(INT8 number_1, INT8 number_2){
      orrer_digit_10                               = number_1;
      orrer_digit_1                                = number_2;
      orrer_digit_10                               = orrer_digit_10 << 8;
      orrer_result                                 = orrer_digit_10 | orrer_digit_1;
      RETURN orrer_result;
   }
//*************************************************************************************************************************************************//
//*******************************************************************READ**MOTOR*******************************************************************//
//*************************************************************************************************************************************************//
//**********************************************************************************************************************CURRENT**TEMIZ**HAVA**CAM**//
   VOID Read_Current_L293DD(){
      value_current_l293dd = 0;
      FOR(INT8 i = 0; i < 10; i++){
         SET_ADC_CHANNEL(CHANNEL_CURRENT_L293DD);
         DELAY_MS(2);
         value_current_temporary                         = READ_ADC();
         value_current_l293dd                            = value_current_l293dd + value_current_temporary;
      }
      value_current_l293dd                               = (value_current_l293dd / 10);
   }
//*************************************************************************************************************************************************//
//****************************************************************MOVEMENT**MOTOR******************************************************************//
//*************************************************************************************************************************************************//
//********************************************************************************************************************************************CAM**//
//************************************************************************************************************************************TURN**RIGHT**//
   VOID Turn_Right_Cam(){
      OUTPUT_HIGH(CAM_EN);
      OUTPUT_LOW(VANA_1_EN);
      OUTPUT_LOW(CAM_IN_1);
      OUTPUT_HIGH(CAM_IN_2);
   }
//*************************************************************************************************************************************TURN**LEFT**//
   VOID Turn_Left_Cam(){
      OUTPUT_HIGH(CAM_EN);
      OUTPUT_LOW(VANA_1_EN);
      OUTPUT_HIGH(CAM_IN_1);
      OUTPUT_LOW(CAM_IN_2);
   }
//*******************************************************************************************************************************************STOP**//
   VOID Stop_Cam(){
      OUTPUT_LOW(CAM_EN);
      OUTPUT_LOW(CAM_IN_1);
      OUTPUT_LOW(CAM_IN_2);
   }
//************************************************************************************************************************************TEMIZ**HAVA**//
//************************************************************************************************************************************TURN**RIGHT**//
   VOID Turn_Right_Temiz_Hava(){
      OUTPUT_HIGH(TEMIZ_HAVA_EN_1);
      OUTPUT_HIGH(TEMIZ_HAVA_EN_2);
      OUTPUT_HIGH(TEMIZ_HAVA_IN_1_1);
      OUTPUT_HIGH(TEMIZ_HAVA_IN_1_2);
      OUTPUT_LOW(TEMIZ_HAVA_IN_2_1);
      OUTPUT_LOW(TEMIZ_HAVA_IN_2_2);
   }
//*************************************************************************************************************************************TURN**LEFT**//
   VOID Turn_Left_Temiz_Hava(){
      OUTPUT_HIGH(TEMIZ_HAVA_EN_1);
      OUTPUT_HIGH(TEMIZ_HAVA_EN_2);
      OUTPUT_LOW(TEMIZ_HAVA_IN_1_1);
      OUTPUT_LOW(TEMIZ_HAVA_IN_1_2);
      OUTPUT_HIGH(TEMIZ_HAVA_IN_2_1);
      OUTPUT_HIGH(TEMIZ_HAVA_IN_2_2);
   }
//*******************************************************************************************************************************************STOP**//
   VOID Stop_Temiz_Hava(){
      OUTPUT_LOW(TEMIZ_HAVA_EN_1);
      OUTPUT_LOW(TEMIZ_HAVA_EN_2);
      OUTPUT_LOW(TEMIZ_HAVA_IN_1_1);
      OUTPUT_LOW(TEMIZ_HAVA_IN_1_2);
      OUTPUT_LOW(TEMIZ_HAVA_IN_2_1);
      OUTPUT_LOW(TEMIZ_HAVA_IN_2_2);
   }
//****************************************************************************************************************************************VANA**1**//
//************************************************************************************************************************************TURN**RIGHT**//
   VOID Turn_Right_Vana_1(){
      OUTPUT_HIGH(VANA_1_EN);
      OUTPUT_LOW(CAM_EN);
      OUTPUT_LOW(VANA_1_IN_1);
      OUTPUT_HIGH(VANA_1_IN_2);
   }
//*************************************************************************************************************************************TURN**LEFT**//
   VOID Turn_Left_Vana_1(){
      OUTPUT_HIGH(VANA_1_EN);
      OUTPUT_LOW(CAM_EN);
      OUTPUT_HIGH(VANA_1_IN_1);
      OUTPUT_LOW(VANA_1_IN_2);
   }
//*******************************************************************************************************************************************STOP**//
   VOID Stop_Vana_1(){
      OUTPUT_LOW(VANA_1_EN);
      OUTPUT_LOW(VANA_1_IN_1);
      OUTPUT_LOW(VANA_1_IN_2);
   }
//*************************************************************************************************************************************************//
//***********************************************************************END***********************************************************************//
//*************************************************************************************************************************************************//
