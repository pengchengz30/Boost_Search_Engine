//
//  main.cpp
//  Boost_Searcher
//
//  Created by Pengcheng Zhang on 12/2/24.
//

#include "GetFileList.hpp"
#include "parse.hpp"

int main(int argc, const char *argv[]) {
    std::pair<bool, std::vector<std::string>> ret = getFiles("Data/Input");
    if (!ret.first) {
        return -1;
    }
    //    std::fstream of("ParseResult.txt", std::ios::out);
    //    if (!of.is_open()) {
    //        return -1;
    //    }

    for (const auto &file : ret.second) {
        std::cout << file << std::endl;
    }
    return 0;
}
