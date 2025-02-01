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

public:
  static AccountsManager &getInstance() {
    static AccountsManager instance;
    return instance;
  }

  /** 복사 생성자 삭제 */
  AccountsManager(const AccountsManager &) = delete;

  /** 대입 연산자 삭제 */
  AccountsManager &operator=(const AccountsManager &) = delete;

  const vector<Account> *getAccounts() const;

  Account *getAccount(int ID);

  void createAccount(int ID, string &name);

  void depositToAccount(int ID, double money);

  void withdrawFromAccount(int ID, double money);
};
