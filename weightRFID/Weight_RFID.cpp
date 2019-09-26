#include "HX711.h"          //调用24bitAD HX711库
#include <SPI.h>
#include <MFRC522.h>         //调用MFRC522库

HX711 HX711_CH0(2, 3, 400); //SCK,DT,GapValue
//SCK引脚用于arduino和HX711模块通讯的时序提供
//DT引脚用于从HX711读取AD的数据
//GapValue用于校准输出的重量值，如果数值偏大就加大该值，如果数据偏小就减小该值
int LED = 13;
long Weight = 0;    //定义一个变量用于存放承重的重量，单位为g


#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above
#define SCK             7
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

//set SPI
void configSPI(){
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));
  digitalWrite(SCK, LOW);
//  SPI.transfer(val);
  digitalWrite(SCK, HIGH);
  }


void setup()
{
  pinMode(LED, OUTPUT);       //设定LED是输出引脚
  digitalWrite(LED, LOW);     //LED熄灭

  Serial.begin(9600);           //设定串口输出波特率
//  Serial.print("Welcome to use!\n");

  HX711_CH0.begin();          //读取传感器支架毛重
  Serial.print("HX711_CH0.begin1 \n");
  delay(3000);                //延时3s用于传感器稳定
  HX711_CH0.begin();          //重新读取传感器支架毛重用于后续计算
  Serial.print("HX711_CH0.begin2 \n");
  digitalWrite(LED, HIGH);    //板载LED点亮，说明可以承重

  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
//  pinMode(SCK, OUTPUT);
//  digitalWrite(n, LOW);
//  data_R = SPI.transfer(data_S);
//  digitalWrite(SCK, HIGH);
  mfrc522.PCD_Init();   // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop()
{
    Weight = HX711_CH0.Get_Weight();    //采样当前传感器重量，该重量已经自动去皮，去皮值根据初始化程序中采样的值计算。
    Serial.print("weight:");
    Serial.println(Weight);     //串口输出当前重量
//    Serial.println(" g");     //单位为g
    delay(1000);  
 
 
 
 // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
 
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
    unsigned char idx ;
    Serial.print("Card UID :");
  for(idx = 0;idx < mfrc522.uid.size;idx++){
//    Serial.print(mfrc522.uid.uidByte[idx] < 0x10? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[idx], HEX);
}
    Serial.println();
}
#include "HX711.h"          //调用24bitAD HX711库
#include <SPI.h>
#include <MFRC522.h>         //调用MFRC522库

HX711 HX711_CH0(2, 3, 400); //SCK,DT,GapValue
//SCK引脚用于arduino和HX711模块通讯的时序提供
//DT引脚用于从HX711读取AD的数据
//GapValue用于校准输出的重量值，如果数值偏大就加大该值，如果数据偏小就减小该值
int LED = 13;
long Weight = 0;    //定义一个变量用于存放承重的重量，单位为g


#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above
#define SCK             7
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

//set SPI
void configSPI(){
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));
  digitalWrite(SCK, LOW);
//  SPI.transfer(val);
  digitalWrite(SCK, HIGH);
  }


void setup()
{
  pinMode(LED, OUTPUT);       //设定LED是输出引脚
  digitalWrite(LED, LOW);     //LED熄灭

  Serial.begin(9600);           //设定串口输出波特率
//  Serial.print("Welcome to use!\n");

  HX711_CH0.begin();          //读取传感器支架毛重
  Serial.print("HX711_CH0.begin1 \n");
  delay(3000);                //延时3s用于传感器稳定
  HX711_CH0.begin();          //重新读取传感器支架毛重用于后续计算
  Serial.print("HX711_CH0.begin2 \n");
  digitalWrite(LED, HIGH);    //板载LED点亮，说明可以承重

  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
//  pinMode(SCK, OUTPUT);
//  digitalWrite(n, LOW);
//  data_R = SPI.transfer(data_S);
//  digitalWrite(SCK, HIGH);
  mfrc522.PCD_Init();   // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop()
{
    Weight = HX711_CH0.Get_Weight();    //采样当前传感器重量，该重量已经自动去皮，去皮值根据初始化程序中采样的值计算。
    Serial.print("weight:");
    Serial.println(Weight);     //串口输出当前重量
//    Serial.println(" g");     //单位为g
    delay(1000);  
 
 
 
 // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
 
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
    unsigned char idx ;
    Serial.print("Card UID :");
  for(idx = 0;idx < mfrc522.uid.size;idx++){
//    Serial.print(mfrc522.uid.uidByte[idx] < 0x10? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[idx], HEX);
}
    Serial.println();
}

