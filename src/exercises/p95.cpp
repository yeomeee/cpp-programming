//
// Created by sooky on 25. 2. 2.
//

#include "stdafx.h"
#include "p95.h"

Point& PntAdder(const Point& p1, const Point& p2) {
  Point* p3 = new Point(p1.xpos + p2.xpos, p1.ypos + p2.ypos);
  return *p3;
}


int p95() {
  Point* p1 = new Point(10, 10);
  Point* p2 = new Point(20, 20);

  auto& p3 = PntAdder(*p1, *p2);

  cout << "x: " << p3.xpos << endl;
  cout << "y: " << p3.ypos << endl;

  delete p1;
  delete p2;
  delete &p3;

  return 0;
}
