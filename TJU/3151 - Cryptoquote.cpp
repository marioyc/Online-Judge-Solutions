#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string encoded,map;
    int N,n;
    int a[26];    
    
    scanf("%d\n",&N);
    
    for(int i=1;i<=N;i++){
        getline(cin,encoded);
        getline(cin,map);
        
        for(int j=0;j<26;j++) a[j]=map[j]-'A';
        
        n=encoded.size();
        
        cout<<i<<" ";
        
        for(int j=0;j<n;j++)
            if(isupper(encoded[j])) cout<<(char)(a[encoded[j]-'A']+'A');
            else cout<<encoded[j];
        
        cout<<endl;
    }
    
    return 0;
}
