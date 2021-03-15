#include "Arduino.h"
#include "IBISSW.h"






IBISSW::IBISSW()
{
Serial2.begin(1200, SERIAL_7E2, 4, 12);
//swSer.begin(1200, SWSERIAL_7E1,4,12,false);  //RX,TX
//swSer.begin(1200, SERIAL_7E2);
//pinMode(12,OUTPUT);
//swSer.flush();
//swSer.enableTx(true);
}


String IBISSW::dopocetCelni(String puvodniPrikaz)
{
        String prikaz = "";
    //byte velikostMezipameti=200;
    //char mezipamet[velikostMezipameti];
   //String mezipamet="";
    char zacatecniByte=0x7F;
    String ridiciZnak ="";
   
    byte jeZnak=5;
    
    char hexridiciznak[3];
    byte hex1=0;
    byte hex2=0;
    //String retezec="";
    
   /* BRNO buse
        puvodniPrikaz.replace("Á","<0E><0F>");
        puvodniPrikaz.replace("č","<0E><07>");
        puvodniPrikaz.replace("Č","<0E><00>");
        puvodniPrikaz.replace("ď","<0E><03>");
        puvodniPrikaz.replace("Ď","<0E><05>");
        puvodniPrikaz.replace("é","<0E><02>");
        puvodniPrikaz.replace("É","<0E><10>");
        puvodniPrikaz.replace("ě","<0E><08>");
        puvodniPrikaz.replace("Ě","<0E><09>");
        puvodniPrikaz.replace("í","<0E><21>");
        puvodniPrikaz.replace("Í","<0E><0B>");
        puvodniPrikaz.replace("ň","<0E><24>");
        puvodniPrikaz.replace("Ň","<0E><25>");
        puvodniPrikaz.replace("ó","<0E><22>");
        puvodniPrikaz.replace("Ó","<0E><15>");
        puvodniPrikaz.replace("ř","<0E><29>");
        puvodniPrikaz.replace("Ř","<0E><1E>");
        puvodniPrikaz.replace("š","<0E><28>");
        puvodniPrikaz.replace("Š","<0E><1B>");
        puvodniPrikaz.replace("ť","<0E><1F>");
        puvodniPrikaz.replace("Ť","<0E><06>");
        puvodniPrikaz.replace("ú","<0E><23>");
        puvodniPrikaz.replace("ů","<0E><16>");
        puvodniPrikaz.replace("Ů","<0E><26>");
        puvodniPrikaz.replace("ý","<0E><18>");
        puvodniPrikaz.replace("Ý","<0E><1D>");
        puvodniPrikaz.replace("ž","<0E><11>");
        puvodniPrikaz.replace("Ž","<0E><12>");
        */

        puvodniPrikaz.replace("á","<0E><41>");
        puvodniPrikaz.replace("Á","<0E><61>");
        puvodniPrikaz.replace("ä","<0E><58>");
        puvodniPrikaz.replace("Ä","<0E><71>");
        puvodniPrikaz.replace("à","<0E><51>");
        puvodniPrikaz.replace("À","<0E><78>");
        puvodniPrikaz.replace("č","<0E><43>");
        puvodniPrikaz.replace("Č","<0E><63>");
        puvodniPrikaz.replace("ď","<0E><44>");
        puvodniPrikaz.replace("Ď","<0E><64>");
        puvodniPrikaz.replace("é","<0E><57>");
        puvodniPrikaz.replace("É","<0E><77>");
        puvodniPrikaz.replace("ě","<0E><45>");
        puvodniPrikaz.replace("Ě","<0E><09>");
        puvodniPrikaz.replace("í","<0E><49>");
        puvodniPrikaz.replace("Í","<0E><69>");    
        puvodniPrikaz.replace("ĺ","<0E><4B>");
        puvodniPrikaz.replace("Ĺ","<0E><6B>");
        puvodniPrikaz.replace("ľ","<0E><4C>");
        puvodniPrikaz.replace("Ľ","<0E><6C>");
        puvodniPrikaz.replace("ň","<0E><4E>");
        puvodniPrikaz.replace("Ň","<0E><6E>");
        puvodniPrikaz.replace("ó","<0E><4F>");
        puvodniPrikaz.replace("Ó","<0E><6F>");
        puvodniPrikaz.replace("ö","<0E><4D>");
        puvodniPrikaz.replace("Ö","<0E><6D>");
        puvodniPrikaz.replace("ô","<0E><50>");
        puvodniPrikaz.replace("Ô","<0E><70>");
        puvodniPrikaz.replace("ŕ","<0E><46>");
        puvodniPrikaz.replace("Ŕ","<0E><66>");
        puvodniPrikaz.replace("ř","<0E><52>");
        puvodniPrikaz.replace("Ř","<0E><72>");
        puvodniPrikaz.replace("š","<0E><53>");
        puvodniPrikaz.replace("Š","<0E><73>");
        puvodniPrikaz.replace("ť","<0E><54>");
        puvodniPrikaz.replace("Ť","<0E><74>");
        puvodniPrikaz.replace("ü","<0E><48>");
        puvodniPrikaz.replace("Ü","<0E><68>");
        puvodniPrikaz.replace("ú","<0E><55>");
        puvodniPrikaz.replace("ú","<0E><55>");
        puvodniPrikaz.replace("Ú","<0E><75>");
        puvodniPrikaz.replace("ů","<0E><4A>");
        puvodniPrikaz.replace("Ů","<0E><6A>");
        puvodniPrikaz.replace("ý","<0E><59>");
        puvodniPrikaz.replace("Ý","<0E><79>");
        puvodniPrikaz.replace("ž","<0E><5A>");
        puvodniPrikaz.replace("Ž","<0E><7A>");
        
        
        
        prikaz=puvodniPrikaz+'\r';
       //mezipamet=prikaz;
        //prikaz.toCharArray(mezipamet, velikostMezipameti);
        /*
        zacatecnibyte=zacatecnibyte^0x7A;
        Serial3.write(0x7A);
         zacatecnibyte=zacatecnibyte^0x41;
        Serial3.write(0x41);
         zacatecnibyte=zacatecnibyte^0x20;
        Serial3.write(0x20);
        zacatecnibyte=zacatecnibyte^0x1B;
        Serial3.write(0x1B);
        zacatecnibyte=zacatecnibyte^0x57;
        Serial3.write(0x57);
        */
        
        
        
        for (int k=0; k<prikaz.length(); k++)
        {
          if (prikaz[k]=='<')
          {
            jeZnak=0;
          }
          if (prikaz[k]=='>')
          {
            jeZnak=4;
          }
          switch (jeZnak)
            {
              case 0:
              jeZnak++;
              break;
              
              case 1:
              hexridiciznak[0]=prikaz[k];
              jeZnak++;
              break;
              
              case 2:
              hexridiciznak[1]=prikaz[k];
              jeZnak++;
              //zacatecniByte=zacatecniByte^atoi(hexridiciznak);
              break;
              
              case 3:
              hexridiciznak[2]=prikaz[k];
              jeZnak++;
              
              break;
              
              
              case 4:
              
              zacatecniByte=zacatecniByte^int(strtol(hexridiciznak,NULL,16));
              //Serial.write(int(strtol(hexridiciznak,NULL,16)));
              Serial2.write(int(strtol(hexridiciznak,NULL,16)));
              //Serial3.write(int(strtol(hexridiciznak,NULL,16)));
              hexridiciznak[0]=0;
              hexridiciznak[1]=0;
              hexridiciznak[2]=0;
              jeZnak++;
              break;
              
              case 5:
              zacatecniByte=zacatecniByte^prikaz[k];
              //Serial.print(prikaz[k]);
              Serial2.print(prikaz[k]);
              //Serial3.print(prikaz[k]);
              break;
              
            
          }
          
          //Serial.print("   ");
        }
        //Serial3.print(prikaz);
        //Serial.print(zacatecniByte);
        Serial2.print(zacatecniByte);
        //Serial3.print(zacatecniByte);
        
return prikaz;  
 }
       
       
void IBISSW::smazPanely ()
{
    String prikaz="";
  prikaz="zA ";
  dopocetCelni(prikaz);
  
  prikaz="zN ";
  dopocetCelni(prikaz);
  
  prikaz="zI2 ";
  dopocetCelni(prikaz);
  
  prikaz="l000";
  dopocetCelni(prikaz);
}       
