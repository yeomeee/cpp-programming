//
// Created by sooky on 25. 2. 4.
//

#include "stdafx.h"
#include "p166.h"

void Point166::showPointInfo() const {
  cout << "[" << xpos << ", " << ypos << "]" << endl;
}

void Circle::showCircleInfo() const {
  cout << "radius: " << radius << endl;
  center.showPointInfo();
}


void Ring::showRingInfo() const {
  cout << "Inner Circle Info..." << endl;
  inner.showCircleInfo();

  cout << "Outer Circle Info..." << endl;
  outer.showCircleInfo();
}


int p166() {
  Ring ring = {1, 1, 4, 2, 2, 9};
  ring.showRingInfo();
  return 0;
}