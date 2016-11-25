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

    Node *predecessor(Node *l, int x)
    {
        //printf("Get predecessor\n");
        if ((l == NULL ) || (l->pnext == NULL)){
            // predecessor sought on null list
            return(NULL);    
        }
    
        if ((l->pnext)->data == x)
            return(l);
        else
            return(predecessor(l->pnext,x));
    }

    Node *search(Node *l, int x)
    {
        //printf("Call search_list\n");
        if (l == NULL) return (NULL);
    
        if (l->data == x)
            return(l);
        else
            return(search(l->pnext, x));
    }

  
    

    // Remove node in front:
    void remove_next();

};





int main()
{
    Node MyNode(7);
    Node *Nodeptr = &MyNode;
    Node *foundnode;
    Nodeptr = Nodeptr->insert(4);
    Nodeptr = Nodeptr->insert(3);
        
    cout << "Print the list" << endl;
    Nodeptr->print(Nodeptr);
    
    cout << "Find node 4" << endl;
    foundnode = Nodeptr->search(Nodeptr,4);
    cout << "Found " << foundnode->data << endl;
    
    
    return 0;
}