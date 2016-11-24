/* ========================================================================== */
/*                                                                            */
/*   Filename.cpp                                                               */
/*   (c) 2012 Author                                                          */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <iostream>
#include <string>
using namespace std;


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
        p->pnext = this;    
        return p;    
    }
    
    void print(Node *l)
    {
        cout << (void *)l << " contains " << l->data << endl;
        if (l->pnext == NULL) return;        
        return print(l->pnext);
    }    
    

    // Remove node in front:
    void remove_next();

};





int main()
{
    Node MyNode(7);
    Node *Nodeptr = &MyNode;
    Nodeptr = Nodeptr->insert(4);
    Nodeptr = Nodeptr->insert(3);
        
    cout << "Print the list" << endl;
    Nodeptr->print(Nodeptr);
    
    return 0;
}