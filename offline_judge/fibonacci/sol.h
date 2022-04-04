#include<bits/stdc++.h>
using namespace std;

int n,fib[10000];

inline void sol(){
	//type your solution here
	cin >>n;
	fib[1]=1;
	for(int i=2;i<=10000;++i)fib[i]=(fib[i-1]+fib[i-2])%100007;
	for(int i=0;i<n;++i){
		int x;
		cin >>x;
		cout<<fib[x]<<'\n';
	}
}
