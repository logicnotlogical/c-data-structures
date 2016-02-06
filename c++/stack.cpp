#include "stack.h"
#include <stdexcept>

using namespace std;

template <class T> T Stack<T>::head() {
    if (elements.empty()) {
        throw out_of_range("Stack is empty, no head!");
    }
    
    return elements.back();
}

template <class T> uint8_t Stack<T>::get_length() {
    return length;
}

template <class T> void Stack<T>::push(T const& elem) {
    elements.push_back(elem);
}

template <class T> T Stack<T>::pop() {
    if (elements.empty()) {
        throw out_of_range("Stack is empty!");
    }
    T tmp = head();
    elements.pop_back();
    return tmp;
}

template <class T> Stack<T>::Stack() {
    length = 0;
}
