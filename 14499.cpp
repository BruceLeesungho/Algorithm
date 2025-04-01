#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, x, y, K;


int dice[7]; //1위, 2뒤, 3오 4왼 5앞 6아래
int temp[7];

int map[20 + 1][20 + 1];
queue<int> q;
void move_dice(void);

int main(void)
{
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++)
	{
		int n;
		cin >> n; 
		q.push(n);
	}

	move_dice();

	return 0;
}

void move_dice(void)
{
	//주사위 초기화
	for (int i = 1; i <= 6; i++)
	{
		dice[i] = 0;
		temp[i] = 0;
	}


	while (!q.empty())
	{
		int n = q.front(); 
		q.pop();


		
		if (n == 1) // 동
		{
			if (y + 1 >= M) continue;
			y += 1;
			//오 -> 아래, 위 -> 오, 왼 -> 위, 아래 -> 왼
			dice[3] = temp[6]; //오 -> 아래, 
			dice[1] = temp[3]; //위 -> 오
			dice[4] = temp[1]; //왼 -> 위
			dice[6] = temp[4]; //아래 -> 왼
		}
		else if(n == 2)// 서
		{
			if (y - 1 < 0) continue;
			y -= 1;
			//왼 -> 아래, 위->왼, 오 -> 위,  아래 -> 오
			dice[4] = temp[6]; //왼 -> 아래
			dice[1] = temp[4]; //위 -> 왼
			dice[3] = temp[1]; //오 -> 위
			dice[6] = temp[3]; //아래 -> 오
		}
		else if (n == 3)// 북
		{
			if (x - 1 < 0) continue;
			x -= 1;
			//위 -> 뒤, 뒤 -> 아래, 앞 -> 위, 아래 -> 앞
			dice[1] = temp[2]; //위 -> 뒤
			dice[2] = temp[6]; //뒤 -> 아래
			dice[5] = temp[1]; //앞 -> 위
			dice[6] = temp[5]; //아래 -> 앞
		}
		else // 남
		{
			if (x + 1 >= N) continue;
			x += 1;
			//앞 -> 아래, 아래 -> 뒤, 뒤 -> 위, 위 -> 앞
			dice[5] = temp[6]; //앞 -> 아래
			dice[6] = temp[2]; //아래 -> 뒤
			dice[2] = temp[1]; //뒤 -> 위
			dice[1] = temp[5]; //위 -> 앞
		}

		if (map[x][y] == 0)
		{
			map[x][y] = dice[6];
		}
		else
		{
			dice[6] = map[x][y];
			map[x][y] = 0;
		}



		//더미 주사위에 찐 주사위 복사
		for (int i = 1; i <= 6; i++)
		{
			temp[i] = dice[i];
		}
		cout << dice[1] << '\n'; //위위위위위 플래시

	}
}