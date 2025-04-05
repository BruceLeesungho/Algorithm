#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

int N;
vector<string> V[50];
set<string> S[50];

int main(void)
{
	string a;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		S[a.size()].insert(a);
	}

	for (int i = 1; i < N; i++)
	{
		if (S[i].size())
		{
			for (auto iter = S[i].begin(); iter != S[i].end();iter++)
			{
				cout << *iter << '\n';
			}
		}
	}


	return 0;
}
