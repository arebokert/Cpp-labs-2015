#ifndef LIST_H
#define LIST_H
  using namespace std;
  using size_type = std::size_t;
  using string = std::string;
	
  struct List_Node {
    string name;
    int age;
    List_Node* next;
  };
  
  void swap(List_Node*&, List_Node*&);
  bool empty(const List_Node* const &);
  
  void clear(List_Node*&);
  
  void reverse(List_Node*&);

  List_Node* copy(const List_Node* const &);
	
  void append(List_Node*&, const string&, int);
  void print(const List_Node* const &, ostream&);
  void insert(List_Node*&, const string&, int);
  
  void print_reversed(const List_Node* const &, ostream&);
  
  //void _internal_reverse_print(const List_Node*);
#endif
