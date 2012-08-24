#include <cstdio>

using namespace std;

int main(){
    int N;
    
    scanf("%d",&N);
    
    char c[N];
    
    for(int i = 0;i < N;++i)
        scanf(" %c",&c[i]);
    
    for(int i = 0,l = 0,r = N - 1,cont = 1;i < N;++i,++cont){
        if(c[l] != c[r]){
            if(c[l] < c[r]) putchar(c[l++]);
            else putchar(c[r--]);
        }else{
            int contl = 0,contr = 0;
            int l2 = l,r2 = r;
            
            while(l2 < r2 && c[l2] == c[r2]) ++l2,--r2;
            
            if(c[l2] < c[r2]) putchar(c[l++]);
            else putchar(c[r--]);
        }
        
        if(cont == 80 || i == N - 1){
            putchar('\n');
            cont = 0;
        }
    }
    
    return 0;
}
