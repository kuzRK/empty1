#include <iostream>

bool isPyth( unsigned a, unsigned b, unsigned c)
{
  bool a = (b*b + c*c == a*a);
  a  = a || (a*a + c*c == b*b);
  a  = a || (b*b + a*a == c*c);
  return   a;
}
int main()
{
  using u_t = unsigned;
  u_t a = 0;
  u_t b = 0;
  u_t c = 0;
  size_t count = 0;
  while (std::cin >> a) {
    count += isPyth(a,b,c);
  }

  if (std::cin.eof()) {
    std::cout << count;
    std::cout << "\n";
  } else if (std::cin.fail()) {
    std::cerr << "input err\n";
    return 1;
  }

}
