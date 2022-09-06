#include "split.h"
//#include "split.cpp"
#include <iostream>


void printLinkedList(Node *& in)
{
  Node *temp = in;
  while(temp != nullptr)
  {
    std::cout << temp->value << std::endl;
    temp = temp->next;
  }
}

void constructList(Node *& in)
{
  Node *temp;
  for (int i=0; i<20; i++)
  {
    Node *n = new Node{i, nullptr};
    if(in == nullptr)
    {
      temp = n;
      in = n;
    }

    else
    {
       temp->next = n;
       temp = temp->next;

    }

  }
}

void deleteList(Node *& in)
{
   Node *temp = in;
   while(temp != nullptr)
   {
      Node *del = temp;
      temp = temp->next;
      delete del;



   }

   return;



}



int main()
{
  Node *in = nullptr; 
  Node *odds = nullptr;
  Node *evens = nullptr;
  
  constructList(in);

  std::cout << "first in" << std::endl;
  printLinkedList(in);

  split(in,odds,evens);

  std::cout << "in" << std::endl;
  printLinkedList(in);
  std::cout << "odds" << std::endl;
  printLinkedList(odds);
  std::cout << "evens" << std::endl;
  printLinkedList(evens);

  deleteList(in);
  deleteList(odds);
  deleteList(evens);

  return 1;
}