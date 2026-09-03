#include <iostream>
#include <cstring>
using namespace std;

/*
  Project: TicTacToe
  Made by: Brady Rozendaal
  Date: 
 */

void printBoard(char board[3][3])
{
  cout << " 1 2 3";//put out first row
  char lines[3] = {'a', 'b', 'c'};//array of collumn indicators
  for (int i = 0; i < 3; i++)//loop through y values
    {
      for (int j = 0; j < 3; j++)//loop through x values (left to right, top to bottom)
	{
	  if (j == 0)//if first in line
	    {
	      cout << "\n" << lines[i] << " ";//print new line, the line indictor, then a space
	    }
	  cout << board[j][i] << " "; //print out the character that is on the board
	}
    }
}

bool isOver(char board[3][3])
{
  
}
char changeTurn(char turn)
{
  if (turn == 'y')
    {
      return 'x';
    }
  elif (turn == 'x')
    {
      return 'y';
    }
  else
    {
      cout << "\nError: turn not 'x' or 'y'";
      return '0';
    }
}
bool isValidPlacement(char board[3][3], int place[])
{
  
}
int convertPlacementToInt()
{
  
}

int main()
{
  char board[3][3];
  char turn = 'x';
  int turnNum = 0;
  printBoard(board);
  while (!isOver(board))
    { 
      cout << "\nWhere would you like to place " << turn << "(a1, b1, b3, etc)";
      char charPlace[2];
      cin >> charPlace;
      int place[2] = covertPlacementToInt(charPlace);
      if (isValidPlacement(board, place))
	{
	  board[place[0]][place[1]] = turn;
	  turn = changeTurn();
	  turn++;
	}
      else
	{
	  cout << "\nNot a valid placement.";
	}
    }
  if (turnNum == 9)
    {
      cout << "\nGame ended in a tie.";
    }
  else
    {
      turn = changeTurn();//would have been the player who took the last turn
      cout << "\n" << turn << " won."
    }
  return 0;
}
