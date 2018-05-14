//Morse Code Binary Tree
//  Left child at 2n+1
// Right child at 2n+2
//         <.|->
//      .E       -T
//    .I  -A   .N  -M
//
const char MorseTree[] = {'\0','E', 'T', 'I', 'A', 'N', 'M', 'S',
                          'U', 'R', 'W', 'D', 'K', 'G', 'O', 'H',
                          'V', 'F', 'U', 'L', 'A', 'P', 'J', 'B',
                          'X', 'C', 'Y', 'Z', 'Q', '\0','\0','5',
                          '4', '\0','3', '\0','\0','\0','2', '\0',
                          '\0','+', '\0','\0','\0','\0','1', '6',
                          '=', '/', '\0','\0','\0','(', '\0','7',
                          '\0','\0','\0','8', '\0','9', '0', '\0',
                          '\0','\0','\0','\0','\0','\0','\0','\0',
                          '\0','\0','\0','?', '_', '\0','\0','\0',
                          '\0','"', '\0','\0','.', '\0','\0','\0',
                          '\0','@', '\0','\0','\0','\0','\0','\0',
                          '-', '\0','\0','\0','\0','\0','\0','\0',
                          '\0',';', '!', '\0',')', '\0','\0','\0',
                          '\0','\0',',', '\0','\0','\0','\0',':',
                          '\0','\0','\0','\0','\0','\0','\0'
                         };
int val = 0; // A Variable to Store the Light Value from the LDR
int ctrHigh = 0;
int ctrLow = 0;
int codePtr = 0;
int dotLen = 450;

int en1 = 5;
 int en2 = 6;
 int in1 = 7;
 int in2 = 8;
 int in3 = 9;
 int in4 = 10;
 //declaring pin nos of SECOND L293D
 int en1o2 = 3;
 int en2o2 = 11;
 int in1o2 = 4;
 int in2o2 = 12;
 int in3o2 = 14;
 int in4o2 = 15;
 int motorPin[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15};//array for storing pin nos
 
void setup()
{
  Serial.begin(9600);// Start a Serial Connection
  Serial.print(codePtr);
   Serial.println("setup");


    
 for (int i = 0; i < 12; i++) 
 {
        pinMode(motorPin[i], OUTPUT);
 }//close for loop
}
void loop()
{
  char  a;
  val = analogRead(4);
 // Serial.print(val);
  //Serial.print("");
  if (val >= 590)
  {
    ctrHigh++;
    ctrLow = 0;
    digitalWrite(13, HIGH);
    tone(9, 1000);
  } else {
    if(ctrHigh==0);
    else{
      Serial.print(ctrHigh);
    }
    ctrLow++;
    if ((ctrHigh >= dotLen) && (ctrHigh < dotLen*2)) {
      Serial.print(".");
      codePtr = (2*codePtr) + 1;
    } else if (ctrHigh >= dotLen * 2) {
      Serial.print("-");
      codePtr = (2*codePtr) + 2;
    } else {
      if(ctrLow == dotLen*2){
        Serial.print(MorseTree[codePtr]);
        a=MorseTree[codePtr];
        if(a == 'F')
        {
          forward();//go forward when f is pressed
        }
        if(a == 'B')
      {
        backward();//go backward when b is pressed
      }
        if(a == 'S')
      {
        stopMotor();//stop/brake when s is pressed
      }
        if(a == 'L')
      {
        left();//go left when l is presed
      }
        if(a == 'R')
        {
          right();//go right when r is pressed
        }
        codePtr = 0;
      }
    }
    ctrHigh = 0;
    digitalWrite(13, LOW);
    noTone(9);
    
  }
  //delay(300);
}

//set of functions
void forward()
{
 // digitalWrite(en1,HIGH);
  //digitalWrite(en2,HIGH);
  digitalWrite(en1o2,HIGH);
  digitalWrite(en2o2,HIGH);
 // digitalWrite(in1,HIGH);
  digitalWrite(in1o2,HIGH);
 // digitalWrite(in2,LOW);
  digitalWrite(in2o2,LOW);
 // digitalWrite(in3,LOW);
  digitalWrite(in3o2,LOW);
 // digitalWrite(in4,HIGH);
  digitalWrite(in4o2,HIGH);
  }
  
  
void backward()
{
 // digitalWrite(en1,HIGH);
  //digitalWrite(en2,HIGH);
  digitalWrite(en1o2,HIGH);
  digitalWrite(en2o2,HIGH);
 // digitalWrite(in1,LOW);
  digitalWrite(in1o2,LOW);
 // digitalWrite(in2,HIGH);
  digitalWrite(in2o2,HIGH);
 // digitalWrite(in3,HIGH);
  digitalWrite(in3o2,HIGH);
//  digitalWrite(in4,LOW);
  digitalWrite(in4o2,LOW);
  
}

void left()
{
 // digitalWrite(en1,HIGH);
 // digitalWrite(en2,HIGH);
  digitalWrite(en1o2,HIGH);
  digitalWrite(en2o2,HIGH);
 // digitalWrite(in1,LOW);
  digitalWrite(in1o2,LOW);
 // digitalWrite(in2,LOW);
  digitalWrite(in2o2,LOW);
 // digitalWrite(in3,LOW);
  digitalWrite(in3o2,LOW);
 // digitalWrite(in4,HIGH);
  digitalWrite(in4o2,HIGH);
  
}

void right()
{
 // digitalWrite(en1,HIGH);
 // digitalWrite(en2,HIGH);
  digitalWrite(en1o2,HIGH);
  digitalWrite(en2o2,HIGH);
 // digitalWrite(in1,HIGH);
  digitalWrite(in1o2,HIGH);
 // digitalWrite(in2,LOW);
  digitalWrite(in2o2,LOW);
 // digitalWrite(in3,LOW);
  digitalWrite(in3o2,LOW);
 // digitalWrite(in4,LOW);
  digitalWrite(in4o2,LOW);
  
}

void stopMotor()
{
  //digitalWrite(en1,HIGH);
  //digitalWrite(en2,HIGH);
  digitalWrite(en1o2,HIGH);
  digitalWrite(en2o2,HIGH);
 // digitalWrite(in1,LOW);
  digitalWrite(in1o2,LOW);
 // digitalWrite(in2,LOW);
  digitalWrite(in2o2,LOW);
 // digitalWrite(in3,LOW);
  digitalWrite(in3o2,LOW);
 // digitalWrite(in4,LOW);
  digitalWrite(in4o2,LOW);
}
  //End Of Code
