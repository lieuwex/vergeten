#include <iostream>
#include <stdexcept>
#include <glob.h>
#include "utils.h"

using namespace std;

namespace Vergeten {

vector<string> expand_glob(string path) {
	glob_t pglob;
	const int code = glob(path.c_str(), 0, nullptr, &pglob);
	if (code > 0) {
		throw logic_error("glob returned an error.");
	}

	vector<string> res;
	res.reserve(pglob.gl_pathc);
	for (size_t i = 0; i < pglob.gl_pathc; i++) {
		res.push_back(pglob.gl_pathv[i]);
	}
	globfree(&pglob);
	return res;
}

vector<string> expand_glob(vector<string> globs) {
	glob_t pglob;
	for(size_t i=0;i<globs.size();i++){
		const int code = glob(globs[i].c_str(), i > 0 ? GLOB_APPEND : 0, nullptr, &pglob);
		if (code > 0) {
			throw logic_error("glob returned error.");
		}
	}

	vector<string> res;
	res.reserve(pglob.gl_pathc);
	for (int i = 0; i < (int)pglob.gl_pathc; i++) {
		res.push_back(pglob.gl_pathv[i]);
	}
	globfree(&pglob);
	return res;
}

}
