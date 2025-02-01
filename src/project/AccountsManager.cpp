//
// Created by sooky on 25. 2. 1.
//

#include "stdafx.h"
#include "Account.h"
#include "AccountsManager.h"

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