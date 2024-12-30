#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    // gas.push_back(gas[0]);
    // cost.push_back(cost[0]);

    int n = gas.size();

    int start = 0;
    int total_gas = gas[0];
    int total_cost = cost[0];
    int current = gas[0];

    for(int i=1; i<n; i++){

        total_gas += gas[i];
        total_cost += cost[i];

        if(current < cost[i - 1]){
            start = i;
            current = gas[i];
        }else{
            current = current - cost[i - 1] + gas[i];
        }

        
        cout<<"From: "<<i-1<<" To: "<<i<<endl;
        cout<<"Current: "<<current<<endl;
        cout<<"Total Gas: "<<total_gas<<endl;
        cout<<"Total Cost: "<<total_cost<<endl;
    }

    // if(current < cost[n - 1]) start = 0;
    // else current = current - cost[n - 1] + gas[0];
    
    if(total_gas < total_cost) cout << -1 << endl;
    else cout << start << endl;
}