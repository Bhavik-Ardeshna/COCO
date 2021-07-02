#include <bits/stdc++.h>
using namespace std;

#define forr(i, n) for (int i = 0; i < n; i++)
#define forrr(i, n) for (int i = 1; i <= n; i++)
#define rforr(i, n) for (int i = n; i >= 0; i--)

// DP array
int t[1001][1001];

//Here we need sum of subset logic to create t array
// So I have used Top-Down approach of sum of subset

void Sum_of_Subset_Top_Down(vector<int> arr, int tar, int n)
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
    // return t[n][tar];
}

int main()
{

    vector<int> arr{3, 1, 4, 2, 2, 1};
    int n = 6;
    int sum = 0;

    for (auto i : arr)
        sum += i;

    // Calling sum of subset method to create DP array
    Sum_of_Subset_Top_Down(arr, sum, n);

    // After creating DP array
    // let's divide array in s1 and s2 with sum of subset
    // now we know we do not need to calculate s2 differently
    // s2 = total_sum - s1
    // Now we need to minimize abs(s2-s1)
    // so, total_sum - s1 - s1 = total_sum - 2*s1;

    // Now in DP array last row tells subproblem that consider all elements in aaray with all possible sum of subset in total range of total sum
    int minn = INT_MAX;

    forr(i, sum)
    {
        if (t[n][i])
        {
            minn = min(minn, abs(sum - 2 * i));
        }
    }
    cout << minn << endl;
    return 0;
}
