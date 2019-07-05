//Humidity
#include <dht.h>
#define dht_apin 12
dht DHT;
// TEMPERATURE SENSOR
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 11
OneWire oneWire (ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float tempC = 0;
float tempF = 0;

int lowerlimit = 60;
int higherlimit = 72;

// LCD DISPLAY
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

//GSM MODULE
#include <SoftwareSerial.h>
SoftwareSerial SIM900(7,8);

//KEYPAD
#include <Keypad.h>
int val=0;
int value1 = 0;
float value = 0;
int result=0;
int integer=0;
float origfloat;
float origint=0;
char keypressed;
long number,number1, num1, num2;
int secondsT4 = 0;
int save4=0;
int hoursT5= 0;
int save5=0;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};
byte rowPins[ROWS] = {43, 42, 41, 40}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {47, 46, 45, 44}; //connect to the column pinouts of the keypad

Keypad keypad_key = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// TIMER1 
int secondsT1=59;
int minutesT1=30;
int hoursT1=6;
int initial1=0;
int save1=0;
int battery1=0;
// TIMER2
int secondsT2=59;
int minutesT2=59;
int hoursT2=8;
int initial2=0;
int save2=0;
int battery2=0;
// TIMER3
int secondsT3=59;
int minutesT3=59;
int hoursT3=4;
int initial3=0;
int save3=0;
int battery3=0;
// TIMER4 
int battery4=0;
int battery5=0;
int initial4=0;
int initial5=0;

int clockk=150; // 

// ARDUINO DIGITAL PINS
const int buttonPin1=48;
const int buttonPin2=49;
const int buttonPin3=50;
const int buttonSET=51;
const int buttonCANCEL=52;
const int fan=36;
const int heater1=38;
const int heater2=39;
const int battery=53;
//BUTTONS    
int buttonState;             
int lastButtonState = LOW;



void setup() {
  // put your setup code here, to run once:
 
  pinMode(battery, OUTPUT); 
  digitalWrite(battery,HIGH);
  
  pinMode(9,OUTPUT);
  SIM900.begin(19200);
  SIM900power();
  delay(2000);
  
  lcd.init();   
  lcd.backlight();    
  sensors.begin();


  pinMode(buttonPin1, INPUT);  
  pinMode(fan, LOW); 
  pinMode(heater1, LOW); 
  pinMode(heater2, LOW); 
  
  
  lcd.begin(20,4);
  
  lcd.setCursor(0,0);
  lcd.print("DEVELOPMENT OF FISH");
  lcd.setCursor( 3,1);
  lcd.print("DEHUMIDIFYING");
  lcd.setCursor(1,2);
  lcd.print("MECHANISM WITH SMS ");
  lcd.setCursor(0,3);
  lcd.print("NOTIFICATION SYSTEM");
  delay(2000);

  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("PLEASE CLICK ON");
  lcd.setCursor(1,1);
  lcd.print("THE DESIRED BUTTON");
  lcd.setCursor(0,2);
  lcd.print("[1] BULINAW");
  lcd.setCursor(11,2);
  lcd.print("[3] LUPOY");
  lcd.setCursor(0,3);
  lcd.print("[2] BUDLOY");
  lcd.setCursor(11,3);
  lcd.print("[4] SET");
 
}



void loop() {
  
  int reading1 = digitalRead(buttonPin1);
  int reading2 = digitalRead(buttonPin2);
  int reading3 = digitalRead(buttonPin3);
  int reading4 = digitalRead(buttonSET);

  //BUTTON[1]  
   
  if (reading1 != lastButtonState ) {

  pinMode(fan, OUTPUT); 
  pinMode(heater1, OUTPUT); 
  pinMode(heater2, OUTPUT);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TYPE OF FISH:BULINAW");
  lcd.setCursor(0,1);
  lcd.print("DRYING TIME: 6.5HRS");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TYPE OF FISH:BULINAW");
  lcd.setCursor(0,1);
  lcd.print("DRYING TIME: 6.5HRS");
    lcd.setCursor(0,2);
    lcd.print("DRYING STARTS IN");
    delay(1000);
    lcd.setCursor(8, 3);
    lcd.print("3");
    delay(1000);
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TYPE OF FISH:BULINAW");
  lcd.setCursor(0,1);
  lcd.print("DRYING TIME: 6.5HRS");
    lcd.setCursor(0,2);
    lcd.print("DRYING STARTS IN");
    lcd.setCursor(8, 3);
    lcd.print("2");
    delay(1000);
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TYPE OF FISH:BULINAW");
  lcd.setCursor(0,1);
  lcd.print("DRYING TIME: 6.5HRS");
    lcd.setCursor(0,2);
    lcd.print("DRYING STARTS IN");
    lcd.setCursor(8, 3);
    lcd.print("1");
    delay(1000);
  
    lcd.clear();
  
    timer1();
    
  if(initial1==100){
    setup();
    SIM900power();
    
  }
  if(initial1==23400){
    digitalWrite(fan, HIGH);
    digitalWrite(heater1, HIGH);
    digitalWrite(heater2, HIGH);

    secondsT1=59; // TO RETURN ORIGINAL VALUE
    minutesT1=30; // TO RETURN ORIGINAL VALUE
    hoursT1=6; // TO RETURN ORIGINAL VALUE
     
   sendSMS();
    
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("FISH IS");
    lcd.setCursor(2,1);
    lcd.print("COMPLETELY DRIED");
    lcd.setCursor(2,3);
    lcd.print("SMS HAS BEEN SENT");
  }

  }
  //BUTTON[2]
 if (reading2 != lastButtonState ) {

  pinMode(fan,OUTPUT); 
  pinMode(heater1,OUTPUT); 
  pinMode(heater2,OUTPUT);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TYPE OF FISH: BUDLOY");
  lcd.setCursor(0,1);
  lcd.print("DRYING TIME: 9HRS ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TYPE OF FISH: BUDLOY");
  lcd.setCursor(0,1);
  lcd.print("DRYING TIME: 9HRS ");
    lcd.setCursor(0,2);
    lcd.print("DRYING STARTS IN");
    delay(1000);
    lcd.setCursor(8, 3);
    lcd.print("3");
    delay(1000);
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TYPE OF FISH: BUDLOY");
  lcd.setCursor(0,1);
  lcd.print("DRYING TIME: 9HRS");
    lcd.setCursor(0,2);
    lcd.print("DRYING STARTS IN");
    lcd.setCursor(8, 3);
    lcd.print("2");
    delay(1000);
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TYPE OF FISH: BUDLOY");
  lcd.setCursor(0,1);
  lcd.print("DRYING TIME: 9HRS");
    lcd.setCursor(0,2);
    lcd.print("DRYING STARTS IN");
    lcd.setCursor(8, 3);
    lcd.print("1");
    delay(1000);
  
    lcd.clear();
  
    timer2();
    
  if(initial2==100){
    setup();
    SIM900power();
  }
  if(initial2==32400){
    digitalWrite(fan, HIGH);
    digitalWrite(heater1, HIGH);
    digitalWrite(heater2, HIGH);
    
    secondsT2=59; // TO RETURN ORIGINAL VALUE
    minutesT2=59; // TO RETURN ORIGINAL VALUE
    hoursT2=4; // TO RETURN ORIGINAL VALUE
   
    sendSMS();
    
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("FISH IS");
    lcd.setCursor(2,1);
    lcd.print("COMPLETELY DRIED");
    lcd.setCursor(2,3);
    lcd.print("SMS HAS BEEN SENT");
  }
  }
//BUTTON[3]
 if (reading3 != lastButtonState ) {

  pinMode(fan,OUTPUT); 
  pinMode(heater1,OUTPUT); 
  pinMode(heater2,OUTPUT);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TYPE OF FISH: LUPOY");
  lcd.setCursor(0,1);
  lcd.print("DRYING TIME: 5HRS ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TYPE OF FISH: LUPOY");
  lcd.setCursor(0,1);
  lcd.print("DRYING TIME: 5HRS ");
    lcd.setCursor(0,2);
    lcd.print("DRYING STARTS IN");
    delay(1000);
    lcd.setCursor(8, 3);
    lcd.print("3");
    delay(1000);
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TYPE OF FISH: LUPOY");
  lcd.setCursor(0,1);
  lcd.print("DRYING TIME: 5HRS");
    lcd.setCursor(0,2);
    lcd.print("DRYING STARTS IN");
    lcd.setCursor(8, 3);
    lcd.print("2");
    delay(1000);
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TYPE OF FISH: LUPOY");
  lcd.setCursor(0,1);
  lcd.print("DRYING TIME: 5HRS");
    lcd.setCursor(0,2);
    lcd.print("DRYING STARTS IN");
    lcd.setCursor(8, 3);
    lcd.print("1");
    delay(1000);
  
    lcd.clear();
  
    timer3();
    
  if(initial3==100){
    setup();
    SIM900power();
  }
  if(initial3==18000){
    digitalWrite(fan, HIGH);
    digitalWrite(heater1, HIGH);
    digitalWrite(heater2, HIGH);
    
    secondsT3=59; // TO RETURN ORIGINAL VALUE
    minutesT3=0; // TO RETURN ORIGINAL VALUE

    sendSMS();
    
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("FISH IS");
    lcd.setCursor(2,1);
    lcd.print("COMPLETELY DRIED");
    lcd.setCursor(2,3);
    lcd.print("SMS HAS BEEN SENT");
  }

  }
//BUTTONSET
int jump=0;
   if (reading4 != lastButtonState ) {
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SET TIME:");
   }
  keypressed = keypad_key.getKey();
  if (keypressed) { 
    detectedbuttons();
    lcd.setCursor(10, 0);
    lcd.print(number);
    value = number;
  }
   if (keypressed != NO_KEY && keypressed == '*') {
      pinMode(fan,OUTPUT); 
      pinMode(heater1,OUTPUT); 
      pinMode(heater2,OUTPUT);
    
      lcd.clear();
       if(value<3600){
      lcd.setCursor(0, 1);
      lcd.print("Processing...");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Remaining Time:");
      timerA();
      
   if(initial4==100){
    number=0;
    setup();
    SIM900power();
  }
   if (initial4==value){
    number=0;   
    digitalWrite(fan, HIGH);
    digitalWrite(heater1, HIGH);
    digitalWrite(heater2, HIGH);
    
    sendSMS();
    
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("FISH IS");
    lcd.setCursor(2,1);
    lcd.print("COMPLETELY DRIED");
    lcd.setCursor(2,3);
    lcd.print("SMS HAS BEEN SENT");   
      delay(500);    
  }

       }
       else if(value >= 3600){
      lcd.setCursor(0, 1);
      lcd.print("Processing...");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Remaining Time:");
      
      timerB();

  if (initial5==value){
    number=0;   
    digitalWrite(fan, HIGH);
    digitalWrite(heater1, HIGH);
    digitalWrite(heater2, HIGH);
    
    sendSMS();
    
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("FISH IS");
    lcd.setCursor(2,1);
    lcd.print("COMPLETELY DRIED");
    lcd.setCursor(2,3);
    lcd.print("SMS HAS BEEN SENT");   
      delay(500);    
  }
  if (initial5==100){
    number=0;
    setup();
    SIM900power();
  }
      }  
 }
 if (keypressed != NO_KEY && keypressed == '#') {
  lcd.clear();
  number= 0;
  lcd.setCursor(0,0);
  lcd.print("SET TIME:");
 }
}

//----------------------------------------------------------

void timer1(){
  int count1=23400;


  for (int x=0; x<count1; x++){
  int sensorValue = analogRead(A0);
  int voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  lcd.setCursor(0,0);
  lcd.print(voltage);  
  if (voltage == 0){
    save1=count1-x;
    
    powerLoss1();
    delay(2000);
    
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("POWER LOSS");
    lcd.setCursor(2,1);
    lcd.print("DETECTED!");
    delay(5000);   
    lcd.clear();
    
    battery1=100; // to exit
    
  } else {
    digitalWrite(battery,HIGH);
  }
  lcd.setCursor(0,3);
  lcd.print("Type: Bulinaw");
  
  DHT.read11(dht_apin);
  lcd.setCursor(0,2);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
 
  sensors.requestTemperatures();
  tempC=sensors.getTempCByIndex(0);
  tempF=sensors.toFahrenheit(tempC);
  lcd.setCursor(0,1);
  lcd.print("Temperature: ");
  lcd.print(tempC);

  if (tempC <= lowerlimit){
    digitalWrite(fan, LOW);
    digitalWrite(heater1, LOW);
    digitalWrite(heater2, LOW);
  }
  else if (tempC >= lowerlimit && tempC <= higherlimit){
    digitalWrite(fan, LOW);
    digitalWrite(heater1, LOW);
    digitalWrite(heater2, LOW);
  }
  else if (tempC >= higherlimit){
    digitalWrite(fan, LOW);
    digitalWrite(heater1, HIGH);
    digitalWrite(heater2, HIGH);
  }
  
    lcd.setCursor(6,0);
    lcd.print(":");
    lcd.setCursor(9,0);
    lcd.print(":");

    secondsT1--;
    delay(clockk);
   
    if (secondsT1<0){
     minutesT1--;
     secondsT1=59;
}
    if (minutesT1<0){
     hoursT1--;
     minutesT1=59;
}
    if (hoursT1<0){
     hoursT1= 0;
     minutesT1=0;
     secondsT1=59;
}
  if (minutesT1>9){
      lcd.setCursor(7,0);
      lcd.print(minutesT1);
   }
  else {
      lcd.setCursor(7,0);
      lcd.print("0");
      lcd.setCursor(8,0);
      lcd.print(minutesT1);
      lcd.setCursor(9,0);
      lcd.print(":");
   } 
if (secondsT1>9){
  lcd.setCursor(10,0);
  lcd.print(secondsT1);
  }
else {
  lcd.setCursor(10,0);
  lcd.print("0");
  lcd.setCursor(11,0);
  lcd.print(secondsT1);
  lcd.setCursor(12,0);
  lcd.print(" ");
  } 
if (hoursT1>9){
  lcd.setCursor(4,0);
  lcd.print(hoursT1);
  }
else {
  lcd.setCursor(4,0);
  lcd.print("0");
  lcd.setCursor(5,0);
  lcd.print(hoursT1);
  lcd.setCursor(6,0);
  lcd.print(":");
}
  if(battery1==100){
   SIM900power();
    digitalWrite(battery, LOW);
    
  }
initial1=count1; // END    
  
  int readingCANCEL = digitalRead(buttonCANCEL);
  if (readingCANCEL != lastButtonState ) {
    x=count1; // TO EXIT
    secondsT1=59; // TO RETURN ORIGINAL VALUE
    minutesT1=30; // TO RETURN ORIGINAL VALUE
    hoursT1=6; // TO RETURN ORIGINAL VALUE
    initial1=100; // JUMP TO SETUP
  }
  }
  
}
void timer2(){
  int count2=32400;
  
  for (int x=0; x<count2; x++){
 int sensorValue = analogRead(A0);
  int voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  lcd.setCursor(0,0);
  lcd.print(voltage);
  if (voltage == 0){
    save2= count2-x;
    
    powerLoss2();
    
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("POWER LOSS");
    lcd.setCursor(2,1);
    lcd.print("DETECTED!");
    delay(10000);
    lcd.clear();
    
    battery2=100; // to exit
   
  } else { 
    digitalWrite(battery,HIGH);
  }
  lcd.setCursor(0,3);
  lcd.print("Type: Budloy");
  
  DHT.read11(dht_apin);
  lcd.setCursor(0,2);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);

  sensors.requestTemperatures();
  tempC=sensors.getTempCByIndex(0);
  tempF=sensors.toFahrenheit(tempC);
  lcd.setCursor(0,1);
  lcd.print("Temperature: ");
  lcd.print(tempC);

  if (tempC <= lowerlimit){
    digitalWrite(fan, LOW);
    digitalWrite(heater1, LOW);
    digitalWrite(heater2, LOW);
  }
  else if (tempC >= lowerlimit && tempC <= higherlimit){
    digitalWrite(fan, LOW);
    digitalWrite(heater1, LOW);
    digitalWrite(heater2, LOW);
  }
  else if (tempC >= higherlimit){
    digitalWrite(fan, LOW);
    digitalWrite(heater1, HIGH);
    digitalWrite(heater2, HIGH);
  }
    lcd.setCursor(6,0);
    lcd.print(":");
    lcd.setCursor(9,0);
    lcd.print(":");

    secondsT2--;
    delay(clockk);
      if (secondsT2<0){
     minutesT2--;
     secondsT2=59;
}
    if (minutesT2<0){
     hoursT2--;
     minutesT2=59;
}
    if (hoursT2<0){
     hoursT2= 0;
     minutesT2=59;
     secondsT2=59;
}
  if (minutesT2>9){
      lcd.setCursor(7,0);
      lcd.print(minutesT2);
   }
  else {
      lcd.setCursor(7,0);
      lcd.print("0");
      lcd.setCursor(8,0);
      lcd.print(minutesT2);
      lcd.setCursor(9,0);
      lcd.print(":");
   } 
if (secondsT2>9){
  lcd.setCursor(10,0);
  lcd.print(secondsT2);
  }
else {
  lcd.setCursor(10,0);
  lcd.print("0");
  lcd.setCursor(11,0);
  lcd.print(secondsT2);
  lcd.setCursor(12,0);
  lcd.print(" ");
  } 
if (hoursT2>9){
  lcd.setCursor(4,0);
  lcd.print(hoursT2);
  }
else {
  lcd.setCursor(4,0);
  lcd.print("0");
  lcd.setCursor(5,0);
  lcd.print(hoursT2);
  lcd.setCursor(6,0);
  lcd.print(":");
}

  if(battery2==100){
   SIM900power();
   digitalWrite(battery, LOW);
  }
initial2=count2; // END
    
  int readingCANCEL = digitalRead(buttonCANCEL);
  if (readingCANCEL != lastButtonState ) {
    x=count2; // TO EXIT
    secondsT2=59; // TO RETURN ORIGINAL VALUE
    minutesT2=59; // TO RETURN ORIGINAL VALUE
    hoursT2=8; // TO RETURN ORIGINAL VALUE
    initial2=100; // JUMP TO SETUP
  }
  }
  
}
void timer3(){
  int count3=18000;
  
  for (int x=0; x<=count3; x++){
 
  int sensorValue = analogRead(A0);
  int voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  lcd.setCursor(0,0);
  lcd.print(voltage);
  if (voltage == 0){
    save3= count3-x;
    
    powerLoss3();
    delay(2000);
    
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("POWER LOSS");
    lcd.setCursor(2,1);
    lcd.print("DETECTED!");
    delay(5000);
    lcd.clear();

    
    battery3=100; // to exit
    
  } else { 
    digitalWrite(battery,HIGH);
  }
  lcd.setCursor(0,3);
  lcd.print("Type: Lupoy");
  
  DHT.read11(dht_apin);
  lcd.setCursor(0,2);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  
  sensors.requestTemperatures();
  tempC=sensors.getTempCByIndex(0);
  tempF=sensors.toFahrenheit(tempC);
  lcd.setCursor(0,1);
  
  lcd.print("Temperature: ");
  lcd.print(tempC);

  if (tempC <= lowerlimit){
    digitalWrite(fan, LOW);
    digitalWrite(heater1, LOW);
    digitalWrite(heater2, LOW);
  }
  else if (tempC >= lowerlimit && tempC <= higherlimit){
    digitalWrite(fan, LOW);
    digitalWrite(heater1, LOW);
    digitalWrite(heater2, LOW);
  }
  else if (tempC >= higherlimit){
    digitalWrite(fan, LOW);
    digitalWrite(heater1, HIGH);
    digitalWrite(heater2, HIGH);
  }
    lcd.setCursor(6,0);
    lcd.print(":");
    lcd.setCursor(9,0);
    lcd.print(":");

    secondsT3--;
    delay(clockk);
   
    if (secondsT3<0){
     minutesT3--;
     secondsT3=59;
}
    if (minutesT3<0){
     hoursT3--;
     minutesT3=59;
}
    if (hoursT3<0){
     hoursT3= 0;
     minutesT3=0;
     secondsT3=59;
}
  if (minutesT3>9){
      lcd.setCursor(7,0);
      lcd.print(minutesT3);
   }
  else {
      lcd.setCursor(7,0);
      lcd.print("0");
      lcd.setCursor(8,0);
      lcd.print(minutesT3);
      lcd.setCursor(9,0);
      lcd.print(":");
   } 
if (secondsT3>9){
  lcd.setCursor(10,0);
  lcd.print(secondsT3);
  }
else {
  lcd.setCursor(10,0);
  lcd.print("0");
  lcd.setCursor(11,0);
  lcd.print(secondsT3);
  lcd.setCursor(12,0);
  lcd.print(" ");
  } 
if (hoursT3>9){
  lcd.setCursor(4,0);
  lcd.print(hoursT3);
  }
else {
  lcd.setCursor(4,0);
  lcd.print("0");
  lcd.setCursor(5,0);
  lcd.print(hoursT3);
  lcd.setCursor(6,0);
  lcd.print(":");
}

  if(battery3==100){
   SIM900power();
    digitalWrite(battery, LOW);
  }

initial3=count3;

  int readingCANCEL = digitalRead(buttonCANCEL);
  if (readingCANCEL != lastButtonState ) {
    x=count3; // TO EXIT
    secondsT3=59; // TO RETURN ORIGINAL VALUE
    minutesT3=59; // TO RETURN ORIGINAL VALUE
    hoursT3=4; // TO RETURN ORIGINAL VALUE
    initial3=100; // JUMP TO SETUP
  }
  }
  
}

void timerA () {
  int count4=value;
  origfloat=value/60/60;
  Serial.println(origfloat);
  integer=origfloat;
  Serial.println(integer);
 int val1=origfloat*1000;
  int val2=val1/10;
  result=val2-(integer*100);
  val=result*60/100;
  Serial.println(val);
  int minutesT4 = val;


  
  for (int x = 0; x <= count4; x++) {
  int sensorValue = analogRead(A0);
  int voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
   lcd.setCursor(0,1);
  lcd.print(voltage);
   if (voltage == 0){
    save4= count4-x;
    
    powerLoss4();
    delay(2000);

    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("POWER LOSS");
    lcd.setCursor(2,1);
    lcd.print("DETECTED!");
    delay(5000);
    lcd.clear();
    
    battery4=100;
   
  } else { 
    digitalWrite(battery,HIGH);
  }
  DHT.read11(dht_apin);
  lcd.setCursor(0,2);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);

  sensors.requestTemperatures();
  tempC=sensors.getTempCByIndex(0);
  tempF=sensors.toFahrenheit(tempC);
  lcd.setCursor(0,3);
  lcd.print("Temperature: ");
  lcd.print(tempC);

  if (tempC <= lowerlimit){
    digitalWrite(fan, HIGH);
    digitalWrite(heater1, LOW);
    digitalWrite(heater2, LOW);
  }
  else if (tempC >= lowerlimit && tempC <= higherlimit){
    digitalWrite(fan, LOW);
    digitalWrite(heater1, LOW);
    digitalWrite(heater2, LOW);
  }
  else if (tempC >= higherlimit){
    digitalWrite(fan, LOW);
    digitalWrite(heater1, HIGH);
    digitalWrite(heater2, HIGH);
  }
    lcd.setCursor(6, 1);
    lcd.print(":");
    lcd.setCursor(9, 1);
    lcd.print(":");

    secondsT4--;
    delay(clockk);

    if (secondsT4 < 0) {
      minutesT4--;
      secondsT4 = 59;
    }
    if (minutesT4 < 0) {
      hoursT5--;
      minutesT4 = val ;
    }
    if (hoursT5 < 0) {
      minutesT4 = val;
      secondsT4 = 59;
    }
    if (minutesT4 > 9) {
      lcd.setCursor(7, 1);
      lcd.print(minutesT4);
    }
    else {
      lcd.setCursor(7, 1);
      lcd.print("0");
      lcd.setCursor(8, 1);
      lcd.print(minutesT4);
      lcd.setCursor(9, 1);
      lcd.print(":");
    }
    if (secondsT4 > 9) {
      lcd.setCursor(10, 1);
      lcd.print(secondsT4);
    }
    else {
      lcd.setCursor(10, 1);
      lcd.print("0");
      lcd.setCursor(11, 1);
      lcd.print(secondsT4);
      lcd.setCursor(12, 1);
      lcd.print(" ");
    }
    if (hoursT5 > 9) {
      lcd.setCursor(4, 1);
      lcd.print(hoursT5);
    }
    else {
      
      lcd.setCursor(4, 1);
      lcd.print("0");
      lcd.setCursor(5, 1);
      lcd.print(hoursT5);
      lcd.setCursor(6, 1);
      lcd.print(":");
    
  }
  initial4=x;
    if(battery4==100){
    SIM900power();
    digitalWrite(battery, LOW);
  }
  
     int readingCANCEL = digitalRead(buttonCANCEL);
  if (readingCANCEL != lastButtonState ) {
    x=count4; // TO EXIT
   initial4=100;
  }
 }
}

void timerB() {
  
  int count5=value;
   origfloat=value/60/60;
  Serial.println(origfloat);
  integer=origfloat;
  Serial.println(integer);
 int val1=origfloat*1000;
  int val2=val1/10;
  result=val2-(integer*100);
  val=result*60/100;
  Serial.println(val);
  
 int hoursT4= integer;
 int minutesT5=val;

  
  for (int x=0; x<= count5; x++) {
int sensorValue = analogRead(A0);
  int voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
   lcd.setCursor(0,1);
  lcd.print(voltage);
    if (voltage == 0){
    save5= count5-x;
    
    powerLoss5();
    delay(2000);
    
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("POWER LOSS");
    lcd.setCursor(2,1);
    lcd.print("DETECTED!");
    delay(5000);
    lcd.clear();
    
    battery5=100;
   
  } else { 
    digitalWrite(battery,HIGH);
  }
  DHT.read11(dht_apin);
  lcd.setCursor(0,2);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);

  sensors.requestTemperatures();
  tempC=sensors.getTempCByIndex(0);
  tempF=sensors.toFahrenheit(tempC);
  lcd.setCursor(0,3);
  lcd.print("Temperature: ");
  lcd.print(tempC);

  if (tempC <= lowerlimit){
    digitalWrite(fan, LOW);
    digitalWrite(heater1, LOW);
    digitalWrite(heater2, LOW);
  }
  else if (tempC >= lowerlimit && tempC <= higherlimit){
    digitalWrite(fan, LOW);
    digitalWrite(heater1, LOW);
    digitalWrite(heater2, LOW);
  }
  else if (tempC >= higherlimit){
    digitalWrite(fan, LOW);
    digitalWrite(heater1, HIGH);
    digitalWrite(heater2, HIGH);
  }
    lcd.setCursor(6, 1);
    lcd.print(":");
    lcd.setCursor(9, 1);
    lcd.print(":");
    
     secondsT4--;
    delay(clockk);

    if (secondsT4 < 0) {
      minutesT5--;
      secondsT4 = 59;
    }
    if (minutesT5 < 0) {
      hoursT4--;
      minutesT5 = 59 ;
    }
    if (hoursT4 < 0) {
      minutesT5 = 59;
      secondsT4 = 59;
    }
    
    if (minutesT5 > 9) {
      lcd.setCursor(7, 1);
      lcd.print(minutesT5);
    }
    else {
      lcd.setCursor(7, 1);
      lcd.print("0");
      lcd.setCursor(8, 1);
      lcd.print(minutesT5);
      lcd.setCursor(9, 1);
      lcd.print(":");
    }
    if (secondsT4 > 9) {
      lcd.setCursor(10, 1);
      lcd.print(secondsT4);
    }
    else {
      lcd.setCursor(10, 1);
      lcd.print("0");
      lcd.setCursor(11, 1);
      lcd.print(secondsT4);
      lcd.setCursor(12, 1);
      lcd.print(" ");
    }
    if (hoursT4 > 9) {
      lcd.setCursor(4, 1);
      lcd.print(hoursT4);
    }
    else {
      
      lcd.setCursor(4, 1);
      lcd.print("0");
      lcd.setCursor(5, 1);
      lcd.print(hoursT4);
      lcd.setCursor(6, 1);
      lcd.print(":");
    }
  
initial5=x;
    if(battery5==100){
   SIM900power();
   digitalWrite(battery, LOW);
  }
  
 
  int readingCANCEL = digitalRead(buttonCANCEL);
  if (readingCANCEL != lastButtonState ) {
    x=count5; // TO EXIT
    initial5=100;
  }
}
}
void detectedbuttons() {
   
  if (keypressed != NO_KEY) {
    if (keypressed == '0') {
      Serial.println("button 0");
      if (number == 0)
        number = 0;
      else
        number = (number * 10) + 0;
    }
    if (keypressed == '1') {
      Serial.println("button 1");
      if (number == 0)
        number = 1;
      else
        number = (number * 10) + 1;
    }
    if (keypressed == '2') {
      Serial.println("button 2");
      if (number == 0)
        number = 2;
      else
        number = (number * 10) + 2;
    }
    if (keypressed == '3') {
      Serial.println("button 3");
      if (number == 0)
        number = 3;
      else
        number = (number * 10) + 3;
    }
    if (keypressed == '4') {
      Serial.println("button 4");
      if (number == 0)
        number = 4;
      else
        number = (number * 10) + 4;
    }
    if (keypressed == '5') {
      Serial.println("button 5");
      if (number == 0)
        number = 5;
      else
        number = (number * 10) + 5;
    }
    if (keypressed == '6') {
      Serial.println("button 6");
      if (number == 0)
        number = 6;
      else
        number = (number * 10) + 6;
    }
    if (keypressed == '7') {
      Serial.println("button 7");
      if (number == 0)
        number = 7;
      else
        number = (number * 10) + 7;
    }
    if (keypressed == '8') {
      Serial.println("button 8");
      if (number == 0)
        number = 8;
      else
        number = (number * 10) + 8;
    }
    if (keypressed == '9') {
      Serial.println("button 9");
      if (number == 0)
        number = 9;
      else
        number = (number * 10) + 9;
    }
    if (keypressed == 'A' || keypressed == 'B' || keypressed == 'C' || keypressed == 'D' || keypressed == 'E' || keypressed == 'F' ) {
      num1 = number;
      number = 0;
      if (keypressed == 'A') {
        lcd.print("A");
      }
      if (keypressed == 'B') {
        lcd.print("B");
      }
      if (keypressed == 'D') {
        lcd.print("D");
      }
      if (keypressed == 'E') {
        lcd.print("E");
      }
      if (keypressed == 'F') {
        lcd.print("F");
      }
      else if (keypressed != NO_KEY && keypressed == 'C') {
        number = 0;
        lcd.clear();
        keypressed = ' ';
      }
    }
    delay(100);
  }
}
void sendSMS(){

//AT command to set SIM900 to SMS mode
SIM900.print("AT+sCMGF=1\r");
delay(100);

//REPLACE THE X's WITH THE RECIPIENTS MOBILE NUMBER
//USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS

SIM900.println("AT + CMGS = \"+639973665068\"");
delay(100);


//REPLACE WITH YOUR OWN SMS MESSAGE CONTENT

SIM900.println("THIS IS A TEST MESSAGE FROM GSM MODULE. FISH IS COMPLETELY DRIED.");
delay(100);

//End AT command with a ^Z, ASCII code 26
SIM900.println((char)26);
delay(100);
SIM900.println();
//Give module time to send SMS
delay(1000);
}
void powerLoss1(){

//AT command to set SIM900 to SMS mode
SIM900.print("AT+CMGF=1\r");
delay(100);

//REPLACE THE X's WITH THE RECIPIENTS MOBILE NUMBER
//USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS

SIM900.println("AT + CMGS = \"+639973665068\"");
delay(100);


//REPLACE WITH YOUR OWN SMS MESSAGE CONTENT

SIM900.println("[1] POWER LOSS DETECTED");
SIM900.println(save1 );
delay(100);

//End AT command with a ^Z, ASCII code 26
SIM900.println((char)26);
delay(100);
SIM900.println();
//Give module time to send SMS
delay(1000);
}
void powerLoss2(){

//AT command to set SIM900 to SMS mode
SIM900.print("AT+CMGF=1\r");
delay(100);

//REPLACE THE X's WITH THE RECIPIENTS MOBILE NUMBER
//USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS

SIM900.println("AT + CMGS = \"+639973665068\"");
delay(100);


//REPLACE WITH YOUR OWN SMS MESSAGE CONTENT

SIM900.println("[2] POWER LOSS DETECTED" );
SIM900.println(save2);
delay(100);

//End AT command with a ^Z, ASCII code 26
SIM900.println((char)26);
delay(100);
SIM900.println();
//Give module time to send SMS
delay(1000);
}
void powerLoss3(){

//AT command to set SIM900 to SMS mode
SIM900.print("AT+CMGF=1\r");
delay(100);

//REPLACE THE X's WITH THE RECIPIENTS MOBILE NUMBER
//USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS

SIM900.println("AT + CMGS = \"+639973665068\"");
delay(100);


//REPLACE WITH YOUR OWN SMS MESSAGE CONTENT

SIM900.println("[3] POWER LOSS DETECTED" );
SIM900.println(save3 );
delay(100);

//End AT command with a ^Z, ASCII code 26
SIM900.println((char)26);
delay(100);
SIM900.println();
//Give module time to send SMS
delay(1000);
}
void powerLoss4(){

//AT command to set SIM900 to SMS mode
SIM900.print("AT+CMGF=1\r");
delay(100);

//REPLACE THE X's WITH THE RECIPIENTS MOBILE NUMBER
//USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS

SIM900.println("AT + CMGS = \"+639973665068\"");
delay(100);


//REPLACE WITH YOUR OWN SMS MESSAGE CONTENT

SIM900.println("[4] POWER LOSS DETECTED" );
SIM900.println(save4);
delay(100);

//End AT command with a ^Z, ASCII code 26
SIM900.println((char)26);
delay(100);
SIM900.println();
//Give module time to send SMS
delay(1000);
}
void powerLoss5(){

//AT command to set SIM900 to SMS mode
SIM900.print("AT+CMGF=1\r");
delay(100);

//REPLACE THE X's WITH THE RECIPIENTS MOBILE NUMBER
//USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS

SIM900.println("AT + CMGS = \"+639973665068\"");
delay(100);


//REPLACE WITH YOUR OWN SMS MESSAGE CONTENT

SIM900.println("[4] POWER LOSS DETECTED" );
SIM900.println(save5);
delay(100);

//End AT command with a ^Z, ASCII code 26
SIM900.println((char)26);
delay(100);
SIM900.println();
//Give module time to send SMS
delay(1000);
}
void SIM900power(){
  digitalWrite(9,LOW);
  delay(1000);
  digitalWrite(9,HIGH);
  delay(2000);
  digitalWrite(9,LOW);
  delay(3000);
}
