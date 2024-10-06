#include<iostream>
#include<vector>
using namespace std;


int main(void)
{
	int N, M;
	int Arr;
	long long Sss = 0;
	int rem;
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	vector <long long> V(1000 + 1);

	cin >> N >> M;

	for (int a = 1; a <= N; a++)
	{
		cin >> Arr;

		Sss = Arr + Sss;

		V[Sss % M]++;
	}


	long long sum = 0;
	long long mid;
	sum += V[0];

	for (int i = 0; i <= M; i++)
	{
		if (V[i] > 1)
		{
			mid = (V[i] * (V[i] - 1)) / 2;
			sum += mid;
		}
	}

	cout << sum;

	return 0;
}
