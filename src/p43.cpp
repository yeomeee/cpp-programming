//
// Created by sooky on 25. 2. 1.
//

#include "stdafx.h"
#include "p43.h"

int ns1::p43() {
  std::cout << "ns1::p43" << std::endl;
  return 0;
}

int ns2::p43() {
  std::cout << "ns2::p43" << std::endl;
  return 0;
}

int p43() {
  ns1::p43();
  ns2::p43();
  return 0;
}