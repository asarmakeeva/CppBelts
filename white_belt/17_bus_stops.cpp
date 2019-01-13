#include "iostream"
#include "string"
#include "vector"
#include "map"

using namespace std;

int main (){
    int n;
    cin >> n;
    map<string, vector<string> > bus_stops;
    map<string, vector<string> > stops_bus;

    for (int i = 0; i < n; i++){
        string command;
        cin >> command;
        if (command == "NEW_BUS"){
            string bus;
            int stop_count;
            cin >> bus >> stop_count;
            for (int i = 0; i < stop_count; i++){
                string stop;
                cin >> stop;
                bus_stops[bus].push_back(stop);
                stops_bus[stop].push_back(bus);
            }   
        }
        else if (command == "BUSES_FOR_STOP"){
            string stop;
            cin >> stop;
            if (stops_bus.count(stop) == 0) cout << "No stop " << endl;
            else {
                for (auto item : stops_bus[stop]){
                    cout << item<< " ";
                }   
                cout << endl;
            }
        }
        else if (command == "STOPS_FOR_BUS"){
            string bus;
            cin >> bus;
            if (bus_stops.count(bus) == 0) cout << "No bus " << endl;
            else{    
                for (auto item : bus_stops[bus]){
                    cout << "Stop " << item << ": ";
                    if (stops_bus.count(item) == 0) cout << "no interchange";
                    for (auto stop : stops_bus[item]){
                        if ((bus == stop)&&(stops_bus[item].size() == 1))  cout << "no interchange";
                        else if (bus == stop) ;
                        else cout << stop << " ";
                    }
                    cout << endl;
                }
            }
        }
        else if (command == "ALL_BUSES"){
            if (bus_stops.size() == 0) cout << "No buses " << endl;
            for (auto item : bus_stops){
                cout << "Bus " << item.first << ": ";
                for (auto stops : item.second){
                    cout << stops << " ";
                }
                cout << endl;
            }
            
        }
       
    }
    return 0;
}