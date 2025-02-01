//
// Created by sooky on 25. 2. 1.
//

#pragma once
#include "stdafx.h"

class Account {
private:
  int ID;
  string name;
  double money;

public:
  Account(const int ID, const string &name);

  int getID() const;

  const string *getName() const;

  double getMoney() const;

  void setMoney(const double money);
};
