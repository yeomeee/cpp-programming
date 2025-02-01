//
// Created by sooky on 25. 2. 1.
//

#include "stdafx.h"

int p17() {
  int v1, v2;
  int r = 0;

  std::cout << "두 개의 숫자 입력? ";
  std::cin >> v1 >> v2;

  const int s = std::ranges::min(v1, v2);
  const int e = std::ranges::max(v1, v2);

  for (int i = s + 1; i < e; i++) r += i;

  std::cout << "답: " << r << std::endl;

  return 0;
}