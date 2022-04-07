
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;
namespace sol1258
{
    class Solution
    {
    private:
        void _generate(vector<string> &words, unordered_map<string, unordered_set<string>> map,
                       int idx, string base, vector<string> &result);
        void getSynonyms(string &s, unordered_map<string, unordered_set<string>> &map, unordered_set<string> &visited, vector<string> &choices);

    public:
        vector<string> generate(vector<vector<string>> &synoyms, string text);
    };
}
#endif