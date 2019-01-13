#include "iostream"
#include "vector"

using namespace std;

// Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней. Найдите номера дней (в нумерации с нуля) 
// со значением температуры выше среднего арифметического за все N дней.

// Гарантируется, что среднее арифметическое значений температуры является целым числом.

int main (){
    int num_days;
    int64_t sum = 0;
    
    cin >> num_days;
    vector<int> days(num_days);
    for (int& i : days){
        cin >> i;
        sum += i;
    } 
    vector<int> res;
    for (int i = 0; i < num_days; i++){
        if (days[i] > sum/num_days) res.push_back(i);
    }
    cout << res.size() << endl;
    for (int i : res){
        cout << i << " ";
    }
    return 0;
}