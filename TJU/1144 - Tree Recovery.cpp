#include <string>
#include <iostream>

using namespace std;

string s1;
string s2;

string f(int n, int m, int p, int q){
    
    int a=s2.find(s1[n]);
    int b=-1;//b seguira valiendo -1 si no hay rama izquierda
    
    string ax="";
    
    if(a!=p){
        b=n;
        while(b<=m && s2.find(s1[b+1])<a) b++;
        if(b!=n) ax+=f(n+1,b,p,a-1);
    }
    
    if(a!=q){
        if(b!=-1) ax+=f(b+1,m,a+1,q);
        else ax+=f(n+1,m,a+1,q);
    }
    
    ax+=s1[n];
    
    return ax;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    while(cin>>s1>>s2){
        cout<<f(0,s1.size()-1,0,s1.size()-1)<<endl;
    }

    return 0;
}
