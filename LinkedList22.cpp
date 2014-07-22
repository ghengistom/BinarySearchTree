#include <iostream>
#include <cstdlib>
#include <string>
#include "LinkedList22.h"

using namespace std;

struct LinkedList22::Node {
        int x;
        Node *parent;
        Node *less;
        Node *more;
};

int LinkedList22::getmax()
{
  int retval;
  retval = a>b? a : b;
  return retval;
}

void LinkedList22::INIT(){
     int input;
     cin >> input;
  append(input);
  iterate();
  INIT();
}
    
void LinkedList22::append(int num){

        tf = true;

        if(startnode == NULL){
              Node *n = new Node();   // create new Node
              n->x = num;             // set value
              n->parent = NULL;
              n->less = NULL;         // make the node point to the next node.
              n->more = NULL;
              startnode = n;
              tf = false;       
        }
        
        iterator = startnode;
        
        while(tf){
                      if(num < iterator->x){
                             if(iterator->less == NULL || num > iterator->less->x){
                                                  Node *n = new Node();   // create new Node
                                                  n->x = num;             // set value
                                                  n->parent = iterator;
                                                  n->less = iterator->less;         // make the node point to the next node.
                                                  n->more = NULL;
                                                  tf = false; 
                                    //add node with parent iterator and with less iterator->less
                                                  //n->parent->less = n;
                                                  iterator->less = n;
                                    //set parent node to relink with new node
                             } else {
                                    //set iterator to the less than node
                                    iterator = iterator->less;
                             }
                      } else if(num >= iterator->x){ //note that if a value is equal to the checked node it will take it as less than
                             if(iterator->more == NULL || num < iterator->more->x){
                                                  Node *n = new Node();   // create new Node
                                                  n->x = num;             // set value
                                                  n->parent = iterator;
                                                  n->more = iterator->more;         // make the node point to the next node.
                                                  n->more = NULL;
                                                  tf = false; 
                                    //add node with parent iterator and with less iterator->less
                                                  //n->parent->more = n;
                                                  iterator->more = n;
                                    //set parent node to relink with new node
                             } else {
                                    //set iterator to the more than node  
                                    iterator = iterator->more;
                             }
                      } else {
                             cout << "some error";
                      }
            }

        
}

void LinkedList22::iterate(){ //still needs to be setup to do both less and greater than iterations in order to be seen as a full BST
     iterator = startnode;
     tf = true;
     while(tf){
     cout<<iterator->x;
     if(iterator->less != 0){
     cout<<",";
     iterator = iterator->less;
     } else {
     tf = false;       
     }
     }
     cout << endl;
}
