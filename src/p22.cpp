//
// Created by sooky on 25. 2. 1.
// 문제 4
//

#include "stdafx.h"
#include <format>

// int p22() {
//
//   while (true) {
//     int sales;
//
//     std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
//     std::cin >> sales;
//
//     if (sales == -1) break;
//
//     auto salary = 50 + sales * 0.12;
//     std::cout << "이번 달 급여: " << salary << "만원" << std::endl;
//   }
//
//   std::cout << "프로그램을 종료합니다.";
//
//   return 0;
// }

int p22() {
  auto getInput = []() -> int {
    int sales;
    std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
    std::cin >> sales;
    return sales;
  };

  auto calculateSalary = [](int sales) -> double {
    return 50.0 + sales * 0.12;
  };

  auto printSalary = [](double salary) {
    if (static_cast<int>(salary) == salary) {
      std::cout << std::format("이번 달 급여: {} 만원\n", static_cast<int>(salary));
    } else {
      std::cout << std::format("이번 달 급여: {:.2f} 만원\n", salary);
    }
  };

  while (true) {
    int sales = getInput();

    if (sales == -1) break;

    double salary = calculateSalary(sales);
    printSalary(salary);
  }

  std::cout << "프로그램을 종료합니다.\n";
  return 0;
}