#include <iostream>
#include "../base.h"

using namespace Vergeten;

void test_init(void){
	register_command({"test"}, [] (int, const char**) -> int {
		cerr << "kaas!" << endl;
		return 0;
	});
}
