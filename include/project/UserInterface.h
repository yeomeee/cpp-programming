//
// Created by sooky on 25. 2. 1.
//

#pragma once

class UserInterface {
private:
  UserInterface() {
  };

  UserInterface(const UserInterface &) = delete;

  UserInterface &operator=(const UserInterface &) = delete;

  void selectMenu();

  void createMenu();

  void depositMenu();

  void withdrawMenu();

  void showAllAccountsMenu();

  void clearMenu();

  void exitMenu();

public:
  static UserInterface &getInstance() {
    static UserInterface instance;
    return instance;
  }

  void navigate(const int menu);
};
