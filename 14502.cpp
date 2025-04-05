#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <queue>
using namespace std;

int map[8 + 1][8 + 1];
int dummy[8 + 1][8 + 1];
int N, M;
int maxmax = -1;
int k = 0;
vector<pair<int, int>> V;

int r[4] = { -1, 1, 0 ,0 };
int c[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;

void BFS(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) dummy[i][j] = map[i][j];
	}

	for (int i = 0; i < V.size(); i++)
	{ 
		int rr = V[i].first;
		int cc = V[i].second;
		q.push({ rr, cc });
	}

	while (!q.empty())
	{
		int rr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int nr = rr + r[d];
			int nc = cc + c[d];

			if (nr < 0 || nc < 0 || nr >= N || nc >= M || dummy[nr][nc] != 0) continue;

			dummy[nr][nc] = 2;
			q.push({ nr, nc });
		}
	}

	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (dummy[i][j] == 0) count++;
		}
	}

	if (count > maxmax) maxmax = count;
}


void DFS(void)
{
	if (k == 3)
	{
		BFS();
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				k++;
				map[i][j] = 1;
				DFS();
				map[i][j] = 0;
				k--;
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2) V.push_back({ i,j });
		}
	}

	queue<pair<int, int>> q;
	int k = 0;
	
	DFS();

	cout << maxmax;

	return 0;
}