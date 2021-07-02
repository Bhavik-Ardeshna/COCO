/*You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.*/

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

    if (tar == 0)
        return 1;
    if (n == 0)
        return 0;

    if (t[n][tar] != -1)
        return t[n][tar];

    if (arr[n - 1] <= tar)
        return CountSumOfSubset(arr, tar - arr[n - 1], n - 1) + CountSumOfSubset(arr, tar, n - 1);
    else
        return CountSumOfSubset(arr, tar, n - 1);
}

int main()

{
    memset(t, -1, sizeof(t));
    vector<int> arr{
        1, 1, 1, 1, 1};
    int n = 5;
    int diff = 3;
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