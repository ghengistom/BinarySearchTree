#include <iostream>


class LinkedList22
{
      

  public:
    struct Node;      
int  a, b;
Node *iterator;
Node *startnode;
Node *holdernode;
bool tf;     
         
    LinkedList22 (int first, int second)
      {a=first; b=second; iterator = NULL; startnode = NULL; holdernode = NULL;}
    int getmax ();
    void INIT();
    void append(int num);
    void iterate();
       
};
