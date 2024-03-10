#include <iostream>
using namespace std;

class Calculator {
    int sqrt_int_helper(int n, int result) {
        if (result * result <= n && n < (result + 1) * (result + 1)) {
            return result;
        }

        return sqrt_int_helper(n, result + 1);
    }

    int log_2_helper(int n, int result) {
        if (expt(2, result) <= n && n < expt(2, result + 1)) {
            return result;
        }

        return log_2_helper(n, result + 1);
    }

  public:
    int max(int a, int b) { return a > b ? a : b; }
    int expt(int b, int n) {
        if (n < 0) {
            cerr << "n should be non-negative" << endl;
            return -1;
        }
        if (n == 0) {
            return 1;
        }
        if (b == 0) {
            return 0;
        }
        int result = 1;
        for (int i = 0; i < n; ++i) {
            result *= b;
        }
        return result;
    }
    int sqrt_int(int n) {
        if (n == 0) {
            return 0;
        }
        if (n < 0) {
            cerr << "The square root of a negative integer can exist in a real "
                    "number"
                 << endl;
            return -1;
        }
        return sqrt_int_helper(n, 0);
    }
    int log_2(int n) {
        if (n <= 0) {
            cerr << "n should be positive" << endl;
            return -1;
        }
        if (n == 1) {
            return 0;
        }
        return log_2_helper(n, 0);
    }
    int away_div(int nom, int denom) {
        if (denom == 0) {
            cerr << "A denominator can not be 0" << endl;
            return -1;
        }
        if (nom % denom) {
            return nom / denom + 1;
        } else {
            return nom / denom;
        }
    }
    int chocolate_boxes(int caramel, int almond, int mint, int nut_free,
                        int box_size) {
        if (box_size % 2 != 0) {
            cerr << "A box size should be even" << endl;
            return -1;
        }

        return away_div(nut_free, box_size) + 0;
    }
};

int main() {
    Calculator c;

    cout << "******************* max ************************" << endl;
    cout << c.max(1, 5) << endl;
    cout << c.max(3, 2) << endl;
    cout << c.max(0, 4) << endl;
    cout << c.max(-1, 5) << endl;
    cout << c.max(-1, -3) << endl;
    cout << "******************* expt ************************" << endl;
    cout << c.expt(2, 5) << endl;
    cout << c.expt(2, 0) << endl;
    cout << c.expt(0, 5) << endl;
    cout << c.expt(2, -1) << endl;
    cout << c.expt(-2, 1) << endl;
    cout << c.expt(-2, 2) << endl;
    cout << "******************* sqrt_int ************************" << endl;
    cout << c.sqrt_int(2) << endl;
    cout << c.sqrt_int(-5) << endl;
    cout << c.sqrt_int(0) << endl;
    cout << c.sqrt_int(4) << endl;
    cout << c.sqrt_int(169) << endl;
    cout << c.sqrt_int(13) << endl;
    cout << "******************* log_2 ************************" << endl;
    cout << c.log_2(1) << endl;
    cout << c.log_2(4) << endl;
    cout << c.log_2(16) << endl;
    cout << c.log_2(13) << endl;
    cout << c.log_2(25) << endl;
    cout << "******************* away_div ************************" << endl;
    cout << c.away_div(2, 3) << endl;
    cout << c.away_div(12, 3) << endl;
    cout << c.away_div(0, 3) << endl;
    cout << c.away_div(2, 0) << endl;
}
