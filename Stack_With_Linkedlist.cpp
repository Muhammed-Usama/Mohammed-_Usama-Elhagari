#include <iostream>
using namespace std;
class node
{
public:
  int data;
  node *next;
};
class Stack
{
public:
  node *Top;
  Stack()
  {
    Top = NULL;
  }
  bool empty()
  {
    return (Top == NULL);
  }
  void Push(int value)
  {
    node *new_node = new node;
    if (empty())
    {
      new_node->data = value;
      new_node->next = NULL;
      Top = new_node;
    }
    else
    {
      new_node->data = value;
      new_node->next = Top;
      Top = new_node;
    }
  }

  void Display()
  {
    node *current_node = Top;
    while (current_node != NULL)
    {
      cout << current_node->data << "\n";
      current_node = current_node->next;
    }
  }
  void search(int key)
  {
    node *temp = Top;
    bool re = false;
    while (temp != NULL)
    {
      if (temp->data == key)
      {
        re = true;
      }
      temp = temp->next;
    }
    if (re)
    {
      cout << "This number is found\n";
    }
    else
    {
      cout << "not found\n";
    }
  }
  void PoP()
  {
    node *delpointer = Top;

    if (empty())
    {
      cout << "Empty Linked list .... No items to delete";
    }
    else
    {
      Top = delpointer->next;
      delete delpointer;
    }
  }
};
int main()
{
  Stack S1;
  int item;
  S1.Push(10);
  S1.Push(30);
  S1.Push(20);
  S1.Display();
  S1.search(30);
  S1.search(300);
  S1.PoP();
  S1.Display();
  return 0;
}