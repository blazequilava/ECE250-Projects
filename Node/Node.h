//Node.h File for a linked list class
//Written by Devon Miller-Junk for the Purposes of ECE250

template <class T>
class Node
{
private:
    T value;
    Node<T> *next;

public:
    Node(const T value);
    Node();
    ~Node();
    T getValue();
    void setValue(const T value);
    Node<T> getNext();
    void setNext(Node<T> next);
};