#include "iostream"
#include "string"

using namespace std;

// В стандартном потоке даны три строки, разделённые пробелом. Каждая строка состоит из строчных латинских букв и 
//имеет длину не более 30 символов. Выведите в стандартный вывод лексикографически минимальную из них.

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    //cout << a.length() << " " << b.length() << " " << c.length() << endl;
    if ((a.length() < b.length()) && (a.length() < c.length())) cout << a <<endl;
    else if ((b.length() < c.length()) && (b.length() < a.length())) cout << c << endl;
    else cout << c << endl;
    return 0;
}