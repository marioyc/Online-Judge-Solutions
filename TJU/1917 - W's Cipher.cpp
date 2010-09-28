#include<iostream>
#include<string>

using namespace std;

int main(){    
    int k1,k2,k3,cont;
    int pos1[80];
    int pos2[80];
    string s;
    
    while(1){
        cin>>k1>>k2>>k3;
        if(k1==0 && k2==0 && k3==0) break;
        
        cin>>s;
        
        string decoded(s.size(),' ');
        
        cont=0;        
        for(int i=0;i<s.size();i++)
            if(s[i]>='a' && s[i]<='i')
                pos1[cont++]=i;
        
        if(cont!=0){
            for(int i=0;i<cont;i++) pos2[(i+k1)%cont]=pos1[i];
            
            for(int i=0;i<cont;i++) decoded[pos1[i]]=s[pos2[i]];
        }
        
        cont=0;
        for(int i=0;i<s.size();i++)
            if(s[i]>='j' && s[i]<='r')
                pos1[cont++]=i;
        
        if(cont!=0){
            for(int i=0;i<cont;i++) pos2[(i+k2)%cont]=pos1[i];
            
            for(int i=0;i<cont;i++) decoded[pos1[i]]=s[pos2[i]];
        }
        
        cont=0;
        for(int i=0;i<s.size();i++)
            if((s[i]>='s' && s[i]<='z') || s[i]=='_')
                pos1[cont++]=i;
        
        if(cont!=0){
            for(int i=0;i<cont;i++) pos2[(i+k3)%cont]=pos1[i];
            
            for(int i=0;i<cont;i++) decoded[pos1[i]]=s[pos2[i]];
        }
        
        cout<<decoded<<endl;
    }
    
    return 0;
}
