#include <iostream>
#include <vector>
using namespace std;

vector<int> stackVec;

void push(int value) {
    stackVec.push_back(value);  // Add value to the top of the stack
}

void pop() {
    if (!stackVec.empty()) {
        stackVec.pop_back();  // Remove value from the top of the stack
    } else {
        cout << "Stack is empty.\n";
    }
}

int top() {
    if (!stackVec.empty()) {
        return stackVec.back();  // Return the top element
    } else {
        cout << "Stack is empty.\n";
        return -1;  // Return a default value for empty stack
    }
}

bool empty() {
    return stackVec.empty();  // Check if stack is empty
}

size_t size() {
    return stackVec.size();  // Get the size of the stack
}

int main() {
    push(10);
    push(20);
    push(30);

    cout << "Top element: " << top() << '\n';

    pop();
    cout << "Top element after pop: " << top() << '\n';

    cout << "Is stack empty? " << (empty() ? "Yes" : "No") << '\n';
    cout << "Stack size: " << size() << '\n';

    return 0;
}
