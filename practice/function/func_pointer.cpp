#include <stdio.h>

void func_hello(void *args) { printf("%s\n", "Hello"); }

void func_world(void *args) { printf("%s\n", "World"); }

typedef void (*pfunc_t)(void *);

void repeat(pfunc_t func, void *args) {
  func(args);
  func(args);
}

void test() {
  int x;
  int y;
  auto closure = [x, y]() mutable {
    x = 1; // error if no mutable
  };
};

int main() {
  repeat(func_hello, NULL);
  return 0;
}