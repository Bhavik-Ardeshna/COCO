/*Leet Code

Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.*/

/*
wt[] -----> lenght[]
val[] -----> price[]
W -----> N
*/

/*
 it is similar to unbounded knapsack because cutting of same length rod is allowe
*/

#include <bits/stdc++.h>
using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

// DP array
int t[1001][1001];

int RodCutting(vector<int> leng, vector<int> price, int N, int n)
{
    forr(i, n + 1)
    {
        forr(j, N + 1)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;

            if (leng[i - 1] <= j)
                t[i][j] = max(
                    price[i - 1] + t[i][j - leng[i - 1]],
                    t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][N];
}

int main()
{
    vector<int> leng{1, 2, 3, 4};
    vector<int> price{1, 3, 4, 5};
    int N = 7;
    int n = 4;

    cout << "Maximum profit after rod cutting  " << RodCutting(leng, price, N, n) << endl;

    return 0;
}