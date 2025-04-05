#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int DP[15 + 2];
int T[15 + 2];
int P[15 + 2];

int N;

int main(void)
{
	int maxmax = 0;

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}
	
	DP[N+1] = 0;
	

	for (int i = N; i > 0; i--)
	{
		int a = 0;
		int b = 0;
		a = DP[i + 1];

		if (T[i] + i - 1 <= N)
		{
			b = DP[i + T[i]] + P[i];
		}

		int c = max(a, b);
		DP[i] = c;
		if (c > maxmax) maxmax = c;
	}

	cout << maxmax;

	return 0;
}