
#include <EtherCard.h>
//https://github.com/greiman/SSD1306Ascii
#include <SPI.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiSoftSpi.h"

// ethernet interface mac address, must be unique on the LAN
static byte mymac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };

byte Ethernet::buffer[700];

#define CSEthernetPin 10

 
// Declaration for SSD1306 oled connected using software SPI (default case):
#define OLED_MOSI   9
#define OLED_CLK   7
#define OLED_DC    5
#define OLED_CS    4
#define OLED_RESET 6
SSD1306AsciiSoftSpi oled;

 
void OLEDprintIp (const uint8_t *buf) {
    for(uint8_t i = 0; i < 4; i++){
      char rr[4];
      int num = buf[i];
      itoa(num, rr, 10);
      oled.write(rr);  
      if(i < 3) oled.write(".");
    }
}
 
void OLEDprintMac (const uint8_t *buf) {
    for(uint8_t i = 0; i < 6; i++){
      char rr[4];
      int num = buf[i];
      itoa(num, rr, 16);
      oled.write(rr);  
      //if(i <5) oled.write(".");
    }
}


void setup()
{
   Serial.begin(9600);
   

  oled.begin(&Adafruit128x64, OLED_CS, OLED_DC, OLED_CLK, OLED_MOSI, OLED_RESET);
  oled.setFont(System5x7);
  oled.clear();

  oled.write("Trying DHCP server...");
  oled.setCursor(0, 1);

  if (ether.begin(sizeof Ethernet::buffer, mymac, CSEthernetPin) == 0)
  {
    oled.write("ETHERNET FAILED");
    for (;;);
  }
  else {
      

      if (!ether.dhcpSetup())
      {
          oled.write("DHCP FAILED");

      }
      else
      {
        oled.write("DHCP OK");
        oled.setCursor(0,2);
        oled.write("IP: ");
        OLEDprintIp(ether.myip); 

        oled.setCursor(0,3);        
        oled.write("Mask: ");
        OLEDprintIp(ether.netmask);

        oled.setCursor(0,4);
        oled.write("DNS: ");
        OLEDprintIp(ether.dnsip);

        oled.setCursor(0,5);
        oled.write("GW: ");
        OLEDprintIp(ether.gwip);

        oled.setCursor(0,6);
        oled.write("MAC: ");
        OLEDprintMac(mymac);
      }

  }


  
}

void loop() { }
    
