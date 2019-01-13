#include "iostream"
#include "string"
#include "map"
#include "vector"
#include "tuple"

using namespace std;

template<typename T>
T Sqr(T x);

template<typename T>
vector<T> Sqr(const vector<T>& lhs);

// Для словаря
template<typename T, typename K>
map<T, K> Sqr(const map<T, K>& lhs);

// Для пары
template<typename T, typename K>
pair<T, K> Sqr(const pair<T, K>& lhs);


template <typename T>
T Sqr(T x) { 
    return x*x;
}

template <typename T>
vector<T> Sqr(const vector<T>& lhs) { 
    vector<T> res;
    for (const T& i: lhs){
        res.push_back(Sqr(i));
    }
    return res;
}

template <typename T, typename K>
map<T, K> Sqr(const map<T, K>& lhs) { 
    int n = lhs.size();
    map<T, K> res;
    for (const auto& item : lhs){
        res[item.first] = Sqr(item.second);
    }
    return res;
}

template <typename T, typename K>
pair<T, K> Sqr(const pair<T, K>& lhs) { 
    return {Sqr(lhs.first), Sqr(lhs.second)};
}
 
int main()
{
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int> > map_of_pairs = {{4, {2, 2}},{7, {4, 3}}};
     cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
}