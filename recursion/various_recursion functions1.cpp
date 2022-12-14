//sum of n natural numbers using recursion

#include<iostream>

using namespace std;

int sum(int n){
	if(n>0)
	return sum(n-1)+n;
	return 0;
	
}

int factorial(int n){
	if(n>1) return factorial(n-1)*n;
}

int exponent(int n, int y){
	
	if(y>0) return exponent(n,y-1)*n;
	return 1;
			
}


int main(){
	
	cout<<"enter number";
	int a;
	cin>>a;
	cout<<"\nthe sum is"<<sum(a);
	cout<<"\nthe factorial is"<<factorial(a);
	cout<<"\nwhat exponent of the given number?";
	int b;
	cin>>b;
	printf("\n%d to the power%d is %d",a,b,exponent(a,b));
	return 0;
}
