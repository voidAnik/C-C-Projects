

#include "iGraphics.h"
//#include "GLAux.h"
#include<stdio.h>
/*
function iDraw() is called again and again by the system.
*/
int input = 0, start = 0, shoot = 0;
char arr[];
int score = 0;
int gun_x = 670, gun_y = 0;
int cl_p = 680;
double b_x = 0,b_y = 600;
double ammo_x = gun_x + 5, ammo_y = gun_y+100;
char str[20], index = 0;
void iDraw()
{
	//place your drawing codes here
	iClear();
	//iShowBMP2(0, 0,"images\\stars_space.bmp");
	iSetColor(128, 128, 128);
	iSetColor(0, 0, 0);
	if (input == 0)
	{
		iSetColor(255, 255, 255);
		iText(450, 570, "<Welcome To Space Shooter Game>", GLUT_BITMAP_HELVETICA_18);
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
		iFilledCircle(cl_p, 0, 100);
		iSetColor(255, 0, 0);
		iFilledRectangle(gun_x, gun_y, 10,100);//Gun
		iFilledCircle(cl_p, 0, 50);
		if (start == 0)
		{
			iSetColor(255, 255, 255);
			iText(500, 500, "Press 's' button to start");
		}
		else
		{
			iShowBMP(b_x, b_y, "images\\ufo.bmp");
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
		if (key != '\b')
		{
			if (input != 1)
			{
				str[index] = key;
				index++;
				str[index] = NULL;
			}
		}
		else
		{
			if (index!=0)
			index--;
			str[index] = NULL;
		}
	}
	else
	{
		input = 1;
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
		if (cl_p - 100 > 0)
		{
			cl_p -= 3;
			gun_x -= 3;
		}
	}
	if (key == GLUT_KEY_RIGHT)
	{
		if (cl_p + 100 < 1360)
		{
			cl_p += 3;
			gun_x += 3;
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
void Boss()
{
	if (start == 1)
		b_x += 2;
}
void Shooting()
{
	if (shoot == 1)
	{
		//double x = 680 - (gun_x[3] + 18);
		ammo_y += 2;
		if (ammo_y >= 700)
			shoot = 0;
	}
}
void main()
{
	//place your own initialization codes here.
	iSetTimer(50, Boss);
	iSetTimer(10, Shooting);
	iInitialize(1360, 700, "Bubble Shooter");
}