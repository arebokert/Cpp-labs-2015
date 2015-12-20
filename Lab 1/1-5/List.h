#ifndef LIST_H
#define LIST_H
class List
{
 public:
  using size_type = std::size_t;
  using string = std::string;
	
	
 List() : _head{ nullptr } {}
	
  void swap(List& other) noexcept {
    std::swap(_head, other._head);
  };
  bool empty() const;
  void clear();
  void reverse();

  List copy();
	
  void append(const string&, int);
  void print();
  void insert(const string&, int);
  void print_reversed();


 private:
  struct List_Node;
  List_Node* _head;
  void _internal_reverse_print(const List_Node*);

};
#endif
