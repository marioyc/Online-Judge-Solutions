#include<iostream>
#include<string>

using namespace std;

long long f(int a, int b){
    long long x=1;
    
    for(int i=b+1;i<=a;i++) x*=i;
    
    return x;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s;
    int n,cont;
    long long pos;
    
    while(1){
        cin>>n;
        if(n==0) break;
        
        cin>>s;
        
        pos=0;
        
        for(int i=0;i<s.size();i++){
            cont=s[i]-'A';
            for(int j=0;j<i;j++) if(s[j]<s[i]) cont--;
            
            pos+=cont*f(25-i,26-n);
        }
        
        cout<<pos<<endl;
    }
    
    return 0;
}
