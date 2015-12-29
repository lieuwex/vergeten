#include <string>

namespace Vergeten {

typedef int (*command_fn_t)(int argc,char **argv);

void register_command(string name,command_fn_t func);
void register_command(vector<string> names,command_fn_t func); //with aliases

}; //namespace
