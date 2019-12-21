#include "Binarytree.h"
#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

Node::Node(int value = 0)
{
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->value = value;
    this->height = 0;
}

Node::~Node()
{
    if (this->left != nullptr)
    {
        delete this->left;
    }
    if (this->right != nullptr)
    {
        delete this->right;
    }
}

Node *Node::operator=(const Node *node)
{
    this->parent = node->parent;
    this->left = node->left;
    this->right = node->right;
    this->value = node->value;
    this->height = node->height;
}

Node *Node::successor()
{
    if (this->right != nullptr)
    {
        Node *currNode = this->right;
        while (currNode->left != nullptr)
        {
            currNode = currNode->left;
        }
        return currNode;
    }
    else if (this->parent == nullptr)
    {
        return nullptr;
    }
    else
    {
        Node *currNode = this;
        while (currNode->parent != nullptr)
        {
            if (currNode->parent->right != currNode)
            {
                return currNode->parent;
            }
            currNode = currNode->parent;
        }
        return nullptr;
    }
    return nullptr;
}

Node *Node::predeccessor()
{
    if (this->left != nullptr)
    {
        Node *currNode = this->left;
        while (currNode->right != nullptr)
        {
            currNode = currNode->right;
        }
        return currNode;
    }
    else if (this->parent == nullptr)
    {
        return nullptr;
    }
    else
    {
        Node *currNode = this;
        while (currNode->parent != nullptr)
        {
            if (currNode->parent->left != currNode)
            {
                return currNode->parent;
            }
            currNode = currNode->parent;
        }
        return nullptr;
    }
    return nullptr;
}

void Node::resetHeight()
{
    int leftHeight = this->left == nullptr ? -1 : this->left->height;
    int rightHeight = this->right == nullptr ? -1 : this->right->height;
    this->height = leftHeight > rightHeight ? leftHeight : rightHeight;
    if (this->parent != nullptr)
    {
        this->parent->resetHeight();
    }
}

int Node::insert(int value, bool equalOn = true)
{
    if (this->value == value)
    {
        if (equalOn)
        {
            if (this->left == nullptr)
            {
                this->left = new Node(value);
                this->left->parent = this;
                this->height = this->height > 1 ? this->height : 1;
                return this->height;
            }
            else
            {
                int height = this->left->insert(value, equalOn) + 1;
                this->height = height > this->height ? height : this->height;
                return this->height;
            }
        }
        else
        {
            if (this->right == nullptr)
            {
                this->right = new Node(value);
                this->right->parent = this;
                this->height = this->height > 1 ? this->height : 1;
                return this->height;
            }
            else
            {
                int height = this->right->insert(value, equalOn) + 1;
                this->height = height > this->height ? height : this->height;
                return this->height;
            }
        }
    }
    else if (this->value > value)
    {
        if (this->right == nullptr)
        {
            this->right = new Node(value);
            this->right->parent = this;
            this->height = this->height > 1 ? this->height : 1;
            return this->height;
        }
        else
        {
            int height = this->right->insert(value, equalOn) + 1;
            this->height = height > this->height ? height : this->height;
            return this->height;
        }
    }
    else
    {
        if (this->left == nullptr)
        {
            this->left = new Node(value);
            this->left->parent = this;
            this->height = this->height > 1 ? this->height : 1;
            return this->height;
        }
        else
        {
            int height = this->left->insert(value, equalOn) + 1;
            this->height = height > this->height ? height : this->height;
            return this->height;
        }
    }
}

Node *Node::search(int value)
{
    if (this->value == value)
    {
        return this;
    }
    else if (this->value < value)
    {
        if (this->left == nullptr)
        {
            return nullptr;
        }
        else
        {
            return this->left->search(value);
        }
    }
    if (this->right == nullptr)
    {
        return nullptr;
    }
    return this->right->search(value);
}

BinaryTree::BinaryTree(bool equalOn = true)
{
    this->root = nullptr;
    this->equalOnLeft = equalOn;
}

BinaryTree::~BinaryTree()
{
    delete this->root;
}

void BinaryTree::insert(int value)
{
    this->size++;
    if (this->root == nullptr)
    {
        this->root = new Node(value);
    }
    else
    {
        this->root->insert(value, this->equalOnLeft);
    }
}

Node *BinaryTree::search(int value)
{
    if (this->root == nullptr)
    {
        return nullptr;
    }
    return this->root->search(value);
}

bool BinaryTree::deletion(int value)
{
    Node *toDelete = this->search(value);
    if (toDelete == nullptr)
    {
        return false;
    }
    this->size--;
    if (toDelete->left == nullptr && toDelete->right == nullptr)
    {
        //No Child Case
        if (toDelete->parent == nullptr)
        {
            delete toDelete;
            this->size = 0;
            this->root = nullptr;
            return true;
        }
        else
        {
            Node *toDeleteParent = toDelete->parent;
            if (toDeleteParent->left->value == toDelete->value)
            {
                toDeleteParent->left = nullptr;
            }
            else
            {
                toDeleteParent->right = nullptr;
            }
            delete toDelete;
            toDeleteParent->resetHeight();
            return true;
        }
    }
    else if (toDelete->left == nullptr || toDelete->right == nullptr)
    {
        //One Child Case
        if (toDelete->parent == nullptr)
        {
            if (toDelete->left == nullptr)
            {
                this->root = toDelete->right;
                toDelete->right->parent = nullptr;
            }
            else
            {
                this->root = toDelete->right;
                toDelete->right->parent = nullptr;
            }
            return true;
        }
        else
        {
            Node *toDeleteParent = toDelete->parent;
            if (toDeleteParent->left->value == toDelete->value)
            {
                if (toDelete->left == nullptr)
                {
                    this->root = toDelete->right;
                    toDelete->right->parent = nullptr;
                }
                else
                {
                    this->root = toDelete->right;
                    toDelete->right->parent = nullptr;
                }
            }
            else
            {
                toDeleteParent->right = nullptr;
            }
            delete toDelete;
            toDeleteParent->resetHeight();
            return true;
        }
    }
    else
    {
        //No Child case
    }
}
#endif