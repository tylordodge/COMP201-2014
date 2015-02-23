#include <iostream>
#include <string>

// Parameterized type
template <typename T>
class Node {
public:
    Node(T d, Node * n) { data = d; next = n; }
    Node(T d)           { data = d; next = NULL; }
    T data;
    Node * next;
};

int main() {
    Node<std::string> node2("world");
    Node<std::string> node1("hello", &node2);
    Node<float> number2(2.0);
    Node<float> number1(1.0, &number2);
    
    for (Node<float> * pointer = &number1;
        pointer != NULL;
        pointer = pointer->next) {
        std::cout << pointer->data << " ";
    }
    
    return 0;
}