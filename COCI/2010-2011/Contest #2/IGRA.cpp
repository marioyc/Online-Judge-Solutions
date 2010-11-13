#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

struct letter{
    int pos;
    char c;
    
    letter(){}
    
    letter(int _pos, char _c){
        pos = _pos; c = _c;
    }
    
    bool operator < (letter X)const{
        if(c==X.c) return pos>X.pos;
        return c<X.c;
    }
};

int main(){
    int L;
    string s;
    
    cin>>L>>s;
    
    letter A[L];
    for(int i = 0;i<L;++i) A[i] = letter(i,s[i]);
    sort(A,A+L);
    
    string s1,s2;
    bool used[L];
    memset(used,false,sizeof(used));
    
    for(int i = 0,j = L-1,k = 0;i<L;++i){
        if(i%2==0){
            while(used[j]) --j;
            used[j] = true;
            s2 += s[j];
            --j;
        }else{
            while(used[A[k].pos]) ++k;
            used[A[k].pos] = true;
            s1 += s[A[k].pos];
            ++k;
        }
    }
    
    if(s1<s2) cout<<"DA"<<endl;
    else cout<<"NE"<<endl;
    cout<<s1<<endl;
    
    return 0;
}
