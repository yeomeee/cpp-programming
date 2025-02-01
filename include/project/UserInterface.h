//
// Created by sooky on 25. 2. 1.
//

#pragma once

class UserInterface {
private:
  UserInterface() {
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
