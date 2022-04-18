byte trig1 = 2;
byte trig2 = 3;
byte echo1 = 4;
byte echo2 = 5;
byte gled1 = 6;
byte gled2 = 13;
byte rled1 = 8;
byte rled2 = 10;
int i=0;
float timeOut=2*(150+10)/100/340*1000000; 
void  setup() {
  // put your setup code here, to run once:
  pinMode(trig1,OUTPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(echo2,INPUT);
  pinMode(gled1,OUTPUT);
  pinMode(gled2,OUTPUT);
  pinMode(rled1,OUTPUT);
  pinMode(rled2,OUTPUT);
  digitalWrite(rled1,LOW);
  digitalWrite(gled1,LOW);
  digitalWrite(rled2,LOW);
  digitalWrite(gled2,LOW);

}

void loop() {
  int d1 = getDistance(trig1,echo1);
  int d2 = getDistance(trig2,echo2);
  if(d1>=100 && d2<=100)
  {
    digitalWrite(rled1,HIGH);
    digitalWrite(gled1,LOW);
    digitalWrite(rled2,LOW);
    digitalWrite(gled2,HIGH);
    delay(5000);
    i=0;
  }
  else if(d1<=100 && d2>=100)
  {
    digitalWrite(rled1,LOW);
    digitalWrite(gled1,HIGH);
    digitalWrite(rled2,HIGH);
    digitalWrite(gled2,LOW);
    delay(5000);
    i=0;
  }
  else if(d1<=100 && d2<=100)
  {
    if(i%2==0)
    {
      digitalWrite(rled1,HIGH);
      digitalWrite(gled1,LOW);
      digitalWrite(rled2,LOW);
      digitalWrite(gled2,HIGH);
      delay(5000);
    }
    else
    {
      digitalWrite(rled1,LOW);
      digitalWrite(gled1,HIGH);
      digitalWrite(rled2,HIGH);
      digitalWrite(gled2,LOW);
      delay(5000);
    }
    i++;
  }
  digitalWrite(rled1,LOW);
  digitalWrite(gled1,LOW);
  digitalWrite(rled2,LOW);
  digitalWrite(gled2,LOW);
  
  // put your main code here, to run repeatedly:

}
int getDistance(byte trig,byte echo)
{
  int distances;
  unsigned long pulseTime; 
  digitalWrite(trig, HIGH);                         //Generate a 10 microsecond pulse
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  pulseTime = pulseIn(echo, HIGH, timeOut);
  distances = (float)pulseTime * 340 / 2 / 10000;
  return distances;
}
