#include <iostream>
#include <string>
#include "SolveSudoku.h"

using namespace std;

int sudoku[9][9];

bool findEmptyPlace(int &row, int &col) // piek��st caur adresi
{
	for (row = 0; row < 9; row++)
		for (col = 0; col < 9; col++)
			if (sudoku[row][col] == 0) //tuk�s lauks
				return true;
	return false;
}

bool isPresentInRow(int row, int number)
{
	for (int col = 0; col < 9; col++)
		if (sudoku[row][col] == number)
			return true;
	return false;
}

bool isPresentInColumn(int col, int number)
{
	for (int row = 0; row < 9; row++)
		if (sudoku[row][col] == number)
			return true;
	return false;
}

bool isPresentInBox(int startRow, int startCol, int number)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (sudoku[row + startRow][col + startCol] == number)
				return true;
	return false;
}

bool canBePlaced(int row, int col, int number)
{
	if (!isPresentInRow(row, number))
		if (!isPresentInColumn(col, number))
			if (!isPresentInBox(row - row%3, col - col%3, number)) // katra bloka s�kums (0,0) (0,3) (0,6) (3,0) utt
				return true;
	return false;
}

void sudokuArray()
{ 
	char sudokuArray[162];
	int k = 0; // iterators

	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			/*sudokuArray[k] = sudoku[row][col];
			sudokuArray[k+1] = ' ';
			k += 2;*/
			cout << sudoku[row][col] << " ";
		}
	}

	//return sudokuArray;
}

bool solveSudoku()
{
	// Sudoku risin��ana

	int row, col; // Koordin�ta laukam, kuram m��ina izdom�t, k�ds cipars j�ieraksta

	if (!findEmptyPlace(row, col))
		return true; // Kad visi tuk�ie lauki aizpild�ti

	for (int number = 1; number <= 9; number++) // Mekl�, kur ievietot pa skait�iem
	{
		if (canBePlaced(row, col, number))
		{
			sudoku[row][col] = number;
			if (solveSudoku()) return true;
			sudoku[row][col] = 0;
		}
	}

	return false;
}

bool solveSudoku(char sudokuString[])
{
	int k = 0; // iterators
	int number;

	// Izveido 2D mas�vu
	for (int i = 0; i < 9; i++) // rindas
	{
		for (int j = 0; j < 9; j++) // kolonnas
		{
			string s(1, sudokuString[k]);
			number = stoi(s);
			sudoku[i][j] = number;
			k += 2; // Izlai� atstarpes
		}
	}

	// Sudoku risin��ana

	return solveSudoku();
}