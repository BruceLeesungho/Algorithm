#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#define MAX_N (100+1)

using namespace std;


int N;
int adj_mat[MAX_N][MAX_N];
int result[MAX_N][MAX_N];
void Floyd_Warshall(void);



int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int c;
			cin >> c;
			adj_mat[i][j] = c;
			result[i][j] = 0;
		}
	}

	Floyd_Warshall();



	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << adj_mat[i][j]<< ' ';
		}
		cout << '\n';
	}



	return 0;
}

void Floyd_Warshall(void)
{
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j= 0; j < N; j++)
			{
				if (adj_mat[i][k] == 1 && adj_mat[k][j] == 1) adj_mat[i][j] = 1;
			}
		}
	}
}