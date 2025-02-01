//
// Created by sooky on 25. 2. 2.
//

#pragma once
#include "stdafx.h"

struct Point {
  int idx;
  int xpos;
  int ypos;

  Point(int x, int y) : xpos(x), ypos(y) {
    static int cnt = 0;
    idx = cnt++;
  }

  ~Point() {
    cout << "detructed: p" << idx + 1 << endl;
  }
};

Point &PntAdder(const Point &p1, const Point &p2);

int p95();
