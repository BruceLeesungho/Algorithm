#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
using namespace std;

int N, M;
int Uni[200 + 1];
int starting_num;

vector<int> adj_list[200 + 1]; //adjacent list

void Union(void)
{
	for (int i = 1; i <= N; i++)
	{
		int end = adj_list[i].size();

		for (int j = 0; j < end; j++)
		{
			int num = adj_list[i][j];
			if (Uni[num] > Uni[i]) // i  -> 4
			{
				Uni[num] = Uni[i];
			}
			else
			{
				if (Uni[i] != i)
				{
					Uni[Uni[i]] = Uni[num]; // num -> 5
				}
				Uni[i] = Uni[num];
			}
		}
	}
}


int main(void)
{
	scanf("%d", &N);
	scanf("%d", &M);
	starting_num = 0;
	int temp = 0;

	for (int i = 1; i <= N; i++)
	{	
		Uni[i] = i;
		for (int j = 1; j <= N; j++) // i가 기준이고 j가 연결된노드
		{
			scanf("%d", &temp);
			if (temp == 0) continue;
			adj_list[i].push_back(j);
		}
	}
	//Union
	Union();

	//Lets find
	int trav;
	scanf("%d", &trav);
	starting_num = Uni[trav];
	
	int result = 0;
	for (int i = 0; i < M-1; i++)
	{
		scanf("%d", &trav);
		if (Uni[trav] != starting_num)
		{
			result = 1;
		}
	}
	if (result == 1)
	{
		printf("NO");
	}
	else
	{
		printf("YES");
	}

	return 0;
}