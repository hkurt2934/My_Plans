//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
//******************************************************************MAIN**FILE*********************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
#INCLUDE <_22_03_2019_3_KARSAN_JEST_1.h>
//*************************************************************************************************************************************************//
//****************************************************************MAIN***FUNCTION******************************************************************//
//*************************************************************************************************************************************************//
   VOID MAIN(){
//********************************************************************SETTING**********************************************************************//
      Setting();
//****************************************************************CHECKING**KLAPE******************************************************************//
      Controller_Klape();
//****************************************************************SCANNING**KLAPE******************************************************************//
      Scan_Klape_Time();
//*****************************************************START**WORKING**ACCORDING**TO**EEPROM**VALUE************************************************//
      Work_According_To_EEPROM_Value();
//**********************************************************SHOW**TEMPERATURE**STARTING************************************************************//
      Show_Temperature_Starting();
//*******************************************************************WHILE***LOOP******************************************************************//
      WHILE(TRUE){
//******************************************************READ**AND**CONTROL**KLAPEs**EVERY**TIME****************************************************//
         Controller_Error_And_Temperature();
//*************************************************************WHEN**PUSH**THE**AC**BUTTON*********************************************************//
         Button_Controller_AC();
//*************************************************************WHEN**PUSH**THE**MAX**BUTTON********************************************************//
         Button_Controller_Max();
//**********************************************************WHEN**PUSH**THE**KLIMA**FAN**BUTTON****************************************************//
         Button_Controller_Klima_Fan();
//***********************************************************WHEN**PUSH**THE**ON**FAN**BUTTON******************************************************//
         Button_Controller_On_Fan();
//**********************************************************WHEN**PUSH**THE**ARKA**FAN**BUTTON*****************************************************//
         Button_Controller_Arka_Fan();
//*********************************************************WHEN**PUSH**THE**TEMIZ**HAVA**BUTTON****************************************************//
         Button_Controller_Cam();
//*********************************************************WHEN**PUSH**THE**TEMIZ**HAVA**BUTTON****************************************************//
         Button_Controller_Temiz_Hava();
//***********************************************************WHEN**PUSH**THE**VANA_1**BUTTON*******************************************************//
         Button_Controller_Vana_1();
//****************************************************WHEN**PUSH**THE**INCREASE**DECREASE**BUTTON**************************************************//
         Button_Controller_Increase_Decrease();
//*******************************************************************WHILE***LOOP******************************************************************//
         Controller_Functions();
//*******************************************************************WHILE***LOOP******************************************************************//
         Controller_Led_Functions();
//*******************************************************************AUTOMATIC**MODE***************************************************************//
         Controller_Klima();
//*******************************************************************AUTOMATIC**MODE***************************************************************//
         Controller_And_Compare_Temp_And_Set_Temp();
//*******************************************************************AUTOMATIC**MODE***************************************************************//
         
//*********************************************************************END**WHILE******************************************************************//
      }
//*********************************************************************END**MAIN*******************************************************************//
   }
//*************************************************************************************************************************************************//
//*******************************************************************END**THE**PROGRAM*************************************************************//
//*************************************************************************************************************************************************//
//*************************************************************************************************************************************************//
//**************************************************************EXPLANATION**FOR**THIS**CODE*******************************************************//
//*************************************************************************************************************************************************//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                    01) KONTAK ILK AÇILDIGINDA CAM, TEMIZ HAVA VE VANA DEGERLERI HAFIZADAN                                   **//
//**                                        OKUNUP SON KALDIGI KONUMDAN LEDLER YANAR.                                                            **//
//**                                        BU SIRADA EKRANDA 88 YAZAR.                                                                          **//
//**                                    02) OGRENME BASLAMASINDAN OGRENME BITENE KADAR EKRANDA -- YAZAR.                                         **//
//**                                    03) OGRENME SURESINCE TUM TUSLAR KILITLIDIR.                                                             **//
//**                                    04) OGRENME BITTIGINDE EKRANDA IC SICAKLI DEGERI GOSTERILIR.                                             **//
//**                                    05) OGRENME BITTIGINDE CAM, TEMIZ HAVA VE VANA KONUMU PANELDEKI                                          **//
//**                                        LED KONUMUNA GELIR.                                                                                  **//
//**                                    06) AC TUSU BASILI DEGILKEN =>                                                                           **//
//**                                        a) FANLAR VE KLAPELER MANUEL KONTROLE EDILIR.                                                        **//
//**                                        b) HATA OLDUGUNDA EKRANDA HATALAR SIRAYLA GOSTERILIR.                                                **//
//**                                        c) SENSOR ARIZASINDA IC SICAKLIK GOSTERILMEZ E1 VE DIGER HATALAR                                     **//
//**                                           GOSTERILIR.                                                                                       **//
//**                                        d) SENSOR ARIZASI YOKSA HATALARLA BIRLIKTE ORTAM SICAKLIGI                                           **//
//**                                           GOSTERILIR.                                                                                       **//
//**                                        e) SET TUSLARINA BASILDIGINDA SET DEGERI 2 sn. YANAR VE SONRA                                        **//
//**                                           HATA VARSA HATALARLA BIRLIKTE IC SICAKLIGI, HATA YOKSA                                            **//
//**                                           IC SICAKLIGI GOSTERMEYE DEVAM EDER.                                                               **//
//**                                        f) KOMPRESSOR VE KONDANSER KAPALIDIR.                                                                **//
//**                                    07) MAX TUSU BASILIYKEN =>                                                                               **//
//**                                        a) MAX LEDI YANAR.                                                                                   **//
//**                                        b) ON FAN 3.DEVIRDE DONER.                                                                           **//
//**                                        c) CAM, CAM KONUMUNA GELIR.                                                                          **//
//**                                        d) TEMIZ HAVA, KAPANIR-DIS KONUMUNA GELIR.                                                           **//
//**                                        e) VANA, 2. KONUMA GELIR-TAM ACILIR.                                                                 **//
//**                                        f) AC TUSUNA BASILIRSA MAX DAN CIKAR AC FONKSIYONLARI                                                **//
//**                                           YERINE GETIRLIR                                                                                   **//
//**                                        g) MAX DA KONUMLARI DEGISEN FONKSYONLAR MAX DAN CIKILDIGINDA                                         **//
//**                                           MAX A GIRMEDEN ONCEKI KONUMLARINA GELIR.                                                          **//
//**                                        h) MAX DA KONUMLARI DEGISEN FONKSIYONLARDAN HERHANGI BIRINE                                          **//
//**                                           BASILDIGINDA MAXDAN CIKAR VE ESKI KONUMLARINA DONER                                               **//
//**                                        i) ARKA FAN VE KLIMA FAN FONKSIYONLARI MANUEL KONTROL EDILIR.                                        **//
//**                                        j) ARKA FAN KLIMA FAN BUTONLARINA BASILDIGINDA MAXDAN CIKMAZ.                                        **//
//**                                    08) AC TUSUNA BASILIYKEN =>                                                                              **//
//**                                        a) AC LEDI YANAR.                                                                                    **//
//**                                        b) KLIMA FAN 3.DEVIRDE CALISIR.                                                                      **//
//**                                        c) KLIMA FAN MINUMUM 1.DEVIRDE CALISIR. 1-2-3-1-2 SEKLINDE.                                          **//
//**                                        d) AC TUSUNA BASILIP KAPATILIRSA KLIMA FAN KAPALI KONUMA                                             **//
//**                                           GECER VE MANUEL DEVAM EDER.                                                                       **//
//**                                        e) VANA 1.KADEME-KAPALI KONUMA GELIR VE VANA BUTONU CALISMAZ.                                        **//
//**                                        f) KLIMA FAN, ON FAN, CAM, TEMIZ HAVA, VANA MANUEL KONTROL EDILIR.                                   **//
//**                                        g) SET DEGERI IC SICAKLIK DEGERINDEN 2 VEYA DAHA FAZLA BUYUK OLURSA                                  **//
//**                                           ONCE 2 SN SONRA KONDANSER SONRA 10 SN SONRA KOMPRESSOR DEVREYE                                    **//
//**                                           GIRER.                                                                                            **//
//**                                        h) SET DEGERI ILE IC SICAKLI DEGERI ARASINDAKI FARK SIFIRLANIR YADA                                  **//
//**                                           IC SICAKLIK DEGERI SET DEGERINDE FAZLA OLURSA ONCE 2 SN SONRA                                     **//
//**                                           KOMPRESSOR SONRA 10 SN SONRA KONDANSER KAPANIR.                                                   **//
//**                                    09) KLIMA ARIZASI OLUSTGUNDA =>                                                                          **//
//**                                        a) AC TUSU BASILIYKEN =>                                                                             **//
//**                                           I)   KOMPRESSOR VE KONDANSER CALISIYORSA AYNI ANDA 2 SN SONRA                                     **//
//**                                                KAPANIR.                                                                                     **//
//**                                           II)  EKRANDA IC SICAKLIK ILE BIRLIKTE E5 YAZAR.                                                   **//
//**                                           III) ARIZA GIDERILDIGINDE KOMPRESSOR VE KONDANSER CALISIYORSA                                     **//
//**                                                ONCE 2 SN SONRA KONDANSER SONRA 10 SN SONRA KOMPRESSOR                                       **//
//**                                                DEVREYE GIRER.                                                                               **//
//**                                        b) AC TUSU BASILI DEGILKEN =>                                                                        **//
//**                                           I)  EKRANDA IC SICAKLIK ILE BIRLIKTE E5 YAZAR.                                                    **//
//**                                           II) ARIZA GIDERILDIGINDE EKRANDA SADECE IC SICAKLIK YAZAR.                                        **//
//**                                    10) SENSOR ARIZASI OLUSTUGUNDA =>                                                                        **//
//**                                        a) AC BASILIYKEN =>                                                                                  **//
//**                                           I)   KOMPRESSOR VE KONDANSER CALISIYORSA AYNI ANDA 2 SN SONRA                                     **//
//**                                                KAPANIR.                                                                                     **//
//**                                           II)  EKRANDA SADECE E1 YAZAR, IC SICAKLIK DEGERI YAZMAZ.                                          **//
//**                                           III) ARIZA GIDERILDIGINDE KOMPRESSOR VE KONDANSER CALISIYORSA                                     **//
//**                                                ONCE 2 SN SONRA KONDANSER SONRA 10 SN SONRA KOMPRESSOR                                       **//
//**                                                DEVREYE GIRER.                                                                               **//
//**                                        b) AC TUSU BASILI DEGILKEN =>                                                                        **//
//**                                           I)  EKRANDA SADECE E1 YAZAR, IC SICAKLIK DEGERI YAZMAZ.                                           **//
//**                                           II) ARIZA GIDERILDIGINDE EKRANDA SADECE IC SICAKLIK YAZAR.                                        **//
//**                                                                                                                                             **//
//**                                    11) PARK/AYDINLATMAYA BASILDIGINDA PANEL TUSLARI AYDINLATILIRÇ.                                          **//
//**                                    12) KLAPE MOTOR ARIZALARI =>                                                                             **//
//**                                        a) KLAPE MOTOR ARIZALARINA BASLANGICTA TARAMA ESNASINDA BAKAR.                                       **//
//**                                        b) EGER KLAPE MOTORLARINDAN HERHANGI BIRINDE ARIZA OLUSURSA                                          **//
//**                                           O KLAPE MOTORUNUN BUTONLARI CALISMA ESNASINDA CALISIR                                             **//
//**                                           VE BASILDIGI DURUMA GORE LEDLERI YANAR AMA MOTORLAR HAREKET                                       **//
//**                                           ETMEZ.                                                                                            **//
//**                                        c) SADECE EKRANDA KLAPE MOTROLARININ ARIZALI OLDUGUNU GOSTEREN                                       **//
//**                                           IFADELER DIGER IFADELER ILE BIRLIKTE SIRAYLA YAZAR.                                               **//
//**                                        d) ARIZA KODLARI =>                                                                                  **//
//**                                           I)   E1 => IC SICAKLIK SENSOR ARIZASI                                                             **//
//**                                           II)  E2 => CAM KLAPE MOTOR ARIZASI                                                                **//
//**                                           III) E3 => VANA KLAPE MOTOR ARIZASI                                                               **//
//**                                           IV)  E4 => TEMIZ HAVA KLAPE MOTOR ARIZASI                                                         **//
//**                                           V)   E5 => KLIMA ARIZASI                                                                          **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//**                                                                                                                                             **//
//*************************************************************************************************************************************************//
//********************************************************************END**THE**CODE***************************************************************//
//*************************************************************************************************************************************************//
