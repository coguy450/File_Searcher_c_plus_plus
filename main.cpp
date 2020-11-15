#include <iostream>
#include <filesystem>
#include <string>
#include "FileSearcher.h"
namespace fs = std::filesystem;
using namespace std;

// clang++ --std=c++17 -Wall -g -o efs ./*.cpp
int main()
{
  string searchString;
  string pathString;
  FileSearcher f{};
  getline(cin, pathString);

  fs::path p = getenv("HOME");
  string newPath = f.getPath(pathString, p);

  cout << "You want to search in " << newPath << endl;
  cout << "Enter Search string: ";
  getline(cin, searchString);
  f.doSearch(newPath, searchString); 
  f.readHomeDirectory();
  return 0;

}