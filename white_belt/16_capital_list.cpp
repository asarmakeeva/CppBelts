#include "iostream"
#include "string"
#include "map"

using namespace std;

// Реализуйте справочник столиц стран.

// На вход программе поступают следующие запросы:

// CHANGE_CAPITAL country new_capital — изменение столицы страны country на new_capital, либо добавление такой страны с 
// такой столицей, если раньше её не было.
// RENAME old_country_name new_country_name — переименование страны из old_country_name в new_country_name.
// ABOUT country — вывод столицы страны country.
// DUMP — вывод столиц всех стран.

int main(){
    int n;
    cin >> n;
    map<string, string>  capital_list;

    for (int i = 0; i < n; i++){
        string command;
        cin >> command;
        if (command == "CHANGE_CAPITAL"){
            string country,new_capital;
            cin >> country >> new_capital;
            if (capital_list.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
                capital_list[country] = new_capital;
            }
            else if (capital_list[country] == new_capital){
                cout << "Country " << country << " hasn't changed its capital" << endl;
            }
            else {
                cout << "Country " << country << " has changed its capital from " << capital_list[country];
                capital_list.erase(country);
                capital_list[country] = new_capital;
                cout << " to " <<new_capital << endl;
            }    
        }
        else if (command == "RENAME"){
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if ((old_country_name == new_country_name) || (capital_list.count(old_country_name) == 0) 
                || (capital_list.count(new_country_name) == 1)) {
                cout << "Incorrect rename, skip" << endl;
                }
            else {
                capital_list[new_country_name] = capital_list[old_country_name];
                capital_list.erase(old_country_name);
                cout << "Country " << old_country_name << " with capital " <<
                 capital_list[new_country_name] << " has been renamed to " << new_country_name << endl;
            }
        }
        else if (command == "ABOUT"){
            string country;
            cin >> country;
            if (capital_list.count(country) == 0) 
                cout << "Country " << country << " doesn't exist"<< endl;
            else cout << "Country " << country << " has capital " << capital_list[country] << endl;
        }
        else if (command == "DUMP"){
            if (sizeof(capital_list) == 0) {
                cout << "There are no countries in the world" << endl;
            }
            else {
            for (auto item : capital_list){
                cout << item.first << "/"<< item.second << " ";
                }
                cout << endl;
            }
            
        }
       
    }
    return 0;
}
