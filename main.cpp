#include <iostream>

bool isPyth( unsigned a, unsigned b, unsigned c)
{
  bool p = (b*b + c*c == a*a);
  p  = p || (a*a + c*c == b*b);
  p  = p || (b*b + a*a == c*c);
  return   a;
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

  if (std::cin.eof()) {
    std::cout << count;
    std::cout << "\n";
  } else if (std::cin.fail()) {
    std::cerr << "input err\n";
    return 1;
  }

}
