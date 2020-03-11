#define sw1 22
#define sw2 24
#define sw3 26
#define sw4 28
#define sw5 30
#define sw6 32
#define hammer 34
#define Startbutton 36
#define reset 38
#define light1Pin 23
#define light2Pin 25
#define light3Pin 27
#define light4Pin 29
#define light5Pin 31
#define light6Pin 33
#define DISPLAY_REFRESH_TIME  0.1
#define DIGIT0  4
#define DIGIT1  3
#define DIGIT2  6
#define DIGIT3  7
#include <Servo.h>
Servo myservo;
boolean first_rand = 1;
int mode = 0;
struct DISPLAY_7SEGMENT {
              // segment a  b  c  d  e  f  g 
  int data[10][7] = {{ 0, 0, 0, 0, 0, 0, 1 },  // '0'
    { 1, 0, 0, 1, 1, 1, 1 },  // '1'
    { 0, 0, 1, 0, 0, 1, 0 },  // '2'
    { 0, 0, 0, 0, 1, 1, 0 },  // '3'
    { 1, 0, 0, 1, 1, 0, 0 },  // '4'
    { 0, 1, 0, 0, 1, 0, 0 },  // '5'
    { 0, 1, 0, 0, 0, 0, 0 },  // '6'
    { 0, 0, 0, 1, 1, 1, 1 },  // '7'
    { 0, 0, 0, 0, 0, 0, 0 },  // '8'
    { 0, 0, 0, 0, 1, 0, 0 },  // '9'
  };
byte segment_score[7] = { 47, 48, 49, 50, 51, 52, 53};
};
byte segment, digit_count = 0, display_data[4] = { 0,0,0,0};

struct DISPLAY_7SEGMENT  segment_display;

unsigned long previous_display_refresh_time = 0, pre_time = 0, freq_rand = 0;
int dpoint1 = 0, dpoint2 = 0, dtime1 = 0, dtime2 = 0, dhpoint1 = 0, dhpoint2 = 0 ;
int high_score = 0, Play_time = 0, Real_score = 0, random_value, servo_angle = 0,count1=0;
boolean debounce_process_status1 = false;
const unsigned long debounce_time1 = 50;
unsigned long first_keypress_time1 = 0;
boolean key_release1 = true;

boolean debounce_process_status2 = false;
const unsigned long debounce_time2 = 50;
unsigned long first_keypress_time2 = 0;
boolean key_release2 = true;


boolean debounce_process_status3 = false;
const unsigned long debounce_time3 = 50;
unsigned long first_keypress_time3 = 0;
boolean key_release3 = true;


boolean debounce_process_status4 = false;
const unsigned long debounce_time4 = 50;
unsigned long first_keypress_time4 = 0;
boolean key_release4 = true;

boolean debounce_process_status5 = false;
const unsigned long debounce_time5 = 50;
unsigned long first_keypress_time5 = 0;
boolean key_release5 = true;

boolean debounce_process_status6 = false;
const unsigned long debounce_time6 = 50;
unsigned long first_keypress_time6 = 0;
boolean key_release6 = true;

boolean debounce_process_status7 = false;
const unsigned long debounce_time7 = 50;
unsigned long first_keypress_time7 = 0;
boolean key_release7 = true;

boolean debounce_process_status8 = false;
const unsigned long debounce_time8 = 50;
unsigned long first_keypress_time8 = 0;
boolean key_release8 = true;

boolean debounce_process_status9 = false;
const unsigned long debounce_time9 = 50;
unsigned long first_keypress_time9 = 0;
boolean key_release9 = true;

int button_status1 = 0, button_status2 = 0, button_status3 = 0, button_status4 = 0, button_status5 = 0;
int button_status6 = 0, button_status7 = 0, button_status8 = 0, button_status9 = 9;

void setup() {
  Serial.begin(9600);
  //Swiches
  pinMode(23, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(sw4, INPUT_PULLUP);
  pinMode(sw5, INPUT_PULLUP);
  pinMode(sw6, INPUT_PULLUP);
  pinMode(hammer, INPUT_PULLUP);
  pinMode(Startbutton, INPUT_PULLUP);
  pinMode(reset, INPUT_PULLUP);
  myservo.attach(9, 0, 1);
  for (count1 = 45; count1 <53; count1++) {
    pinMode(count1, OUTPUT);
  }
  pinMode(DIGIT0, OUTPUT);
  pinMode(DIGIT1, OUTPUT);
  pinMode(DIGIT2, OUTPUT);
  pinMode(DIGIT3, OUTPUT);
 // pinMode(DIGIT3, OUTPUT);

  pinMode(47, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);
  digitalWrite(DIGIT0, HIGH);
  digitalWrite(DIGIT1, HIGH);
  digitalWrite(DIGIT2, HIGH);
  digitalWrite(DIGIT3, HIGH);
}

void light_brigh() {
  if (random_value == 1) {
    digitalWrite(light1Pin, HIGH);
    digitalWrite(light2Pin, LOW);
    digitalWrite(light3Pin, LOW);
    digitalWrite(light4Pin, LOW);
    digitalWrite(light5Pin, LOW);
    digitalWrite(light6Pin, LOW);
  }
  if (random_value == 2) {

    digitalWrite(light1Pin, LOW);
    digitalWrite(light2Pin, HIGH);
    digitalWrite(light3Pin, LOW);
    digitalWrite(light4Pin, LOW);
    digitalWrite(light5Pin, LOW);
    digitalWrite(light6Pin, LOW);
  }
  if (random_value == 3) {
    digitalWrite(light1Pin, LOW);
    digitalWrite(light2Pin, LOW);
    digitalWrite(light3Pin, HIGH);
    digitalWrite(light4Pin, LOW);
    digitalWrite(light5Pin, LOW);
    digitalWrite(light6Pin, LOW);
  }
  if (random_value == 4) {
    digitalWrite(light1Pin, LOW);
    digitalWrite(light2Pin, LOW);
    digitalWrite(light3Pin, LOW);
    digitalWrite(light4Pin, HIGH);
    digitalWrite(light5Pin, LOW);
    digitalWrite(light6Pin, LOW);
  }
  if (random_value == 5) {
    digitalWrite(light1Pin, LOW);
    digitalWrite(light2Pin, LOW);
    digitalWrite(light3Pin, LOW);
    digitalWrite(light4Pin, LOW);
    digitalWrite(light5Pin, HIGH);
    digitalWrite(light6Pin, LOW);
  }
  if (random_value == 6) {
    digitalWrite(light1Pin, LOW);
    digitalWrite(light2Pin, LOW);
    digitalWrite(light3Pin, LOW);
    digitalWrite(light4Pin, LOW);
    digitalWrite(light5Pin, LOW);
    digitalWrite(light6Pin, HIGH);
  }
}




void display_score() {
  if(Play_time>0)
  {
  display_data[0] = Play_time/10; 
  display_data[1] = Play_time%10;                                           // saperate value into most significant digit
  display_data[2] = Real_score/10;
  display_data[3] = Real_score%10; // saperate value into least significant digit
  }
  if(Play_time<1)
  {
  display_data[0] = Play_time/10; 
  display_data[1] = Play_time%10;                                           // saperate value into most significant digit
  display_data[2] = high_score/10;
  display_data[3] = high_score%10; // saperate value into least significant digit
  }
  
  
    if(( millis() - previous_display_refresh_time) >= DISPLAY_REFRESH_TIME)
    {
    digitalWrite(DIGIT0, HIGH);digitalWrite(DIGIT1,  HIGH); digitalWrite(DIGIT2,  HIGH);digitalWrite(DIGIT3,  HIGH);

    for(segment = 0; segment < 7; segment++)
    {
      digitalWrite(segment_display.segment_score[segment], segment_display.data[display_data[digit_count]][segment]);

    }

    if (digit_count > 3 )
    {
      digit_count = 0;
    }
     else 
    {
      if (digit_count == 0) { digitalWrite(DIGIT0,  LOW); digitalWrite(DIGIT1, HIGH); digitalWrite(DIGIT2, HIGH);digitalWrite(DIGIT3, HIGH); }
      if (digit_count == 1) { digitalWrite(DIGIT0, HIGH); digitalWrite(DIGIT1,  LOW); digitalWrite(DIGIT2, HIGH);digitalWrite(DIGIT3, HIGH);}
       if (digit_count == 2) { digitalWrite(DIGIT0,  HIGH); digitalWrite(DIGIT1, HIGH);digitalWrite(DIGIT2, LOW);digitalWrite(DIGIT3, HIGH); }
       if (digit_count == 3) { digitalWrite(DIGIT0,  HIGH); digitalWrite(DIGIT1, HIGH);digitalWrite(DIGIT2, HIGH);digitalWrite(DIGIT3, LOW); }
      
      digit_count++;
    }

    previous_display_refresh_time = millis();
    }
}

void Debounce() {
  if ((digitalRead(sw1) == 0) && (key_release1 == 1) && (debounce_process_status1 == 0))
  {
    first_keypress_time1 = millis();
    debounce_process_status1 = 1;
    key_release1 = 0 ;
  }
  else if (digitalRead(sw1) == 1) {
    key_release1 = true;
  }
  else if (((millis() - first_keypress_time1) > debounce_time1) && debounce_process_status1 == 1)
  {
    if ((digitalRead(sw1) == 0) && (key_release1 == 0))
    {

      button_status1 = 1;
    }

    debounce_process_status1 = 0 ;
  }



  /* 2nd switch pressed */
  if ((digitalRead(sw2) == 0) && (key_release2 == 1) && (debounce_process_status2 == 0))
  {
    first_keypress_time2 = millis();
    debounce_process_status2 = 1;
    key_release2 = 0 ;
  }
  else if (digitalRead(sw2) == 1) {
    key_release2 = true;
  }
  else if (((millis() - first_keypress_time2) > debounce_time2) && debounce_process_status2 == 1)
  {
    if ((digitalRead(sw2) == 0) && (key_release2 == 0))
    {
      // score();
      button_status2 = 1;
    }
    debounce_process_status2 = 0 ;
  }


  /* 3rd switch pressed */
  if ((digitalRead(sw3) == 0) && (key_release3 == 1) && (debounce_process_status3 == 0))
  {
    first_keypress_time3 = millis();
    debounce_process_status3 = 1;
    key_release3 = 0 ;
  }
  else if (digitalRead(sw3) == 1) {
    key_release3 = true;
  }
  else if (((millis() - first_keypress_time3) > debounce_time3) && debounce_process_status3 == 1)
  {
    if ((digitalRead(sw3) == 0) && (key_release3 == 0))
    {
      button_status3 = 1;
      //score();
    }
    debounce_process_status3 = 0 ;
  }

  /* 4th Switch pressed */

  if ((digitalRead(sw4) == 0) && (key_release4 == 1) && (debounce_process_status4 == 0))
  {
    first_keypress_time4 = millis();
    debounce_process_status4 = 1;
    key_release4 = 0 ;
  }
  else if (digitalRead(sw4) == 1) {
    key_release4 = true;
  }
  else if (((millis() - first_keypress_time4) > debounce_time4) && debounce_process_status4 == 1)
  {
    if ((digitalRead(sw4) == 0) && (key_release4 == 0))
    {
      button_status4 = 1;
      //count4++;
      //Serial.print("4.-->");
      //Serial.println(count4);
    }
    debounce_process_status4 = 0 ;
  }

  //5 th sw press
  if ((digitalRead(sw5) == 0) && (key_release5 == 1) && (debounce_process_status5 == 0))
  {
    first_keypress_time5 = millis();
    debounce_process_status5 = 1;
    key_release5 = 0 ;
  }
  else if (digitalRead(sw5) == 1) {
    key_release5 = true;
  }
  else if (((millis() - first_keypress_time5) > debounce_time5) && debounce_process_status5 == 1)
  {
    if ((digitalRead(sw5) == 0) && (key_release5 == 0))
    {

      button_status5 = 1;
    }

    debounce_process_status5 = 0 ;
  }

  //6 th sw press
  if ((digitalRead(sw6) == 0) && (key_release6 == 1) && (debounce_process_status6 == 0))
  {
    first_keypress_time6 = millis();
    debounce_process_status6 = 1;
    key_release6 = 0 ;
  }
  else if (digitalRead(sw6) == 1) {
    key_release6 = true;
  }
  else if (((millis() - first_keypress_time6) > debounce_time6) && debounce_process_status6 == 1)
  {
    if ((digitalRead(sw6) == 0) && (key_release6 == 0))
    {

      button_status6 = 1;
    }

    debounce_process_status6 = 0 ;
  }

  //7 th sw press
  if ((digitalRead(hammer) == 0) && (key_release7 == 1) && (debounce_process_status7 == 0))
  {
    first_keypress_time7 = millis();
    debounce_process_status7 = 1;
    key_release7 = 0 ;
  }
  else if (digitalRead(hammer) == 1) {
    key_release7 = true;
  }
  else if (((millis() - first_keypress_time7) > debounce_time7) && debounce_process_status7 == 1)
  {
    if ((digitalRead(hammer) == 0) && (key_release7 == 0))
    {

      button_status7 = 1;
    }

    debounce_process_status7 = 0 ;
  }

  //8 th sw press
  if ((digitalRead(Startbutton) == 0) && (key_release8 == 1) && (debounce_process_status8 == 0))
  {
    first_keypress_time8 = millis();
    debounce_process_status8 = 1;
    key_release8 = 0 ;
  }
  else if (digitalRead(Startbutton) == 1) {
    key_release8 = true;
  }
  else if (((millis() - first_keypress_time8) > debounce_time8) && debounce_process_status8 == 1)
  {
    if ((digitalRead(Startbutton) == 0) && (key_release8 == 0))
    {

      button_status8 = 1;

    }

    debounce_process_status8 = 0 ;
  }

  //9 th sw press
  if ((digitalRead(reset) == 0) && (key_release9 == 1) && (debounce_process_status9 == 0))
  {
    first_keypress_time9 = millis();
    debounce_process_status9 = 1;
    key_release9 = 0 ;
  }
  else if (digitalRead(reset) == 1) {
    key_release9 = true;
  }
  else if (((millis() - first_keypress_time9) > debounce_time9) && debounce_process_status9 == 1)
  {
    if ((digitalRead(reset) == 0) && (key_release9 == 0))
    {

      button_status9 = 1;
    }

    debounce_process_status9 = 0 ;
  }
}

void score_x() {



  //score of botton 1
  if (button_status7 == 1 && (digitalRead(23) == 1) && button_status1 == 1)
  {
    digitalWrite(23, LOW);
    if (Real_score <= 99)
    {
      Real_score++;
      button_status7 = 0;
      button_status1 = 0;
      if (servo_angle < 180)
      {
        servo_angle = servo_angle + 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(23) == 1) && button_status2 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status2 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(23) == 1) && button_status3 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status3 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(23) == 1) && button_status4 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status4 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(23) == 1) && button_status5 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status5 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(23) == 1) && button_status6 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status6 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }


  //score of botton 2
  if (button_status7 == 1 && (digitalRead(25) == 1) && button_status2 == 1)
  {
    digitalWrite(25, LOW);
    if (Real_score <= 99)
    {
      Real_score++;
      button_status7 = 0;
      button_status2 = 0;
      if (servo_angle < 180)
      {
        servo_angle = servo_angle + 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(25) == 1) && button_status1 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status1 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(25) == 1) && button_status3 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status3 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(25) == 1) && button_status4 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status4 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(25) == 1) && button_status5 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status5 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(25) == 1) && button_status6 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status6 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }


  //score of botton 3
  if (button_status7 == 1 && (digitalRead(27) == 1) && button_status3 == 1)
  {
    digitalWrite(27, LOW);
    if (Real_score <= 99)
    {
      Real_score++;
      button_status7 = 0;
      button_status3 = 0;
      if (servo_angle < 180)
      {
        servo_angle = servo_angle + 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(27) == 1) && button_status1 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status1 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(27) == 1) && button_status2 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status2 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(27) == 1) && button_status4 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status4 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(27) == 1) && button_status5 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status5 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(27) == 1) && button_status6 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status6 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }


  //score of botton 4
  if (button_status7 == 1 && (digitalRead(29) == 1) && button_status4 == 1)
  {
    digitalWrite(29, LOW);
    if (Real_score <= 99)
    {
      Real_score++;
      button_status7 = 0;
      button_status4 = 0;
      if (servo_angle < 180)
      {
        servo_angle = servo_angle + 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(29) == 1) && button_status1 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      servo_angle--;
      button_status7 = 0;
      button_status1 = 0;
      myservo.write(servo_angle);
    }
  }
  if (button_status7 == 1 && (digitalRead(29) == 1) && button_status2 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status2 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 4;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(29) == 1) && button_status3 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status3 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle + 4;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(29) == 1) && button_status5 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status5 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 4;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(29) == 1) && button_status6 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status6 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 4;
        myservo.write(servo_angle);
      }
    }
  }



  //score of botton 5
  if (button_status7 == 1 && (digitalRead(31) == 1) && button_status5 == 1) {

    digitalWrite(31, LOW);
    if (Real_score <= 99)
    {
      Real_score++;
      button_status7 = 0;
      button_status5 = 0;
      if (servo_angle < 180)
      {
        servo_angle = servo_angle + 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(31) == 1) && button_status1 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status1 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(31) == 1) && button_status2 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status2 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(31) == 1) && button_status3 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status3 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(31) == 1) && button_status4 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status4 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(31) == 1) && button_status6 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status6 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }



  //score of botton 6
  if (button_status7 == 1 && (digitalRead(33) == 1) && button_status6 == 1)
  {
    digitalWrite(33, 0);
    if (Real_score <= 99)
    {
      Real_score++;
      button_status7 = 0;
      button_status6 = 0;
      if (servo_angle < 180)
      {
        servo_angle = servo_angle + 10;
        myservo.write(servo_angle);
      }
    }

  }
  if (button_status7 == 1 && (digitalRead(31) == 1) && button_status1 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status1 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(31) == 1) && button_status2 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status2 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(31) == 1) && button_status3 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status3 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(31) == 1) && button_status4 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status4 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }
  if (button_status7 == 1 && (digitalRead(31) == 1) && button_status5 == 1)
  {
    if (Real_score > 0)
    {
      Real_score--;
      button_status7 = 0;
      button_status5 = 0;
      if (servo_angle > 0)
      {
        servo_angle = servo_angle - 10;
        myservo.write(servo_angle);
      }
    }
  }


}
void loop() {

  Debounce();
  score_x();
  display_score();
  myservo.write(servo_angle);
  if (mode == 0)
  {
    if (button_status8 == 1)
    {
      mode = 1;
      Play_time = 90;
      Real_score = 0;
      pre_time = millis();
      digitalWrite(light1Pin, HIGH);
      digitalWrite(light2Pin, HIGH);
      digitalWrite(light3Pin, HIGH);
      digitalWrite(light4Pin, HIGH);
      digitalWrite(light5Pin, HIGH);
      digitalWrite(light6Pin, HIGH);
      button_status8 = 0;
    }
  }
  if (mode == 1)
  {
    if (millis() - pre_time >= 3000)
    {
      digitalWrite(light1Pin, LOW);
      digitalWrite(light2Pin, LOW);
      digitalWrite(light3Pin, LOW);
      digitalWrite(light4Pin, LOW);
      digitalWrite(light5Pin, LOW);
      digitalWrite(light6Pin, LOW);
    }
    if (millis() - pre_time >= 5000)
    {
      mode = 2;
      pre_time = millis();
    }
  }
  if (mode == 2)
  {
    if (millis() - pre_time >= 1000)
    {
      Play_time--;
      pre_time = millis();

    }
    if (Play_time < 91 && Play_time > 60)
    {
      //
      /*if (first_rand = 1)
        {
          first_rand = 0;
          random_value = random(1, 7);
          light_brigh();
          freq_rand=millis();

        }*/

      if (millis() - freq_rand >= 2000)
      {
        random_value = random(1, 7);
        freq_rand = millis();
        light_brigh();
        // score_x();
      }
    }
    if (Play_time < 61 && Play_time > 30)
    {
      //
      if (millis() - freq_rand >= 1000)
      {
        random_value = random(1, 7);
        freq_rand = millis();
        light_brigh();
        //score_x();
      }
    }
    if (Play_time < 31)
    {
      //
      if (millis() - freq_rand >= 500)
      {
        random_value = random(1, 7);
        freq_rand = millis();
        light_brigh();
        //score_x();
      }
    }
    if (Play_time < 1)
    {
      if (Real_score > high_score)
      {
        high_score = Real_score;
      }
      mode = 0;
      Play_time = 0;
      Real_score = 0;
      servo_angle=0;
      digitalWrite(light1Pin, LOW);
      digitalWrite(light2Pin, LOW);
      digitalWrite(light3Pin, LOW);
      digitalWrite(light4Pin, LOW);
      digitalWrite(light5Pin, LOW);
      digitalWrite(light6Pin, LOW);

    }
  }
  Serial.println(Play_time);



}
