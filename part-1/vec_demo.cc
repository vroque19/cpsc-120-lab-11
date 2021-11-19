
/* Do not edit below this line. */
/* Do not edit below this line. */
/* Do not edit below this line. */

#include <iostream>

#include "vec3.h"

using namespace std;

/// Entry point to the vec_demo program
/// \remark The program does not have any commad line arguments.
int main(int argc, char const *argv[]) {
  // Declare three Vec3 variables, initialize each one to some values.
  Vec3 zero;
  Vec3 a(1.1, 2.2, 3.3);
  Vec3 b(3.1, 4.2, 5.3);

  // Print out each Vec3 to the terminal.
  cout << "zero == " << zero << "\n";
  cout << "a == " << a << "\n";
  cout << "b == " << b << "\n";

  // Sum the Vec3 a and b and save it in Vec3 c.
  Vec3 c = a + b;
  cout << "a + b == " << c << "\n";
  // Take the difference of Vec3 b and a and save it in Vec3 c
  c = b - a;
  cout << "b - a == " << c << "\n";

  // Define a scalar s.
  double s = 3.0;
  cout << "s == " << s << "\n";

  // Multiply the Vec3 b by the scalar s.
  c = b * s;
  cout << "b * s == " << c << "\n";
  // Multiply the Vec3 b by the scalar s.
  c = s * b;
  cout << "s * b == " << c << "\n";
  // Divide the Vec3 a by the scalar s.
  c = a / s;
  cout << "a / s == " << c << "\n";

  // Calculate the dot product between Vec3 a and Vec3 zero
  double d = Dot(a, zero);
  cout << "Dot(a, zero) == " << d << "\n";
  // Calculate the dot product between Vec3 a and Vec3 b
  d = Dot(a, b);
  cout << "Dot(a, b) == " << d << "\n";
  // Calculate the cross product between Vec3 a and Vec3 b
  c = Cross(a, b);
  cout << "Cross(a, b) == " << c << "\n";

  return 0;
}
