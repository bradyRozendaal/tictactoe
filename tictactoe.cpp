#include <iostream>
#include <cstring>
using namespace std;

/*
  Project: TicTacToe
  Made by: Brady Rozendaal
  Date: 9/15/26
 */

void printBoard(char board[3][3])
{
  cout << "  1 2 3";//put out first row
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
  cout << "\n";
}

bool isOver(char board[3][3])
{
  for (int i = 0; i < 3; i++)
    {
      char currenty = board[0][i];
      char currentx = board[i][0];
      if (currenty != ' ') //checks left to right if the same
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
      if (currentx != ' ' && currentx == board[i][1] && currentx == board[i][2])
	  {
	    return true;
	  }
    }
  return false;
}
char changeTurn(char turn) //just flips the turn value
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
bool isValidPlacement(char board[3][3], int place[])//checks if valid placement
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
bool foundBoth(bool found[2])//returns true if both bools passed into it are true
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
int* convertPlacementToInt(char place[2])//returns a pointer to 2 items
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
	      found[0] = true;
	    }
	}
    }
  if (foundBoth(found))
    {
      return intPlace;//worked as expected, returns x and y value
    }
  else
    {
      intPlace[0] = -1;//returns negative one if not a valid placement
      return intPlace;
    }
}


int main()
{
  bool play = true;
  while (play)
  {
	char board[3][3];
  memset(board, ' ', sizeof(board));//initialize every cell to empty (' ') instead of leaving garbage memory -- this took me way too long to realize :/
  char turn = 'x';//starts turn x
  int turnNum = 0;
  while (!isOver(board) && turnNum < 9)//terminates the loop if max turn number is reached or a player has won
    {
      printBoard(board);
      cout << "\nWhere would you like to place " << turn << "(a1, b1, b3, etc): ";
      char charPlace[3] = {0};//room for 2 characters plus the null terminator cin appends
      cin.width(3);//limit extraction so cin can never write past the array bounds
      cin >> charPlace;
      int* place = convertPlacementToInt(charPlace);
      if (isValidPlacement(board, place))
	{
	  board[place[0]][place[1]] = turn;
	  turnNum++;
	  turn = changeTurn(turn);
	}
      else
	{
	  cout << "\nNot a valid placement.";
	}
      delete[] place;//avoid leaking the array convertPlacementToInt allocated
    }
  printBoard(board);
  if (isOver(board))
    {
      turn = changeTurn(turn);//would have been the player who took the last turn
      cout << "\n" << turn << " won.";
    }
  else
    {
      cout << "\nGame ended in a tie.";
    }
	  char yn;
	  cout << "would you like to play again? (y/n) \n";
	  cin >> yn;
	  if (yn == 'n')
	  {
		play = false;
	  }
  }
    return 0;
}
