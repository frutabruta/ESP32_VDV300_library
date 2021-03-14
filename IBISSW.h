#ifndef IBISSW_h
#define IBISW_h
#include "Arduino.h"
//#include <SoftwareSerial.h>
//#include <espsoftwareserial\src\SoftwareSerial.h>

class IBISSW
{
  public:
  //SoftwareSerial swSer(11,12);
  //SoftwareSerial swSer;
  IBISSW();
  String dopocetCelni(String puvodniPrikaz);
  void smazPanely();	
  
};

#endif