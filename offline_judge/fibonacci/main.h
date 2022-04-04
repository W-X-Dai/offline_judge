#include<bits/stdc++.h>
#include<conio.h>
#include "./sol.h"
#include "./kernal/terminal_color.h"
#include "./kernal/hash.h"
#include "./kernal/cmp.h"
using namespace std;

time_t begi,endt;
int _n,exe_time,time_limit;
bool AC;string log_path;
double totaltime;

//clock time of execution
std::string timeToString(std::chrono::system_clock::time_point &t){
    std::time_t time = std::chrono::system_clock::to_time_t(t);
    std::string time_str = std::ctime(&time);
    time_str.resize(time_str.size() - 1);
    return time_str;
}

inline void cmp(int num){
	//setting the path
	//s1:testdata s2:execute result
	string s1=".//testdatas//"+to_string(num)+".out";
	string s2=".//testdatas//"+to_string(num)+".tmp";
	
	bool Accept;
	
	ofstream fout(log_path,ios::app);
	
//	cerr<<_cmp_pre(s1,s2)<<'\n';
	Accept=_cmp_pre(s1,s2);cerr<<Accept;
	Accept=_cmp(s1,s2);
//	cerr<<Accept<<_cmp(s1,s2)<<'\n';
//	Accept=_cmp(s1,s2);
//	cerr<<"Accept"<<Accept;
	
	cerr<<"testcase #"<<num<<'\n';
	cerr<<"time:"<<(long double)(endt-begi)/CLOCKS_PER_SEC<<" ";
	totaltime+=(long double)(endt-begi)/CLOCKS_PER_SEC*1000;
	
	
	fout<<"testcase #"<<num<<'\n';
	fout<<(long double)(endt-begi)/CLOCKS_PER_SEC<<" ";
	
	if(Accept){
		if(time_limit>=(long double)(endt-begi)/CLOCKS_PER_SEC){
			cerr<<"Accept\n";
			fout<<"Accept\n";
		}
		else {
			cerr<<blue<<"Time Limit Exceed\n";
			fout<<blue<<"Time Limit Exceed\n";
			AC=0;
		}
	}else {
		AC=0;
		cerr<<red<<"Wrong Answer\n";
		fout<<red<<"Wrong Answer\n";
	}
}


inline void execute(int num){
	//setting the path of the testdatas
	char path_in[200],path_out[200];
	string tmp=".//testdatas//";
	tmp+=to_string(num);tmp+=".in";
	for(unsigned i=0;i<tmp.size();++i)path_in[i]=tmp[i];
	tmp=".//testdatas//";tmp+=to_string(num),tmp+=".tmp";
	for(unsigned i=0;i<tmp.size();++i)path_out[i]=tmp[i];
	
	//setting the log file
	ofstream fout(log_path,ios::app);
	
	freopen(path_in,"r",stdin);
	freopen(path_out,"w",stdout);
	
	//check if the path is correct
//	for(int i=0;path_in[i]!='\0';++i)cerr<<path_in[i];cerr<<'\n';
//	for(int i=0;path_out[i]!='\0';++i)cerr<<path_out[i];cerr<<'\n';
	
	begi=clock();
	sol();
	endt=clock();

	cmp(num);
//	cerr<<"time:"<<exe_time<<'\n';
}

inline void _exetime(){
	auto time_p=std::chrono::system_clock::now();
	ofstream f(log_path,ios::app);
	f<<"Execution time:"<<timeToString(time_p)<<'\n';
}

inline void _result(){
	ofstream f(log_path,ios::app);
	
	f<<"\nFinal result:";
	cerr<<"Final result:";
	
	if(AC){
		cerr<<"Accept\n";
		f<<"Accept\n";
		
		string hashcode;
		int _h=_rand();
		if(_h<10)hashcode+="0";
		if(_h<100)hashcode+="0";
			
		hashcode+=to_string(_h);
		hashcode+=to_string((long long)_hash(_n)*_hash(_h));
		cerr<<hashcode<<'\n';
		f<<"AC code:"<<hashcode<<'\n';
			
	}else {
		cerr<<"Wrong Answer\n";
		f<<"Wrong Answer\n";
	}
} 

int judge(){
	auto time_p=std::chrono::system_clock::now();
	ifstream f1(".//testdatas//log.txt",ios::in);
	string s;f1 >>s>>_n>>time_limit;
	AC=1;
	log_path="..//Execution_results//"+s+"_log.txt";
	
	
	ofstream f(log_path,ios::trunc);
	cerr<<"Execution time:"<<timeToString(time_p)<<'\n';
	_exetime();
	
	for(int i=0;i<_n;++i)execute(i);
	_result();
	while(1){
		if(_kbhit()){
			return 0;
		}
	}
}

