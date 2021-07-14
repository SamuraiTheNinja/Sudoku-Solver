
#include "Main.h"

int main(void)
{
	cell * board[9][9];
	unsigned short input[9][9] =
		{
			{0,0,0, 0,7,6, 0,0,0},
			{1,0,0, 0,3,8, 7,4,0},
			{0,7,0, 0,0,0, 0,0,0},

			{0,0,4, 0,6,0, 5,0,1},
			{0,6,7, 0,0,0, 2,8,0},
			{3,0,1, 0,4,0, 6,0,7},

			{0,0,0, 0,0,0, 0,1,0},
			{0,2,5, 6,1,0, 0,0,9},
			{0,0,0, 9,8,0, 0,0,0}
		};/*
	unsigned short input[9][9] =
	{
		{0,5,2, 6,0,0, 1,9,8},
		{0,6,7, 0,0,3, 5,0,4},
		{9,0,4, 0,0,2, 3,0,0},

		{0,9,5, 0,0,0, 0,0,7},
		{7,0,0, 0,0,0, 0,0,5},
		{2,0,0, 0,0,0, 6,1,0},

		{0,0,9, 4,0,0, 7,0,1},
		{4,0,1, 9,0,0, 8,6,0},
		{5,3,6, 0,0,8, 9,4,0}
	};/**/
	bool debug = true;
	//asks user for input if not debugging, if debugging then uses pre written sudoku puzzle. 
	if (!debug)
	{
		printf("This program will solve Sudoku games for you.\n");
		printf("\n\nPlease enter the sudoku page starting in the top left and to the right, then down. Enter a 0 for an unknown space");

		for (int i = 0; i < 9; i++)
		{

			if (i == 0)
				printf("\nPlease enter the first row of numbers:\n_ _ _  _ _ _  _ _ _\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			else
				printf("\nPlease enter row %d of the puzzle:\n_ _ _  _ _ _  _ _ _\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", i + 1);

			scanf_s("%d %d %d %d %d %d %d %d %d", &input[i][0], &input[i][1], &input[i][2], &input[i][3], &input[i][4], &input[i][5], &input[i][6], &input[i][7], &input[i][8]);

		}

	}

	//make objects, assign them to board
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (input[i][j] != 0)
				board[i][j] = new cell(input[i][j], i, j); //make a new cell, give it the number stored in its spot if its not 0, then assign it to its location on the board
			else
				board[i][j] = new cell(i, j); //make new cell for an unknown square
		}
	}


	//pass board into each object
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			board[i][j]->build_internal_board(board);
		}
	}

	print_puzzle(board);

	int sum = 0;
	while (sum < 404)
	{
		sum = 0;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				board[i][j]->evaluate();
				sum += board[i][j]->get_value();
			}
		print_puzzle(board);
		system("Pause");
	}

	print_puzzle(board);
	system("Pause");
	return 0;
}

void print_puzzle(cell * board[9][9])
{
	printf("\n");

	//prints the entered sudoku puzzle
	for (int i = 0; i <= 8; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			printf(" %d ", board[i][j]->get_value());
			if (j == 2 || j == 5)
				printf(" ");
		}
		printf("\n");
		if (i == 2 || i == 5)
			printf("\n");
	}

	printf("\n");
}
