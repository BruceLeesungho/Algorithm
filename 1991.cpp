#define _CRT_SECURE_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N;
char now_node;
char Left[26 + 1];
char Right[26 + 1];
char Node[26 + 1];



void Pre_order(char n);
void In_order(char n);
void Post_order(char n);


int main(void)
{
	cin >> N;

	for (int i = 0; i < 26; i++)
	{
		Left[i] = '.';
		Right[i] = '.';
		Node[i] = '.';
	}

	for (int i = 0; i < N; i++)
	{
		char node, l, r;
		cin >> node >> l >> r;
		
		Node[node - 'A'] = node;
		Left[node - 'A'] = l;
		Right[node - 'A'] = r;
	}


	now_node = 'A';
	Pre_order('A'); cout << '\n';
	In_order('A');  cout << '\n';
	Post_order('A');


	return 0;
}


void Pre_order(char n)
{
	cout << n;
	if (Left[n-'A'] != '.') Pre_order(Left[n-'A']);
	if (Right[n-'A'] != '.') Pre_order(Right[n -'A']);
}

void In_order(char n)
{
	
	if (Left[n - 'A'] != '.') In_order(Left[n - 'A']);
	cout << n;
	if (Right[n - 'A'] != '.') In_order(Right[n - 'A']);
}

void Post_order(char n)
{
	
	if (Left[n - 'A'] != '.') Post_order(Left[n - 'A']);
	if (Right[n - 'A'] != '.') Post_order(Right[n - 'A']);
	cout << n;
}