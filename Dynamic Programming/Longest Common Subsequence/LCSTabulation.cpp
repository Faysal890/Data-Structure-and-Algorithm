#include<bits/stdc++.h>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int i, j, n = s1.size(), m = s2.size(), left, up, left_up;
    vector< vector<int> > dp(n+1, vector<int>(m+1, 0));
    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            left = dp[i][j-1];
            up = dp[i-1][j];
            if(s1[i-1] == s2[j-1]) left_up = dp[i-1][j-1]+1;
            else{
                left_up = INT_MIN;
            }
            if(left_up > left && left_up > up ) {
                dp[i][j] = left_up;
            }
            else if(up > left) {
                dp[i][j] = up;
            } 
            else{
                dp[i][j] = left;
            }
        }
    }
    string lcs;
    i = n;
    j = m;
    while(i>0 && j>0) {
        up = dp[i-1][j];
        left = dp[i][j-1];
        left_up = dp[i-1][j-1];
        if(up == dp[i][j]) {
            i--;
        }
        else if(left == dp[i][j]) {
            j--;
        }
        else{
            lcs.push_back(s1[i-1]);
            i--;
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << "Length of lcs is: " << dp[n][m] << "\n" << "LCS: " << lcs << "\n";
}