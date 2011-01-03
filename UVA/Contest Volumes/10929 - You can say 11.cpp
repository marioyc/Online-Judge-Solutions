#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    char num[1001];
    
    int sum;
    
    while(1){
        cin>>num;
        
        if(num[0]=='0' && strlen(num)==1) break;
        
        sum=0;
        
        for(int i=0;i<strlen(num);i+=2) sum+=num[i]-'0';
        for(int i=1;i<strlen(num);i+=2) sum-=num[i]-'0';
        
        if(sum%11==0) cout<<num<<" is a multiple of 11."<<endl;
        else cout<<num<<" is not a multiple of 11."<<endl;
    }
}
