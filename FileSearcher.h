#include <set>
#include <string>
#include <vector>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

class FileSearcher
{
private:
  fs::path userPath;
  string searchText;
  set<string> folderExceptions;
public:
  FileSearcher();
  void doSearch(fs::path p, string searchString);
  string getPath(string pathIndicator, fs::path originalPath);
  void readHomeDirectory();
};