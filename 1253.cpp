#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int a;
    int result = 0;

    vector<int> V;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a;
        V.push_back(a);
    }
    sort(V.begin(), V.end());

    int start_p, end_p;

    for (int n = 0; n < N; n++)
    {
        start_p = 0;
        end_p = N - 1;
        
        int K = V[n];
        
        int sum_cnt;
        while (start_p < end_p)
        {
            if (start_p == n)
            {
                start_p++;
                continue;
            }
            else if (end_p == n)
            {
                end_p--;
                continue;
            }

            sum_cnt = V[start_p] + V[end_p];
            if (sum_cnt == K)
            {
                result++;
                break;
            }
            else if (sum_cnt < K)
            {
                start_p++;
            }
            else
            {
                end_p--;
            }
        }
    }

    cout << result;
    return 0;
}