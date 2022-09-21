#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char** argv) {
    double a, b, c, d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cout << setprecision (1) << setw(9) << a << showpoint << setw(10) 
            << setprecision(2) << a << setw(10) << setprecision(3) << a << endl;
    cout << noshowpoint << setprecision (1) << setw(9) << b << showpoint << setw(10) 
            << setprecision(2) << b << setw(10) << setprecision(3) << b << endl;
    cout << noshowpoint << setprecision (1) << setw(9) << c << showpoint << setw(10) 
            << setprecision(2) << c << setw(10) << setprecision(3) << c << endl;
    cout << noshowpoint << setprecision (1) << setw(9) << d << showpoint << setw(10) 
            << setprecision(2) << d << setw(10) << setprecision(3) << d;
    return 0;
}