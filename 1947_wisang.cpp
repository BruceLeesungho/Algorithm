#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>

#define MAX_N 10001

using namespace std;


int N, M;
int in_array[MAX_N];
int in_array_R[MAX_N];
int imge[MAX_N];
bool used[MAX_N];
bool used_R[MAX_N];
vector<int>Adj_List[MAX_N];
vector<int>Adj_List_Reverse[MAX_N];
short dist[MAX_N][MAX_N];
int Max_dist = 0;
int Max_street = 0;

queue<int> in_Zero;

void SearchAndGo(int v)
{
	for (int i = 0; i < Adj_List[v].size(); i++)
	{
		int arrival_node = Adj_List[v][i];
		in_array[arrival_node]--;
		if (in_array[arrival_node] == 0)
		{
			in_Zero.push(arrival_node);
		}
		int kk = imge[v] + dist[v][arrival_node];
		if (imge[arrival_node] < kk) imge[arrival_node] = kk;
	}
}

void SearchAndGo_Reverse(int v)
{
	for (int i = 0; i < Adj_List_Reverse[v].size(); i++)
	{
		int Prev = Adj_List_Reverse[v][i];
		int m = imge[v];
		int PrevTime = dist[v][Prev];

		if ((m - PrevTime) == imge[Prev])
		{
			
			Max_street++;
			if(used_R[Prev] == 0)
			{
				used_R[Prev] = 1;
				in_Zero.push(Prev);
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;
	int starting_point;
	int end_point;

	int a, b, c; // a -> starting, b -> arrival, c -> distance 
	
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		in_array[b]++;
		in_array_R[a]++; //반대도 해야함. 리버스.
		Adj_List[a].push_back(b);
		Adj_List_Reverse[b].push_back(a);
		dist[a][b] = c;
		dist[b][a] = c;
	}

	cin >> starting_point >> end_point;
	in_Zero.push(starting_point);
	
	while (!in_Zero.empty())
	{
		int i = in_Zero.front();
		in_Zero.pop();

		if (used[i] == 1) continue;
		if (in_array[i] == 0)
		{
			//used[i] = 1; //used this node!
			//topological_array.push_back(i); //위상정렬세팅
			SearchAndGo(i);
		}
	}
	

	
	Max_dist = imge[end_point];
	


	//_______________________reverse 반대로 엔드부터 스타팅으로뛰어.
	
	in_Zero.push(end_point);
	used_R[end_point] = 1;

	while (!in_Zero.empty())
	{
		int i = in_Zero.front();
		in_Zero.pop();
		SearchAndGo_Reverse(i);
		
	}

	cout << Max_dist << '\n';
	cout << Max_street;

	return 0;
}