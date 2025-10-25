#include <iostream>
#include <limits>

unsigned max_u()
{
  using u_t = unsigned;
  using u_limits = std::numeric_limits<u_t>;
  return u_limits::max();
}

bool oversquare(unsigned a)
{
  unsigned res = 0;
  if (a > max_u() / a) {
    return true;
  }
  res = a * a;
  return false;
}

bool overplus(unsigned a, unsigned b)
{
  unsigned res = 0;
  if (a > max_u() - b) {
    return true;
  }
  res = a + b;
  return false;
}

bool isPyth(unsigned a, unsigned b, unsigned c)
{
  bool p = (b*b + c*c == a*a);
  p  = p || (a*a + c*c == b*b);
  p  = p || (b*b + a*a == c*c);
  return   p;
}

int main()
{
  using u_t = unsigned;
  u_t a = 0;
  u_t b = 0;
  u_t c = 0;
  std::cin >> c >> b;
  size_t count = 0;
  while (std::cin >> a) {
    count += isPyth(a,b,c);
    c = b;
    b = a;
  }

  bool i1 = oversquare(a);
  bool i2 = oversquare(b);
  bool i3 = oversquare(c);
  bool osum1 = overplus(a*a, b*b);
  bool osum2 = overplus(a*a, c*c);
  bool osum3 = overplus(c*c, b*b);
  if (i1 || i2 || i3 || osum1 || osum2 || osum3) {
    std::cerr << "overflow err\n";
    return 2;
  }

  if (std::cin.eof()) {
    std::cout << count;
    std::cout << "\n";
  } else if (std::cin.fail()) {
    std::cerr << "input err\n";
    return 1;
  }
}
