#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1258;

/*
Input:
 synonyms = [["happy","joy"],["sad","sorrow"],["joy","cheerful"]],
 text = "I am happy today but was sad yesterday"

 Output:
 ["I am cheerful today but was sad yesterday",
 ​​​​​​​"I am cheerful today but was sorrow yesterday",
 "I am happy today but was sad yesterday",
 "I am happy today but was sorrow yesterday",
 "I am joy today but was sad yesterday",
 "I am joy today but was sorrow yesterday"]

*/

tuple<vector<vector<string>>, string, vector<string>> testFixture1()
{
  auto input = vector<vector<string>>{
      {"happy", "joy"}, {"sad", "sorrow"}, {"joy", "cheerful"}};

  auto output = vector<string>{"I am cheerful today but was sad yesterday",
                               "I am cheerful today but was sorrow yesterday",
                               "I am happy today but was sad yesterday",
                               "I am happy today but was sorrow yesterday",
                               "I am joy today but was sad yesterday",
                               "I am joy today but was sorrow yesterday"};

  return make_tuple(input, "I am happy today but was sad yesterday", output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << Util::toString(get<2>(f)) << endl;
  Solution sol;
  cout << "result: " << Util::toString(sol.generate(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  return 0;
}