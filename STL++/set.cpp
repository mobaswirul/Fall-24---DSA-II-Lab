#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> numbers = {5, 2, 8, 1, 9, 3};
    numbers.insert(4);
    numbers.erase(2);

    cout << "Set elements (sorted): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << '\n';

    if (numbers.find(8) != numbers.end()) {
        cout << "Element 8 found in the set.\n";
    } else {
        cout << "Element 8 not found in the set.\n";
    }

    return 0;
}
