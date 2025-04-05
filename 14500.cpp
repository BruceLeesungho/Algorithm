#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int N, M;

int map[500 + 1][500 + 1];
int chk[500 + 1][500 + 1];

int MAXMAX;


void puton(int n);

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			chk[i][j] = 0;
		}
	}



	MAXMAX = 0;
	
	for (int i = 1; i <= 5; i++)
	{
		puton(i);
	}
	cout << MAXMAX;
	return 0;
}


void puton(int n)
{
	int score = 0;

	if (n == 1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				
				if ((chk[i][j] == 0) && (chk[i][j+1] == 0) && (chk[i+1][j] == 0) && (chk[i+1][j + 1] == 0) && (i+1 < N) && (j+1 < M))
				{
					chk[i][j] = 1;
					chk[i][j + 1] = 1; 
					chk[i + 1][j] = 1;
					chk[i + 1][j + 1] = 1;
					score = 0;
					score += map[i][j];
					score += map[i][j + 1];
					score += map[i + 1][j];
					score += map[i + 1][j + 1];
					
					if (score > MAXMAX) MAXMAX = score;

					chk[i][j] = 0;
					chk[i][j + 1] = 0;
					chk[i + 1][j] = 0;
					chk[i + 1][j + 1] = 0;

				}
				
			}
		}
	}
	else if (n == 2)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				
				if ((chk[i][j] == 0) && (chk[i][j + 1] == 0) && (chk[i][j+2] == 0) && (chk[i][j+3] == 0) && (j + 3 < M))
				{
					chk[i][j] = 1;
					chk[i][j + 1] = 1;
					chk[i][j + 2] = 1;
					chk[i][j + 3] = 1;
					score = 0;
					score += map[i][j];
					score += map[i][j + 1];
					score += map[i][j + 2];
					score += map[i][j + 3];

					if (score > MAXMAX) MAXMAX = score;

					chk[i][j] = 0;
					chk[i][j + 1] = 0;
					chk[i][j + 2] = 0;
					chk[i][j + 3] = 0;

				}
				if ((chk[i][j] == 0) && (chk[i+1][j] == 0) && (chk[i + 2][j] == 0) && (chk[i + 3][j] == 0) && (i + 3 < N))
				{
					chk[i][j] = 1;
					chk[i+1][j] = 1;
					chk[i+2][j] = 1;
					chk[i+3][j] = 1;
					score = 0;
					score += map[i][j];
					score += map[i+1][j];
					score += map[i + 2][j];
					score += map[i + 3][j];

					if (score > MAXMAX) MAXMAX = score;
					chk[i][j] = 0;
					chk[i+1][j] = 0;
					chk[i+2][j] = 0;
					chk[i+3][j] = 0;
				}
				
			}
		}
	}
	else if (n == 3)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				
				if ((chk[i][j] == 0) && (chk[i+1][j] == 0) && (chk[i+2][j] == 0) && (chk[i+2][j + 1] == 0) && (i + 2 < N) && (j + 1 < M))
				{
					chk[i][j] = 1;
					chk[i + 1][j] = 1;
					chk[i + 2][j] = 1;
					chk[i + 2][j + 1] = 1;
					score = 0;
					score += map[i][j];
					score += map[i + 1][j];
					score += map[i + 2][j];
					score += map[i + 2][j+1];

					if (score > MAXMAX) MAXMAX = score;
					chk[i][j] = 0; 
					chk[i + 1][j] = 0;
					chk[i + 2][j] = 0; 
					chk[i + 2][j + 1] = 0;

				}
				if ((chk[i][j] == 0) && (chk[i + 1][j] == 0) && (chk[i][j+1] == 0) && (chk[i][j+2] == 0) && (i + 1 < N) && (j+2 < M))
				{
					chk[i][j] = 1;
					chk[i + 1][j] = 1;
					chk[i][j+1] = 1;
					chk[i][j+2] = 1;
					score = 0;
					score += map[i][j];
					score += map[i + 1][j];
					score += map[i][j+1];
					score += map[i][j+2];
					if (score > MAXMAX) MAXMAX = score;

					chk[i][j] = 0;
					chk[i + 1][j] = 0;
					chk[i][j + 1] = 0;
					chk[i][j + 2] = 0;
				}
				if ((chk[i][j] == 0) && (chk[i][j+1] == 0) && (chk[i+1][j + 1] == 0) && (chk[i+2][j + 1] == 0) && (i + 2 < N) && (j + 1 < M))
				{
					chk[i][j] = 1;
					chk[i][j+1] = 1;
					chk[i+1][j + 1] = 1;
					chk[i+2][j + 1] = 1;
					score = 0;
					score += map[i][j];
					score += map[i][j+1];
					score += map[i + 1][j+1];
					score += map[i + 2][j+1];
					if (score > MAXMAX) MAXMAX = score;

					chk[i][j] = 0;
					chk[i][j + 1] = 0;
					chk[i + 1][j + 1] = 0;
					chk[i + 2][j + 1] = 0;
				}
				if ((chk[i][j] == 0) && (chk[i + 1][j] == 0) && (chk[i+1][j - 1] == 0) && (chk[i+1][j - 2] == 0) && (i + 1 < N) && (j - 2 >= 0))
				{
					chk[i][j] = 1;
					chk[i + 1][j] = 1;
					chk[i+1][j - 1] = 1;
					chk[i+1][j - 2] = 1;
					score = 0;
					score += map[i][j];
					score += map[i + 1][j];
					score += map[i + 1][j-1];
					score += map[i + 1][j-2];
					if (score > MAXMAX) MAXMAX = score;

					chk[i][j] = 0;
					chk[i + 1][j] = 0;
					chk[i + 1][j - 1] = 0;
					chk[i + 1][j - 2] = 0;
				}

				//´ëÄª¸ð¾ç

				if ((chk[i][j] == 0) && (chk[i + 1][j] == 0) && (chk[i + 2][j] == 0) && (chk[i + 2][j - 1] == 0) && (i + 2 < N) && (j - 1 >= 0))
				{
					chk[i][j] = 1;
					chk[i + 1][j] = 1;
					chk[i + 2][j] = 1;
					chk[i + 2][j - 1] = 1;
					score = 0;
					score += map[i][j];
					score += map[i + 1][j];
					score += map[i + 2][j];
					score += map[i + 2][j - 1];
					if (score > MAXMAX) MAXMAX = score;

					chk[i][j] = 0;
					chk[i + 1][j] = 0;
					chk[i + 2][j] = 0;
					chk[i + 2][j - 1] = 0;
				}
				



				if ((chk[i][j] == 0) && (chk[i + 1][j] == 0) && (chk[i + 1][j+1] == 0) && (chk[i + 1][j + 2] == 0) && (i + 1 < N) && (j + 2 < M))
				{
					chk[i][j] = 1;
					chk[i + 1][j] = 1;
					chk[i + 1][j+1] = 1;
					chk[i + 1][j +2] = 1;
					score = 0;
					score += map[i][j];
					score += map[i + 1][j];
					score += map[i + 1][j+1];
					score += map[i + 1][j + 2];
					if (score > MAXMAX) MAXMAX = score;

					chk[i][j] = 0;
					chk[i + 1][j] = 0;
					chk[i + 1][j + 1] = 0;
					chk[i + 1][j + 2] = 0;
				}


				if ((chk[i][j] == 0) && (chk[i][j+1] == 0) && (chk[i][j +2] == 0) && (chk[i + 1][j + 2] == 0) && (i + 1 < N) && (j + 2 < M))
				{
					chk[i][j] = 1;
					chk[i][j+1] = 1;
					chk[i][j + 2] = 1;
					chk[i + 1][j + 2] = 1;
					score = 0;
					score += map[i][j];
					score += map[i][j+1];
					score += map[i][j + 2];
					score += map[i + 1][j + 2];
					if (score > MAXMAX) MAXMAX = score;

					chk[i][j] = 0;
					chk[i][j + 1] = 0;
					chk[i][j + 2] = 0;
					chk[i + 1][j + 2] = 0;
				}


				if ((chk[i][j] == 0) && (chk[i][j + 1] == 0) && (chk[i+1][j] == 0) && (chk[i + 2][j] == 0) && (i + 2 < N) && (j + 1 < M))
				{
					chk[i][j] = 1;
					chk[i][j + 1] = 1;
					chk[i+1][j] = 1;
					chk[i + 2][j] = 1;
					score = 0;
					score += map[i][j];
					score += map[i][j + 1];
					score += map[i+1][j];
					score += map[i + 2][j];
					if (score > MAXMAX) MAXMAX = score;

					chk[i][j] = 0;
					chk[i][j + 1] = 0;
					chk[i+1][j] = 0;
					chk[i + 2][j] = 0;
				}
			}
		}
	}
	else if (n == 4)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				
				if ((chk[i][j] == 0) && (chk[i + 1][j] == 0) && (chk[i + 1][j+1] == 0) && (chk[i + 2][j + 1] == 0) && (i + 2 < N) && (j + 1 < M))
				{
					chk[i][j] = 1;
					chk[i + 1][j] = 1;
					chk[i + 1][j + 1] = 1;
					chk[i + 2][j + 1] = 1;
					score = 0;
					score += map[i][j];
					score += map[i + 1][j];
					score += map[i + 1][j+1];
					score += map[i + 2][j+1];
					if (score > MAXMAX) MAXMAX = score;

					chk[i][j] = 0;
					chk[i + 1][j] = 0;
					chk[i + 1][j + 1] = 0;
					chk[i + 2][j + 1] = 0;

				}
				if ((chk[i][j] == 0) && (chk[i + 1][j] == 0) && (chk[i+1][j - 1] == 0) && (chk[i+2][j - 1] == 0) && (i + 2 < N) && (j - 1 >= 0))
				{
					chk[i][j] = 1;
					chk[i + 1][j] = 1;
					chk[i+1][j - 1] = 1;
					chk[i+2][j - 1] = 1;
					score = 0;
					score += map[i][j];
					score += map[i + 1][j];
					score += map[i + 1][j-1];
					score += map[i + 2][j-1];
					if (score > MAXMAX) MAXMAX = score;

					chk[i][j] = 0;
					chk[i + 1][j] = 0;
					chk[i + 1][j - 1] = 0;
					chk[i + 2][j - 1] = 0;
				}
				if ((chk[i][j] == 0) && (chk[i][j + 1] == 0) && (chk[i - 1][j+1] == 0) && (chk[i - 1][j + 2] == 0) && (i - 1 >= 0) && (j + 2 < M))
				{
					chk[i][j] = 1;
					chk[i][j + 1] = 1;
					chk[i - 1][j + 1] = 1;
					chk[i - 1][j + 2] = 1;
					score = 0;
					score += map[i][j];
					score += map[i][j+1];
					score += map[i -1][j+1];
					score += map[i -1][j+2];
					if (score > MAXMAX) MAXMAX = score;

					chk[i][j] = 0;
					chk[i][j + 1] = 0;
					chk[i - 1][j + 1] = 0;
					chk[i - 1][j + 2] = 0;
				}
				if ((chk[i][j] == 0) && (chk[i][j+1] == 0) && (chk[i + 1][j + 1] == 0) && (chk[i + 1][j + 2] == 0) && (i + 1 < N) && (j + 2 < M))
				{
					chk[i][j] = 1;
					chk[i][j + 1] = 1;
					chk[i + 1][j + 1] = 1;
					chk[i + 1][j + 2] = 1;
					score = 0;
					score += map[i][j];
					score += map[i][j+1];
					score += map[i + 1][j+1];
					score += map[i + 1][j+2];
					if (score > MAXMAX) MAXMAX = score;

					chk[i][j] = 0;
					chk[i][j + 1] = 0;
					chk[i + 1][j + 1] = 0;
					chk[i + 1][j + 2] = 0;
				}
				
			}
		}
	}
	else // (n == 5)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				
				if ((chk[i][j] == 0) && (chk[i][j+1] == 0) && (chk[i][j + 2] == 0) && (chk[i + 1][j + 1] == 0) && (i + 1 < N) && (j + 2 < M))
				{
					chk[i][j] = 1;
					chk[i][j+1] = 1;
					chk[i][j + 2] = 1;
					chk[i + 1][j + 1] = 1;
					score = 0;
					score += map[i][j];
					score += map[i][j + 1];
					score += map[i][j+2];
					score += map[i+1][j+1];
					if (score > MAXMAX) MAXMAX = score;
					chk[i][j] = 0;
					chk[i][j + 1] = 0;
					chk[i][j + 2] = 0;
					chk[i + 1][j + 1] = 0;

				}
				if ((chk[i][j] == 0) && (chk[i + 1][j] == 0) && (chk[i + 1][j - 1] == 0) && (chk[i + 2][j] == 0) && (i + 2 < N) && (j - 1 >= 0))
				{
					chk[i][j] = 1;
					chk[i + 1][j] = 1;
					chk[i + 1][j - 1] = 1;
					chk[i + 2][j] = 1;
					score = 0;
					score += map[i][j];
					score += map[i + 1][j];
					score += map[i + 1][j-1];
					score += map[i + 2][j];
					if (score > MAXMAX) MAXMAX = score;
					chk[i][j] = 0;
					chk[i + 1][j] = 0;
					chk[i + 1][j - 1] = 0;
					chk[i + 2][j] = 0;
				}
				if ((chk[i][j] == 0) && (chk[i][j + 1] == 0) && (chk[i][j + 2] == 0) && (chk[i - 1][j + 1] == 0) && (i - 1 >= 0) && (j + 2 < M))
				{
					chk[i][j] = 1;
					chk[i][j + 1] = 1;
					chk[i][j + 2] = 1;
					chk[i - 1][j + 1] = 1;
					score = 0;
					score += map[i][j];
					score += map[i][j+1];
					score += map[i][j+2];
					score += map[i - 1][j+1];
					if (score > MAXMAX) MAXMAX = score;
					chk[i][j] = 0;
					chk[i][j + 1] = 0;
					chk[i][j + 2] = 0;
					chk[i - 1][j + 1] = 0;
				}
				if ((chk[i][j] == 0) && (chk[i+1][j] == 0) && (chk[i + 2][j] == 0) && (chk[i + 1][j + 1] == 0) && (i + 2 < N) && (j + 1 < M))
				{
					chk[i][j] = 1;
					chk[i+1][j] = 1;
					chk[i + 2][j] = 1;
					chk[i + 1][j + 1] = 1;
					score = 0;
					score += map[i][j];
					score += map[i + 1][j];
					score += map[i + 2][j];
					score += map[i + 1][j+1];
					if (score > MAXMAX) MAXMAX = score;
					chk[i][j] = 0;
					chk[i + 1][j] = 0;
					chk[i + 2][j] = 0;
					chk[i + 1][j + 1] = 0;
				}

				
			}
		}
	}


	//³õÀº°Å Ã¶È¸
	return;
}

