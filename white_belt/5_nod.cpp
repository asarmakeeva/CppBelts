#include "iostream"
#include "vector"

using namespace std;

//В stdin даны два натуральных числа. Выведите в stdout их наибольший общий делитель.

int nod(int& n1, int& n2){
    int num1 = n1%n2;
    int num2 = n2;

    if (num1 == 0) return num2;
    else return nod(num2, num1);
}

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    cout << nod(n1,n2) << endl;
    return 0;
}