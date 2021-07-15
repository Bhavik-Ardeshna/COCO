## 0/1 Knapsack Problem



### Variation Problems

<br>

> Subset of sum

> Equal sum partition

> Count of subset sum

> Minimum subset sum difference

> Target Sum

> Count subset with given difference

<br>

### Statement

<br>

```
    // wgt constains Item weight and val constain cost/value of that item
    wgt[] = { I1, I2, I3, I4 }
    val[] = { V1, V2, V3, V4 }
    W = capacity of knapsack
```

<br>

### Constriant

<br>

- _Maximum weight_ can be added in knapsack bag is = **W**
- We need to fill the bag with provided Items such that bag gets full with sum of value of each Items should be **Maximum**

<br>

### NOTE

```
    Fractional Knapsack -----> Greedy Approach  [ Fractional wgt of Items are allowed ]
    0/1 Knapsack -----> DP
    Unbounded Knapsack -----> DP    [ Multiple instance of Items are allowed ]
```

<br>

### Why Knapsack is DP?

<br>

> Here we have choice to include particular items in knapsack

> Here we need to find max/min solution which is optimal solution

<br>

### Base Condition

<br>

```
    wtg[] = { } [ min = 0 ]
    val[] = { } [ min = 0 ]
    W = capacity of knapsack

    ANS: 0
```

> Base Condition with minimum possible solution

```
    if( n==0 || W==0 )
        return 0
```

<br>

### Choice Diagram

<br>

```
                        I1/W1
                      /       \
                W1<=W           W1>W
               /     \            |
            True      False     False
    (include I1       (Not    (Not inlcuded)
    in knapsack)     inlcuded)
```

> Condition

```
    if( W1<=W ){
        return max(
                val[n-1] + knapsack(wgt,val,W-W1,n-1),
                kanpsack(wgt,vla,W,n-1)
        )
    }

    else // W1==W
    {
        return kanpsack(wgt,vla,W,n-1)
    }
```

<br>

## Recursive Knapsack

<br>

```
    int knapsack(int wgt, int val, int W, int n){

        // Base Condition

        if( n==0 || W==0 ) return 0;

        // Choice Conditions

        if( wgt[n-1] <= W ){
            return max(
                    val[n-1] + knapsack(wgt, val, W-wgt[n-1], n-1),  // True
                    kanpsack(wgt, val, W, n-1)  // False
            );
        }

        else // W1==W
        {
            return kanpsack(wgt, val, W, n-1);  // False
        }
    }
```

<br>

> Time Complexity : **_2^n_**

<br>

## Memoization Knapsack

<br>

> Here variable W and n is changing with every call in recursion **_t[n+1][w+1]_**

> **memset( t, -1, sizeof(t))**

> Memoized Condition : **if(t[n][w] != -1) return t[n][w]** _[To check that subproblem was previously calculated or not]_

<Br>

```
    int knapsack(int wgt, int val, int W, int n){

        // Base Condition

            if( n==0 || W==0 ) return 0;

        // Memoized Condition

            if(t[n][W] != -1) return t[n][W];

        // Choice Conditions

            if( wgt[n-1] <= W ){
                return t[n][W] = max(
                        val[n-1] + knapsack(wgt, val, W-wgt[n-1], n-1),  // True
                        kanpsack(wgt, val, W, n-1)  // False
                );
            }

            else // W1==W
            {
                return t[n][W] kanpsack(wgt, val, W, n-1);  // False
            }
    }
```

<br>

> Time Complexity : **_N\*W_**

> Auxillary Space : **_N\*W_**

<br>

## Top-Down Knapsack

<br>

> Here variable W and n is changing with every call in recursion **_t[n+1][w+1]_**

> Here **t[i][j]** give the solution of subproblem with total number of item equals to **i** and W equals to **j**

> Base condition will change to initialization step
> <br>

```
    int knapsack(int wgt, int val, int W, int n){

        for( i=0 to n ){

            for( j=0 to W ){

                // Base Condition

                    if( i==0 || j==0 ) t[i][j] = 0;

                // Choice Conditions

                    if( wgt[i-1] <= j ){
                        t[i][j] = max(
                                        val[i-1] + t[i-1][j-wgt[i-1]],  // True
                                        t[i-1][j]  // False
                                     );
                    }

                    else // W1==W
                    {
                        t[n][W] = t[i-1][j];  // False
                    }

            }
        }
        return t[n][W];
    }
```

<br>

> Time Complexity : **_N\*W_**

> Auxillary Space : **_N\*W_**
