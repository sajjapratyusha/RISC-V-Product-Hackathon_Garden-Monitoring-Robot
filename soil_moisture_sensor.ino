int soil=A0;
int buzzer=12;
int led =13;
 void setup()
 {
 pinMode(soil,INPUT);
 pinMode(buzzer,OUTPUT);
 pinMode(led,OUTPUT);
   Serial.begin(9600);
 }

 void loop()
 {
 int moisture = analogRead(soil);
  //Serial.println("measure water level in the soil");
   Serial.println(moisture);

 if (moisture>500)
 {
 digitalWrite(buzzer,1);
 digitalWrite(led,1);
 }

 else
 {
 digitalWrite(buzzer,0);
 digitalWrite(led,0);
 }
   delay(2000);
   }
