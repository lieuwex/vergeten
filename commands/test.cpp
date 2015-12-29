#include "../base.h"
using namespace Vergeten;

void test_init(void){
	register_command({"test"}, [] (int argc, char **argv) -> int {
		cerr << "kaas!" << endl;
	});
}
