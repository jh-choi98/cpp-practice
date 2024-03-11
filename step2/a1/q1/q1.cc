#include <iostream>
using namespace std;

class Calculator {
    int sqrt_int_helper(int n, int result) {
        if (result * result <= n && n < (result + 1) * (result + 1)) {
            return result;
        }

        return sqrt_int_helper(n, result + 1);
    }

    int log_2_helper(int n, int result, int b) {
        if (b == n) {
            return result;
        }

        if (b < n && n < b * 2) {
            return result + 1;
        }

        return log_2_helper(n, result + 1, b * 2);
    }

    // 2^lower <= n < 2^lower+1
    // int result = 0;
    // while (lower + 1 < upper) {
    //     if (mid == n) {
    //         return result;
    //     } else if (n < mid) {
    //         upper /= 2;
    //         result = upper;
    //     } else {
    //         lower *= 2;
    //         result = lower;
    //     }
    // }
    // return result + 1;

    // Time complexity: O(logn)
    int log_2_helper2(int n, int lower, int upper, int mid, int result) {
        if (mid == n) {
            cout << "n: " << n << ", lower: " << lower << ", upper: " << upper
                 << ", result: " << result << ", mid: " << mid << endl;
            return result;
        } else if (lower + 1 == upper) {
            cout << "n: " << n << ", lower: " << lower << ", upper: " << upper
                 << ", result: " << result << ", mid: " << mid << endl;
            return result + 1;
        } else if (n < mid) {
            cout << "n: " << n << ", lower: " << lower << ", upper: " << upper
                 << ", result: " << result << ", mid: " << mid << endl;
            return log_2_helper2(n, lower, upper / 2, 2 ^ [(upper + lower) / 2],
                                 upper / 2);
        } else {
            cout << "n: " << n << ", lower: " << lower << ", upper: " << upper
                 << ", result: " << result << ", mid: " << mid << endl;
            return log_2_helper2(n, lower * 2, upper, mid * 2, lower * 2);
        }
    }
    // log2 b = result  => 2^result = b

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

        if (n < 0) {
            cerr << "The square root of a negative integer can exist in a real "
                    "number"
                 << endl;
            return -1;
        }

        if (n < 2) {
            return n;
        }

        int initial = 2;
        while (initial * initial <= n) {
            initial *= 2;
        }

        return sqrt_int_helper(n, initial / 2);
    }
    int log_2(int n) {
        if (n <= 0) {
            cerr << "n should be positive" << endl;
            return -1;
        }
        if (n == 1) {
            return 0;
        }

        const int value_2_to_16 = expt(2, 16);
        int lower = 1;
        int upper = 32;
        int mid = value_2_to_16;

        // 2^lower <= n < 2^lower+1
        // int result = 0;
        // while (lower + 1 < upper) {
        //     if (mid == n) {
        //         return result;
        //     } else if (n < mid) {
        //         upper /= 2;
        //         result = upper;
        //     } else {
        //         lower *= 2;
        //         result = lower;
        //     }
        // }
        // return result + 1;

        return log_2_helper2(n, 1, 32, value_2_to_16, 0);
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

int test(int actual[], int expected[], int len, string testName) {
    cout << "Test " << testName << " begin ..." << endl;
    for (int i = 0; i < len; i++) {
        if (actual[i] == expected[i])
            continue;
        cout << i << "-th Test " << testName << " failed: " << endl;
        cout << "Actual: " << actual[i] << endl;
        cout << "Expected: " << expected[i] << endl;
    }
    cout << "Test max end" << endl;
}

int main() {
    Calculator c;

    cout << "******************* max ************************" << endl;
    // cout << c.max(1, 5) << endl;
    // cout << c.max(3, 2) << endl;
    // cout << c.max(0, 4) << endl;
    // cout << c.max(-1, 5) << endl;
    // cout << c.max(-1, -3) << endl;
    const int maxLen = 5;
    int maxTestActual[maxLen] = {c.max(1, 5), c.max(3, 2), c.max(0, 4),
                                 c.max(-1, 5), c.max(-1, -3)};
    int maxTestExpected[maxLen] = {5, 3, 4, 5, -1};
    test(maxTestActual, maxTestExpected, maxLen, "Max");
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
