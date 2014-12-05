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
  gameOver(); 
  drawSnake();
  DrawPx(snakeArray[0].x, snakeArray[0].y, White);
  DrawPx(xapple, yapple, Red);
  DisplaySlate();
  delay(200);
  ClearSlate();
  updateSnake();
  
  if (dir == 0)
  {
    snakeArray[0].y++;
  }
  
  if (snakeArray[0].y > 7)
  {
    (snakeArray[0].y = 0);
  }
 
  if (dir == 90)
  {
    snakeArray[0].x++;
  }
  
  if (snakeArray[0].x > 7)
  {
    (snakeArray[0].x = 0);
  }
 
  if (dir == 180)
  {
    snakeArray[0].y--;
  }
  
  if (snakeArray[0].y < 0)
  {
    (snakeArray[0].y = 7);
  }  
  
  if (dir == 270)
  {
    snakeArray[0].x--;
  }
  
  if (snakeArray[0].x < 0)
  {
    (snakeArray[0].x = 7);
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
  
  if (xapple == snakeArray[0].x)
  {
    if (yapple == snakeArray[0].y)
    {
      xapple = random(8);
      yapple = random(8);
      marker++;
    }
  }
}

void drawSnake()
{
  for (int i = 0; i < marker; i++)
  {
    DrawPx(snakeArray[i].x, snakeArray[i].y, Violet);
  }
}

void updateSnake()
{
  for (int i = marker-1; i>0; i--)
  {
    snakeArray[i] = snakeArray[i-1];
  }
}

void gameOver()
{
  CheckButtonsPress();
  {
    if (Button_A)
      ClearSlate();
  }
}
