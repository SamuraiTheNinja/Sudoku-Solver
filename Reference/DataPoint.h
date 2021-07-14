/*

An object that contains all information and algorithms for a given sudoku cell

*/

#include "Visitor.h"

class cell
{
public:
	cell(unsigned short num, int LocationM, int LocationN);
	cell(int LocationM, int LocationN);
	void build_internal_board(cell *input[9][9]);
	void evaluate();
	unsigned short get_value();
	bool * get_poss_vals();
private:
	//functions
	void check_column();
	void check_row();
	void check_square();
	void check_square_pt2(int tmb);
	void check_square_pt3(int tmb, int lmr);
	void check_possible_column();
	void check_possible_row();
	void check_possible_square(int tmb, int lmr);
	void accept(visitor * v);
	

	//variables
	bool PossibleValues[9];
	unsigned short Value;
	bool Given;
	cell * board[9][9];
	int M, N;
};
