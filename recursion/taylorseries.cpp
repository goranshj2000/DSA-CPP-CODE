//taylore series recursion e^x

#include<iostream>

using namespace std;

float factorial(float n){
	if(n>0) return factorial(n-1)*n;
	return 1;
}

float exponent(float n, float y){
	
	if(y>0) return exponent(n,y-1)*n;
	return 1;
		
}

float taylor(float x, float n){
	
	if(n>0){
	float b;
	b=exponent(x,n)/factorial(n);
	cout<<b<<endl;
	return taylor(x,n-1)+b;
	}
	return 1;
}

int main(){
	float a=3,b=4;
	float c;
	c=taylor(a,b);
	cout<<c;
}
