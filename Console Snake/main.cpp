#include <iostream>
#include <conio.h>

using namespace std;

#define GRIDSIZE 11

char grid[GRIDSIZE][GRIDSIZE];
int snakeSize = 1;

//starting position
int headRow = 6;
int headColm = 6;
int appleRow;
int appleColm;

char input;

void clearGrid()//done
{
  for(int i=0; i<GRIDSIZE; i++)
    for(int j=0; j<GRIDSIZE; j++)
      grid[i][j] = 0;
}

void drawGrid()//done
{
  cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  for(int i=0; i<GRIDSIZE +2; i++)
    cout << "_";

  for(int row=0; row<GRIDSIZE; row++)
  {
    cout << "\n|";
   for(int colm=0; colm<GRIDSIZE; colm++)
    {
      if(grid[row][colm] == 0) //empty square
        cout << " ";
      else if(grid[row][colm] == snakeSize) //snake Head
        cout << "O";
      else if(grid[row][colm] > 0) //snake Body
        cout << "X";
        else if(grid[row][colm] == -1) //apple
        cout << "a";
        else if(grid[row][colm] == -2) //Wall
        cout << "#";
    }
    cout << "|";
  }
  cout << "\n";
  for(int i=0; i<GRIDSIZE +2; i++)
    cout << "_";
}

void refreshGrid() //done
{
  for(int row=0; row<GRIDSIZE; row++)
    for(int colm=0; colm<GRIDSIZE; colm++)
      {
        if(grid[row][colm] > 0)
          grid[row][colm]--;
      }
}

void newApple() //done
{
  do
  {
    appleRow = rand() % GRIDSIZE;
    appleColm = rand() % GRIDSIZE;
  } while (grid[appleRow][appleColm] != 0);

  grid[appleRow][appleColm] = -1;
}

void newWall() //done
{
  int wallRow;
  int wallColm;
  do
  {
    wallRow = rand() % GRIDSIZE;
    wallColm = rand() % GRIDSIZE;
  } while (grid[wallRow][wallColm] != 0);

  grid[wallRow][wallColm] = -2;
}


int main()
{
  while(1)
  {
    //void setup XD
  clearGrid();
  grid[headRow][headColm] = snakeSize;
  newApple();
  drawGrid();


  //void loop XD
  while(1)
  {
    //get input
    input = getch();
    if(input == 'w')
      headRow--;
    else if(input == 's')
      headRow++;
    else if(input == 'a')
      headColm--;
    else if(input == 'd')
      headColm++;
    else continue;

    //check if snake crossed the boarder
    if(headRow >= GRIDSIZE)
      headRow = 0;
    else if(headRow < 0)
      headRow = GRIDSIZE-1;
    if(headColm >= GRIDSIZE)
      headColm = 0;
    else if(headColm < 0)
      headColm = GRIDSIZE-1;

    //refresh grid
    refreshGrid();

    //check for eat or death
    if(grid[headRow][headColm] == -1)
    {
      snakeSize++;
      newApple();
      if(snakeSize % 5 == 0)
        newWall();
    }
    if(grid[headRow][headColm] == -2 || grid[headRow][headColm] > 0)
      break;

    //change head position
    grid[headRow][headColm] = snakeSize;

    drawGrid();
  }

  cout << "\n\nGame Over\n\n";
  cout << "Score = " <<snakeSize <<"\n\n";
  cout << "Continue? (y,n)\t\t";

    input = getch();
  if(input == 'n' || input == 'N')
    break;

  }
}


