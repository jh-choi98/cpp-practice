#include <iostream>
#include <string>
using namespace std;

class BillProcessor {
  public:
    void printMoney(int amount) {
        if (amount < 0) {
            cout << "-";
            amount *= -1;
        }
        int cent = amount % 100;
        int dollar = amount / 100;

        cout << "$";
        if (dollar == 0) {
            cout << "0";
        }
        string str = "";

        while (dollar > 0) {
            int remainder = dollar % 1000;
            dollar = dollar / 1000;

            if (remainder == 0) {
                str.insert(0, "000");
            } else {
                str.insert(0, to_string(remainder));
            }

            if (dollar > 0) {
                str.insert(0, ",");
            }
        }

        cout << str << ".";

        if (cent < 10) {
            cout << "0";
        }
        cout << cent << endl;
    }
    void printBill(int amount, int taxRate, int tipRate) {
        if (taxRate < 0 || tipRate < 0) {
            cerr << "Tax rate and tip rate should be non-negative" << endl;
            return;
        }
        int tax = amount * (taxRate * 0.01);
        int tip = tax * (tipRate * 0.01);
        cout << "bill:   ";
        printMoney(amount);
        cout << "tax:    ";
        printMoney(tax);
        cout << "tip:    ";
        printMoney(tip);
        cout << "total:  ";
        printMoney(amount + tax + tax);
        cout << endl;
    }
};

int main() {
    BillProcessor b;
    cout << "********************** printMoney **********************" << endl;
    b.printMoney(999999);
    b.printMoney(1000000);
    b.printMoney(1000);
    b.printMoney(-1000);
    b.printMoney(1000000000);
    b.printMoney(1000000007);
    b.printMoney(5);
    b.printMoney(-5);
    cout << "********************** printBill **********************" << endl;
    b.printBill(10000, 13, 10);
    b.printBill(1000000, 130, 100);
    b.printBill(1000, 5, 5);
}
