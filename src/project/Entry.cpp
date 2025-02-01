//
// Created by sooky on 25. 2. 1.
//

#include "Entry.h"
#include "UserInterface.h"

int Entry() {
  auto& ui = UserInterface::getInstance();
  ui.navigate(0);
  return 0;
}