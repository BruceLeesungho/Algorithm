#define _CRT_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
int LeftStart;
int Total_size;
vector<long> V;
void SetSegmentTree(void);
void ChangeVal(int index, int value);
long Mul(int s, int e);

int main(void)
{
	cin >> N >> M >> K;
	Total_size = 1;
	while (Total_size <= N)
	{
		Total_size *= 2;
	}
	Total_size *= 2;
	LeftStart = Total_size / 2;
	

	V.resize(Total_size, 1); // resize 주의할점은 다시 resize 하면 resize하면서
	//벡터크기가 커지는 경우에만 값이 들어감.
	for (int i = LeftStart; i < LeftStart + N; i++)
	{
		cin >> V[i];
	}
	SetSegmentTree();




	for (int i = 0; i < M + K; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			ChangeVal(b + LeftStart - 1, c);
		}
		else
		{
			int s = b + LeftStart - 1;
			int e = c + LeftStart - 1;
			cout << Mul(s, e) << '\n';
		}
	}



	return 0;
}



void SetSegmentTree(void)
{
	int index = Total_size - 1;
	while (index != 1)
	{
		V[index / 2] = V[index] * V[index - 1] % 1000000007;
		index -= 2;
	}
}


void ChangeVal(int idx, int Val)
{
	V[idx] = Val;
	while (idx > 1)
	{
		if (idx % 2 == 0) // 짝수야?
		{
			V[idx / 2] = V[idx] * V[idx + 1] % 1000000007;
		}
		else //홀수야?
		{
			V[idx / 2] = V[idx] * V[idx - 1] % 1000000007;
		}

		idx /= 2;
	}
}


long Mul(int s, int e)
{
	long result = 1;
	while (s <= e)
	{
		if (s % 2 == 1)
		{
			result *= V[s];
			result %= 1000000007;
			s++;
		}
		
		if (e % 2 == 0)
		{
			result *= V[e];
			result %= 1000000007;
			e--;
		}

		s = s / 2;
		e = e / 2;
	}

	return result;
}