//
// Created by sooky on 25. 2. 1.
//

#include "oop1.h"


/**
 * Account
 */

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

/**
 * AccountsManager
 */

const vector<Account>* AccountsManager::getAccounts() const {
  return &accounts;
}

Account* AccountsManager::getAccount(const int ID) {
  if (const auto it = ranges::find(accounts, ID, &Account::getID);
    it != accounts.end())
    return (&*it);

  throw std::runtime_error("Account with ID not found.");
}

void AccountsManager::createAccount(int ID, string& name) {
  const auto account = make_unique<Account>(ID, name);
  accounts.push_back(*account);
}


void AccountsManager::depositToAccount(const int ID, const double money) {
  Account* account = getAccount(ID);
  account->setMoney(account->getMoney() + money);
}

void AccountsManager::withdrawFromAccount(const int ID, const double money) {
  Account* account = getAccount(ID);
  account->setMoney(account->getMoney() - money);
}


/**
 * Entrypoint
 */

int oop() {
  cout << "oop" << endl;
  auto& ui = UserInterface::getInstance();
  ui.navigate(0);
  return 0;
}