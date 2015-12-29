#include <string>

using namespace std;

namespace Vergeten {

typedef int (*command_fn_t)(int,const char**);

void register_command(vector<string> names,command_fn_t func);

}; //namespace
