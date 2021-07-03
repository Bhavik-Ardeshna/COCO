/*You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.*/

/*
dp[n][sum]

dp[i][j] = 1 if subset sum = j is possible by (1, i) elements, add, sub, skip
         = 0 subset sum = j not possible

dp[i][j] = dp[i - 1][j]         // skip this element, 
dp[i][j] |= dp[i - 1][j - a[i]] // add this element
dp[i][j] |= dp[i - 1][j + a[i]] // subtract this element
*/

#include <bits/stdc++.h>
using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

// DP array
int t[1001][1001];

//using memiozation
int CountSumOfSubset(vector<int> arr, int tar, int n)
{

    forr(i, tar)
    {
        t[0][i] = false;
    }
    forr(i, n)
    {
        t[i][0] = true;
    }
    forrr(i, n)
    {
        forrr(j, tar)
        {

            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            if (arr[i - 1] > j)
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][tar];
}

int main()

{
    memset(t, -1, sizeof(t));
    vector<int> arr{
        2, 3, 5, 1};
    int n = 3;
    int diff = 1;
    // Now we need s1-s2 = diff
    // And s1+s2=total_sum
    // In equal we can easly able to find s1 value becauz it's total_sum/2
    // Here by solving above to eqn, we get s1 = (diff+sum)/2

    int sum = 0;
    forr(i, n) sum += arr[i];

    int s1 = (diff + sum) / 2;

    // Now count the subset which sum is equal to s1 in an array
    // So problem reduce to count sum of subset
    cout << "No of subset with diff " << diff << " is " << CountSumOfSubset(arr, s1, n) << endl;
    return 0;
}