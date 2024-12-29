#include <bits/stdc++.h>
using namespace std;

pair<int, int> findSecondMax(vector<int> &v, int left, int right){
    if(left == right) {
        return {v[left], INT_MIN};
    }

    int mid = left + (right - left) / 2;
    pair<int, int> lm = findSecondMax(v, left, mid);
    pair<int, int> rm = findSecondMax(v, mid + 1, right);

    pair<int, int> result;
    if(lm.first > rm.first) {
        result.first = lm.first;
        result.second = max(lm.second, rm.first);
    } else {
        result.first = rm.first;
        result.second = max(rm.second, lm.first);
    }

    return result;
}

int main() {
    vector<int> v = {5, 8, 9, -2, -1, 12, 1, 3};

    pair<int, int> result = findSecondMax(v, 0, v.size() - 1);
    cout << "Second max: " << result.second << endl;
}