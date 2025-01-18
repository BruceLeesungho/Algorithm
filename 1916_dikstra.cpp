#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
#define MAX_N (1001)

using namespace std;

int N, M;
int Start, End;
long long Cost[MAX_N];
vector<pair<short, long long>> AdjList[MAX_N]; //node, dist

struct COMP
{
	bool operator()(pair<short, long long> a, pair<short, long long> b)
	{
		return a.second > b.second;
	}

};

priority_queue<pair<short, long long>, vector<pair<short, long long>>, COMP> pq; //node number, dist

long long Dijkstra(int S, int E)
{
	bool used[MAX_N];
	pq.push({ S, 0 });

	while (!pq.empty())
	{
		short start_node = pq.top().first;
		long long Until_now_dist = pq.top().second;
		pq.pop();

		if (used[start_node] == 1) continue;

		for (int i = 0; i < AdjList[start_node].size(); i++)
		{
			short next_node = AdjList[start_node][i].first;
			long long next_dist = (long long)AdjList[start_node][i].second;

			//int my_cost = Cost[start_node];

			if ((Until_now_dist + next_dist) < Cost[next_node])
			{
				Cost[next_node] = Until_now_dist + next_dist;
				pq.push({ next_node, Cost[next_node] });
			}
		}
		used[start_node] = 1;

	}

	return Cost[End];

}

int main(void)
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) Cost[i] = 0x7ffffffff;
	for (int i = 0; i < M; i++)
	{
		int s, e, d;
		cin >> s >> e >> d;

		AdjList[s].push_back({ e, d });
	}
	cin >> Start >> End;
	Cost[Start] = 0;

	long long result = Dijkstra(Start, End);

	cout << result;


	return 0;
}