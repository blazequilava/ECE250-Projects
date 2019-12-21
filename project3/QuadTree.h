/**
 * This is the Header File for the Quad Tree for Project 3 of ECE 250. Written by Devon Miller-Junk.
 * Contains the necessary information for the implementation of a Quad Tree, including a node class.
 * Each node contains the information of a city and 5 pointers, 4 to each child (4 quadrants of NE, NW, SE, SW) and it's parent.
 * The Type and Attribute Enum are used for traversing the quad tree to find the min/max/total of certain statistics about the city.
*/
#include <string>
using namespace std;
#ifndef QUADTREE_H
#define QUADTREE_H
enum Attribute //Different statistics about the city to be used in traversals
{
    population = 0,
    costOfLiving = 1,
    averageNetSalary = 2
};
enum Type //Types of statistic agregates that can be requested during a traversal.
{
    minType = 0,
    maxType = 1,
    totalType = 2
};
struct Node //Each individual node of the tree.
{
private:
    int selectRegion(double location[]) const; //Mapper function of which quadrant to go to which index in location.

public:
    Node *parent;       //Pointer to the parents node. Not strictly needed for this implementation.
    Node *children[4];  //Pointers to the 4 quadrants
    string name;        //Name of the city
    double location[2]; //Lattitude and Longitude in the order of x,y

    //Data about the city
    long int population;
    long int costOfLiving;
    long int averageNetSalary;

    //Constructors and Destructor
    Node();
    Node(string name, double location[], long int population, long int costOfLiving, long int averageNetSalary);
    ~Node();

    //Operator Overloads
    Node *operator=(const Node *node);
    bool operator==(const Node *node) const;
    bool operator==(double location[]) const;

    //Typical Functions
    bool insert(Node *node);
    Node *search(double location[]);
    long int traversal(Attribute attr, Type type) const;
    string print() const;
};
class QuadTree //Quad tree data structure that is just a pointer to the root
{
public:
    Node *root; //Root of the tree
    int size;   //Size of the tree

    //Constructor and Destructor
    QuadTree();
    ~QuadTree();

    //Typical Functions
    bool insert(Node *node);
    Node *search(double location[]);
    void clear();
    string print();
};
#endif