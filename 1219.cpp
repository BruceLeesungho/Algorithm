#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#define MAX_N (51)

using namespace std;

long long result[MAX_N];
//1 �ϴ� �� -21�� �ʱ�ȭ.
//2 �������� �Ἥ ũ�� ������Ʈ.
//3 ��� ����Ŭ ã�ƾ��ϹǷ� N+50��ŭ �� ������Ʈ�ϴµ�, N���� ū�� �����̵Ǹ� �������Ŭ���ִ°�.??���� N+50����?

int N, M, S, E;

struct Edge
{
	int a, b;
	long long w;
}Edge_list[MAX_N];
long long money[MAX_N];
int cycle = 0;


void Bellman_Ford(void);

int main(void)
{
	cin >> N >> S >> E >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> Edge_list[i].a >> Edge_list[i].b >> Edge_list[i].w;
		
	}
	
	for (int i = 0; i < N; i++)
	{
		cin >> money[i];
		result[i] = -0x7f7f7f7f7f7f;
	}

	//Ʈ���Ű� ���۵��ø� ������Ʈ���ְ� ����.
	result[S] = money[S];
	Bellman_Ford();
	
	if (result[E] == -0x7f7f7f7f7f7f)
	{
		cout << "gg";
	}
	else if(result[E] == 0x7f7f7f7f7f7f)
	{
		cout << "Gee";
	}
	else
	{
		cout << result[E];
	}



	return 0;
}


void Bellman_Ford(void)
{
	for (int n = 0; n <= N+50; n++)
	{
		for (int i = 0; i < M; i++)
		{
			Edge E = Edge_list[i];
			int s = E.a;
			int e = E.b;
			int weight = E.w;
			if (result[s] == -0x7f7f7f7f7f7f) continue;
			else if (result[s] == 0x7f7f7f7f7f7f) result[e] = 0x7f7f7f7f7f7f;
			else if (result[e] < result[s] + money[e] - weight)
			{
				result[e] = result[s] + money[e] - weight;
				if (n >= N - 1) result[e] = 0x7f7f7f7f7f7f;
			}
			
		}
	}
}


