// Lab15 使用四位數七段顯示器當計數器 V2

// 定義七段顯示器各節段與 Arduino 的腳位對應關係
#define ASeg 5
#define BSeg 7
#define CSeg 4
#define DSeg 11
#define ESeg 10
#define FSeg 3
#define GSeg 6

// 定義共陽極與 Arduino 的腳位對應關係
#define CA1 13
#define CA2 12
#define CA3 9
#define CA4 8

// 定義七個節段的腳位&#65292;將 A, B, C, D, E, F, G 依序放入陣列
byte segs[7] = { ASeg, BSeg, CSeg, DSeg, ESeg, FSeg, GSeg };

// 定義共陽極七段顯示器的字型(digit pattern)
// define the LED digit patterns, from 0 - 9
// 0 = LED on, 1 = LED off, in this order:
//                Mapping to       a,b,c,d,e,f,g of Seven-Segment LED
byte seven_seg_digits[10][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                 { 1,1,0,1,1,0,1 },  // = 2
                                 { 0,1,1,0,0,1,1 },  // = 4
                                 { 1,0,1,1,1,1,1 },  // = 6
                                 { 1,1,1,1,1,1,1 },  // = 8
                                 { 1,1,1,0,0,1,1 }   // = 9
                                 { 1,1,1,0,0,0,0 },  // = 7
                                 { 1,0,1,1,0,1,1 },  // = 5
                                 { 1,1,1,1,0,0,1 },  // = 3 
                                 { 0,1,1,0,0,0,0 },  // = 1
                             }; 

// 定義每個七段顯示器顯示的時間 (延遲時間), 預設 1ms 
int delay_time = 1;
const int buttonPin = 2;
int buttonState = 0;
int number = 0;
                             
void setup() {
  pinMode(ASeg, OUTPUT);
  pinMode(BSeg, OUTPUT);
  pinMode(CSeg, OUTPUT);
  pinMode(DSeg, OUTPUT);
  pinMode(ESeg, OUTPUT);
  pinMode(FSeg, OUTPUT);
  pinMode(GSeg, OUTPUT);
  pinMode(CA1, OUTPUT);
  pinMode(CA2, OUTPUT);
  pinMode(CA3, OUTPUT);
  pinMode(CA4, OUTPUT);
  pinMode(buttonPin,INPUT);
}

