#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
//#include <stdlib.h>
//#include <string.h>


int main(void)
{
	int input[9][9] =
	{
		{0,0,0,0,7,6,0,0,0},
		{1,0,0,0,3,8,7,4,0},
		{0,7,0,0,0,0,0,0,0},

		{0,0,4,0,6,0,5,0,1},
		{0,6,7,0,0,0,2,8,0},
		{3,0,1,0,4,0,6,0,7},

		{0,0,0,0,0,0,0,1,0},
		{0,2,5,6,1,0,0,0,9},
		{0,0,0,9,8,0,0,0,0}
	};
	int checker[9][9][9] =
	{
		{ { 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 }},
		{ { 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 }},
		{ { 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 } },
		{ { 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 } },
		{ { 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 } },
		{ { 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 } },
		{ { 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 } },
		{ { 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 } },
		{ { 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 },{ 1,2,3,4,5,6,7,8,9 } }
	};
	int checkerPT2 = 0, checkerPT3 = 0, checkerPT4 = 0;
	int counterR, counterC, counterZ, counterJ, sum = 0;
	int across, down;
	int across2, down2;
	int across3, down3;
	int location = 0;
	int debug = 1;


	//asks user for input if not debugging, if debugging then uses pre written sudoku puzzle. 
	if (debug == 0)
	{


		printf("This program will solve Sudoku games for you.\n");
		printf("\n\nPlease enter the sudoku page starting in the top left and to the right, then down. Enter a 0 for an unknown space");

		for (counterR = 0; counterR < 9; counterR++)
		{

			if (counterR == 0)
				printf("\nPlease enter the first row of numbers:\n_ _ _  _ _ _  _ _ _\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			else
				printf("\nPlease enter row %d of the puzzle:\n_ _ _  _ _ _  _ _ _\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b", counterR + 1);

			scanf("%d %d %d %d %d %d %d %d %d", &input[counterR][0], &input[counterR][1], &input[counterR][2], &input[counterR][3], &input[counterR][4], &input[counterR][5], &input[counterR][6], &input[counterR][7], &input[counterR][8]);

		}



		//end of debug if
	}





	printf("\n");

	//prints the entered sudoku puzzle
	for (counterR = 0; counterR <= 8; counterR++)
	{
		for (counterC = 0; counterC <= 8; counterC++)
		{
			printf(" %d ", input[counterR][counterC]);
			if (counterC == 2 || counterC == 5)
				printf(" ");
		}
		printf("\n");
		if (counterR == 2 || counterR == 5)
			printf("\n");
	}

	printf("\n");


	//loop does the checking and replacing of values. checks for completion by summing all values
	while (sum < 404)
	{


		//SUDOKU PUZZLE EVALUATION METHOD 1:
			//checks block by block for solutions
		for (counterR = 0; counterR <= 8; counterR++)
		{
			for (counterC = 0; counterC <= 8; counterC++)
			{
				//scanf("%d",&counterZ);


						 //checks if value is 0. If not then goes checks next block.
				if (input[counterR][counterC] != 0)
				{
					for (counterJ = 0; counterJ <= 8; counterJ++)
					{
						checker[counterR][counterC][counterJ] = 0; //sets all "potential" values to 0 since block is already defined (for method 2)
					}

				}
				//printf("This number is already defined\n");

			//checks column, row, and 3x3 square for numbers that may help determine the target square.
				else
				{
					//printf("Unknown value in puzzle\n");
					//checks the column for numbers, any numbers it finds it replaces with 0 in the checker[counterR][counterC] variable
					for (across = 0; across <= 8; across++)
					{
						if (input[counterR][across] == 0);
						//printf("got a 0(across)\n");
						else if (input[counterR][across] == 1)
						{
							checker[counterR][counterC][0] = 0;
							//printf("across found a 1\n");
						}
						else if (input[counterR][across] == 2)
						{
							checker[counterR][counterC][1] = 0;
							//printf("across found a 2\n");
						}
						else if (input[counterR][across] == 3)
						{
							checker[counterR][counterC][2] = 0;
							//printf("across found a 3\n");
						}
						else if (input[counterR][across] == 4)
						{
							checker[counterR][counterC][3] = 0;
							//printf("across found a 4\n");
						}
						else if (input[counterR][across] == 5)
						{
							checker[counterR][counterC][4] = 0;
							//printf("across found a 5\n");
						}
						else if (input[counterR][across] == 6)
						{
							checker[counterR][counterC][5] = 0;
							//printf("across found a 6\n");
						}
						else if (input[counterR][across] == 7)
						{
							checker[counterR][counterC][6] = 0;
							//printf("across found a 7\n");
						}
						else if (input[counterR][across] == 8)
						{
							checker[counterR][counterC][7] = 0;
							//printf("across found a 8\n");
						}
						else if (input[counterR][across] == 9)
						{
							checker[counterR][counterC][8] = 0;
							//printf("across found a 9\n");
						}
						else
							printf("I don't know what went wrong...across? The number found is: %d counterR: %d   across: %d\n", input[counterR][across], counterR, across);
					}

					//checks the row for numbers, any numbers it finds it replaces with 0 in the checker[counterR][counterC] variable
					for (down = 0; down <= 8; down++)
					{
						if (input[down][counterC] == 0);
						//printf("got a 0(down)\n");
						else if (input[down][counterC] == 1)
						{
							//printf("down found a 1\n");
							checker[counterR][counterC][0] = 0;
						}
						else if (input[down][counterC] == 2)
						{
							//printf("down found a 2\n");
							checker[counterR][counterC][1] = 0;
						}
						else if (input[down][counterC] == 3)
						{
							//printf("down found a 3\n");
							checker[counterR][counterC][2] = 0;
						}
						else if (input[down][counterC] == 4)
						{
							//printf("down found a 4\n");
							checker[counterR][counterC][3] = 0;
						}
						else if (input[down][counterC] == 5)
						{
							//printf("down found a 5\n");
							checker[counterR][counterC][4] = 0;
						}
						else if (input[down][counterC] == 6)
						{
							//printf("down found a 6\n");
							checker[counterR][counterC][5] = 0;
						}
						else if (input[down][counterC] == 7)
						{
							//printf("down found a 7\n");
							checker[counterR][counterC][6] = 0;
						}
						else if (input[down][counterC] == 8)
						{
							//printf("down found a 8\n");
							checker[counterR][counterC][7] = 0;
						}
						else if (input[down][counterC] == 9)
						{
							//printf("down found a 9\n");
							checker[counterR][counterC][8] = 0;
						}
						else
							printf("I don't know what went wrong...down? The number found is: %d  down: %d   counterC: %d\n", input[down][counterC], down, counterC);
					}
					if (counterR <= 2)
					{
						//top left block of 3
						if (counterC <= 2)
						{
							for (across = 0; across <= 2; across++)
							{
								for (down = 0; down <= 2; down++)
								{
									if (input[down][across] == 0);
									//printf("got a 0(TL)\n");
									else if (input[down][across] == 1)
									{
										checker[counterR][counterC][0] = 0;
										//printf("TL got a 1\n");
									}
									else if (input[down][across] == 2)
									{
										checker[counterR][counterC][1] = 0;
										//printf("TL got a 2\n");
									}
									else if (input[down][across] == 3)
									{
										checker[counterR][counterC][2] = 0;
										//printf("TL got a 3\n");
									}
									else if (input[down][across] == 4)
									{
										checker[counterR][counterC][3] = 0;
										//printf("TL got a 4\n");
									}
									else if (input[down][across] == 5)
									{
										checker[counterR][counterC][4] = 0;
										//printf("TL got a 5\n");
									}
									else if (input[down][across] == 6)
									{
										checker[counterR][counterC][5] = 0;
										//printf("TL got a 6\n");
									}
									else if (input[down][across] == 7)
									{
										checker[counterR][counterC][6] = 0;
										//printf("TL got a 7\n");
									}
									else if (input[down][across] == 8)
									{
										checker[counterR][counterC][7] = 0;
										//printf("TL got a 8\n");
									}
									else if (input[down][across] == 9)
									{
										checker[counterR][counterC][8] = 0;
										//printf("TL got a 9\n");
									}
									else
										printf("I'm not sure what happened Top left block of 3. The number found is: %d down:%d across:%d\n", input[down][across], down, across);
								}
							}
						}

						//top middle block of 3
						else if (counterC <= 5 && counterC > 2)
						{
							for (across = 3; across <= 5; across++)
							{
								for (down = 0; down <= 2; down++)
								{
									if (input[down][across] == 0);
									//printf("got a 0(TM)\n");
									else if (input[down][across] == 1)
										checker[counterR][counterC][0] = 0;
									else if (input[down][across] == 2)
										checker[counterR][counterC][1] = 0;
									else if (input[down][across] == 3)
										checker[counterR][counterC][2] = 0;
									else if (input[down][across] == 4)
										checker[counterR][counterC][3] = 0;
									else if (input[down][across] == 5)
										checker[counterR][counterC][4] = 0;
									else if (input[down][across] == 6)
										checker[counterR][counterC][5] = 0;
									else if (input[down][across] == 7)
										checker[counterR][counterC][6] = 0;
									else if (input[down][across] == 8)
										checker[counterR][counterC][7] = 0;
									else if (input[down][across] == 9)
										checker[counterR][counterC][8] = 0;
									else
										printf("I'm not sure what happened Top middle block of 3.\n");
								}
							}
						}

						//top right block of 3
						else
						{
							for (across = 6; across <= 8; across++)
							{
								for (down = 0; down <= 2; down++)
								{
									if (input[down][across] == 0);
									//printf("got a 0(TR)\n");
									else if (input[down][across] == 1)
										checker[counterR][counterC][0] = 0;
									else if (input[down][across] == 2)
										checker[counterR][counterC][1] = 0;
									else if (input[down][across] == 3)
										checker[counterR][counterC][2] = 0;
									else if (input[down][across] == 4)
										checker[counterR][counterC][3] = 0;
									else if (input[down][across] == 5)
										checker[counterR][counterC][4] = 0;
									else if (input[down][across] == 6)
										checker[counterR][counterC][5] = 0;
									else if (input[down][across] == 7)
										checker[counterR][counterC][6] = 0;
									else if (input[down][across] == 8)
										checker[counterR][counterC][7] = 0;
									else if (input[down][across] == 9)
										checker[counterR][counterC][8] = 0;
									else
										printf("I'm not sure what happened Top right block of 3.\n");
								}
							}
						}
					}
					else if (counterR <= 5 && counterR > 2)
					{
						//middle left block of 3
						if (counterC <= 2)
						{
							for (across = 0; across <= 2; across++)
							{
								for (down = 3; down <= 5; down++)
								{
									if (input[down][across] == 0);
									//printf("got a 0(ML)\n");
									else if (input[down][across] == 1)
										checker[counterR][counterC][0] = 0;
									else if (input[down][across] == 2)
										checker[counterR][counterC][1] = 0;
									else if (input[down][across] == 3)
										checker[counterR][counterC][2] = 0;
									else if (input[down][across] == 4)
										checker[counterR][counterC][3] = 0;
									else if (input[down][across] == 5)
										checker[counterR][counterC][4] = 0;
									else if (input[down][across] == 6)
										checker[counterR][counterC][5] = 0;
									else if (input[down][across] == 7)
										checker[counterR][counterC][6] = 0;
									else if (input[down][across] == 8)
										checker[counterR][counterC][7] = 0;
									else if (input[down][across] == 9)
										checker[counterR][counterC][8] = 0;
									else
										printf("I'm not sure what happened middle left block of 3.\n");
								}
							}
						}

						//middle middle block of 3
						else if (counterC <= 5 && counterC > 2)
						{
							for (across = 3; across <= 5; across++)
							{
								for (down = 4; down <= 5; down++)
								{
									if (input[down][across] == 0);
									//printf("got a 0(MM)\n");
									else if (input[down][across] == 1)
										checker[counterR][counterC][0] = 0;
									else if (input[down][across] == 2)
										checker[counterR][counterC][1] = 0;
									else if (input[down][across] == 3)
										checker[counterR][counterC][2] = 0;
									else if (input[down][across] == 4)
										checker[counterR][counterC][3] = 0;
									else if (input[down][across] == 5)
										checker[counterR][counterC][4] = 0;
									else if (input[down][across] == 6)
										checker[counterR][counterC][5] = 0;
									else if (input[down][across] == 7)
										checker[counterR][counterC][6] = 0;
									else if (input[down][across] == 8)
										checker[counterR][counterC][7] = 0;
									else if (input[down][across] == 9)
										checker[counterR][counterC][8] = 0;
									else
										printf("I'm not sure what happened middle middle block of 3.\n");
								}
							}
						}

						//middle right block of 3
						else
						{
							for (across = 6; across <= 8; across++)
							{
								for (down = 3; down <= 5; down++)
								{
									if (input[down][across] == 0);
									//printf("got a 0(MR)\n");
									else if (input[down][across] == 1)
										checker[counterR][counterC][0] = 0;
									else if (input[down][across] == 2)
										checker[counterR][counterC][1] = 0;
									else if (input[down][across] == 3)
										checker[counterR][counterC][2] = 0;
									else if (input[down][across] == 4)
										checker[counterR][counterC][3] = 0;
									else if (input[down][across] == 5)
										checker[counterR][counterC][4] = 0;
									else if (input[down][across] == 6)
										checker[counterR][counterC][5] = 0;
									else if (input[down][across] == 7)
										checker[counterR][counterC][6] = 0;
									else if (input[down][across] == 8)
										checker[counterR][counterC][7] = 0;
									else if (input[down][across] == 9)
										checker[counterR][counterC][8] = 0;
									else
										printf("I'm not sure what happened middle right block of 3.\n");
								}
							}
						}
					}
					else
					{
						//bottom left block of 3
						if (counterC <= 2)
						{
							for (across = 0; across <= 2; across++)
							{
								for (down = 6; down <= 8; down++)
								{
									if (input[down][across] == 0);
									//printf("got a 0(BL)\n");
									else if (input[down][across] == 1)
										checker[counterR][counterC][0] = 0;
									else if (input[down][across] == 2)
										checker[counterR][counterC][1] = 0;
									else if (input[down][across] == 3)
										checker[counterR][counterC][2] = 0;
									else if (input[down][across] == 4)
										checker[counterR][counterC][3] = 0;
									else if (input[down][across] == 5)
										checker[counterR][counterC][4] = 0;
									else if (input[down][across] == 6)
										checker[counterR][counterC][5] = 0;
									else if (input[down][across] == 7)
										checker[counterR][counterC][6] = 0;
									else if (input[down][across] == 8)
										checker[counterR][counterC][7] = 0;
									else if (input[down][across] == 9)
										checker[counterR][counterC][8] = 0;
									else
										printf("I'm not sure what happened bottom left block of 3.\n");
								}
							}
						}

						//bottom middle block of 3
						else if (counterC <= 5 && counterC > 2)
						{
							for (across = 3; across <= 5; across++)
							{
								for (down = 6; down <= 8; down++)
								{
									if (input[down][across] == 0);
									//printf("got a 0(BM)\n");
									else if (input[down][across] == 1)
										checker[counterR][counterC][0] = 0;
									else if (input[down][across] == 2)
										checker[counterR][counterC][1] = 0;
									else if (input[down][across] == 3)
										checker[counterR][counterC][2] = 0;
									else if (input[down][across] == 4)
										checker[counterR][counterC][3] = 0;
									else if (input[down][across] == 5)
										checker[counterR][counterC][4] = 0;
									else if (input[down][across] == 6)
										checker[counterR][counterC][5] = 0;
									else if (input[down][across] == 7)
										checker[counterR][counterC][6] = 0;
									else if (input[down][across] == 8)
										checker[counterR][counterC][7] = 0;
									else if (input[down][across] == 9)
										checker[counterR][counterC][8] = 0;
									else
										printf("I'm not sure what happened bottom middle block of 3.\n");
								}
							}
						}

						//bottom right block of 3
						else
						{
							for (across = 6; across <= 8; across++)
							{
								for (down = 6; down <= 8; down++)
								{
									if (input[down][across] == 0);
									//printf("got a 0(BR)\n");
									else if (input[down][across] == 1)
										checker[counterR][counterC][0] = 0;
									else if (input[down][across] == 2)
										checker[counterR][counterC][1] = 0;
									else if (input[down][across] == 3)
										checker[counterR][counterC][2] = 0;
									else if (input[down][across] == 4)
										checker[counterR][counterC][3] = 0;
									else if (input[down][across] == 5)
										checker[counterR][counterC][4] = 0;
									else if (input[down][across] == 6)
										checker[counterR][counterC][5] = 0;
									else if (input[down][across] == 7)
										checker[counterR][counterC][6] = 0;
									else if (input[down][across] == 8)
										checker[counterR][counterC][7] = 0;
									else if (input[down][across] == 9)
										checker[counterR][counterC][8] = 0;
									else
										printf("I'm not sure what happened bottom right block of 3.\n");
								}
							}
						}
					}
				}


				checkerPT3 = 0; //resets checkerPT3 so that it only totals values during this iteration.


				//checks to see how many non zero terms are have been found
				for (checkerPT2 = 0; checkerPT2 <= 8; checkerPT2++)
				{
					if (checker[counterR][counterC][checkerPT2] == 0);
					//continue;
					//printf("got a 0(checker[counterR][counterC]PT2)\n");
					else if (checker[counterR][counterC][checkerPT2] != 0)
					{
						checkerPT3++;
						//printf("got a non zero\n");
					}
				}
				if (checkerPT3 != 1)
					continue;

				//IF AND ONLY IF one value is left then writes the value to the block
				else
				{
					checkerPT2 = 0;
					checkerPT2 = checker[counterR][counterC][0] + checker[counterR][counterC][1] + checker[counterR][counterC][2] + checker[counterR][counterC][3] + checker[counterR][counterC][4] + checker[counterR][counterC][5] + checker[counterR][counterC][6] + checker[counterR][counterC][7] + checker[counterR][counterC][8];
					input[counterR][counterC] = checkerPT2;
					printf("replaced row:%d column:%d with %d\n", counterR + 1, counterC + 1, checkerPT2);
					//printf("%d, %d, %d, %d, %d, %d, %d, %d, %d\n", checker[8][6][0], checker[8][6][1], checker[8][6][2], checker[8][6][3], checker[8][6][4], checker[8][6][5], checker[8][6][6], checker[8][6][7], checker[8][6][8]); //just checks a specific block's available numbers. I used this to check against the page i had been working by hand.

				}
			}
		}



		//SUDOKU PUZZLE EVALUATION METHOD 2:
			//checks number by number for solutions
		for (counterR = 0; counterR <= 8; counterR++)			//counter for determining the block location horizontally
		{
			for (counterC = 0; counterC <= 8; counterC++)		//counter for determining the block location vertically
			{
				//scanf("%d", &debug);
				for (counterZ = 0; counterZ <= 8; counterZ++)	//counter for determining the specific "potential" number within the above block
				{
					//printf("[%d][%d][%d]\n", counterR+1, counterC+1, counterZ+1);
					checkerPT3 = 0;
					if (checker[counterR][counterC][counterZ] != 0)  //is the "potential" value 0? if no proceed
					{
						//checks all "potential" values in this row to look for a match, or lack there of.
						for (across = 0; across <= 8; across++)
						{
							if (checker[counterR][across][counterZ] == checker[counterR][counterC][counterZ])
								checkerPT3++;
							//printf("checkerPT3:%d\n", checkerPT3);
						}
						if (checkerPT3 == 1) //if the checked value can only be in this one place it must be THE value
						{
							input[counterR][counterC] = checker[counterR][counterC][counterZ];
							printf("Replaced row:%d column:%d with %d\n", counterR + 1, counterC + 1, checker[counterR][counterC][counterZ]);
							continue;
						}
						checkerPT3 = 0;

						//checks all "potential" values in this column to look for a match, or lack there of.
						for (down = 0; down <= 8; down++)
						{
							if (checker[down][counterC][counterZ] == checker[counterR][counterC][counterZ])
							{
								checkerPT3++; //will always be at least 2 by this point (minimum of 1 from across, plus finding its self here)
							}
							//printf("checkerPT3:%d\n", checkerPT3);
						}
						if (checkerPT3 == 1) //if the checked value can only be in this one place it must be THE value
						{
							input[counterR][counterC] = checker[counterR][counterC][counterZ];
							printf("Replaced row:%d column:%d with %d\n", counterR + 1, counterC + 1, checker[counterR][counterC][counterZ]);
							continue;
						}
						checkerPT3 = 0;

						//checks the "potential values in the 3x3 to look for a match, or lack there of.
						//top 3x3 row
						if (counterR <= 2)
						{

							//Top left 3x3
							if (counterC <= 2)
							{

								for (down2 = 0; down2 <= 2; down2++)
								{
									for (across2 = 0; across2 <= 2; across2++)
									{
										//printf("I am here");
										if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
											checkerPT3++; //will bring min value for checkerPT3 up to 3
										else
											continue;
									}
								}
								if (checkerPT3 == 1) //if the checked value can only be in this one place it must be THE value
								{
									input[counterR][counterC] = checker[counterR][counterC][counterZ];
									printf("Replaced row:%d column:%d with %d\n", counterR + 1, counterC + 1, checker[counterR][counterC][counterZ]);
									continue;
								}

								checkerPT3 = 0;
								//printf("checkerPT3:%d\n", checkerPT3);
							}


							//top middle 3x3
							if (counterC > 2 && counterC <= 5)
							{
								for (down2 = 0; down2 <= 2; down2++)
								{
									for (across2 = 3; across2 <= 5; across2++)
									{
										if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
											checkerPT3++; //will bring min value for checkerPT3 up to 3
									}
								}
								if (checkerPT3 == 1) //if the checked value can only be in this one place it must be THE value
								{
									input[counterR][counterC] = checker[counterR][counterC][counterZ];
									printf("Replaced row:%d column:%d with %d\n", counterR + 1, counterC + 1, checker[counterR][counterC][counterZ]);
									continue;
								}
								checkerPT3 = 0;
							}

							//top right 3x3
							if (counterC > 5)
							{
								for (down2 = 0; down2 <= 2; down2++)
								{
									for (across2 = 6; across2 <= 8; across2++)
									{
										if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
											checkerPT3++; //will bring min value for checkerPT3 up to 3
									}
								}
								if (checkerPT3 == 1) //if the checked value can only be in this one place it must be THE value
								{
									input[counterR][counterC] = checker[counterR][counterC][counterZ];
									printf("Replaced row:%d column:%d with %d\n", counterR + 1, counterC + 1, checker[counterR][counterC][counterZ]);
									continue;
								}
								checkerPT3 = 0;
							}
							//Top left 3x3
							if (counterC <= 2)
							{
								for (down2 = 0; down2 <= 2; down2++)
								{
									for (across2 = 0; across2 <= 2; across2++)
									{
										if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
											checkerPT3++; //will bring min value for checkerPT3 up to 3
									}
								}
								if (checkerPT3 == 1) //if the checked value can only be in this one place it must be THE value
								{
									input[counterR][counterC] = checker[counterR][counterC][counterZ];
									printf("Replaced row:%d column:%d with %d\n", counterR + 1, counterC + 1, checker[counterR][counterC][counterZ]);
									continue;
								}
								checkerPT3 = 0;
							}

							//top middle 3x3
							if (counterC > 2 && counterC <= 5)
							{
								for (down2 = 0; down2 <= 2; down2++)
								{
									for (across2 = 3; across2 <= 5; across2++)
									{
										if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
											checkerPT3++; //will bring min value for checkerPT3 up to 3
									}
								}
								if (checkerPT3 == 1) //if the checked value can only be in this one place it must be THE value
								{
									input[counterR][counterC] = checker[counterR][counterC][counterZ];
									printf("Replaced row:%d column:%d with %d\n", counterR + 1, counterC + 1, checker[counterR][counterC][counterZ]);
									continue;
								}
								checkerPT3 = 0;
							}

							//top right 3x3
							if (counterC > 5)
							{
								for (down2 = 0; down2 <= 2; down2++)
								{
									for (across2 = 6; across2 <= 8; across2++)
									{
										if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
											checkerPT3++; //will bring min value for checkerPT3 up to 3
									}
								}
								if (checkerPT3 == 1) //if the checked value can only be in this one place it must be THE value
								{
									input[counterR][counterC] = checker[counterR][counterC][counterZ];
									printf("Replaced row:%d column:%d with %d\n", counterR + 1, counterC + 1, checker[counterR][counterC][counterZ]);
									continue;
								}
								checkerPT3 = 0;
							}
						}

						//middle 3x3 row
						if (counterR > 2 && counterR <= 5)
						{
							//Middle left 3x3
							if (counterC <= 2)
							{
								for (down2 = 3; down2 <= 5; down2++)
								{
									for (across2 = 0; across2 <= 2; across2++)
									{
										if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
											checkerPT3++; //will bring min value for checkerPT3 up to 3
									}
								}
								if (checkerPT3 == 1) //if the checked value can only be in this one place it must be THE value
								{
									input[counterR][counterC] = checker[counterR][counterC][counterZ];
									printf("Replaced row:%d column:%d with %d\n", counterR + 1, counterC + 1, checker[counterR][counterC][counterZ]);
									continue;
								}
								checkerPT3 = 0;
							}

							//Middle middle 3x3
							if (counterC > 2 && counterC <= 5)
							{
								for (down2 = 3; down2 <= 5; down2++)
								{
									for (across2 = 3; across2 <= 5; across2++)
									{
										if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
											checkerPT3++; //will bring min value for checkerPT3 up to 3
									}
								}
								if (checkerPT3 == 1) //if the checked value can only be in this one place it must be THE value
								{
									input[counterR][counterC] = checker[counterR][counterC][counterZ];
									printf("Replaced row:%d column:%d with %d\n", counterR + 1, counterC + 1, checker[counterR][counterC][counterZ]);
									continue;
								}
								checkerPT3 = 0;
							}

							//Middle right 3x3
							if (counterC > 5)
							{
								for (down2 = 3; down2 <= 5; down2++)
								{
									for (across2 = 6; across2 <= 8; across2++)
									{
										if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
											checkerPT3++; //will bring min value for checkerPT3 up to 3
									}
								}
								if (checkerPT3 == 1) //if the checked value can only be in this one place it must be THE value
								{
									input[counterR][counterC] = checker[counterR][counterC][counterZ];
									printf("Replaced row:%d column:%d with %d\n", counterR + 1, counterC + 1, checker[counterR][counterC][counterZ]);
									continue;
								}
								checkerPT3 = 0;
							}

						}

						//bottom 3x3 row
						if (counterR > 5)
						{
							//bottom left 3x3
							if (counterC <= 2)
							{
								for (down2 = 6; down2 <= 8; down2++)
								{
									for (across2 = 0; across2 <= 2; across2++)
									{
										if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
											checkerPT3++; //will bring min value for checkerPT3 up to 3
									}
								}
								if (checkerPT3 == 1) //if the checked value can only be in this one place it must be THE value
								{
									input[counterR][counterC] = checker[counterR][counterC][counterZ];
									printf("Replaced row:%d column:%d with %d\n", counterR + 1, counterC + 1, checker[counterR][counterC][counterZ]);
									continue;
								}
								checkerPT3 = 0;
							}

							//bottom middle 3x3
							if (counterC > 2 && counterC <= 5)
							{
								for (down2 = 6; down2 <= 8; down2++)
								{
									for (across2 = 3; across2 <= 5; across2++)
									{
										if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
											checkerPT3++; //will bring min value for checkerPT3 up to 3
									}
								}
								if (checkerPT3 == 1) //if the checked value can only be in this one place it must be THE value
								{
									input[counterR][counterC] = checker[counterR][counterC][counterZ];
									printf("Replaced row:%d column:%d with %d\n", counterR + 1, counterC + 1, checker[counterR][counterC][counterZ]);
									continue;
								}
								checkerPT3 = 0;
							}

							//bottom right 3x3
							if (counterC > 5)
							{
								for (down2 = 6; down2 <= 8; down2++)
								{
									for (across2 = 6; across2 <= 8; across2++)
									{
										if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
											checkerPT3++; //will bring min value for checkerPT3 up to 3
									}
								}
								if (checkerPT3 == 1) //if the checked value can only be in this one place it must be THE value
								{
									input[counterR][counterC] = checker[counterR][counterC][counterZ];
									printf("Replaced row:%d column:%d with %d\n", counterR + 1, counterC + 1, checker[counterR][counterC][counterZ]);
									continue;
								}
								checkerPT3 = 0;
							}
						}


					}
					else
						continue;

					//printf("checkerPT3:%d\n", checkerPT3);
					//if (checkerPT3 == 3)
					//{
						//input[counterR][counterC] = checker[counterR][counterC][counterZ];
						//printf("Replaced row:%d column:%d with %d\n", counterR+1, counterC+1, checker[counterR][counterC][counterZ]);
						//continue;
					//}
					//else
						//continue;
				} //end of counterZ
			} //end of counterC
		} //end of counterR



	//SUDOKU PUZZLE EVALUATION METHOD 3:
		//Candidate Lines: eliminates penciled numbers by checking for specific patterns of penciled numbers.
		//note, does not write to input, only removes values from checker

		//checks the 3x3 of the current block and number for 2 or 3 of that number only.
		for (counterR = 0; counterR <= 8; counterR++)
		{
			for (counterC = 0; counterC <= 8; counterC++)
			{
				for (counterZ = 0; counterZ <= 8; counterZ++)
				{
					if (checker[counterR][counterC][counterZ] == 0)
						continue;

					//top 3x3 row
					if (counterR <= 2)
					{

						//Top left 3x3
						if (counterC <= 2)
						{

							for (down2 = 0; down2 <= 2; down2++)
							{
								for (across2 = 0; across2 <= 2; across2++)
								{
									//printf("I am here");
									if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
										checkerPT4++;
									else
										continue;
								}
							}
							//printf("checkerPT4:%d\n", checkerPT4);
						}


						//top middle 3x3
						if (counterC > 2 && counterC <= 5)
						{
							for (down2 = 0; down2 <= 2; down2++)
							{
								for (across2 = 3; across2 <= 5; across2++)
								{
									if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
										checkerPT4++;
								}
							}
						}

						//top right 3x3
						if (counterC > 5)
						{
							for (down2 = 0; down2 <= 2; down2++)
							{
								for (across2 = 6; across2 <= 8; across2++)
								{
									if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
										checkerPT4++;
								}
							}
						}
						//Top left 3x3
						if (counterC <= 2)
						{
							for (down2 = 0; down2 <= 2; down2++)
							{
								for (across2 = 0; across2 <= 2; across2++)
								{
									if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
										checkerPT4++;
								}
							}
						}

						//top middle 3x3
						if (counterC > 2 && counterC <= 5)
						{
							for (down2 = 0; down2 <= 2; down2++)
							{
								for (across2 = 3; across2 <= 5; across2++)
								{
									if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
										checkerPT4++;
								}
							}
						}

						//top right 3x3
						if (counterC > 5)
						{
							for (down2 = 0; down2 <= 2; down2++)
							{
								for (across2 = 6; across2 <= 8; across2++)
								{
									if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
										checkerPT4++;
								}
							}

						}
					}

					//middle 3x3 row
					if (counterR > 3 && counterR <= 5)
					{
						//Middle left 3x3
						if (counterC <= 2)
						{
							for (down2 = 3; down2 <= 5; down2++)
							{
								for (across2 = 0; across2 <= 2; across2++)
								{
									if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
										checkerPT4++;
								}
							}
						}

						//Middle middle 3x3
						if (counterC > 2 && counterC <= 5)
						{
							for (down2 = 3; down2 <= 5; down2++)
							{
								for (across2 = 3; across2 <= 5; across2++)
								{
									if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
										checkerPT4++;
								}
							}
						}

						//Middle right 3x3
						if (counterC > 5)
						{
							for (down2 = 3; down2 <= 5; down2++)
							{
								for (across2 = 6; across2 <= 8; across2++)
								{
									if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
										checkerPT4++;
								}
							}
						}

					}

					//bottom 3x3 row
					if (counterR > 5)
					{
						//bottom left 3x3
						if (counterC <= 2)
						{
							for (down2 = 6; down2 <= 8; down2++)
							{
								for (across2 = 0; across2 <= 2; across2++)
								{
									if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
										checkerPT4++;
								}
							}
						}

						//bottom middle 3x3
						if (counterC > 2 && counterC <= 5)
						{
							for (down2 = 6; down2 <= 8; down2++)
							{
								for (across2 = 3; across2 <= 5; across2++)
								{
									if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
										checkerPT4++;
								}
							}
						}

						//bottom right 3x3
						if (counterC > 5)
						{
							for (down2 = 6; down2 <= 8; down2++)
							{
								for (across2 = 6; across2 <= 8; across2++)
								{
									if (checker[down2][across2][counterZ] == checker[counterR][counterC][counterZ])
										checkerPT4++;
								}
							}
						}
					}
					//end of 3x3 checking

					//defines 'location' variable
					if (counterR == 0 || counterR == 3 || counterR == 6)
					{
						if (counterC == 0 || counterC == 3 || counterC == 6)
							location = 1;
						if (counterC == 1 || counterC == 4 || counterC == 7)
							location = 4;
						if (counterC == 2 || counterC == 5 || counterC == 8)
							location = 7;
					}
					if (counterR == 1 || counterR == 4 || counterR == 7)
					{
						if (counterC == 0 || counterC == 3 || counterC == 6)
							location = 2;
						if (counterC == 1 || counterC == 4 || counterC == 7)
							location = 5;
						if (counterC == 2 || counterC == 5 || counterC == 8)
							location = 8;
					}
					if (counterR == 2 || counterR == 5 || counterR == 8)
					{
						if (counterC == 0 || counterC == 3 || counterC == 6)
							location = 3;
						if (counterC == 1 || counterC == 4 || counterC == 7)
							location = 6;
						if (counterC == 2 || counterC == 5 || counterC == 8)
							location = 9;
					}


					if (checkerPT4 == 3 || checkerPT4 == 2)
					{
						//at home used checkerPT4 for number of one number in a given 3x3

						//top left
						if (location == 1) //counterR +1,+2    counterC +1,+2
						{
							//check across
							if (checker[counterR][counterC][counterZ] == checker[counterR][counterC + 1][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR][counterC + 2][counterZ])
							{
								for (across3 = 0; across3 <= 8; across3++)
								{
									if (across3 != counterC && across3 != counterC + 1 && across3 != counterC + 2)
										checker[counterR][across3][counterZ] = 0;
								}
							}

							//check down
							if (checker[counterR][counterC][counterZ] == checker[counterR + 1][counterC][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR + 2][counterC][counterZ])
							{
								for (down3 = 0; down3 <= 8; down3++)
								{
									if (down3 != counterR && down3 != counterR + 1 && down3 != counterR + 2)
										checker[down3][counterC][counterZ] = 0;
								}
							}

						}

						//top middle 
						else if (location == 2) //counterR +1,+2	counterC -1,+1
						{
							//check across
							if (checker[counterR][counterC][counterZ] == checker[counterR][counterC + 1][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR][counterC - 1][counterZ])
							{
								for (across3 = 0; across3 <= 8; across3++)
								{
									if (across3 != counterC && across3 != counterC + 1 && across3 != counterC - 1)
										checker[counterR][across3][counterZ] = 0;
								}
							}

							//check down
							if (checker[counterR][counterC][counterZ] == checker[counterR + 1][counterC][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR + 2][counterC][counterZ])
							{
								for (down3 = 0; down3 <= 8; down3++)
								{
									if (down3 != counterR && down3 != counterR + 1 && down3 != counterR + 2)
										checker[down3][counterC][counterZ] = 0;
								}
							}

						}

						//top right
						else if (location == 3) //counterR +1,+2	counterC -2,-1
						{
							//check across
							if (checker[counterR][counterC][counterZ] == checker[counterR][counterC - 1][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR][counterC - 2][counterZ])
							{
								for (across3 = 0; across3 <= 8; across3++)
								{
									if (across3 != counterC && across3 != counterC - 1 && across3 != counterC - 2)
										checker[counterR][across3][counterZ] = 0;
								}
							}

							//check down
							if (checker[counterR][counterC][counterZ] == checker[counterR + 1][counterC][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR + 2][counterC][counterZ])
							{
								for (down3 = 0; down3 <= 8; down3++)
								{
									if (down3 != counterR && down3 != counterR + 1 && down3 != counterR + 2)
										checker[down3][counterC][counterZ] = 0;
								}
							}

						}

						//middle left 
						else if (location == 4) //counterR -1,+1	counterC +1,+2
						{
							//check across
							if (checker[counterR][counterC][counterZ] == checker[counterR][counterC + 1][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR][counterC + 2][counterZ])
							{
								for (across3 = 0; across3 <= 8; across3++)
								{
									if (across3 != counterC && across3 != counterC + 1 && across3 != counterC + 2)
										checker[counterR][across3][counterZ] = 0;
								}
							}

							//check down
							if (checker[counterR][counterC][counterZ] == checker[counterR + 1][counterC][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR - 1][counterC][counterZ])
							{
								for (down3 = 0; down3 <= 8; down3++)
								{
									if (down3 != counterR && down3 != counterR + 1 && down3 != counterR - 1)
										checker[down3][counterC][counterZ] = 0;
								}
							}

						}

						//middle middle
						else if (location == 5) //counterR -1,+1	counterC -1,+1
						{
							//check across
							if (checker[counterR][counterC][counterZ] == checker[counterR][counterC - 1][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR][counterC + 1][counterZ])
							{
								for (across3 = 0; across3 <= 8; across3++)
								{
									if (across3 != counterC && across3 != counterC - 1 && across3 != counterC + 1)
										checker[counterR][across3][counterZ] = 0;
								}
							}

							//check down
							if (checker[counterR][counterC][counterZ] == checker[counterR + 1][counterC][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR - 1][counterC][counterZ])
							{
								for (down3 = 0; down3 <= 8; down3++)
								{
									if (down3 != counterR && down3 != counterR + 1 && down3 != counterR - 1)
										checker[down3][counterC][counterZ] = 0;
								}
							}

						}

						//middle right
						else if (location == 6) //counterR -1,+1	counterC -1,-2
						{
							//check across
							if (checker[counterR][counterC][counterZ] == checker[counterR][counterC - 1][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR][counterC - 2][counterZ])
							{
								for (across3 = 0; across3 <= 8; across3++)
								{
									if (across3 != counterC && across3 != counterC - 1 && across3 != counterC - 2)
										checker[counterR][across3][counterZ] = 0;
								}
							}

							//check down
							if (checker[counterR][counterC][counterZ] == checker[counterR + 1][counterC][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR - 1][counterC][counterZ])
							{
								for (down3 = 0; down3 <= 8; down3++)
								{
									if (down3 != counterR && down3 != counterR + 1 && down3 != counterR - 1)
										checker[down3][counterC][counterZ] = 0;
								}
							}
						}

						//bottom left
						else if (location == 7) //counterR -1,-2	counterC +1,+2
						{
							//check across
							if (checker[counterR][counterC][counterZ] == checker[counterR][counterC + 1][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR][counterC + 2][counterZ])
							{
								for (across3 = 0; across3 <= 8; across3++)
								{
									if (across3 != counterC && across3 != counterC + 1 && across3 != counterC + 2)
										checker[counterR][across3][counterZ] = 0;
								}
							}

							//check down
							if (checker[counterR][counterC][counterZ] == checker[counterR - 1][counterC][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR - 2][counterC][counterZ])
							{
								for (down3 = 0; down3 <= 8; down3++)
								{
									if (down3 != counterR && down3 != counterR - 1 && down3 != counterR - 2)
										checker[down3][counterC][counterZ] = 0;
								}
							}

						}

						//bottom middle
						else if (location == 8) //counterR -1,-2	counterC -1,+1
						{
							//check across
							if (checker[counterR][counterC][counterZ] == checker[counterR][counterC + 1][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR][counterC - 1][counterZ])
							{
								for (across3 = 0; across3 <= 8; across3++)
								{
									if (across3 != counterC && across3 != counterC - 1 && across3 != counterC + 1)
										checker[counterR][across3][counterZ] = 0;
								}
							}

							//check down
							if (checker[counterR][counterC][counterZ] == checker[counterR - 1][counterC][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR - 2][counterC][counterZ])
							{
								for (down3 = 0; down3 <= 8; down3++)
								{
									if (down3 != counterR && down3 != counterR - 1 && down3 != counterR - 2)
										checker[down3][counterC][counterZ] = 0;
								}
							}

						}

						//bottom right
						else if (location == 9) //counterR -1,-2	counterC -1,-2
						{
							//check across
							if (checker[counterR][counterC][counterZ] == checker[counterR][counterC - 1][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR][counterC - 2][counterZ])
							{
								for (across3 = 0; across3 <= 8; across3++)
								{
									if (across3 != counterC && across3 != counterC - 1 && across3 != counterC - 2)
										checker[counterR][across3][counterZ] = 0;
								}
							}

							//check down
							if (checker[counterR][counterC][counterZ] == checker[counterR - 1][counterC][counterZ] || checker[counterR][counterC][counterZ] == checker[counterR - 2][counterC][counterZ])
							{
								for (down3 = 0; down3 <= 8; down3++)
								{
									if (down3 != counterR && down3 != counterR - 1 && down3 != counterR - 2)
										checker[down3][counterC][counterZ] = 0;
								}
							}

						}
					}

				} //end of counterZ
			} //end of counterC
		} //end of counterZ

		sum = 0;
		//loop for summation. Adds the value in every block, if total is 405 or higher than the page is complete
		for (counterR = 0; counterR <= 8; counterR++)
		{
			for (counterC = 0; counterC <= 8; counterC++)
			{
				sum += input[counterR][counterC];
			}
		}

	}

	printf("\n\n\n");
	printf("This is the completed sudoku page\n");
	//prints the completed sudoku puzzle
	for (counterR = 0; counterR <= 8; counterR++)
	{
		for (counterC = 0; counterC <= 8; counterC++)
		{
			printf(" %d ", input[counterR][counterC]);
			if (counterC == 2 || counterC == 5)
				printf(" ");
		}
		printf("\n");
		if (counterR == 2 || counterR == 5)
			printf("\n");
	}



	printf("\n");
	return 0;
}
