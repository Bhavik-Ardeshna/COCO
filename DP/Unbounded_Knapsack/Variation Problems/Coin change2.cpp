#include <bits/stdc++.h>
using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

// DP array
int t[1001][1001];

int CoinChange(vector<int> coins, int sum, int n)
{

    forr(i, n + 1)
    {
        t[i][0] = 0;
    }
    // Because number of element is zero so we need to take infinite sum hypothetically
    forr(i, sum + 1)
    {
        t[0][i] = INT_MAX - 1;
    }
    forrr(i, n)
    {
        forrr(j, sum)
        {
            if (coins[i - 1] <= j)
            {
                t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum] >= INT_MAX - 1 ? -1 : t[n][sum];
}

int main()
{
    vector<int> coins{1, 2, 3};
    int sum = 5;
    int n = 3;

    cout << "Minimum no of coin change possible  " << CoinChange(coins, sum, n) << endl;

    return 0;
}