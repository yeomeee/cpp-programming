//
// Created by sooky on 25. 2. 1.
//

#pragma once
#include "stdafx.h"
#include "Account.h"

class AccountsManager {
private:
  vector<Account> accounts{};

  AccountsManager() {
  }

  AccountsManager(const AccountsManager &) = delete;

  AccountsManager &operator=(const AccountsManager &) = delete;

  optional<reference_wrapper<Account> > getAccount(int ID);

public:
  static AccountsManager &getInstance() {
    static AccountsManager instance;
    return instance;
  }

  const vector<Account> *getAccounts() const;

  bool create(int ID, string &name);

  bool deposit(int ID, double money);

  bool withdraw(int ID, double money);
};
