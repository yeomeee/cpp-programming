//
// Created by sooky on 25. 2. 1.
//

#include "stdafx.h"


/**
 * 1. n1, n2의 참조를 전달 eg.swap1(&n1, &n2);
 * 2. 넘어온 메모리 주소를 포인터 변수로 받음
 * 3. 포인터를 역참조해서 가리키는 값을 바꿈
 */
template <typename T>
void swap1(T* a, T* b) {
  T tmp = *a;
  *a = *b;
  *b = tmp;
}

/**
 * 1. n1, n2의 값을 전달 eg.swap2(n1, n2);
 * 2. 넘어온 값을 값 자체로 받지 않고 참조 변수로 받음
 * 3. 참조를 사용해서 가리키는 값을 바꿈
 */
template <typename T>
void swap2(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

int p26() {
  int n1 = 10, n2 = 20;
  std::cout << n1 << " " << n2 << std::endl;
  // swap1(&n1, &n2);
  swap2(n1, n2);
  std::cout << n1 << " " << n2 << std::endl;

  std::cout << "##############################" << std::endl;

  char ch1 = 'A', ch2 = 'B';
  std::cout << ch1 << " " << ch2 << std::endl;
  // swap1(&ch1, &ch2);
  swap2(ch1, ch2);
  std::cout << ch1 << " " << ch2 << std::endl;

  std::cout << "##############################" << std::endl;

  double dbl1 = 10.1, dbl2 = 20.2;
  std::cout << dbl1 << " " << dbl2 << std::endl;
  // swap1(&dbl1, &dbl2);
  swap2(dbl1, dbl2);
  std::cout << dbl1 << " " << dbl2 << std::endl;

  return 0;
}

