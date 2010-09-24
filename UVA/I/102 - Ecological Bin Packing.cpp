#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    string config[]={"BGC","BCG","GBC","GCB","CBG","CGB"};
    string s;

    int B[3];
    int G[3];
    int C[3];
    long long costo,min;
    int sum_B,sum_G,sum_C,ax;

    while(scanf("%d %d %d %d %d %d %d %d %d",&B[0],&B[1],&B[2],&G[0],&G[1],&G[2],&C[0],&C[1],&C[2])==9){        
        int array[]={0,1,2};
        
        sum_B=B[0]+B[1]+B[2];
        sum_G=G[0]+G[1]+G[2];
        sum_C=C[0]+C[1]+C[2];
        
        ax=0;min=(1LL<<31);
        
        do{
            costo=sum_B-B[array[0]]+sum_G-G[array[1]]+sum_C-C[array[2]];
            
            if(costo<min || (costo==min && config[ax]<s)){
                s=config[ax];
                min=costo;
            }
            
            ax++;
        }while(next_permutation(array,array+3));
    
        cout<<s<<" "<<min<<endl;
    }

    return 0;
}
