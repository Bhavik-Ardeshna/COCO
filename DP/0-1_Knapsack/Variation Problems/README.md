## Sum of Subset

> max ----> ||

```
    bool SumOfSubset(int arr, int tar, int n){

        for(i=0 to tar)
            t[0][i] = false;

        for(i=0 to n)
            t[i][0] = true;

        for( i=0 to n ){
            for( j=0 to tar )

                    if( wgt[i-1] <= j ){
                        t[i][j] = arr[i-1] + t[i-1][j-arr[i-1]] ||  t[i-1][j];

                    }

                    else // W1==W
                    {
                        t[n][W] = t[i-1][j];
                    }
            }
        }
        return t[n][W];
    }
```

<br>

## Equal Sum Partition

```
    for(i=0 to n)
        total_sum += arr[i];

    if(total_sum % 2 != 0) // ODD
        cout<< "Not possible";

    else // EVEN
        cout<< SumOfSubset(arr,total_sum/2,n);
```

## Count sum of Subset

> **_SumOfSubet ----> CountSumOfSubset_** [ || ----> + ]

```
    int CountSumOfSubset(int arr, int tar, int n){

        for(i=0 to tar)
            t[0][i] = false;

        for(i=0 to n)
            t[i][0] = true;

        for( i=0 to n ){
            for( j=0 to tar )

                    if( wgt[i-1] <= j ){
                        t[i][j] = arr[i-1] + t[i-1][j-arr[i-1]] +  t[i-1][j];

                    }

                    else // W1==W
                    {
                        t[n][W] = t[i-1][j];
                    }
            }
        }
        return t[n][W];
    }
```

<br>

## Minimum Subset Sum Difference

> After creating DP array
> let's divide array in s1 and s2 with sum of subset
> now we know we do not need to calculate s2 differently
> s2 = total_sum - s1
> Now we need to minimize abs(s2-s1)
> so, total_sum - s1 - s1 = total_sum - 2\*s1;
