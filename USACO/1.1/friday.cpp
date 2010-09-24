/*
ID: zion_ba1
LANG: C++
TASK: friday
*/

#include <iostream>

using namespace std;

int main(){
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);

    int cont[]={0,0,0,0,0,0,0};
    int meses[]={31,0,31,30,31,30,31,31,30,31,30,31};
    int dia=5;
    int N;
    
    scanf("%d",&N);
    
    for(int i=1900;i<1900+N;i++){
        if(i%4==0){
            if(i%100==0){
                if(i%400==0) meses[1]=29;
                else meses[1]=28;
            }else meses[1]=29;
        }else meses[1]=28;
        
        for(int j=0;j<12;j++){
            cont[dia]++;
            dia=(dia+meses[j])%7;
        }
    }
    
    printf("%d %d %d %d %d %d %d\n",cont[5],cont[6],cont[0],cont[1],cont[2],cont[3],cont[4]);

    return 0;
}
