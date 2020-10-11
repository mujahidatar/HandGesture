
char rec ;
int thresh= 170;
#include <Wire.h> 
int ADXL345 = 0x53;
float X_out, Y_out, Z_out; 
int ReadA0, ReadA1, ReadA2, ReadA3, ReadA6;
void setup() {
  Serial.begin(9600); 
  Wire.begin(); 
 
  Wire.beginTransmission(ADXL345);  
  Wire.write(0x2D); 
  
  Wire.write(8);
  Wire.endTransmission();
  delay(10);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A6,INPUT);
}
void loop() {

  
  if(Serial.available() > 0);
{  
  rec = Serial.read();
}  
  if (rec == 'S')                                                                               
  {
    while(1)
    {
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32); 
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true);
  X_out = ( Wire.read()| Wire.read() << 8);
  X_out = X_out/128;
  Y_out = ( Wire.read()| Wire.read() << 8); 
  Y_out = Y_out/128;
  Z_out = ( Wire.read()| Wire.read() << 8);
  Z_out = Z_out/128;
  /*Serial.print("Xa= ");
  delay(500);
  Serial.print(X_out);
  Serial.print("   Ya= ");
  delay(500);
  Serial.print(Y_out);
  Serial.print("   Za= ");
  delay(500);
  Serial.println(Z_out);*/

  ReadA0 = analogRead(A0);
  
  
  ReadA1 = analogRead(A1);
 
  ReadA2 = analogRead(A2);
 
  ReadA3 = analogRead(A3);
  
  ReadA6 = analogRead(A6);

/*  
  Serial.print(ReadA0);
  Serial.print("    ");
  Serial.print(ReadA1);
  Serial.print("    ");
   Serial.print(ReadA2);
  Serial.print("    ");
  Serial.print(ReadA3);
  Serial.print("    ");
  Serial.println(ReadA6);
  Serial.print("    ");
  delay(1000);
*/



 
if(X_out<1 && Y_out>2 && Z_out<1  && ReadA1>thresh && ReadA2<thresh && ReadA3<thresh && ReadA6<thresh && ReadA0<thresh)
 {
  Serial.println("ONE");
 }

 if(X_out<1 && Y_out>2 && Z_out<1 && ReadA1>thresh&& ReadA2>thresh && ReadA3<thresh && ReadA6<thresh && ReadA0<thresh)
 {
  Serial.println("TWO");
 }

 if(X_out<1 && Y_out>2 && Z_out<1 && ReadA1>thresh && ReadA2>thresh && ReadA3>thresh && ReadA6<thresh && ReadA0<thresh)
 {
  Serial.println("THREE");
 }

 if(X_out<1 && Y_out>2 && Z_out<1 && ReadA1>thresh && ReadA2>thresh && ReadA3>thresh && ReadA6>thresh && ReadA0<thresh)
 {
  Serial.println("FOUR");
 }

 
 

 if(X_out<1 && Y_out>2 && Z_out<1  && ReadA1>thresh && ReadA2>thresh && ReadA3>thresh && ReadA6>thresh && ReadA0>thresh)
 
 {
    Serial.println("HII");
 }
/*
// HOW ARE   
if(X_out>0 && Y_out>0 && Z_out<0 && ReadA1>200 && ReadA2<200 && ReadA3<200 && ReadA6<200 && ReadA0>200){
  Serial.print("HOW ARE");
 }

// YOU

if(X_out<0 && Y_out>0 && Z_out>0 && ReadA1>200 && ReadA2<200 && ReadA3<200 && ReadA6<200 && ReadA0<200){
  Serial.print("YOU");
 } */

//DONE

if(X_out<0 && Y_out>0 && Z_out>0 && ReadA1<thresh && ReadA2<thresh && ReadA3<thresh && ReadA6<thresh && ReadA0>thresh){
  Serial.println("DONE");
 }

/* //left

 if(X_out>0 && Y_out>2 && Z_out>0 && ReadA1<200 && ReadA2<200 && ReadA3<200 && ReadA6<200 && ReadA0>200){
  Serial.print("left");
 }

 //Right

    
 if(X_out<0 && Y_out>0 && Z_out>0 && ReadA1>200 && ReadA2<200 && ReadA3<200 && ReadA6<200 && ReadA0>200){
  Serial.print("Right");
 }

 // UP

 if(X_out<1 && Y_out>2 && Z_out<1 && ReadA1>200 && ReadA2<200 && ReadA3<200 && ReadA6<200 && ReadA0>200)
 {
  Serial.print("UP");
 }

//Down

if(X_out>0 && Y_out<0 && Z_out>0 && ReadA1>200 && ReadA2<200 && ReadA3<200 && ReadA6<200 && ReadA0>200)
 {
  Serial.print("Down");
 }
 */
    }
  }
}
