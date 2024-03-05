#include <iostream>
using namespace std;

int main() {
    int numRows, numCols;
    cout << "Enter numRows; ";
    cin >> numRows;

    cout << "Enter numCols: ";
    cin >> numCols;

    int** arr2D;
    arr2D = new int* [numRows]; // allocation

    for (int i = 0; i < numRows; i++)
        arr2D[i] = new int[numCols];

    for (int i=0; i<numRows; i++) //deallocation
        delete[] arr2D[i];

    delete[] arr2D;
}

