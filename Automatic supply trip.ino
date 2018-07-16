const int sensorIn = 34;
int mVperAmp = 100; // use 100 for 20A Module and 66 for 30A Module


double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;
double Amps=0;
int flag = 0;
int count=0;
void setup(){ 
 Serial.begin(115200);
 pinMode(27,OUTPUT);
}

void loop(){
 
 amps1();
 
 Serial.print(" Amps RMS:");
  Serial.print(AmpsRMS);
  Serial.println(" ");

 Serial.print(" Amps:");
  Serial.print(Amps);
Serial.println(" ");
if(Amps<3)
{
  digitalWrite(27,HIGH);
}

 if(Amps>3)//for 20A, but for 5A it is 4
 {
  do{

 if(count>=2)
 {
  digitalWrite(27,LOW);//Trigger Relay off 
 
 break;
 }
  Serial.println("relay OFF");
  digitalWrite(27,LOW);//Trigger Relay off 
  delay(10000);
  digitalWrite(27,HIGH);//Trigger Relay on
  delay(2000);
  amps1();
  count+=1;
  }while(Amps>3);
 
 }


 }


float getVPP()
{
  float result;
  
  int readValue;             //value read from the sensor
  int maxValue = 0;          // store max value here
  int minValue = 4096;          // store min value here
  
   uint32_t start_time = millis();
   while((millis()-start_time) < 1000) //sample for 1 Sec
   {
       readValue = analogRead(sensorIn);
       //Serial.println(readValue);
       // see if you have a new maxValue
       if (readValue > maxValue) 
       {
           /*record the maximum sensor value*/
           maxValue = readValue;
       }
       if (readValue < minValue) 
       {
           /*record the maximum sensor value*/
           minValue = readValue;
       }
   }
   
   // Subtract min from max
   result = (((maxValue - minValue)) * 5.0)/4096.0;
      
   return result;
 }

 void amps1()
 {
 Voltage = getVPP();
 VRMS = (Voltage/2.0) *0.707; 
 AmpsRMS = (VRMS * 1000)/mVperAmp;
 Amps=((Voltage/2)*1000)/mVperAmp;
 }

