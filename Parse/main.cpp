//
//  main.cpp
//  Boost_Searcher
//
//  Created by Pengcheng Zhang on 12/2/24.
//

#include "GetFileList.hpp"
#include "Parse.hpp"

int main(int argc, const char *argv[]) {
    std::vector<std::string> files = getFiles(file_location);
    if (files.empty()) {
        return -1;
    }
    //    std::fstream of("ParseResult.txt", std::ios::out);
    //    if (!of.is_open()) {
    //        return -1;
    //    }

    //    for (const auto &file : ret.second) {
    //        std::cout << file << std::endl;
    //    }

    std::vector<HtmlInfo> infos;

    for (const auto &file : files) {
        Parse::parse(file, infos);
    }
    //    for (const auto &info : infos) {
    //        std::cout << "title: " << info.title << std::endl;
    //        std::cout << "body: " << info.content << std::endl;
    //        std::cout << "url: " << info.url << std::endl;
    //        std::cout << std::endl;
    //    }
    saveHtml(infos, "Data/Parsed/output.txt");

    return 0;
}
