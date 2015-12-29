#include <iostream>
#include <fstream>
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


vector<string> read_line_split_null(istream &f){
	vector<string> res;
	string str;
	do {
		getline(f,str,'\0');
		if(str.size()==0)break;
		res.push_back(move(str));
	}while(f);
	return res;
}

vector<vector<string>> read_file_split_null(const string &fname){
	ifstream f(fname);
	vector<vector<string>> res;
	while(f){
		vector<string> r=move(read_line_split_null(f));
		if(r.size()==0)continue;
		res.push_back(move(r));
	}
	return res;
}

}
