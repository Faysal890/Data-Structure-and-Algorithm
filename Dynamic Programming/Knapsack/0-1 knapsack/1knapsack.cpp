// 0/1 knapsack problem
// Problem link : https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// By recursion
// Time complexity : O(N*W)

#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000];
int knapsack(int w, vector<int>& wt, vector<int>& val, int n) {
    if(n<0 || w<=0) return 0;
    if(dp[w][n] !=-1) return dp[w][n];
    int res = 0;
    res = knapsack(w, wt, val, n-1);
    if(w >= wt[n]) {
        res = max(res, knapsack(w-wt[n], wt, val, n-1)+val[n]);
    }
    return dp[w][n] = res;
}


int main() {
    int w, n, i;
    cout << "Enter number of elements :";
    cin >> n;
    cout << "Enter total weight that can be taken :";
    cin >> w;
    vector<int>wt(n), val(n);
    cout << "Enter all elements value:\n";
    for(i=0; i<n; i++) {
        cin >> val[i];
    }
    cout << "Enter all elements weight :\n";
    for(i=0; i<n; i++) {
        cin >> wt[i];
    }
    memset(dp, -1, sizeof(dp));
    int maxValue = knapsack(w, wt, val, n-1);
    cout << "Max Value that can be carried: " << maxValue;
}