#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    // Using map (ordered)
    map<string, int> orderedMap;
    orderedMap["Alice"] = 25;
    orderedMap["Bob"] = 30;
    orderedMap["Charlie"] = 20;

    cout << "Contents of map (ordered):\n";
    for (const auto& entry : orderedMap) {
        cout << entry.first << ": " << entry.second << endl;
    }

    // Using unordered_map
    unordered_map<string, int> unorderedMap;
    unorderedMap["Alice"] = 25;
    unorderedMap["Bob"] = 30;
    unorderedMap["Charlie"] = 20;

    cout << "\nContents of unordered_map:\n";
    for (const auto& entry : unorderedMap) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
