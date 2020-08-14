#define lf 2
#define lr 3
#define rf 4
#define rr 5
#define buzzer 11

char t;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(lf,OUTPUT);
  pinMode(lr,OUTPUT);
  
  pinMode(rf,OUTPUT);
  pinMode(rr,OUTPUT);

  pinMode(buzzer,OUTPUT);

  beep();
  beep();
  
}
void beep()
{
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
}
void fwd()
{
  digitalWrite(lf,HIGH);
  digitalWrite(rf,HIGH);

  digitalWrite(lr,LOW);
  digitalWrite(rr,LOW);
}
void bwd()
{
  digitalWrite(lf,LOW);
  digitalWrite(rf,LOW);
  
  digitalWrite(lr,HIGH);
  digitalWrite(rr,HIGH);
}
void lft()
{
  digitalWrite(lf,LOW);
  digitalWrite(rf,HIGH);
  
  digitalWrite(lr,HIGH);
  digitalWrite(rr,LOW); 
}
void ryt()
{
  digitalWrite(lf,HIGH);
  digitalWrite(rf,LOW);
  
  digitalWrite(lr,LOW);
  digitalWrite(rr,HIGH);
}
void brk()
{
  digitalWrite(lr,LOW);
  digitalWrite(lf,LOW);
  
  digitalWrite(rf,LOW);
  digitalWrite(rr,LOW);
}
void loop() 
{
  if(Serial.available())
  {
      t = Serial.read();
      Serial.println(t);
  }
  if(t == 'a')
  {
    beep();
    fwd();
    delay(5000);
    brk();
  }
  else if(t == 'b')
  {
    beep();
    ryt();
    delay(300);
    
    brk();
    delay(1000);
    
    fwd();
    delay(5000);

    brk();
    delay(1000);
  }
  else if(t == 'c')
  {
    beep();
    lft();
    delay(600);
    
    brk();
    delay(1000);
    
    fwd();
    delay(5000);

    brk();
    delay(1000);
  }
  else if(t == 's')
  {
    beep();
    brk();
  }
  t=0;
}
