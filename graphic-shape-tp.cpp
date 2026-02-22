/* implement graphic shapes and an editor

the graphic shapes:
   - are Circle (radius), Rectangle (width, height) ...
   - have a position: x, y
   - can be moved
   - have member function that check if a shape is at a given position
     (juste check that the given point is inside the smallest rectangular bounding box englobing the shape)
   - have a member function that compute the area of the shape (fix a value for PI)

the editor:
  - contains a list of graphic shapes
  - can add/remove an existing graphic-shape to the list
  - has a member function find that returns the (first) graphic shape at a given position
  - can remove the graphic-shape found at a given position
  - can compute the area of the shape found at a given position

We can add a new shape to your code (Square) WITHOUT modifying your classes !
Only by adding some code and modifying the main function.

*/

#include <iostream>
#include <vector>
#include <stdexcept>

class Shape // abstraite
{
  int x;
  int y;

protected:
  Shape(int x, int y) : x(x), y(y) {}

public:
  virtual double area() = 0; // la fonction n'a pas de corps.
  void move(int dx, int dy)
  {
    x = x + dx;
    y = y + dy;
  }
};

class Circle : public Shape
{
  int radius;

public:
  Circle(int x, int y, int r) : Shape(x, y)
  {
    if (r < 0)
    {
      throw std::out_of_range(std::string("Rayon négatif"));
    }
    else
    {
      radius = r;
    }
  }
  double area()
  {
    return 3.14159 * radius * radius;
  }
};

class Rectangle : public Shape
{
  int width;
  int height;

public:
  Rectangle(int x, int y, int w, int h) : Shape(x, y)
  {
    if (w <= 0 or h <= 0)
    {
      throw std::out_of_range(std::string("Dimensions d'un rectangle négatives"));
    }
    else
    {
      width = w;
      height = h;
    }
  }

  double area()
  {
    return width * height;
  }
};

int main()
{
  try
  {
    Circle c1(100, 50, 12);
    c1.move(8, 10);
    std::cout << c1.area() << std::endl;

    Rectangle r1(100, 300, -56, 67);
    r1.move(9, 10);
    std::cout << r1.area() << std::endl;

    std::vector<Shape *> shapes;
    shapes.push_back(&c1);
    shapes.push_back(&r1);

    for (int i = 0; i < shapes.size(); i++)
    {
      shapes[i]->move(2, 3);
      std::cout << shapes[i]->area() << std::endl;
    }

    return 0;
  }
  catch (const std::out_of_range &e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }  
}