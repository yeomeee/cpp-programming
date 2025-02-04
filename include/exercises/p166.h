//
// Created by sooky on 25. 2. 4.
//

#pragma once

class Point166 {
private:
  int xpos_, ypos_;

public:
  Point166(int x, int y): xpos_(x), ypos_(y) {
  }

  void ShowPointInfo() const;
};

class Circle {
private:
  Point166 center_;
  int radius_;

public:
  Circle(int x, int y, int r): center_(x, y), radius_(r) {
  } ;

  void ShowCircleInfo() const;
};

class Ring {
private:
  Circle inner_, outer_;

public:
  Ring(int x1, int y1, int r1, int x2, int y2, int r2): inner_(x1, y1, r1), outer_(x2, y2, r2) {
  }

  void ShowRingInfo() const;
};

int P166();
