#include <cstdio>
#include <string>

using namespace std;

int f(char c){
    if(c=='m') return 1000;
    if(c=='c') return 100;
    if(c=='x') return 10;
    return 1;
}

int toNum(string &s){
    int aux=0;
    
    for(int i=0;i<s.size();i++){
        if(s[i]>='2' && s[i]<='9'){
            aux+=(s[i]-'0')*f(s[i+1]);
            i++;
        }else aux+=f(s[i]);
    }
    
    return aux;
}

string toString(int n){
    string s;
    
    if(n>=1000){
        if(n>=2000) s+=(char)('0'+n/1000);
        s+='m';
        n%=1000;
    }
    if(n>=100){
        if(n>=200) s+=(char)('0'+n/100);
        s+='c';
        n%=100;
    }
    if(n>=10){
        if(n>=20) s+=(char)('0'+n/10);
        s+='x';
        n%=10;
    }
    if(n>=1){
        if(n>=2) s+=(char)('0'+n);
        s+='i';
    }
    
    return s;
}

int main(){
    int T;
    char str[9];
    string s1,s2;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%s",str);
        s1=str;
        
        scanf("%s",str);
        s2=str;
        
        printf("%s\n",toString(toNum(s1)+toNum(s2)).c_str());
    }
    
    return 0;
}
