#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.push(1);
    pq.push(9);
    pq.push(3);

    cout << "Priority Queue elements (max-heap): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << '\n';

    pq.push(7);
    pq.push(4);

    cout << "Priority Queue after manipulation (max-heap): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << '\n';

    return 0;
}
