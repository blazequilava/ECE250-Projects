#ifndef BINARYTREE_H
#define BINARYTREE_H
enum Traversal
{
    postOrder,
    inOrder,
    preOrder
};
struct Node
{
    Node *parent;
    Node *left;
    Node *right;
    int value;
    int height;
    Node(int value = 0);
    ~Node();

    Node *operator=(const Node *node);
    Node *successor();
    Node *predeccessor();
    void resetHeight();
    int insert(int value, bool equalOn = true);
    Node *search(int value);
    bool deletion(int value);
    //int *traversal(Traversal order) const;
};
class BinaryTree
{
private:
    Node *root;
    bool equalOnLeft;
    int size;

public:
    BinaryTree(bool equalOn = true);
    ~BinaryTree();

    void insert(int value);
    Node *search(int value);
    bool deletion(int value);
    int *traversal(Traversal order) const;
    Node *getRoot() const;
    void print() const;
};
#endif