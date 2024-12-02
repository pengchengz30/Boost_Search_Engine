//
//  Parse.hpp
//  Boost_Searcher
//
//  Created by Pengcheng Zhang on 12/2/24.
//

#pragma once

const char *url_head = "https://www.boost.org/doc/libs/1_86_0/doc/html/";

class Parse {
  public:
    static std::string parseTitle(const std::string &file) {
        size_t begin = file.find("<title>");
        if (begin == std::string::npos) {
            return "";
        }
        begin += std::string("<title>").size();
        size_t end = file.find("</title>");
        if (end == std::string::npos || end <= begin) {
            return "";
        }
        return file.substr(begin, end - begin);
    }

    static std::string parseContent(const std::string &file) {
        bool isLabel = false;
        std::string content;
        for (char c : file) {
            if (c == '<') {
                isLabel = true;
                continue;
            }
            if (c == '>') {
                isLabel = false;
                content += " ";
                continue;
            }
            if (!isLabel) {
                if (c == '\n')
                    c = ' ';
                content += c;
            }
        }
        return content;
    }

    static std::string parseUrl(const std::string &filename) {
        size_t pos = filename.find("Input/Data");
        if (pos == std::string::npos) {
            return "";
        }
        std::string url_tail = filename.substr(pos + 1);

        return std::string(url_head) + url_tail;
    }
};
