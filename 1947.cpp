#define _CRT_SECURE_NOWARNIGS
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

long long DP[1000000 + 1];

int N;

void init_DP(int n)
{
	for (int i = 3; i <= n; i++)
	{
		//DP[i] = (i - 1) * (DP[i - 1] % 1000000000 + DP[i - 2] % 1000000000) ;
		DP[i] = ((i - 1) * (DP[i - 1] + DP[i - 2])) % 1000000000;
	}
}


int main(void)
{
	cin >> N;
	DP[0] = 0;
	DP[1] = 0;
	DP[2] = 1;
	init_DP(N);


	cout << DP[N];
	return 0;
}
