#include <bits/stdc++.h>
using namespace std;

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
    // W1<=W
    if (wt[n - 1] <= W)
    {
        return max(
            // true
            val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1),
            // false
            knapsack(wt, val, W, n - 1));
    }
    // W1>W
    else
    {
        // false
        return knapsack(wt, val, W, n - 1);
    }
}

int main()
{

    vector<int> wt{10, 20, 30};
    vector<int> val{60, 100, 120};
    int W = 50;
    int n = 3;
    cout << knapsack(wt, val, W, n);
    return 0;
}