#include "iostream"
#include "vector"

using namespace std;

// Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить в конец и уходить оттуда. 
//Более того, иногда некоторые люди могут прекращать и начинать беспокоиться из-за того, что очередь не продвигается.
// 
// Реализуйте обработку следующих операций над очередью:
// 
// WORRY i: пометить i-го человека с начала очереди (в нумерации с 0) как беспокоящегося;
// QUIET i: пометить i-го человека как успокоившегося;
// COME k: добавить k спокойных человек в конец очереди;
// COME -k: убрать k человек из конца очереди;
// WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
// Изначально очередь пуста.

int main (){
    int n;
    cin >> n;
    vector<bool> quie;
    for (int i = 0; i < n; i++){
        string command;
        cin >> command;
        int k = 0;
        if (command == "WORRY"){
            cin >> k;
            quie[k] = true;
        }
        else if (command == "QUIET"){
            cin >> k;
            quie[k] = false;
        }
        else if (command == "COME"){
            cin >> k;
            quie.resize(quie.size()+k, false);
        }
        else if(command == "WORRY_COUNT"){
            int res = 0;
            for (bool p : quie){
                if (p) res++;
            }
            cout << res << endl;
        }
    }
    return 0;
}