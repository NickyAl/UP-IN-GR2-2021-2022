#include <iostream>
#include<iomanip>
using namespace std;
const int MAXSIZE = 50;
const int TICTACTOESIZE = 3;
const int CHESSSIZE = 8;
void inputMatrix(int matrix[][MAXSIZE], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void inputMatrix(int matrix[][MAXSIZE], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void inputMatrix(bool matrix[][CHESSSIZE], const int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void printMatrix(int matrix[][MAXSIZE], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

void printMatrix(short matrix[][TICTACTOESIZE], const int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

bool isSubset(int* firstArr, int* secondArr, int size1, int size2)
{
	int j = 0;
	for (int i = 0; i < size1; i++)
	{
		for (j = 0; j < size2; j++)
		{
			if (firstArr[i] == secondArr[j]) // there is element of firstArr that is equal to element of secondArr
			{
				break;
			}
		}
		if (j == size2)
		{
			return false;
		}
	}
	return true;
}

void switchCols(int matrix[][MAXSIZE], int size)
{
	int tempArr[MAXSIZE];
	for (int i = 0; i < size; i++)
	{
		tempArr[i] = matrix[i][size - 1];
	}
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[j][i] = matrix[j][i - 1];
		}
	}
	for (int i = 0; i < size; i++)
	{
		matrix[i][0] = tempArr[i];
	}
}

void switchRows(int matrix[][MAXSIZE], int size)
{
	int tempArr[MAXSIZE];
	for (int i = 0; i < size; i++)
	{
		tempArr[i] = matrix[size - 1][i];
	}
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = matrix[i - 1][j];
		}
	}
	for (int i = 0; i < size; i++)
	{
		matrix[0][i] = tempArr[i];
	}
}

bool isValidChessCoordinates(int col, int row)
{
	return col >= 0 && col < 8 && row >= 0 && row < 8;
}

bool hasEqualElementsOnRow(short board[TICTACTOESIZE][TICTACTOESIZE], int size)
{

	for (int i = 0; i < size; i++)
	{
		bool hasEqualElementsOnRows = true;
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == 0)
			{
				hasEqualElementsOnRows = false;
			}
		}
		if (hasEqualElementsOnRows)
		{
			return true;
		}
	}
	return false;
}
bool hasEqualElementsOnCol(short board[TICTACTOESIZE][TICTACTOESIZE], int size)
{
	for (int i = 0; i < size; i++)
	{
		bool hasEqualElementsOnCols = true;
		for (int j = 0; j < size; j++)
		{
			if (board[j][i] == 0)
			{
				hasEqualElementsOnCols = false;
			}
		}
		if (hasEqualElementsOnCols)
		{
			return true;
		}
	}
	return false;
}
bool hasEqualElementsOnDiagonals(short board[TICTACTOESIZE][TICTACTOESIZE], int size)
{
	bool hasEqualElementsOnFirstDiag = true;
	bool hasEqualElementsOnSecondDiag = true;
	for (int i = 0; i < size; i++)
	{
		if (board[i][i] == 0)
		{
			hasEqualElementsOnFirstDiag = false;
		}
		if (board[i][size - 1 - i] == 0)
		{
			hasEqualElementsOnSecondDiag = false;
		}
	}
	return hasEqualElementsOnFirstDiag || hasEqualElementsOnSecondDiag;
}
bool hasWinner(short board[TICTACTOESIZE][TICTACTOESIZE], int size)
{
	return hasEqualElementsOnCol(board, size) || hasEqualElementsOnDiagonals(board, size) || hasEqualElementsOnRow(board, size);
}

int main()
{
	//task 1
	/* int matrix[MAXSIZE][MAXSIZE];
	  int size,sum=0;
	  cin >> size;
	  inputMatrix(matrix, size);
	  for (int i = 0; i < size; i++)
	  {
		  for (int j = 0; j < size; j++)
		  {
			  sum += matrix[i][j];
		  }
	  }
	  cout << "Sum of matrix elements : " << sum << " average  of matrix elements: " << setprecision(2)<< sum*1.0 / (size * size);*/

	  //task 2
	  /*bool diagonal = true;
	  bool underDiagonal = true;
	  bool overDiagonal = true;
	  int matrix[MAXSIZE][MAXSIZE];
	  int size, sum = 0;
	  cin >> size;
	  inputMatrix(matrix, size);
	  for (int i = 0; i < size; i++)
	  {
		  for (int j = 0; j < size; j++)
		  {
			  if (i == j)
			  {
				  if (matrix[i][j] % 3 != 0)
				  {
					  diagonal = false;
				  }
			  }
			  if (i > j)
			  {
				  if (matrix[i][j] % 2 != 0)
				  {
					  underDiagonal = false;
				  }
			  }
			  if (i < j)
			  {
				  if (matrix[i][j] % 4 != 0)
				  {
					  underDiagonal = false;
				  }
			  }
		  }
	  }
	  if (diagonal && overDiagonal && underDiagonal)
	  {
		  for (int i = 0; i < size; i++)
		  {
			  for (int j = 0; j < size; j++)
			  {
				  if (i == j)
				  {
					  sum += matrix[i][j] / 3;
				  }
				  if (i > j)
				  {
					  sum += matrix[i][j] / 2;
				  }
				  if (i < j)
				  {
					  sum += matrix[i][j] / 4;
				  }
			  }
		  }
		  cout << sum;
	  }
	  else
	  {
		  cout << "Elements does not meet the requirements.";
	  }*/

	  //task 3
	  /*int matrix[MAXSIZE][MAXSIZE];
		int size;
		cin >> size;
		inputMatrix(matrix, size);
		for (int j = 0; j < size; j++)
		{
			int i = -1;
			do
			{
				i++;
			}
			while (matrix[i][j] == matrix[j][i] && i < size - 1);
			if (matrix[i][j] == matrix[j][i])
			cout << j;
		}*/

		//task 4
	/*bool hasSubSequences = false;
	int matrix[MAXSIZE][MAXSIZE];
	int size;
	cin >> size;
	int countOfEqualDigits = 0;
	inputMatrix(matrix, size);
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (isSubset(matrix[i], matrix[j], size, size))
			{
				hasSubSequences = true;
			}
		}
	}
	cout << boolalpha << hasSubSequences;*/

	//task 5
	/*int matrix[MAXSIZE][MAXSIZE];
	int size;
	cin >> size;
	inputMatrix(matrix, size);
	int rowsOfset, colsOfset;
	cin >> rowsOfset >> colsOfset;
	int rowsRotations = rowsOfset % size;
	int colsRotations = colsOfset % size;
	for (int i = 0; i < rowsRotations; i++)
	{
		switchRows(matrix, size);
	}
	for (int j = 0; j < colsRotations; j++)
	{
		switchCols(matrix, size);
	}
	printMatrix(matrix, size);*/
	//task 6

	/*bool board[CHESSSIZE][CHESSSIZE];
	inputMatrix(board, CHESSSIZE);
	int row, col;
	cin >> row >> col;
	int countOfPossiblePositions = 0;
	if (isValidChessCoordinates(row + 2, col + 1) && board[row + 2][col + 1] == 1)
		countOfPossiblePositions++;
	if (isValidChessCoordinates(row + 1, col + 2) && board[row + 1][col + 2] == 1)
		countOfPossiblePositions++;
	if (isValidChessCoordinates(row + 2, col - 1) && board[row + 2][col - 1] == 1)
		countOfPossiblePositions++;
	if (isValidChessCoordinates(row + 1, col - 2) && board[row + 1][col - 2] == 1)
		countOfPossiblePositions++;
	if (isValidChessCoordinates(row - 2, col + 1) && board[row - 2][col + 1] == 1)
		countOfPossiblePositions++;
	if (isValidChessCoordinates(row -1 , col + 2) && board[row -1][col +2 ] == 1)
		countOfPossiblePositions++;
	if (isValidChessCoordinates(row - 1, col - 2) && board[row -1 ][col - 2] == 1)
		countOfPossiblePositions++;
	if (isValidChessCoordinates(row - 2, col - 1) && board[row - 2][col - 1] == 1)
		countOfPossiblePositions++;
	cout << "There are " << countOfPossiblePositions << " possible moves.";*/

	//task 7

	short board[TICTACTOESIZE][TICTACTOESIZE] = { 0 };
	int row, col;
	int move = 0;
	printMatrix(board, TICTACTOESIZE);
	while (!hasWinner(board, TICTACTOESIZE))
	{
		do 
		{
			cin >> row >> col;
		} while ((row<0 || row>TICTACTOESIZE - 1) || (col<0 || col>TICTACTOESIZE - 1));
		board[row][col] = move % 2 + 1;
		move++;
		printMatrix(board, TICTACTOESIZE);
	}
	cout << "Plater " << move % 2 << " wins" << endl;
	return 0;
}