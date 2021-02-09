/*
byte lupTable[16] = {0x3F, 0x06, 0x5B, 0x4F,0x66, 0x6D, 0x7D, 0x07, 
0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};  

void setup()
{
DDRD = 0xff;   
DDRB = 0xff;    
DDRC = 0xff;   
}

void loop()
{

// show 2 in left 7SD
digitalWrite(A0, 0);
digitalWrite(A1, 1);
byte y = 0x5B; 
PORTB = y;     
bool n = bitRead(y, 6); 
digitalWrite(6, n);          
n = bitRead(y, 7);  
bitWrite(PORTD, 7, n); 

delay(10);

// show 5 in left 7SD
digitalWrite(A0, 1);
digitalWrite(A1, 0);
y = 0x6F;
PORTB = y;     

n = bitRead(y, 6); 
digitalWrite(6, n);          

n = bitRead(y, 7);  
bitWrite(PORTD, 7, n); 

delay(10);

}


//byte lupTable[16] = {0x3F, 0x06, 0x5B,0x4F,0x66, 0x6D,0x7D,0x07, 
//0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};





/*
byte ccCode[2] = { 0x5B, 0x6F};
void setup()
{
DDRD = 0xff;   
DDRB = 0xff;    
DDRC = 0xff;  
  
}

void loop()
{

for (byte i=0; i<3; i++)
{
  byte x = 0b11111111;
  bitClear(x,i);
  PORTC = x;

byte y = ccCode[i]; 

PORTB = y;     

bool n = bitRead(y, 6); 
digitalWrite(6, n);          

n = bitRead(y, 7);  
bitWrite(PORTD, 7, n);  

delay(1000);
}
}


/*
byte lupTable[16] = {0x3F, 0x06, 0x5B, 0x4F,0x66, 0x6D,0x7D, 0x07, 
0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

byte x;
byte sum;
byte digit;

void setup()
{
DDRD = 0xff;   
DDRB = 0xff;    
DDRC = 0xff; 
byte y1 = 0x23;
byte y2 = 0x06;
sum = y1+y2;  
}

void loop()
{
digitalWrite(A0, 0);
digitalWrite(A1, 1);
byte digitDP0 = sum>>4;
byte y = lupTable[digitDP0]; 
PORTB = y;     

bool n = bitRead(y, 6); 
digitalWrite(6, n);          

n = bitRead(y, 7);  
bitWrite(PORTD, 7, n); 
digitalWrite(7, n); 

delay(10);
  
digitalWrite(A0, 1);
digitalWrite(A1, 0);
byte digitDP1 = sum&0x0f;
y = lupTable[digitDP1]; 
PORTB = y;     

n = bitRead(y, 6); 
digitalWrite(6, n);          

n = bitRead(y, 7);  
bitWrite(PORTD, 7, n); 

delay(10);
}




byte lupTable[16] = {0x3F, 0x06, 0x5B, 0x4F,0x66, 0x6D,0x7D,0x07, 
0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

byte x;
byte sum;
byte digit;

void setup()
{
DDRD = 0xff;   
DDRB = 0xff;    
DDRC = 0xff; 
byte y1 = 0x27;
byte y2 = 0x02;
sum = y1+y2;  
}

void loop()
{
for (byte i=0; i<2; i++)
{
  x = 0b11111111;
  bitClear(x,1-i);
  PORTC = x;
digit = sum>>4*i;
digit = digit & 0x0f;
byte y = lupTable[digit]; 

PORTB = y;     

bool n = bitRead(y, 6); 
digitalWrite(6, n);          

n = bitRead(y, 7);  
bitWrite(PORTD, 7, n); 
digitalWrite(7, n); 

delay(10);
}
}

void setup()
{
for (int i = 6; i<= 15; i++)
{
pinMode(i, OUTPUT); //DPins: 7-6, 13-8, A1-A0 work as output lines
}
}
void loop()
{
byte y = 0x5B; //cc-code of 2; y7 y6 y5 y4 y3 y2 y1 y0 = 0 1 0 1 1 0 1 1
PORTB = y; //PORTB accepts lower 6-bit and puts on DPins:13-8
bool m = bitRead(y, 6); //y6 = 1 is in variable m
digitalWrite(6, m); //m = y6 = 1 goes on DPin-6
digitalWrite(7, bitRead(y, 7)); //y7 is put on DPin-7; nested instruction
//------------------------------------------------------------------------------
digitalWrite(A0, LOW); //DP0 is ON; 2 appears on DP0 position
digitalWrite(A1, HIGH); //DP1 is OFF ; nothing appears on DP1 position
delay(5); //10 ms wait for a while so that eye/brain can remember 2
//----------------------------------------------------------------------------
byte z = 0x6D; //cc-code of 5
PORTB = z;
bool n = bitRead(z, 6);
digitalWrite(6, n);
digitalWrite(7, bitRead(z, 7));
//---------------------------------------
digitalWrite(A0, HIGH); //DP0 is OFF; noting appears on DP0 position
digitalWrite(A1, LOW); //DP1 is ON; 5 appears on DP1 position
delay(5);
}

byte ccCode[2] = {0x5B, 0x6F};
void setup()
{
  for (int i = 6; i < 16; i++)
  {
    pinMode(i, OUTPUT);  //DPins: 7-6, 13-8, A1-A0 work as output
  }
}

void loop()
{
  for (int i = 0; i < 2; i++)
  {
    byte x = 0b11111111;   //0b means base 2 (binary); to activate cc-pin of display devices
    bitClear(x, i);         //x = 0b11111110; Bit-0 will be sent at DPin-A0 of display to see 2
    //------------------------------------------------------------
    byte y = ccCode[i];         //cc-code of 2 and then 5
    PORTB = y;              //PORTB accepts lower 6-bit and puts on DPins:13-8
    bool m = bitRead(y, 6);
    digitalWrite(6, m);             //y6 is put on DPin-6
    digitalWrite(7, bitRead(y, 7)); //y7 is put on DPin-7
    //-----------------------------------------------------------
    digitalWrite(A0, bitRead(x, 0));//DP0 is ON and then OFF in the  next pass
    digitalWrite(A1, bitRead(x, 1));//DP1 is ON and then OFF
  //------------------------------------------------------------
    delay(10); //time delay for the digit to remain ON for a while so that eye can remember it
  }
}
*/
void setup()
{
  for (int i = 6; i < 16; i++)
  {
    pinMode(i, OUTPUT);  //DPins: 7-6, 13-8, A1-A0 work as output
  }
}


void loop() {
  byte lt[10] = {0x06, 0x07, 0x3F, 0x5B, 0x3F, 0x6D, 0x06, 0x7F, 0x6D, 0x00};

  for (int j = 0; j < 10; j = j+2)
  {
    for (int p = 0; p <= 50; p++)
    {
      {
        for (int i = 0; i < 2; i++)
        {
          byte x = 0b11111111;   //0b means base 2 (binary); to activate cc-pin of display devices
          bitClear(x, i);         //x = 0b11111110; Bit-0 will be sent at DPin-A0 of display to see 2
          //------------------------------------------------------------
          byte y = lt[i + j];       //cc-code of 2 and then 5
          PORTB = y;              //PORTB accepts lower 6-bit and puts on DPins:13-8
          bool m = bitRead(y, 6);
          digitalWrite(6, m);             //y6 is put on DPin-6
          digitalWrite(7, bitRead(y, 7)); //y7 is put on DPin-7
          //-----------------------------------------------------------
          digitalWrite(A0, bitRead(x, 0));//DP0 is ON and then OFF in the  next pass
          digitalWrite(A1, bitRead(x, 1));//DP1 is ON and then OFF
          //------------------------------------------------------------
          delay(10); //time delay for the digit to remain ON for a while so that eye can remember it
        }
      }
   }
  }

}
