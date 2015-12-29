#include <iostream>
#include "../base.h"

using namespace Vergeten;

void test_init(void){
	register_command({"test"}, {"(no args)", "Test Vergeten."}, [] (int, const char**) -> int {
		cerr << "kaas!" << endl;
		return 0;
	});
}
