#include <iostream>
#include <string>

using namespace std;

struct Node {
    long long int val;
    Node* next;
    Node(long long int _val) : val(_val), next(nullptr) {}
};

struct List {
    Node* first;
    Node* last;
    Node* cur;
    List() : first(nullptr), last(nullptr), cur(nullptr) {}
};

int main() {
    // Подсказка - используйте List
    // А для создания новых элементов списка воспользуйтесь оператором new

    // Тесты из примера можно пройти без списка, сохраняя только последние значения
    // Но финальные тесты так не пройдут!
    long long int last_value = 100;
    long long int current_value = 100;
    List a;
    a.first = new Node(last_value);
    a.last = a.cur = a.first;
    
    string cmd;
    while (cin >> cmd) {
        // Выполните обработку команд append, go, print, reset
        if (cmd == "append") {
            long long X; cin >> X;
            Node* p = new Node(X);
            a.cur->next = p;
            a.cur = p;
            last_value = current_value = X;
            cout << "append " << X << " - OK" << '\n';
        } else if (cmd == "go") {
            long long N; cin >> N; long long originalN = N;
            Node* p = a.cur;
            while (p->next && N > 0) {
                p = p->next;
                N--;
            }
            last_value = p->val;
            current_value = last_value;
            cout << "go " << originalN << " - OK" << '\n';
        } else if (cmd == "print") {
            cout << "print " << current_value << " - OK" << '\n';
        } else if (cmd == "reset") {
            Node* p = a.first;
            a.cur = p;
            current_value = 100;
            cout << "reset - OK" << '\n';
        } else {
            cout << "???";
            break;
        }
    }

    return 0;
}
