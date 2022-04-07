#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
using namespace sol1258;
using namespace std;

/*takeaways
  - Group synonyms using a set. Put all the synonyms as the keys to a hash table
    to help look for the entire group starting with any synonym in that group
  - scan the text from left to right and recursively to find a synonym and
    replace with other synonyms in the same group to generate different texts

*/

void Solution::_generate(vector<string> &words, unordered_map<string, unordered_set<string>> map,
                         int idx, string base, vector<string> &result)
{
  if (idx == words.size())
  {
    /*remove the extra space we put in the end */
    base.pop_back();
    result.push_back(base);
    return;
  }

  /* find a synonym - find all the members in that group */
  if (map.count(words[idx]))
  {
    auto choices = vector<string>();
    auto visisted = unordered_set<string>();
    getSynonyms(words[idx], map, visisted, choices);

    /*replace it with all possible synonyms in that group */
    for (auto s : choices)
      _generate(words, map, idx + 1, base + s + " ", result);
  }
  else
    /*keep the word */
    _generate(words, map, idx + 1, base + words[idx] + " ", result);
}

void Solution::getSynonyms(string &s, unordered_map<string, unordered_set<string>> &map,
                           unordered_set<string> &visited, vector<string> &choices)
{
  visited.insert(s), choices.push_back(s);

  for (auto syn : map[s])
    if (visited.count(syn) == 0)
      getSynonyms(syn, map, visited, choices);
}

vector<string> Solution::generate(vector<vector<string>> &synoyms, string text)
{
  auto map = unordered_map<string, unordered_set<string>>();
  for (auto &pair : synoyms)
    map[pair[0]].insert(pair[1]), map[pair[1]].insert(pair[0]);

  auto words = Util::split(text);
  vector<string> result;

  _generate(words, map, 0, "", result);

  std::sort(result.begin(), result.end());
  return result;
}