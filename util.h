#ifndef UTIL_H
#define UTIL_H

#include "node.h"

#include <vector>
#include <string>

using namespace sol1258;
using namespace std;

namespace sol1258
{
    class Util
    {
    public:
        static string toString(vector<string> input);
        static string toString(vector<int> input);
        static string toString(vector<vector<int>> input);
        static vector<string> split(string input);
        static vector<string> split(string input, char delimiter);
    };
}

#endif