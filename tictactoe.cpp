#include <iostream>
#include <cstring>
using namespace std;

/*
  Project: TicTacToe
  Made by: Brady Rozendaal
  Date: 
 */

void printBoard(char board[][])
{
  cout << " 1 2 3";
  char lines[3] = ['a', 'b', 'c']
  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
	{
	  if (j == 0)
	    {
	      cout << "\n" << lines[i] << " ";
	    }
	  cout << board[j][i] << " " <<;
	}
    }
}

int main()
{
  char board[3][3];
  
  return 0;
}
