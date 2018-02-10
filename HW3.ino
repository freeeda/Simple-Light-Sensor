//set up my analog input and digital output
int reading;
int blue = 7;
int red = 2;
int mapped;

void setup() {
  Serial.begin(9600);
  pinMode(blue,OUTPUT);
  pinMode(red,OUTPUT);

}

void loop() {
  reading = analogRead(A0);
  
  //map the range to 0 ~ 5
  mapped = map(reading,0,1023,0,5);
  
  //check if photoresistor is working
  Serial.println(reading);
  Serial.println(mapped);

  //when it is darker, resistence is smaller
  //only light up the red LED
  if (mapped < 2.5){
    digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
    }
   //when it is lighter, resistence is larger
  //only light up the blue LED
   else if (mapped >= 2.5){
    digitalWrite(blue,HIGH);
    digitalWrite(red,LOW);
    }

}
