#include "iostream"
#include "string"
#include "set"
#include "map"

using namespace std;

int main (){
    int n;
    cin >> n;
    map<set<string>,int> bus_stops;
    int num = 1;
    for (int i = 0; i < n; i++){
        int num_stops;
        cin >> num_stops;
        set<string> buf;
        for (int j = 0; j < num_stops; j++){
            string stop;
            cin >> stop;
            buf.insert(stop);
        }
        if (bus_stops.count(buf) == 1) cout << "Already exists for " << bus_stops[buf] << endl;
        else {
            bus_stops[buf] = num;
            cout << "New bus " << bus_stops[buf] << endl;
            num++;
        }
    }
    return 0;
}