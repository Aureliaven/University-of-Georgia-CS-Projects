#include <iostream>

using namespace std;

/**
 * Represents a rectangle with width and height
 * Has functions to set width and height and return the area
 */
class Rectangle {
  int width, height;
public:
  void set_values (int, int);
  int getArea () { return width * height; }
}; // Rectangle

/**
 * Sets the width and height of a Rectangle
 * @param w - the new width
 * @param h - the new height
 */
void Rectangle::set_values(int w, int h) {
  width = w;
  height = h;
} // set_values

int main() {
  Rectangle a, b;
  a.set_values(3, 4);
  b.set_values(5, 6);
  cout << "Rectangle a area: " << a.getArea() << endl;
  cout << "Rectangle b area: " << b.getArea() << endl;
  return EXIT_SUCCESS;
} // main
