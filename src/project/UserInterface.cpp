//
// Created by sooky on 25. 2. 1.
//

#include "stdafx.h"
#include "UserInterface.h"
#include "AccountsManager.h"

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
      clearConsole();
    case 6:
    default:
      exitProgram();
  }
}

void UserInterface::showMenu() {
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

void UserInterface::createAccount() {
  int ID;
  string name;

  cout << "[계좌개설]" << endl;
  cout << "계좌ID: ";
  cin >> ID;
  cout << "이 름: ";
  cin >> name;

  AccountsManager::getInstance().createAccount(ID, name);

  cout << "--계좌개설 완료--" << endl;

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

  cout << "--입금 완료--" << endl;

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

  cout << "--출금 완료--" << endl;

  navigate(0);
}

void UserInterface::showAllAccounts() {
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

void UserInterface::clearConsole() {
  try {
    boost::process::system("cmd /c cls");
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  navigate(0);
}

void UserInterface::exitProgram() {
  cout << "[프로그램 종료]" << endl;
  exit(0);
}