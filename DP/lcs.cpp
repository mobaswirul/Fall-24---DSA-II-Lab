#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "AGGTAB";
    string t = "GXTXAYB";

    int n = s.size();
    int m = t.size();

    int dp[n+1][m+1] = {0};

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            int from_top = dp[i-1][j];
            int from_left = dp[i][j-1];
            int from_diagonal = 0;
            if(s[i-1] == t[j-1]) {
                from_diagonal = dp[i-1][j-1] + 1;
            }
            dp[i][j] = max({from_top, from_left, from_diagonal});
        }
    }
    cout<<dp[n][m]<<endl;
}