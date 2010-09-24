#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int mcd(int a, int b){
    while(a%b!=0){
        a%=b;
        swap(a,b);
    }
    
    return b;
}

int main(){    
    int n,m;
    
    scanf("%d %d",&n,&m);
    long long cont=(long long)(n+1)*(m+1)+mcd(n,m)+1;
    cont/=2;
    
    printf("%lld\n",cont);
    
    return 0;
}
