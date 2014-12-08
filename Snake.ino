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
  Draw player (snake head) - call drawSnake();
  Display Slate/Delay 100
  Check Buttons
  Update direction if button is pressed
  Update update player based on direction
  Correct for wrap
  Draw Apples (random location)
    Eating apples increases marker (snake body number)
  Draw body of snake
  Increasing marker of snake
  Game over (Button_A and go on body) 

  */
  gameOver(); 
  drawSnake();
  DrawPx(snakeArray[0].x, snakeArray[0].y, White);
  DrawPx(xapple, yapple, Red);
  DisplaySlate();
  delay(170);//a reasonable speed that that doesn't delay reactiont time
  ClearSlate();
  updateSnake();
  
  if (dir == 0) //up
  {
    snakeArray[0].y++;
  }
  
  if (snakeArray[0].y > 7)
  {
    (snakeArray[0].y = 0);//wrap
  }
 
  if (dir == 90) //right
  {
    snakeArray[0].x++;
  }
  
  if (snakeArray[0].x > 7)
  {
    (snakeArray[0].x = 0);//wrap
  }
 
  if (dir == 180)//down
  {
    snakeArray[0].y--;
  }
  
  if (snakeArray[0].y < 0)
  {
    (snakeArray[0].y = 7);//wrap
  }  
  
  if (dir == 270)//left
  {
    snakeArray[0].x--;
  }
  
  if (snakeArray[0].x < 0)
  {
    (snakeArray[0].x = 7);//wrap
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
      marker++;//when snake touches apple, marker increases and apple relocates
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
  CheckButtonsDown();
  {
    if (Button_A) //body will restart if a button is pressed
    {
      (marker = 3); //snake becomes 3
      Tone_Start(ToneD6,100);
      delay(100);
      Tone_Start(ToneC6,100);
    }
  }
  for (int i = 1; i < marker; i++)
  {
    if(snakeArray[0].x == snakeArray[i].x && snakeArray[0].y == snakeArray[i].y) //code for if snake head touches snake body (from Mrs. Kiang's snake code)
    {
      (marker = 3); //snake becomes 3
      Tone_Start(ToneD6,100);
      delay(100);
      Tone_Start(ToneC6,100);
    }
  }
}
