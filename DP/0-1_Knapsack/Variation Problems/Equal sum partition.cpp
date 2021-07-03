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
            1 + Sum_of_Subset_Recursive(arr, tar - arr[n - 1], n - 1),
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

    vector<int> arr{5, 1, 5, 19};
    int n = 4;
    int tot_sum = 0;
    for (auto i : arr)
    {
        tot_sum += i;
    }
    if (tot_sum % 2 != 0)
        cout << "Odd total! No partition";
    else
    {
        cout << "Partition " << (Sum_of_Subset_Top_Down(arr, tot_sum / 2, n) ? "is possible" : "not possible") << endl;
    }

    return 0;
}