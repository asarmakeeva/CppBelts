#include "iostream"

using namespace std;

// Напишите функцию, которая

// называется Factorial
// возвращает int
// принимает int и возвращает факториал своего аргумента. Гарантируется, что аргумент функции по модулю не превышает 10. 
// Для отрицательных аргументов функция должна возвращать 1.

int Factorial(int n1){
    if (n1 <= 1) return 1;
    else return n1*Factorial(n1-1);
}

int main(){
    int n1;
    cin >> n1;
    cout << Factorial(n1) << endl;
    return 0;
}