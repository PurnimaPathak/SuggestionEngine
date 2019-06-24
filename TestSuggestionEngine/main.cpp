#include "suggestLib.h"


/// Test for funcToLower ///
bool TestNegativefuncToLowerAndCheckAlpha() {
    vector<string> input = {",complete,ba.2", "complete,ba", "complete,ba2,2", "com,ba,2", "complete,ba,2,34",
                           "complete.ba,#"};

    for (auto it = begin(input); it != end(input); ++it) {
        string s = funcToLowerAndCheckAlpha(it->data());
        if (s == "")
            return true;

        return false;
    }
}

bool TestPositivefuncToLowerAndCheckAlpha() {
    vector<string> input = {"complete,ba,2"};

    for (auto it = begin(input); it != end(input); ++it) {
        string s = funcToLowerAndCheckAlpha(it->data());
        if (s == "complete,ba,2")
            return true;

        return false;
    }
}


/// Test for findWordSuggestions ///
/// Making commmand, phrase, maxcount seperated from the query ///
bool TestfuncToXform() {
    Query query;
    vector<string> input = {",complete,ba.2", "complete,ba", "complete,ba2,2", "com,ba,2", "complete,ba,2,34",
                            "complete,ba.#"};

    vector<string> output = {"", "", "", "", "",
                            ""};

    for (auto it1 = begin(input); it1 != end(input); ++it1) {
        for (auto it = begin(output); it != end(output); ++it) {
            query = funcToXform(query, *it1, ',');
            if (*it == query.phrase)
                return true;
            else
                return false;
        }

    }
}




int main() {
    bool res;
    res = TestNegativefuncToLowerAndCheckAlpha();
    if(res == true)
        cout<<"Negative test to funcToLowerAndCheckAlpha passed"<<endl;
    res = TestPositivefuncToLowerAndCheckAlpha();
    if(res == true)
        cout<<"Positive test to funcToLowerAndCheckAlpha passed"<<endl;
    res = TestfuncToXform();
    if(res == true)
        cout<<"test to TestfuncToXform passed"<<endl;
}