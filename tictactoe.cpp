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
  char lines[3] = {'a', 'b', 'c'};//array of row indicators
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
  for (int i = 0; i < 3; i++)
    {
      char currenty = board[0][i];
      char currentx = board[i][0];
      cout << currentx;
      if (currenty != '\0') //checks left to right if the same
	{
	  if (currenty == board[1][i] && currenty == board[2][i])
	    {
	      return true;
	    }
	  if (i==0)//if starting top left check diagonal
	    {
	      if (currenty == board[1][1] && currenty == board[2][2])
		{
		  return true;
		}
	    }
	  else if (i==2)//if starting bottom left check diagonal
	    {
	      if (currenty == board[1][1] && currenty == board[2][0])
		{
		  return true;
		}
	    }
	  }
	else if (currentx != '\0' && currentx == board[i][1] && currentx == board[i][2])
	  {
	    return true;
	  }
    }
  return false;
}
char changeTurn(char turn)
{
  if (turn == 'o')
    {
      return 'x';
    }
  else if (turn == 'x')
    {
      return 'o';
    }
  else
    {
      cout << "\nError: turn not 'x' or 'o'";
      return '0';
    }
}
bool isValidPlacement(char board[3][3], int place[])
{
  if (place[0] == -1)
    {
      return false;
    }
  if (board[place[0]][place[1]] != ' ')
    {
      return false;
    }
  else
    {
      return true;
    }
}
bool foundBoth(bool found[2])
{
  for (int i =0; i<2; i++)
    {
      if (!found[i])
	{
	  return false;
	}
    }
  return true;
}
int* convertPlacementToInt(char place[2])
{
  char lines[3] = {'a', 'b', 'c'};//array of row indicators
  char collumns[3] = {'1', '2', '3'};//array of collumn indicators
  int* intPlace = new int[2];//intialize return variable
  bool found[2] = {false, false};
  for (int i=0; i<3; i++)//iterate through lines and collumns
    {
      for (int j=0;j<2;j++)//iterate through place character 1&2 in case person puts in '1a' instead of 'a1'
	{
	  if (place[j] == lines[i])//if this character in place is equal to anything in lines
	    {
	      intPlace[1] = i;//, set y position of return variable to num in array where char is found
	      found[1] = true;
	    }
	  else if(place[j] == collumns[i])//if this character in place is equal to anything in collums
	    {
	      intPlace[0] = i;//, set x position of return variable to num in array where char is found
	      found[2] = true;
	    }
	}
    }
  if (foundBoth(found))
    {
      return intPlace;
    }
  else
    {
      intPlace[0] = -1;
      return intPlace;
    }
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
      int* place = convertPlacementToInt(charPlace);
      if (isValidPlacement(board, place))
	{
	  board[place[0]][place[1]] = turn;
	  turn = changeTurn(turn);
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
      turn = changeTurn(turn);//would have been the player who took the last turn
      cout << "\n" << turn << " won.";
    }
  return 0;
}
