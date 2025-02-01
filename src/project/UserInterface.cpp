//
// Created by sooky on 25. 2. 1.
//

#include "stdafx.h"
#include "UserInterface.h"
#include "AccountsManager.h"

void UserInterface::navigate(const int menu) {
  switch (menu) {
    case 0:
      selectMenu();
    case 1:
      createMenu();
    case 2:
      depositMenu();
    case 3:
      withdrawMenu();
    case 4:
      showAllAccountsMenu();
    case 5:
      clearMenu();
    case 6:
    default:
      exitMenu();
  }
}

void UserInterface::selectMenu() {
  cout << endl;

  int menu;

  cout << "-----Menu-----" << endl;
  cout << "1. 계좌개설" << endl;
  cout << "2. 입 금" << endl;
  cout << "3. 출 금" << endl;
  cout << "4. 계좌정보 전체 출력" << endl;
  cout << "5. 콘솔 지우기" << endl;
  cout << "6. 프로그램 종료" << endl;
  cout << "선택: ";
  cin >> menu;

  cout << endl;

  navigate(menu);
}

void UserInterface::createMenu() {
  int ID;
  string name;

  cout << "[계좌개설]" << endl;
  cout << "계좌ID: ";
  cin >> ID;
  cout << "이 름: ";
  cin >> name;

  const bool res = AccountsManager::getInstance().create(ID, name);

  cout << (res ? "--계좌개설 완료--" : "--계좌개설 실패--") << endl;

  navigate(0);
}

void UserInterface::depositMenu() {
  int ID;
  double moneyToDeposit;

  cout << "[입 금]" << endl;
  cout << "계좌ID: ";
  cin >> ID;
  cout << "입금액: ";
  cin >> moneyToDeposit;

  const bool res = AccountsManager::getInstance().
      deposit(ID, moneyToDeposit);

  cout << (res ? "--입금 완료--" : "--입금 실패--") << endl;

  navigate(0);
}

void UserInterface::withdrawMenu() {
  int ID;
  double moneyToWithdraw;

  cout << "[출 금]" << endl;
  cout << "계좌ID: ";
  cin >> ID;
  cout << "출금액: ";
  cin >> moneyToWithdraw;

  const bool res = AccountsManager::getInstance().withdraw(ID, moneyToWithdraw);

  cout << (res ? "--출금 완료--" : "--출금 실패--") << endl;

  navigate(0);
}

void UserInterface::showAllAccountsMenu() {
  const auto& mgr = AccountsManager::getInstance();

  cout << "[계좌정보 전체 출력]" << endl << endl;

  for (const auto accounts = mgr.getAccounts(); const auto& account : *
       accounts) {
    cout << "계좌ID: " << account.getID() << endl;
    cout << "이 름: " << *account.getName() << endl;
    cout << "잔 액: " << account.getMoney() << endl;
    cout << endl;
  }

  cout << "--계좌정보 전체 출력 완료--" << endl;

  navigate(0);
}

void UserInterface::clearMenu() {
  try {
    boost::process::system("cmd /c cls");
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  navigate(0);
}

void UserInterface::exitMenu() {
  cout << "[프로그램 종료]" << endl;
  exit(0);
}