# DHCP_TEST
## Simple Ethernet/DHCP test using arduino, Ethernet breakout board and DDS1306 Oled display

This device try to connect to DHCP server and get an IP adress. The oled display will show IP, netmask, DNS server, gateway and Mac address. Mac can be changed in the .ino file.

![This is an image](https://github.com/fg1998/DHCP_TEST/blob/main/assets/screen_capture.png)

### Part List
- Arduino nano (another arduino can be used, like UNO, mini, etc)
- SSD1306 SPI oled display (7 pins)
- ENC28j60 ethernet breakout board 
- Push button for reset (optional, nano reset can be used)
 
### Library used
- Ethercard - https://github.com/njh/EtherCard
- SSD1306Ascii - https://github.com/greiman/SSD1306Ascii

Thanks to Bill Greiman for SSD1306Ascii library. Normal SSD1306 library provided by adafruit cannot be used with Ethercard since arduino memory restrictions

## Conections

|Arduino NANO | ethernet board. | SPI Display |
|-------------|-----------------|-------------|
|D12          |   SO            |             |
|D11          |   SI            |             |
|D10          |   CS            |             |
|D13          |   SCK           |             |
|5V           |   VCC           |             |
|GND          |   GND           |             |
|D9           |                 |    SDA      |
|D7           |                 |    SCK      |
|D6           |                 |    RST      |
|D5           |                 |    DC       |
|D4           |                 |    CS       |
|5V           |                 |    VDD      |
|GND          |                 |    GND      |


Put a pushbutton between arduino RST and GND if you want a external Reset


![This is an image](https://github.com/fg1998/DHCP_TEST/blob/main/assets/breadboard.png)
