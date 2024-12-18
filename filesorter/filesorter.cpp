
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

std::vector<std::string> getFilePaths(int argc, char* argv[]);
bool fileOpenReadSort(const std::vector<std::string>& fileNames);

int main(int argc, char* argv[]) {

  std::vector<std::string> fileNames;
  fileNames.reserve(argc - 1);
  fileNames = getFilePaths(argc, argv);

  fileOpenReadSort(fileNames);

  std::cout << fileNames.size() << std::endl;
}

std::vector<std::string> getFilePaths(int argc, char* argv[]) {
  std::vector<std::string> fileNames;
  
  std::cout << "Num of Arg: " << argc << std::endl;
  for (int i = 1; i < argc; i++) {
    std::cout << "Arg " << i << ": " << argv[i] << std::endl;
    fileNames.push_back(argv[i]);
  }
  return fileNames;
}

bool fileOpenReadSort(const std::vector<std::string>& fileNames) { 
  for (int i = 0; i < fileNames.size(); i++) {
    std::fstream filepath(fileNames.at(i));
    std::vector<std::string> toSort;
    std::string line = "";
    
    if (!filepath.is_open()) {//bad file check
      std::cout << "invalid file name ... skipping" << std::endl;
    } 
    else {
      //items to sort
      while (getline(filepath, line)) {
        toSort.push_back(line);
      }

      //sorted items
      std::sort(toSort.begin(), toSort.end());

      filepath.close();
      filepath.open(fileNames.at(i), std::ios::out | std::ios::trunc);
      for (auto line : toSort) {
        filepath << line << std::endl;
      }
      filepath.close();
    }
  }
  
  return false; 
}



