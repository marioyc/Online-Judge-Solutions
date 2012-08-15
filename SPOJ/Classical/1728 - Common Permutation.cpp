#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    int L1,L2;
    char s1[1001],s2[1001];
    int cont1[26],cont2[26];
    
    while(cin >> s1 >> s2){
        L1 = strlen(s1);
        L2 = strlen(s2);
        
        memset(cont1,0,sizeof cont1);
        memset(cont2,0,sizeof cont2);
        
        for(int i = 0;i < L1;++i) ++cont1[ s1[i] - 'a' ];
        for(int i = 0;i < L2;++i) ++cont2[ s2[i] - 'a' ];
        
        for(int i = 0;i < 26;++i)
            for(int j = min(cont1[i],cont2[i]);j >= 1;--j)
                cout << (char)('a' + i);
        
        cout << '\n';
    }
    
    return 0;
}
