/* ========================================================================== */
/*                                                                            */
/*   Filename.cpp                                                               */
/*   (c) 2012 Author                                                          */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */

#include <iostream>
#include <string>
using namespace std;


class Node {
    Node *pnext;
public:
    string data;

    // Constructor taking initial value:
    Node( string value = NULL )
    : pnext( NULL ), data( value )
    {
    }
    // Insert node in front
    // Return a link to the head:
    Node *insert( string x = NULL )
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

    Node *predecessor(string x)
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

    Node *search(string x)
    {
        if (this == NULL) return (NULL);
    
        if (this->data == x)
            return(this);
        else
            return((this->pnext)->search(x));
    }

    Node *remove(Node *listhead, string x)
    {
        Node *p;            
        Node *pred;        
        // list *search_list(), *predecessor_list();
    
        cout << "Call delete_list" << endl;
        p = this->search(x);
        if (p != NULL) {
            cout << "Got a match" << endl;
            pred = this->predecessor(x);
            if (pred == NULL)  
               listhead = p->pnext;
            else
               pred->pnext = p->pnext;
            cout << "Free p=" << (void*)p << endl;
            delete p; 
            return listhead;           
        }
    }

};

class LinkedList {
    Node *Listhead;
public:

    // Constructor taking initial value:
    LinkedList()
    : Listhead( NULL )
    {
    }

    void insert( string x = NULL )
    {
        if (Listhead == NULL) Listhead = new Node(x);
        else  Listhead = Listhead->insert(x);
    }
    
    void print()
    {
       if (Listhead == NULL) return;
       Listhead->print();
    }
    
    LinkedList *search(string x)
    {
       if (Listhead == NULL) return NULL;
       return (LinkedList *) Listhead->search(x);
    }

    void remove(string x)
    {
        if (Listhead == NULL) return;
        Listhead = Listhead->remove(Listhead, x);
    }

};




int main()
{
    Node MyNode("Robin");
    Node *Listhead = &MyNode;
    Node *foundnode;
    Listhead = Listhead->insert("Batman");
    Listhead = Listhead->insert("Joker");
        
    cout << "Print the list" << endl;
    Listhead->print();
    
    cout << "Find node Batman" << endl;
    foundnode = Listhead->search("Batman");
    cout << "Found " << foundnode->data << endl;
    
    cout << "Delete node Joker" << endl;
    Listhead = Listhead->remove(Listhead, "Joker");
    
    cout << "Print the list" << endl;
    Listhead->print();
    
    
    
    return 0;
}