#include "iostream"
#include "string"
#include "set"
#include "map"

using namespace std;
// Два слова называются синонимами друг друга, если они имеют похожие значения. Реализуйте следующие операции над словарём
//  синонимов:

// ADD word1 word2 — добавить в словарь пару синонимов (word1, word2).
// COUNT word — узнать количество синонимов слова word.
// CHECK word1 word2 — проверить, являются ли слова word1 и word2 синонимами. Слова word1 и word2 считаются синонимами,
//  если среди запросов ADD был хотя бы один запрос ADD word1 word2 или ADD word2 word1.

// В ответ на запрос COUNT word выведите единственное целое число — количество синонимов слова word.
// В ответ на запрос CHECK word1 word2 выведите строку YES, если word1 и word2 являются синонимами, и NO в противном случае.


int main (){
    int n;
    cin >> n;
    map<string,set<string> > dict1;
 
    for (int i = 0; i < n; i++){
        string command;
        cin >> command;
        if (command == "ADD"){
            string word1, word2;
            cin >> word1 >> word2;
            dict1[word1].insert(word2);
            dict1[word2].insert(word1);
        }
        else if (command == "COUNT"){
            string word;
            cin >> word;
            cout << dict1[word].size() << endl;
        }
        else if (command == "CHECK"){
            string word1, word2;
            cin >> word1 >> word2;
            if (dict1[word1].count(word2) == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}