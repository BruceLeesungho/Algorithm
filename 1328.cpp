#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, L, R;
long long DP[100 + 1][100 + 1][100 + 1];



void init_DP()
{
	DP[1][1][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= L; j++)
		{
			for (int k = 1; k <= R; k++)
			{
				if (j == 1) DP[i - 1][j - 1][k] = 0;
				if (k == 1) DP[i - 1][j][k - 1] = 0;

				DP[i][j][k] = DP[i-1][j - 1][k] + DP[i-1][j][k - 1] + DP[i - 1][j][k] * (i - 2);
				DP[i][j][k] %= 1000000007;
			}
		}
	}
}


int main(void)
{
	cin >> N >> L >> R;
	//1000000007;
	init_DP();

	cout << DP[N][L][R];

	return 0;
}