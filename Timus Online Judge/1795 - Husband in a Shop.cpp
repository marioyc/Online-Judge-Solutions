#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct product{
    string name;
    int cont;
    
    bool operator < (product X)const{
        return name < X.name;
    }
}P[1000];

int m,n;

int getInd(string s){
    int lo = 0,hi = m - 1,mi;
    
    while(lo < hi){
        mi = (lo + hi + 1) >> 1;
        
        if(P[mi].name > s) hi = mi - 1;
        else lo = mi;
    }
    
    if(P[lo].name != s) return -1;
    return lo;
}

int main(){
    scanf("%d",&m);
    
    char s[21];
    
    for(int i = 0;i < m;++i){
        scanf("%d of %s\n",&P[i].cont,s);
        P[i].name = string(s);
    }
    
    sort(P,P + m);
    
    scanf("%d",&n);
    
    int id[1000],want[1000],prev[1000];
    
    for(int i = 0;i < n;++i){
        scanf("%d of %s",&want[i],s);
        id[i] = getInd(string(s));
    }
    
    int head = 0,ans = 0;
    
    while(head != n){
        if(id[head] != -1){
            int &have = P[id[head]].cont;
            
            if(have > 0){
                if(want[head] > have){
                    if(head == n-1){
                        ++ans;
                        ++head;
                        break;
                    }
                    
                    swap(id[head],id[head + 1]);
                    swap(want[head],want[head + 1]);
                    
                    want[head + 1] = have;
                }else{
                    have -= want[head];
                    ++head;
                }
            }else ++head;
        }else ++head;
        
        ++ans;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
