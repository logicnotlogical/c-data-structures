#include <vector>
#include <stdint.h>

using namespace std;

template <class T>
class Stack {
private:
    vector<T> elements;
    uint8_t length;
public:
    T head();
    uint8_t get_length();
    void push(T const&);
    T pop();
    Stack();
};

template class Stack<uint8_t>;
template class Stack<int>;
