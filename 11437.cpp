#define _CRT_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int used[50000 + 1];
int depth[50000 + 1];
int parent[50000 + 1];
vector<int> V[50000 + 1];
void BFS(void);
int LCA(int a, int b);


int main(void)
{
	cin >> N;
	used[N] = 0;
	for (int i = 1; i <= N-1; i++)
	{
		used[i] = 0;
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	BFS();

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}

	return 0;
}

void BFS(void)
{
	queue<int> q;
	q.push(1);
	used[1] = 1;
	depth[1] = 1;

	while (!q.empty())
	{
		int idx = q.front();
		int size = V[idx].size();
		q.pop();

		for (int i = 0; i < size; i++)
		{
			int connected_n = V[idx][i];
			if (used[connected_n] == 1) continue;

			used[connected_n] = 1;
			depth[connected_n] = depth[idx] + 1;
			parent[connected_n] = idx;

			q.push(connected_n);
		}

	}
}


int LCA(int u, int v)
{
	//int depth_1 = depth[a];
	//int depth_2 = depth[b];
	//int left = a;
	//int right = b;

	//while (parent[left] != parent[right])
	//{
	//	depth_1 = depth[left];
	//	depth_2 = depth[right];

	//	if (depth_1 < depth_2)
	//	{
	//		if (parent[right] == left) return left;
	//		right = parent[right];//내 부모 노드로 간다.
	//	}
	//	else if (depth_1 > depth_2)
	//	{
	//		if (parent[left] == right) return right;
	//		left = parent[left];
	//	}
	//	else
	//	{
	//		right = parent[right];
	//		left = parent[left];
	//	}
	//}


	//return parent[left];
	if (depth[u] > depth[v]) swap(u, v);

	// 두 노드의 깊이가 같아질때까지 v노드는 위로 거슬러 올라감
	while (depth[u] != depth[v]) v = parent[v];

	// 두 노드가 같아질때 까지 위로 거슬러 올라감
	while (u != v)
	{
		u = parent[u];
		v = parent[v];
	}
	return u; // LCA 
}
