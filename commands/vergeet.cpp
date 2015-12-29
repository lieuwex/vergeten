#include <iostream>
#include "../base.h"

using namespace std;
using namespace Vergeten;

void vergeet_init(void) {
	register_command({"vergeet"}, {"<file paths..>", "Stages the given file(s)."}, [] (int argc, const char **argv) -> int {
		if (argc <= 1) {
			cerr << "command 'vergeet' requires one or more files as arguments." << endl;
			return 1;
		}

		auto res = expand_glob(string(argv[1]));
		for ( string x : res ) {
			cerr << x << endl;
		}

		return 0;
	});
}
