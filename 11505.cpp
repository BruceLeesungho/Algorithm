#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;

long Tree[3000000];
int N, M, K;

void changeVal(int index, long val);
long GetMul(int s, int e);

int main(void)
{
	cin >> N >> M >> K;
	int dob = 1;
	int cnt_k = 0;
	while (dob < N)
	{
		dob = dob * 2;
		cnt_k++;
	}
	int leftNodeStartIndex = dob - 1;
	int end_index = dob * 2 - 1;

	for (int i = 0; i < N; i++)
	{
		int Leaf;
		cin >> Leaf;
		Tree[dob++] = Leaf;
	}
	
	for (int i = dob; i <= end_index; i++)
	{
		Tree[i] = 1;
	}

		
	while (end_index != 1)
	{
		Tree[end_index / 2] = Tree[end_index] * Tree[end_index - 1];//% MOD; //헷갈리긴하는데
		Tree[end_index / 2] = Tree[end_index / 2] % 1000000007;
		end_index -= 2;
	}


	for (int i = 0; i < M + K; i++)
	{
		int a, s, e;
		cin >> a >> s >> e;
		
		if (a == 1)
		{
			changeVal(leftNodeStartIndex + s, e);
		}
		else
		{
			s = s + leftNodeStartIndex;
			e = e + leftNodeStartIndex;
			cout << GetMul(s, e)<< '\n';
		}
	}



	return 0;
} 

void changeVal(int index, long val)
{
	Tree[index] = val;

	while (index > 1)
	{
		index /= 2;
		Tree[index] = Tree[index * 2] % 1000000007 * Tree[index * 2 + 1] % 1000000007;
	}
}


long GetMul(int s, int e)
{
	long Partmul = 1;

	while (s <= e)
	{
		if (s % 2 == 1) //오른쪽 자식노드
		{
			Partmul = Partmul * Tree[s] % 1000000007;
			s++;
		}

		if (e % 2 == 0)
		{
			Partmul = Partmul * Tree[e] % 1000000007;
			e--;
		}
		s /= 2;
		e /= 2;
	}

	return Partmul;
}