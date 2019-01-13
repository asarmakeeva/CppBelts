#include "iostream"
#include "string"

using namespace std;

int main(){
    string word;
    cin >> word;
    int index = 0;
    int res = -2; 
    for (auto i : word){
        index ++;
        if ((i == 'f') && (res == -2)) res = -1;
        else if ((i == 'f') && (res == -1)) res = index-1;
    }
    cout << res << endl;
    return 0;
}