#include "printing.h"
#include <iostream>
#include <iomanip>



void print_matrix(matrix mat, int size)
{

	std::cout << std::endl << std::endl;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 1; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (j > i && mat[i][j] == 1)
			{
				system("Color 0B");
			}
			else
			{
				system("Color 08");
			}
			std::cout << std::setw(7) << mat[i][j];
		}
		std::cout << std::endl << std::endl;
	}

	system("cls");


	SetConsoleTextAttribute(hConsole, 176);
	std::cout << std::endl << std::endl;
	for (int i = 0; i <= size; ++i)
	{
		for (int j = 0; j <=  size; ++j)
		{
			if (i == 0 && j == 0)
			{
				SetConsoleTextAttribute(hConsole, 187);
				std::cout << "       ";
			}
			if (i == 0 && j != 0)
			{
				SetConsoleTextAttribute(hConsole, 176);
				std::cout << std::setw(7) << j;
			}
			else if (i != 0 && j == 0)
			{
				SetConsoleTextAttribute(hConsole, 176);
				std::cout << std::setw(7) << i;
			}
			else if (j > i && mat[i][j] == 1)
			{
				SetConsoleTextAttribute(hConsole, 11);
				std::cout << std::setw(7) << mat[i][j];
			}
			else if (i != 0)
			{
				SetConsoleTextAttribute(hConsole, 8);
				std::cout << std::setw(7) << mat[i][j];
			}
			
		}
		std::cout << std::endl << std::endl;
	}
}