#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int B = 10000000;
int ans[5000],pow3[5000];

void add(int *a, int &la, int *b, int &lb){
    string ret;
    
    for(int i = 0,c = 0;i < la || i < lb || c;++i){
        if(i < la) c += a[i];
        if(i < lb) c += b[i];
        
        if(i < la) a[i] = c % B;
        else a[la++] += c % B;
        
        c /= B;
    }
}

void mult(int *a, int &la, int b){
    for(int i = 0,c = 0;i < la || c;++i){
        if(i < la){
            c += a[i] * b;
            a[i] = c % B;
        }else a[la++] += c % B;
        
        c /= B;
    }
}

int main(){
    char op[10001];
    scanf("%s",op);
    int L = strlen(op);
    
    memset(pow3,0,sizeof pow3);
    memset(ans,0,sizeof ans);
    pow3[0] = 1;
    ans[0] = 1;
    int Lp3 = 1,Lans = 1;
    
    for(int i = 0;i < L;++i){
        if(op[i] == 'L') mult(ans, Lans, 2);
        else if(op[i] == 'R'){
            mult(ans, Lans, 2);
            add(ans, Lans, pow3, Lp3);
        }else if(op[i] == '*'){
            mult(ans, Lans, 5);
            add(ans, Lans, pow3, Lp3);
            mult(pow3, Lp3 , 3);
        }
    }
    
    for(int i = Lans - 1;i >= 0;--i){
        if(i == Lans - 1) printf("%d",ans[i]);
        else printf("%07d",ans[i]);
    }
    putchar('\n');
    
    return 0;
}
