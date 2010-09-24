#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,M,aux;
    
    cin>>N;
    
    string s1(1000000,' ');
    string s2(1000000,' ');
    
    
    for(int i=0;i<N;i++){
        cin>>M;
        
        string sum(M,' ');
        
        for(int j=0;j<M;j++) cin>>s1[j]>>s2[j];
        
        aux=0;
        
        for(int j=M-1;j>=0;j--){
            aux+=(s1[j]-'0')+(s2[j]-'0');
            
            sum[j]=aux%10+'0';
            
            aux/=10;
        }
        
        if(i!=0) cout<<endl;
        cout<<sum<<endl;
    }
}
