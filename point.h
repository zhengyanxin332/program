#pragma once
#include<Windows.h>
#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <mmsystem.h>
#pragma comment(lib,"WinMM.Lib")
#define random(x) rand()%(x)
using namespace std;
int survive=1;//是否存活
int BX=0,BY=0;//接随机事物的坐标
int score=0;//分数
int speed=200;//当前速度
int  GK=1;//当前关卡
int N=7;//当n对5求余数等于零时，就过关，然后速度减少20ms
class point
{
public:
	point(int _x=0,int _y=0,char _c='*');
	~point(void);
	void show();
	void erase();
	static void gotoxy(int x,int y);
	void JM();
public:
	int px,py;
	char pc;
	const static int KLEFT = 8;//左上顶点到左界限的距离
	const static int KUP = 4;//左上顶点到上界限的距离
	const static int KWIDTH = 70;//界面的宽
	const static int KHEIGHT = 20;//界面的高
};

class food:public point
{
public:
	food();
	void randomfood(int *px,int *py);

};
/*typedef enum{
	UP,DOWN,LEFT,RIGHT
}Directions;*/
struct snode{
	int sx;
	int sy;
	struct snode *next;
	struct snode *front;

};
void createsnake(snode *head,int headx,int heady,int length ,char schar );
	static void Gotoxy(int x,int y);
void move(snode *head,int headx,int heady,int length,char schar);
void moveleft(snode *head,int headx,int heady,int length,char schar);
void moveright(snode *head,int headx,int heady,int length,char schar);
void moveup(snode *head,int headx,int heady,int length,char schar);
void movedown(snode *head,int headx,int heady,int length,char schar);
void movesnake(snode *head,int headx,int heady,int length,char schar);



class Snake
{
public:


	Snake(int x=40,int y=10,int length=5,int speed=500,char c='O');
	virtual ~Snake(void);
	void changeDirection();
	void move(Snake S);
	bool eatFood();
	void showSnake(Snake S);
	void eraseSnake();
	void growup();
	static void gotoxy(int x,int y);

public:
	int s_length;//蛇身长度
	int s_headx;//蛇头横坐标
	int s_heady;//蛇头纵坐标
	int s_speed;//蛇的移动速度
	char s_char;//蛇的蛇身符号
	//Directions m_enumCurrentDirection;
	
	int  *px,*py;//指向头结点的指针
	//int *pxx,*pyy;
	//int LS,ls;
	 snode S;
	 int fx,fy;
};


void welcomeinterface();
void endinterface();
void controldirection(Snake snake);
void startmove(Snake snake);
void bumpwall(snode *head,food B);
void eatself(snode *head,int length ); 
void ifsurvive();
void rightfood(snode *head,int length,food b);
void JMadd();
void eatfood(snode *head, int *length,food B);
void startgame(Snake snake,food B);
