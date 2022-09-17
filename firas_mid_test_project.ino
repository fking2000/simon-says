int redled = 11;
int blueled = 6;
int greenled = 9;
int yellowled = 10;
int xaxis = A3;
int yaxis = A2;


int xread;
int yread;


int generator = 0;
int counter = 0;
void setup() {
  
  pinMode(redled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(blueled, OUTPUT);
  pinMode(greenled, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
 
 
  Serial.print("led : ");
  generator = random(1,8); 
  Serial.println(generator);
  gen(generator);
  Serial.print("correct moves : ");
  counter++; 
  Serial.println(counter);
  delay(1000);
    if (counter > 9){Serial.println("game over, press the reset button ");for(;;){}}
}
void gen(int seq) {
  switch (seq) {
    case 1:
      digitalWrite(blueled, HIGH);
      for (;;) {
        xread = analogRead(xaxis);
        yread = analogRead(yaxis);
        if ( yread < 10) {
          allOff();
          break;
        }
      }
      break;
    case 2:
      digitalWrite(redled, HIGH);
      for (;;) {
        xread = analogRead(xaxis);
        yread = analogRead(yaxis);
        if ( xread > 1000) {
          allOff();
          break;

        }
      }
     break;
    case 3:
      digitalWrite(greenled, HIGH);
      for (;;) {
        xread = analogRead(xaxis);
        yread = analogRead(yaxis);
        if ( xread < 10) {
          allOff();
          break;

        }
      }
     break;
    case 4:
      digitalWrite(yellowled, HIGH);
      for (;;) {
        xread = analogRead(xaxis);
        yread = analogRead(yaxis);
        if (yread > 1000) {
          allOff();
          break;

        }
      }
break;
    case 5:
      
      digitalWrite(yellowled, HIGH);
      digitalWrite(redled, HIGH);
      for (;;) {
        xread = analogRead(xaxis);
        yread = analogRead(yaxis);
        if (yread > 1000 && xread > 1000) {
          allOff();
          break;
        }
      }
      break;
    case 6:
      digitalWrite(yellowled, HIGH);
      digitalWrite(greenled, HIGH);
      for (;;) {
        xread = analogRead(xaxis);
        yread = analogRead(yaxis);
        if (yread > 1000 && xread < 10) {
          allOff();
          break;
        }
      }
      break;
    case 7:
      digitalWrite(blueled, HIGH);
      digitalWrite(redled, HIGH);
      for (;;) {
        xread = analogRead(xaxis);
        yread = analogRead(yaxis);
        if (yread < 10 && xread > 1000) {
          allOff();
          break; 
        }
      }
      break;
    case 8:
      digitalWrite(blueled, HIGH);
      digitalWrite(greenled, HIGH);
      for (;;) {
        xread = analogRead(xaxis);
        yread = analogRead(yaxis);
        if (yread < 10 && xread < 10) {
          allOff();
          break;
        }
      }
      break;
    default:
      break;
  }
}
void allOff() {
  digitalWrite(redled, LOW);
  digitalWrite(yellowled, LOW);
  digitalWrite(greenled, LOW);
  digitalWrite(blueled, LOW);

}
