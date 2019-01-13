#include "iostream"
#include "string"

using namespace std;

// Напишите функцию, которая

// называется IsPalindrom
// возвращает bool
// принимает параметр типа string и возвращает, является ли переданная строка палиндромом
// Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево. 
// Пустая строка является палиндромом.

bool IsPalindrom(string& l){
    string line = l;

    for (int i = 0; i < line.size(); i++){
        if (line[i] != line[line.size()-i-1]) return false;
    }
    return true;
}

int main(){
    string word;
    cin >> word;
    cout << IsPalindrom(word) << endl;
    return 0;
}