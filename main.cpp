#include <iostream>
#include <cassert>

using namespace std;

int loopCompare(string string1, string string2, int index1, int index2) {// Compares the strings
    for (int i = index1; i < index2; i++) {
        if (int(tolower(string1[i])) != int(tolower(string2[i]))) {// Return difference if characters are not equal.
            return int(tolower(string1[i])) - int(tolower(string2[i]));
        }
    }
    return 0;
}

int strcmp_case_insensitive(string string1, string string2) {
    int smallestSize;
    if (string1.size() < string2.size()) {
        smallestSize = string1.size();
    } else {
        smallestSize = string2.size();
    }
    // iterate through smallest string to avoid out of bounds
    if (loopCompare(string1, string2, 0, smallestSize) != 0) {
        return loopCompare(string1, string2, 0, smallestSize);
    }
    if (string1.size() >
        string2.size()) {//runs the same loop as before but for the rest of the characters in the larger string
        if (loopCompare(string1, string2, string2.size(), string1.size()) != 0) {
            return loopCompare(string1, string2, string2.size(), string1.size());
        }

    } else if (string2.size() > string1.size()) {
        if (loopCompare(string1, string2, string1.size(), string2.size()) != 0) {
            return loopCompare(string1, string2, string1.size(), string2.size());
        }
    }

    // After loops run without returning anything, the strings must be equal, so returns 0.
    return 0;
}

int main() {
    // Testing different length strings
    assert(strcmp_case_insensitive("aa", "aab") < 0);
    assert(strcmp_case_insensitive("aab", "aa") > 0);
    assert(strcmp_case_insensitive("aa", "a") > 0);
    assert(strcmp_case_insensitive("a", "aa") < 0);
    assert(strcmp_case_insensitive("a", "a") == 0);
    assert(strcmp_case_insensitive("", "") == 0);

    //Testing case insensitivity
    assert(strcmp_case_insensitive("Hi", "hi") == 0);
    assert(strcmp_case_insensitive("hi", "Hi") == 0);

    //Testing with spaces
    assert(strcmp_case_insensitive("Hi", "h i") > 0);
    assert(strcmp_case_insensitive(" ", " ") == 0);
    assert(strcmp_case_insensitive(" ", " f") < 0);
}