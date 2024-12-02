//
//  GetFileList.hpp
//  Boost_Searcher
//
//  Created by Pengcheng Zhang on 12/2/24.
//

#pragma once

#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::pair<bool, std::vector<std::string>> getFiles(const std::string &path) {
    namespace fs = boost::filesystem;
    std::vector<std::string> files;
    if (!fs::exists(path)) {
        std::cerr << "Path does not exist." << std::endl;
        return {false, files};
    }
    if (!fs::is_directory(path)) {
        std::cerr << "Not a directory." << std::endl;
        return {false, files};
    }
    for (auto &file : fs::directory_iterator(path)) {
        if (!file.is_regular_file() || file.path().extension() != ".html") {
            continue;
        }
        files.push_back(file.path().string());
    }

    return {true, files};
}

void parse(const std::vector<std::string> &files){
    
}
