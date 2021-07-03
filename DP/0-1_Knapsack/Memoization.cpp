#include <bits/stdc++.h>
using namespace std;

// DP array

int t[1001][1001];

int knapsack(vector<int> wt, vector<int> val, int W, int n)
{

    // Base condition
    // Check min i/p
    // When n==0 or W==0
    if (n == 0 || W == 0)
        return 0;

    // Choice diagram condition
    /*
        ITEM1(W1)
            - W1<=W
                -true
                -false
            - W1>W
                -false   
    */

    // Check that value of state is already is calculated
    if (t[n][W] != -1)
        return t[n][W];

    // W1<=W
    if (wt[n - 1] <= W)
    {
        return t[n][W] = max(
                   val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1),
                   knapsack(wt, val, W, n - 1));
    }

    // W1>W
    else
    {
        return t[n][W] = knapsack(wt, val, W, n - 1);
    }
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