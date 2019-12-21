/**
 * This is the Cpp File for the Quad Tree for Project 3 of ECE 250. Written by Devon Miller-Junk.
 * Contains the necessary information for the implementation of a Quad Tree, including a node class.
 * Each node contains the information of a city and 5 pointers, 4 to each child (4 quadrants of NE, NW, SE, SW) and it's parent.
 * The Type and Attribute Enum are used for traversing the quad tree to find the min/max/total of certain statistics about the city.
*/

#include "QuadTree.h"
#ifndef QUADTREE_CPP
#define QUADTREE_CPP

//Takes the coordinates of a city and compares them to those of the current city to determine
//Which quadrant to go into.
int Node::selectRegion(double location[]) const
{
    int result = -1;
    if (location[0] >= this->location[0] && location[1] > this->location[1])
    {
        result = 0;
    }
    else if (location[0] < this->location[0] && location[1] >= this->location[1])
    {
        result = 1;
    }
    else if (location[0] <= this->location[0] && location[1] < this->location[1])
    {
        result = 2;
    }
    else if (location[0] > this->location[0] && location[1] <= this->location[1])
    {
        result = 3;
    }
    return result;
}

//Constructors
Node::Node()
{
    for (int i = 0; i < 4; i++)
    {
        this->children[i] = nullptr;
    }
    for (int i = 0; i < 2; i++)
    {
        this->location[i] = 0;
    }
    this->parent = nullptr;
    this->name = "";
    this->population = -1;
    this->costOfLiving = -1;
    this->averageNetSalary = -1;
}

Node::Node(string name, double location[], long int population, long int costOfLiving, long int averageNetSalary)
{
    for (int i = 0; i < 4; i++)
    {
        this->children[i] = nullptr;
    }
    for (int i = 0; i < 2; i++)
    {
        this->location[i] = location[i];
    }
    this->parent = nullptr;
    this->name = name;
    this->population = population;
    this->costOfLiving = costOfLiving;
    this->averageNetSalary = averageNetSalary;
}

//Destructor
Node::~Node()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->children[i] != nullptr)
        {
            delete this->children[i];
        }
    }
}

//Operator Overloads
Node *Node::operator=(const Node *node)
{
    for (int i = 0; i < 4; i++)
    {
        this->children[i] = node->children[i];
    }
    for (int i = 0; i < 2; i++)
    {
        this->location[i] = node->location[i];
    }
    this->parent = node->parent;
    this->name = node->name;
    this->population = node->population;
    this->costOfLiving = node->costOfLiving;
    this->averageNetSalary = node->averageNetSalary;
}

bool Node::operator==(const Node *node) const
{
    for (int i = 0; i < 2; i++)
    {
        if (this->location[i] != node->location[i])
        {
            return false;
        }
    }
    if (this->name != node->name)
    {
        return false;
    }
    if (this->population != node->population)
    {
        return false;
    }
    if (this->costOfLiving != node->costOfLiving)
    {
        return false;
    }
    if (this->averageNetSalary != node->averageNetSalary)
    {
        return false;
    }
    return true;
}

bool Node::operator==(double location[]) const
{
    for (int i = 0; i < 2; i++)
    {
        if (this->location[i] != location[i])
        {
            return false;
        }
    }
    return true;
}

//Insert the given node as a leaf (if the node is not already in the tree).
bool Node::insert(Node *node)
{
    int index = this->selectRegion(node->location);
    if (index >= 0)
    {
        if (this->children[index] == nullptr)
        {

            this->children[index] = node;
            node->parent = this;
            return true;
        }
        else
        {
            return this->children[index]->insert(node);
        }
    }
    //Error Case. Either a location isn't defined or the location is equal to the current location.
    return false;
}

//Search for a node with coordinates of location. Return said node.
Node *Node::search(double location[])
{
    int index = this->selectRegion(location);
    if (index >= 0)
    {
        if (this->children[index] != nullptr)
        {
            return this->children[index]->search(location);
        }
        return nullptr;
    }
    //Either a location isn't defined or the location is equal to the current location.
    if ((*this) == location)
    {
        return this;
    }
    return nullptr;
}

//Traverse the tree to determine the min/max/total of a certain value.
long int Node::traversal(Attribute attr, Type type) const
{
    long int result = 0;
    switch (attr)
    {
    case 0:
        result = this->population;
        break;
    case 1:
        result = this->costOfLiving;
        break;
    case 2:
        result = this->averageNetSalary;
        break;
    default:
        result = -1;
        break;
    }
    if (result == -1)
    {
        return -1;
    }
    for (int i = 0; i < 4; i++)
    {
        long int subTraversal;
        if (this->children[i] != nullptr)
        {
            switch (type)
            {
            case 0:
                subTraversal = this->children[i]->traversal(attr, type);
                result = subTraversal < result ? subTraversal : result;
                break;
            case 1:
                subTraversal = this->children[i]->traversal(attr, type);
                result = subTraversal > result ? subTraversal : result;
                break;
            case 2:
                result += this->children[i]->traversal(attr, type);
                break;
            }
        }
        if (result == -1)
        {
            return -1;
        }
    }
    return result;
}

//Print the names of the cities (in-order traversal).
string Node::print() const
{
    string result = "";
    for (int i = 0; i < 4; i++)
    {
        if (this->children[i] != nullptr)
        {
            result += this->children[i]->print();
        }
        if (i == 1)
        {
            result += this->name + " ";
        }
    }
    return result;
}

//Tree Functions

//Constructor
QuadTree::QuadTree()
{
    this->root = nullptr;
    this->size = 0;
}

//Destructor
QuadTree::~QuadTree()
{
    if (this->root != nullptr)
    {
        delete this->root;
    }
}

//Insert Node as a leaf if it isn't already in the tree.
bool QuadTree::insert(Node *node)
{
    bool result = false;
    if (this->root == nullptr)
    {
        result = true;
        this->root = node;
        node->parent = nullptr;
    }
    else
    {
        result = this->root->insert(node);
    }
    this->size = result ? this->size + 1 : this->size;
    return result;
}

//Search the tree for a node with the given location and return the node.
Node *QuadTree::search(double location[])
{
    if (this->root == nullptr)
    {
        return nullptr;
    }
    return this->root->search(location);
}

//Delete all nodes in the tree and set the size to 0.
void QuadTree::clear()
{
    if (this->root != nullptr)
    {
        delete this->root;
    }
    this->root = nullptr;
    this->size = 0;
}

//Print the tree using an in-order traversal.
string QuadTree::print()
{
    return this->root == nullptr ? "" : this->root->print();
}
#endif