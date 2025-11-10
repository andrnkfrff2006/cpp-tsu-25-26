#include <iostream>
#include <string>

using namespace std;

struct List {
    // определите самостоятельно
};

int main() {
    // Подсказка - используйте List
    // А для создания новых элементов списка воспользуйтесь оператором new

    // Тесты из примера можно пройти без списка, сохраняя только последние значения
    // Но финальные тесты так не пройдут!
    long long int last_value = 100;
    long long int current_value = 100;

    string cmd;
    while (cin >> cmd) {
        // Выполните обработку команд append, go, print, reset
        if (cmd == "append") {
            long long X; cin >> X;
            // Ваша реализация здесь
            last_value = current_value = X;
            cout << "append " << X << " - OK" << '\n';
        } else if (cmd == "go") {
            long long N; cin >> N; long long originalN = N;
            // Ваша реализация здесь
            current_value = last_value;
            cout << "go " << originalN << " - OK" << '\n';
        } else if (cmd == "print") {
            // Ваша реализация здесь
            cout << "print " << current_value << " - OK" << '\n';
        } else if (cmd == "reset") {
            // Ваша реализация здесь
            current_value = 100;
            cout << "reset - OK" << '\n';
        } else {
            // Игнорируем неизвестные команды (не должны встречаться по условию)
        }
    }

    return 0;
}
