#include "iostream"
#include "string"
#include "map"
#include "vector"
#include "tuple"

using namespace std;
//Реализуйте шаблонную функцию GetRefStrict, которая на вход принимает: map и значение ключа k. Если элемент по ключу k
//  в коллекции отсутствует, то функция должна бросить исключение runtime_error, иначе вернуть ссылку на элемент в коллекции.
template <typename T, typename K>
K& GetRefStrict(map<T, K>& dict, T key){
    if (dict.count(key) == 0) {
        throw runtime_error("smth happend");
    }
    else {
        return dict[key];
    }
}

int main()
{
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
}