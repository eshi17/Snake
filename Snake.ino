/*
  SnakeGame.pde
 */

#include <MeggyJrSimple.h>

//global variables
int xplayer = 3; //coordinates of player dot
int yplayer = 4;
int dir = 0; //possible values: 0, 90, 180, 270
int xapple = random(8);
int yapple = random(8);
int marker = 3;

struct Point
{
  int x;
  int y;
};

Point p1 = {3, 4};
Point p2 = {4, 4};
Point p3 = {5, 4};

Point snakeArray[64] = {p1, p2, p3};


void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // RequiYellow code, line 2 of 2.
}


void loop()
{
  /*
  Draw player - call drawSnake();
  Draw Apple
  Display Slate/Delay 100
  Correct for wrap
  Check Buttons
  Update direction if button is pressed
  Update update player based on direction
  */
  DrawPx(xplayer, yplayer, White);
  DisplaySlate();
  delay(200);
  ClearSlate();
  
  if (dir == 0)
  {
    (yplayer = yplayer+1);
  }
  
  if (yplayer > 7)
  {
    (yplayer = 0);
  }
 
  if (dir == 90)
  {
    (xplayer = xplayer+1);
  }
  
  if (xplayer > 7)
  {
    (xplayer = 0);
  }
 
  if (dir == 180)
  {
    (yplayer = yplayer-1);
  }
  
  if (yplayer < 0)
  {
    (yplayer = 7);
  }  
  
  if (dir == 270)
  {
    (xplayer = xplayer-1);
  }
  
  if (xplayer < 0)
  {
    (xplayer = 7);
  }

  
  CheckButtonsPress();
  if (Button_Right)
  {
    (dir = 90);
  }
  if (Button_Left)
  {
    (dir = 270);
  }
  if (Button_Down)
  {
    (dir = 180);
  }
  if (Button_Up)
  {
    (dir = 0);
  }
  
  DrawPx(xapple, yapple, Red);
  DisplaySlate();
  
  if (xapple == xplayer)
  {
    if (yapple == yplayer)
    {
      xapple = random(8);
      yapple = random(8);
    }
  }
}

void drawSnake()
{
  for (int i = 0; i < marker; i++)
  {
    DrawPx(snakeArray[i].x, snakeArray[i].y, White);
  }
}
