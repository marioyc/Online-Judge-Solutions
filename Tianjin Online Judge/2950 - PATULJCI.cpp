#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int numbers[9];
    int total;
    
    total=0;
    for(int i=0;i<9;i++){
        cin>>numbers[i];
        total+=numbers[i];
    }
    
    for(int i=0;i<8;i++)
        for(int j=i+1;j<9;j++)
            if(total-numbers[i]-numbers[j]==100){
                for(int k=0;k<9;k++)
                    if(k!=i && k!=j) cout<<numbers[k]<<endl;
            }
    
    return 0;
}
