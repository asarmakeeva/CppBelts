#include "iostream"
#include "vector"
#include "string"

using namespace std;

// У каждого из нас есть ежемесячные дела, каждое из которых нужно выполнять в конкретный день каждого месяца: 
// оплата счетов за электричество, абонентская плата за связь и пр. Вам нужно реализовать работу со списком таких дел, 
// а именно, обработку следующих операций:

// ADD i s
// Добавить дело с названием s в день i.

// NEXT
// Закончить текущий месяц и начать новый. Если новый месяц имеет больше дней, чем текущий, добавленные дни изначально 
// не будут содержать дел. Если же в новом месяце меньше дней, дела со всех удаляемых дней необходимо будет переместить 
// на последний день нового месяца.

// Обратите внимание, что количество команд этого типа может превышать 11.

// DUMP i
// Вывести все дела в день i.

// Изначально текущим месяцем считается январь. Количества дней в месяцах соответствуют Григорианскому календарю с той лишь
//  разницей, что в феврале всегда 28 дней.

int main (){
    int n;
    cin >> n;
    vector<int> days_in_month = {31,28,31,30,31,30,31,31,30,31,30,31};
    int month = 0;
    vector<vector<string> > month_deals(days_in_month[month]);

    for (int i = 0; i < n; i++){
        
        string command;
        cin >> command;
        
        if (command == "ADD"){
            int day = 0;
            string deal;
            cin >> day >> deal;
            //cout << day << "chech it check" << deal <<endl;
            day--;
            month_deals[day].push_back(deal);
        }
        else if (command == "NEXT"){
            int old_days_in_month = days_in_month[month];
            month ++;
            if (month%12 == 0) month = 0;

            int new_days_in_month = days_in_month[month];
            
            if (new_days_in_month < old_days_in_month){
                vector<string>& deals_in_month = month_deals[new_days_in_month-1];
                for(int j = new_days_in_month; j < old_days_in_month; j++){
                    deals_in_month.insert(end(deals_in_month), begin(month_deals[j]), end(month_deals[j]));
                }
            }
            month_deals.resize(new_days_in_month);
        }
        else if (command == "DUMP"){
            int day = 0;
            cin >> day;
            day--;
            cout << month_deals[day].size();
            for (string d : month_deals[day]){
                cout << " " << d;
            }
            cout << endl;
        }
    }
    return 0;
}