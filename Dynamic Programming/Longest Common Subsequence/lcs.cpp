// By recursion
// Time complexity : O(n*m)

#include<bits/stdc++.h>
using namespace std;

int lcs(string& s1, string& s2, int i, int j) {
    if(i<0 || j<0) return 0;
    int res = 0;
    res = max(lcs(s1, s2, i-1, j), max(lcs(s1, s2, i, j-1), (lcs(s1, s2, i-1, j-1) + (s1[i]==s2[j])) ) );
    return res;
}

int main() {
    cout << "Enter two strings:\n";
    string s1, s2;
    cin >> s1 >> s2;
    int n, m, x;
    n = s1.size();
    m = s2.size();
    x = lcs(s1, s2, n-1, m-1);
    cout << "Longest common subsequence size is: " << x;
}