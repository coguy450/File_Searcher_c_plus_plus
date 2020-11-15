#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include "FileSearcher.h"
namespace fs = std::filesystem;
using namespace std;


FileSearcher::FileSearcher()
{
  cout << "Welcome to eSearch, to search your Documents and Downloads" << endl;
  cout << "Enter 1 to Search Documents" << endl;
  cout << "Enter 2 to search Downloads" << endl;
  cout << "Enter 3 to search all (will take a while)" << endl;
  cout << "Or enter a path you'd like to search like /usr/bin: ";
 
}

void FileSearcher::doSearch(fs::path p, string s)
{
  userPath = p;
  searchText  = s;
  cout << "Searching for ...." << s << " in " << userPath << endl;
  folderExceptions.insert("node_modules");
  folderExceptions.insert(".git");
  folderExceptions.insert(".terraform");
  folderExceptions.insert("kotlin-classes");
  folderExceptions.insert("coverage-lcov");
  folderExceptions.insert("site-packages");
  folderExceptions.insert("aetnaboost-android");
  return;
}

string FileSearcher::getPath(string pathIndicator, fs::path originalPath)
{
  string one = {'1'};
  string two = {'2'};
  string three = {'3'};
  if (pathIndicator == one) 
  {
    originalPath += "/Documents";
    return originalPath;    
  }
  else if (pathIndicator == two)
  {
    originalPath += "/Downloads";
    return originalPath;
  }
   else if (pathIndicator == three)
  {
    return "/";
  } else {
    return pathIndicator;
  }
}

void FileSearcher::readHomeDirectory()
{
  cout << "found result in:  " << userPath;
  for(auto p = fs::recursive_directory_iterator(userPath);
             p != fs::recursive_directory_iterator();
           ++p)
  {
    string currentPath = p->path();
    string pp = p->path().filename();
    const bool is_in = folderExceptions.find(pp) != folderExceptions.end();
    if(is_in)
      p.disable_recursion_pending();

    if (currentPath.find(searchText) != string::npos)
    {
       cout << p->path() << endl;
    }
  }
}
