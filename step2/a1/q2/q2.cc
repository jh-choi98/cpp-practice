#include <exception>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*

    exception() noexcept;
    exception( const exception& other ) noexcept;


    */
class BillProcessor {
  public:
    // print_money(amount) prints amount using a "money" or "dollars" notation.
    void printMoney(int amount) {
        if (amount <= -9999999 || amount >= 9999999) {
            throw exception{};
        }

        string prefix = "";
        if (amount < 0) {
            prefix += "-";
            amount *= -1;
        }
        int cent = amount % 100;
        int dollar = amount / 100;

        prefix += "$";
        if (dollar == 0) {
            prefix += "0";
        }

        string amountDigit = "";
        while (dollar > 0) {
            int remainder = dollar % 1000;
            dollar = dollar / 1000;

            string intermediate = "";
            if (dollar > 0) {
                intermediate = ",";
            }

            if (remainder == 0) {
                amountDigit.insert(0, intermediate + "000");
            } else {
                amountDigit.insert(0, intermediate + to_string(remainder));
            }
        }

        cout << prefix << amountDigit << ".";

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
        int params[] = {amount, tax, tip, amount + tax + tip};
        string msgs[] = {"bill:   ", "tax:    ", "tip:    ", "total:  "};

        for (int i = 0; i < 4; i++) {
            cout << msgs[i];
            try {
                printMoney(params[i]);
            } catch (exception &e) {
                cerr << "amount exceeds out of boundary" << endl;
            }
        }

        cout << endl;
    }
};

int main() {
    BillProcessor b;
    cout << "********************** printMoney **********************" << endl;

    // b.printMoney(999999);
    // b.printMoney(1000000);
    // b.printMoney(1000);
    // b.printMoney(-1000);
    // b.printMoney(1000000000);
    // b.printMoney(1000000007);
    // b.printMoney(5);
    // b.printMoney(-5);
    cout << "********************** printBill **********************" << endl;
    b.printBill(10000, 13, 10);
    b.printBill(1000000, 130, 100);
    b.printBill(1000, 5, 5);
}
