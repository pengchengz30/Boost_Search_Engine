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

const char* file_location = "Data/Input";

std::vector<std::string> getFiles(const std::string &path) {
    namespace fs = boost::filesystem;
    std::vector<std::string> files;
    if (!fs::exists(path)) {
        std::cerr << "Path does not exist." << std::endl;
        return files;
    }
    if (!fs::is_directory(path)) {
        std::cerr << "Not a directory." << std::endl;
        return files;
    }
    for (auto &file : fs::directory_iterator(path)) {
        if (!file.is_regular_file() || file.path().extension() != ".html") {
            continue;
        }
        files.push_back(file.path().string());
    }

    return files;
}

