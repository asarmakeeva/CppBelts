#include "iostream"
#include "vector"

using namespace std;

//На вход дано целое положительное число N. Выведите его в двоичной системе счисления без ведущих нулей.

int main(){
    int num;
    cin >> num;
    vector<int> bin_num;
    while (num > 0){
        if ((num%2) == 0) bin_num.push_back(0);
        else bin_num.push_back(1);
        num/=2;
    }
    for (int i = bin_num.size()-1; i >= 0; i--){
        cout << bin_num[i];
    }
    cout << endl;
    return 0;
}