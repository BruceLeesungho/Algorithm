#define _CRT_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
#include <vector>

using namespace std;

int DP[14 + 1][14 + 1];

int T, a, b;

void init_DP(void)
{
	for (int i = 0; i <= 14; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			if (i == 0) DP[i][j] = j;
			else
			{
				DP[i][j] = DP[i][j - 1] + DP[i - 1][j];
			}
		}
	}
}


int main(void)
{
	cin >> T;

	init_DP();



	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;
		cout << DP[a][b] << '\n';
	}


	return 0;
}