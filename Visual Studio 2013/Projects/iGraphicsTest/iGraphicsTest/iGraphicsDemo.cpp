
#include "iGraphics.h"

double r1_x = 270, r1_y = 100;
double r2_x = 370, r2_y = 300;
double c_x = 100, c_y = 525;
double l1_x = 450, l1_y = 300, l1_xx=380;
double p1_x = 100, p1_y = 420;
double xa[] = { r1_x, p1_x, r1_x };
double ya[] = { r1_y, p1_y, r1_y+200 };
double xb[] = { r1_x+460, 1000-p1_x, r1_x+460 };
int ball_x=40,ball_y=40,bx,by;

int move = 0;
void iDraw()
{
	//place your drawing codes here
	iClear();
	iSetColor(102, 51, 0);
	iFilledRectangle(r1_x,r1_y,460,200);//First Rectangle.
	iSetColor(150, 255, 0);
	iFilledPolygon(xa, ya, 3);//Two Polygons.
	iFilledPolygon(xb, ya, 3);
	iSetColor(0, 0, 200);
	iFilledRectangle(r2_x, r2_y, 260, 100);//Second Rectangle.
	iSetColor(0, 191, 255);
	iFilledRectangle(0, 0, 1000, 100);//Third Rectangle/Water.
	iSetColor(0, 0, 0);
	iLine(l1_x, l1_y, l1_xx, l1_y+100);//Lines inside 2nd Rectangle.
	iLine(l1_x + 50, l1_y, l1_xx + 50, l1_y + 100);
	iLine(l1_x + (50 * 2), l1_y, l1_xx + (50 * 2), l1_y + 100);
	iLine(l1_x + (50 * 3), l1_y, l1_xx + (50 * 3), l1_y + 100);
	iSetColor(0, 0, 255);
	iFilledEllipse(ball_x,ball_y,20,15);
	iSetColor(255,255,0);
	iFilledCircle(c_x, c_y, 30);
}

void iMouseMove(int mx, int my)
{
	//place your codes here
	c_x = mx;
	c_y = my;
}

void iMouse(int button, int state, int mx, int my)
{
	//place your codes here
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//printf("x= %d y= %d\n", mx, my);
		if (mx >= 370 && mx <= 630 && my >= 300 && my <= 400)
		{
			printf("Yes\n");
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

void iKeyboard(unsigned char key)
{
	if (key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if (key == 'r')
	{
		iResumeTimer(0);
	}
	//place your codes for other keys here
}

void iSpecialKeyboard(unsigned char key)
{
	//place your codes for other keys here
}
void MoveBoat()
{
	if (move == 0)
	{
		r1_x += 2;
		r2_x += 2;
		l1_x += 2, l1_xx += 2;
		for (int i = 0; i < 3; i++)
			xa[i] += 2, xb[i] += 2;
		if (r1_x+630 >= 1000)
			move = 1;
	}
	else
	{
		r1_x -= 2;
		r2_x -= 2;
		l1_x -= 2, l1_xx -= 2;
		for (int i = 0; i < 3; i++)
			xa[i] -= 2, xb[i] -= 2;
		if (r1_x-170 <= 0)
			move = 0;
	}
	ball_x += bx;
	ball_y += by;

	if (ball_x > 1000 || ball_x < 0)bx = -bx;
	if (ball_y > 100 || ball_y < 0)by = -by;
}

void main()
{
	//place your own initialization codes here.
	iSetTimer(25, MoveBoat);
	bx = 5, by = 7;
	iInitialize(1000, 600,"<A Boat>");
}
