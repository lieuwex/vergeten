#include <string>
#include <vector>

using namespace std;

namespace Vergeten {

vector<string> expand_glob(string path);
vector<string> expand_glob(vector<string> paths);

vector<vector<string>> read_file_split_null(const string &fname);

}
