#include <iostream>
int main() 
{
    int res = 0;
    int a;
    int pos;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
      std::cin >> a >> pos; 
      res = res + a * pos;
    }
    std::cout << res;
    return 0;
}
