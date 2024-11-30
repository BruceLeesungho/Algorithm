#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX (10000)

int prime_arr[MAX + 1];
int cnt = 1; // ->1 is  not prime's cnt

int prime_cnt = 0;
void is_prime(int n)
{
	int root = sqrt(n);
	for (int i = 2; i <= root; i++)
	{
		if (n % i == 0)
		{
			prime_arr[n] = 0;
			cnt++; // not prime.
			return;
		}
	}
}

int main(void)
{
	for (int i = 1; i <= MAX; i++) prime_arr[i] = 1;

	prime_arr[0] = 0;
	prime_arr[1] = 0;

	for (int i = 2; i <= MAX; i++)
	{
		if (prime_arr[i] == true) //소수면 배수 다 지워
		{
			is_prime(i);
			for (int j = i+i; j <= MAX; j = j+i)
			{	
				if (prime_arr[j] == 0) continue;
				prime_arr[j] = 0;
				cnt++;
			}
		}
	}

	prime_arr[2] = 1; 
	
	prime_arr[3] = 1;

	for (int i = 1; i <= MAX; i++)
	{
		if (prime_arr[i] == 1) prime_cnt++;
	}

	printf("%d\n", MAX - cnt);
	printf("%d\n", prime_cnt);
	return 0;
}