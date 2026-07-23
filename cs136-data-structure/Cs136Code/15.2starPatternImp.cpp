#include <iostream>
#include <iomanip>

using namespace std;

void starHelper(const int i) {
    for (int j = 0; j < i; j++) {
        cout << " *";
    }
}

void printStars(int i, int lines) {

    if (i <= lines) {
        cout << setw(lines - i + 1) << " ";

        //for () edit this line
        starHelper(i);
        cout << endl;
        printStars(i + 1, lines);

        if (i != lines){
            cout << setw(lines - i + 1) << " ";

            //for () edit this line
            starHelper(i);
            cout << endl;
        }
    }
}

void Test15_2() {
    int lines;

    cout << "Enter the number of lines in the grid: ";
    cin >> lines;
    cout << endl;

    printStars(1, lines);

    cout << endl;
    system("pause");
}
