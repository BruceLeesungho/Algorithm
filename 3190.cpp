#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int map[100 + 2][100 + 2]; //맵 1부터~100까지 씀.
struct SNAKE
{
	int dir;
	int length;
	int headr;
	int headc;
	int tailr;
	int tailc;
}snake;
queue<pair<int, char>>q;
queue<pair<int, int>> History;
int N, K, X;

int Game_play(void);


int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int r, c;
	int t;
	char DIR;

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) map[i][j] = 0;
	}

	for (int i = 0; i < K; i++)
	{
		cin >> r >> c;
		map[r][c] = 1;
	}

	cin >> X;
	for (int i = 0; i < X; i++)
	{
		cin >> t >> DIR;
		q.push(make_pair(t, DIR));
	}

	cout << Game_play();


	return 0;
}


int Game_play(void)
{
	int time = 0;
	int dir;
	int dr[4] = { -1, 1, 0, 0 }; //상하좌우
	int dc[4] = {0, 0, -1, 1};   //0 1 2 3
	
	snake.headr = 1;
	snake.headc = 1;
	snake.tailr = 1;
	snake.tailc = 1;
	snake.dir = 3;
	snake.length = 1;
	map[1][1] = 2; 
	History.push(make_pair(1, 1)); //위치를 다 넣어.

//____________________________게임초기화



	while (1)
	{
		time++;
		dir = snake.dir; //움직이고 방향전환이 맞다.
		int nextr = snake.headr + dr[dir];
		int nextc = snake.headc + dc[dir];
		
		if (map[nextr][nextc] == 1) //사과가 있음.
		{
			map[nextr][nextc] = 0; //사과 없앰.
			map[nextr][nextc] = 2; //머리 이동 but 꼬리는 사과먹으면 그대로. 
			snake.headr = nextr;
			snake.headc = nextc;	
		}
		else if (nextr > N || nextc > N || nextr < 1 || nextc < 1 || map[nextr][nextc] == 2) //벽 or my body
		{
			break;
		}
		else// if(map[nextr][nextc] == 0)
		{
			map[nextr][nextc] = 2;
			snake.headr = nextr;
			snake.headc = nextc;
			map[History.front().first][History.front().second] = 0;
			History.pop(); // 꼬리를 빼
		}

		History.push(make_pair(nextr, nextc));//이거는 이제 내가 간곳. 넣어줘.

		//Change dir;
		if (!q.empty() && q.front().first == time)
		{
			char d = q.front().second;
			q.pop();
			if (d == 'D')
			{
				if (snake.dir == 0)  // 상하좌우
				{					//  0 1 2 3
					snake.dir = 3;
				}
				else if (snake.dir == 1)
				{
					snake.dir = 2;
				}
				else if (snake.dir == 2)
				{
					snake.dir = 0;
				}
				else
				{
					snake.dir = 1;
				}
			}
			else
			{
				if (snake.dir == 0)  // 상하좌우
				{					//  0 1 2 3
					snake.dir = 2;
				}
				else if (snake.dir == 1)
				{
					snake.dir = 3;
				}
				else if (snake.dir == 2)
				{
					snake.dir = 1;
				}
				else
				{
					snake.dir = 0;
				}
			}
		}
	}


	return time;
}