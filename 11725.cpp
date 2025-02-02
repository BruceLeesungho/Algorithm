#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
#include <iostream>
#define MAX_N (100001)

using namespace std;

int N;

vector<int> V[MAX_N];
int used[MAX_N];
int parent[MAX_N];

void dfs(int n)
{
	int s = V[n].size();
	for (int i = 0; i < s; i++)
	{
		if (used[V[n][i]] == 1)
		{
			parent[n] = V[n][i];
			continue;
		}
		used[V[n][i]] = 1;
		dfs(V[n][i]);
	}
}



int main(void)
{
	cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}

	used[1] = 1;
	dfs(1);

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << '\n';
	}

	return 0;
}