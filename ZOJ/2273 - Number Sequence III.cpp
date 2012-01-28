#include <cstdio>

using namespace std;

int solve(int p, int n){
    if(n == 1) return 1;
    
    if(p == 0) return 2 * solve(1,n - n / 2) - 1;
    return 2 * solve(0,n - (n + 1) / 2);
}

int dig(int n){
    int ret = 0;
    
    for(int d = 1,last = 0,e = 9;n > last;d++,last = last * 10 + 9,e = e * 10 + 9){
        if(n <= e) ret += (n - last) * d;
        else ret += (e - last) * d;
    }
    
    return ret;
}

char s[488890];
int pos = 0;

int main(){
    for(int d = 1,last = 0,e = 9;d <= 5;d++,last = last * 10 + 9,e = e * 10 + 9){
        for(int i = last + 1;i <= e;++i){
            sprintf(s + pos,"%d",i);
            pos += d;
        }
    }
    
    s[pos] = 0;
    
    int n;
    
    while(scanf("%d",&n) == 1)
        printf("%c\n",s[solve(0,dig(n)) - 1]);
    
    return 0;
}
