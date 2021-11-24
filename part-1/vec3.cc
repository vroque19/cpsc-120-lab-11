// Vanessa Roque
// CPSC 120-19
// 2021-11-18
// vroque19@csu.fullerton.edu
// @vroque19
//
// Lab 11-01
//
#include "vec3.h"

// See the header file for documentation.

double Vec3::x() const {
  return x_;
  // return x_
}

double Vec3::y() const {
  return y_;
  // return y_
}
double Vec3::z() const {
  return z_;
  // return z_
}

Vec3 Vec3::operator-() const {
  return Vec3(-x_, -y_, -z_);
  // return a new vector which has the same components but they
  // have been negated. For example, if you have a variable p then to
  // negate it is -p.
}

double Vec3::operator[](int i) const noexcept(false) {
  if (i == 0) {
    return x_;
  } else if (i == 1) {
    return y_;
  } else if (i == 2) {
    return z_;
  } else {
    throw std::out_of_range("Index out of range. Must be between 0 and 2.");
  }

  // The implementation is the same body as
  // double& Vec3::operator[](int i) noexcept(false).
}

double& Vec3::operator[](int i) noexcept(false) {
  // Yes, this will generate a linter warning:
  // readability-else-after-return
  // Since we are ignoring switch statements in CPSC 120, there does not
  // exist a CPSC 120 friendly way to write the logic below other than
  // using returns after elses.
  if (i == 0) {
    return x_;
  } else if (i == 1) {
    return y_;
  } else if (i == 2) {
    return z_;
  } else {
    throw std::out_of_range("Index out of range. Must be between 0 and 2.");
  }
}

// Yes, this will generate a linter warning:
// readability-convert-member-functions-to-static
// For the sake of CPSC 120, we will leave this as a member function
// although it is better off being a static class function.
int Vec3::size() const { return kSize_; }

double Vec3::length() const { return std::sqrt(length_squared()); }

double Vec3::length_squared() const {
  double d = x_ * x_ + y_ * y_ + z_ * z_;
  // return the sum of the square of the 
  // components. That means x_ * x_ + y_ * y_ + z_ * z_.
  return length_squared();
}

std::ostream& operator<<(std::ostream& out, const Vec3& v) {
  out << v.x();
  out << v.y();
  out << v.z();
  return out;
  // send to out something that will look like "(1.2, 3.4, 5.6)".
  // Remember that this is a function and not a member function so you 
  // can only see/use things that are publich. Hint: you can't use x_, y_,
  // or z_. You can use v.x(), v.y(), or v.z(). Don't forget the return.
}

Vec3 operator+(const Vec3& lhs, const Vec3& rhs) {

  return Vec3(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
  // Return a new Vec3 with the sum of the components.
  // lhs means "left hand side" and rhs means "right hand side".
  // lhs + rhs means Vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z)
}

Vec3 operator-(const Vec3& lhs, const Vec3& rhs) {
  return Vec3(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
  // Return a new Vec3 with the difference of the components.
  // lhs means "left hand side" and rhs means "right hand side".
  // lhs - rhs means Vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z)
}

Vec3 operator*(double lhs, const Vec3& rhs) {
  return Vec3(lhs * rhs.x(), lhs * rhs.y(), lhs * rhs.z());
  // Return a new Vec3 with the components scaled by lhs.
  // lhs means "left hand side" and rhs means "right hand side".
  // lhs * rhs means Vec3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z)
}

Vec3 operator*(const Vec3& lhs, double rhs) {
  return Vec3(rhs * lhs.x(), rhs * lhs.y(), rhs * lhs.z());
  // Return a new Vec3 with the components scaled by lhs.
  // lhs means "left hand side" and rhs means "right hand side".
  // Hint: Reuse Vec3 operator*(double lhs, const Vec3& rhs) by 
  // swapping the order of lhs and rhs.
}

Vec3 operator/(const Vec3& lhs, double rhs) noexcept(false) {
  // Ever wonder how to throw an exception? This is how.
  if (rhs == 0.0) {
    throw std::domain_error("t is zero; divide by zero exception.");
  }
  return (1.0 / rhs) * lhs;
}

bool operator==(const Vec3& lhs, const Vec3& rhs) {
  bool status = true;
  double epsilon = 1e-7;
  for (int i = 0; i < lhs.size(); i++) {
    double a = lhs[i];
    double b = rhs[i];
    // You can't directly compare to see if a floating point number is
    // equal to another floating point number. You have to check to see
    // if the number is withing `epsilon` (a really small number).
    status = status && ((a == b) || ((a - epsilon) < b && (a + epsilon) > b));
  }
  return status;
}

bool operator!=(const Vec3& lhs, const Vec3& rhs) { return not(lhs == rhs); }

double Dot(const Vec3& u, const Vec3& v) {
  double dot = u.x() * v.x() + u.y() + v.y() * u.z() * v.z();
  return dot;
  // Calculate the dot product between u and v.
  // See https://en.wikipedia.org/wiki/Dot_product
  // This function returns a double.
  // u.x * v.x + u.y + v.y * u.z * v.z
}

Vec3 Cross(const Vec3& u, const Vec3& v) {
  return Vec3{u.y() * v.z() - u.z() * v.y(), u.z() * v.x() - u.x() * v.z(),
              u.x() * v.y() - u.y() * v.x()};
}

Vec3 UnitVector(const Vec3& v) noexcept(false) {
  double length = v.length();
  if (length == 0.0) {
    // This is how you throw an exception.
    throw std::domain_error("v.length() is zero; divide by zero exception.");
  }
  return v / v.length();
}

Vec3 Reflect(const Vec3& v, const Vec3& n) { return (2 * Dot(v, n) * n) - v; }
