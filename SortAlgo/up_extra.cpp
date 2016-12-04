// up_extra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

// Buble sort
void sort(int arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
	}
}

void print(int arr[], int size)
{
	for (std::size_t index = 0; index < size; ++index)
	{
		std::cout << arr[index] << " ";
	}
}







int main()
{
	int arr[] = { 1, 5, 0, 3 };

	sort(arr, 4);

	print(arr, 4);

	std::cout << std::endl;

    return 0;
}


//int rows = 5;
//int cols = 5;

//int matrix[5][5] = { {1,2,3,4,5},
//					{6,7,8,9,10 },
//					{11,12,13,14,15},
//					{ 16,17,18,19,20 },
//					{ 21,22,23,24,25} };
//
//int currentColumn = 0;
//int currentRow = 0;

//while (currentColumn < cols && currentRow < rows)
//{
//	for (int j = currentRow; j < cols; j++)
//	{
//		cout << matrix[currentRow][j] << " ";
//	}
//	currentRow++;

//	for (int i = currentRow; i < rows; i++)
//	{
//		cout << matrix[i][cols - 1] << " ";
//	}
//	cols--;

//	for (int i = cols - 1; i >= currentColumn; i--)
//	{
//		cout << matrix[rows - 1][i] << " ";
//	}
//	rows--;

//	for (int i = rows - 1; i >= currentRow; i--)
//	{
//		cout << matrix[i][currentColumn] << " ";
//	}
//	currentColumn++;

//}