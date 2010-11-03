#include <iostream>
#include <string>
#include <map>

using namespace std;

string s[6],res[3];

bool test(char c, int w, int n){
    int wl = 0,wr = 0,L = s[2*n].size();
        
    for(int i=0;i<L;++i) if(s[2*n][i]==c) wl += w;
    for(int i=0;i<L;++i) if(s[2*n+1][i]==c) wr += w;
    
    if(wr>wl && res[n][0]=='d') return true;
    if(wr<wl && res[n][0]=='u') return true;
    if(wr==wl && res[n][0]=='e') return true;
    return false;
}

pair<char, int> getCounterfeit(){
    for(char c='A';c<='L';++c){
        for(int w=-1;w<=1;w+=2){
            if(!test(c,w,0) || !test(c,w,1) || !test(c,w,2)) continue;
            return make_pair(c,w);
        }
    }
}

int main(){
    int n;
    cin>>n;
    
    for(int tc=1;tc<=n;++tc){
        for(int i=0;i<3;++i) cin>>s[2*i]>>s[2*i+1]>>res[i];
        
        pair<char, int> P = getCounterfeit();
        char coin = P.first;
        int w = P.second;
        
        cout<<P.first<<" is the counterfeit coin and it is ";
        
        if(P.second==1) cout<<"heavy."<<endl;
        else cout<<"light."<<endl;
    }
    
    return  0;
}
