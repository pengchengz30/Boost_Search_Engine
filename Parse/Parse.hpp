//
//  Parse.hpp
//  Boost_Searcher
//
//  Created by Pengcheng Zhang on 12/2/24.
//

#pragma once

#include <fstream>
#include <iostream>

#include "HtmlInfo.hpp"
#include "GetFileList.hpp"

const char *title_delimiter = "title\r";
size_t title_delimiter_size = std::string(title_delimiter).size();
const char *content_delimiter = "content\r";
size_t content_delimiter_size = std::string(content_delimiter).size();
const char *url_delimiter = "\rurl\r";
size_t url_delimiter_size = std::string(url_delimiter).size();


const char *url_head = "https://www.boost.org/doc/libs/1_86_0/doc/html";

std::string readFile(const std::string &filename) {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        return "";
    }
    std::string line;
    std::string content;
    while (std::getline(ifs, line)) {
        content += line;
        if (!content.empty() && content.back() != ' ')
            content += ' ';
    }
    while (!content.empty() && content.back() == ' ')
        content.pop_back();
    return content;
}

class Parse {
  public:
    static std::string parseTitle(const std::string &file) {
        size_t begin = file.find("<title>");
        if (begin == std::string::npos) {
            return "";
        }
        begin += std::string("<title>").size();
        size_t end = file.find("</title>", begin);
        if (end == std::string::npos) {
            return "";
        }
        return file.substr(begin, end - begin);
    }

    static std::string parseBody(const std::string &file) {
        bool isLabel = false;
        bool prevIsSpace = true;
        std::string body;
        for (char c : file) {
            if (c == '<') {
                isLabel = true;
                continue;
            }
            if (c == '>') {
                isLabel = false;
                if (!body.empty() && !prevIsSpace) {
                    body += " ";
                    prevIsSpace = true;
                }
                continue;
            }
            if (!isLabel) {
                if (c == '\n' || c == '\t' || c == '\r') {
                    c = ' ';
                }
                if (c == ' ' && prevIsSpace)
                    continue;
                if (c == ' ')
                    prevIsSpace = true;
                else
                    prevIsSpace = false;
                body += c;
            }
        }
        return body;
    }

    static std::string parseUrl(const std::string &filename) {
        size_t pos = filename.find(file_location);
        if (pos == std::string::npos) {
            return "";
        }
        std::string url_tail =
            filename.substr(pos + std::string(file_location).size());

        return std::string(url_head) + url_tail;
    }

    static void parse(const std::string &filename,
                      std::vector<HtmlInfo> &infos) {
        std::string content = readFile(filename);

        std::string title = parseTitle(content);
        std::string body = parseBody(content);
        std::string url = parseUrl(filename);
        HtmlInfo info(title, body, url);
        if (info.isValid()) {
            infos.push_back(std::move(info));
        }
    }
};
void saveHtml(const std::vector<HtmlInfo> &infos, const std::string &output) {
    std::ofstream ofs(output,
                      std::ios::out | std::ios::trunc | std::ios::binary);
    if (!ofs.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return;
    }

    for (const auto &info : infos) {
        ofs.write(title_delimiter, std::string(title_delimiter).size());
        ofs.write(info.title.c_str(), info.title.size());
        ofs.write(content_delimiter, std::string(content_delimiter).size());
        ofs.write(info.content.c_str(), info.content.size());
        ofs.write(url_delimiter, std::string(url_delimiter).size());
        ofs.write(info.url.c_str(), info.url.size());
        ofs.write("\n", 1);
    }
}
