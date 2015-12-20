#include <string>
#include <iostream>
#include "List.h"

using namespace std;

struct List::List_Node {
  string name;
  int age;
  List_Node* next;
};


List List::copy() {
  List list;
  if (_head == nullptr)
    list._head = nullptr;
  else {
    list._head = new List_Node{ _head->name, _head->age, nullptr };
    List_Node* iterator = list._head;
    for (List_Node* temp_head = _head->next; temp_head != nullptr; temp_head = temp_head->next) {
      iterator->next = new List_Node{ temp_head->name, temp_head->age, nullptr };
      iterator = iterator->next;
    }
  }
  return list;
}

void List::append(const string& name, int age)
{
  auto p = new List_Node{ name, age, nullptr };

  if (_head == nullptr)
    {
      _head = p;
      return;
    }

  auto last = _head;

  while (last->next != nullptr)
    {
      last = last->next;
    }

  last->next = p;
}

void List::print()
{
  for (auto p = _head; p != nullptr; p = p->next)
    {
      cout << " -> " << p->name << '(' << p->age << ')';
    }
  cout << "\n";
}

void List::_internal_reverse_print(const List_Node* node) {
  if (node == nullptr) {
    return;
  }
  _internal_reverse_print(node->next);
  cout << " -> " << node->name << '(' << node->age << ')';
}

void List::print_reversed() {
  _internal_reverse_print(_head);
  cout << "\n";
}

void List::insert(const string& name, int age) {
  if (_head == nullptr)
    {
      auto p = new List_Node{ name, age, nullptr };
      _head = p;
      return;
    }
  else {
    auto p = new List_Node{ name, age, _head };
    _head = p;
  }
}

void List::clear() {
  while(_head != nullptr)
    {
      List_Node* temp = _head->next;
      delete _head;
      _head = temp;
    }
}

void List::reverse() {
  struct List_Node* previous_node = nullptr;
  struct List_Node* temp_head = _head;
  struct List_Node* next_node;
  while (temp_head != nullptr)
    {
      next_node = temp_head->next;
      temp_head->next = previous_node;
      previous_node = temp_head;
      temp_head = next_node;
    }
  _head = previous_node;
}

bool List::empty() const {
  if (_head == nullptr) {
    return true;
  }
  else {
    return false;
  }
}
