
# include "iGraphics.h"
//Block co-ordinates
int block_x[100] = { 0, 50, 100, 150, 200, 250, 300, 350, 400, 450, 0, 50, 100, 150, 200, 250, 300, 350, 400, 450,
					0, 50, 100, 150, 200, 250, 300, 350, 400, 450, 0, 50, 100, 150, 200, 250, 300, 350, 400, 450,
					0, 50, 100, 150, 200, 250, 300, 350, 400, 450, 0, 50, 100, 150, 200, 250, 300, 350, 400, 450,
					0, 50, 100, 150, 200, 250, 300, 350, 400, 450, 0, 50, 100, 150, 200, 250, 300, 350, 400, 450,
					0, 50, 100, 150, 200, 250, 300, 350, 400, 450, 0, 50, 100, 150, 200, 250, 300, 350, 400, 450 };
int block_y[100] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 100, 100, 100, 100, 100,
					100, 100, 100, 100, 100,150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 200, 200, 200, 200, 200,
					200, 200, 200, 200, 200, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 300, 300, 300, 300, 300,
					300, 300, 300, 300, 300, 350, 350, 350, 350, 350, 350, 350, 350, 350, 350,400, 400, 400, 400, 400, 
					400, 400, 400, 400, 400, 450, 450, 450, 450, 450, 450, 450, 450, 450, 450 };
int block_xx[100], block_yy[100];
//Line co-ordinates
int line_x[10] = { 50, 100, 150, 200, 250, 300, 350, 400, 450 };
int line_y[10] = { 50, 100, 150, 200, 250, 300, 350, 400, 450, 500 };

int mine_x[15] = {110,310,210,410,60,210,410,260,260,310,60};
int mine_y[15] = { 110, 110, 260, 310, 360, 410, 410, 460, 60, 260, 260 };
int mine[11] = { 15, 26, 22, 51, 54, 56, 68, 71, 84, 88, 95 };

int two_x[100] = { 10, 60, 110, 210, 260, 360, 410, 460, 260, 260, 260, 310, 260, 360, 360 };
int two_y[100] = { 310, 310, 310, 460, 410, 360, 360, 360, 260, 310, 210, 60, 110, 310, 260 };

int one_x[100] = { 10, 10, 60, 110, 110, 110, 110, 60, 10, 10, 60, 60, 110, 160, 160, 160, 110, 60, 210, 210, 210, 260, 310,
				   360, 360, 310, 260, 210, 160, 160, 160, 210, 160, 210, 260, 160, 310, 360, 360, 410, 460, 460, 460, 460,
				   410, 310, 360,160,310,310 };
int one_y[100] = { 360, 410, 410, 410, 360, 260, 210, 210, 210, 260, 110, 160, 160, 160, 110, 60, 60, 60, 110, 60, 10, 10,
				   10, 110, 160, 160, 160, 210, 210, 260, 310, 310, 360, 360, 360, 410, 460, 410, 460, 460, 460, 410, 310, 260,
				   260, 210, 210,460,410,310 };
int blank_block[50] = { 0, 1, 2, 3, 7, 8, 9, 10, 17, 18, 19, 20, 28, 29, 30, 34, 38, 39, 48, 49, 76, 90, 91, 92 };
int detect_x[10] = { -100 };
int detect_y[10] = { -1000 };
int detectIndex = 0;
int score=0,hiddenScore = 0;
char scoreStr[10];
int vanish[100] = {-1}, indexVanish = 0;

bool gamePage = false, startPage = true, gameOver = false;
int input = 0, nameIndex = 0;
char name[30];

int r = 0, g = 255, b = 0;
bool over = false;

void checkBlank(int i)
{
	for (int j = 0; j < indexVanish; j++)
	{
		if (i == vanish[j])
		{
			block_xx[i] = -100;
			block_yy[i] = -100;
		}
	}

}
void iDraw()
{
	//place your drawing codes here	
	iClear();
	//Info bar
	if (startPage)
	{
		iShowBMP(0, 0, "BC2.bmp");
		iSetColor(255, 0, 0);
		iText(150, 210, "  Enter Your name here:");
		iRectangle(150, 150, 250, 50);
		iText(155, 155, name, GLUT_BITMAP_TIMES_ROMAN_24);

	}
	if (gamePage)
	{
		iSetColor(192, 192, 192);
		iFilledRectangle(0, 500, 500, 100);
		iSetColor(0, 0, 0);
		_itoa_s(score, scoreStr, 10);
		iText(385, 570, "Score: ");
		iText(450, 570, scoreStr);
		iText(385, 525, "Mines: 10");
		iText(10, 547, "Player: ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(100, 547, name, GLUT_BITMAP_TIMES_ROMAN_24);
		for (int i = 0; i < 100; i++) //Blocks
		{
			iSetColor(r, g, b);
			iFilledRectangle(block_x[i], block_y[i], 50, 50);
		}
		for (int i = 0; i < 11; i++){
			iShowBMP2(mine_x[i], mine_y[i], "mine.bmp", 0);
		}
		for (int i = 0; i < 15; i++){
			iShowBMP2(two_x[i], two_y[i], "2icon.bmp", 0);
		}
		for (int i = 0; i < 50; i++){
			iShowBMP2(one_x[i], one_y[i], "1icon.bmp", 0);
		}

		if (!over)
		for (int i = 0; i < 100; i++) //Outer blocks
		{
			checkBlank(i);
			iSetColor(255, 255, 0);
			iFilledRectangle(block_xx[i], block_yy[i], 50, 50);
		}
		for (int i = 0; i < 10; i++) //Lines
		{
			iSetColor(0, 0, 255);
			iLine(line_x[i], 0, line_x[i], 500);
			iLine(0, line_y[i], 500, line_y[i]);
		}
		for (int i = 0; i < 10; i++) //Lines
		{
			//iFilledCircle(detect_x[i], detect_y[i], 20);
			iShowBMP(detect_x[i], detect_y[i], "flag.bmp");
		}
		if (gameOver)
		{
			iFilledRectangle(100, 200, 300, 200);
			iSetColor(0, 0, 0);
			iText(150, 350, "GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(130, 290, "YOU HAVE SCORED:");
			iText(270, 290, scoreStr);
			iText(130, 230, "Press 'END' to close game");
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
void mouseListener(int mx, int my)
{
	for (int i = 0; i < 100; i++)
	{
		if (mx > block_x[i] && mx < block_x[i] + 50 && my>block_y[i] && my < block_y[i]+50)
		{
			printf("%d\n", i);
			if (i == 15 || i == 22 || i == 26 || i == 56 || i == 54 || i == 51 || i == 71 || i == 68 || i == 88 || i == 84 || i == 95)
			{
				r = 255; g = 0; b = 0;
				over = true;
				gameOver = true;
			}
			for (int j = 0; j < 24; j++)
			{
				if (i == blank_block[j])
				{
					vanish[indexVanish++] = i - 11;
					vanish[indexVanish++] = i - 10;
					vanish[indexVanish++] = i - 9;
					vanish[indexVanish++] = i - 1;
					vanish[indexVanish++] = i;
					vanish[indexVanish++] = i + 1;
					vanish[indexVanish++] = i + 9;
					vanish[indexVanish++] = i + 10;
					vanish[indexVanish++] = i + 11;
					score += 9;
				}
				else
				{
					vanish[indexVanish++] = i;
					score++;
				}
			}
			
			for (int j = 0; j < 11; j++)
			{
				for (int k = 0; k < indexVanish; k++)
				{
					if (mine[j] == vanish[k])
					{
						vanish[k] = -1;
					}
				}
			}
		}
	}
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
		//printf("x:%d y:%d\n", mx, my);
		if (gamePage)
		mouseListener(mx,my);
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		if (gamePage)
		{
			for (int i = 0; i < 100; i++)
			{
				if (block_x[i] < mx && block_x[i] + 50 > mx && block_y[i] < my && block_y[i] + 50 > my)
				{
					if (detectIndex <= 10)
					{
						detect_x[detectIndex] = block_x[i] + 15;
						detect_y[detectIndex] = block_y[i] + 15;
						detectIndex++;
						if (i == 15 || i == 22 || i == 26 || i == 56 || i == 54 || i == 51 || i == 71 || i == 68 || i == 88 || i == 84 || i == 95)
						{
							hiddenScore++;
							score += 10;
						}
					}
				}
			}
		}
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
				name[nameIndex] = key;
				nameIndex++;
				name[nameIndex] = NULL;
		}
		else
		{
			if (nameIndex != 0)
				nameIndex--;
			name[nameIndex] = NULL;
		}
	}
	else
	{
		startPage = false;
		gamePage = true;
	}
}
void iKeyboard(unsigned char key)
{
	if (startPage)
	Input(key);
	if (key == 'q')
	{
		//do something with 'q'
	}
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}
void copy()
{
	for (int i = 0; i < 100; i++)
	{
		block_xx[i] = block_x[i];
		block_yy[i] = block_y[i];
	}
}

void main()
{
	//place your own initialization codes here. 
	copy();
	iInitialize(500, 600, "Mine Sweeper");
}