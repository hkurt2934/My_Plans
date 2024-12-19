//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
//****************************************************************HEADER**FILE*********************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
//********************************************************EXPLANATION**FOR**THIS**CODE*************************************************************//
//*************************************************************************************************************************************************//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
#INCLUDE <16F1947.h>
//*************************************************************************************************************************************************//
#DEVICE ADC=10
//*************************************************************************************************************************************************//
#FUSES NOWDT
#FUSES NOLVP
#FUSES NOMCLR
#FUSES NOBROWNOUT
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
#USE DELAY(INTERNAL = 4MHZ)
#USE FAST_IO(A)
#USE FAST_IO(B)
#USE FAST_IO(C)
#USE FAST_IO(D)
#USE FAST_IO(E)
#USE FAST_IO(G)
//*************************************************************************************************************************************************//
//****************************************************************PIN***DEFINES********************************************************************//
//*************************************************************************************************************************************************//
//Display**Pins************************************************************************************************************************************//
#DEFINE DATA_DISPLAY                               PIN_D5
#DEFINE SH_CP_DISPLAY                              PIN_D6
#DEFINE ST_CP_DISPLAY                              PIN_D7
//Led**Pins****************************************************************************************************************************************//
#DEFINE DATA_LED                                   PIN_D2
#DEFINE SH_CP_LED                                  PIN_D0
#DEFINE ST_CP_LED                                  PIN_D1                                         
//Bildirim**Ledleri********************************************************************************************************************************//
#DEFINE KLIMA_FAN_DEFAULT                          0xFFFC
#DEFINE KLIMA_FAN_1_ON                             0x0002
#DEFINE KLIMA_FAN_1_OFF                            0xFFFD
#DEFINE KLIMA_FAN_2_ON                             0x0001
#DEFINE KLIMA_FAN_2_OFF                            0xFFFE
#DEFINE KLIMA_FAN_3_ON                             PIN_D4
#DEFINE ON_FAN_DEFAULT                             0xFF1F
#DEFINE ON_FAN_1_ON                                0x0080
#DEFINE ON_FAN_1_OFF                               0xFF7F
#DEFINE ON_FAN_2_ON                                0x0040
#DEFINE ON_FAN_2_OFF                               0xFFBF
#DEFINE ON_FAN_3_ON                                0x0020
#DEFINE ON_FAN_3_OFF                               0xFFDF
#DEFINE ARKA_FAN_DEFAULT                           0xF9FF
#DEFINE ARKA_FAN_1_ON                              0x0200
#DEFINE ARKA_FAN_1_OFF                             0xFDFF
#DEFINE ARKA_FAN_2_ON                              0x0400
#DEFINE ARKA_FAN_2_OFF                             0xFBFF
#DEFINE CAM_DEFAULT                                0xBFF7
#DEFINE CAM_ON                                     0x0008
#DEFINE CAM_OFF                                    0xFFF7
#DEFINE YUZ_ON                                     0x4000
#DEFINE YUZ_OFF                                    0xBFFF
#DEFINE MAX_DEFAULT                                0xFFEF
#DEFINE MAX_ON                                     0x0010
#DEFINE MAX_OFF                                    0xFFEF
#DEFINE TEMIZ_HAVA_DEFAULT                         0xDFFF
#DEFINE TEMIZ_HAVA_ON                              0x2000
#DEFINE TEMIZ_HAVA_OFF                             0xDFFF
#DEFINE VANA_1_DEFAULT                             0xFFFB
#DEFINE VANA_1_1_ON                                PIN_F1
#DEFINE VANA_1_2_ON                                PIN_F0
#DEFINE VANA_1_3_ON                                0x0004
#DEFINE VANA_1_3_OFF                               0xFFFB
#DEFINE VANA_2_DEFAULT                             0x67FF
#DEFINE VANA_2_1_ON                                0x0800
#DEFINE VANA_2_1_OFF                               0xF7FF
#DEFINE VANA_2_2_ON                                0x1000
#DEFINE VANA_2_2_OFF                               0xEFFF
#DEFINE VANA_2_3_ON                                0x8000
#DEFINE VANA_2_3_OFF                               0x7FFF
#DEFINE AC_DEFAULT                                 0xFEFF
#DEFINE AC_ON                                      0x0100
//ADC**Pins****************************************************************************************************************************************//
#DEFINE ADC_Vana_1                                 sAN1
#DEFINE ADC_Vana_2                                 sAN2
#DEFINE ADC_Cam_Pot                                sAN3
#DEFINE ADC_Temiz_Hava_Pot                         sAN4
#DEFINE ADC_Sensor_Driver                          sAN9
#DEFINE ADC_Sensor_Passenger                       sAN10
#DEFINE ADC_Vana_Current                           sAN11
#DEFINE ADC_Cam_Temiz_Hava_Current                 sAN15
//ADC**Channel*************************************************************************************************************************************//
#DEFINE CHANNEL_Vana_1                             1
#DEFINE CHANNEL_Vana_2                             2
#DEFINE CHANNEL_Cam_Pot                            3
#DEFINE CHANNEL_Temiz_Hava_Pot                     4               
#DEFINE CHANNEL_Sensor_Driver                      9
#DEFINE CHANNEL_Sensor_Passenger                   10
#DEFINE CHANNEL_Vana_Current                       11
#DEFINE CHANNEL_Cam_Temiz_Hava_Current             15
//Buttons******************************************************************************************************************************************//
#DEFINE BUT_ON_FAN                                 PIN_E7
#DEFINE BUT_MAX                                    PIN_E6
#DEFINE BUT_CAM                                    PIN_E5
#DEFINE BUT_YUZ                                    PIN_E1
#DEFINE BUT_KLIMA_FAN                              PIN_D3
#DEFINE BUT_INCREASE                               PIN_B0
#DEFINE BUT_ARKA_FAN                               PIN_G0
#DEFINE BUT_VANA_1                                 PIN_E4
#DEFINE BUT_VANA_2                                 PIN_E0
#DEFINE BUT_TEMIZ_HAVA                             PIN_E2
#DEFINE BUT_AC                                     PIN_E3
#DEFINE BUT_DECREASE                               PIN_A4
//Temiz**Hava**Pins********************************************************************************************************************************//
#DEFINE TEMIZ_HAVA_EN                              PIN_C7
#DEFINE TEMIZ_HAVA_IN_1                            PIN_B2
#DEFINE TEMIZ_HAVA_IN_2                            PIN_C6
#DEFINE TEMIZ_HAVA_POT                             PIN_A5
//CAM**Pins****************************************************************************************************************************************//
#DEFINE CAM_EN                                     PIN_B5
#DEFINE CAM_IN_1                                   PIN_B4
#DEFINE CAM_IN_2                                   PIN_B3
#DEFINE CAM_POT                                    PIN_A3
//VANA**1**Pins************************************************************************************************************************************//
#DEFINE VANA_1_EN                                  PIN_C3
#DEFINE VANA_1_IN_1                                PIN_A7
#DEFINE VANA_1_IN_2                                PIN_B1
#DEFINE VANA_1_POT                                 PIN_A1
//VANA**2**Pins************************************************************************************************************************************//
#DEFINE VANA_2_EN                                  PIN_C4
#DEFINE VANA_2_IN_1                                PIN_C5
#DEFINE VANA_2_IN_2                                PIN_A6
#DEFINE VANA_2_POT                                 PIN_A2
//PWM**********************************************************************************************************************************************//
#DEFINE PWM_1                                      PIN_C2
#DEFINE PWM_2                                      PIN_C1
//CANBUS*******************************************************************************************************************************************//
#DEFINE TXD                                        PIN_C0
#DEFINE RXD                                        PIN_A0
//CURRENT**CONTROL*********************************************************************************************************************************//
#DEFINE CURRENT_VANA                               PIN_F6
#DEFINE CURRENT_CAM_TEMIZ_HAVA                     PIN_G1
//SENSOR*******************************************************************************************************************************************//
#DEFINE SENSOR_DRIVER                              PIN_F4
#DEFINE SENSOR_PASSENGER                           PIN_F5
//KLIMA-POMPA**************************************************************************************************************************************//
#DEFINE KLIMA_FAN_1                                PIN_F3
#DEFINE KLIMA_FAN_2                                PIN_F2
#DEFINE KLIMA_FAN_3                                PIN_F7
#DEFINE POMPA_OUTPUT                               PIN_G3
//ERROR**Pins**************************************************************************************************************************************//
#DEFINE ERROR_1                                    PIN_A0
#DEFINE ERROR_2                                    PIN_C0
//KOMPRESOR-KONDANSER******************************************************************************************************************************//
#DEFINE KOMPRESOR                                  PIN_G4
#DEFINE KLIMA_SINYALI                              PIN_G2
//DISPLAY******************************************************************************************************************************************//
#DEFINE D_0                                        0x0000
#DEFINE D_H                                        0x0076
#DEFINE D_E                                        0x0079
#DEFINE D_L                                        0x0038
#DEFINE D_O                                        0x003F
#DEFINE D_b                                        0x007C
#DEFINE D_y                                        0x006E
//*************************************************************************************************************************************************//
//*************************************************************INTEGER**VARIABLEs******************************************************************//
//*************************************************************************************************************************************************//
//LED**VALUEs**************************************************************************************************************************************//
INT8 numbers[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x79,0x50,0x00};
INT16 display_hello[] = {D_0,D_H,D_E,D_L,D_L,D_O,D_0,D_0};
INT16 display_bye_bye[] = {D_0,D_0,D_b,D_y,D_E,D_0,D_b,D_y,D_E,D_0,D_0};
int8 digit_1                                       = 0;
INT8 digit_10                                      = 0;
INT8 counter_write_display                         = 0;
INT8 counter_write_led                             = 0;
INT8 counter_write_hello                           = 0;
INT8 counter_write_bye_bye                         = 0;
INT16 leds_register                                = 0x0000;
INT16 register_write_hello                         = 0x0000;
INT16 register_write_bye_bye                       = 0x0000;
INT16 display_register                             = 0x0000;
INT16 orrer_digit_1                                = 0x0000;
INT16 orrer_digit_10                               = 0x0000;
INT16 orrer_result                                 = 0x0000;
INT16 _16_bit_data_temporary                       = 0x0000;
//COUNTERs*****************************************************************************************************************************************//
INT8 counter_klima_fan                             = 0;
INT8 counter_on_fan                                = 0;
INT8 counter_arka_fan                              = 0;
INT8 counter_cam                                   = 0;
INT8 counter_temiz_hava                            = 0;
INT8 counter_vana_1                                = 0;
INT8 counter_vana_2                                = 0;
INT8 counter_auto_mode                             = 0;
INT8 counter_max                                   = 0;
//EEPROM**ADDRESS**DATAs***************************************************************************************************************************//
INT8 address_cam                                   = 1;
INT8 address_temiz_hava                            = 2;
INT8 address_vana_1                                = 3;
INT8 address_vana_2                                = 4;
INT8 address_sensor_driver_set_temp                = 5;
INT8 address_sensor_passenger_set_temp             = 6;
INT8 address_auto_mode                             = 7;
//TEMPERATURE**VARIABLEs***************************************************************************************************************************//
SIGNED INT16 sensor_driver_temp                    = 0;
SIGNED INT16 sensor_passenger_temp                 = 0;
SIGNED INT16 sensor_driver_set_temp                = 24;
SIGNED INT16 sensor_passenger_set_temp             = 22;
SIGNED INT16 temp_1                                = -12;
SIGNED INT16 temp_2                                = 0;
SIGNED INT16 temp_3                                = -12;
SIGNED INT16 temp_4                                = 0;
//ADC**VARIABLEs***********************************************************************************************************************************//
INT16 motor_pot_cam                                = 0;
INT16 motor_pot_temiz_hava                         = 0;
INT16 motor_pot_vana_1                             = 0;
INT16 motor_pot_vana_2                             = 0;
INT16 current_temiz_hava_cam                       = 0;
INT16 current_vana_value                           = 0;
INT16 sensor_driver_value                          = 0;
INT16 sensor_passenger_value                       = 0;
INT32 register_adc                                 = 0x00000000;
//SCAN**KLAPE**POT**VARIABLEs**********************************************************************************************************************//
INT16 orta_cam                                     = 0;
INT16 min_cam                                      = 0;
INT16 max_cam                                      = 0;
INT16 min_temiz_hava                               = 0;
INT16 max_temiz_hava                               = 0;
INT16 min_vana_1                                   = 0;
INT16 max_vana_1                                   = 0;
INT16 orta_vana_1                                  = 0;
INT16 min_vana_2                                   = 0;
INT16 max_vana_2                                   = 0;
INT16 orta_vana_2                                  = 0;
//PWM**VARIABLEs***********************************************************************************************************************************//
INT16 value_pwm1                                   = 0;
INT16 value_pwm2                                   = 0;
//KLAPE**CONTROL**FUNCTION**VARIABLEs**************************************************************************************************************//
INT8 cam_test                                      = 0;
INT8 temiz_hava_test                               = 0;
INT8 vana_1_test                                   = 0;
INT8 vana_2_test                                   = 0;
INT16 value_2_klape_control_cam                    = 0;
INT16 value_1_klape_control_cam                    = 0;
INT16 value_2_klape_control_temiz_hava             = 0;
INT16 value_1_klape_control_temiz_hava             = 0;
INT16 value_2_klape_control_vana_1                 = 0;
INT16 value_1_klape_control_vana_1                 = 0;
INT16 value_2_klape_control_vana_2                 = 0;
INT16 value_1_klape_control_vana_2                 = 0;
//CONTROLLER**FUNCTIONS**VARIABLEs*****************************************************************************************************************//
INT8 counter_klima_fan_old                         = 0;
INT8 counter_on_fan_old                            = 0;
INT8 counter_arka_fan_old                          = 0;
INT8 counter_cam_old                               = 0;
INT8 counter_temiz_hava_old                        = 0;
INT8 counter_vana_1_old                            = 0;
INT8 counter_vana_2_old                            = 0;
//*************************************************************************************************************************************************//
INT16 reverse_value                                = 0;
//CONTROLLER**KLAPE**ERROR**VARIABLEs**************************************************************************************************************//
INT32 counter_controller_klape_error_cam           = 0;
INT32 counter_controller_klape_error_temiz_hava    = 0;
INT32 counter_controller_klape_error_vana_1        = 0;
INT32 counter_controller_klape_error_vana_2        = 0;
INT32 counter_klape_error_cam                      = 0;
INT32 counter_klape_error_temiz_hava               = 0;
INT32 counter_klape_error_vana_1                   = 0;
INT32 counter_klape_error_vana_2                   = 0;
INT32 counter_decrease                             = 0;
//CONTROLLER**ERROR**VARIABLEs*********************************************************************************************************************//
INT16 counter_error                                = 0;
INT16 counter_controller_error                     = 0;
INT16 counter_write_eeprom_auto_mode               = 0;
//AC**ONER**VARIABLEs******************************************************************************************************************************//
INT16 counter_ac_oner                              = 0;
//*************************************************************************************************************************************************//
INT8 counter_on_fan_before                         = 0;
INT8 counter_cam_before                            = 0;
INT8 counter_temiz_hava_before                     = 0;
INT8 counter_vana_1_before                         = 0;
//*************************************************************************************************************************************************//
//*************************************************************BOOLEAN**VARIABLEs******************************************************************//
//*************************************************************************************************************************************************//
//CONTROLLER**KLAPE**VARIABLEs*********************************************************************************************************************//
BOOLEAN state_error_cam                            = FALSE;
BOOLEAN state_error_temiz_hava                     = FALSE;
BOOLEAN state_error_vana_1                         = FALSE;
BOOLEAN state_error_vana_2                         = FALSE;
BOOLEAN state_controller_klape_error_cam           = FALSE;
BOOLEAN state_controller_klape_error_temiz_hava    = FALSE;
BOOLEAN state_controller_klape_error_vana_1        = FALSE;
BOOLEAN state_controller_klape_error_vana_2        = FALSE;
//BUTON**CONTROLLER**VARIABLEs*********************************************************************************************************************//
BOOLEAN state_button_klima_fan                     = TRUE;
BOOLEAN state_button_on_fan                        = TRUE;
BOOLEAN state_button_arka_fan                      = TRUE;
BOOLEAN state_button_cam                           = TRUE;
BOOLEAN state_button_yuz                           = TRUE;
BOOLEAN state_button_temiz_hava                    = TRUE;
BOOLEAN state_button_vana_1                        = TRUE;
BOOLEAN state_button_vana_2                        = TRUE;
BOOLEAN state_button_max                           = TRUE;
BOOLEAN state_button_auto_mode                     = TRUE;
BOOLEAN state_button_increase                      = TRUE;
BOOLEAN state_button_decrease                      = TRUE;
BOOLEAN state_counter_ac_and_max_once_make_zero    = TRUE;
BOOLEAN state_ac_button                            = FALSE;
//ERROR**CONTROLLER**VARIABLEs*********************************************************************************************************************//
BOOLEAN state_error_sensor_driver                  = FALSE;
BOOLEAN state_error_sensor_passenger               = FALSE;
BOOLEAN state_error_yuksek_basinc                  = FALSE;
//CHECK**CHANGABLE**VARIABLEs**********************************************************************************************************************//
BOOLEAN state_check_manuel_klima_fan               = FALSE;
BOOLEAN state_check_manuel_on_fan                  = FALSE;
BOOLEAN state_check_manuel_arka_fan                = FALSE;
BOOLEAN state_check_manuel_vana_1                  = FALSE;
BOOLEAN state_check_manuel_vana_2                  = FALSE;
//CHECK**VARIABLEs*********************************************************************************************************************************//
BOOLEAN state_check_once_controller_functions      = TRUE;
//CHECK**TEMPERATURE**VARIABLEs********************************************************************************************************************//
BOOLEAN state_sensor_driver_temp                   = FALSE;
BOOLEAN state_sensor_driver_temp_inner             = TRUE;
BOOLEAN state_sensor_driver_temp_minus             = FALSE;
BOOLEAN state_sensor_driver_temp_plus              = FALSE;
BOOLEAN state_sensor_passenger_temp                = FALSE;
BOOLEAN state_sensor_passenger_temp_inner          = TRUE;
BOOLEAN state_sensor_passenger_temp_minus          = FALSE;
BOOLEAN state_sensor_passenger_temp_plus           = FALSE;
//AC**MODE**VARIABLEs******************************************************************************************************************************//
BOOLEAN state_once_ac_mode_in_sensor_driver_error     = TRUE;
BOOLEAN state_once_ac_mode_in_sensor_passenger_error  = TRUE;
BOOLEAN state_check_once_entrance_to_ac               = TRUE;
BOOLEAN state_ac_oner                                 = FALSE;
//INCREASE**DECREASE**VARIABLEs********************************************************************************************************************//
BOOLEAN state_set_temp_show_only_once_at_main      = TRUE;
//REVERSE**CONTROL**IN**SCAN**KLAPE**POT**VARIABLEs************************************************************************************************//
BOOLEAN state_correct_direction_cam                = TRUE;
BOOLEAN state_correct_direction_temiz_hava         = TRUE;
BOOLEAN state_correct_direction_vana_1             = TRUE;
BOOLEAN state_correct_direction_vana_2             = TRUE;
//CONTROLLER**FUNCTIONS**VARIABLEs*****************************************************************************************************************//
BOOLEAN state_turn_complete_cam                    = FALSE;
BOOLEAN state_turn_complete_temiz_hava             = FALSE;
BOOLEAN state_turn_complete_vana_1                 = FALSE;
BOOLEAN state_turn_complete_vana_2                 = FALSE;
//SCAN**KLAPE**POT**VARIABLEs**********************************************************************************************************************//
BOOLEAN state_scan_klape_pot                       = TRUE;
//SETTING**KLIMA***********************************************************************************************************************************//
BOOLEAN state_kompressor                           = FALSE;
BOOLEAN state_klima_driver                         = FALSE;
BOOLEAN state_klima_passenger                      = FALSE;
BOOLEAN state_klima_fan_once                       = FALSE;
BOOLEAN state_klima_heating                        = FALSE;
//SERVICE**MODE************************************************************************************************************************************//
BOOLEAN state_increase_service_mode                = FALSE;
BOOLEAN state_increase_service_mode_worked         = FALSE;
//SERVICE**MODE************************************************************************************************************************************//
BOOLEAN state_auto_mode_passenger_equal            = FALSE;
//SERVICE**MODE************************************************************************************************************************************//
BOOLEAN state_max_on_in_auto_mode                  = FALSE;
BOOLEAN state_button_max_counter_before            = FALSE;
//*************************************************************************************************************************************************//
//******************************************************************FUNCTIONs**********************************************************************//
//*************************************************************************************************************************************************//
//MAIN**FUNCTIONs**********************************************************************************************************************************//
VOID Setting();
VOID Controller_Klape();
VOID Scan_Klape_Pot();
VOID Controller_Klape_Error();
VOID Make_Default_Value();
VOID Read_Value_From_EEPROM();
VOID Work_According_To_EEPROM_Value();
VOID Controller_Error_In_Main();
//BUTTON**FUNCTIONs********************************************************************************************************************************//
VOID Button_Controller_Klima_Fan();
VOID Button_Controller_On_Fan();
VOID Button_Controller_Arka_Fan();
VOID Button_Controller_Cam();
VOID Button_Controller_Temiz_Hava();
VOID Button_Controller_Vana_1();
VOID Button_Controller_Vana_2();
VOID Button_Controller_Max();
VOID Button_Controller_AC();
VOID Button_Controller_Increase_Decrease();
//CONTROLLER**FUNCTIONs****************************************************************************************************************************//
VOID Controller_Klima_Fan();
VOID Controller_On_Fan();
VOID Controller_Arka_Fan();
VOID Controller_Cam_Yuz();
VOID Controller_Temiz_Hava();
VOID Controller_Vana_1();
VOID Controller_Vana_2();
VOID Controller_Auto_Mode();
VOID Controller_Max();
VOID Controller_AC_Led();
VOID Controller_Error();
VOID Controller_Klape();
VOID Controller_Klape_Error();
VOID Controller_Functions();
//READ**ADC**FUNCTIONs*****************************************************************************************************************************//
VOID Read_Temp();
VOID Read_Motor_Cam();
VOID Read_Motor_Temiz_Hava();
VOID Read_Motor_Vana_1();
VOID Read_Motor_Vana_2();
VOID Read_Current_Temiz_Hava_Cam();
VOID Read_Current_Vana();
//MOTOR**MOVEMENT**FUNCTIONs***********************************************************************************************************************//
VOID Turn_Right_Cam();
VOID Turn_Left_Cam();
VOID Stop_Cam();
VOID Turn_Right_Temiz_Hava();
VOID Turn_Left_Temiz_Hava();
VOID Stop_Temiz_Hava();
VOID Turn_Right_Vana_1();
VOID Turn_Left_Vana_1();
VOID Stop_Vana_1();
VOID Turn_Right_Vana_2();
VOID Turn_Left_Vana_2();
VOID Stop_Vana_2();
//AC**FUNCTIONs************************************************************************************************************************************//
VOID AC_ONer();
VOID AC_Mode_In_Sensor_Driver_Error();
VOID AC_Mode_In_Sensor_Passenger_Error();
VOID Compare_Temp_And_Set_Temp();
//KLIMA-POMPA**FUNCTIONs***************************************************************************************************************************//
VOID Setting_Pompa();
VOID Setting_Klima();
VOID Setting_In_Sensor_Driver_Error();
VOID Setting_In_Sensor_Passenger_Error();
//DISPLAY-LED**FUNCTIONs***************************************************************************************************************************//
VOID ONer(INT16);
VOID OFFer(INT16);
VOID Write_Led(INT16);
VOID Write_Display(INT16);
VOID Write_Hello();
VOID Write_Bye_Bye();
INT16 ORer_Two_Number(INT8,INT8);
INT16 Change_8_Bits_Of_16_Bit_Data(INT16);
//SERVICE**MODE**FUNCTIONs*************************************************************************************************************************//
VOID Service_Mode_Increase();
//*************************************************************************************************************************************************//
//*****************************************************************SETTING*************************************************************************//
//*************************************************************************************************************************************************//
   VOID Setting(){
//Setting I/O Ports********************************************************************************************************************************//
      OUTPUT_F(0x00);
      OUTPUT_A(0x00);
      OUTPUT_B(0x00);
      OUTPUT_C(0x00);
      OUTPUT_D(0x00);
      OUTPUT_E(0x00);
      OUTPUT_G(0x00);
      OFFer(0x0000);
      Write_Display(0x0000);
      DELAY_MS(1000);
      SET_TRIS_A(0X3F);
      SET_TRIS_B(0X01);
      SET_TRIS_C(0X01);
      SET_TRIS_D(0X08);
      SET_TRIS_E(0xF7);
      OUTPUT_LOW(KLIMA_FAN_2);
      OUTPUT_F(0x00);
      SET_TRIS_G(0X03);
//Setting PWM_1************************************************************************************************************************************//
      OUTPUT_LOW(PWM_1);
      SETUP_CCP1(CCP_PWM);
      SETUP_TIMER_2(T2_DIV_BY_1, 255, 1);
      SETUP_OSCILLATOR(0x7A);
      SETUP_CCP1(CCP_OFF);
      DELAY_MS(100);
//Setting PWM_2************************************************************************************************************************************//
      OUTPUT_LOW(PWM_2);
      SETUP_CCP2(CCP_PWM);
      SETUP_TIMER_2(T2_DIV_BY_1, 255, 1);
      SETUP_OSCILLATOR(0x7A);
      SETUP_CCP2(CCP_OFF);
      DELAY_MS(100);
//Setting ADC Ports********************************************************************************************************************************//
      register_adc = register_adc | ADC_Cam_Pot;
      register_adc = register_adc | ADC_Temiz_Hava_Pot;
      register_adc = register_adc | ADC_Vana_1;
      register_adc = register_adc | ADC_Vana_2;
      register_adc = register_adc | ADC_Cam_Temiz_Hava_Current;
      register_adc = register_adc | ADC_Vana_Current;
      register_adc = register_adc | ADC_Sensor_Driver;
      register_adc = register_adc | ADC_Sensor_Passenger;
      register_adc = register_adc | VSS_VDD;
      SETUP_ADC_PORTS(register_adc);
      SETUP_ADC(RTCC_INTERNAL|ADC_CLOCK_DIV_8);
      DELAY_MS(100);
      ONer(0xFFFF);
      Write_Display(0x4040);
      OUTPUT_HIGH(KLIMA_FAN_3_ON);
      OUTPUT_HIGH(VANA_1_1_ON);
      OUTPUT_HIGH(VANA_1_2_ON);
      DELAY_MS(4000);
      #USE STANDARD_IO(A)
      #USE STANDARD_IO(B)
      #USE STANDARD_IO(C)
      #USE STANDARD_IO(D)
      #USE STANDARD_IO(E)
      #USE STANDARD_IO(F)
      #USE STANDARD_IO(G)
   }
//*************************************************************************************************************************************************//
//******************************************************************KLAPE**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Klape(){
//************************************************************************CAM**********************************************************************//
      Write_Display(ORer_Two_Number(numbers[0],numbers[8]));
      Turn_Right_Cam();
      DELAY_MS(200);
      FOR(cam_test = 0; cam_test < 50; cam_test++){
         Turn_Right_Cam();
         DELAY_MS(50);
         Read_Current_Temiz_Hava_Cam();
         IF(current_temiz_hava_cam > 45){
            Stop_Cam();
            cam_test = 50;
         }
      }
      Stop_Cam();
      DELAY_MS(100);
      Read_Motor_Cam();
      value_1_klape_control_cam = motor_pot_cam;
      Turn_Left_Cam();
      DELAY_MS(200);
      FOR(cam_test = 0; cam_test < 50; cam_test++){
         Turn_Left_Cam();
         DELAY_MS(50);
         Read_Current_Temiz_Hava_Cam();
         IF(current_temiz_hava_cam > 45){
            Stop_Cam();
            cam_test = 50;
         }
      }
      Stop_Cam();
      DELAY_MS(100);
      Read_Motor_Cam();
      value_2_klape_control_cam = motor_pot_cam;
      IF(abs(value_1_klape_control_cam - value_2_klape_control_cam) < 50){
         state_error_cam = TRUE;
         state_controller_klape_error_cam = TRUE;
      }
//********************************************************************TEMIZ**HAVA******************************************************************//
      Write_Display(ORer_Two_Number(numbers[0],numbers[7]));
      Turn_Right_Temiz_Hava();
      DELAY_MS(200);
      FOR(temiz_hava_test = 0; temiz_hava_test < 50; temiz_hava_test++){
         Turn_Right_Temiz_Hava();
         DELAY_MS(50);
         Read_Current_Temiz_Hava_Cam();
         IF(current_temiz_hava_cam > 75){
            Stop_Temiz_Hava();
            temiz_hava_test = 50;
         }
      }
      Stop_Temiz_Hava();
      DELAY_MS(100);
      Read_Motor_Temiz_Hava();
      value_1_klape_control_temiz_hava = motor_pot_temiz_hava;
      Turn_Left_Temiz_Hava();
      DELAY_MS(200);
      FOR(temiz_hava_test = 0;temiz_hava_test < 50; temiz_hava_test++){
         Turn_Left_Temiz_Hava();
         DELAY_MS(50);
         Read_Current_Temiz_Hava_Cam();
         IF(current_temiz_hava_cam > 75){
            Stop_Temiz_Hava();
            temiz_hava_test = 50;
         }
      }
      Stop_Temiz_Hava();
      DELAY_MS(100);
      Read_Motor_Temiz_Hava();
      value_2_klape_control_temiz_hava = motor_pot_temiz_hava;
      IF(abs(value_1_klape_control_temiz_hava - value_2_klape_control_temiz_hava) < 50){
         state_error_temiz_hava = TRUE;
         state_controller_klape_error_temiz_hava = TRUE;
      }
//*********************************************************************VANA**1*********************************************************************//
      SET_TRIS_F(0XF0);
      OUTPUT_LOW(PIN_F3);
      OUTPUT_LOW(PIN_F2);
      OUTPUT_LOW(PIN_F7);
      Turn_Right_Vana_1();
      Write_Display(ORer_Two_Number(numbers[0],numbers[6]));
      DELAY_MS(200);
      FOR(vana_1_test = 0; vana_1_test < 50; vana_1_test++){
         Turn_Right_Vana_1();
         DELAY_MS(50);
         Read_Current_Vana();
         IF(current_vana_value > 45){
            Stop_Vana_1();
            vana_1_test = 50;
         }
      }
      Stop_Vana_1();
      DELAY_MS(100);
      Read_Motor_Vana_1();
      value_1_klape_control_vana_1 = motor_pot_vana_1;
      Turn_Left_Vana_1();
      DELAY_MS(200);
      FOR(vana_1_test = 0; vana_1_test < 50; vana_1_test++){
         Turn_Left_Vana_1();
         DELAY_MS(50);
         Read_Current_Vana();
         IF(current_vana_value > 45){
            Stop_Vana_1();
            vana_1_test = 50;
         }
      }
      Stop_Vana_1();
      DELAY_MS(100);
      Read_Motor_Vana_1();
      value_2_klape_control_vana_1 = motor_pot_vana_1;
      IF(abs(value_1_klape_control_vana_1 - value_2_klape_control_vana_1) < 50){
         state_error_vana_1 = TRUE;
         state_controller_klape_error_vana_1 = TRUE;
         counter_vana_1 = 0;
      }
//*********************************************************************VANA**2*********************************************************************//
      Write_Display(ORer_Two_Number(numbers[0],numbers[5]));
      Turn_Right_Vana_2();
      DELAY_MS(200);
      FOR(vana_2_test = 0; vana_2_test < 50; vana_2_test++){
         Turn_Right_Vana_2();
         DELAY_MS(50);
         Read_Current_Vana();
         IF(current_vana_value > 45){
            Stop_Vana_2();
            vana_2_test = 50;
         }
      }
      Stop_Vana_2();
      DELAY_MS(100);
      Read_Motor_Vana_2();
      value_1_klape_control_vana_2 = motor_pot_vana_2;
      Turn_Left_Vana_2();
      DELAY_MS(200);
      FOR(vana_2_test = 0;vana_2_test < 50; vana_2_test++){
         Turn_Left_Vana_2();
         DELAY_MS(40);
         Read_Current_Vana();
         IF(current_vana_value > 45){
            Stop_Vana_2();
            vana_2_test = 50;
         }
      }
      Stop_Vana_2();
      DELAY_MS(100);
      Read_Motor_Vana_2();
      value_2_klape_control_vana_2 = motor_pot_vana_2;
      IF(abs(value_1_klape_control_vana_2 - value_2_klape_control_vana_2) < 50){
         state_error_vana_2 = TRUE;
         state_controller_klape_error_vana_2 = TRUE;
         counter_vana_2 = 0;
      }
      DELAY_MS(200);
   }
//*************************************************************************************************************************************************//
//********************************************************************SCANNING*********************************************************************//
//*************************************************************************************************************************************************//
   VOID Scan_Klape_Pot(){
//*********************************************************************CAM*************************************************************************//
      Write_Display(ORer_Two_Number(numbers[0],numbers[4]));
      IF(!state_error_cam){
         state_scan_klape_pot = TRUE;
         Turn_Right_Cam();
         DELAY_MS(200);
         WHILE(state_scan_klape_pot){
            Turn_Right_Cam();
            DELAY_MS(50);
            Read_Current_Temiz_Hava_Cam();
            IF(current_temiz_hava_cam > 45){
               state_scan_klape_pot = FALSE;
               Stop_Cam();
            }
         }
         DELAY_MS(50);
         Read_Motor_Cam();
         max_cam = motor_pot_cam;
         state_scan_klape_pot = TRUE;
         Turn_Left_Cam();
         DELAY_MS(200);
         WHILE(state_scan_klape_pot){
            Turn_Left_Cam();
            DELAY_MS(50);
            Read_Current_Temiz_Hava_Cam();
            IF(current_temiz_hava_cam > 45){
               state_scan_klape_pot = FALSE;
               Stop_Cam();
            }
         }
         DELAY_MS(50);
         Read_Motor_Cam();
         min_cam = motor_pot_cam;
      }
//*******************************************************************TEMIZ**HAVA*******************************************************************//
      Write_Display(ORer_Two_Number(numbers[0],numbers[3]));
      IF(!state_error_temiz_hava){ 
         state_scan_klape_pot = TRUE;
         Turn_Right_Temiz_Hava();
         DELAY_MS(200);
         WHILE(state_scan_klape_pot){
            Turn_Right_Temiz_Hava();
            DELAY_MS(50);
            Read_Current_Temiz_Hava_Cam();
            IF(current_temiz_hava_cam > 75){
               state_scan_klape_pot = FALSE;
               Stop_Temiz_Hava();
            }
         }
         DELAY_MS(50);
         Read_Motor_Temiz_Hava();
         max_temiz_Hava = motor_pot_temiz_Hava;
         state_scan_klape_pot = TRUE;
         Turn_Left_Temiz_Hava();
         DELAY_MS(200);
         WHILE(state_scan_klape_pot){
            Turn_Left_Temiz_Hava();
            DELAY_MS(50);
            Read_Current_Temiz_Hava_Cam();
            IF(current_temiz_hava_cam > 75){
               state_scan_klape_pot = FALSE;
               Stop_Temiz_Hava();
            }
         }
         DELAY_MS(50);
         Read_Motor_Temiz_Hava();
         min_temiz_Hava = motor_pot_temiz_Hava;
      }

//**********************************************************************VANA**1********************************************************************//
      Write_Display(ORer_Two_Number(numbers[0],numbers[2]));
      IF(!state_error_vana_1){
         state_scan_klape_pot = TRUE;
         Turn_Right_Vana_1();
         DELAY_MS(200);
         WHILE(state_scan_klape_pot){
            Turn_Right_Vana_1();
            DELAY_MS(50);
            Read_Current_Vana();
            IF(current_vana_value > 45){
               state_scan_klape_pot = FALSE;
               Stop_Vana_1();
            }
         }
         DELAY_MS(50);
         Read_Motor_Vana_1();
         max_vana_1 = motor_pot_vana_1;
         state_scan_klape_pot = TRUE;
         Turn_Left_Vana_1();
         DELAY_MS(200);
         WHILE(state_scan_klape_pot){
            Turn_Left_Vana_1();
            DELAY_MS(50);
            Read_Current_Vana();
            IF(current_vana_value > 45){
               state_scan_klape_pot = FALSE;
               Stop_Vana_1();
            }
         }
         DELAY_MS(50);
         Read_Motor_Vana_1();
         min_vana_1 = motor_pot_vana_1;
      }
//************************************************************************VANA**2******************************************************************//
      Write_Display(ORer_Two_Number(numbers[0],numbers[1]));
     IF(!state_error_vana_2){
        state_scan_klape_pot = TRUE;
        Turn_Left_Vana_2();
        DELAY_MS(200);
        WHILE(state_scan_klape_pot){
            Turn_Left_Vana_2();
            DELAY_MS(50);
            Read_Current_Vana();
            IF(current_vana_value > 45){
               state_scan_klape_pot = FALSE;
               Stop_Vana_2();
            }
         }
         DELAY_MS(50);
         Read_Motor_Vana_2();
         max_vana_2 = motor_pot_vana_2;
         state_scan_klape_pot = TRUE;
         Turn_Right_Vana_2();
         DELAY_MS(200);
         WHILE(state_scan_klape_pot){
            Turn_Right_Vana_2();
            DELAY_MS(50);
            Read_Current_Vana();
            IF(current_vana_value > 45){
               state_scan_klape_pot = FALSE;
               Stop_Vana_2();
            }
         }
         DELAY_MS(50);
         Read_Motor_Vana_2();
         min_vana_2 = motor_pot_vana_2;
     }
//****************************************************************REVERSE**CONTROL***************************************************************** //
      IF(min_cam > max_cam){
         state_correct_direction_cam = FALSE;
         reverse_value = max_cam;
         max_cam = min_cam;
         min_cam = reverse_value;
      }
      IF(min_temiz_hava > max_temiz_hava){
         state_correct_direction_temiz_hava = FALSE;
         reverse_value = max_temiz_hava;
         max_temiz_hava = min_temiz_hava;
         min_temiz_hava = reverse_value;
      }
      IF(min_vana_1 > max_vana_1){
         state_correct_direction_vana_1 = FALSE;
         reverse_value = max_vana_1;
         max_vana_1 = min_vana_1;
         min_vana_1 = reverse_value;
      }
      IF(min_vana_2 > max_vana_2){
         state_correct_direction_vana_2 = FALSE;
         reverse_value = max_vana_2;
         max_vana_2 = min_vana_2;
         min_vana_2 = reverse_value;
      }
//*******************************************************************MID**VALUE********************************************************************//
      IF(!state_error_cam){
         orta_cam = (max_cam + min_cam) / 2;
      }
      IF(!state_error_vana_1){
         orta_vana_1 = ((4 * max_vana_1) + min_vana_1) / 5;
      }
      IF(!state_error_vana_2){
         orta_vana_2 = ((4 * max_vana_2) + min_vana_2) / 5;
      }
   }
//*************************************************************************************************************************************************//
//***********************************************************CONTROL**KLAPE**MOTOR**ERROR**********************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Klape_Error(){
      Write_Display(0x4040);
      WHILE(state_controller_klape_error_cam){
         counter_controller_klape_error_cam++;
         IF(counter_controller_klape_error_cam == 10000){
            ONer(CAM_ON);
         }
         IF(counter_controller_klape_error_cam == 20000){
            OFFer(CAM_DEFAULT);
            counter_controller_klape_error_cam = 0;
         }
         WHILE(!INPUT(BUT_CAM)){
            counter_klape_error_cam++;
            IF(counter_klape_error_cam == 200000){
               state_controller_klape_error_cam = FALSE;
               OFFer(CAM_DEFAULT);
            }
         }
      }
      WHILE(state_controller_klape_error_temiz_hava){
         counter_controller_klape_error_temiz_hava++;
         IF(counter_controller_klape_error_temiz_hava == 10000){
            ONer(TEMIZ_HAVA_ON);
         }
         IF(counter_controller_klape_error_temiz_hava == 20000){
            OFFer(TEMIZ_HAVA_DEFAULT);
            counter_controller_klape_error_temiz_hava = 0;
         }
         WHILE(!INPUT(BUT_TEMIZ_HAVA)){
            counter_klape_error_temiz_hava++;
            IF(counter_klape_error_temiz_hava == 200000){
               state_controller_klape_error_temiz_hava = FALSE;
               OFFer(TEMIZ_HAVA_DEFAULT);
            }
         }
      }
      WHILE(state_controller_klape_error_vana_1){
         counter_controller_klape_error_vana_1++;
            IF(counter_controller_klape_error_vana_1 == 10000){
               OUTPUT_HIGH(VANA_1_1_ON);
               OUTPUT_HIGH(VANA_1_2_ON);
               ONer(VANA_1_3_ON);
            }
            IF(counter_controller_klape_error_vana_1 == 20000){
               OFFer(VANA_1_DEFAULT);
               OUTPUT_LOW(VANA_1_1_ON);
               OUTPUT_LOW(VANA_1_2_ON);
               counter_controller_klape_error_vana_1 = 0;
            }
         WHILE(!INPUT(BUT_VANA_1)){
            counter_klape_error_vana_1++;
            IF(counter_klape_error_vana_1 == 200000){
               state_controller_klape_error_vana_1 = FALSE;
               OFFer(VANA_1_DEFAULT);
               OUTPUT_LOW(VANA_1_1_ON);
               OUTPUT_LOW(VANA_1_2_ON);
            }
         }
      }
      WHILE(state_controller_klape_error_vana_2){
         counter_controller_klape_error_vana_2++;
         IF(counter_controller_klape_error_vana_2 == 10000){
            ONer(VANA_2_1_ON);
            ONer(VANA_2_2_ON);
            ONer(VANA_2_3_ON);
         }
         IF(counter_controller_klape_error_vana_2 == 20000){
            OFFer(VANA_2_DEFAULT);
            counter_controller_klape_error_vana_2 = 0;
         }
         WHILE(!INPUT(BUT_VANA_2)){
            counter_klape_error_vana_2++;
            IF(counter_klape_error_vana_2 == 200000){
               state_controller_klape_error_vana_2 = FALSE;
               OFFer(VANA_2_DEFAULT);
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
      OFFer(0x0000);
      OUTPUT_LOW(VANA_1_1_ON);
      OUTPUT_LOW(VANA_1_2_ON);
      OUTPUT_LOW(KLIMA_FAN_3_ON);
      OFFer(VANA_2_DEFAULT);
      OFFer(AC_DEFAULT);
      OFFer(VANA_1_DEFAULT);
      OUTPUT_LOW(VANA_1_1_ON);
      OUTPUT_LOW(VANA_1_2_ON);
      display_register = ORer_Two_Number(numbers[12],numbers[12]);
      Write_Display(display_register);
      counter_klima_fan_old = 0;
      counter_on_fan_old = 0;
      counter_arka_fan_old = 0;
      counter_cam_old = 0;
      counter_temiz_hava_old = 0;
      counter_vana_1_old = 0;
      counter_vana_2_old = 0;
      value_pwm1 = 0;
      value_pwm2 = 0;
      counter_error = 0;
      counter_klima_fan = 0;
      counter_max = 0;
      counter_auto_mode = 0;
   }
//*************************************************************************************************************************************************//
//*************************************************READ**VALUE**WHEN**BEFORE**SHUTDOWN**FROM**EEPROM***********************************************//
//*************************************************************************************************************************************************//
   VOID Read_Value_From_EEPROM(){
      IF(!state_error_cam){
         counter_cam = READ_EEPROM(address_cam);
      }
      IF(!state_error_temiz_hava){
         counter_temiz_hava = READ_EEPROM(address_temiz_hava);
      }
      IF(!state_error_vana_1){
         counter_vana_1 = READ_EEPROM(address_vana_1);
      }
      IF(!state_error_vana_2){
         counter_vana_2 = READ_EEPROM(address_vana_2);
      }
      sensor_driver_set_temp = READ_EEPROM(address_sensor_driver_set_temp);
      sensor_passenger_set_temp = READ_EEPROM(address_sensor_passenger_set_temp);
      counter_klima_fan = 0;
      counter_on_fan = 0;
      counter_arka_fan = 0;
      counter_auto_mode = 0;
      counter_max = 0;
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
      Controller_Vana_2();
      Button_Controller_Increase_Decrease();
   }
//*************************************************************************************************************************************************//
//************************************************************CONTROLLER**ERROR**IN**MAIN**********************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Error_In_Main(){
      SET_ADC_CHANNEL(CHANNEL_Sensor_Driver);
      DELAY_MS(20);
      sensor_driver_value = READ_ADC();
      IF(sensor_driver_value < 30){
         state_error_sensor_driver = TRUE;
      }
      ELSE{
         state_error_sensor_driver = FALSE;
      }
      SET_ADC_CHANNEL(CHANNEL_Sensor_Passenger);
      DELAY_MS(20);
      sensor_passenger_value = READ_ADC();
      IF(sensor_passenger_value < 30){
         state_error_sensor_passenger = TRUE;
      }
      ELSE{
         state_error_sensor_passenger = FALSE;
      }
      Read_Temp();
   }
//*************************************************************************************************************************************************//
//***************************************************************CONTROLLER**FUNCTIONS*************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Functions(){
      IF(!(counter_klima_fan == counter_klima_fan_old)){
         Controller_Klima_Fan();
         counter_klima_fan_old = counter_klima_fan;
      }
      IF(!(counter_on_fan == counter_on_fan_old)){
         Controller_On_Fan();
         counter_on_fan_old = counter_on_fan;
      }
      IF(!(counter_arka_fan == counter_arka_fan_old)){
         Controller_Arka_Fan();
         counter_arka_fan_old = counter_arka_fan;
      }
      IF(!(counter_cam == counter_cam_old)){
         state_turn_complete_cam = FALSE;
         counter_cam_old = counter_cam;
      }
      IF(!state_turn_complete_cam){
         Controller_Cam_Yuz();
      }
      IF(!(counter_temiz_hava == counter_temiz_hava_old)){
         state_turn_complete_temiz_hava = FALSE;
         counter_temiz_hava_old = counter_temiz_hava;
      }
      IF(!state_turn_complete_temiz_hava){
         Controller_Temiz_Hava();
      }
      IF(!(counter_vana_1 == counter_vana_1_old)){
         state_turn_complete_vana_1 = FALSE;
         counter_vana_1_old = counter_vana_1;
      }
      IF(!state_turn_complete_vana_1){
         Controller_Vana_1();
      }
      IF(!(counter_vana_2 == counter_vana_2_old)){
         state_turn_complete_vana_2 = FALSE;
         counter_vana_2_old = counter_vana_2;
      }
      IF(!state_turn_complete_vana_2){
         Controller_Vana_2();
      }
   }
//*************************************************************************************************************************************************//
//*****************************************************************SETTING**POMPOUT****************************************************************//
//*************************************************************************************************************************************************//
   VOID Setting_Pompa(){
      IF((state_error_vana_1) && (state_error_vana_2)){
         OUTPUT_LOW(POMPA_OUTPUT);
      }
      IF((!state_error_vana_1) && (state_error_vana_2)){
         IF((counter_vana_1 % 3) == 0){
            OUTPUT_LOW(POMPA_OUTPUT);
         }
         ELSE{
            OUTPUT_HIGH(POMPA_OUTPUT);
         }
      }
      IF((state_error_vana_1) && (!state_error_vana_2)){
         IF((counter_vana_2 % 3) == 0){
            OUTPUT_LOW(POMPA_OUTPUT);
         }
         ELSE{
            OUTPUT_HIGH(POMPA_OUTPUT);
         }
      }
      IF((!state_error_vana_1) && (!state_error_vana_2)){
         IF(((counter_vana_1 % 3) == 0) && ((counter_vana_2 % 3) == 0)){
            OUTPUT_LOW(POMPA_OUTPUT);
         }
         ELSE{
            OUTPUT_HIGH(POMPA_OUTPUT);
         }
      }
   }
//*************************************************************************************************************************************************//
//*******************************************************KLIMA**SINYALI**KOMPRESSOR**IN**CHECK*****************************************************//
//*************************************************************************************************************************************************//
   VOID Setting_Klima(){
      IF(!state_error_yuksek_basinc){
         IF(((state_klima_driver) || (state_klima_passenger))){
            OUTPUT_HIGH(KOMPRESOR);
            state_kompressor = TRUE;
            IF(state_klima_passenger){
               state_klima_heating = TRUE;
            }
            IF((state_auto_mode_passenger_equal) && (state_klima_driver)){
               state_klima_heating = TRUE;
            }
            IF((counter_klima_fan % 4) < 1){
               counter_klima_fan = 1;
            }
         }
         ELSE{
            OUTPUT_LOW(KOMPRESOR);
            state_kompressor = FALSE;
         }
         IF(state_klima_driver){
            OUTPUT_HIGH(KLIMA_SINYALI);
         }
         ELSE{
            OUTPUT_LOW(KLIMA_SINYALI);
         }
      }
   }   
//*************************************************************************************************************************************************//
//***********************************************************CONTROL**BUTTON**KLIMA**FAN***********************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Klima_Fan(){
      IF((!INPUT(BUT_KLIMA_FAN)) && (state_button_klima_fan)){
         state_button_klima_fan = FALSE;
         counter_klima_fan++;
         IF((counter_auto_mode % 2) == 1){
            state_check_manuel_klima_fan = TRUE;
            state_ac_oner = TRUE;
         }
      }
      IF(INPUT(BUT_KLIMA_FAN)){
         state_button_klima_fan = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//*************************************************************CONTROL**BUTTON**ON**FAN************************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_On_Fan(){
      IF((!INPUT(BUT_ON_FAN)) && (state_button_on_fan)){
         state_button_on_fan = FALSE;
         IF((counter_auto_mode % 2) == 0){
            IF((counter_max % 2) == 0){
               counter_on_fan++;
            }
            IF((counter_max % 2) == 1){
               counter_max          = 0;
               counter_on_fan       = counter_on_fan_before;
               counter_cam          = counter_cam_before;
               counter_temiz_hava   = counter_temiz_hava_before;
               counter_vana_1       = counter_vana_1_before;
               OFFer(MAX_DEFAULT);
            }
         }
         IF((counter_auto_mode % 2) == 1){
            counter_on_fan++;
            state_check_manuel_on_fan     = TRUE;
            state_check_manuel_vana_1     = TRUE;
            state_ac_oner                 = TRUE;
            IF((counter_max % 2) == 1){
               counter_max          = 0;
               counter_on_fan       = counter_on_fan_before;
               counter_cam          = counter_cam_before;
               counter_temiz_hava   = counter_temiz_hava_before;
               counter_vana_1       = counter_vana_1_before;
               OFFer(MAX_DEFAULT);
            }
         }
      }
      IF(INPUT(BUT_ON_FAN)){
         state_button_on_fan = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//************************************************************CONTROL**BUTTON**ARKA**FAN***********************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Arka_Fan(){
      IF((!INPUT(BUT_ARKA_FAN)) && (state_button_arka_fan)){
         state_button_arka_fan = FALSE;
         counter_arka_fan++;
         IF((counter_auto_mode % 2) == 1){
            state_check_manuel_arka_fan      = TRUE;
            state_check_manuel_klima_fan     = TRUE;
            state_check_manuel_vana_2        = TRUE;
            state_ac_oner                    = TRUE;
         }
      }
      IF(INPUT(BUT_ARKA_FAN)){
         state_button_arka_fan = TRUE;
      }
   }
//*************************************************************************************************************************************************//
//***************************************************************CONTROL**BUTTON**CAM**************************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Cam(){
      IF((counter_max % 2) == 0){
         IF(!INPUT(BUT_CAM) && (state_button_cam)){
            state_button_cam = FALSE;
            IF(counter_cam == 2){
               counter_cam = 1;
            }
            ELSE IF(counter_cam == 0){
               counter_cam = 2;
            }
            ELSE{
               counter_cam = 1;
            }
            write_eeprom(address_cam, counter_cam);
         }
         IF(INPUT(BUT_CAM)){
            state_button_cam = TRUE;
         }
         IF(!INPUT(BUT_YUZ) && (state_button_yuz)){
            state_button_yuz = FALSE;
            IF(counter_cam == 2){
               counter_cam = 0;
            }
            ELSE IF(counter_cam == 1){
               counter_cam = 2;
            }
            ELSE{
               counter_cam = 0;
            }
            write_eeprom(address_cam, counter_cam);
         }
         IF(INPUT(BUT_YUZ)){
            state_button_yuz = TRUE;
         }
      }
      IF((counter_max % 2) == 1){
         IF(!INPUT(BUT_CAM) && (state_button_cam)){
            state_button_cam     = FALSE;
            counter_max          = 0;
            counter_on_fan       = counter_on_fan_before;
            counter_cam          = counter_cam_before;
            counter_temiz_hava   = counter_temiz_hava_before;
            counter_vana_1       = counter_vana_1_before;
            OFFer(MAX_DEFAULT);
         }
         IF(INPUT(BUT_CAM)){
            state_button_cam = TRUE;
         }
         IF(!INPUT(BUT_YUZ) && (state_button_yuz)){
            state_button_yuz = FALSE;
            counter_max          = 0;
            counter_on_fan       = counter_on_fan_before;
            counter_cam          = counter_cam_before;
            counter_temiz_hava   = counter_temiz_hava_before;
            counter_vana_1       = counter_vana_1_before;
            OFFer(MAX_DEFAULT);
         }
         IF(INPUT(BUT_YUZ)){
            state_button_yuz = TRUE;
         }
      }
   }
//*************************************************************************************************************************************************//
//***********************************************************CONTROL**BUTTON**TEMIZ**HAVA**********************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Temiz_Hava(){
      IF((!INPUT(BUT_TEMIZ_HAVA)) && (state_button_temiz_hava)){
         state_button_temiz_hava = false;
         IF((counter_auto_mode % 2) == 0){
            IF((counter_max % 2) == 0){
               counter_temiz_hava++;
            }
            IF((counter_max % 2) == 1){
               counter_max          = 0;
               counter_on_fan       = counter_on_fan_before;
               counter_cam          = counter_cam_before;
               counter_temiz_hava   = counter_temiz_hava_before;
               counter_vana_1       = counter_vana_1_before;
               OFFer(MAX_DEFAULT);
            }
         }
         IF((counter_auto_mode % 2) == 1){
            counter_temiz_hava++;
            IF((counter_max % 2) == 1){
               counter_max          = 0;
               counter_on_fan       = counter_on_fan_before;
               counter_cam          = counter_cam_before;
               counter_temiz_hava   = counter_temiz_hava_before;
               counter_vana_1       = counter_vana_1_before;
               OFFer(MAX_DEFAULT);
            }
         }
         write_eeprom(address_temiz_hava,counter_temiz_hava);
      }
      IF(INPUT(BUT_TEMIZ_HAVA)){
         state_button_temiz_hava = true;
      }
   }
//*************************************************************************************************************************************************//
//**************************************************************CONTROL**BUTTON**VANA_1************************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Vana_1(){
      IF(!state_error_vana_1){
         IF((!INPUT(BUT_VANA_1)) && (state_button_vana_1)){
            state_button_vana_1 = FALSE;
            IF((counter_auto_mode % 2) == 0){
               IF((counter_max % 2) == 0){
                  counter_vana_1++;
               }
               IF((counter_max % 2) == 1){
                  counter_max          = 0;
                  counter_on_fan       = counter_on_fan_before;
                  counter_cam          = counter_cam_before;
                  counter_temiz_hava   = counter_temiz_hava_before;
                  counter_vana_1       = counter_vana_1_before;
                  OFFer(MAX_DEFAULT);
               }
            }
            IF((counter_auto_mode % 2) == 1){
               counter_vana_1++;
               state_check_manuel_vana_1     = TRUE;
               state_check_manuel_on_fan     = TRUE;
               state_ac_oner                 = TRUE;
               IF((counter_max % 2) == 1){
                  counter_max          = 0;
                  counter_on_fan       = counter_on_fan_before;
                  counter_cam          = counter_cam_before;
                  counter_temiz_hava   = counter_temiz_hava_before;
                  counter_vana_1       = counter_vana_1_before;
                  OFFer(MAX_DEFAULT);
               }
            }
            write_eeprom(address_vana_1,counter_vana_1);
         }  
         IF(INPUT(BUT_VANA_1)){
            state_button_vana_1 = TRUE;
         }
      }
   }
//*************************************************************************************************************************************************//
//**************************************************************CONTROL**BUTTON**VANA_2************************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Vana_2(){
      IF(!state_error_vana_2){
         IF(!INPUT(BUT_VANA_2) && (state_button_vana_2)){
            state_button_vana_2 = FALSE;
            counter_vana_2++;
            IF((counter_auto_mode % 2) == 1){
               state_check_manuel_vana_2        = TRUE;
               state_check_manuel_klima_fan     = TRUE;
               state_check_manuel_arka_fan      = TRUE;
               state_ac_oner                    = TRUE;
            }
            write_eeprom(address_vana_2,counter_vana_2);
         }
         IF(INPUT(BUT_VANA_2)){
            state_button_vana_2 = TRUE;
         }
      }
   }
//*************************************************************************************************************************************************//
//***************************************************************CONTROL**BUTTON**AC***************************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_AC(){
      IF(!state_error_yuksek_basinc){
         IF((!INPUT(BUT_AC)) && (state_button_auto_mode)){
            state_button_auto_mode                 = FALSE;
            counter_auto_mode++;
            state_check_once_entrance_to_ac        = TRUE;
            state_check_once_controller_functions  = TRUE;
            state_check_manuel_klima_fan           = FALSE;
            state_check_manuel_on_fan              = FALSE;
            state_check_manuel_arka_fan            = FALSE;
            state_check_manuel_vana_1              = FALSE;
            state_check_manuel_vana_2              = FALSE;
            state_klima_heating                    = FALSE;
            state_ac_oner                          = FALSE;
            state_sensor_driver_temp               = TRUE;
            state_sensor_driver_temp_inner         = FALSE;
            state_sensor_driver_temp_plus          = FALSE;
            state_sensor_driver_temp_minus         = FALSE;
            state_sensor_passenger_temp            = TRUE;
            state_sensor_passenger_temp_inner      = FALSE;
            state_sensor_passenger_temp_plus       = FALSE;
            state_sensor_passenger_temp_minus      = FALSE;
            state_max_on_in_auto_mode              = FALSE;
            counter_max                            = 0;
            OFFer(AC_DEFAULT);
            OFFer(MAX_DEFAULT);
            IF((counter_auto_mode % 2) == 0){
               state_ac_button         = FALSE;
               state_kompressor        = FALSE;
               state_klima_fan_once    = FALSE;
               state_klima_driver      = FALSE;
               state_klima_passenger   = FALSE;
               counter_auto_mode       = 0;
               counter_klima_fan       = 0;
               counter_on_fan          = 0;
               counter_arka_fan        = 0;
               value_pwm1              = 0;
               value_pwm2              = 0;
//************************************COOLER**NOT**WORK**IN**MANUEL**MODE**SO**KOMPRESSOR**AND**KLIMA_SINYALI**OFF*********************************//
               OUTPUT_LOW(KOMPRESOR);
               OUTPUT_LOW(KLIMA_SINYALI);
            }
            counter_write_eeprom_auto_mode = 0;
         }
         IF(INPUT(BUT_AC)){
            state_button_auto_mode = TRUE;
         }
      }
      counter_write_eeprom_auto_mode++;
      IF(counter_write_eeprom_auto_mode == 2000){
         write_eeprom(address_auto_mode , counter_auto_mode);
      }
//********************************************COUNTER_AC**AND**COUNTER_MAX**MAKING**ZERO**ONLY**ONE**AT**FIRST*************************************//
      IF(state_counter_ac_and_max_once_make_zero){
         counter_auto_mode = READ_EEPROM(address_auto_mode);;
         counter_max = 0;
         state_counter_ac_and_max_once_make_zero = FALSE;
      }
   }
//*************************************************************************************************************************************************//
//***************************************************************CONTROL**BUTTON**MAX**************************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Max(){
      IF((!INPUT(BUT_MAX)) && (state_button_max)){
         state_button_max = false;
         counter_max++;
         IF(state_button_max_counter_before){
            state_button_max_counter_before        = FALSE;
            counter_on_fan_before                  = counter_on_fan;
            counter_cam_before                     = counter_cam;
            counter_temiz_hava_before              = counter_temiz_hava;
            counter_vana_1_before                  = counter_vana_1;
         }
         IF((counter_auto_mode % 2) == 0){
            IF((counter_max % 2) == 0){
               OFFer(MAX_DEFAULT);
               counter_max                         = 0;
               counter_on_fan                      = counter_on_fan_before;
               counter_cam                         = counter_cam_before;
               counter_temiz_hava                  = counter_temiz_hava_before;
               counter_vana_1                      = counter_vana_1_before;
               state_button_max_counter_before     = TRUE;
            }
            IF((counter_max % 2) == 1){
               ONer(MAX_ON);
               counter_on_fan = 3;
               counter_cam = 1;
               counter_temiz_hava = 0;
               counter_vana_1 = 2;
            }
         }
         IF((counter_auto_mode % 2) == 1){
            IF((counter_max % 2) == 0){
               OFFer(MAX_DEFAULT);
               state_max_on_in_auto_mode = FALSE;
               counter_max = 0;
               counter_on_fan                      = counter_on_fan_before;
               counter_cam                         = counter_cam_before;
               counter_temiz_hava                  = counter_temiz_hava_before;
               counter_vana_1                      = counter_vana_1_before;
               state_button_max_counter_before     = TRUE;
            }
            IF((counter_max % 2) == 1){
               state_max_on_in_auto_mode = TRUE;
               state_sensor_driver_temp = TRUE;
               state_sensor_driver_temp_inner = FALSE;
               state_sensor_driver_temp_plus = FALSE;
               state_sensor_driver_temp_minus = FALSE;
               state_klima_driver = FALSE;
               ONer(MAX_ON);
               counter_on_fan = 3;
               counter_klima_fan = 0;
               counter_cam = 1;
               counter_temiz_hava = 0;
               counter_vana_1 = 2;
            }
         }
      }
      IF(INPUT(BUT_MAX)){
         state_button_max = true;
      }
   }
//*************************************************************************************************************************************************//
//**********************************************************BUTTON**INCREASE**DECREASE*************************************************************//
//*************************************************************************************************************************************************//
   VOID Button_Controller_Increase_Decrease(){
//*************************************************************************************************************************************************//
      IF(!INPUT(BUT_INCREASE) && (state_button_increase)){
         DELAY_MS(250);
         Service_Mode_Increase();
         state_button_increase = FALSE;
         IF(!state_increase_service_mode_worked){
            sensor_driver_set_temp++;
            IF(sensor_driver_set_temp > 30){
               sensor_driver_set_temp = 30;
            }
            digit_10 = (sensor_driver_set_temp / 10);
            digit_1 = (sensor_driver_set_temp % 10);
            IF(!state_error_sensor_driver){
               display_register = ORer_Two_Number(numbers[(digit_10)], numbers[(digit_1)]);
               Write_Display(display_register);
               write_eeprom(address_sensor_driver_set_temp, sensor_driver_set_temp);
            }
         }
      }
      IF(INPUT(BUT_INCREASE)){
         state_button_increase = TRUE;
         state_increase_service_mode_worked = FALSE;
      }
//*************************************************************************************************************************************************//
      IF((!INPUT(BUT_DECREASE)) && (state_button_decrease)){
         state_button_decrease = FALSE;
         sensor_driver_set_temp--;
         IF(sensor_driver_set_temp < 16){
            sensor_driver_set_temp = 16;
         }
         digit_10 = (sensor_driver_set_temp / 10);
         digit_1 = (sensor_driver_set_temp % 10);
         IF(!state_error_sensor_driver){
            display_register = ORer_Two_Number(numbers[(digit_10)], numbers[(digit_1)]);
            Write_Display(display_register);
            write_eeprom(address_sensor_driver_set_temp, sensor_driver_set_temp);
         }
      }
      IF(INPUT(BUT_DECREASE)){
         state_button_decrease = TRUE;
      }
//*************************************************************************************************************************************************//
      IF(state_set_temp_show_only_once_at_main){
         state_set_temp_show_only_once_at_main = false;
         digit_10 = (sensor_driver_set_temp / 10);
         digit_1 = (sensor_driver_set_temp % 10);
         display_register = ORer_Two_Number(numbers[(digit_10)], numbers[(digit_1)]);
         Write_Display(display_register);
      }
   }
//*************************************************************************************************************************************************//
//**************************************************************SERVICE**MODE**INCREASE************************************************************//
//*************************************************************************************************************************************************//
   VOID Service_Mode_Increase(){
//*************************************************************************************************************************************************//
         state_increase_service_mode = FALSE;
         WHILE(!INPUT(BUT_INCREASE)){
            IF(!INPUT(BUT_DECREASE)){
               counter_decrease++;
               IF(counter_decrease > 300000){
                  counter_decrease = 0;
                  Write_Hello();
                  digit_10 = (sensor_passenger_set_temp / 10);
                  digit_1 = (sensor_passenger_set_temp % 10);
                  display_register = ORer_Two_Number(numbers[(digit_10)], numbers[(digit_1)]);
                  Write_Display(display_register);
                  write_eeprom(address_sensor_passenger_set_temp, sensor_passenger_set_temp);
                  state_increase_service_mode = TRUE;
               }
            }
         }
//*************************************************************************************************************************************************//
         WHILE(state_increase_service_mode){
//*************************************************************************************************************************************************//
            IF(!INPUT(BUT_INCREASE) && (state_button_increase)){
               DELAY_MS(250);
               counter_decrease = 0;
               WHILE(!INPUT(BUT_INCREASE)){
                  counter_decrease++;
                  IF(counter_decrease > 300000){
                     counter_decrease = 0;
                     state_increase_service_mode = FALSE;
                     state_increase_service_mode_worked = TRUE;
                     Write_Bye_Bye();
                     IF(abs(sensor_passenger_temp - sensor_passenger_set_temp) <= 2){
                        state_auto_mode_passenger_equal = TRUE;
                        IF((state_klima_passenger) || (state_klima_driver)){
                           counter_klima_fan = 1;
                           state_klima_fan_once = TRUE;
                        }
                        ELSE{
                           IF(!state_klima_fan_once){
                              IF(state_kompressor){
                                 counter_klima_fan = 1;
                              }
                              IF(!state_kompressor){
                                 counter_klima_fan = 0;
                              }
                           }
                           ELSE{
                              counter_klima_fan = 1;
                              state_klima_fan_once = TRUE;
                           }
                        }
                        counter_arka_fan = 0;
                        counter_vana_2 = 0;
                     }
                  }
               }
               IF(state_increase_service_mode){
                  state_button_increase = FALSE;
                  sensor_passenger_set_temp++;
                  IF(sensor_passenger_set_temp > 30){
                     sensor_passenger_set_temp = 30;
                  }
                  digit_10 = (sensor_passenger_set_temp / 10);
                  digit_1 = (sensor_passenger_set_temp % 10);
                  display_register = ORer_Two_Number(numbers[(digit_10)], numbers[(digit_1)]);
                  Write_Display(display_register);
                  write_eeprom(address_sensor_passenger_set_temp, sensor_passenger_set_temp);
               }
            }
            IF(INPUT(BUT_INCREASE)){
               state_button_increase = TRUE;
            }
//*************************************************************************************************************************************************//
            IF(!INPUT(BUT_DECREASE) && (state_button_decrease)){
               DELAY_MS(250);
               state_button_decrease = FALSE;
               IF(state_increase_service_mode){
                  sensor_passenger_set_temp--;
                  IF(sensor_passenger_set_temp < 16){
                     sensor_passenger_set_temp = 16;
                  }
                  digit_10 = (sensor_passenger_set_temp / 10);
                  digit_1 = (sensor_passenger_set_temp % 10);
                  display_register = ORer_Two_Number(numbers[(digit_10)], numbers[(digit_1)]);
                  Write_Display(display_register);
                  write_eeprom(address_sensor_passenger_set_temp, sensor_passenger_set_temp);
               }
            }
            IF(INPUT(BUT_DECREASE)){
               state_button_decrease = TRUE;
            }
         }
   }
//*************************************************************************************************************************************************//
//*****************************************************************ERROR**CONTROLLER***************************************************************//
//*************************************************************************************************************************************************//
//***                                                                                                                                           ***//
//***                                                  300 DEGERINDE YAKALADI. 1000 DEGERI IDEAL.                                               ***//
//***                                                                                                                                           ***//
//*************************************************************************************************************************************************//
   VOID Controller_Error(){
      counter_controller_error++;
      counter_error++;
      IF((counter_controller_error % 1001) == 1000){
         counter_controller_error = 0;
         SET_ADC_CHANNEL(CHANNEL_Sensor_Driver);
         DELAY_MS(20);
         sensor_driver_value = READ_ADC();
         IF(sensor_driver_value < 30){
            state_error_sensor_driver = TRUE;
         }
         ELSE{
            state_error_sensor_driver = FALSE;
         }
         SET_ADC_CHANNEL(CHANNEL_Sensor_Passenger);
         DELAY_MS(20);
         sensor_passenger_value = READ_ADC();
         IF(sensor_passenger_value < 30){
            state_error_sensor_passenger = TRUE;
         }
         ELSE{
            state_error_sensor_passenger = FALSE;
         }
         IF(!INPUT(ERROR_2)){
            state_error_yuksek_basinc = TRUE;
            IF((counter_auto_mode % 2) == 1){
               counter_auto_mode = 0;
               OFFer(AC_DEFAULT);
               OFFer(MAX_OFF);
               counter_klima_fan = 0;
               Controller_Klima_Fan();
               counter_on_fan = 0;
               Controller_On_Fan();
               counter_arka_fan = 0;
               Controller_Arka_Fan();
            }
         }
         ELSE{
            state_error_yuksek_basinc = FALSE;
         }
         Read_Temp();
      }
      IF((state_error_sensor_driver) && (state_error_sensor_passenger) && (state_error_yuksek_basinc)){
         IF((counter_error % 6001) == 2000){
            display_register = ORer_Two_Number(numbers[10],numbers[11]);
            Write_Display(display_register);
         }
         IF((counter_error % 6001) == 4000){
            display_register = ORer_Two_Number(numbers[10],numbers[1]);
            Write_Display(display_register);
         }
         IF((counter_error % 6001) == 6000){
            display_register = ORer_Two_Number(numbers[10],numbers[2]);
            Write_Display(display_register);
            counter_error = 0;
         }
      }
      ELSE IF((state_error_sensor_driver) && (state_error_sensor_passenger)){
         IF((counter_error % 4001) == 2000){
            display_register = ORer_Two_Number(numbers[10],numbers[1]);
            Write_Display(display_register);
         }
         IF((counter_error % 4001) == 4000){
            display_register = ORer_Two_Number(numbers[10],numbers[2]);
            Write_Display(display_register);
            counter_error = 0;
         }
      }
      ELSE IF((state_error_sensor_driver) && (state_error_yuksek_basinc)){
         IF((counter_error % 4001) == 2000){
            display_register = ORer_Two_Number(numbers[10],numbers[11]);
            Write_Display(display_register);
         }
         IF((counter_error % 4001) == 4000){
            display_register = ORer_Two_Number(numbers[10],numbers[1]);
            Write_Display(display_register);
            counter_error = 0;
         }
      }
      ELSE IF((state_error_sensor_passenger) && (state_error_yuksek_basinc)){
         IF((counter_error % 4001) == 2000){
            display_register = ORer_Two_Number(numbers[10],numbers[11]);
            Write_Display(display_register);
         }
         IF((counter_error % 4001) == 4000){
            display_register = ORer_Two_Number(numbers[10],numbers[2]);
            Write_Display(display_register);
            counter_error = 0;
         }
      }
      ELSE IF(state_error_sensor_driver){
         IF((counter_error % 2001) == 2000){
            display_register = ORer_Two_Number(numbers[10],numbers[1]);
            Write_Display(display_register);
            counter_error = 0;
         }
      }
      ELSE IF(state_error_sensor_passenger){
         IF((counter_error % 4001) == 2000){
            display_register = ORer_Two_Number(numbers[10],numbers[2]);
            Write_Display(display_register);
         }
         IF((counter_error % 4001) == 4000){
            digit_10 = (sensor_driver_set_temp / 10);
            digit_1 = (sensor_driver_set_temp % 10);
            display_register = ORer_Two_Number(numbers[digit_10], numbers[digit_1]);
            Write_Display(display_register);
            counter_error = 0;
         }
      }
      ELSE IF(state_error_yuksek_basinc){
         IF((counter_error % 4001) == 2000){
            display_register = ORer_Two_Number(numbers[10],numbers[11]);
            Write_Display(display_register);
         }
         IF((counter_error % 4001) == 4000){
            digit_10 = (sensor_driver_set_temp / 10);
            digit_1 = (sensor_driver_set_temp % 10);
            display_register = ORer_Two_Number(numbers[digit_10], numbers[digit_1]);
            Write_Display(display_register);
            counter_error = 0;
         }
      }
      ELSE{
         IF((counter_error % 2001) == 2000){
            digit_10 = (sensor_driver_set_temp / 10);
            digit_1 = (sensor_driver_set_temp % 10);
            display_register = ORer_Two_Number(numbers[digit_10], numbers[digit_1]);
            Write_Display(display_register);
            counter_error = 0;
         }
      }
   }
//*************************************************************************************************************************************************//
//**************************************************************KLIMA**FAN**CONTROLLER*************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Klima_Fan(){
      IF((counter_klima_fan % 4) == 0){
         counter_klima_fan = 0;
         OFFer(KLIMA_FAN_1_OFF);
         OFFer(KLIMA_FAN_2_OFF);
         OUTPUT_LOW(KLIMA_FAN_3_ON);
         OUTPUT_LOW(KLIMA_FAN_1);
         OUTPUT_LOW(KLIMA_FAN_2);
         OUTPUT_LOW(KLIMA_FAN_3);
      }
      IF((counter_klima_fan % 4) == 1){
         ONer(KLIMA_FAN_1_ON);
         OFFer(KLIMA_FAN_2_OFF);
         OUTPUT_LOW(KLIMA_FAN_3_ON);
         OUTPUT_HIGH(KLIMA_FAN_1);
         OUTPUT_LOW(KLIMA_FAN_2);
         OUTPUT_LOW(KLIMA_FAN_3);
      }
      IF((counter_klima_fan % 4) == 2){
         ONer(KLIMA_FAN_1_ON);
         ONer(KLIMA_FAN_2_ON);
         OUTPUT_LOW(KLIMA_FAN_3_ON);
         OUTPUT_HIGH(KLIMA_FAN_1);
         OUTPUT_HIGH(KLIMA_FAN_2);
         OUTPUT_LOW(KLIMA_FAN_3);
      }
      IF((counter_klima_fan % 4) == 3){
         ONer(KLIMA_FAN_1_ON);
         ONer(KLIMA_FAN_2_ON);
         OUTPUT_HIGH(KLIMA_FAN_3_ON);
         OUTPUT_HIGH(KLIMA_FAN_1);
         OUTPUT_HIGH(KLIMA_FAN_2);
         OUTPUT_HIGH(KLIMA_FAN_3);
      }
   }
//*************************************************************************************************************************************************//
//****************************************************************ON**FAN**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_On_Fan(){
   
      IF((counter_on_fan % 4) == 0){
         OFFer(ON_FAN_1_OFF);
         OFFer(ON_FAN_2_OFF);
         OFFer(ON_FAN_3_OFF);
         counter_on_fan = 0;
         set_pwm1_duty(0);
         SETUP_CCP1(CCP_OFF);
         value_pwm1 = 0;
      }
      IF((counter_on_fan % 4) == 1){
         ONer(ON_FAN_1_ON);
         OFFer(ON_FAN_2_OFF);
         OFFer(ON_FAN_3_OFF);
         SETUP_CCP1(CCP_PWM);
         IF(value_pwm1 == 0){
           FOR(value_pwm1 = 0; value_pwm1 <= 600; value_pwm1++){
               set_pwm1_duty(value_pwm1);
               DELAY_MS(2);
            }
            value_pwm1 = 600;
            set_pwm1_duty(600);
         }
         ELSE{
            value_pwm1 = 600;
            set_pwm1_duty(600);
         }
      }
      IF((counter_on_fan % 4) == 2){
         ONer(ON_FAN_1_ON);
         ONer(ON_FAN_2_ON);
         OFFer(ON_FAN_3_OFF);
         SETUP_CCP1(CCP_PWM);
         IF(value_pwm1 == 0){
            FOR(value_pwm1 = 0; value_pwm1 <= 850; value_pwm1++){
               set_pwm1_duty(value_pwm1);
               DELAY_MS(2);
            }
            value_pwm1 = 850;
            set_pwm1_duty(850);
         }
         ELSE IF(value_pwm1 == 600){
            FOR(value_pwm1 =600; value_pwm1 <= 850; value_pwm1++){
               set_pwm1_duty(value_pwm1);
               DELAY_MS(2);
            }
            value_pwm1 = 850;
            set_pwm1_duty(850);
         }
         ELSE{
            value_pwm1 = 850;
            set_pwm1_duty(850);
         }
      }
      IF((counter_on_fan % 4) == 3){
         ONer(ON_FAN_1_ON);
         ONer(ON_FAN_2_ON);
         ONer(ON_FAN_3_ON);
         SETUP_CCP1(CCP_PWM);
         IF(value_pwm1 == 0){
            FOR(value_pwm1 = 0; value_pwm1 <= 1018; value_pwm1++){
               set_pwm1_duty(value_pwm1);
               DELAY_MS(2);
            }
            value_pwm1 = 1018;
            set_pwm1_duty(1018);
         }
         ELSE IF(value_pwm1 == 600){
            FOR(value_pwm1 = 600; value_pwm1 <= 1018; value_pwm1++){
               set_pwm1_duty(value_pwm1);
               DELAY_MS(2);
            }
            value_pwm1 = 1018;
            set_pwm1_duty(1018);
         }
         ELSE IF(value_pwm1 == 850){
            FOR(value_pwm1 = 850; value_pwm1 <= 1018; value_pwm1++){
               set_pwm1_duty(value_pwm1);
               DELAY_MS(2);
            }
            value_pwm1 = 1018;
            set_pwm1_duty(1018);
         }
         ELSE{
            value_pwm1 = 1018;
            set_pwm1_duty(1018);
         }
      }
   }
//*************************************************************************************************************************************************//
//***************************************************************ARKA**FAN**CONTROLLER*************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Arka_Fan(){
   
      IF((counter_arka_fan % 3) == 0){
         OFFer(ARKA_FAN_1_OFF);
         OFFer(ARKA_FAN_2_OFF);
         counter_arka_fan = 0;
         SETUP_CCP2(CCP_OFF);
         value_pwm2 = 0;
      }
      IF((counter_arka_fan % 3) == 1){
         ONer(ARKA_FAN_1_ON);
         OFFer(ARKA_FAN_2_OFF);
         SETUP_CCP2(CCP_PWM);
         IF(value_pwm2 == 0){
            FOR(value_pwm2 = 0; value_pwm2 <= 700; value_pwm2++){
               set_pwm2_duty(value_pwm2);
               DELAY_MS(2);
            }
            value_pwm2 = 700;
            set_pwm2_duty(700);
         }
         ELSE{
            value_pwm2 = 700;
            set_pwm2_duty(700);
         }
      }
      IF((counter_arka_fan % 3) == 2){
         ONer(ARKA_FAN_1_ON);
         ONer(ARKA_FAN_2_ON);
         SETUP_CCP2(CCP_PWM);
         IF(value_pwm2 == 0){
            FOR(value_pwm2 = 0; value_pwm2 <= 1000; value_pwm2++){
               set_pwm2_duty(value_pwm2);
               DELAY_MS(2);
            }
            value_pwm2 = 1000;
            set_pwm2_duty(1000);
         }
         ELSE IF(value_pwm2 == 700){
            FOR(value_pwm2 = 700; value_pwm2 <= 1000; value_pwm2++){
               set_pwm2_duty(value_pwm2);
               DELAY_MS(2);
            }
            value_pwm2 = 1000;
            set_pwm2_duty(1000);
         }
         ELSE{
            value_pwm2 = 1000;
            set_pwm2_duty(1000);
         }
      }
   }
//*************************************************************************************************************************************************//
//*******************************************************************CAM**CONTROL******************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Cam_Yuz(){
      IF(!state_error_cam){
//*******************************************************************YUZ**KONUMU*******************************************************************//
            IF((counter_cam % 3) == 0){
               OFFer(CAM_OFF);
               ONer(YUZ_ON);
               Read_Motor_Cam();
               IF(motor_pot_cam > (min_cam + 20)){
                  Turn_Left_Cam();
               }
               ELSE{
                  Stop_Cam();
                  state_turn_complete_cam = TRUE;
               }
            }
//*******************************************************************CAM**KONUMU*******************************************************************//
            IF((counter_cam % 3) == 1){
               ONer(CAM_ON);
               OFFer(YUZ_OFF);
               Read_Motor_Cam();
               IF(motor_pot_cam < (max_cam - 20)){
                  Turn_Right_Cam();
               }
               ELSE{
                  Stop_Cam();
                  state_turn_complete_cam = TRUE;
               }
            }
//*****************************************************************BERABER**KONUMU*****************************************************************//
            IF((counter_cam % 3) == 2){
               ONer(CAM_ON);
               ONer(YUZ_ON);
               Read_Motor_Cam();
               IF(motor_pot_cam < (orta_cam - 20)){
                  Turn_Right_Cam();
               }
               ELSE IF(motor_pot_cam > (orta_cam + 20)){
                  Turn_Left_Cam();
               }
               ELSE{
                  Stop_Cam();
                  state_turn_complete_cam = TRUE;
               }
            }
      }
   }
//*************************************************************************************************************************************************//
//************************************************************TEMIZ**HAVA**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Temiz_Hava(){
      IF(!state_error_temiz_hava){
         IF((counter_temiz_hava % 2) == 0){
            counter_temiz_hava = 0;
            OFFer(TEMIZ_HAVA_OFF);
            Read_Motor_Temiz_Hava();
            IF(motor_pot_temiz_hava < (max_temiz_hava - 20)){
               Turn_Right_Temiz_Hava();
            }
            ELSE{
              Stop_Temiz_Hava();
              state_turn_complete_temiz_hava = TRUE;
            }
         }
         IF((counter_temiz_hava % 2) == 1){
            ONer(TEMIZ_HAVA_ON);
            Read_Motor_Temiz_Hava();
            IF(motor_pot_temiz_hava > (min_temiz_hava + 20)){
               Turn_Left_Temiz_Hava();
            }
            ELSE{
              Stop_Temiz_Hava();
              state_turn_complete_temiz_hava = TRUE;
            }
         }
      }
   }
   
//*************************************************************************************************************************************************//
//****************************************************************VANA**1**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Vana_1(){
      IF(!state_error_vana_1){
         IF((counter_vana_1 % 3) == 0){
            counter_vana_1 = 0;
            OUTPUT_HIGH(VANA_1_1_ON);
            OUTPUT_LOW(VANA_1_2_ON);
            OFFer(VANA_1_3_OFF);
            Read_Motor_Vana_1();
            if(motor_pot_vana_1 > (min_vana_1 + 20)){
               Turn_Left_Vana_1();
            }
            else{
              Stop_Vana_1();
              state_turn_complete_vana_1 = TRUE;
            }
         }
         IF((counter_vana_1 % 3) == 1){
            OUTPUT_LOW(VANA_1_1_ON);
            OUTPUT_HIGH(VANA_1_2_ON);
            OFFer(VANA_1_3_OFF);
            Read_Motor_Vana_1();
            if(motor_pot_vana_1 < (orta_vana_1 - 20)){
               Turn_Right_Vana_1();
            }
            else if(motor_pot_vana_1 > (orta_vana_1 + 20)){
               Turn_Left_Vana_1();
            }
            else{
              Stop_Vana_1();
              state_turn_complete_vana_1 = TRUE;
            }
         }
         IF((counter_vana_1 % 3) == 2){
            OUTPUT_LOW(VANA_1_1_ON);
            OUTPUT_HIGH(VANA_1_2_ON);
            ONer(VANA_1_3_ON);
            Read_Motor_Vana_1();
            if(motor_pot_vana_1 < (max_vana_1 - 20)){
               Turn_Right_Vana_1();
            }
            else{
              Stop_Vana_1();
              state_turn_complete_vana_1 = TRUE;
            }
         }
      }
   }
//*************************************************************************************************************************************************//
//****************************************************************VANA**2**CONTROLLER**************************************************************//
//*************************************************************************************************************************************************//
    VOID Controller_Vana_2(){
       IF(!state_error_vana_2){
         IF((counter_vana_2 % 3) == 0){
            counter_vana_2 = 0;
            ONer(VANA_2_1_ON);
            OFFer(VANA_2_2_OFF);
            OFFer(VANA_2_3_OFF);
            Read_Motor_Vana_2();
            IF(motor_pot_vana_2 > (min_vana_2 + 20)){
               Turn_Right_Vana_2();
            }
            ELSE{
              Stop_Vana_2();
              state_turn_complete_vana_2 = TRUE;
            }
         }
         IF((counter_vana_2 % 3) == 1){
            OFFer(VANA_2_1_OFF);
            ONer(VANA_2_2_ON);
            OFFer(VANA_2_3_OFF);
            Read_Motor_Vana_2();
            IF(motor_pot_vana_2 < (orta_vana_2 - 20)){
               Turn_Left_Vana_2();
            }
            ELSE IF(motor_pot_vana_2 > (orta_vana_2 + 20)){
               Turn_Right_Vana_2();
            }
            ELSE{
              Stop_Vana_2();
              state_turn_complete_vana_2 = TRUE;
            }
         }
         IF((counter_vana_2 % 3) == 2){
            OFFer(VANA_2_1_OFF);
            ONer(VANA_2_2_ON);
            ONer(VANA_2_3_ON);
            Read_Motor_Vana_2();
            IF(motor_pot_vana_2 < (max_vana_2 - 20)){
               Turn_Left_Vana_2();
            }
            ELSE{
              Stop_Vana_2();
              state_turn_complete_vana_2 = TRUE;
            }
         }
       }
   }
//*************************************************************************************************************************************************//
//************************************************************AUTO**MODE**ON**CONTROLLER***********************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_Auto_Mode(){
//**********************************************************IF**THERE**IS**NO**ERROR_2**ERROR******************************************************//
      IF(!state_error_yuksek_basinc){
         IF((counter_auto_mode % 2) == 1){
            Controller_AC_Led();
//**************************************************CHECK**COMPARE**WITH**MEDIUM**TEMP**AND**SET**TEMP*********************************************//
            Compare_Temp_And_Set_Temp();
//*********************************************************CONTROL**KLIMA**SINYALI**KOPMRESSOR*****************************************************//
            Setting_Klima();
//**********************************************************IF**THERE**ARE**NO**SENSORs**ERROR*****************************************************//
            IF((!state_error_sensor_driver) && (!state_error_sensor_passenger)){
               state_once_ac_mode_in_sensor_driver_error       = TRUE;
               state_once_ac_mode_in_sensor_passenger_error    = TRUE;
            }
//*********************************************************IF**THERE**IS**DRIVER**SENSOR**ERROR****************************************************//
            IF((state_error_sensor_driver) && (!state_error_sensor_passenger)){
               IF(state_once_ac_mode_in_sensor_driver_error){
                  state_ac_oner = TRUE;
                  counter_on_fan = 0;
                  state_check_manuel_on_fan = TRUE;
                  counter_vana_1 = 0;
                  state_check_manuel_vana_1 = TRUE;
                  state_once_ac_mode_in_sensor_driver_error = FALSE;
               }
               IF(!((counter_on_fan % 4) == 0) && ((counter_vana_1 % 3) == 0)){
                  state_klima_driver = TRUE;
               }
               ELSE{
                  state_klima_driver = FALSE;
               }
            }
//********************************************************IF**THERE**IS**PASSENGER**SENSOR**ERROR**************************************************//
            IF((!state_error_sensor_driver) && (state_error_sensor_passenger)){
               IF(state_once_ac_mode_in_sensor_passenger_error){
                  state_ac_oner = TRUE;
                  counter_klima_fan = 0;
                  state_check_manuel_klima_fan = TRUE;
                  counter_arka_fan = 0;
                  state_check_manuel_arka_fan = TRUE;
                  counter_vana_2 = 0;
                  state_check_manuel_vana_2 = TRUE;
                  state_once_ac_mode_in_sensor_passenger_error = FALSE;
               }
               IF(((counter_arka_fan % 3) == 0) && ((counter_vana_2 % 3) == 0)){
                  state_klima_passenger = TRUE;
               }
               ELSE{
                  state_klima_passenger = FALSE;
               }
            }
            IF((state_error_sensor_driver) && (state_error_sensor_passenger)){
               IF(state_once_ac_mode_in_sensor_driver_error){
                  state_ac_oner = TRUE;
                  counter_on_fan = 0;
                  state_check_manuel_on_fan = TRUE;
                  counter_vana_1 = 0;
                  state_check_manuel_vana_1 = TRUE;
                  state_once_ac_mode_in_sensor_driver_error = FALSE;
               }
               IF(state_once_ac_mode_in_sensor_passenger_error){
                  state_ac_oner = TRUE;
                  counter_klima_fan = 0;
                  state_check_manuel_klima_fan = TRUE;
                  counter_arka_fan = 0;
                  state_check_manuel_arka_fan = TRUE;
                  counter_vana_2 = 0;
                  state_check_manuel_vana_2 = TRUE;
                  state_once_ac_mode_in_sensor_passenger_error = FALSE;
               }
               IF(!((counter_on_fan % 4) == 0) && ((counter_vana_1 % 3) == 0)){
                  state_klima_driver = TRUE;
               }
               ELSE{
                  state_klima_driver = FALSE;
               }
               IF(((counter_arka_fan % 3) == 0) && ((counter_vana_2 % 3) == 0)){
                  state_klima_passenger = TRUE;
               }
               ELSE{
                  state_klima_passenger = FALSE;
               }
            }
         }
      }
//************************************************************IF**THERE**IS**ERROR_2**ERROR********************************************************//
//*********************************************NOT**WORKING**KLIMA**FAN**ON**FAN**KOMPRESSOR**KLIMA**SINYALI***************************************//
//***************************************************************DISPLAY**WRITING**ER**************************************************************//
   }
//*************************************************************************************************************************************************//
//**********************************************************************CHECK**********************************************************************//
//*************************************************************************************************************************************************//
   VOID Compare_Temp_And_Set_Temp(){
//******************************************************************DRIVER**SIDE*******************************************************************//
      IF(!state_max_on_in_auto_mode){
      IF(abs(sensor_driver_temp - sensor_driver_set_temp) >= 2){
         state_sensor_driver_temp = TRUE;
         state_sensor_driver_temp_inner = FALSE;
      }
      IF(state_sensor_driver_temp){
         IF(abs(sensor_driver_temp - sensor_driver_set_temp) <= 2){
            state_sensor_driver_temp = FALSE;
            state_sensor_driver_temp_inner = TRUE;
         }
      }
      IF(state_sensor_driver_temp_inner){
         IF(sensor_driver_temp > sensor_driver_set_temp){
            state_sensor_driver_temp_plus = TRUE;
            state_sensor_driver_temp_minus = FALSE;
            state_sensor_driver_temp_inner = FALSE;
         }
         IF(sensor_driver_temp < sensor_driver_set_temp){
            state_sensor_driver_temp_plus = FALSE;
            state_sensor_driver_temp_minus = TRUE;
            state_sensor_driver_temp_inner = FALSE;
         }
      }
      IF(state_sensor_driver_temp_plus){
         IF((sensor_driver_set_temp - sensor_driver_temp) >= 1){
            IF(!state_error_sensor_driver){
               state_klima_driver = FALSE;
            }
            state_sensor_driver_temp_plus = FALSE;
            IF(!state_check_manuel_on_fan){
               counter_on_fan = 0;
            }
            IF(!state_check_manuel_vana_1){
               IF(!state_error_vana_1){
                  counter_vana_1 = 0;
               }
            }
         }
      }
      IF(state_sensor_driver_temp_minus){
         IF((sensor_driver_temp - sensor_driver_set_temp) >= 1){
            IF(!state_error_sensor_driver){
               state_klima_driver = FALSE;
            }
            state_sensor_driver_temp_minus = FALSE;
            IF(!state_check_manuel_on_fan){
               counter_on_fan = 0;
            }
            IF(!state_check_manuel_vana_1){
               IF(!state_error_vana_1){
                  counter_vana_1 = 0;
               }
            }
         }
      }
      }
//*****************************************************************PASSENGER**SIDE*****************************************************************//
//OFFSET**DEGERI**AYARLAMA*************************************************************************************************************************//
      IF(abs(sensor_passenger_temp - sensor_passenger_set_temp) >= 2){
         state_sensor_passenger_temp = TRUE;
         state_sensor_passenger_temp_inner = FALSE;
      }
      IF(state_sensor_passenger_temp){
         IF(abs(sensor_passenger_temp - sensor_passenger_set_temp) <= 2){
            state_sensor_passenger_temp = FALSE;
            state_sensor_passenger_temp_inner = TRUE;
         }
      }
      IF(state_sensor_passenger_temp_inner){
//SOGUTMA******************************************************************************************************************************************//
         IF(sensor_passenger_temp > sensor_passenger_set_temp){
            state_sensor_passenger_temp_plus = TRUE;
            state_sensor_passenger_temp_minus = FALSE;
            state_sensor_passenger_temp_inner = FALSE;
         }
//ISITMA*******************************************************************************************************************************************//
         IF(sensor_passenger_temp < sensor_passenger_set_temp){
            state_sensor_passenger_temp_plus = FALSE;
            state_sensor_passenger_temp_minus = TRUE;
            state_sensor_passenger_temp_inner = FALSE;
         }
      }
//SOGUTMA******************************************************************************************************************************************//
      IF(state_sensor_passenger_temp_plus){
         IF((sensor_passenger_set_temp - sensor_passenger_temp) >= 1){
            IF(!state_error_sensor_passenger){
               state_klima_passenger = FALSE;
            }
            state_sensor_passenger_temp_plus = FALSE;
            IF(!state_check_manuel_klima_fan){
               IF((state_klima_passenger) || (state_klima_driver)){
                  counter_klima_fan = 1;
                  state_klima_fan_once = TRUE;
               }
               ELSE{
                  IF(!state_klima_fan_once){
                     IF(state_kompressor){
                        counter_klima_fan = 1;
                     }
                     IF(!state_kompressor){
                        counter_klima_fan = 0;
                     }
                  }
                  ELSE{
                     counter_klima_fan = 1;
                     state_klima_fan_once = TRUE;
                  }
               }
            }
            IF(!state_check_manuel_arka_fan){
               counter_arka_fan = 0;
            }
            IF(!state_check_manuel_vana_2){
               IF(!state_error_vana_2){
                  counter_vana_2 = 0;
               }
            }
         }
      }
//ISITMA*******************************************************************************************************************************************//
      IF(state_sensor_passenger_temp_minus){
         IF((sensor_passenger_temp - sensor_passenger_set_temp) >= 1){
            IF(!state_error_sensor_passenger){
               state_klima_passenger = FALSE;
            }
            state_sensor_passenger_temp_minus = FALSE;
            IF(!state_check_manuel_klima_fan){
               IF(state_klima_passenger){
                  counter_klima_fan = 1;
                  state_klima_fan_once = TRUE;
               }
               IF(!state_klima_passenger){
                  IF(!state_klima_fan_once){
                     IF(state_kompressor){
                        counter_klima_fan = 1;
                     }
                     IF(!state_kompressor){
                        counter_klima_fan = 0;
                     }
                  }
                  ELSE{
                     counter_klima_fan = 1;
                     state_klima_fan_once = TRUE;
                  }
               }
            }
            IF(!state_check_manuel_arka_fan){
               counter_arka_fan = 0;
            }
            IF(!state_check_manuel_vana_2){
               IF(!state_error_vana_2){
                  counter_vana_2 = 0;
               }
            }
         }
      }
//********************************************************************DRIVER**SIDE*****************************************************************//
//ISITMA-KALORIFER*********************************************************************************************************************************//
      IF(!state_max_on_in_auto_mode){
         IF(((sensor_driver_set_temp - sensor_driver_temp) <= 4) && ((sensor_driver_set_temp - sensor_driver_temp) > 2)){
            IF(!state_error_sensor_driver){
               state_klima_driver = FALSE;
            }
            IF(!state_check_manuel_on_fan){
               counter_on_fan = 1;
            }
            IF(!state_check_manuel_vana_1){
               IF(!state_error_vana_1){
                  counter_vana_1 = 1;
               }
            }
         }
      }
//*******************************************************************PASSENGER**SIDE***************************************************************//
//ISITMA-KALORIFER*********************************************************************************************************************************//
      IF(((sensor_passenger_set_temp - sensor_passenger_temp) <= 4)&&((sensor_passenger_set_temp - sensor_passenger_temp) > 2)){
         state_auto_mode_passenger_equal = FALSE;
         IF(!state_error_sensor_passenger){
            state_klima_passenger = FALSE;
         }
         IF(!state_check_manuel_klima_fan){
            IF(sensor_passenger_temp > 10){
               counter_klima_fan = 1;
               state_klima_fan_once = TRUE;
            }
            IF(sensor_passenger_temp <= 10){
               counter_klima_fan = 0;
            }
         }
         IF(!state_check_manuel_arka_fan){
            IF(state_klima_heating){
               counter_arka_fan = 0;
            }
            IF(!state_klima_heating){
               counter_arka_fan = 1;
            }
         }
         IF(!state_check_manuel_vana_2){
            IF(!state_error_vana_2){
               counter_vana_2 = 1;
            }
         }
      }
//********************************************************************DRIVER**SIDE*****************************************************************//
//ISITMA-KALORIFER*********************************************************************************************************************************//
      IF(!state_max_on_in_auto_mode){
         IF(((sensor_driver_set_temp - sensor_driver_temp) <= 6)&&((sensor_driver_set_temp - sensor_driver_temp) > 4)){
            IF(!state_error_sensor_driver){
               state_klima_driver = FALSE;
            }
            IF(!state_check_manuel_on_fan){
               counter_on_fan = 2;
            }
            IF(!state_check_manuel_vana_1){
               IF(!state_error_vana_1){
                  counter_vana_1 = 2;
               }
            }
         }
      }
//*******************************************************************PASSENGER**SIDE***************************************************************//
//ISITMA-KALORIFER*********************************************************************************************************************************//
      IF(((sensor_passenger_set_temp - sensor_passenger_temp) <= 6)&&((sensor_passenger_set_temp - sensor_passenger_temp) > 4)){
         state_auto_mode_passenger_equal = FALSE;
         IF(!state_error_sensor_passenger){
            state_klima_passenger = FALSE;
         }
         IF(!state_check_manuel_klima_fan){
            IF(sensor_passenger_temp > 10){
               counter_klima_fan = 1;
               state_klima_fan_once = TRUE;
            }
            IF(sensor_passenger_temp <= 10){
               counter_klima_fan = 0;
            }
         }
         IF(!state_check_manuel_arka_fan){
            IF(state_klima_heating){
               counter_arka_fan = 1;
            }
            IF(!state_klima_heating){
               counter_arka_fan = 2;
            }
         }
         IF(!state_check_manuel_vana_2){
            IF(!state_error_vana_2){
               counter_vana_2 = 2;
            }
         }
      }
//********************************************************************DRIVER**SIDE*****************************************************************//
//ISITMA-KALORIFER*********************************************************************************************************************************//
      IF(!state_max_on_in_auto_mode){
         IF((sensor_driver_set_temp - sensor_driver_temp) > 6){
            IF(!state_error_sensor_driver){
               state_klima_driver = FALSE;
            }
            IF(!state_check_manuel_on_fan){
               counter_on_fan = 3;
            }
            IF(!state_check_manuel_vana_1){
               IF(!state_error_vana_1){
                  counter_vana_1 = 2;
               }
            }
         }
      }
//*******************************************************************PASSENGER**SIDE***************************************************************//
//ISITMA-KALORIFER*********************************************************************************************************************************//
      IF((sensor_passenger_set_temp - sensor_passenger_temp) > 6){
         state_auto_mode_passenger_equal = FALSE;
         IF(!state_error_sensor_passenger){
            state_klima_passenger = FALSE;
         }
         IF(!state_check_manuel_klima_fan){
            IF(sensor_passenger_temp > 10){
               counter_klima_fan = 1;
               state_klima_fan_once = TRUE;
            }
            IF(sensor_passenger_temp <= 10){
               counter_klima_fan = 0;
            }
         }
         IF(!state_check_manuel_arka_fan){
            counter_arka_fan = 2;
         }
         IF(!state_check_manuel_vana_2){
            IF(!state_error_vana_2){
               counter_vana_2 = 2;
            }
         }
      }
//********************************************************************DRIVER**SIDE*****************************************************************//
//**********************************************************************************************************************************SOGUTMA-KLIMA**//
      IF(!state_max_on_in_auto_mode){
         IF(((sensor_driver_temp - sensor_driver_set_temp) <= 4)&&((sensor_driver_temp - sensor_driver_set_temp) > 2)){
            IF(!state_error_sensor_driver){
               IF((state_check_manuel_vana_1) && !((counter_vana_1 % 3) == 0)){
                  state_klima_driver = FALSE;
               }
               ELSE IF((state_check_manuel_on_fan) && ((counter_on_fan % 4) == 0)){
                  state_klima_driver = FALSE;
               }
               ELSE{
                  state_klima_driver = TRUE;
               }
            }
            IF(!state_check_manuel_on_fan){
               counter_on_fan = 1;
            }
            IF(!state_check_manuel_vana_1){
               IF(!state_error_vana_1){
                  counter_vana_1 = 0;
               }
            }
         }
      }
//*******************************************************************PASSENGER**SIDE***************************************************************//
//**********************************************************************************************************************************SOGUTMA-KLIMA**//
      IF(((sensor_passenger_temp - sensor_passenger_set_temp) <= 4)&&((sensor_passenger_temp - sensor_passenger_set_temp) > 2)){
         state_auto_mode_passenger_equal = FALSE;
         IF(!state_error_sensor_passenger){
            IF((state_check_manuel_vana_2) && !((counter_vana_2 % 3) == 0)){
               state_klima_passenger = FALSE;
            }
            ELSE{
               state_klima_passenger = TRUE;
            }
         }
         IF(!state_check_manuel_klima_fan){
            IF(sensor_passenger_temp > 10){
               counter_klima_fan = 1;
               state_klima_fan_once = TRUE;
            }
            IF(sensor_passenger_temp <= 10){
               counter_klima_fan = 0;
            }
         }
         IF(!state_check_manuel_arka_fan){
            counter_arka_fan = 0;
         }
         IF(!state_check_manuel_vana_2){
            IF(!state_error_vana_2){
               counter_vana_2 = 0;
            }
         }
      }
//********************************************************************DRIVER**SIDE*****************************************************************//
//**********************************************************************************************************************************SOGUTMA-KLIMA**//
      IF(!state_max_on_in_auto_mode){
         IF(((sensor_driver_temp - sensor_driver_set_temp) <= 6)&&((sensor_driver_temp - sensor_driver_set_temp) > 4)){
            IF(!state_error_sensor_driver){
               IF((state_check_manuel_vana_1) && !((counter_vana_1 % 3) == 0)){
                  state_klima_driver = FALSE;
               }
               ELSE IF((state_check_manuel_on_fan) && ((counter_on_fan % 4) == 0)){
                  state_klima_driver = FALSE;
               }
               ELSE{
                  state_klima_driver = TRUE;
               }
            }
            IF(!state_check_manuel_on_fan){
               counter_on_fan = 2;
            }
            IF(!state_check_manuel_vana_1){
               IF(!state_error_vana_1){
                  counter_vana_1 = 0;
               }
            }
         }
      }
//*******************************************************************PASSENGER**SIDE***************************************************************//
//**********************************************************************************************************************************SOGUTMA-KLIMA**//
      IF(((sensor_passenger_temp - sensor_passenger_set_temp) <= 6)&&((sensor_passenger_temp - sensor_passenger_set_temp) > 4)){
         state_auto_mode_passenger_equal = FALSE;
         IF(!state_error_sensor_passenger){
            IF((state_check_manuel_vana_2) && !((counter_vana_2 % 3) == 0)){
               state_klima_passenger = FALSE;
            }
            ELSE{
               state_klima_passenger = TRUE;
            }
         }
         IF(!state_check_manuel_klima_fan){
            IF(sensor_passenger_temp > 10){
               counter_klima_fan = 2;
               state_klima_fan_once = TRUE;
            }
            IF(sensor_passenger_temp <= 10){
               counter_klima_fan = 0;
            }
         }
         IF(!state_check_manuel_arka_fan){
            counter_arka_fan = 0;
         }
         IF(!state_check_manuel_vana_2){
            IF(!state_error_vana_2){
               counter_vana_2 = 0;
            }
         }
      }
//********************************************************************DRIVER**SIDE*****************************************************************//
//**********************************************************************************************************************************SOGUTMA-KLIMA**//
      IF(!state_max_on_in_auto_mode){
         IF((sensor_driver_temp - sensor_driver_set_temp) > 6){
            IF(!state_error_sensor_driver){
               IF((state_check_manuel_vana_1) && !((counter_vana_1 % 3) == 0)){
                  state_klima_driver = FALSE;
               }
               ELSE IF((state_check_manuel_on_fan) && ((counter_on_fan % 4) == 0)){
                  state_klima_driver = FALSE;
               }
               ELSE{
                  state_klima_driver = TRUE;
               }
            }
            IF(!state_check_manuel_on_fan){
               counter_on_fan = 3;
            }
            IF(!state_check_manuel_vana_1){
               IF(!state_error_vana_1){
                  counter_vana_1 = 0;
               }
            }
         }
      }
//*******************************************************************PASSENGER**SIDE***************************************************************//
//**********************************************************************************************************************************SOGUTMA-KLIMA**//
      IF((sensor_passenger_temp - sensor_passenger_set_temp) > 6){
         state_auto_mode_passenger_equal = FALSE;
         IF(!state_error_sensor_passenger){
            IF((state_check_manuel_vana_2) && !((counter_vana_2 % 3) == 0)){
               state_klima_passenger = FALSE;
            }
            ELSE{
               state_klima_passenger = TRUE;
            }
         }
         IF(!state_check_manuel_klima_fan){
            IF(sensor_passenger_temp > 10){
               counter_klima_fan = 3;
               state_klima_fan_once = TRUE;
            }
            IF(sensor_passenger_temp <= 10){
               counter_klima_fan = 0;
            }
         }
         IF(!state_check_manuel_arka_fan){
            counter_arka_fan = 0;
         }
         IF(!state_check_manuel_vana_2){
            IF(!state_error_vana_2){
               counter_vana_2 = 0;
            }
         }
      }
//****************************************************************ONCE**ENTERANCE**TO**AC**********************************************************//
      IF(state_check_once_entrance_to_ac){
         Setting_Klima();
         IF(abs(sensor_driver_temp - sensor_driver_set_temp) <= 2){
            counter_on_fan = 0;
            counter_vana_1 = 0;
         }
         IF(abs(sensor_passenger_temp - sensor_passenger_set_temp) <= 2){
            state_auto_mode_passenger_equal = TRUE;
            IF((state_klima_passenger) || (state_klima_driver)){
               counter_klima_fan = 1;
               state_klima_fan_once = TRUE;
            }
            ELSE{
               IF(!state_klima_fan_once){
                  IF(state_kompressor){
                     counter_klima_fan = 1;
                  }
                  IF(!state_kompressor){
                     counter_klima_fan = 0;
                  }
               }
               ELSE{
                  counter_klima_fan = 1;
                  state_klima_fan_once = TRUE;
               }
            }
            counter_arka_fan = 0;
            counter_vana_2 = 0;
         }
         state_check_once_entrance_to_ac = FALSE;
      }
   }
//*************************************************************************************************************************************************//
//****************************************************CHANGE**PLACE**OF**8**BIT**OF**16**BIT**DATA*************************************************//
//*************************************************************************************************************************************************//
   INT16 Change_8_Bits_Of_16_Bit_Data(INT16 _16_bit_data_will_changed){
      _16_bit_data_temporary = _16_bit_data_will_changed << 8;
      _16_bit_data_will_changed = _16_bit_data_will_changed >> 8;
      _16_bit_data_will_changed = _16_bit_data_will_changed | _16_bit_data_temporary;
      RETURN _16_bit_data_will_changed;
   }
//*************************************************************************************************************************************************//
//*********************************************************************ORRER***********************************************************************//
//*************************************************************************************************************************************************//
   INT16 ORer_Two_Number(INT8 number_1, INT8 number_2){
      orrer_digit_10 = number_1;
      orrer_digit_1  = number_2;
      orrer_digit_10  = orrer_digit_10 << 8;
      orrer_result   = orrer_digit_10 | orrer_digit_1;
      RETURN orrer_result;
   }
//*************************************************************************************************************************************************//
//********************************************************************DISPLAY**********************************************************************//
//*************************************************************************************************************************************************//
   VOID Write_Display(INT16 write_display_integer){
      write_display_integer = Change_8_Bits_Of_16_Bit_Data(write_display_integer);
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
      leds_register = leds_register | process_counter_1;
      Write_Led(leds_register);
   }
//*************************************************************************************************************************************************//
//******************************************************************TURN**OFF**LED*****************************************************************//
//*************************************************************************************************************************************************//
   VOID OFFer(INT16 process_counter_2){
      leds_register = leds_register & process_counter_2;
      Write_Led(leds_register);
   }
//*************************************************************************************************************************************************//
//***********************************************************AUTO**MODE**LED**CONTROLLER***********************************************************//
//*************************************************************************************************************************************************//
   VOID Controller_AC_Led(){
//***********************************************************IF**PROGRAM**IN**AUTOMATIC**MODE******************************************************//
      IF(!state_ac_oner){
//************************************************************AC**LED**TURN**ON**CONTINUOUSLY******************************************************//
         ONer(AC_ON);
      }
//*********************************************************IF**PROGRAM**IN**HALF-AUTOMATIC**MODE***************************************************//
      IF(state_ac_oner){
//*******************************************************AC**LED**TURN**ON**AND**OFF**SEQUENTALLIY*************************************************//
         AC_ONer();
      }
   }
//*************************************************************************************************************************************************//
//************************************************************AUTOMATIC**LED**TURN**ON*************************************************************//
//*************************************************************************************************************************************************//
   VOID AC_ONer(){
      counter_ac_oner++;
      IF(counter_ac_oner == 6000){
         OFFer(AC_DEFAULT);
      }
      IF(counter_ac_oner == 12000){
         ONer(AC_ON);
         counter_ac_oner = 0;
      }
   }
//*************************************************************************************************************************************************//
//***************************************************************READ**TEMPERATURE*****************************************************************//
//*************************************************************************************************************************************************//
   VOID Read_Temp(){
//READING**AND**CALCULATING**TEMPERATURE***********************************************************************************************************//
      IF((!state_error_sensor_driver) && (!state_error_sensor_passenger)){
         SET_ADC_CHANNEL(CHANNEL_Sensor_Driver);
         DELAY_MS(20);
         temp_2 = READ_ADC();
         IF(abs(temp_2 - temp_1) > 9){
            sensor_driver_temp = ((temp_2 - 290) / (11));
            temp_1 = temp_2;
         }
         SET_ADC_CHANNEL(CHANNEL_Sensor_Passenger);
         DELAY_MS(20);
         temp_4 = READ_ADC();
         IF(abs(temp_4 - temp_3) > 9){
            sensor_passenger_temp = ((temp_4 - 290) / (11));
            temp_3 = temp_4;
         }
      }
   }
//*************************************************************************************************************************************************//
//*******************************************************************WRITE**HELLO******************************************************************//
//*************************************************************************************************************************************************//
   VOID Write_Hello(){
      DELAY_MS(1500);
      FOR(counter_write_hello = 0; counter_write_hello < 8; counter_write_hello++){
         register_write_hello = register_write_hello << 8;
         register_write_hello = register_write_hello | display_hello[counter_write_hello];
         Write_Display(register_write_hello);
         DELAY_MS(2000);
      }
   }
//*************************************************************************************************************************************************//
//******************************************************************WRITE**BYE**BYE****************************************************************//
//*************************************************************************************************************************************************//
   VOID Write_Bye_Bye(){
      DELAY_MS(1500);
      FOR(counter_write_bye_bye = 0; counter_write_bye_bye < 11; counter_write_bye_bye++){
         register_write_bye_bye = register_write_bye_bye << 8;
         register_write_bye_bye = register_write_bye_bye | display_bye_bye[counter_write_bye_bye];
         Write_Display(register_write_bye_bye);
         DELAY_MS(2000);
      }
   }
//*************************************************************************************************************************************************//
//*******************************************************************READ**MOTOR*******************************************************************//
//*************************************************************************************************************************************************//
   VOID Read_Motor_Temiz_Hava(){
      SET_ADC_CHANNEL(CHANNEL_Temiz_Hava_Pot);
      DELAY_MS(20);
      motor_pot_temiz_hava = READ_ADC();
   }
   VOID Read_Motor_Cam(){
      SET_ADC_CHANNEL(CHANNEL_Cam_Pot);
      DELAY_MS(20);
      motor_pot_cam = read_adc();
   }
   VOID Read_Motor_Vana_1(){
      SET_ADC_CHANNEL(CHANNEL_Vana_1);
      DELAY_MS(20);
      motor_pot_vana_1 = READ_ADC();
   }
   VOID Read_Motor_Vana_2(){
      SET_ADC_CHANNEL(CHANNEL_Vana_2);
      DELAY_MS(20);
      motor_pot_vana_2 = READ_ADC();
   }
   VOID Read_Current_Temiz_Hava_Cam(){
      SET_ADC_CHANNEL(CHANNEL_Cam_Temiz_Hava_Current);
      DELAY_MS(20);
      current_temiz_hava_cam = READ_ADC();
   }
   VOID Read_Current_Vana(){
      SET_ADC_CHANNEL(CHANNEL_Vana_Current);
      DELAY_MS(20);
      current_vana_value = READ_ADC();
   }
//*************************************************************************************************************************************************//
//****************************************************************MOVEMENT**MOTOR******************************************************************//
//*************************************************************************************************************************************************//
//********************************************************************VANA**1**********************************************************************//
   VOID Turn_Right_Vana_1(){
      IF(state_correct_direction_vana_1){
         OUTPUT_HIGH(VANA_1_EN);
         OUTPUT_HIGH(VANA_1_IN_1);
         OUTPUT_LOW(VANA_1_IN_2);
      }
      IF(!state_correct_direction_vana_1){
         OUTPUT_HIGH(VANA_1_EN);
         OUTPUT_LOW(VANA_1_IN_1);
         OUTPUT_HIGH(VANA_1_IN_2);
      }
   }
   VOID Turn_Left_Vana_1(){
      IF(state_correct_direction_vana_1){
         OUTPUT_HIGH(VANA_1_EN);
         OUTPUT_LOW(VANA_1_IN_1);
         OUTPUT_HIGH(VANA_1_IN_2);
      }
      IF(!state_correct_direction_vana_1){
         OUTPUT_HIGH(VANA_1_EN);
         OUTPUT_HIGH(VANA_1_IN_1);
         OUTPUT_LOW(VANA_1_IN_2);
      }
   }
   VOID Stop_Vana_1(){
      OUTPUT_LOW(VANA_1_EN);
      OUTPUT_LOW(VANA_1_IN_1);
      OUTPUT_LOW(VANA_1_IN_2);
   }
//********************************************************************VANA**2**********************************************************************//
   VOID Turn_Right_Vana_2(){
      IF(state_correct_direction_vana_2){
         OUTPUT_HIGH(VANA_2_EN);
         OUTPUT_LOW(VANA_2_IN_1);
         OUTPUT_HIGH(VANA_2_IN_2);
      }
      IF(!state_correct_direction_vana_2){
         OUTPUT_HIGH(VANA_2_EN);
         OUTPUT_HIGH(VANA_2_IN_1);
         OUTPUT_LOW(VANA_2_IN_2);
      }
   }
   VOID Turn_Left_Vana_2(){
      IF(state_correct_direction_vana_2){
         OUTPUT_HIGH(VANA_2_EN);
         OUTPUT_HIGH(VANA_2_IN_1);
         OUTPUT_LOW(VANA_2_IN_2);
      }
      IF(!state_correct_direction_vana_2){
         OUTPUT_HIGH(VANA_2_EN);
         OUTPUT_LOW(VANA_2_IN_1);
         OUTPUT_HIGH(VANA_2_IN_2);
      }
   }
   VOID Stop_Vana_2(){
      OUTPUT_LOW(VANA_2_EN);
      OUTPUT_LOW(VANA_2_IN_1);
      OUTPUT_LOW(VANA_2_IN_2);
   }
//*******************************************************************TEMIZ**HAVA*******************************************************************//
   VOID Turn_Right_Temiz_Hava(){
      IF(state_correct_direction_temiz_hava){
         OUTPUT_HIGH(TEMIZ_HAVA_EN);
         OUTPUT_HIGH(TEMIZ_HAVA_IN_1);
         OUTPUT_LOW(TEMIZ_HAVA_IN_2);
      }
      IF(!state_correct_direction_temiz_hava){
         OUTPUT_HIGH(TEMIZ_HAVA_EN);
         OUTPUT_LOW(TEMIZ_HAVA_IN_1);
         OUTPUT_HIGH(TEMIZ_HAVA_IN_2);
      }
   }
   VOID Turn_Left_Temiz_Hava(){
      IF(state_correct_direction_temiz_hava){
         OUTPUT_HIGH(TEMIZ_HAVA_EN);
         OUTPUT_LOW(TEMIZ_HAVA_IN_1);
         OUTPUT_HIGH(TEMIZ_HAVA_IN_2);
      }
      IF(!state_correct_direction_temiz_hava){
         OUTPUT_HIGH(TEMIZ_HAVA_EN);
         OUTPUT_HIGH(TEMIZ_HAVA_IN_1);
         OUTPUT_LOW(TEMIZ_HAVA_IN_2);
      }
   }
   VOID Stop_Temiz_Hava(){
      OUTPUT_LOW(TEMIZ_HAVA_EN);
      OUTPUT_LOW(TEMIZ_HAVA_IN_1);
      OUTPUT_LOW(TEMIZ_HAVA_IN_2);
   }
//***********************************************************************CAM***********************************************************************//
   VOID Turn_Right_Cam(){
      IF(state_correct_direction_cam){
         OUTPUT_HIGH(CAM_EN);
         OUTPUT_HIGH(CAM_IN_1);
         OUTPUT_LOW(CAM_IN_2);
      }
      IF(!state_correct_direction_cam){
         OUTPUT_HIGH(CAM_EN);
         OUTPUT_LOW(CAM_IN_1);
         OUTPUT_HIGH(CAM_IN_2);
      }
   }
   VOID Turn_Left_Cam(){
      IF(state_correct_direction_cam){
         OUTPUT_HIGH(CAM_EN);
         OUTPUT_LOW(CAM_IN_1);
         OUTPUT_HIGH(CAM_IN_2);
      }
      IF(!state_correct_direction_cam){
         OUTPUT_HIGH(CAM_EN);
         OUTPUT_HIGH(CAM_IN_1);
         OUTPUT_LOW(CAM_IN_2);
      }
   }
   VOID Stop_Cam(){
      OUTPUT_LOW(CAM_EN);
      OUTPUT_LOW(CAM_IN_1);
      OUTPUT_LOW(CAM_IN_2);
   }
//*************************************************************************************************************************************************//
//***********************************************************************END***********************************************************************//
//*************************************************************************************************************************************************//
