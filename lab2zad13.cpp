#include <iostream>
#include <string>

using namespace std;

class Vozilo
{
private:
    string model;
    int godinaProizvodnje;

    friend bool operator<(Vozilo const &a, Vozilo const &b);

public:
    Vozilo(){};
    Vozilo(string model, int godinaProizvodnje) : model(model), godinaProizvodnje(godinaProizvodnje){};

    string getModel() { return this->model; }
    int getGodinaProizvodnje() { return this->godinaProizvodnje; }

    void setModel(string model) { this->model = model; }
    void setGodinaProizvodnje(int godinaProizvodnje) { this->godinaProizvodnje = godinaProizvodnje; }

    ~Vozilo() {cout << "Obrisan " << this->model << "(" << this->godinaProizvodnje << ")..." << endl; }

    Vozilo &operator=(Vozilo const &vozilo)
    {
        this->model = vozilo.model;
        this->godinaProizvodnje = vozilo.godinaProizvodnje;

        return *this;
    }
};

bool operator<(Vozilo const &a, Vozilo const &b)
{
    return (a.model != b.model) ? (a.model < b.model) : a.godinaProizvodnje > b.godinaProizvodnje;
}

void Zamijeni(Vozilo &prvi, Vozilo &drugi)
{
    Vozilo temp = prvi;
    prvi = drugi;
    drugi = temp;
    return;
}

template <typename T>
void SelectionSort(T A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        int min = i;
        for (int j = i + 1; j < N; j++)
            if (A[j] < A[min])
                min = j;
        Zamijeni(A[i], A[min]);
    }
}

int main(void)
{
    static const int MAX = 6;
    Vozilo *vozila = new Vozilo[MAX];
    for (int i = 0; i < MAX; i++)
    {
        string model;
        cout << "Upisite model " << i + 1 << ". vozila: ";
        getline(cin, model);
        int godinaProizvodnje;
        cout << "Upisite godinu proizvodnje " << i + 1 << ". vozila: ";
        cin >> godinaProizvodnje;
        cin.ignore(1, '\n');

        vozila[i] = Vozilo(model, godinaProizvodnje);
    }

    SelectionSort(vozila, MAX);

    cout << "{";
    for (int i = 0; i < MAX - 1; i++)
    {
        cout << "{\"" << vozila[i].getModel() << "\"," << vozila[i].getGodinaProizvodnje() << "}, ";
    }
    cout << "{\"" << vozila[MAX - 1].getModel() << "\"," << vozila[MAX - 1].getGodinaProizvodnje() << "}}" << endl;

    delete[] vozila;

    return 0;
}