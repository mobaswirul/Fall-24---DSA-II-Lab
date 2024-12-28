#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>& p1, pair<int, int>& p2){
    if(p1.first == p2.first) return p1.second < p2.second;
    return p1.first < p2.first;
}

double euclideanDistance(pair<int, int>& p1, pair<int, int>& p2){
    int x = p1.first - p2.first;
    int y = p1.second - p2.second;
    return sqrt(x*x + y*y);
}

double mixedDistance(vector<pair<int, int>>& points, int l, int r, int m, double max_distance){
    double min_distance = max_distance;
    for(int i = m; i >= l; i--){
        for(int j = m+1; j <= r; j++){
            if(points[j].second - points[i].second >= min_distance) break;
            min_distance = min(min_distance, euclideanDistance(points[i], points[j]));
        }
    }
    return min_distance;
}

double closestPair(vector<pair<int, int>>& points, int l, int r){
    if(l == r) return DBL_MAX;
    if(r - l == 1) return euclideanDistance(points[l], points[r]);
    int m = l + (r-l)/2;
    double left_distance = closestPair(points, l, m);
    double right_distance = closestPair(points, m+1, r);
    double min_distance = min(left_distance, right_distance);
    double mixed_distance = mixedDistance(points, l, r, m, min_distance);
    return min(min_distance, mixed_distance);
}

int main(){
    vector<pair<int, int>> points = {{-5, 10}, {15, -20}, {-10, -30}, {25, 35}};

    sort(points.begin(), points.end(), compare);

    cout << closestPair(points, 0, points.size()-1) << endl;
    return 0;
}