
int ANNOYstate = 0;
int buttonval;
int oldbuttonval;  
int randomSeconds(){  
  int random_number = rand() % 100 + 5;
  int wait = random_number * 1000;
  return wait;
}
    
void setup() {
  // put your setup code here, to run once:
  pinMode(9,INPUT);
  pinMode(10,OUTPUT);  // light
  pinMode(11, OUTPUT); // Speaker
}

void loop() {
  analogWrite(11,0); // turns speaker off 
  digitalWrite(10,LOW); // turns light off
  //put your main code here, to run repeatedly:
  buttonval = digitalRead(9);
  
  if( (buttonval == LOW) && (oldbuttonval == HIGH) ){
    ++ANNOYstate;   // 0 is "off", not 0 is "on"
  }
  oldbuttonval=buttonval;
  
  if(ANNOYstate >= 2) {
    ANNOYstate = 0; 
  }
  
  while(ANNOYstate == 1) { //on
    // TODO Replace delay with this milli thing so it can be interrupted by the button: https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay
    digitalWrite(10,HIGH); // turns light on
    analogWrite(11,0);
    delay( randomSeconds() );
    analogWrite(11,100);  // make NoISe
    delay( randomSeconds() );
 }
}



//delay(10);
