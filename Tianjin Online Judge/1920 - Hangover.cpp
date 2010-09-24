#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n;
    double sum,tot;
    
    while(1){
        cin>>tot;
        if(tot==0.00) break;
        
        n=2;
        sum=0.00;
        
        while(sum<tot){
            sum+=1.0/n;
            n++;
        }
        cout<<n-2<<" card(s)"<<endl;
    }

    return 0;
}
