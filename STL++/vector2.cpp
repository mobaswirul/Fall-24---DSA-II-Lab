#include <iostream>
#include <vector>
#include <algorithm>  // For std::find and std::sort
using namespace std;

int main() {
    vector<int> numbers = {5, 2, 8, 1, 9, 3};

    // Find the element
    auto it = find(numbers.begin(), numbers.end(), 8);
    if (it != numbers.end()) {
        cout << "Element 8 found at position: " << distance(numbers.begin(), it) << '\n';
    } else {
        cout << "Element 8 not found\n";
    }

    if (it != numbers.end()) {
        numbers.erase(it);
        cout << "Element 8 removed.\n";
    }

    sort(numbers.begin(), numbers.end());
    cout << "Sorted vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << '\n';

    return 0;
}
