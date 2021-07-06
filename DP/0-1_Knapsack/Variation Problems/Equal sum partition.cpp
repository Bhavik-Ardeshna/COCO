#include <bits/stdc++.h>

using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

// DP array
int t[1001][1001];

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