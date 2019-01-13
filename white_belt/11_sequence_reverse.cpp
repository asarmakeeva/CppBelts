#include "iostream"
#include "vector"

using namespace std;

//Реализуйте функцию void Reverse(vector<int>& v), которая переставляет элементы вектора в обратном порядке.


void Reverse(vector<int>& v){
    vector<int> buf = v;
    for (int i = 0; i < buf.size(); i++){
        v[i] = buf[buf.size()-i-1];
    }
}

int main(){
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for (int i : numbers){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

// void Reverse(vector<int>& v) {
//   int n = v.size();  // для удобства сохраним размер вектора в переменную n
//   for (int i = 0; i < n / 2; ++i) {
//     // элемент с индексом i симметричен элементу с индексом n - 1 - i
//     // поменяем их местами с помощью временной переменной tmp
//     int tmp = v[i];
//     v[i] = v[n - 1 - i];
//     v[n - 1 - i] = tmp;
//   }
// }