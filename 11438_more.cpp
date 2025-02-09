#define _CRT_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int N, M;
vector<int> V[100000 + 1];
int used[100000 + 1];
int max_k;
int depth[100000 + 1];
int parent[20][100000 + 1];
int max_depth;

void BFS(void)
{
	queue<int> q;
	q.push(1);
	used[1] = 1;
	depth[1] = 1;
	parent[0][1] = -1;

	while (!q.empty())
	{
		int now_idx = q.front();
		q.pop();
		int size = V[now_idx].size();
		
		for (int i = 0; i < size; i++)
		{
			int connected = V[now_idx][i];
			
			if (used[connected] == 1) continue;

			q.push(connected);
			used[connected] = 1;
			depth[connected] = depth[now_idx] + 1;
			parent[0][connected] = now_idx;

			if (depth[connected] > max_depth) max_depth = depth[connected]; //최고깊이 구하기

		}

	}


}
int Fast_LCA(int a, int b, int k)
{
	if (depth[a] > depth[b]) //b가 항상 깊도록
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

	//깊이 맞추고. 빠르게.
	
	for (int i = k; i >= 0; i--)
	{
		int diff = depth[b] - depth[a];
		if (diff >= pow(2, i)) //2의 i제곱만큼 점프
		{
			b = parent[i][b];
		}
	}




	//올라가기. 빠르게.
	for (int i = k; i >= 0; i--)
	{
		if (parent[i][a] == parent[i][b]) continue;
		else
		{
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	
	if (a != b) a = parent[0][a]; //같을수가있거든? 원래 밑에있는놈이 부모가 윗놈일경우. 그럼걍출력인데
								  //다르면 그 위를 가면 됨.

	return a;
}

//parent[k][n] = parent[k-1][parent[k-1][n]]
void make_dp(int a)
{
	for (int k = 1; k <= a; k++)
	{
		for (int n = 1; n <= N; n++)
		{
			parent[k][n] = parent[k - 1][parent[k - 1][n]];
		}
	}
}



int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		V[a].push_back(b);
		V[b].push_back(a);

	}
	for (int i = 0; i <= N; i++) used[i] = 0;
	max_depth = -1;

	BFS();
	
	int max_k = 0;
	int k2 = 1;
	while (k2 <= max_depth)
	{
		k2 *= 2;
		max_k++;
	}
	max_k--;
	
	make_dp(max_k);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << Fast_LCA(a, b, max_k) << '\n';
	}

	return 0;
}




