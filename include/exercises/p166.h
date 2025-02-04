//
// Created by sooky on 25. 2. 4.
//

#pragma once

class Point166 {
private:
  int xpos, ypos;

public:
  Point166(int x, int y): xpos(x), ypos(y) {
  }

  void showPointInfo() const;
};

class Circle {
private:
  Point166 center;
  int radius;

public:
  Circle(int x, int y, int r): center(x, y), radius(r) {
  } ;

  void showCircleInfo() const;
};

class Ring {
private:
  Circle inner, outer;

public:
  Ring(int x1, int y1, int r1, int x2, int y2, int r2): inner(x1, y1, r1), outer(x2, y2, r2) {
  }

  void showRingInfo() const;
};

int p166();
