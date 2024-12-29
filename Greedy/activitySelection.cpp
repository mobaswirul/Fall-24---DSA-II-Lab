#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    vector<pair<int, int>> activities = {{0, 6}, {1, 2}, {5, 7}, {3, 4}, {7, 9}, {8, 9}};
    
    sort(activities.begin(), activities.end(), comparator);

    int last = -1;

    int sz = activities.size();

    for(int i=0; i<sz; i++){
        if(activities[i].first >= last){
            cout << "Selected: " << activities[i].first << " " << activities[i].second << endl;
            last = activities[i].second;
        }else{
            cout << "Not selected: " << activities[i].first << " " << activities[i].second << endl;
        }
    }
}