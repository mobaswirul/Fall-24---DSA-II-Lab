#include <bits/stdc++.h>
using namespace std;

int path[1000];

int coinChange(int amount, vector<int>& coins, vector<int>& dp){
    if(amount == 0) return 0;
    if(dp[amount] != -1) return dp[amount];
    int n = coins.size();
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        if(coins[i] == amount) return 1;
        if(coins[i] > amount) continue;

        int retAns = 1 + coinChange(amount - coins[i], coins, dp);

        if(retAns < ans){
            ans = retAns;
            path[amount] = amount - coins[i];
        } 
    }
    return dp[amount] = ans;
}

int main(){
    int amount = 31;
    vector<int> dp(amount + 1, -1);
    vector<int> coins = {25, 10, 1};
    sort(coins.begin(), coins.end(), greater<int>());
    cout << coinChange(amount, coins, dp) << endl;

    // for(int i=0; i<=amount; i++){
    //     cout << i << " " << path[i] << endl;
    // }
    int cr = amount;
    while(cr > 0){
        cout << cr - path[cr] << " ";
        cr = path[cr];
    }
}