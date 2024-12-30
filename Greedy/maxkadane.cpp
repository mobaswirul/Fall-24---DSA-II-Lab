#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> ara = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = ara.size();
    int max_sum = ara[0];
    int endAtI = ara[0];

    for(int i = 1; i < n; i++){
        endAtI = max(ara[i], endAtI + ara[i]);
        max_sum = max(max_sum, endAtI);
    }

    cout << max_sum << endl;
}