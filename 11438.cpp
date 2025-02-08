#define _CRT_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <stdio.h>

using namespace std;

int N, M;
int depth[100000 + 1]; //깊이 차를 구하려는
int max_depth;
int parent[21][100000];
int used[100000 + 1];
int kmax;
vector<int> V[100000 + 1];

void BFS(void)
{
	for (int i = 1; i <= N; i++) used[i] = 0;
	max_depth = -1;
	queue<int> q;
	q.push(1);
	used[1] = 1;
	depth[1] = 1;

	while (!q.empty())
	{
		int idx = q.front();
		q.pop();
		//used[idx] = 1;
		int connected;

		for (int i = 0; i < V[idx].size(); i++)
		{
			connected = V[idx][i];
			
			if (used[connected]) continue;
			
			depth[connected] = depth[idx] + 1;
			parent[0][connected] = idx;
			used[connected] = 1;
			q.push(connected);

			if (max_depth < depth[connected]) max_depth = depth[connected]; //미리 최대깊이 구해놓

		}
	}



}

void Make_FastTrack(int kcnt)
{
	for (int k = 1; k <= kcnt; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			parent[k][i] = parent[k - 1][parent[k - 1][i]];
		}
	}
}


int FastLCA(int a, int b)
{
	//b가 더 깊도록
	if (depth[a] > depth[b])
	{
		int tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
	//깊이 맞추고
	for (int k = kmax; k >= 0; k--)
	{
		if (pow(2, k) <= (depth[b] - depth[a]))
		{
			if(depth[a] <= depth[parent[k][b]]) b = parent[k][b];
		}
	}


	//조상을 빠르게 찾는다.

	for (int k = kmax; ((k >= 0) && (a!= b)); k--)
	{
		if (parent[k][a] != parent[k][b])
		{
			a = parent[k][a];
			b = parent[k][b];
		}
	}

	if (a != b) a = parent[0][a];
	

	return a;
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	BFS();

	int ak = 1;
	int cnt = 0;
	while (ak <= max_depth)
	{
		ak *= 2;
		cnt++;
	}
	cnt--;
	kmax = cnt;

	Make_FastTrack(cnt);

	cin >> M;


	for (int i = 0; i < M; i++)
	{
		int c, d;
		cin >> c >> d;
		cout << FastLCA(c, d) << '\n';
	}


	return 0;
}