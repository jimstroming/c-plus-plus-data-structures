/* ========================================================================== */
/*                                                                            */
/*   Filename.cpp                                                               */
/*   (c) 2012 Author                                                          */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */

#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class List {
    char item[100];             /* data item.  100 character long words */
    List *next;          /* point to successor */
    
  public:  
    void insert(List **, char*);
    
    
} list;


void List::insert(List **l, char* x)
{
    List *p;   
       
    p = new List;
    strcpy(p->item, x);
    p->next = *l;
    *l = p;
}



int main()
{
    List MyList;
    MyList.insert("Batman");

    return 0;
}