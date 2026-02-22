#include <iostream>

struct Cell
{
  int val;
  Cell* adr;

  Cell(int v, Cell* a) : val(v), adr(a) {}
};

struct LinkedList
{
  Cell* head;

  LinkedList() : head(nullptr) {}

  bool is_empty()
  {
    return head == nullptr;
  }

  void push_front(int v)
  {
    Cell* c = new Cell(v, head);
    head = c;
  }

  bool find(int elt)
  {
    Cell* curr = head;
    while (curr != nullptr)
    {
      if (curr->val == elt)
        return true;
      curr = curr->adr;
    }
    return false;
  }

  void remove(int elt)
  {
    if (head == nullptr)
      return;

    if (head->val == elt)
    {
      Cell* tmp = head;
      head = head->adr;
      delete tmp;
      return;
    }

    Cell* prev = head;
    Cell* curr = head->adr;

    while (curr != nullptr)
    {
      if (curr->val == elt)
      {
        prev->adr = curr->adr;
        delete curr;
        return;
      }
      prev = curr;
      curr = curr->adr;
    }
  }

  void print()
  {
    Cell* curr = head;
    while (curr != nullptr)
    {
      std::cout << curr->val << " ";
      curr = curr->adr;
    }
    std::cout << std::endl;
  }

  ~LinkedList()
  {
    while (head != nullptr)
    {
      Cell* tmp = head;
      head = head->adr;
      delete tmp;
    }
  }
};

int main()
{
  LinkedList list;

  list.push_front(45);
  list.push_front(12);
  list.push_front(42);
  list.push_front(33);
  list.push_front(17);

  list.print();

  list.remove(88);
  list.remove(17);
  list.remove(45);
  list.remove(42);

  list.print();

  return 0;
}