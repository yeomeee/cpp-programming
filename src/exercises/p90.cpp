//
// Created by sooky on 25. 2. 2.
//

#include "stdafx.h"

int p90() {
  const int n = 12;
  const int* p = &n;
  const int*& r = p;

  cout << n << endl;
  cout << *p << endl;
  cout << *r << endl;

  return 0;
}
