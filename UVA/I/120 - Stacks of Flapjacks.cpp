#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int stack[30];
    int n,aux,max,ind;
    
    string s;
    
    while(getline(cin,s)){
        n=0;
        
        istringstream is(s);
        
        cout<<s<<endl;
        
        while(is>>aux) stack[n++]=aux;
        
        for(int i=n-1;i>=0;i--){
            
            max=-1;
            
            for(int j=0;j<=i;j++)
                if(max<=stack[j]){
                    max=stack[j];
                    ind=j;
                }
            
            if(ind != i){
                if(ind != 0){
                    cout<<n-ind<<" ";
                    
                    for(int j=0;j<=ind/2;j++) swap(stack[j],stack[ind-j]);
                }
                
                cout<<n-i<<" ";
                
                for(int j=0;j<=i/2;j++) swap(stack[j],stack[i-j]);
            }
        }
        
        cout<<0<<endl;
    }
    
    return 0;
}
