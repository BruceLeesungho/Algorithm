#define _CRT_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;

int N, K;
int DP[10 + 1][10 + 1];

int main(void)
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			if (j == 0) DP[i][j] = 1;
			if (i == j) DP[i][j] = 1;
			if (j == 1) DP[i][j] = i;
		}
	}


	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= K; j++)
		{
			DP[i][j] = DP[i - 1][j] + DP[i - 1][j - 1];
		}
	}


	cout << DP[N][K];


	return 0;
}