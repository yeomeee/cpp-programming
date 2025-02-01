//
// Created by sooky on 25. 2. 1.
//

#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Account
 */

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

/**
 * AccountsManager
 */

class AccountsManager {
private:
  vector<Account> accounts{};

  AccountsManager() {
    //
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

/**
 * UserInterface
 */

class UserInterface {
private:
  UserInterface() {
    //
  };

public:
  static UserInterface &getInstance() {
    static UserInterface instance;
    return instance;
  }

  UserInterface(const UserInterface &) = delete;

  UserInterface &operator=(const UserInterface &) = delete;

  void navigate(const int menu);

  void showMenu();

  void createAccount();

  void depositToAccount();

  void withdrawFromAccount();

  void showAllAccounts();

  void clearConsole();

  void exitProgram();
};

int oop();
