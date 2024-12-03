//
//  HtmlInfo.hpp
//  Boost_Searcher
//
//  Created by Pengcheng Zhang on 12/2/24.
//

#pragma once
#include <string>

struct HtmlInfo {
    template <class T1, class T2, class T3>
    HtmlInfo(T1 &&title, T2 &&content, T3 &&url)
        : title(std::forward<T1>(title)), content(std::forward<T2>(content)),
          url(std::forward<T3>(url)) {}
    HtmlInfo() = default;

    std::string title;
    std::string content;
    std::string url;
    
    bool isValid(){
        return !title.empty() && !content.empty() && !url.empty();
    }
};
