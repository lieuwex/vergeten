#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "base.h"

using namespace std;

namespace Vergeten {

vector<command_fn_t> commandfuncs;
unordered_map<string,int> aliasidcs;

void register_command(string name,command_fn_t func){
	aliasidcs[name]=commandfuncs.size();
	commandfuncs.push_back(func);
}
void register_command(vector<string> names,command_fn_t func){
	const int idx=commandfuncs.size();
	commandfuncs.push_back(func);
	for(const string name : names){
		aliasidcs[name]=idx;
	}
}


}

using namespace Vergeten;

#define Xi(name) void name##_init(void);
#define X(name) Xi(name)
COMMANDS_XLIST
#undef Xi
#undef X


int main(int argc,const char **argv) {
#define Xi(name) name##_init();
#define X(name) Xi(name)
	COMMANDS_XLIST
#undef Xi
#undef X
	const char *subcommand=argv[1];
	auto it=aliasidcs.find(subcommand);
	if(it==aliasidcs.end()){
		cerr<<"Subcommand "<<subcommand<<" not found."<<endl;
		return 1;
	}
	return commandfuncs[it->second](argc-1,argv+1);
}
