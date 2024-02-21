// 0/1 knapsack problem
// Problem link : https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// By Tabulation
// Time complexity : O(N*W)

#include<bits/stdc++.h>
using namespace std;

int knapsack(int w, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    int i, j, temp;
    for(i=1; i<=n; i++) {
        for(j=1; j<=w; j++) {
            temp = dp[i-1][j];
            if(j>=wt[i-1]) {
                temp = max(temp, dp[i-1][j-wt[i-1]]+val[i-1]);
            }
            dp[i][j] = temp;
        }
    }
    return dp[n][w];
}

int main() {
    int w, n, i;
    cout << "Enter number of elements :";
    cin >> n;
    cout << "Enter total weight that can be taken :";
    cin >> w;
    vector<int>wt(n), val(n);
    cout << "Enter all elements value :\n";
    for(i=0; i<n; i++) {
        cin >> val[i];
    }
    cout << "Enter all elements weight :\n";
    for(i=0; i<n; i++) {
        cin >> wt[i];
    }
    int maxValue = knapsack(w, wt, val, n);
    cout << "Max Value that can be carried: " << maxValue;
}
