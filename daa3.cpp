#include <bits/stdc++.h>
using namespace std;

// Top-Down (Memoization)
int memoHelper(int i, int cap, const vector<int> &w, const vector<int> &val, vector<vector<int>> &dp)
{
    if (i == 0 || cap == 0)
        return 0;

    if (dp[i][cap] != -1)
        return dp[i][cap];

    if (w[i - 1] <= cap)
        return dp[i][cap] = max(
                   val[i - 1] + memoHelper(i - 1, cap - w[i - 1], w, val, dp), // include item
                   memoHelper(i - 1, cap, w, val, dp)                          // exclude item
               );
    else
        return dp[i][cap] = memoHelper(i - 1, cap, w, val, dp);
}
int memo(int cap, vector<int> &w, vector<int> &val, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, -1));
    return memoHelper(n, cap, w, val, dp);
}

// Bottom-Up (Tabulation)
int knapsack(int capacity, const vector<int> &weights, const vector<int> &values, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][capacity];
}

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    vector<int> weights(n), values(n);

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++)
        cin >> values[i];

    cout << "\nUsing Bottom-Up DP:\n";
    cout << "Maximum value = " << knapsack(capacity, weights, values, n) << endl;

    cout << "\nUsing Top-Down Memoization:\n";
    cout << "Maximum value = " << memo(capacity, weights, values, n) << endl;

    return 0;
}
