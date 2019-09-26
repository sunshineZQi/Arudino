#include "HX711.h"          //����24bitAD HX711��
#include <SPI.h>
#include <MFRC522.h>         //����MFRC522��

HX711 HX711_CH0(2, 3, 400); //SCK,DT,GapValue
//SCK��������arduino��HX711ģ��ͨѶ��ʱ���ṩ
//DT�������ڴ�HX711��ȡAD������
//GapValue����У׼���������ֵ�������ֵƫ��ͼӴ��ֵ���������ƫС�ͼ�С��ֵ
int LED = 13;
long Weight = 0;    //����һ���������ڴ�ų��ص���������λΪg


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
  pinMode(LED, OUTPUT);       //�趨LED���������
  digitalWrite(LED, LOW);     //LEDϨ��

  Serial.begin(9600);           //�趨�������������
//  Serial.print("Welcome to use!\n");

  HX711_CH0.begin();          //��ȡ������֧��ë��
  Serial.print("HX711_CH0.begin1 \n");
  delay(3000);                //��ʱ3s���ڴ������ȶ�
  HX711_CH0.begin();          //���¶�ȡ������֧��ë�����ں�������
  Serial.print("HX711_CH0.begin2 \n");
  digitalWrite(LED, HIGH);    //����LED������˵�����Գ���

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
    Weight = HX711_CH0.Get_Weight();    //������ǰ�������������������Ѿ��Զ�ȥƤ��ȥƤֵ���ݳ�ʼ�������в�����ֵ���㡣
    Serial.print("weight:");
    Serial.println(Weight);     //���������ǰ����
//    Serial.println(" g");     //��λΪg
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
#include "HX711.h"          //����24bitAD HX711��
#include <SPI.h>
#include <MFRC522.h>         //����MFRC522��

HX711 HX711_CH0(2, 3, 400); //SCK,DT,GapValue
//SCK��������arduino��HX711ģ��ͨѶ��ʱ���ṩ
//DT�������ڴ�HX711��ȡAD������
//GapValue����У׼���������ֵ�������ֵƫ��ͼӴ��ֵ���������ƫС�ͼ�С��ֵ
int LED = 13;
long Weight = 0;    //����һ���������ڴ�ų��ص���������λΪg


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
  pinMode(LED, OUTPUT);       //�趨LED���������
  digitalWrite(LED, LOW);     //LEDϨ��

  Serial.begin(9600);           //�趨�������������
//  Serial.print("Welcome to use!\n");

  HX711_CH0.begin();          //��ȡ������֧��ë��
  Serial.print("HX711_CH0.begin1 \n");
  delay(3000);                //��ʱ3s���ڴ������ȶ�
  HX711_CH0.begin();          //���¶�ȡ������֧��ë�����ں�������
  Serial.print("HX711_CH0.begin2 \n");
  digitalWrite(LED, HIGH);    //����LED������˵�����Գ���

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
    Weight = HX711_CH0.Get_Weight();    //������ǰ�������������������Ѿ��Զ�ȥƤ��ȥƤֵ���ݳ�ʼ�������в�����ֵ���㡣
    Serial.print("weight:");
    Serial.println(Weight);     //���������ǰ����
//    Serial.println(" g");     //��λΪg
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

