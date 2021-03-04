
# include "iGraphics.h"
#include<stdio.h>
/*
function iDraw() is called again and again by the system.
*/
int input = 0, start = 0, shoot = 0;
char arr[];
int score = 0;
double gun_x[] = { 670, 690, 698, 662 };
double gun_y[] = { 0, 0, 180, 180 };
double en_x, en_y;
double bl_x[] = {0};
double bl_y[] = { 600, 600 };
double ammo_x=gun_x[3]+5, ammo_y=gun_y[3];
char str[20], index = 0;
void iDraw()
{
	//place your drawing codes here
	iClear();
	iSetColor(128, 128, 128);
	iFilledRectangle(0, 0, 1360, 750);
	iSetColor(0, 0, 0);
	if (input == 0)
	{
		iSetColor(255, 255, 255);
		iText(450, 570, "<Welcome To Bubble Shooter Game>", GLUT_BITMAP_HELVETICA_18);
		iText(480, 395, "  Enter Your name here:");
		iRectangle(480, 340, 250, 50);
		iText(490, 355, str);
	}
	else
	{
		//iFilledRectangle(0, 250, 50, 100);
		iSetColor(0, 0, 255);
		iText(5, 340, "Player Name:", GLUT_BITMAP_HELVETICA_10);
		iText(5, 320, str, GLUT_BITMAP_TIMES_ROMAN_24);
		//iText(5, 310, "%d");
		iSetColor(0, 255, 0);
		iFilledCircle(680, 0, 100);
		iSetColor(255, 0, 0);
		iFilledPolygon(gun_x, gun_y,4);//Gun
		iFilledCircle(680, 0, 50);
		if (start == 0)
		{
			iSetColor(255, 255, 255);
			iText(500, 500, "Press 's' button to start");
		}
		else
		{
			iSetColor(0, 255, 0);
			iFilledEllipse(bl_x[0],bl_y[0],50,15);
			if (shoot == 1)
			{
				iSetColor(255, 0, 0);
				iPoint(ammo_x, ammo_y, 5);
			}
		}
	}
}
/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}
/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	//place your codes here
		printf("%d %d\n", mx, my);
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void Input(char key)
{
	if (key != '\r')
	{
		if (input!=1)
		str[index] = key;
		index++;
	}
	else
	{
		input = 1;
		str[index] = NULL;
	}
}
void iKeyboard(unsigned char key)
{
	Input(key);
	if (key == 'q')
	{
		//do something with 'q'
	}
	if (key == 's')
		start = 1;
	if (key == ' ')
	{
		shoot = 1;
	}
}
void GunMove(char key)
{
	if (key == GLUT_KEY_LEFT)
	{
		if (gun_x[3] > 560)
		{
			if (gun_x[3] <= 670)
			{
				gun_x[2] -= 4.5;
				gun_y[2] -= 3;
				gun_x[3] -= 4.5;
				gun_y[3] -= 3;
			}
			else
			{
				gun_x[2] -= 4.5;
				gun_y[2] += 3;
				gun_x[3] -= 4.5;
				gun_y[3] += 3;
			}
		}
	}
	if (key == GLUT_KEY_RIGHT)
	{
		if (gun_x[2] < 800)
		{
			if (gun_x[3] <= 670)
			{
				gun_x[2] += 4.5;
				gun_y[2] += 3;
				gun_x[3] += 4.5;
				gun_y[3] += 3;
			}
			else
			{
				gun_x[2] += 4.5;
				gun_y[2] -= 3;
				gun_x[3] += 4.5;
				gun_y[3] -= 3;
			}
		}
	}
}
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (start == 1)
		GunMove(key);


	//place your codes for other keys here
}
void Balloons()
{
	if (start==1)
	bl_x[0] += 2;
}
void Shooting()
{
	if (shoot == 1)
	{
		double x = 680 - (gun_x[3] + 18);
		ammo_x += x;
		ammo_y += 2;
		if (ammo_y >= 700)
			shoot = 0;
	}
}
void main()
{
	//place your own initialization codes here.
	iSetTimer(50, Balloons);
	iSetTimer(10, Shooting);
	iInitialize(1360, 700, "Bubble Shooter");
}