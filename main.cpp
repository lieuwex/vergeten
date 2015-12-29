#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "base.h"

using namespace std;

namespace Vergeten {

vector<command_fn_t> commandfuncs;
unordered_map<string,int> aliasidcs;
unordered_map<string,Docitem> commanddocs;

void register_command(vector<string> names,Docitem docitem,command_fn_t func){
	const int idx=commandfuncs.size();
	commandfuncs.push_back(func);
	for(const string name : names){
		aliasidcs[name]=idx;
		commanddocs.insert(make_pair(name,docitem));
	}
}


}

using namespace Vergeten;

#define Xi(name) void name##_init(void);
#define X(name) Xi(name)
COMMANDS_XLIST
#undef Xi
#undef X


void print_usage(int,const char**){
	cerr<<"Vergeten -- a version control program"<<endl<<endl;
	cerr<<"Subcommands:"<<endl;
	for(const pair<string,Docitem> p : commanddocs){
		cerr<<"  "<<p.first<<": "<<p.second.args<<" -- "<<p.second.desc<<endl;
	}
}

int main(int argc,const char **argv) {
#define Xi(name) name##_init();
#define X(name) Xi(name)
	COMMANDS_XLIST
#undef Xi
#undef X
	if(argc<2){
		print_usage(argc,argv);
		return 1;
	}
	const char *subcommand=argv[1];
	auto it=aliasidcs.find(subcommand);
	if(it==aliasidcs.end()){
		cerr<<"Subcommand "<<subcommand<<" not found."<<endl;
		print_usage(argc,argv);
		return 1;
	}
	return commandfuncs[it->second](argc-1,argv+1);
}
