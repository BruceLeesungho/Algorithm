#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int map[1000 + 1][1000 + 1];
int chk[1000 + 1][1000 + 1];

int result_N;
int M, N;
queue<pair<int, int>> q;
int rr[4] = {-1, 1, 0, 0};
int cc[4] = {0, 0, -1, 1};

int main(void)
{
	cin >> M >> N;
	result_N = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];		chk[i][j] = 0;

			if (map[i][j] == 1)
			{
				q.push({ i,j });
				chk[i][j] = 1;
			}
			
		}
	}

	int size = q.size();
	int cnt = 0;
	
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			int nr = r + rr[i];
			int nc = c + cc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= M || chk[nr][nc] == 1 || map[nr][nc] == -1) continue;

			q.push({ nr,nc });
			chk[nr][nc] = 1;
			map[nr][nc] = 1;
		}

		if (cnt == size)
		{
			size = q.size();
			cnt = 0;
			result_N++;
		}
		

	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}
	
	cout << result_N - 1;

	return 0;
}