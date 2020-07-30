#define DIGIT0  48
#define DIGIT1  49

#define DISPLAY_REFRESH_TIME  1
unsigned long previous_display_refresh_time = 0;
#define COUNT_DELAY_TIME  100
unsigned long previous_count_time = 0;

struct DISPLAY_7SEGMENT {
             // segment a  b  c  d  e  f  g dot
  byte  data[10][8] = {{ 1, 1, 1, 1, 1, 1, 0, 0 },  // '0'
                       { 0, 1, 1, 0, 0, 0, 0, 0 },  // '1'
                       { 1, 1, 0, 1, 1, 0, 1, 0 },  // '2'
                       { 1, 1, 1, 1, 0, 0, 1, 0 },  // '3'
                       { 0, 1, 1, 0, 0, 1, 1, 0 },  // '4'
                       { 1, 0, 1, 1, 0, 1, 1, 0 },  // '5'
                       { 1, 0, 1, 1, 1, 1, 1, 0 },  // '6'
                       { 1, 1, 1, 0, 0, 0, 0, 0 },  // '7'
                       { 1, 1, 1, 1, 1, 1, 1, 0 },  // '8'
                       { 1, 1, 1, 1, 0, 1, 1, 0 },  // '9'
                      };
  byte  segment[8] = { 35, 37, 39, 41, 43, 45, 47};
};

struct DISPLAY_7SEGMENT  segment_display;

int  count;
byte segment, digit_count = 0, display_data[2] = {0, 0}; 
void setup()
{ 
  for (count = 13; count > 3; count--) {  pinMode(count, OUTPUT);  }
  pinMode(DIGIT0, OUTPUT);
  digitalWrite(48, HIGH);
}

void display(int data){
  display_data[0] = data/10;                                           // saperate value into most significant digit
  display_data[1] = data%10;                                           // saperate value into least significant digit
  
  if(( millis() - previous_display_refresh_time) >= DISPLAY_REFRESH_TIME) 
  {
    digitalWrite(DIGIT0, HIGH); digitalWrite(DIGIT1,  HIGH);
    
    for(segment = 0; segment < 8; segment++) 
    {
      digitalWrite(segment_display.segment[segment], segment_display.data[display_data[digit_count]][segment]);
    }  
    
    if (digit_count > 2 ) 
    { 
      digit_count = 0; 
    } 
    else 
    {
      if (digit_count == 0) { digitalWrite(DIGIT0,  LOW); digitalWrite(DIGIT1, HIGH); }
      if (digit_count == 1) { digitalWrite(DIGIT0, HIGH); digitalWrite(DIGIT1,  LOW); }
      digit_count++;
    }
    previous_display_refresh_time = millis();
  }
}

void loop(){ 
  if(( millis() - previous_count_time) >= COUNT_DELAY_TIME) {
    (count < 99) ? (count++) : (count = 0);
    previous_count_time = millis();
  }
  display(count);
}




