#include <iostream>
using namespace std;

void findAverage (int arr[][4], int rows, float arr1[])
{
	for(int i = 0;i < rows;i++)
	{
		int total = 0;
		for(int k = 0;k < 4; k++)
		{
			total = total+arr[i][k];
		}
		arr1[i]=(float)total/4;
	}
	cout<<"Average of rows : ";
	for (int i = 0;i < rows;i++)
	{
		cout<<arr1[i]<<" ";
	}
}

int main()
{
	const int rows=5;
	int arr[rows][4]={{98,90,95,100},
			{80,85,100,97},
			{60,68,80,98},
			{78,68,90,80},
			{90,95,85,83}};
	float arr1[rows];

	findAverage(arr, rows, arr1);

	return 0;
}
