#ifndef NODE_H
#define NODE_H
#include <string>
template <class T>
class Node //Node Class
{
public:
    Node *next;
    Node *previous;
    T *value;
    Node()
    {
        this->next = nullptr;
        this->previous = nullptr;
        this->value = new T();
    };
    ~Node()
    {
        delete this->value;
    }
    bool operator==(std::string name)
    {
        return this->value == name;
    };
    void operator=(T *value)
    {
        this->value = value;
    };
};

#endif