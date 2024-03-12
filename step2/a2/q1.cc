#include <iostream>
#include <vector>
using namespace std;

class ASCIIArt {
  public:
    void drawBox(int size) { // size specifies the number of rows and columns
        if (size < 3) {
            cerr << "ERROR: a size should be bigger than or equal to 3" << endl;
            return;
        }
        int rows = size / 2;
        int cols = size - rows;

        cout << "+";
        for (int i = 0; i < cols; ++i) {
            cout << "-";
        }
        cout << "+" << endl;

        for (int i = 0; i < rows; ++i) {
            cout << "|";
            for (int j = 0; j < cols; ++j) {
                cout << " ";
            }
            cout << "|" << endl;
        }

        cout << "+";
        for (int i = 0; i < cols; ++i) {
            cout << "-";
        }
        cout << "+" << endl;
    }

    void drawTree(int height) {
        if (height < 4) {
            cerr << "ERROR: a height should be bigger than or equal to 4"
                 << endl;
            return;
        }
        int toMiddle = height - 2;
        for (int i = 0; i < toMiddle; ++i) {
            cout << " ";
        }
        cout << "*" << endl;

        int loopIndex = 0;

        while (loopIndex < height - 2) {
            for (int j = loopIndex; j < toMiddle - 1; ++j) {
                cout << " ";
            }

            cout << "/";
            for (int j = 0; j < 2 * loopIndex + 1; ++j) {
                cout << "o";
            }
            cout << "\\" << endl;
            ++loopIndex;
        }

        for (int i = 0; i < toMiddle - 1; ++i) {
            cout << " ";
        }
        cout << "|_|" << endl;
    }

    void decode() {
        int number;
        int asciiInt;
        vector<int> numbers;
        vector<int> asciiInts;

        while (cin >> number >> asciiInt) {
            numbers.push_back(number);
            asciiInts.push_back(asciiInt);
        }
        // for ()
    }
};

int main() {
    ASCIIArt a;
    a.decode();
}
