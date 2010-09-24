#include<iostream>

using namespace std;

void triangulo(int H){
   for(int i=0;i<H;i++){
        for(int j=0;j<H-1-i;j++) cout<<' ';
        for(int j=0;j<2*i+1 ;j++) cout<<'*';
        cout<<endl;
    } 
}

void paralelogramo(int W, int H){
    for(int i=H-1;i>=0;i--){
        for(int j=0;j<i;j++) cout<<' ';
        for(int j=0;j<W;j++) cout<<'*';
        cout<<endl;
    }
}

void rectangulo(int W, int H){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) cout<<'*';
        cout<<endl;
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int C,a,b;
    
    while(1){
        cin>>C;
        
        if(C==-1) break;
        else if(C==1){
            cin>>a;
            triangulo(a);
        }else if(C==2){
            cin>>a>>b;
            paralelogramo(a,b);
        }else{
            cin>>a>>b;
            rectangulo(a,b);
        }
        
        cout<<endl;
    }

    return 0;
}
