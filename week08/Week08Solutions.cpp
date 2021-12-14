#include<iostream>
using namespace std;
const int MAXSIZE = 100;
//task 1
void swapValues(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swapValues(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//task 2
bool increasingElements(int array[100], int size)
{
	for (int i = 0; i < size-1; i++)
	{
		if (array[i] > array[i + 1])
		{
			return false;
		}
		
	}
	return true;
}

//task 3
int* reverseArray(int* arr, int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		swap(arr[i], arr[size - 1 - i]);
	}
	return arr;
}

// task4 
void sort(int* array, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				swap(array[i], array[j]);
			}
		}
	}
}

//task5
void merge(int* arr1, int arr1Size, int* arr2, int arr2Size, int* arr3)
{
	int counter1 = 0;
	int counter2 = 0;
	for (int i = 0; i < arr1Size + arr2Size; i++)
	{
		if (counter1 == arr1Size)
		{
			for (int k = counter1 + counter2; k < arr1Size + arr2Size; k++)
			{
				arr3[k] = arr2[counter2];
				counter2++;
			}
			return;
		}
		if (counter2 == arr2Size)
		{
			for (int k = counter1 + counter2; k < arr1Size + arr1Size; k++)
			{
				arr3[k] = arr1[counter1];
				counter1++;
			}
			return;
		}
		if (arr1[counter1] < arr2[counter2])
		{
			arr3[i] = arr1[counter1];
			counter1++;
		}
		else
		{
			arr3[i] = arr2[counter2];
			counter2++;
		}
	}
}

//task6
void transposed(int matrixOne[MAXSIZE][MAXSIZE], int rowsOne, int cowsOne, int matrixTwo[MAXSIZE][MAXSIZE], int rowsTwo, int colsTwo)
{
	for (int i = 0; i < rowsOne; i++)
	{
		for (int j = 0; j < rowsTwo; j++)
		{
			matrixTwo[j][i] = matrixOne[i][j];
		}
	}
}

//task7
int* findDigit(int* arr, int size, int number)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == number)
		{
			return (arr + i);
		}
	}
	return nullptr;
}

//task8
int sumOfDigit(int number)
{
	int sum = 0;
	while (number != 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

void digitSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (sumOfDigit(arr[i]) > sumOfDigit(arr[j]))
			{
				swap(arr[i], arr[j]);
			}
			if (sumOfDigit(arr[i]) == sumOfDigit(arr[j]))
			{
				if (arr[j] < arr[i])
				{
					swap(arr[i], arr[j]);
				}
			}
		}
	}
}

int main()
{
	return 0;
}


