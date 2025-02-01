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

  void navigate(const int menu) {
    cout << endl;
    cout << endl;

    switch (menu) {
      case 0:
        showMenu();
      case 1:
        createAccount();
      case 2:
        depositToAccount();
      case 3:
        withdrawFromAccount();
      case 4:
        showAllAccounts();
      case 5:
      default:
        exit();
    }
  }

  void showMenu() {
    int menu;

    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
    cout << "선택: ";
    cin >> menu;

    navigate(menu);
  }

  void createAccount() {
    int ID;
    string name;

    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";
    cin >> ID;
    cout << "이 름: ";
    cin >> name;

    AccountsManager::getInstance().createAccount(ID, name);

    cout << "계좌개설 완료" << endl;

    navigate(0);
  }

  void depositToAccount() {
    int ID;
    double moneyToDeposit;

    cout << "[입 금]" << endl;
    cout << "계좌ID: ";
    cin >> ID;
    cout << "입금액: ";
    cin >> moneyToDeposit;

    AccountsManager::getInstance().depositToAccount(ID, moneyToDeposit);

    cout << "입금 완료" << endl;

    navigate(0);
  }

  void withdrawFromAccount() {
    int ID;
    double moneyToWithdraw;

    cout << "[출 금]" << endl;
    cout << "계좌ID: ";
    cin >> ID;
    cout << "출금액: ";
    cin >> moneyToWithdraw;

    AccountsManager::getInstance().withdrawFromAccount(ID, moneyToWithdraw);

    cout << "출금 완료" << endl;

    navigate(0);
  }

  void showAllAccounts() {
    const auto &mgr = AccountsManager::getInstance();

    for (const auto accounts = mgr.getAccounts(); const auto &account: *accounts) {
      cout << "계좌ID: " << account.getID() << endl;
      cout << "이 름: " << *account.getName() << endl;
      cout << "잔 액: " << account.getMoney() << endl;
      cout << endl;
    }

    navigate(0);
  }

  void exit() {
    cout << "프로그램을 종료합니다." << endl;
  }
};

int oop();
