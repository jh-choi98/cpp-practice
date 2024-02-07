// #include "input.h"
#include "node.h"
#include "cmpGraphics.h"
#include "rgbProcessor.h"
#include <iostream>

using namespace std;

int main()
{
    Input *white = new Node<int>{255, 255, 255};
    Input *black = new Node<int>{0, new Node<int>{0, new Node<int>{0, nullptr}}};

    ColourManager c;
    ComputerGraphics cg{100, 100, &c};

    cout << cg.getColour(white) << endl;

    delete white;
    delete black;
}
