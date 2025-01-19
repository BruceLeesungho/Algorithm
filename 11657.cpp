#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define MAX_N (501)

using namespace std;

int N, M;
vector<pair<int, int>> Edge[MAX_N];
long long result[MAX_N];
int minus_cycle;
void Vel_Ford(void);

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		Edge[s].push_back({ e, w });
	}
	for (int i = 1; i <= N; i++)
	{
		result[i] = 2100000000;
	}
	result[1] = 0;
	minus_cycle = 0;

	Vel_Ford();

	if (minus_cycle) 
	{
		cout << -1<<'\n';
	}
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (result[i] == 2100000000)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << result[i] << '\n';
			}
		}
	}

	return 0;
}


void Vel_Ford(void)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < Edge[j].size(); k++)
			{
				int start = j;
				int end = Edge[start][k].first;
				int weight = Edge[start][k].second;

				
				if (result[start] == 2100000000) continue; //시작하는 쪽이 무한대면 이미 글러먹었음.
				if (result[end] > result[start] + weight)
				{
					result[end] = result[start] + weight;
					if (i == N) minus_cycle = 1;
				}
			}
		} //1차 시도
	}
}


