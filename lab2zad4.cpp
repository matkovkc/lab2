#include <iostream>
#include <ctime>

using namespace std;

class Stog {
   
   private:
      struct Atom {
         int data;
         Atom *next;
      };

      Atom *head;

   public:
      Stog() {head = nullptr;}

      bool push(int data) {
         Atom *newAtom = new (nothrow) Atom;     
         if(newAtom == nullptr) {return false;}

         newAtom->data = data;
         newAtom->next = head;

         head = newAtom;
         return true;
      }

      bool pop(int &el) {
         if(head == nullptr) {return false; }

         Atom *tbd = head;
         el = head->data;
         head = head->next;
         delete tbd;
         return true;
      }
};


int main() {
   Stog s;
   int n;

   srand((unsigned)time(0));

   for(int i = 0; i < 101; i++) {
      n = rand() % 100 + 1;
      s.push(n);
   }
   int el, i = 100;
   cout << "VRH" << endl;
   while(s.pop(el)) {
      cout << i << ". ->" << el << endl;
      i--;
   }

   return 0;
}