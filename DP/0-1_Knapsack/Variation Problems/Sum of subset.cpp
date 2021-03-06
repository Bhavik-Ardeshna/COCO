/* 

#include <stdio.h>
#include <stdbool.h>
//typedef int bool;
//#define true 1
//#define false 0

bool isSubsetSum(int set[], int n, int sum, int offset) {
    // Base Cases
    if ((sum  + n*offset) == 0)
        return true;
    if (n == 0 && (sum  + n*offset) != 0)
        return false;

    if (set[n - 1] > sum + n*offset)
        return isSubsetSum(set, n - 1, sum, offset);

    return isSubsetSum(set, n - 1, sum, offset) ||
           isSubsetSum(set, n - 1, sum - set[n - 1], offset);
}

int main() {
    int set[] = { -3, 34, -2, 12, 5, 8 };
    int sum = 0;
    int i;
    int n = sizeof(set) / sizeof(set[0]);
    int min = -3;  // TBD code to find minimum
    for (i = 0; i<6; i++) set[i] -= min;

    if (isSubsetSum(set, n, sum, -min) == true)
        printf("Found a subset");
    else
        printf("No subset");
    return 0;
}
*/

#include <bits/stdc++.h>

using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

// DP array
int t[1001][1001];

int Sum_of_Subset_Recursive(vector<int> arr, int tar, int n)
{

    // Base condition
    // Check min i/p
    // When n==0 or tar==0
    if (tar == 0)
        return true;
    if (n == 0)
        return false;
    // Choice diagram condition
    /*
                ITEM1(Val1)
                    - Val1<=Tar
                        -true
                        -false
                    - Val1>Tar
                        -false   
            */
    // Val1<=Tar
    if (arr[n - 1] <= tar)
    {
        return max(
            Sum_of_Subset_Recursive(arr, tar - arr[n - 1], n - 1),
            Sum_of_Subset_Recursive(arr, tar, n - 1));
    }
    // Val1>Tar
    else
    {
        return Sum_of_Subset_Recursive(arr, tar, n - 1);
    }
}

int Sum_of_Subset_Memiozation(vector<int> arr, int tar, int n)
{
    // Base condition
    // Check min i/p
    // When n==0 or tar==0
    if (tar == 0)
        return true;
    if (n == 0)
        return false;
    // Choice diagram condition
    /*
                ITEM1(Val1)
                    - Val1<=Tar
                        -true
                        -false
                    - Val1>Tar
                        -false   
            */

    // Memoization condition
    if (t[n][tar] != -1)
        return t[n][tar];

    // Val1<=Tar
    if (arr[n - 1] <= tar)
    {
        return t[n][tar] = max(
                   Sum_of_Subset_Recursive(arr, tar - arr[n - 1], n - 1),
                   Sum_of_Subset_Recursive(arr, tar, n - 1));
    }

    // Val1>Tar
    else
    {
        return t[n][tar] = Sum_of_Subset_Recursive(arr, tar, n - 1);
    }
}

int Sum_of_Subset_Top_Down(vector<int> arr, int tar, int n)
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
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            if (arr[i - 1] > j)
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][tar];
}

int main()
{

    vector<int> arr{2, 5, 6, 9, 10};
    int tar = 7;
    int n = 5;

    cout << "Recursive Approach " << Sum_of_Subset_Recursive(arr, tar, n) << endl;

    // memset(t, -1, sizeof(t));
    // cout << "Memoization Approach " << Sum_of_Subset_Memiozation(arr, tar, n) << endl;

    cout << "Top Down Approach " << Sum_of_Subset_Top_Down(arr, tar, n) << endl;

    return 0;
}