#include<iostream>
#include <stdlib.h>
#include <stdio.h>  
#include <time.h>
using namespace std;


bool gameGenerator(char board[][10], bool firstPlayer, bool secondPlayer, int first);
void display(char board[][10]);
void doTurn(char board[][10], bool playerTurn);
bool check(char board[][10], bool check);

int main()
{
	//true= first player , false = second player
	cout << "Mobina Kashaniyan - connect 4" << endl << endl;
	bool firstPlayer = false, secondPlayer = false;
	char board[10][10];
	bool res = false;
	int first = 1;
	bool ends = false;
	do
	{
		bool turn = gameGenerator(board, firstPlayer, secondPlayer, first);
		if (turn == true)
		{
			firstPlayer = true;
			secondPlayer = false;
			doTurn(board, turn);
			res = check(board, turn);
			if (res == true)
			{
				cout << "**** First Player Wins! ****" << endl;
				display(board);
				break;
			}


		}
		if (turn == false)
		{
			firstPlayer = false;
			secondPlayer = true;
			doTurn(board, turn);
			res = check(board, turn);
			if (res == true)
			{
				cout << "**** Second Player Wins! ****" << endl;
				display(board);
				break;
			}
		}
		first++;
		display(board);
	} while (res != true);

	return 0;
}

bool turn = NULL;
bool gameGenerator(char board[][10], bool firstPlayer, bool secondPlayer, int first)
{
	float randy = 0;
	if (first == 1)
	{
		srand(time(NULL));
		randy = rand() % 10 + 1;
		if (randy <= 5)
		{
			cout << "First Player's Turn To Play First with Character X " << endl;
			firstPlayer = true;
			turn = true;
		}
		else if (randy > 5 && randy < 10) {
			cout << "Second Player's Turn To Play With Charachter O " << endl;
			secondPlayer = true;
			turn = false;
		}
	}
	if (first != 1)
	{
		if (turn == true)
		{
			turn = false;
			cout << "Second Player's Turn To Play With Charachter O " << endl;
		}
		else {
			turn = true;
			cout << "First Player's Turn To Play with Character X " << endl;
		}
	}
	return turn;
}

void display(char board[][10]) {
	int row = 6;
	int col = 5;
	for (int i = 1; i <= row; i++)
	{
		cout << "[";
		for (int j = 1; j <= col; j++)
		{
			if (board[i][j] != 'X' && board[i][j] != 'O')
			{
				board[i][j] = '*';
			}
			cout << board[i][j];
		}
		cout << "]" << endl;
	}

}
void doTurn(char board[][10], bool playerTurn)
{
	int row;
	int lenght = 5;
	char turn;
	if (playerTurn == true)
	{
		turn = 'X';

	}
	if (playerTurn == false)
	{
		turn = 'O';
	}
	cout << "Enter a number between 1 and 5 : ";
	cin >> row;
	for (int i = 1; i <= 6; i++)
	{
		if (board[i][row] != 'X' && board[i][row] != 'O') {
			board[i][row] = turn;
			break;
		}
		else if (board[i][row] == 'X' || board[i][row] == 'O') {
			if (i > 6)
			{
				cout << endl << "You Can't Select Here,Try Another Number,Or Start Again" << endl;
			}
			continue;
		}
	}
}
bool check(char board[][10], bool player)
{
	char XO;
	bool win;

	if (player == true)
	{
		XO = 'X';
	}
	else {
		XO = 'O';
	}
	win = 0;

	for (int i = 8; i >= 1; --i)
	{

		for (int ix = 9; ix >= 1; --ix)
		{

			if (board[i][ix] == XO &&
				board[i - 1][ix - 1] == XO &&
				board[i - 2][ix - 2] == XO &&
				board[i - 3][ix - 3] == XO)
			{
				win = 1;
			}


			if (board[i][ix] == XO &&
				board[i][ix - 1] == XO &&
				board[i][ix - 2] == XO &&
				board[i][ix - 3] == XO)
			{
				win = 1;
			}

			if (board[i][ix] == XO &&
				board[i - 1][ix] == XO &&
				board[i - 2][ix] == XO &&
				board[i - 3][ix] == XO)
			{
				win = 1;
			}

			if (board[i][ix] == XO &&
				board[i - 1][ix + 1] == XO &&
				board[i - 2][ix + 2] == XO &&
				board[i - 3][ix + 3] == XO)
			{
				win = 1;
			}

			if (board[i][ix] == XO &&
				board[i][ix + 1] == XO &&
				board[i][ix + 2] == XO &&
				board[i][ix + 3] == XO)
			{
				win = 1;
			}
		}

	}

	return win;
}
