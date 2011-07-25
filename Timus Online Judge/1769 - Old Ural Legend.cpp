#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int main(){
    char s[100001];
    
    scanf("%s",s);
    
    int L = strlen(s);
    set<int> S;
    
    for(int d = 1;d <= 6;++d){
        for(int i = 0;i+d-1 < L;++i){
            int aux = 0;
            
            for(int j = 0;j < d;++j)
                aux = aux * 10 + s[i+j] - '0';
            
            S.insert(aux);
        }
    }
    
    for(int i = 1;i <= 999999;++i){
        if(S.find(i) == S.end()){
            printf("%d\n",i);
            break;
        }
    }
    
    return 0;
}
