#include <bits/stdc++.h>
using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

// DP array
int t[1001][1001];

int Unbounded_Recursive(vector<int> wt, vector<int> val, int W, int n)
{

    //Base Condidtion
    if (n == 0 || W == 0)
        return 0;

    // W1<=W
    // if item is considered that instead of calling for n-1 we will call for n to allow multiple instance
    if (wt[n - 1] <= W)
    {
        return max(
            val[n - 1] + Unbounded_Recursive(wt, val, W - wt[n - 1], n),
            Unbounded_Recursive(wt, val, W, n - 1));
    }

    // W1>W
    else
    {
        return Unbounded_Recursive(wt, val, W, n - 1);
    }
}

int Memoization_Recursive(vector<int> wt, vector<int> val, int W, int n)
{
    //Base Condidtion
    if (n == 0 || W == 0)
        return 0;

    if (t[n][W] != -1)
        return t[n][W];

    // W1<=W
    // if item is considered that instead of calling for n-1 we will call for n to allow multiple instance
    if (wt[n - 1] <= W)
    {
        return t[n][W] = max(
                   val[n - 1] + Unbounded_Recursive(wt, val, W - wt[n - 1], n),
                   Unbounded_Recursive(wt, val, W, n - 1));
    }

    // W1>W
    else
    {
        return t[n][W] = Unbounded_Recursive(wt, val, W, n - 1);
    }
}

int Top_Down_Recursive(vector<int> wt, vector<int> val, int W, int n)
{
    forr(i, n + 1)
    {
        forr(j, W + 1)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;

            if (wt[i - 1] <= j)
                t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);

            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][W];
}

int main()
{

    // vector<int> wt{1, 50};
    // vector<int> val{1, 30};
    // int W = 100;
    // int n = 2;

    vector<int> wt{1, 3, 4, 5};
    vector<int> val{10, 40, 50, 70};
    int W = 8;
    int n = 4;

    cout << "Recursive Approach " << Unbounded_Recursive(wt, val, W, n) << endl;

    // memset(t, -1, sizeof(t));
    // cout << "Memoization Approach " << Memoization_Recursive(wt, val, W, n) << endl;

    cout << "Top Down Approach " << Top_Down_Recursive(wt, val, W, n) << endl;

    return 0;
}
