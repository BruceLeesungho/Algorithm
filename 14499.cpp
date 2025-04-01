#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, x, y, K;


int dice[7]; //1��, 2��, 3�� 4�� 5�� 6�Ʒ�
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
	//�ֻ��� �ʱ�ȭ
	for (int i = 1; i <= 6; i++)
	{
		dice[i] = 0;
		temp[i] = 0;
	}


	while (!q.empty())
	{
		int n = q.front(); 
		q.pop();


		
		if (n == 1) // ��
		{
			if (y + 1 >= M) continue;
			y += 1;
			//�� -> �Ʒ�, �� -> ��, �� -> ��, �Ʒ� -> ��
			dice[3] = temp[6]; //�� -> �Ʒ�, 
			dice[1] = temp[3]; //�� -> ��
			dice[4] = temp[1]; //�� -> ��
			dice[6] = temp[4]; //�Ʒ� -> ��
		}
		else if(n == 2)// ��
		{
			if (y - 1 < 0) continue;
			y -= 1;
			//�� -> �Ʒ�, ��->��, �� -> ��,  �Ʒ� -> ��
			dice[4] = temp[6]; //�� -> �Ʒ�
			dice[1] = temp[4]; //�� -> ��
			dice[3] = temp[1]; //�� -> ��
			dice[6] = temp[3]; //�Ʒ� -> ��
		}
		else if (n == 3)// ��
		{
			if (x - 1 < 0) continue;
			x -= 1;
			//�� -> ��, �� -> �Ʒ�, �� -> ��, �Ʒ� -> ��
			dice[1] = temp[2]; //�� -> ��
			dice[2] = temp[6]; //�� -> �Ʒ�
			dice[5] = temp[1]; //�� -> ��
			dice[6] = temp[5]; //�Ʒ� -> ��
		}
		else // ��
		{
			if (x + 1 >= N) continue;
			x += 1;
			//�� -> �Ʒ�, �Ʒ� -> ��, �� -> ��, �� -> ��
			dice[5] = temp[6]; //�� -> �Ʒ�
			dice[6] = temp[2]; //�Ʒ� -> ��
			dice[2] = temp[1]; //�� -> ��
			dice[1] = temp[5]; //�� -> ��
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



		//���� �ֻ����� �� �ֻ��� ����
		for (int i = 1; i <= 6; i++)
		{
			temp[i] = dice[i];
		}
		cout << dice[1] << '\n'; //���������� �÷���

	}
}