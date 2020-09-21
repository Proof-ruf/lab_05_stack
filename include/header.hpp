// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#define STACK_UNDERFLOW -2

#include <cstdlib>
#include <iostream>
#include <new>

using std::cout;
using std::endl;

template <typename T>
class stack
{
 private:
  T *stackPtr;
  int count;

 public:
  stack() {
    stackPtr = nullptr;
    count = 0;
  }

  ~stack() {
    delete[] stackPtr;
  }

  template <typename ... Args>
  void push_emplace(Args &&... value) {
    push(std::forward<Args>(value)...);
  }

  void push(T&& value) {
    T* tmpPtr;
    tmpPtr = stackPtr;
    stackPtr = new T[count + 1];
    count++;

    for (int i = 0; i < count - 1; i++) {
      stackPtr[i] = tmpPtr[i];
    }
    stackPtr[count - 1] = value;

    if (count > 1) delete[] tmpPtr;
  }

  void push(const T& value) {
    T* tmpPtr;
    tmpPtr = stackPtr;
    stackPtr = new T[count + 1];
    count++;

    for (int i = 0; i < count - 1; i++) {
      stackPtr[i] = tmpPtr[i];
    }
    stackPtr[count - 1] = value;

    if (count > 1) delete[] tmpPtr;
  }

  T pop() {
    if (count == 0)
      return 0; 
    count--;
    return stackPtr[count];
  }

  const T& head() const {
    if (count == 0) {
      cout << "stack underflow" << endl;
      exit(STACK_UNDERFLOW);
    }
    return stackPtr[count-1];
  }
};

#endif // INCLUDE_HEADER_HPP_
