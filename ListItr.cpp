//Bamphiane Annie Phongphouthai
//bp8qg
//Sep 3, 2017
//ListItr.cpp

#include <iostream>
#include "ListItr.h"

using namespace std;

ListItr::ListItr(){      //Default Constructor
  current=new ListNode();
  current=NULL;
}

ListItr:: ListItr(ListNode* theNode) {    //Constructor
  current=theNode;
}

bool ListItr::isPastEnd() const{ //true pointing at past the end-> dummy tail
  if(current->next==NULL){  //Dummy tail is when next point to null
    return true;
  }
  else{
    return false;
  }
}

bool ListItr::isPastBeginning() const{  //true pointing before first->dummy head
  if(current->previous ==NULL){   //Dummy head is when previous point to null
    return true;
  }
  else{
    return false;
  }
}

void ListItr::moveForward(){ //advance current to next position
  if(!isPastEnd()){
    current = current->next;
  }
}

void ListItr::moveBackward(){ //move current back
  if(!isPastBeginning()){
    current=current-> previous;
  }
}

int ListItr::retrieve() const{ //returns the value of item in current
  return current->value;
}
