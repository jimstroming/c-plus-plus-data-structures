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
    // Insert node in front:
    void insert( Node* newNode );

    // Remove node in front:
    void remove_next();

};


/*
void List::insert(char* x)
{
    List *p;   
       
    p = new List;
    strcpy(p->item, x);
    p->next = *l;
    *l = p;
}
*/


int main()
{
    Node MyNode(7);
    Node *Nodeptr = &MyNode;
    //MyList.insert("Batman");

    return 0;
}