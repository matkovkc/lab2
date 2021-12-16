#include <iostream>
#include <string>

using namespace std;

class Osoba
{
private:
    string ime;
    unsigned short int starost;
    friend bool operator<(Osoba const &a, Osoba const &b);

public:
    Osoba() {};
    Osoba(string ime, unsigned short int starost) : ime(ime), starost(starost) {}
    string getIme() { return ime; }
    unsigned short int getStarost() { return starost; }
    void setIme(string ime) { this->ime = ime; }
    void setStarost(unsigned short int starost) { this->starost = starost; }
    ~Osoba() { cout << "Obrisan/a " << this->ime << "|" << this->starost << endl; }

    Osoba &operator=(const Osoba &osoba)
    {
        this->ime = osoba.ime;
        this->starost = osoba.starost;

        return *this;
    }
};

bool operator<(Osoba const &a, Osoba const &b)
{
    if (a.starost < b.starost)
        return a.starost < b.starost;
    return a.ime[0] < b.ime[0];
}

template <typename T>
void InsertionSort(T A[], int n)
{
    for(int i = 1; i < n; i++)
    {
        T temp = A[i];
        int j;
        for(j = i; j >= 1 && temp < A[j - 1]; j--)
            A[j] = A[j - 1];
        A[j] = temp;
    }
}

int main(void)
{
    static const int MAX = 5;
    Osoba *osobe = new Osoba[MAX];
    for(int i = 0; i < MAX; i++)
    {
        string ime;
        cout << "Upisite ime " << i + 1 << ". osobe: ";
        getline(cin, ime);
        unsigned short int starost;
        cout << "Upisite starost " << i + 1 << ". osobe: ";
        cin >> starost;
        cin.ignore(1, '\n');
        osobe[i] = Osoba(ime, starost);
    }

    InsertionSort(osobe, MAX);

    cout << "{";
    for(int i = 0; i < MAX; i++)
    {
        if(i == MAX - 1)
        {
            cout << "{\"" << osobe[i].getIme() << "\"," << osobe[i].getStarost() << "}}" << endl;
            break;
        }
        cout << "{\"" << osobe[i].getIme() << "\"," << osobe[i].getStarost() << "},";
    }

    delete[] osobe;

    return 0;
}