#include<iostream>

using namespace std;

int y=0;

int fun1(int n){
	if(n>0) return fun1(n-1)+n;
	return 0;
}

int fun2(int n){
	static int x=0;
	if(n>0) {
		x++;
		return fun2(n-1)+x;
	}
	return 0;
}

int fun3(int n){
	if(n>0){
		y++;
		return fun3(n-1)+y;
 	}
	return 0;
}

int main(){
	int a=5;
	cout<<fun1(a)<<endl;
	cout<<fun2(a)<<endl;
	cout<<fun3(a);
	return 0;
}
