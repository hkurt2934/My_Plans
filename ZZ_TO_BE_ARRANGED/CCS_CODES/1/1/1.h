//*************************************************************************************************************************************************//
//******************************************************************HEADER**FILE*******************************************************************//
//*************************************************************************************************************************************************//
#INCLUDE <16F1508.h>
//*************************************************************************************************************************************************//
#DEVICE ADC = 10
//*************************************************************************************************************************************************//
#FUSES NOWDT
#FUSES NOLVP                                                 
#FUSES NOPUT
#FUSES NOWRT
#FUSES NOMCLR
//*************************************************************************************************************************************************//
#USE DELAY(INTERNAL = 4000000)
//*************************************************************************************************************************************************//
//******************************************************************PIN***DEFINES******************************************************************//
//*************************************************************************************************************************************************//
//******************************************************************************************************************************************INPUT**//
#DEFINE SWITCH_BREAKE_1                                        PIN_A4
#DEFINE SWITCH_BREAKE_2                                        PIN_A5
#DEFINE SWITCH_4WD                                             PIN_A2
#DEFINE SWITCH_DIFF_LOCK_1                                     PIN_C5
#DEFINE SWITCH_DIFF_LOCK_2                                     PIN_C4
//*****************************************************************************************************************************************OUTPUT**//
#DEFINE STOP_LAMB_1                                            PIN_B6
#DEFINE STOP_LAMB_2                                            PIN_C2
#DEFINE SELENOID_VALF_DIFF_LOCK                                PIN_B7
#DEFINE SELENOID_VALF_4WD                                      PIN_C3
#DEFINE BST5016_1_D_EN                                         PIN_C7
#DEFINE BST5016_1_D_SEL                                        PIN_C6
#DEFINE BST5016_2_D_EN                                         PIN_B5
#DEFINE BST5016_2_D_SEL                                        PIN_B4
//***************************************************************************************************************************************ADC**PIN**//
#DEFINE ADC_BTS5016_1                                          PIN_C1
#DEFINE ADC_BTS5016_2                                          PIN_C0
#DEFINE ADC_BTS5016_1_CURRENT                                  sAN5
#DEFINE ADC_BTS5016_2_CURRENT                                  sAN4
#DEFINE ADC_BTS5016_1_CHANNEL                                  5
#DEFINE ADC_BTS5016_2_CHANNEL                                  4
#DEFINE ADC_BTS5016_1_VALUE                                    500
#DEFINE ADC_BTS5016_2_VALUE                                    500
//*************************************************************************************************************************************************//
//*******************************************************************FUNCTIONs*********************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Input();
VOID Controller_Output();
VOID Setting();
VOID Read_ADC_BTS5016_1();
VOID Read_ADC_BTS5016_2();
VOID Controller_Short_Current();
//*************************************************************************************************************************************************//
//*******************************************************************VARIABLEs*********************************************************************//
//*************************************************************************************************************************************************//
INT32 adc_value_bts5016_1                                = 0x00000000;
INT32 adc_value_bts5016_2                                = 0x00000000;
INT16 value_temporary                                    = 0x0000;
INT16 current_value_diff_lock                            = 0x0000;
INT16 current_value_4wd                                  = 0x0000;
INT16 current_value_stop_lamb_1                          = 0x0000;
INT16 current_value_stop_lamb_2                          = 0x0000;
INT16 counter_controller_short_current                   = 0x0000;
INT32 register_adc                                       = 0x00000000;
BOOLEAN state_control_switch_breake_1                    = FALSE;
BOOLEAN state_control_switch_breake_2                    = FALSE;
BOOLEAN state_control_switch_4wd                         = FALSE;
BOOLEAN state_control_switch_diff_lock_1                 = FALSE;
BOOLEAN state_control_switch_diff_lock_2                 = FALSE;
BOOLEAN state_error_diff_lock                            = FALSE;
BOOLEAN state_error_4wd                                  = FALSE;
BOOLEAN state_error_stop_lamb_1                          = FALSE;
BOOLEAN state_error_stop_lamb_2                          = FALSE;
BOOLEAN state_special_statuation_for_brakes              = TRUE;
BOOLEAN state_diff_lock_out_on                           = FALSE;
//*************************************************************************************************************************************************//
//*******************************************************************SETTING***********************************************************************//
//*************************************************************************************************************************************************//
VOID Setting(){
   OUTPUT_A(0x00);
   OUTPUT_B(0x00);
   OUTPUT_C(0x00);
   DELAY_MS(4000);
   SET_TRIS_A(0x34);
   SET_TRIS_B(0x00);
   SET_TRIS_C(0x33);
//****************************************************************************************************************************SETTING**ADC**PORTs**//
   register_adc                  = register_adc | ADC_BTS5016_1_CURRENT;
   register_adc                  = register_adc | ADC_BTS5016_2_CURRENT;
   register_adc                  = register_adc | VSS_VDD;
   SETUP_ADC_PORTS(register_adc);
   SETUP_ADC(RTCC_INTERNAL|ADC_CLOCK_DIV_8);
   DELAY_MS(50);
}
//*************************************************************************************************************************************************//
//****************************************************************CONTROL**INPUT*******************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Input(){
//**********************************************************************************************************************CONTROL**SWITCH**BREAKE_1**//
      IF(!INPUT(SWITCH_BREAKE_1)){
         state_control_switch_breake_1             = TRUE;
         state_special_statuation_for_brakes       = TRUE;
      }
      IF(INPUT(SWITCH_BREAKE_1)){
         state_control_switch_breake_1             = FALSE;
      }
//**********************************************************************************************************************CONTROL**SWITCH**BREAKE_2**//
      IF(!INPUT(SWITCH_BREAKE_2)){
         state_control_switch_breake_2             = TRUE;
         state_special_statuation_for_brakes       = TRUE;
      }
      IF(INPUT(SWITCH_BREAKE_2)){
         state_control_switch_breake_2             = FALSE;
      }
//***************************************************************************************************************************CONTROL**SWITCH**4WD**//
      IF(!INPUT(SWITCH_4WD)){
         state_control_switch_4wd                  = TRUE;
      }
      IF(INPUT(SWITCH_4WD)){
         state_control_switch_4wd                  = FALSE;
      }
//******************************************************************************************************************CONTROL**SWITCH**DIFF**LOCK_1**//
      IF(!INPUT(SWITCH_DIFF_LOCK_1)){
         state_control_switch_diff_lock_1          = TRUE;
      }
      IF(INPUT(SWITCH_DIFF_LOCK_1)){
         state_control_switch_diff_lock_1          = FALSE;
      }
//******************************************************************************************************************CONTROL**SWITCH**DIFF**LOCK_2**//
      IF(!INPUT(SWITCH_DIFF_LOCK_2)){
         state_control_switch_diff_lock_2          = TRUE;
      }
      IF(INPUT(SWITCH_DIFF_LOCK_2)){
         state_control_switch_diff_lock_2          = FALSE;
      }
}
//*************************************************************************************************************************************************//
//*****************************************************************CONTROL**OUTPUT*****************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Output(){
//**************************************************************************************************************************CONTROL**STOP**LAMB_1**//
   IF(!state_error_stop_lamb_1){
      IF((state_control_switch_breake_1) || (state_control_switch_breake_2)){
         OUTPUT_HIGH(STOP_LAMB_1);
      }
      ELSE{
         OUTPUT_LOW(STOP_LAMB_1);
      }
   }
   ELSE{
      OUTPUT_LOW(STOP_LAMB_1);
   }
//**************************************************************************************************************************CONTROL**STOP**LAMB_2**//
   IF(!state_error_stop_lamb_2){
      IF((state_control_switch_breake_1) || (state_control_switch_breake_2)){
         OUTPUT_HIGH(STOP_LAMB_2);
      }
      ELSE{
         OUTPUT_LOW(STOP_LAMB_2);
      }
   }
   ELSE{
      OUTPUT_LOW(STOP_LAMB_2);  
   }
//*******************************************************************************************************************CONTROL**SELENOID**VALF**4WD**//
   IF(!state_error_4wd){
      IF((!state_control_switch_breake_1) || (!state_control_switch_breake_2)){
         IF(state_control_switch_4wd){
            OUTPUT_HIGH(SELENOID_VALF_4WD);
         }
         ELSE{
            OUTPUT_LOW(SELENOID_VALF_4WD);
         }
      }
      ELSE{
         OUTPUT_LOW(SELENOID_VALF_4WD);
      }
   }
   ELSE{
      OUTPUT_LOW(SELENOID_VALF_4WD);
   }
//************************************************************************************************************CONTROL**SELENOID**VALF**DIFF**LOCK**//
   IF(!state_error_diff_lock){
      IF((!state_control_switch_breake_1) && (!state_control_switch_breake_2)){
         IF(state_special_statuation_for_brakes){
            IF((state_control_switch_diff_lock_1) && (state_control_switch_diff_lock_2)){
               state_special_statuation_for_brakes = FALSE;
               OUTPUT_HIGH(SELENOID_VALF_DIFF_LOCK);
               state_diff_lock_out_on              = TRUE;
            }
         }
         IF(!state_special_statuation_for_brakes){
            IF(state_diff_lock_out_on){
               IF(state_control_switch_diff_lock_1){
                  OUTPUT_HIGH(SELENOID_VALF_DIFF_LOCK);
                  state_diff_lock_out_on           = TRUE;
               }
               ELSE IF((!state_control_switch_diff_lock_1) && (!state_control_switch_diff_lock_2)){
                  OUTPUT_LOW(SELENOID_VALF_DIFF_LOCK);
                  state_diff_lock_out_on           = FALSE;
               }
            }
            IF(!state_diff_lock_out_on){
               IF(!state_control_switch_diff_lock_1){
                  OUTPUT_LOW(SELENOID_VALF_DIFF_LOCK);
                  state_diff_lock_out_on           = FALSE;
               }
               ELSE IF((state_control_switch_diff_lock_1) && (!state_control_switch_diff_lock_2)){
                  OUTPUT_HIGH(SELENOID_VALF_DIFF_LOCK);
                  state_diff_lock_out_on           = TRUE;
               }
            }
         }
      }
      ELSE{
         OUTPUT_LOW(SELENOID_VALF_DIFF_LOCK);
         state_diff_lock_out_on                    = FALSE;
      }
   }
   ELSE{
      OUTPUT_LOW(SELENOID_VALF_DIFF_LOCK);
      state_diff_lock_out_on                       = FALSE;
   }
}
//*************************************************************************************************************************************************//
//*****************************************************************SHORT**CURRENT******************************************************************//
//*************************************************************************************************************************************************//
VOID Controller_Short_Current(){
   DELAY_MS(100);
//**************************************************************************************************************************************BST5016_1**//
//*************************************************************************************************************************************DIFF**LOCK**//
   OUTPUT_HIGH(BST5016_1_D_EN);
   OUTPUT_LOW(BST5016_1_D_SEL);
   Read_ADC_BTS5016_1();
   current_value_diff_lock = adc_value_bts5016_1;
   IF(current_value_diff_lock > ADC_BTS5016_1_VALUE){
      state_error_diff_lock = TRUE;
      OUTPUT_LOW(SELENOID_VALF_DIFF_LOCK);
   }
//********************************************************************************************************************************************4WD**//
   OUTPUT_HIGH(BST5016_1_D_EN);
   OUTPUT_HIGH(BST5016_1_D_SEL);
   Read_ADC_BTS5016_1();
   current_value_4wd = adc_value_bts5016_1;
   IF(current_value_4wd > ADC_BTS5016_1_VALUE){
      state_error_4wd = TRUE;
      OUTPUT_LOW(SELENOID_VALF_4WD);
   }
//**************************************************************************************************************************************BST5016_2**//
//**********************************************************************************************************************************STOP**LAMB**1**//
   OUTPUT_HIGH(BST5016_2_D_EN);
   OUTPUT_LOW(BST5016_2_D_SEL);
   Read_ADC_BTS5016_2();
   current_value_stop_lamb_1 = adc_value_bts5016_2;
   IF(current_value_stop_lamb_1 > ADC_BTS5016_2_VALUE){
      state_error_stop_lamb_1 = TRUE;
      OUTPUT_LOW(STOP_LAMB_1);
   }
//**********************************************************************************************************************************STOP**LAMB**2**//
   OUTPUT_HIGH(BST5016_2_D_EN);
   OUTPUT_HIGH(BST5016_2_D_SEL);
   Read_ADC_BTS5016_2();
   current_value_stop_lamb_2 = adc_value_bts5016_2;
   IF(current_value_stop_lamb_2 > ADC_BTS5016_2_VALUE){
      state_error_stop_lamb_2 = TRUE;
      OUTPUT_LOW(STOP_LAMB_2);
   }
}
//*************************************************************************************************************************************************//
//*******************************************************************READ**ADC*********************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
VOID Read_ADC_BTS5016_1(){
   adc_value_bts5016_1 = 0;
   FOR(INT i = 0; i < 10; i++){
      SET_ADC_CHANNEL(ADC_BTS5016_1_CHANNEL);
      DELAY_MS(2);
      value_temporary = READ_ADC();
      adc_value_bts5016_1 = adc_value_bts5016_1 + value_temporary;
   }
   adc_value_bts5016_1 = (adc_value_bts5016_1 / 10);
}
//*************************************************************************************************************************************************//
VOID Read_ADC_BTS5016_2(){
   adc_value_bts5016_2 = 0;
   FOR(INT j = 0; j < 10; j++){
      SET_ADC_CHANNEL(ADC_BTS5016_2_CHANNEL);
      DELAY_MS(2);
      value_temporary = READ_ADC();
      adc_value_bts5016_2 = adc_value_bts5016_2 + value_temporary;
   }
   adc_value_bts5016_2 = (adc_value_bts5016_2 / 10);
}
//*************************************************************************************************************************************************//
//*********************************************************************END*************************************************************************//
//*************************************************************************************************************************************************//
