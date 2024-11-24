#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2(5, 10);
    vector<int> vec3(vec1.begin(), vec1.end());

    vec1.push_back(4);
    vec1[1] = 20;
    vec1.erase(vec1.begin() + 2);
    vec1.insert(vec1.begin(), 99);

    cout << "Using range-based for loop:\n";
    for (int num : vec1) {
        cout << num << " ";
    }
    cout << '\n';

    cout << "Using traditional for loop:\n";
    for (size_t i = 0; i < vec1.size(); ++i) {
        cout << vec1[i] << " ";
    }
    cout << '\n';

    cout << "Using iterators:\n";
    for (auto it = vec1.begin(); it != vec1.end(); ++it) {
        cout << *it << " ";
    }
    cout << '\n';

    return 0;
}
