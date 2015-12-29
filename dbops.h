#include <string>
#include <unordered_map>

using namespace std;

namespace Vergeten {

void stash_file(string);
void unstash_file(string);

typedef string hash_t;
typedef unordered_map<string, string> changes;
typedef unordered_map<hash_t, changes> commitmap;

class Database {
	commitmap commits;
};

Database read_db(string);

class State {
	hash_t head;
	Database db;
};

class Thing {
	string path;
	bool stashed;
};


}
