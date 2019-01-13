#include "iostream"
#include "cmath"

using namespace std;

// На вход вашей программе в стандартном вводе даны действительные коэффициенты A, B и C уравнения Ax² + Bx + C = 0. 
// Выведите все его различные действительные корни в любом порядке. Гарантируется, что хотя бы один из коэффициентов не равен нулю.

int main () {
    float a, b, c;
    cin >> a >> b >> c;
    if (((a != 0) && (b != 0) && (c != 0)) || ((a != 0) && (b != 0) && (c == 0))) {
        float discr;
        discr = b*b - (4*a*c);
        if (discr < 0) ;
        else if (discr == 0) cout << -b/(2*a) << endl;
        else cout << (-b + sqrt(discr))/(2*a) << " " << (-b - sqrt(discr))/(2*a) << endl;
    }
    else if ((a == 0) && (b != 0) && (c != 0)) {
        cout << -c/b << endl;
    }
    else if ((a != 0) && (b == 0) && (c != 0)) {
        cout << -c/sqrt(a) << " " << -c/-sqrt(a) << endl;
    }
    else if (((a != 0) && (b == 0) && (c == 0)) || (((a == 0) && (b != 0) && (c == 0)))) {
        cout << 0 << endl;
    }
    else ;
    return 0;
}