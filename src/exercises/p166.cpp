//
// Created by sooky on 25. 2. 4.
//

#include "stdafx.h"
#include "p166.h"

void Point166::ShowPointInfo() const {
  cout << "[" << xpos_ << ", " << ypos_ << "]" << endl;
}

void Circle::ShowCircleInfo() const {
  cout << "radius: " << radius_ << endl;
  center_.ShowPointInfo();
}


void Ring::ShowRingInfo() const {
  cout << "Inner Circle Info..." << endl;
  inner_.ShowCircleInfo();

  cout << "Outer Circle Info..." << endl;
  outer_.ShowCircleInfo();
}


int P166() {
  Ring ring = {1, 1, 4, 2, 2, 9};
  ring.ShowRingInfo();
  return 0;
}