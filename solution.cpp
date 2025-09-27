#include <iostream>
#include <string>
int main() 
{
    std::string a = "";
    int price;
    int n;
    int q;
    long long int sum_price = 0;
    long long int sum_q = 0;
    std::cin >> a >> a >> a >> n;
    for(int i = 1; i < n + 1; i++) {
      while (true) {
        std::cin >> a;
        if (a == "за") {
          std::cin >> price;
          sum_price = sum_price + price;
          sum_q++;
          break;
        }
        if (a == "по") {
          std::cin >> price >> a >> q;
          sum_price = sum_price + price * q;
          sum_q = sum_q + q;
          break;
        }
      }
    }
    if (sum_q == 1) {
        std::cout << "Куплен товар за " << sum_price << " рублей" << std::endl;
    }  else if (sum_q > 1) {
        std::cout << "Куплено " << sum_q << " штук товара за " << sum_price << " рублей" << std::endl;
    }
    return 0;
}
