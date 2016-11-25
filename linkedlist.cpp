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
    Node *pnext;
public:
    int data;

    // Constructor taking initial value:
    Node( int value = 0 )
    : pnext( NULL ), data( value )
    {
    }
    // Insert node in front
    // Return a link to the head:
    Node *insert( int x = 0 )
    {
        Node *p;   
       
        p = new Node(x);
        p->pnext = this;    
        return p;    
    }
    
    void print()
    {
        cout << (void *)this << " contains " << this->data << endl;
        if (this->pnext == NULL) return;        
        return (this->pnext)->print();
    }    

    Node *predecessor(int x)
    {
        if ((this == NULL ) || (this->pnext == NULL)){
            // predecessor sought on null list
            return(NULL);    
        }
    
        if ((this->pnext)->data == x)
            return(this);
        else
            return((this->pnext)->predecessor(x));
    }

    Node *search(int x)
    {
        if (this == NULL) return (NULL);
    
        if (this->data == x)
            return(this);
        else
            return((this->pnext)->search(x));
    }


};





int main()
{
    Node MyNode(7);
    Node *Listhead = &MyNode;
    Node *foundnode;
    Listhead = Listhead->insert(4);
    Listhead = Listhead->insert(3);
        
    cout << "Print the list" << endl;
    Listhead->print();
    
    cout << "Find node 4" << endl;
    foundnode = Listhead->search(4);
    cout << "Found " << foundnode->data << endl;
    
    
    return 0;
}