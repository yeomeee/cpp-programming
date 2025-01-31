//
// Created by sooky on 25. 2. 1.
//

#include "stdafx.h"

int p21() {
  std::string name;
  std::string lang;

  std::cout << "이름이 뭐야? ";
  std::cin >> name;

  std::cout << "좋아하는 언어는 뭐야? ";
  std::cin >> lang;

  std::cout << "너의 이름은 " << name << "이고," << std::endl;
  std::cout << lang << "을 좋아하는구나.";

  return 0;
}