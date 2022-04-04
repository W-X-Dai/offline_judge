#include<bits/stdc++.h>
using namespace std;

inline _cmp_pre(string s1,string s2){
	ifstream f1(s1,ios::in),f2(s2,ios::in);
	f1.seekg(ios::beg),f2.seekg(ios::beg);
	
	if(!f1 || !f2){
		cerr<<"error\n";
		exit(1);
	}
	int i=0,AC=1;
	while(f1>>s1){
		f2>>s2;
		if(s1!=s2){
			return 0;
		}
		++i;
	}
	if(AC)return 1;	
	
	return 0;
}

inline int _cmp(string s1,string s2){
	ifstream f1(s1,ios::in),f2(s2,ios::in);
	f1.seekg(ios::beg),f2.seekg(ios::beg);
	
	if(!f1 || !f2){
		cerr<<"error\n";
		exit(1);
	}
	int i=0,AC=1;
	while(f1>>s1){
		f2>>s2;
		if(s1!=s2){
			cerr<<"WA Line:"<<i<<'\n';
			cerr<<s1<<" "<<s2<<'\n';
			AC=0;
			return 0;
		}
		++i;
	}
	if(AC)return 1;
	return 0;
}
