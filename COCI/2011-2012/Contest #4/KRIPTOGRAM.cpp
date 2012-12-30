#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#define MAXLEN 1000000

string VT[MAXLEN],VP[MAXLEN];
int T[MAXLEN],P[MAXLEN];
int lp = 0,lt = 0;

map<string,int> id;

int prevt[MAXLEN],prevp[MAXLEN];
int last[MAXLEN];
int f[MAXLEN];

bool checkp(int pos, int pos2){
    int aux = prevp[pos];
    if(aux != -1 && aux < pos - pos2) aux = -1;
    
    if(prevp[pos2] == -1 && aux != -1) return false;
    if(prevp[pos2] != -1 && (aux == -1 || pos - aux != pos2 - prevp[pos2])) return false;
    return true;
}

bool checkt(int pos, int pos2){
    int aux = prevt[pos];
    if(aux != -1 && aux < pos - pos2) aux = -1;
    
    if(prevp[pos2] == -1 && aux != -1) return false;
    if(prevp[pos2] != -1 && (aux == -1 || pos - aux != pos2 - prevp[pos2])) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    
    while(cin >> VT[lt]){
        if(VT[lt] == "$") break;
        ++lt;
    }
    
    for(int i = 0,cont = 0;i < lt;++i){
        if(id.find(VT[i]) == id.end()) id[ VT[i] ] = cont++;
        T[i] = id[ VT[i] ];
    }
    
    while(cin >> VP[lp]){
        if(VP[lp] == "$") break;
        ++lp;
    }
    
    id.clear();
    
    for(int i = 0,cont = 0;i < lp;++i){
        if(id.find(VP[i]) == id.end()) id[ VP[i] ] = cont++;
        P[i] = id[ VP[i] ];
    }
    
    memset(last,-1,sizeof last);
    
    for(int i = 0;i < lt;++i){
        prevt[i] = last[ T[i] ];
        last[ T[i] ] = i;
    }
    
    memset(last,-1,sizeof last);
    
    for(int i = 0;i < lp;++i){
        prevp[i] = last[ P[i] ];
        last[ P[i] ] = i;
    }
    
    f[0] = 0;
    
    for(int i = 1,k = 0;i < lp;++i){
        while(k > 0 && !checkp(i,k))
            k = f[k - 1];
        
        if(checkp(i,k)) ++k;
        
        f[i] = k;
    }
    
    for(int i = 0,k = 0;i < lt;++i){
        while(k > 0 && !checkt(i,k))
            k = f[k - 1];
        
        if(checkt(i,k)) ++k;
        
        if(k == lp){
            cout << i + 2 - lp << '\n';
            break;
        }
    }
    
    return 0;
}
