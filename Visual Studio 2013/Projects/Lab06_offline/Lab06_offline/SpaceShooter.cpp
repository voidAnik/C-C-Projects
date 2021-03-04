


#include "iGraphics.h"
#include<stdio.h>

int input = 0, start = 0, shoot = 0, move = 0, attack = 0, blast = 0, over = 1;
char scoreText[10], ammoCheck[10];
int score = 0, ammo = 10;

int ammoList_x[10] = { 0 };
int ammoList_y[10] = { 240,220,200,180,160,140,120,100,80,60 };

int gun_x = 670, gun_y = 0;
int cl_p = 680;
double ammo_x = cl_p, ammo_y = 200;

int b_x = 0, b_y = 600;
int bs_x = b_x + 75, bs_y = b_y+20;
int eyes_p1 = b_x+30, eyes_p2 = b_x+120 ;
int horn_x = b_x + 65;
int mouth_x = b_x + 75;

char str[20], index = 0;
void iDraw()  
{
	iClear();
	iShowBMP(0, 0,"images\\stars_space.bmp");
	iSetColor(128, 128, 128);
	iSetColor(0, 0, 0);
	if (input == 0)
	{
		iSetColor(255, 255, 255);
		iText(450, 570, "<Welcome To Space Shooter Game>", GLUT_BITMAP_HELVETICA_18);
		iText(480, 395, "  Enter Your name here:");
		iRectangle(480, 340, 250, 50);
		iText(490, 355, str,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else
	{
		//iFilledRectangle(0, 250, 50, 100);
		iSetColor(0, 255, 0);
		iText(5, 340, "Player Name:", GLUT_BITMAP_HELVETICA_10);
		iText(5, 320, str, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(5, 300, "Score:");
		_itoa_s(score, scoreText, 10);
		iText(5, 280, scoreText);
		iText(5, 260, "Ammo:");
		_itoa_s(ammo, ammoCheck, 10);
		iText(45, 260, ammoCheck);
		for (int i = 0; i < ammo; i++)//Ammo list
		{
			iFilledRectangle(ammoList_x[i], ammoList_y[i], 10, 10);
		}
		iSetColor(0, 255, 0);
		iFilledCircle(cl_p, 0, 100);
		iSetColor(0, 0, 255);
		iFilledRectangle(gun_x, gun_y, 20, 150);//Gun
		iFilledCircle(cl_p, 0, 50);
		if (over == 0)
		{
			iPauseTimer;
			iSetColor(255, 255, 255);
			iText(500, 500, "Game Over!!", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(500, 460, "Player name:", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(650, 460, str, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(500, 430, "You Have Scored:", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(690, 430, scoreText, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(500, 400, "Press 'End' to exit the game!", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (start == 0)
		{
			iSetColor(255, 255, 255);
			iText(300, 600, "Instructions:Press 'Left arrow' & 'Right arrow' to control gun.Press 'Space' to shoot.");
			iText(300, 580, "You have 10 ammo.you can see it in left bottom corner.If ufo can shoot you or your ammo is over..It's ( GAME OVER :-( )");
			iText(500, 500, "Press 's' button to start", GLUT_BITMAP_TIMES_ROMAN_24);
		}
		
		else
		{
			if (over == 1)
			{
				if (attack == 0)
				{
					iSetColor(255, 0, 0);
					iFilledCircle(bs_x, bs_y, 10);
					iFilledRectangle(b_x, b_y, 150, 70);//Boss
					iSetColor(255, 255, 255);
					iFilledCircle(eyes_p1, 650, 10);
					iFilledCircle(eyes_p2, 650, 10);
					iFilledEllipse(mouth_x, 620, 30, 5);
					iSetColor(0, 0, 0);
					iFilledCircle(eyes_p1, 650, 5);
					iFilledCircle(eyes_p2, 650, 5);
					iFilledRectangle(horn_x, 660, 20, 700);
				}
				if (attack == 1)
				{
					iSetColor(0, 0, 255);
					iFilledRectangle(b_x, b_y, 150, 70);//Boss
					iFilledCircle(bs_x, bs_y, 30);
					attack = 0;
				}
				if (shoot == 1)
				{
					iSetColor(0, 255, 0);
					iPoint(ammo_x, ammo_y, 5);//Ammo
				}
			}
		}
	}
}

void iMouseMove(int mx, int my)
{
}
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//printf("%d %d\n", mx, my);
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

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
			if (index != 0)
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
	if (key == 'p')
	{
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
	}
	if (key == 'r')
	{
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);
	}
	if (key == 's')
	{
		start = 1;
		shoot = 0;
		ammo = 10;
	}
	if (key == ' ')
	{
		if (blast == 0)
		{
			ammo_x = cl_p;
			shoot = 1;
			ammo -= 1;
		}
	}
}
void GunMove(char key)
{
	if (key == GLUT_KEY_LEFT)
	{
		if (cl_p - 100 > 0)
		{
			cl_p -= 6;
			gun_x -= 6;
		}
	}
	if (key == GLUT_KEY_RIGHT)
	{
		if (cl_p + 100 < 1360)
		{
			cl_p += 6;
			gun_x += 6;
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
	{
		if (move == 0)
		{
			b_x += 5;
			eyes_p1 += 5;
			eyes_p2 += 5;
			mouth_x += 5;
			horn_x += 5;
			if (b_x+150 >= 1360)
				move = 1;
		}
		else
		{
			b_x -= 5;
			eyes_p1 -= 5;
			eyes_p2 -= 5;
			mouth_x -= 5;
			horn_x -= 5;
			if (b_x <= 0)
				move = 0;
		}
	}
}
void BossShooting()
{
	bs_y -= 10;
	if (bs_y <= 0 || (bs_y <= 100 && bs_y > 0 && bs_x >= cl_p-105 && bs_x <= cl_p + 105))
	{
		if (bs_y > 0)
		{
			over = 0;
		}
		bs_y = 620;
		bs_x = b_x+75;
	}
}
void Shooting()
{
	if (shoot == 1)
	{
		blast = 1;
		ammo_y += 2;
		if (ammo_y >= 700 || (ammo_y+5>=600-3 && ammo_y+5<=670 && ammo_x>=b_x-5 && ammo_x+5<=b_x+155))
		{
			if (ammo_y < 700)
			{
				score++;
				attack = 1;
			}
			ammo_y = 150;
			shoot = 0;
			blast = 0;
			if (ammo == 0)
				over = 0;
		}
	}
}
void main()
{
	//place your own initialization codes here.
	iSetTimer(50, Boss);
	iSetTimer(50, BossShooting);
	iSetTimer(10, Shooting);
	iInitialize(1360, 700, "Space Shooter");
}