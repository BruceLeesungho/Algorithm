#define _CRT_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

int N;

int DP[1000000 + 1];
void make_DP(void);
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	
	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 1;

	make_DP();


	cout << DP[N];

	return 0;
}

void make_DP(void)
{
	for (int i = 3; i <= N; i++)
	{
		int minmin = 0x7fffffff;
		if (DP[i - 1] + 1 < minmin) minmin = DP[i - 1] + 1; //-1한 경우
		
		if (i % 2 == 0)//2로 나뉠경우
		{
			if (DP[i / 2] + 1 < minmin) minmin = DP[i / 2] + 1;
		}

		if (i % 3 == 0)
		{
			if (DP[i / 3] + 1 < minmin) minmin = DP[i / 3] + 1;
		}

		DP[i] = minmin;

	}
}