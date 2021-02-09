
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
