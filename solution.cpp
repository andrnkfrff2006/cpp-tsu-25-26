#include <iostream>
using namespace std;

int main() 
{
    int res = 0;
    int a;
    int pos;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> a >> pos; 
      res = res + a * pos;
    }
    cout << res;
    return 0;
}
