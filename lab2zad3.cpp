#include <iostream>
#include <ctime>

using namespace std;


class Stog {
    private:
        const static int MAX = 100;
        int stog[MAX];
        int vrh = -1;

    public: 
        bool push(int el) {
            if(vrh >= (MAX - 1))
                return false;
            stog[++vrh] = el;
            return true;
        }

        bool pop(int &el) {
            if(vrh < 0) {
                return false;
            } else {
                el = stog[vrh--];
            }
        }

        void print() {
            cout << "VRH" << endl;;
            for(int i = vrh; i > -1; i--) {
                cout << i <<". ->" << stog[i] << endl;
            }
            cout << "DNO" << endl;
        }

};


int main() {
    Stog s;
    int n;
    bool dodano;

    srand((unsigned)time(0));

    for(int i = 0; i < 101; i++) {
        n = rand() % 100 + 1;
        dodano = s.push(n);

        if(!dodano) {
            cout << "Stog je pun" << endl;
        }
    }

    s.print();

    return 0;
}