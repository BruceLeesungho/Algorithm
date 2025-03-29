#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int ori_map[100 + 2][100 + 2];
int sero_stair[100 + 2][100 + 2];
int garo_stair[100 + 2][100 + 2];
int N, L;

queue<int> q_garo;
queue<int> q_sero;


int count_street(void);


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sero_stair[i][j] = 0;
			garo_stair[i][j] = 0;
			cin >> ori_map[i][j];
			if (i > 0 && j > 0)
			{
				if (abs(ori_map[i][j - 1] - ori_map[i][j]) > 1)
				{
					q_garo.push(i);
				}
				if (abs(ori_map[i - 1][j] - ori_map[i][j]) > 1)
				{
					q_sero.push(j);
				}
			}
		}
	}

	cout << count_street();




	return 0;
}


int count_street(void)
{
	int Total_street = 0;
	int high_now = 0;

	for (int i = 0; i < N; i++) //���ѹ�(�����ѹ�)
	{
		if (!q_garo.empty() && (q_garo.front() == i))
		{
			q_garo.pop();
			continue;
		}

		for (int j = 0; j < N; j++)
		{
			
			high_now = ori_map[i][j];
			if (j == N - 1)
			{
				Total_street++;
				continue;
			}
			if (abs(high_now - ori_map[i][j + 1]) > 1)
			{
				continue;
			}

			if (high_now < ori_map[i][j + 1]) //������ ���� ��Ȳ
			{
				int length = 0;
				int idx = j;
				int cant = 0;
				for (int k = 0; k < L; k++)
				{
					if ((idx < 0) || (ori_map[i][idx] != high_now) || (garo_stair[i][idx] == 1))
					{   // �������, �������̾ȸ���, �̹� ����ְų�  
						cant = 1;
						break;
					}
					garo_stair[i][idx--] = 1; //��ܼ���Ⱑ��.3213123123
				}
				if (cant == 1) break;
			}
			else if (high_now > ori_map[i][j + 1]) //������ ���� ��Ȳ.
			{
				int length = 0;
				int idx = j;
				int cant = 0;
				idx++;
				for (int k = 0; k < L; k++)
				{
					if ((idx >= N) || (ori_map[i][idx] != high_now - 1) || (garo_stair[i][idx] == 1))
					{   // �������, �������̾ȸ���, �̹� ����ְų�  
						cant = 1;
						break;
					}
					garo_stair[i][idx++] = 1; //��ܼ���Ⱑ��.3213123123
				}
				if (cant == 1) break;
			}
		}
	}




	for (int i = 0; i < N; i++) //�� �ѹ�(�����ѹ�)
	{
		if (!q_sero.empty() && (q_sero.front() == i))
		{
			q_sero.pop();
			continue;
		}

		for (int j = 0; j < N; j++) //��
		{
			high_now = ori_map[j][i];
			if (j == N - 1)
			{
				Total_street++;
				continue;
			}

			if (abs(high_now - ori_map[j+1][i]) > 1)
			{
				continue;
			}


			if (high_now < ori_map[j+1][i]) //������ ���� ��Ȳ
			{
				int length = 0;
				int idx = j;
				int cant = 0;
				for (int k = 0; k < L; k++)
				{
					if ((idx < 0) || (ori_map[idx][i] != high_now) || (sero_stair[idx][i] == 1))
					{   // �������, �������̾ȸ���, �̹� ����ְų�  
						cant = 1;
						break;
					}
					sero_stair[idx--][i] = 1; //��ܼ���Ⱑ��.3213123123
				}
				if (cant == 1) break;
			}
			else if (high_now > ori_map[j + 1][i]) //������ ���� ��Ȳ.
			{
				int length = 0;
				int idx = j;
				int cant = 0;
				idx++;
				for (int k = 0; k < L; k++)
				{
					if ((idx >= N) || (ori_map[idx][i] != high_now - 1) || (sero_stair[idx][i] == 1))
					{   // �������, �������̾ȸ���, �̹� ����ְų�  
						cant = 1;
						break;
					}
					sero_stair[idx++][i] = 1; //��ܼ���Ⱑ��.3213123123
				}
				if (cant == 1) break;
			}
		}
	}




	return Total_street;
}