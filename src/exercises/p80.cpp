//
// Created by sooky on 25. 2. 2.
// 문제3
//

#include "stdafx.h"

int p80() {
  auto swapPointer = [](int*& a, int*& b) {
    int* temp = a;
    a = b;
    b = temp;
  };

  int n1 = 5;
  int n2 = 10;

  int* p1 = &n1;
  int* p2 = &n2;

  swapPointer(p1, p2);

  cout << "*p1: " << *p1 << endl;
  cout << "*p2: " << *p2 << endl;

  return 0;
}