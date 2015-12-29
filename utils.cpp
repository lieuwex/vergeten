#include <glob.h>
#include <stdexcept>
#include "utils.h"

namespace Vergeten {

vector<string> expand_glob(string path) {
	glob_t pglob;
	int code = glob(path.c_str(), 0, nullptr, &pglob);
	if (code > 0) {
		throw logic_error("glob returned error.");
	}

	vector<string> res(pglob.gl_pathc);
	for (int i = 0; i < (int)pglob.gl_pathc; i++) {
		res.push_back(pglob.gl_pathv[i]);
	}
	return res;
}

vector<string> expand_glob(vector<string> globs) {
	vector<string> res;
	for (int i = 0; i < (int)globs.size(); i++) {
		const vector<string> paths = expand_glob(globs[i]);
		res.insert(res.end(), paths.begin(), paths.end());
	}
	return res;
}

}
