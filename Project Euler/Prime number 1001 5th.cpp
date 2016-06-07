#include <stdio.h>
#include <math.h>
#include<iostream>
using namespace std;


int isPrime(int num){
  int i;

  if (num==2)
    return 1;

  for (i=2;i<sqrt(num)+1;i++){
    if (num%i==0)
      return 0;
    } 

  return 1;
}

int main(){
  int i,counter,ans;
  int sum=0;
  counter=0;

  for (i=2;i<2000000;i++){
    if (isPrime(i)==1){
      counter++;
     sum=sum+i;      
    }
    if (counter==2000000){
      break;
    }
  }
cout<<sum;
  return 0;
}
