//
// Created by sooky on 25. 2. 1.
//

#include "stdafx.h"
#include "Account.h"
#include "AccountsManager.h"

const vector<Account>* AccountsManager::getAccounts() const {
  return &accounts;
}

optional<reference_wrapper<Account> >
AccountsManager::getAccount(const int ID) {
  for (auto& account : accounts)
    if (account.getID() == ID)
      return ref(account);

  cout << "유효하지 않은 ID 입니다" << endl;
  return nullopt;
}

bool AccountsManager::create(int ID, string& name) {
  accounts.push_back(*make_unique<Account>(ID, name));
  return true;
}

bool AccountsManager::deposit(const int ID, const double money) {
  auto accountOpt = getAccount(ID);
  if (!accountOpt.has_value()) return false;

  auto& account = accountOpt.value().get();
  account.setMoney(account.getMoney() + money);
  return true;
}

bool AccountsManager::withdraw(const int ID, const double money) {
  auto accountOpt = getAccount(ID);
  if (!accountOpt.has_value()) return false;

  auto& account = accountOpt.value().get();

  if (account.getMoney() < money) {
    cout << "잔액이 부족합니다" << endl;
    return false;
  }

  account.setMoney(account.getMoney() - money);
  return true;
}