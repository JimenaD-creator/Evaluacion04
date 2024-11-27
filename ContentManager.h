#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H


#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class ContentManager {
private:
    unordered_map<string,  std::unordered_set<std::string>> contentByCategory;

public:
    void addContent(const std::string& category, const std::string& content);
    std::vector<std::string> getContentByCategory(const std::string& category) const;
};

#endif