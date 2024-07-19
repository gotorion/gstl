#include <cstdio>
#include <iostream>
#include <ostream>
#include <system_error>
template <typename T> class ListItem {
private:
  T _value;
  ListItem *_next{nullptr};

public:
  ListItem(T value) : _value(value), _next(nullptr) {}
  T value() const { return _value; }
  ListItem *next() const { return _next; }
  void next(ListItem *next) { _next = next; }
  // std::ostream os &operator<<(std::ostream &os, ListItem<U> item);
};

template <typename T> class List {
private:
  ListItem<T> *_end{nullptr};
  ListItem<T> *_start{nullptr};
  long _size{};

public:
  ListItem<T> *front() const { return _start; }
  void insert_front(T value) {
    ListItem<T> *tmp = _start;
    ListItem<T> *newStart = new ListItem<T>(value);
    _start = newStart;
    _start->next(tmp);
    ListItem<T> *next = _start->next();
    if (!_size) {
      _end = _start;
    }
    ++_size;
  }
  void insert_end(T value) {
    ListItem<T> *ptr = new ListItem<T>(value);
    _end->next() = ptr;
    _end = ptr;
    ++_size;
  }
  void display(std::ostream &os = std::cout) const {
    ListItem<T> *iter = _start;
    while (iter->next()) {
      os << iter->value() << " ";
      iter = iter->next();
    }
    os << std::endl;
  }
};

template <typename Item> struct ListIter {
  Item *ptr;
  ListIter(Item *p = 0) : ptr(p) {}

  Item &operator*() const { return *ptr; }
  Item *operator->() const { return ptr; }
  ListIter &operator++() { // pre-increment
    ptr = ptr->next();
    return *this;
  }
  ListIter operator++(int) { // post-increment
    ListIter tmp = *this;
    ++(*this);
    return tmp;
  }
  bool operator==(const ListIter &other) const { return ptr == other.ptr; }
  bool operator!=(const ListIter &other) const { return ptr != other.ptr; }
};