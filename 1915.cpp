#define _CRT_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int DP[1000 + 1][1000 + 1];
string SQ[1000 + 1];
int N, M;
int MAX_result = 0;

void Make_DP(void);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> SQ[i];
		for (int j = 0; j < M; j++) DP[i][j] = 0;
	}

	Make_DP();

	cout << MAX_result*MAX_result;


	return 0;
}

void Make_DP(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (SQ[i][j] == '1')
			{
				if (i - 1 < 0 || j - 1 < 0)
				{
					if (MAX_result == 0) MAX_result = 1;
					DP[i][j] = 1;
					continue;
				}
				int a, b, c, d;
				
				b = DP[i][j - 1]; //¿Þ
				c = DP[i - 1][j]; // À§
				d = DP[i - 1][j - 1]; //¿ÞÀ§

				a = min({b,c,d});
				DP[i][j] = a + 1;
				if (a + 1 > MAX_result) MAX_result = a + 1;
			}
		}
	}
	return;
}


