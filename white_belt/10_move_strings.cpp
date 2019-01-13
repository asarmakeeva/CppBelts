#include "iostream"
#include "string"
#include "vector"

using namespace std;

// Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination, и дописывает все строки из
//  первого вектора в конец второго. После выполнения функции вектор source должен оказаться пустым.

void MoveStrings(vector<string>& source, vector<string>& destination){
    for (string i : source){
        destination.push_back(i);
    }
    source.clear();
}

int main(){
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    cout << "size = " << destination.size() << endl;
    for (string i : destination){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}