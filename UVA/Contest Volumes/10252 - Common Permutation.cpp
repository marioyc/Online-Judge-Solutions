#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string a,b;
    int contA[26],contB[26];
    
    while(getline(cin,a) && getline(cin,b)){
        int L1 = a.size(),L2 = b.size();
        
        memset(contA,0,sizeof(contA));
        memset(contB,0,sizeof(contB));
        
        for(int i = 0;i < L1;++i) ++contA[a[i] - 'a'];
        for(int i = 0;i < L2;++i) ++contB[b[i] - 'a'];
        
        for(int i = 0;i < 26;++i)
            for(int j = min(contA[i],contB[i])-1;j >= 0;--j)
                putchar('a' + i);
        
        putchar('\n');
    }
    
    return 0;
}
