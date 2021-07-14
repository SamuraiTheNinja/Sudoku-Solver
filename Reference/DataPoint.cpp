#include "DataPoint.h"

//Build the cell with a number
cell::cell(unsigned short num, int LocationM, int LocationN)
	:PossibleValues{ 0 }, //since we have a number already, set all to false
	Value(num), 
	board{ 0 }, 
	Given(true), 
	M(LocationM), 
	N(LocationN)
{
}

//Build the cell without a number
cell::cell(int LocationM, int LocationN)
	:PossibleValues{ 1,1,1,1,1,1,1,1,1 }, //since non-0 values are true, set all 9 to true
	Value(0), 
	board{ 0 }, 
	Given(false), 
	M(LocationM), 
	N(LocationN)
{
}

//take the external board and keep references to it locally
void cell::build_internal_board(cell * input[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = input[i][j];
		}
	}
}

//checks row, column, and block before checking if only one option left avaialable
void cell::evaluate()
{
	if (Value == 0)
	{
		int Available = 0;
		int temp = 0;

		check_column();
		check_row();
		check_square();

		for (int i = 0; i < 9; i++)
		{
			if (PossibleValues[i])
			{
				Available++;
				temp = i;
			}
		}
		if (Available == 1)
		{
			Value = temp + 1;
			for (int i = 0; i < 9; i++)
				PossibleValues[i] = false;
		}
		if (Value == 0)
		{
			check_possible_column();
			check_possible_row();
		}
	}
}

void cell::check_column()
{
	for (int i = 0; i < 9; i++)
	{
		int temp = board[i][N]->Value;
		if (temp != 0)
			PossibleValues[temp - 1] = false;
	}
}

void cell::check_row()
{
	for (int j = 0; j < 9; j++)
	{
		int temp = board[M][j]->Value;
		if (temp != 0)
			PossibleValues[temp - 1] = false;
	}
}

void cell::check_square()
{
	//is in top
	if (M < 3)
	{
		int send_offset_for_top = 0;
		check_square_pt2(send_offset_for_top);
	}
	//is in middle
	else if (M >= 3 && M <= 5)
	{
		int send_offset_for_middle = 3;
		check_square_pt2(send_offset_for_middle);
	}
	//is in bottom
	else if (M > 5)
	{
		int send_offset_for_bottom = 6;
	check_square_pt2(send_offset_for_bottom);
	}
}

void cell::check_square_pt2(int tmb)
{
	//is in left block
	if (N < 3)
	{
		int send_offset_for_left = 0;
		check_square_pt3(tmb, send_offset_for_left);
		check_possible_square(tmb, send_offset_for_left);
	}
	//is in middle block
	else if (N >= 3 && N <= 5)
	{
		int send_offset_for_middle = 3;
		check_square_pt3(tmb, send_offset_for_middle);
		check_possible_square(tmb, send_offset_for_middle);
	}
	//is in right block
	else if (N > 5)
	{
		int send_offset_for_right = 6;
			check_square_pt3(tmb, send_offset_for_right);
			check_possible_square(tmb, send_offset_for_right);
	}
}

void cell::check_square_pt3(int tmb, int lmr)
{
	for (int i = tmb; i < tmb + 3; i++)
	{
		for (int j = lmr; j < lmr + 3; j++)
		{
			int temp = board[i][j]->Value;
			if (temp != 0)
				PossibleValues[temp - 1] = false;
		}
	}
}

//check to see if a particular number is the only available one in a particular column 
void cell::check_possible_column()
{
	unsigned short count[9] = { 0 };
	bool * pv;
	//for every cell in this column
	for (int i = 0; i < 9; i++)
	{
		pv = board[i][N]->get_poss_vals();
		//check all possible values and record them in an array
		for (int k = 0; k < 9; k++)
		{
			if (*pv == true)
				count[k]++;
			pv++;
		}
	}
	int c = 0;
	int temp = 0;
	for (int a = 0; a < 9; a++)
	{
		if (count[a] == 1)
		{
			temp = a;
			c++;
		}
	}
	if (c == 1 && PossibleValues[temp])
	{
		Value = temp + 1;
		for (int i = 0; i < 9; i++)
			PossibleValues[i] = false;
	}
}

void cell::check_possible_row()
{
	unsigned short count[9] = { 0 };
	bool * pv;
	//for every cell in this column
	for (int j = 0; j < 9; j++)
	{
		pv = board[M][j]->get_poss_vals();
		//check all possible values and record them in an array
		for (int k = 0; k < 9; k++)
		{
			if (*pv == true)
				count[k]++;
			pv++;
		}
	}
	int c = 0;
	int temp = 0;
	for (int a = 0; a < 9; a++)
	{
		if (count[a] == 1)
		{
			temp = a;
			c++;
		}
	}
	if (c == 1 && PossibleValues[temp])
	{
		Value = temp + 1;
		for (int i = 0; i < 9; i++)
			PossibleValues[i] = false;
	}
}

void cell::check_possible_square(int tmb, int lmr)
{
	unsigned short count[9] = { 0 };
	bool * pv;
	for (int i = tmb; i < tmb + 3; i++)
	{
		for (int j = lmr; j < lmr + 3; j++)
		{
			pv = board[i][j]->get_poss_vals();
			//check all possible values and record them in an array
			for (int k = 0; k < 9; k++)
			{
				if (*pv == true)
					count[k]++;
				pv++;
			}
		}
	}
	int c = 0;
	int temp = 0;
	for (int a = 0; a < 9; a++)
	{
		if (count[a] == 1)
		{
			temp = a;
			c++;
		}
	}
	if (c == 1 && PossibleValues[temp])
	{
		Value = temp + 1;
		for (int i = 0; i < 9; i++)
			PossibleValues[i] = false;
	}
}

void cell::accept(visitor * v)
{
}

unsigned short cell::get_value()
{
	return Value;
}

bool * cell::get_poss_vals()
{
	return &PossibleValues[0];
}
