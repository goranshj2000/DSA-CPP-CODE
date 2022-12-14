//nCr using recursion

#include<iostream>

using namespace std;

float factorial(float n){
	if(n>0) return factorial(n-1)*n;
	return 1;
}

float ncr1(float n, float r){
    int b=factorial(n)/(factorial(n-r)*factorial(r));
    return b;
}

float ncr2(float n, float r){
    if(r==0||n==r) return 1;
    else return ncr2(n-1,r-1)+ncr2(n-1,r);
}

int main(){
    cout<<ncr1(5,4)<<" "<<ncr2(5,4);
    return 0;
}