/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "strlib.h"
#include <cctype>
using namespace std;

string onlyConnectize(string phrase) {
    // Base case
    if (phrase.empty()) {
        return "";
    }
    char first = toupper(phrase[0]);
    string rest = onlyConnectize(phrase.substr(1));

    // Recursive case
    if (isalpha(first) && !(first == 'A' || first == 'E' || first == 'I' || first == 'O' || first == 'U')) {
        return first + rest;
    }
    return rest;
}

/* * * * * * Provided Test Cases * * * * * */
#include "GUI/SimpleTest.h"

PROVIDED_TEST("Various cases") {
    EXPECT_EQUAL(onlyConnectize("For sale: baby shoes, never worn."), "FRSLBBYSHSNVRWRN");
    EXPECT_EQUAL(onlyConnectize("I'm the bad guy. (Duh!)"), "MTHBDGYDH");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Different cases") {
    EXPECT_EQUAL(onlyConnectize("Annie Mae, My Sea Anemone Enemy!"), "NNMMYSNMNNMY");
    EXPECT_EQUAL(onlyConnectize("Antonin Scalia"), "NTNNSCL");
}

PROVIDED_TEST("Extreme cases") {
    EXPECT_EQUAL(onlyConnectize("......."), "");
    EXPECT_EQUAL(onlyConnectize("0AAIII_-3214'////''(#@!$@"), "");
}
