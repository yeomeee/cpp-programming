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
 * UserInterface
 */

void UserInterface::navigate(const int menu) {
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
      exitProgram();
  }
}

void UserInterface::showMenu() {
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

void UserInterface::createAccount() {
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

void UserInterface::depositToAccount() {
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

void UserInterface::withdrawFromAccount() {
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

void UserInterface::showAllAccounts() {
  const auto& mgr = AccountsManager::getInstance();

  for (const auto accounts = mgr.getAccounts(); const auto& account : *
       accounts) {
    cout << "계좌ID: " << account.getID() << endl;
    cout << "이 름: " << *account.getName() << endl;
    cout << "잔 액: " << account.getMoney() << endl;
    cout << endl;
  }

  navigate(0);
}

void UserInterface::exitProgram() {
  cout << "프로그램을 종료합니다." << endl;
  exit(0);
}

/**
 * EntryPoint
 */

int oop() {
  auto& ui = UserInterface::getInstance();
  ui.navigate(0);
  return 0;
}