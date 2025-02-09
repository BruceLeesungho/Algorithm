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

			if (depth[connected] > max_depth) max_depth = depth[connected]; //�ְ���� ���ϱ�

		}

	}


}
int Fast_LCA(int a, int b, int k)
{
	if (depth[a] > depth[b]) //b�� �׻� ����
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

	//���� ���߰�. ������.
	
	for (int i = k; i >= 0; i--)
	{
		int diff = depth[b] - depth[a];
		if (diff >= pow(2, i)) //2�� i������ŭ ����
		{
			b = parent[i][b];
		}
	}




	//�ö󰡱�. ������.
	for (int i = k; i >= 0; i--)
	{
		if (parent[i][a] == parent[i][b]) continue;
		else
		{
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	
	if (a != b) a = parent[0][a]; //���������ְŵ�? ���� �ؿ��ִ³��� �θ� �����ϰ��. �׷�������ε�
								  //�ٸ��� �� ���� ���� ��.

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




