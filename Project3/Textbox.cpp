
#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>

using namespace std;

#define ESC 27
#define ENTER 13
#define RIGHT 77
#define LEFT 75
#define HOME 71
#define END 79
#define INSERT 82
#define DEL 83
#define BKSP 8
#define TXW 8
#define TXH 8

/*   To Check the status of Insert       1 if ON       0 if OFF*/int ins_state()
{
	unsigned char far *stat = (char far*)0x417;
	char status;
	status = *stat;
	if ((status & 128) == 128)
		return 1;
	else return 0;
}

class TextField
{
private:
	char str[21];
	int startx, starty, size;
	void draw(char *strin);
public:
	TextField(int x1, int y1, int s, char *str1)
	{
		startx = x1 + 2;
		starty = y1 + 2;
		strcpy(str, str1);
		size = s;
	}
	TextField(int x1, int y1, int s)
	{
		strcpy(str, "");
		startx = x1 + 2;
		starty = y1 + 2;
		size = s;
	}
	void setText(char *str1);
	void draw();
	char *getText();
	void hide();
	void cursor(int x, int y, int ins, char ch);
};

void TextField::hide()
{
	setcolor(getbkcolor());
	setfillstyle(SOLID_FILL, getbkcolor());
	bar(startx - 3, starty - 3, startx + size*TXW + 9, starty + TXH + 3);
}

void TextField::setText(char *str1)
{
	strcpy(str, str1);
}

void TextField::draw()
{
	setcolor(RED);
	setfillstyle(SOLID_FILL, WHITE);
	bar(startx - 2, starty - 2, startx + size*TXW + 8, starty + TXH + 2);
	outtextxy(startx, starty, str);
}

void TextField::cursor(int x, int y, int ins, char ch)
{
	y += 2;
	flushall();
	char str[2];
	str[0] = ch;
	str[1] = '\0';
	while (!kbhit())
	{
		setcolor(RED);
		if (ins)
			outtextxy(x, y, "Ü");
		else
			outtextxy(x, y, "_");
		delay(500);
		setcolor(WHITE);
		if (ins)
			outtextxy(x, y, "Ü");
		else
			outtextxy(x, y, "_");
		setcolor(RED);
		if (ch != 0)
			outtextxy(x, y - 2, str);
		delay(500);
	}
	setcolor(WHITE);
	if (ins)
		outtextxy(x, y, "Ü");
	else
		outtextxy(x, y, "_");
	setcolor(RED);
	if (ch != 0)
		outtextxy(x, y - 2, str);
}
char* TextField::getText()
{
	draw();
	int cur_x, xend, ins, len;
	char cur_ch, ch;
	int stx;
	cur_x = xend = textwidth(str);
	ins = ins_state();
	cur_ch = str[cur_x / TXW];
	cursor(cur_x + startx, starty, ins, cur_ch);
	ch = getch();
	setcolor(RED);
	while (ch != ENTER)
	{
		if ((ch != 0) && ((isalnum(ch)) || (ch == '.') || (ch == ' ')))
		{
			ins = ins_state();
			if (!ins)
			{
				if (cur_x == xend)
				{
					if (xend / TXW<size)
					{
						strncat(str, &ch, 1);
						xend += TXW;
						cur_x += TXW;
					}
				}
				else
				{
					str[cur_x / TXW] = ch;
					cur_x += TXW;
				}
			}
			else if(xend / TXW<size)
			{
				len = strlen(str);
				if (cur_x == xend)
					strncat(str, &ch, 1);
				else
				{
					str[len + 1] = '\0';
					for (int i = len; i >= cur_x / TXW; i--)
						str[i] = str[i - 1];
					str[cur_x / TXW] = ch;
				}
				xend += TXW;
			}
		}
		else if(ch == ESC)
		{
			setText("");
			cur_x = xend = 0;
		}
		else if((ch == BKSP) && (cur_x>0))
		{
			len = strlen(str);
			for (int i = (cur_x - 1) / TXW; i<len; i++)
				str[i] = str[i + 1];
			str[len] = '\0';
			xend -= TXW;
			cur_x -= TXW;
		}
		else if(ch == 0)
		{
			ch = getch();
			if ((ch == LEFT) && (cur_x>0))
				cur_x -= TXW;
			else if((ch == RIGHT) && (cur_x<xend))
				cur_x += TXW;
			else if(ch == HOME)
				cur_x = 0;
			else if(ch == END)
				cur_x = xend;
			else if((ch == DEL) && (cur_x<xend))
			{
				len = strlen(str);
				for (int i = (cur_x + 1) / TXW; i<len; i++)
					str[i] = str[i + 1];
				str[len] = '\0';
				xend -= TXW;
			}
			ins = ins_state();
		}
		if (cur_x == xend)
			cur_ch = 0;
		else
			cur_ch = str[cur_x / TXW];
		draw();
		stx = startx;
		cursor(cur_x + stx, starty, ins, cur_ch);
		ch = getch();
	}
	return str;
}

//Example
void main()
{
	int gd = DETECT, gm = 0;
	initgraph(&gd, &gm, "");
	char *st = "Hello";
	TextField t1(100, 100, 10, st);
	t1.draw();
	char *str = t1.getText();
	closegraph();
	cout << str;
	getch();
}