#include <bits/stdc++.h>
using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

// DP array
int t[1001][1001];

int knapsack(vector<int> wt, vector<int> val, int W, int n)
{
    // Replace n---> i and W---> j in memoization
    forr(i, n + 1)
    {
        forr(j, W + 1)
        {
            // Base condition
            // Check min i/p
            // When n==0 or W==0
            if (i == 0 || j == 0)
                t[i][j] = 0;
            // Choice diagram condition
            /*
                ITEM1(W1)
                    - W1<=W
                        -true
                        -false
                    - W1>W
                        -false   
            */
            // W1<=W
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            // W1>W
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}

int main()
{

    vector<int> wt{10, 20, 30};
    vector<int> val{60, 100, 120};
    int W, n;
    W = 50;
    n = 3;
    cout << knapsack(wt, val, W, n) << endl;
    return 0;
}