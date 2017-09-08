//Bamphiane Annie Phongphouthai
//Sep 2, 2017
//bp8qg
//List.cpp
#include <iostream>
#include "List.h"

using namespace std;

List::List(){         //Default Constructor
  head= new ListNode;
  tail= new ListNode;
  head->previous=NULL;
  tail->next =NULL;
  head-> next = tail;
  tail-> previous = head;
  count=0;
}
  
List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}
List::~List(){           //Destructor
  makeEmpty();
  delete tail;
  delete head;
}
  
List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const{      //function: true if list empty, else false
  if (count==0)
    return true;
  else
    return false;
}

void List::makeEmpty(){        //function:removes all items in list except for dummy head and tail nodes
  while(!isEmpty()) {
    int temp = first().retrieve();
    remove(temp);
    }
}
ListItr List::first(){      //sets to first node
  ListItr* temp= new ListItr(head->next);
  if(temp->isPastEnd()){   //if pointing at dummy tail means end of linklist
    temp->moveBackward(); 
    return *temp;
  }
  return *temp;
}

ListItr List::last(){     //returns ListNode in last pos before tail
  ListItr* temp= new ListItr(tail->previous);
  if(temp->isPastBeginning()){   //if pointing at dummy head means end of linklist
    temp-> moveForward();
    return *temp;
  }
  return *temp;
}
  
void List::insertAfter(int x, ListItr position){  //insert x after current
  ListNode* nnode = new ListNode(); //create new node
  //fix new node's pointers to point at right location to insert
  nnode-> value=x;
  nnode-> previous=position.current;
  nnode-> next= position.current->next;
  //fix the pointers of nodes around new node
  position.current-> next->previous=nnode;
  position.current-> next=nnode;
  count++;
}  

void List::insertBefore(int x, ListItr position){  //insert x before current
  ListNode* nnode = new ListNode();
  nnode->previous=position.current-> previous;
  nnode->value=x;
  nnode->next=position.current;
  position.current->previous->next =nnode;
  position.current->previous=nnode;
  count++;
}

void List::insertAtTail(int x){  //inserts x at tail of list
  ListNode* nnode = new ListNode();
  nnode->value =x;
  nnode->next = tail;
  nnode->previous= tail->previous;
  tail->previous->next = nnode;
  tail->previous= nnode;
  count++;
}

void List::remove(int x){   // removes the first occurrence of x
  ListItr fItr = find(x); //find position of x
  fItr.current->previous->next=fItr.current->next;
  fItr.current->next->previous =fItr.current->previous;
  delete fItr.current;
  count--;
}

ListItr List::find(int x){   //points to first occurrence of x
  ListItr* temp = new ListItr(first());
  while(!temp->isPastEnd()){
    if(temp-> current->value==x){
      return *temp;
    }
    else{
    temp->moveForward();
    }
  }
  return *temp;
}

int List::size() const{ //returns number of elements in  list
  return count;
}

void printList(List& theList, bool forward) { //prints list either forward or backwards
  ListItr f = theList.first();
  ListItr l = theList.last();
  
  if(forward){
    while(!f.isPastEnd()){
      cout<<"[ "<<f.retrieve()<<" ] ";
      f.moveForward();
    }
  }
  else{
    while(!l.isPastBeginning()){
      cout<<" [ "<<l.retrieve()<<" ] ";
      l.moveBackward();
    }
  }
  cout<<endl<<endl;
}

