#include "ContentManager.h"

using namespace std;

void ContentManager::addContent(const string& category, const string& content) {
    contentByCategory[category].insert(content);
}

vector<string> ContentManager::getContentByCategory(const string& category) const
{
    vector<string> result;
    auto it =contentByCategory.find(category);
    if(it != contentByCategory.end())
    {
        result.assign(it->second.begin(), it->second.end());
    }

    return result;
}
