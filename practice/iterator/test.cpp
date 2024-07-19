#include "my_list.h"
#include <algorithm>
template <typename T> bool operator!=(const ListItem<T> &item, T n) {
  return item.value() != n;
}

int main() {
  // this can not be compiled, just for learn the concept of iterator
  List<int> mylist;
  for (int i = 0; i < 10; ++i) {
    mylist.insert_front(i);
  }
  mylist.display();

  // find
  ListIter<ListItem<int>> begin(mylist.front());
  ListIter<ListItem<int>> end;
  ListIter<ListItem<int>> iter;
  iter = std::find(begin, end, 3);
  if (iter == end) {
  }
  return 0;
}