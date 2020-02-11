//-------------------------
//抖音：爆改车间车间主任
//自制键盘外设OLED升级版
//共享代码 请勿商用
//-------------------------
#include <Wire.h>          
#include <Adafruit_GFX.h>   
#include <Adafruit_SSD1306.h>     //lcd显示使用的库

#include "HID-Project.h"    //该HID库文件下载地址 https://github.com/NicoHood/HID
#define  CLK 2
#define  DT 3
#define  BUTTON 4

#define OLED_DC 8      //这部分是olcd连接管脚可以自己定义
#define OLED_CS 9
#define OLED_CLK 5
#define OLED_MOSI 6
#define OLED_RESET 7
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#define key1 10

char key_num =0;

bool aState;
bool aLastState;
bool lastButtonState = 0;
long lastClickTime = 0;

void menu();

void setup() {
  Serial.begin(9600);
  pinMode(key1, INPUT_PULLUP);

  Consumer.begin();
  pinMode(DT, INPUT);
  pinMode(CLK, INPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  aLastState = digitalRead(DT);
  
  display.begin(SSD1306_SWITCHCAPVCC);
  // init done
  
  display.display(); // show splashscreen
  delay(100);
  display.clearDisplay();   // clears the screen and buffer

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("music");
  display.println("Pr(mac)");
  display.println("Pr(win)");
  display.println("Lightroom");
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.setCursor(0,0);
  display.println("          ");
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.setCursor(0,0);
  display.println("music");
  display.display();
  delay(200);
}

void loop() {

  if (digitalRead(key1) == LOW) {
    key_num++;
    if(key_num==4)key_num=0;
    while(!digitalRead(key1));
    menu();
   }
   

     aState = digitalRead(DT);
        
    if (aState != aLastState) {
        
              if (digitalRead(CLK) != aState) {
                switch (key_num) {
                   case 0: Consumer.write(MEDIA_VOLUME_DOWN); break;
                   case 1: Keyboard.write(KEY_LEFT_ARROW); break;
                   case 2: Keyboard.write(KEY_LEFT_ARROW);  break;
                   case 3: Keyboard.write(KEY_DOWN_ARROW);  break;
                }

                delay(8);
              } else {
                switch (key_num) {
                   case 0: Consumer.write(MEDIA_VOLUME_UP); break;
                   case 1: Keyboard.write(KEY_RIGHT_ARROW); break;
                   case 2: Keyboard.write(KEY_RIGHT_ARROW);  break;
                   case 3: Keyboard.write(KEY_UP_ARROW);  break;
                }
                delay(8);
              }
        
              Keyboard.releaseAll();
              aLastState = aState;
       }
        
        
       if (digitalRead(BUTTON) == LOW) {
        
              if (lastButtonState == HIGH) {

                switch (key_num) {
                   case 0: Consumer.write(MEDIA_PLAY_PAUSE); break;
                   case 1: {Keyboard.press(KEY_LEFT_GUI);
                            Keyboard.press('k');
                            delay(100);
                            Keyboard.releaseAll();}; break;
                   case 2: {Keyboard.press(KEY_LEFT_CTRL);
                            Keyboard.press('k');
                            delay(100);
                            Keyboard.releaseAll();}; break;
                   case 3: Keyboard.write(KEY_TAB);  break;
                }
                
        
                 lastClickTime = millis();
              }
               delay(200);
              if(digitalRead(BUTTON)==LOW){
                Consumer.write(MEDIA_NEXT);
                while(!digitalRead(BUTTON));
              }
        
              lastButtonState = LOW;
            } else {
        
              lastButtonState = HIGH;
       }

  
}

void menu(){

  if(key_num==0){
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("music");
      display.println("Pr(mac)");
      display.println("Pr(win)");
      display.println("Lightroom");
      display.setTextColor(BLACK, WHITE); // 'inverted' text
      display.setCursor(0,0);
      display.println("          ");
      display.setTextColor(BLACK, WHITE); // 'inverted' text
      display.setCursor(0,0);
      display.println("music");
      display.display();
    
  }else if(key_num==1){
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("music");
      display.println("Pr(mac)");
      display.println("Pr(win)");
      display.println("Lightroom");
      display.setTextColor(BLACK, WHITE); // 'inverted' text
      display.setCursor(0,16);
      display.println("          ");
      display.setTextColor(BLACK, WHITE); // 'inverted' text
      display.setCursor(0,16);
      display.println("Pr(mac)");
      display.display();
    
  }else if(key_num==2){
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("music");
      display.println("Pr(mac)");
      display.println("Pr(win)");
      display.println("Lightroom");
      display.setTextColor(BLACK, WHITE); // 'inverted' text
      display.setCursor(0,32);
      display.println("          ");
      display.setTextColor(BLACK, WHITE); // 'inverted' text
      display.setCursor(0,32);
      display.println("Pr(win)");
      display.display();
    
  }else if(key_num==3){
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println("music");
      display.println("Pr(mac)");
      display.println("Pr(win)");
      display.println("Lightroom");
      display.setTextColor(BLACK, WHITE); // 'inverted' text
      display.setCursor(0,48);
      display.println("          ");
      display.setTextColor(BLACK, WHITE); // 'inverted' text
      display.setCursor(0,48);
      display.println("Lightroom");
      display.display();
    
  }
  
}
