#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX_N (51)

using namespace std;

int used[MAX_N];
int N;
vector<int> L[MAX_N];
int My_parent[MAX_N];
int leaf_cnt = 0;
int erase_n;
int tree_n;

void erase_node(int);

int main(void)
{
	
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int parent;
		used[i] = 0;
		cin >> parent;
		My_parent[i] = parent;
		if (parent == -1) tree_n = i;


		else
		{
			L[parent].push_back(i); //자식넣기
		}
	}
	cin >> erase_n;
	if (tree_n == erase_n)
	{
		cout << 0;
		return 0;
	}
	int mp = My_parent[erase_n];
	
	vector<int>::iterator a;
	for (auto iter = L[mp].begin(); iter != L[mp].end(); iter++) 
	{	
		if (*iter == erase_n)
		{
			a = iter;
		}
	}
	L[mp].erase(a);

	erase_node(tree_n);
	
	cout << leaf_cnt;

	return 0;
}

void erase_node(int pnt)
{
	if (pnt == erase_n)
	{
		return;
	}

	if (L[pnt].size() == 0)
	{
		leaf_cnt++;
		return;
	}

	for (int i = 0; i < L[pnt].size(); i++)
	{
		erase_node(L[pnt][i]);
	}
	
}

