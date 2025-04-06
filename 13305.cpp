#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dist[100000];
int maeul[100000+1];
int N;

int main(void)
{
	cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		cin >> dist[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> maeul[i];
	}

	long long result = 0;

	//다음 마을 갈때 그 마을 전 애들중 result += (최소값 * 거리)
	for (int i = 0; i < N-1; i++)
	{
		int minmin = *min_element(maeul, maeul + i+1);
		result += (long long)dist[i] * (long long)minmin;
	}

	cout << result;
	return 0;
}