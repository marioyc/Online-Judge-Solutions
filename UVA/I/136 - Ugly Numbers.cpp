#include<iostream>

using namespace std;

int main(){
    freopen("out.txt","w",stdout);

    printf("The 1500'th ugly number is %d.\n",859963392);

    return 0;
}

/*

#include <iostream>

using namespace std;

bool simp(int a)
{
    while(a%2==0) a>>=1;
    while(a%3==0) a/=3;
    while(a%5==0) a/=5;
    
    return a==1;
}

int main(){

    int cont=1;
    
    for(int i=2;;i++){        
        if(simp(i)) cont++;                
        if(cont==1500) break;        
    }
    
    cout<<i<<endl;
    
    return 0;
}


*/
