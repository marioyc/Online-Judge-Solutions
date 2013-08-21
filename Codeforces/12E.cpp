#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    int M[n][n];
    
    for(int i = 0;i < n - 1;++i)
        for(int j = 0;j < n - 1;++j)
            M[i][j] = 1 + (i + j) % (n - 1);
    
    for(int i = 0;i < n - 1;++i)
        M[i][n - 1] = M[n - 1][i] = M[i][i];
    
    for(int i = 0;i < n;++i)
        M[i][i] = 0;
    
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j) cout << M[i][j] << ' ';
        cout << '\n';
    }
    
    return 0;
}
