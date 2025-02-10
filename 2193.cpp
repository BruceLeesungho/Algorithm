#define _CRT_NO_WARNINGS
#include <iostream>

using namespace std;

int N;

int DP[90 + 1];
int hap[90 + 1];

void make_dp(int n);

int main(void)
{
	cin >> N;

	DP[0] = 1;
	DP[1] = 1;
	DP[2] = 1;

	hap[0] = 1;
	hap[1] = 2;
	hap[2] = 3;

	make_dp(N);

	if (N <= 3) cout << DP[N];
	else cout << hap[N - 2];

	return 0;
}

void make_dp(int n)
{
	for (int i = 3; i <= n; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
		hap[i] = hap[i-1] + DP[i];
	}
	
}