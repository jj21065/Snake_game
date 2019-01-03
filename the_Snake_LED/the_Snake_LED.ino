// SNAKE.cpp : 定義主控台應用程式的進入點。
#include "math.h";
#include <MaxMatrix.h>
#include <avr /pgmspace.h>
 
// 在程式記憶體區（快閃記憶體）儲存點矩陣字元資料
PROGMEM unsigned char CH[] = {
3, 8, B0000000, B0000000, B0000000, B0000000, B0000000, // space
1, 8, B1011111, B0000000, B0000000, B0000000, B0000000, // !
3, 8, B0000011, B0000000, B0000011, B0000000, B0000000, // "
5, 8, B0010100, B0111110, B0010100, B0111110, B0010100, // #
4, 8, B0100100, B1101010, B0101011, B0010010, B0000000, // $
5, 8, B1100011, B0010011, B0001000, B1100100, B1100011, // %
5, 8, B0110110, B1001001, B1010110, B0100000, B1010000, // &
1, 8, B0000011, B0000000, B0000000, B0000000, B0000000, // '
3, 8, B0011100, B0100010, B1000001, B0000000, B0000000, // (
3, 8, B1000001, B0100010, B0011100, B0000000, B0000000, // )
5, 8, B0101000, B0011000, B0001110, B0011000, B0101000, // *
5, 8, B0001000, B0001000, B0111110, B0001000, B0001000, // +
2, 8, B10110000, B1110000, B0000000, B0000000, B0000000, // ,
4, 8, B0001000, B0001000, B0001000, B0001000, B0000000, // -
2, 8, B1100000, B1100000, B0000000, B0000000, B0000000, // .
4, 8, B1100000, B0011000, B0000110, B0000001, B0000000, // /
4, 8, B0111110, B1000001, B1000001, B0111110, B0000000, // 0
3, 8, B1000010, B1111111, B1000000, B0000000, B0000000, // 1
4, 8, B1100010, B1010001, B1001001, B1000110, B0000000, // 2
4, 8, B0100010, B1000001, B1001001, B0110110, B0000000, // 3
4, 8, B0011000, B0010100, B0010010, B1111111, B0000000, // 4
4, 8, B0100111, B1000101, B1000101, B0111001, B0000000, // 5
4, 8, B0111110, B1001001, B1001001, B0110000, B0000000, // 6
4, 8, B1100001, B0010001, B0001001, B0000111, B0000000, // 7
4, 8, B0110110, B1001001, B1001001, B0110110, B0000000, // 8
4, 8, B0000110, B1001001, B1001001, B0111110, B0000000, // 9
2, 8, B01010000, B0000000, B0000000, B0000000, B0000000, // :
2, 8, B10000000, B01010000, B0000000, B0000000, B0000000, // ;
3, 8, B0010000, B0101000, B1000100, B0000000, B0000000, // <
3, 8, B0010100, B0010100, B0010100, B0000000, B0000000, // =
3, 8, B1000100, B0101000, B0010000, B0000000, B0000000, // >
4, 8, B0000010, B1011001, B0001001, B0000110, B0000000, // ?
5, 8, B0111110, B1001001, B1010101, B1011101, B0001110, // @
4, 8, B1111110, B0010001, B0010001, B1111110, B0000000, // A
4, 8, B1111111, B1001001, B1001001, B0110110, B0000000, // B
4, 8, B0111110, B1000001, B1000001, B0100010, B0000000, // C
4, 8, B1111111, B1000001, B1000001, B0111110, B0000000, // D
4, 8, B1111111, B1001001, B1001001, B1000001, B0000000, // E
4, 8, B1111111, B0001001, B0001001, B0000001, B0000000, // F
4, 8, B0111110, B1000001, B1001001, B1111010, B0000000, // G
4, 8, B1111111, B0001000, B0001000, B1111111, B0000000, // H
3, 8, B1000001, B1111111, B1000001, B0000000, B0000000, // I
4, 8, B0110000, B1000000, B1000001, B0111111, B0000000, // J
4, 8, B1111111, B0001000, B0010100, B1100011, B0000000, // K
4, 8, B1111111, B1000000, B1000000, B1000000, B0000000, // L
5, 8, B1111111, B0000010, B0001100, B0000010, B1111111, // M
5, 8, B1111111, B0000100, B0001000, B0010000, B1111111, // N
4, 8, B0111110, B1000001, B1000001, B0111110, B0000000, // O
4, 8, B1111111, B0001001, B0001001, B0000110, B0000000, // P
4, 8, B0111110, B1000001, B1000001, B10111110, B0000000, // Q
4, 8, B1111111, B0001001, B0001001, B1110110, B0000000, // R
4, 8, B1000110, B1001001, B1001001, B0110010, B0000000, // S
5, 8, B0000001, B0000001, B1111111, B0000001, B0000001, // T
4, 8, B0111111, B1000000, B1000000, B0111111, B0000000, // U
5, 8, B0001111, B0110000, B1000000, B0110000, B0001111, // V
5, 8, B0111111, B1000000, B0111000, B1000000, B0111111, // W
5, 8, B1100011, B0010100, B0001000, B0010100, B1100011, // X
5, 8, B0000111, B0001000, B1110000, B0001000, B0000111, // Y
4, 8, B1100001, B1010001, B1001001, B1000111, B0000000, // Z
2, 8, B1111111, B1000001, B0000000, B0000000, B0000000, // [
4, 8, B0000001, B0000110, B0011000, B1100000, B0000000, // backslash
2, 8, B1000001, B1111111, B0000000, B0000000, B0000000, // ]
3, 8, B0000010, B0000001, B0000010, B0000000, B0000000, // hat
4, 8, B1000000, B1000000, B1000000, B1000000, B0000000, // _
2, 8, B0000001, B0000010, B0000000, B0000000, B0000000, // `
4, 8, B0100000, B1010100, B1010100, B1111000, B0000000, // a
4, 8, B1111111, B1000100, B1000100, B0111000, B0000000, // b
4, 8, B0111000, B1000100, B1000100, B0101000, B0000000, // c
4, 8, B0111000, B1000100, B1000100, B1111111, B0000000, // d
4, 8, B0111000, B1010100, B1010100, B0011000, B0000000, // e
3, 8, B0000100, B1111110, B0000101, B0000000, B0000000, // f
4, 8, B10011000, B10100100, B10100100, B01111000, B0000000, // g
4, 8, B1111111, B0000100, B0000100, B1111000, B0000000, // h
3, 8, B1000100, B1111101, B1000000, B0000000, B0000000, // i
4, 8, B1000000, B10000000, B10000100, B1111101, B0000000, // j
4, 8, B1111111, B0010000, B0101000, B1000100, B0000000, // k
3, 8, B1000001, B1111111, B1000000, B0000000, B0000000, // l
5, 8, B1111100, B0000100, B1111100, B0000100, B1111000, // m
4, 8, B1111100, B0000100, B0000100, B1111000, B0000000, // n
4, 8, B0111000, B1000100, B1000100, B0111000, B0000000, // o
4, 8, B11111100, B0100100, B0100100, B0011000, B0000000, // p
4, 8, B0011000, B0100100, B0100100, B11111100, B0000000, // q
4, 8, B1111100, B0001000, B0000100, B0000100, B0000000, // r
4, 8, B1001000, B1010100, B1010100, B0100100, B0000000, // s
3, 8, B0000100, B0111111, B1000100, B0000000, B0000000, // t
4, 8, B0111100, B1000000, B1000000, B1111100, B0000000, // u
5, 8, B0011100, B0100000, B1000000, B0100000, B0011100, // v
5, 8, B0111100, B1000000, B0111100, B1000000, B0111100, // w
5, 8, B1000100, B0101000, B0010000, B0101000, B1000100, // x
4, 8, B10011100, B10100000, B10100000, B1111100, B0000000, // y
3, 8, B1100100, B1010100, B1001100, B0000000, B0000000, // z
3, 8, B0001000, B0110110, B1000001, B0000000, B0000000, // {
1, 8, B1111111, B0000000, B0000000, B0000000, B0000000, // |
3, 8, B1000001, B0110110, B0001000, B0000000, B0000000, // }
4, 8, B0001000, B0000100, B0001000, B0000100, B0000000, // ~
};


#define MAX7219_DIN_PIN 11
#define MAX7219_LOAD_PIN 10
#define MAX7219_CLK_PIN 13
#define LED_INTENSITY 3
#define SIZE 8 
MaxMatrix m(MAX7219_DIN_PIN,MAX7219_LOAD_PIN,MAX7219_CLK_PIN, 1);
enum SnakeState {None,Food,Body};   //第n個玩家是Body1+n
void insertAtHead(const int x,const int y);
void removeAtTail();
void gotoxy(const int x,const int y);
int back(const int direct);
void createFood();
void Init();
 //LED matrix size 

struct DIRECTION{int up, down, left, right;}; //control direction
struct POSITION{int x, y;};  //for xy 
struct MAP{int state;struct MAP *pnext;}; //the map 
struct PLAYER{   //the snake info 
	POSITION HEAD;
	struct MAP *pHEAD,*pTAIL;
	int direction;
};

DIRECTION Direction;
PLAYER snake;
MAP Map[SIZE][SIZE];
POSITION FOOD;

int LED[SIZE*SIZE];
int speed = 200;
int b_up = A0;
int b_down = A1;
int b_left = A2;
int b_right = A3;
byte buffer[8];
char msg[] = "snake"; 
int init_flag = 0;
void setup() {
        
  pinMode(b_up,INPUT);       // set the control button 
  pinMode(b_down,INPUT);
  pinMode(b_left,INPUT);
  pinMode(b_right,INPUT);

	//init
  m.init();
  m.clear();
  m.setIntensity(LED_INTENSITY);
   
  
}

void loop()
{
 
 if(init_flag == 0)    // print the title
{
  for(int k = 0; k<3;k++)
  {
    printStringWithShift(msg, 200);
  }
  delay(100);
  Init();                // initiate the game 
  init_flag = 1;
} 
 
  int val_up = digitalRead(b_up);           
  int val_down = digitalRead(b_down);
  int val_left = digitalRead(b_left);
  int val_right = digitalRead(b_right);
	
  delay(speed);   //sleep to set the speed 
		
  int  key;
  if(val_up == HIGH)  
    key = b_up;
  else if(val_down == HIGH)
    key = b_down;
  else if(val_left == HIGH)
    key = b_left;
  else if(val_right == HIGH)
    key = b_right;

  if((key!=back(snake.direction))&&(key==Direction.up||key==Direction.down||key==Direction.left||key==Direction.right))
    snake.direction=key;  //no backward	

  if(snake.direction==Direction.up)   //up
    snake.HEAD.y = snake.HEAD.y==0 ? SIZE-1 : snake.HEAD.y-1;
  else if(snake.direction==Direction.down)  //down
    snake.HEAD.y = (snake.HEAD.y+1)%SIZE;
  else if(snake.direction==Direction.left)  //left
    snake.HEAD.x = snake.HEAD.x==0 ? SIZE-1 : snake.HEAD.x-1;
  else if(snake.direction==Direction.right) //right
    snake.HEAD.x = (snake.HEAD.x+1)%SIZE;
    
  if(Map[snake.HEAD.x][snake.HEAD.y].state==Body)
  {
    delay(500);
    for(int i=0;i<SIZE;i++)
    {
      for(int j=0;j<SIZE;j++)
      {
      m.setDot(j,i,HIGH);
      }
    delay(300);
    }
    Init();
    
  }
		

  if(Map[snake.HEAD.x][snake.HEAD.y].state<Body) //None | Food
   {
	insertAtHead(snake.HEAD.x,snake.HEAD.y);
  if(FOOD.x == snake.HEAD.x&&FOOD.y == snake.HEAD.y)
  {	
	createFood();
        speed-= 5;
  }
  else
    removeAtTail();
  }
  for(int i =0 ;i<SIZE;i++) ///print the whole map 
  {
    for(int j =0;j<SIZE;j++)
    {
      switch(Map[j][i].state)
      {
        case None:
         m.setDot(j,i,LOW);
        break;
	case Food:
	m.setDot(j,i,HIGH);
	break;
      case Body:
      if(j==snake.HEAD.x&&i==snake.HEAD.y){
	Serial.print("HA");
        m.setDot(j,i,HIGH);
      }
      else
       m.setDot(j,i,HIGH);
      break;
      }			
    }
  }

	
}
void insertAtHead(const int x,const int y)
{
	Map[x][y].state=Body;
	Map[x][y].pnext=NULL;
	snake.pHEAD->pnext=&Map[x][y];
	snake.pHEAD=snake.pHEAD->pnext;
}
void removeAtTail()
{
	struct MAP *tmp;
	tmp=snake.pTAIL->pnext;
	
	snake.pTAIL->state=None;
	snake.pTAIL->pnext=NULL;
	snake.pTAIL=tmp;

}
//void gotoxy(const int x,const int y)
//{
//	COORD point;
//	point.X=2*x;
//	point.Y=y;  //設游標
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
//}
void createFood()
{
  long randNumber; 
  randomSeed(analogRead(0)); 
	do
	{
		FOOD.x=random(300)%SIZE;
		FOOD.y=random(300)%SIZE;
	}while(Map[FOOD.x][FOOD.y].state!=None);
	Map[FOOD.x][FOOD.y].state=Food;
}
int back(const int direct)
{
	if(direct==Direction.up)
		return Direction.down;
	else if(direct==Direction.down)
		return Direction.up;
	else if(direct==Direction.left)
		return Direction.right;
	else if(direct==Direction.right)
		return Direction.left;
}
void Init(){
  m.init();
  m.clear();
  m.setIntensity(LED_INTENSITY);
  
 
  speed =200;
	//init
	Map[snake.HEAD.x][snake.HEAD.y].state=Body;
	//head
	snake.pHEAD=&Map[snake.HEAD.x][snake.HEAD.y];
	//HEad
	snake.pTAIL=&Map[snake.HEAD.x][snake.HEAD.y];
	//tail
	for(int i =0 ;i<SIZE;i++)
	{
		for(int j =0;j<SIZE;j++)
		{
			Map[i][j].state = None;
			Map[i][j].pnext=NULL;
		}
	}
	Direction.up=b_up;Direction.down=b_down;Direction.left=b_left;Direction.right=b_right;
	
	snake.HEAD.x = 5;snake.HEAD.y = 5;
	snake.direction = Direction.up;
	createFood();
 
}
void printStringWithShift(char* s, int shift_speed)
{
  while (*s != 0)
  {
    printCharWithShift(*s, shift_speed);
    s++;
  }
}
void printCharWithShift(char c, int shift_speed)
{
  // 以下註解請參閱下文說明
  if (c < 32) return;   // 不處理空白字元（ASCII值32）以前的字元
  c -= 32;			// 求出實際的對應點矩陣字元索引
  memcpy_P(buffer, CH + 7*c, 7);
  m.writeSprite(32, 0, buffer);    // 輸出存在buffer裡的點矩陣
  m.setColumn(32 + buffer[0], 0); // 輸出一個空行（亦即，字與字之間的空行）
  
  for (int i=0; i<buffer[0]+1; i++) 
  {
    delay(shift_speed);      // 延遲一段時間（位移速度）
    m.shiftLeft(false, false);
  }
}
