#pragma once

#include <string>
#include <vector>
#include "utils.h"

using namespace std;

namespace Vergeten {

typedef int (*command_fn_t)(int,const char**);

struct Docitem{
	string args,desc;
};

void register_command(vector<string> names,Docitem docitem,command_fn_t func);

}; //namespace
