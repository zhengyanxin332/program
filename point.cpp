#include "point.h"


point::point(int _x,int _y,char _c)
{
	px=_x;
	py=_y;
	pc=_c;
}


point::~point(void)
{
}

void point::show()
{
	gotoxy(px,py);
	cout<<pc;
}
void point::erase()
{
	gotoxy(px,py);
	cout<<" ";
	gotoxy(78,24);
}

void point::gotoxy(int x, int y)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position 是一个 COORD 结构
	position.X = x; 
	position.Y = y;
	//将光标放在那里，然后开始打印
	SetConsoleCursorPosition(screen, position);
}
void Snake::gotoxy(int x, int y)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position 是一个 COORD 结构
	position.X = x; 
	position.Y = y;
	//将光标放在那里，然后开始打印
	SetConsoleCursorPosition(screen, position);
}

void Gotoxy(int x, int y)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position 是一个 COORD 结构
	position.X = x; 
	position.Y = y;
	//将光标放在那里，然后开始打印
	SetConsoleCursorPosition(screen, position);
}

void food::randomfood(int *px,int *py)
{
	srand((int)time(0));
	*px=random(KLEFT+KHEIGHT-2-(KLEFT+1)+1)+KLEFT+1;//(m,n)=random(n-m+1)+m
	*py=random(KUP+KHEIGHT-2-(KUP+3)+1)+KUP+3;
	BX=*px;
	BY=*py;
	gotoxy(*px,*py);
	cout<<pc;
}//使生成的随机食物出现在(8,6)->(77,23)且不出现在界面上
food::food()
{

}

void point::JM()
{
    gotoxy(KLEFT,KUP);
	for (int i=0;i<KWIDTH;i++)
	{
		cout<<"#";
	}
	gotoxy(KLEFT,KUP+1);
	cout<<"#";
	gotoxy(KLEFT+1,KUP+1);
	cout<<"    游戏名称：贪吃蛇"<<"\t"<<"编写者：燃犀"<<"\t";
	gotoxy(KLEFT+KWIDTH-1,KUP+1);
	cout<<"#";
	gotoxy(KLEFT+1,KUP+2);
	for (int i=0;i<KWIDTH-2;i++)
	{
		cout<<"#";
	}
	for (int i=KUP+2;i<KUP+KHEIGHT-1;i++)
	{
		gotoxy(KLEFT,i);
		cout<<"#";
		gotoxy(KLEFT+KWIDTH-1,i);
		cout<<"#";
	}
	gotoxy(KLEFT,KUP+KHEIGHT-1);
	for (int i=0;i<KWIDTH;i++)
	{
		cout<<"#";
	}
	//gotoxy(77,26);
	//cout<<"@";
}

void JMadd()
{
	Gotoxy(80,4);
	for (int i=0;i<15;i++)
	{
		cout<<"-";
	}
	Gotoxy(80,5);
	cout<<"  游戏数据";
	Gotoxy(81,6);
	for (int i=0;i<13;i++)
	{
		cout<<"-";
	}
	for (int i=0;i<18;i++)
	{
		Gotoxy(80,5+i);
		cout<<"|";
		Gotoxy(80+14,5+i);
		cout<<"|";
	}
	Gotoxy(80,23);
	for (int i=0;i<15;i++)
	{
		cout<<"-";
	}
	Gotoxy(81,8);
	if (N%6==0)
	{
		GK++;
		speed=speed-50;
		N=N+1;
	}
	cout<<"关卡："<<GK;
	Gotoxy(81,10);
	cout<<"速度："<<speed<<"ms";
	Gotoxy(81,12);
	cout<<"分数："<<score;
}
void welcomeinterface()
{
	HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
	Gotoxy(10,5);//
	for(int i=0;i<70;i++)
	{
		cout<<"#";
	}
	for(int i=6;i<25;i++)
	{
		Gotoxy(10,i);//
		cout<<"#";
		Gotoxy(79,i);
		cout<<"#";
	}
	Gotoxy(10,25);//
	for(int i=0;i<70;i++)
	{
		cout<<"#";
	}
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	Gotoxy(33,8);//
	cout<<"$ 欢迎来到贪吃蛇游戏 $"; 
	Gotoxy(15,10);//
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	cout<<"游戏操作：";
	Gotoxy(15,12);//
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
	cout<<"        使用上下左右建控制方向";
	Gotoxy(15,13);//
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	cout<<"游戏规则：";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
	Gotoxy(15,15);
	cout<<"       1,蛇撞墙死亡";
	Gotoxy(15,16);
	cout<<"       2,蛇自咬死亡";
	Gotoxy(15,17);
	cout<<"       3,吃一个食物获得10分";
	Gotoxy(15,18);
	cout<<"       4,获得50分通往下一关";
	Gotoxy(15,19);
	cout<<"       5,晋级一关速度就会将加快50ms"; 
	Gotoxy(15,22);
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	cout<<"        空格开始游戏                 ESC退出游戏 ";

	Gotoxy(100,30);
}
void endinterface()
{
	HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED);
	Gotoxy(10,5);
	cout<<"              游戏失败！" ;
	Gotoxy(10,10);
	for(int i=0;i<7;i++)
	{
		cout<<"#";
	}

	for(int i=11;i<20;i++)
	{
		Gotoxy(10,i);
		cout<<"#";
	}
	for(int i=0;i<3;i++)
	{
		Gotoxy(10+i,15);
		cout<<"#";
	}


	Gotoxy(25,10);
	for(int i=25,j=10;i>15;i--,j++)
	{
		Gotoxy(i,j);
		cout<<"#";
	}
	Gotoxy(25,10);
	for(int i=25,j=10;i<35;i++,j++)
	{
		Gotoxy(i,j);
		cout<<"#";
	}
	Gotoxy(21,15);
	for(int i=0;i<9;i++)
	{
		cout<<"#";	
	}

	for(int i=0;i<10;i++)
	{
		Gotoxy(42,10+i);
		cout<<"#";
	}
	Gotoxy(40,10);
	for(int i=0;i<5;i++)
	{
		cout<<"#";
	}
	Gotoxy(40,19);
	for(int i=0;i<5;i++)
	{
		cout<<"#";
	}
	Gotoxy(50,10);
	for(int i=0;i<10;i++)
	{
		Gotoxy(50,10+i);
		cout<<"#";

	}
	Gotoxy(50,19);
	for(int i=0;i<7;i++)
	{
		cout<<"#";
	}

	Gotoxy(50,20);
}

Snake::Snake(int x,int y,int length,int speed,char c)
{
	s_headx=x;
	s_heady=y;
	s_length=length;
	s_speed=speed;
	s_char=c;
}
Snake::~Snake()
{

}

void createsnake(snode *head,int headx,int heady,int length,char schar)
{
	head->next=NULL;
	head->front=NULL;
	snode *P,*T;
	//head->next=P;
	T=head;
	int i;
	for ( i=0;i<length-1;i++)
	{
		P=(snode*)malloc(sizeof(snode));
		P->next=NULL;
		P->front=T;
		T->next=P;
		P->sx=headx+i;
		P->sy=heady;
		Gotoxy(P->sx,P->sy);
		cout<<schar;
		T=P;
	}
	P=(snode*)malloc(sizeof(snode));
	P->next=NULL;
	P->front=T;
	T->next=P;
	P->sx=headx+i;
	P->sy=heady;
	Gotoxy(P->sx,P->sy);
	cout<<" ";
	T=P;

}
void moveleft(snode *head,int headx,int heady,int length,char schar)
{
	snode *P=NULL;
	P=head;
	for (int i=0;i<length;i++)
	{
		P=P->next;
	}
	for (int i=0;i<length-1;i++)
	{
		P->sx=P->front->sx;
		P->sy=P->front->sy;
		P=P->front;
	}
	P->sx=P->sx-1;

}

void movesnake(snode *head,int headx,int heady,int length,char schar)
{
	HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
	snode *P=NULL;
	P=head;
	P=P->next;
	for (int i=0;i<length-1;i++)
	{
		Gotoxy(P->sx,P->sy);
		cout<<schar;
		P=P->next;
	}
	Gotoxy(P->sx,P->sy);
	cout<<" ";
	//Gotoxy(78,24);
}

void moveright(snode *head,int headx,int heady,int length,char schar)
{
	snode *P=NULL;
	P=head;
	for (int i=0;i<length;i++)
	{
		P=P->next;
	}
	for (int i=0;i<length-1;i++)
	{
		P->sx=P->front->sx;
		P->sy=P->front->sy;
		P=P->front;
	}
	P->sx=P->sx+1;
	/*for (int i=0;i<length-1;i++)
	{
		Gotoxy(P->sx,P->sy);
		cout<<schar;
		P=P->next;
	}
	Gotoxy(P->sx,P->sy);
	cout<<" ";*/
	//Gotoxy(78,24);

}

void moveup(snode *head,int headx,int heady,int length,char schar)
{
	snode *P=NULL;
	P=head;
	for (int i=0;i<length;i++)
	{
		P=P->next;
	}
	for (int i=0;i<length-1;i++)
	{
		P->sx=P->front->sx;
		P->sy=P->front->sy;
		P=P->front;
	}
	P->sy=P->sy-1;
/*	for (int i=0;i<length-1;i++)
	{
		Gotoxy(P->sx,P->sy);
		cout<<schar;
		P=P->next;
	}
	Gotoxy(P->sx,P->sy);
	cout<<" ";*/
	//Gotoxy(78,24);
}

void movedown(snode *head,int headx,int heady,int length,char schar)
{
	snode *P=NULL;
	P=head;
	for (int i=0;i<length;i++)
	{
		P=P->next;
	}
	for (int i=0;i<length-1;i++)
	{
		P->sx=P->front->sx;
		P->sy=P->front->sy;
		P=P->front;
	}
	P->sy=P->sy+1;
/*	for (int i=0;i<length-1;i++)
	{
		Gotoxy(P->sx,P->sy);
		cout<<schar;
		P=P->next;
	}
	Gotoxy(P->sx,P->sy);
	cout<<" ";*/
	//Gotoxy(78,24);
}

//***********************************************************************************************************************//
void bumpwall(snode *head,food B)//判断蛇是否撞墙
{
	snode *P=head;
	P=P->next;
	if (P->sx==B.KLEFT||P->sx==B.KLEFT+B.KWIDTH-1||P->sy==B.KUP+2||P->sy==B.KUP+B.KHEIGHT-1)
	{
		survive=0;
	}
}
void rightfood(snode *head,int length,food b)
{
	snode *p;
	p=head;
	p=p->next;
	for (int i=0;i<length-1;i++)
	{
		if (p->sx==BX&&p->sy==BY)
		{
			b.randomfood(&b.px,&b.py);
		}
		p=p->next;
	}
}

void eatself(snode *head ,int length)
{
	snode *P=head;
	snode *T;
	P=P->next;
	T=P->next;
	for (int i=0;i<length-2;i++)
	{
		if (P->sx==T->sx&&P->sy==T->sy)
		{
			survive=0;
		}
		T=T->next;
	}
}

void startgame(Snake snake,food B)
{
	B.randomfood(&B.px,&B.py);
	rightfood(&snake.S,snake.s_length,B);

	char ch =72;
	while (1)
	{
		JMadd();
		if (_kbhit())
		{
			ch=_getch();
			if (ch==224)
			{
				ch=_getch();
			}
		}

		switch(ch)
		{
		case 72:
			moveup(&snake.S,snake.s_headx,snake.s_heady,snake.s_length,snake.s_char);break;
		case 75:
			moveleft(&snake.S,snake.s_headx,snake.s_heady,snake.s_length,snake.s_char);break;
		case 77:
			moveright(&snake.S,snake.s_headx,snake.s_heady,snake.s_length,snake.s_char);break;
		case 80:
			movedown(&snake.S,snake.s_headx,snake.s_heady,snake.s_length,snake.s_char);break;
		}
		bumpwall(&snake.S,B);
		eatself(&snake.S,snake.s_length);
		//ifsurvive();
		eatfood(&snake.S,&snake.s_length,B);
		Sleep(speed);
		movesnake(&snake.S,snake.s_headx,snake.s_heady,snake.s_length,snake.s_char);
		if(survive==0)
			break;
	}

}

void eatfood(snode *head, int *length,food B)
{
	snode *P=NULL;
	P=head;
	P=P->next;
	//snake.fx=B.px;
	//snake.fy=B.py;
	if (P->sx==BX&&P->sy==BY)
	{
		B.randomfood(&B.px,&B.py);
		score=score+10;
		N++;
		for (int i=0;i<*length-1;i++)
		{
			P=P->next;
		}
		snode *newnode=(snode*)malloc(sizeof(snode));
		newnode->sx=0;
		newnode->sy=0;
		newnode->next=NULL;
		newnode->front=P;
		P->next=newnode;
		if ((P->sx-P->front->sx==1)&&(P->sy==P->front->sy))
		{
			newnode->sx=P->sx+1;
			newnode->sy=P->sy;
			*length=*length+1;
		}
		if ((P->sx-P->front->sx==-1)&&(P->sy==P->front->sy))
		{
			newnode->sx=P->sx-1;
			newnode->sy=P->sy;
			*length=*length+1;
		}
		if ((P->sy-P->front->sy==1)&&(P->sx==P->front->sx))
		{
			newnode->sy=P->sy+1;
			newnode->sx=P->sx;
			*length=*length+1;
		}
		if ((P->sy-P->front->sy==-1)&&(P->sx==P->front->sx))
		{
			newnode->sy=P->sy-1;
			newnode->sx=P->sx;
			*length=*length+1;
		}
				

	}

}
int main()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态



	welcomeinterface();
	PlaySound(TEXT("H:\\BGM.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
	char c;
	c=_getch();
//welcomeinterface();
if (c==27)
{
		 system("CLS") ;
		 endinterface();
		 system("pause");
}
if (c==32)
{
	system("CLS") ;
	food B;
	B.JM();
	JMadd();
	B.randomfood(&B.px,&B.py);
	//B.show();
	Snake snake;
	createsnake(&snake.S,snake.s_headx,snake.s_heady,snake.s_length,snake.s_char);
	startgame(snake,B);//开始游戏
	system("CLS") ;
	PlaySound(NULL, NULL, SND_PURGE) ;//关闭声音
	//PlaySound(TEXT("H:\\BGM.wav"),NULL,NULL);
	endinterface();
	system("pause");
}
	


	//endinterface();
/*	food B;
	B.JM();
	JMadd();
	B.randomfood(&B.px,&B.py);
	//B.show();
	Snake snake;
	createsnake(&snake.S,snake.s_headx,snake.s_heady,snake.s_length,snake.s_char);
	startgame(snake,B);//开始游戏
	 system("CLS") ;
	cout<<"游戏结束"<<endl;*/
	//system("pause");



	return 0;
}