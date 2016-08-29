#pragma once

class Stick {
  public:
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void read();
  protected:
    int x;
    int y;
};
