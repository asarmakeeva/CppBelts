#include "iostream"
#include "string"
#include "vector"
#include "fstream"

using namespace std;

// Напишите функцию, которая

// называется PalindromFilter
// возвращает vector<string>
// принимает vector<string> words и int minLength и возвращает все строки из вектора words, которые являются палиндромами и 
// имеют длину не меньше minLength
// Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.

bool IsPalindrom(string& l){
    string line = l;

    for (int i = 0; i < line.size(); i++){
        if (line[i] != line[line.size()-i-1]) return false;
    }
    return true;
}

vector<string> PalindromFilter(vector<string>& words, int& minLength){
    vector<string> res(0);
    for (string word : words){
        if ((IsPalindrom(word)) && (word.size() < minLength)) res.push_back(word);
    }
    return res;
}

int main(){
    vector<string> words;
    string word;
    ifstream input("inp.txt");
    while (getline(input, word, ' ')){
        cin >> word;
        words.push_back(word);
    }
    int minLength = 5;
    vector<string> res = PalindromFilter(words, minLength);
    for (string i : res) cout << i << endl;
    return 0;
}