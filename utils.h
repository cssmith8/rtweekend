#ifndef ATL_UTILS_H
#define ATL_UTILS_H

#include <string>
using std::string;

//returns the last letter of a string
char last_letter(string s) {
    return s[s.size() - 1];
}

#endif //ATL_UTILS_H
