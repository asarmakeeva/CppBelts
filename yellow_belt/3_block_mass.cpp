#include "iostream"

using namespace std;


int main (){
    int n, rho;
    
    cin >> n >> rho;
    uint64_t res;
    uint64_t k,j,m;
    for (int i = 0; i < n; i++){
        cin >> k >> j >> m;
        res += k*j*m*rho;
    } 
    cout << res << endl;
    
    return 0;
}