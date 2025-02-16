#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int DP[100001][5][5];
int mp[5][5] = 
{
	{0,2,2,2,2},
	{0,1,3,4,3},
	{0,3,1,3,4},
	{0,4,3,1,3},
	{0,3,4,3,1}
};

int main(void)
{
	int n = 1;
	int s = 1;
	for (int k = 0; k < 100001; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				DP[k][i][j] = 0x7ffffff;
			}
		}
	}
	DP[0][0][0] = 0;


	while (n != 0)
	{
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < 5; i++) //현재 내 왼발 위치
		{
			if (n == i) continue;
			for (int j = 0; j < 5; j++)//현재 내 오른발 위치
			{
				DP[s][i][n] = min(DP[s][i][n], DP[s - 1][i][j] + mp[j][n]);
			}
		}

		for (int i = 0; i < 5; i++) //현재 내 오른발 위치
		{
			if (n == i) continue;
			for (int j = 0; j < 5; j++)//현재 내 왼발 위치
			{
				DP[s][n][i] = min(DP[s][n][i], DP[s - 1][i][j] + mp[j][n]);
			}
		}	


		s++;
	}

	s--;
	
	int minmin = 0x7fffffff;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			minmin = min(minmin, DP[s][i][j]);
		}
	}

	cout << minmin;


	return 0;
}