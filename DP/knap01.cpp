#include <bits/stdc++.h>
using namespace std;


vector<pair<int, int>> items = {
    {4, 12},
    {10, 4},
    {2, 2},
    {2, 1},
    {1, 1}
    // per_unit_value, weight
};

int number_of_items = 5;

int memory[5][16];

int knapsack(int remaining_weight, int index){
    if(remaining_weight == 0) return 0;
    if(index == number_of_items) return 0;

    if(memory[index][remaining_weight] != -1)
     return memory[index][remaining_weight];

    int take = 0, leave = 0;
    if(items[index].second > remaining_weight){
        take = 0;
    }else {
        int profit = items[index].first * items[index].second;
        int remaining_profit = 
            knapsack(remaining_weight - items[index].second, index + 1);
        take = profit + remaining_profit;
    }

    leave = knapsack(remaining_weight, index + 1);
    return memory[index][remaining_weight] = max(take, leave);
}

int main(){
    memset(memory, -1, sizeof(memory));

    cout << knapsack(15, 0) << endl;
    return 0;
}