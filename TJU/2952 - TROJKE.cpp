#include<iostream>
#include<string>

using namespace std;

int main(){
    int N,cont1,cont2;
    int pos[26][2];
    string s;
    
    cin>>N;
    
    cont1=0;
    
    for(int i=0;i<N;i++){
        cin>>s;
        
        for(int j=0;j<N;j++)
            if(s[j]!='.'){
                pos[cont1][0]=i;
                pos[cont1][1]=j;
                cont1++;
            }
    }
    
    cont2=0;
    
    for(int i=0;i<cont1;i++)
        for(int j=i+1;j<cont1;j++)
            for(int k=j+1;k<cont1;k++)
                if((pos[i][0]-pos[j][0])*(pos[k][1]-pos[j][1])+(pos[i][1]-pos[j][1])*(pos[j][0]-pos[k][0])==0) cont2++;
    
    cout<<cont2<<endl;
        
    return 0;
}
