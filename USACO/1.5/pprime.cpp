/*
ID:zion_ba1
LANG:C++
TASK:pprime
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool prime(int n){
    if(n==2) return true;
    if(n%2==0) return false;
    
    for(int i=3;i*i<=n;i+=2) if(n%i==0) return false;
    
    return true;
}

int A,B;
vector<int> ans;
int D[4];

int palindrome1(int d){
    int aux=0;
    
    for(int i=0;i<d;i++) aux=aux*10+D[i];
    for(int i=d-1;i>=0;i--) aux=aux*10+D[i];
    
    return aux;
}

int palindrome2(int d){
    int aux=0;
    
    for(int i=0;i<d-1;i++) aux=aux*10+D[i];
    aux=aux*10+D[d-1];
    for(int i=d-2;i>=0;i--) aux=aux*10+D[i];
    
    return aux;
}

void generate(int d){
    if(d>=1 && d<=3){
        int n=palindrome1(d);
        if(n>=A && n<=B && prime(n))
        ans.push_back(n);
    }
    
    if(d>=1 && d<=4){
        int n=palindrome2(d);
        if(n>=A && n<=B && prime(n))
        ans.push_back(n);
    }
    
    if(d==4) return;
    
    for(int i=0;i<10;i++){
        D[d]=i;
        generate(d+1);
    }
}

int main(){
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
    
    scanf("%d %d",&A,&B);
    
    for(int i=1;i<=9;i++){
        D[0]=i;
        generate(1);
    }
    
    sort(ans.rbegin(),ans.rend());
    
    for(int i=ans.size()-1;i>=0;i--) printf("%d\n",ans[i]);
    
    return 0;
}
