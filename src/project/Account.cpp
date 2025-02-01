//
// Created by sooky on 25. 2. 1.
//

#include "stdafx.h"
#include "Account.h"

Account::Account(const int ID, const string& name): money(0) {
  this->ID = ID;
  this->name = name;
};

int Account::getID() const {
  return ID;
}

const string* Account::getName() const {
  return &name;
}

double Account::getMoney() const {
  return money;
}

void Account::setMoney(const double money) {
  this->money = money;
}