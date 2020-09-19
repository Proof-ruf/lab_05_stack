// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <iostream>
#include <cstring>
#include <cstdlib>
#define ERROR -1

template <typename T>
class Stack{
 private:
  T *ArrStack;
  int top;
  int size;

 public:
  explicit Stack(int s) : ArrStack(nullptr){
    size = s;
    top = 0;
  }
  ~Stack() {
    free(ArrStack);
  }
  void push(T&& value){
    top++;
    ArrStack = static_cast<T*>(realloc(ArrStack, top * sizeof(T)));
    ArrStack[top - 1] = value;
  }
  void push(const T& value){
    top++;
    ArrStack = static_cast<T*>(realloc(ArrStack, top * sizeof(T)));
    ArrStack[top - 1] = value;
  }
  void pop(){
    if (top == 0) {
      exit(ERROR);
    }
    --top;
    ArrStack = static_cast<T*>(realloc(ArrStack, top * sizeof(T)));
  }
  const T& head() const{
    return ArrStack[top-1];
  }
};

template <typename T>
class stack{
 private:
  T *ArrStack;
  int top;
  int size;

 public:
  explicit stack(int s) : ArrStack(nullptr){
    size = s;
    top = 0;
  }
  ~stack(){
    free(ArrStack);
  }
  template <typename ... Args>
  void push_emplace(Args&&... value){
    T obj(std::forward<Args>(value)...);
    top++;
    ArrStack = static_cast<T*>(realloc(ArrStack, top * sizeof(T)));
    ArrStack[top - 1] = obj;
  }
  void push(T&& value){
    top++;
    ArrStack = static_cast<T*>(realloc(ArrStack, top * sizeof(T)));
    ArrStack[top - 1] = value;
  }
  const T& head() const{
    return ArrStack[top-1];
  }
  T pop(){
    if (top == 0) {
      exit(ERROR);
    }
    T rezult = ArrStack[top - 1];
    --top;
    ArrStack = static_cast<T*> (realloc(ArrStack, top * sizeof(T)));
    return rezult;
  }
};

#endif // INCLUDE_HEADER_HPP_
