#include <string>
#include <iostream>
#include "List.h"

using namespace std;


void swap (List_Node*& first, List_Node*& second){
  std::swap(first, second);
}

List_Node* copy(const List_Node* const & _head) {
  List_Node* list;
  if (_head == nullptr)
    list = nullptr;
  else {
    list = new List_Node{ _head->name, _head->age, nullptr };
    List_Node* iterator = list;
    for (List_Node* temp_head = _head->next; temp_head != nullptr; temp_head = temp_head->next) {
      iterator->next = new List_Node{ temp_head->name, temp_head->age, nullptr };
      iterator = iterator->next;
    }
  }
  return list;
}


void append(List_Node*& _head, const string& name, int age)
{
  auto p = new List_Node{ name, age, nullptr };
  if (_head == nullptr)
    {
      _head = p;
      return;
    }

  auto* last = _head;

  while (last->next != nullptr)
    {
      last = last->next;
    }

  last->next = p;
}

void print(const List_Node* const & _head, ostream& stream)
{
  for (auto p = _head; p != nullptr; p = p->next)
    {
      stream << " -> " << p->name << '(' << p->age << ')';
    }
  stream << "\n";
}

void print_reversed(const List_Node* const & _head, ostream& stream) {
  if (_head == nullptr) {
    return;
  }
  print_reversed(_head->next, stream);
  stream << " -> " << _head->name << '(' << _head->age << ')';
}

void insert(List_Node*& _head, const string& name, int age) {
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

void clear(List_Node*& _head) {
  while(_head != nullptr)
    {
      List_Node* temp = _head->next;
      delete _head;
      _head = temp;
    }
}

void reverse(List_Node*& _head) {
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

bool empty(const List_Node* const & _head) {
  if (_head == nullptr) {
    return true;
  }
  else {
    return false;
  }
}
