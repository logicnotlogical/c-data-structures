#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack<int> stack;
    stack.push(7);
    stack.push(18);
    cout << stack.pop() << std::endl;
    cout << stack.pop() << std::endl;

    return 0;
}
