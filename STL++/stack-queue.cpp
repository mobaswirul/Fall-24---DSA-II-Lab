#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    // Stack example
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);

    cout << "Stack (LIFO):\n";
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << '\n';

    // Queue example
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue (FIFO):\n";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << '\n';

    return 0;
}
