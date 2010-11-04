#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_DEN 10000

string getIntegerPart(int num, int base){
    if(num==0) return "0";
    string ret;
    
    while(num!=0){
        int aux = num%base;
        ret += (char)(aux<10? '0'+aux : 'A'+aux-10);
        num /= base;
    }
    
    reverse(ret.begin(),ret.end());
    return ret;
}

int used[MAX_DEN];

string getFractionalPart(int num, int den, int base){
    string ret;
    memset(used,-1,sizeof(used));
    
    for(int i = 0;num!=0 && used[num]==-1;++i){
        used[num] = i;
        num *= base;
        int aux = num/den;
        ret += (char)(aux<10? '0'+aux : 'A'+aux-10);
        num %= den;
    }
    
    if(num!=0){
        ret.insert(used[num],"(");
        ret += ')';
    }
    
    return ret;
}

string fractionRepresentation(int num, int den, int base){
    string ret = getIntegerPart(num/den,base);
    num %= den;
    
    if(num!=0) ret += "." + getFractionalPart(num,den,base);
    return ret;
}

int main(){
    int a,b,k;
    
    while(scanf("%d %d %d",&a,&b,&k)==3)
        printf("%s\n",fractionRepresentation(a,b,k).c_str());
    
    return 0;
}
