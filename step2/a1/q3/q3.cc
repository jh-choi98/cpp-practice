#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class InputPrinter {
  public:
    void printReverse() {
        vector<int> numbers;
        int input;

        while (cin >> input) {
            numbers.push_back(input);
        }

        cout << "Original order: " << endl;
        for (int number : numbers) {
            cout << number << " ";
        }
        cout << endl;

        cout << "Reverse order: " << endl;
        for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    void printPalindrome() {
        int input;
        cin >> input;
        string str = to_string(input);
        cout << "*********** result ***********" << endl;
        for (char ch : str) {
            cout << ch;
        }
        for (auto it = str.rbegin(); it != str.rend(); ++it) {
            cout << *it;
        }
        cout << endl;
    }

    void printReverseFilter() {
        vector<int> numbers;
        int input;
        while (cin >> input) {
            numbers.push_back(input);
        }
        int lowerBound =
            numbers.front() < numbers.back() ? numbers.front() : numbers.back();
        int upperBound =
            numbers.front() < numbers.back() ? numbers.back() : numbers.front();
        cout << "*********** result ***********" << endl;
        for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
            if (lowerBound <= *it && *it <= upperBound) {
                cout << *it << " ";
            }
        }
        cout << endl;
    }

    void printReverseMean() {
        vector<int> numbers;
        int input;
        int sum = 0;
        while (cin >> input) {
            numbers.push_back(input);
            sum += input;
        }
        int mean = sum / numbers.size();

        cout << "*********** result ***********" << endl;
        for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
            if (abs(*it - mean) <= 1) {
                cout << *it << endl;
            }
        }
    }
};

int main() {
    InputPrinter p;
    // p.printReverse();
    // p.printPalindrome();
    // p.printReverseFilter();
    p.printReverseMean();
}
