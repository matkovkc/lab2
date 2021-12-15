#include <iostream>
#include <ctime>

using namespace std;

class Stog {
    private: 
        const static int MAX = 10;
        int vrh = -1;
        int stog[MAX];

    public:
        bool push(int el) {
            if(vrh >= (MAX - 1)) {
                return false;
            }
            stog[++vrh] = el;
            return true;
        }

        bool pop(int &el) {
            if(vrh < 0) {
                return false;
            } else {
                el = stog[vrh--];
                return true;
            }
        }

        void print() {
            cout << "pocetak";
            for(int i = vrh; i > -1; i--) {
                cout << " -> " << stog[i];
            }
            cout << " kraj" << endl;
        }

};

int main() {
    Stog s;
    Stog pomocni;

    int n;

    srand((unsigned)time(0));

    for(int i = 0; i < 10; i++) {
        n = rand() % 10 + 1;
        pomocni.push(n);
    }
    cout << "ispis pomocnog stoga >   ";
    pomocni.print();  //njega cu okrenuti u s, i ispisati s, i onda ce taj s zapravo biti okrenuti pomocni i tako cu dobit ispis od DNA stoga, tj da je lement sa dna prvi koji se ispiše

    int el;
    while(pomocni.pop(el)) {
        s.push(el);
    }

    cout << "zavrsni stog s okrenutim elementima >   ";
    s.print();
    return 0;
}