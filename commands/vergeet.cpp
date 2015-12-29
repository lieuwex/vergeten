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

		vector<string> v = vector<string>(argv + 1, argv+argc);
		auto files = expand_glob(v);

		for (string file : files) {
			stash_file(file);
		}

		return 0;
	});
}
