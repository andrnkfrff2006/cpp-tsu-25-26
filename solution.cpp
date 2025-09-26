#include <iostream>
int main() 
{
    long long int res = 0;
    int a;
    int pos;
    int n;
    std::cin >> n;
    for(int i = 1; i < n + 1; i++) {
      std::cin >> a >> pos; 
      res = res + a * pos;
    }
    std::cout << res;
    return 0;
}
