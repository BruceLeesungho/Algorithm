#define _CRT_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

int N;
int T[15 + 1];
int P[15 + 1];
int DP[15 + 1];

void make_dp(void)
{
	for (int i = N; i > 0; i--)
	{
		if (i + T[i] > N + 1) DP[i] = DP[i + 1]; //선택못함.
		else
		{
			DP[i] = max(DP[i + 1], DP[T[i] + i] + P[i]);
		}
	}

}


int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}
	DP[N + 1] = 0;
	make_dp();

	cout << DP[1];

	return 0;
}