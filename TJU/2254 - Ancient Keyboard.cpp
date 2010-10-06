#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,n,a,b,cont[1000];
    char ch;
    
    cin>>T;
    
    while(T--){
        cin>>n;
        
        memset(cont,0,sizeof(cont));
        
        for(int i = 0;i<n;++i){
            cin>>ch>>a>>b;
            for(int j = a;j<b;++j) ++cont[j];
        }
        
        for(int i = 0;i<1000;++i)
            if(cont[i]>0) printf("%c",'A'+cont[i]-1);
        
        printf("\n");
    }
    
    return 0;
}
