/* ========================================================================== */
/*                                                                            */
/*   Filename.cpp                                                               */
/*   (c) 2012 Author                                                          */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */

#include <iostream> 
//#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

class Node {
    Node* pnext;
public:
    int data;

    // Constructor taking initial value:
    Node( int value = 0 )
    : pnext( NULL ), data( value )
    {
    }
    // Insert node in front
    // Return a link to the head:
    Node* insert( int value = 0 )
    {
        Node *p;   
       
        p = new Node(value);
        // strcpy(p->item, x);
        p->pnext = Node;
        return p;    
    }

    // Remove node in front:
    void remove_next();

};





int main()
{
    Node MyNode(7);
    Node *Nodeptr = &MyNode;
    //MyList.insert("Batman");

    return 0;
}