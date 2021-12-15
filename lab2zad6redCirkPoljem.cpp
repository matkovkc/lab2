#include <iostream>

using namespace std;

//ulaz je read, izlaz je write

class Red {
    private:
        static const int MAX = 10;
        double red[MAX];
        int read = 0;
        int write = 0;

    public:

        bool dodaj(double broj) {
            if(((write + 1) % MAX) == read) {
                return false;
            }
            red[write] = broj;
            write = (write + 1) % MAX;
            return true;
        }

        bool skini(double &broj) {
            if(write == read) {
                return false;
            }
            broj = red[read];
            read = (read + 1) % MAX;
            return true;
        }

        void print() {
            cout << "READ";
            for(int i = read; i < write; i++) {
                cout << " -> " << red[i];
            }
            cout << " <- WRITE" << endl;
        }
};

int main() {
    
    Red r;
    int n;
    cout << "Upisite velicinu reda n, n <= 10: ";
    cin >> n;

    double broj;
    for(int i = 0; i < n; i++) {
        cout << "Upisite jedan realan broj kojeg zelite upisati u red > ";
        cin >> broj;
        r.dodaj(broj);
    }
    
    r.print();

    cout << "READ";
    while(r.skini(broj)) {
        cout << " -> " << broj;
    }
    cout << " <- WRITE" << endl;
    return true;
}
