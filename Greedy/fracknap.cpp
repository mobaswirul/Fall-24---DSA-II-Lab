#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    return a.second > b.second;
}

int main() {
    vector<pair<int, int>> amountTotalProfit = {
        {10, 100},
        {20, 50},
        {5, 60},
        {12, 144}
    };

    vector<pair<int, double>> amountUnitProfit;
    for(auto& p : amountTotalProfit) {
        amountUnitProfit.push_back({p.first, 1.0 * p.second / p.first});
    }

    sort(amountUnitProfit.begin(), amountUnitProfit.end(), compare);

    int capacity = 20;
    double totalProfit = 0;

    for(auto& p : amountUnitProfit) {
        if(capacity >= p.first) {
            capacity -= p.first;
            totalProfit += p.second * p.first;
        } else {
            totalProfit += p.second * capacity;
            break;
        }
    }

    cout << totalProfit << endl;
}