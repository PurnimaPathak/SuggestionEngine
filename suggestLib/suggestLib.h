/* Suggest phrases based on commonly occurring phrases in the corpus
The program is capable of searching and finding auto suggestive words and sentences based on the query */

#ifndef SUGGESTLIB_H
#define SUGGESTLIB_H


#include <iostream>
#include <fstream>
#include <iterator>
#include <unordered_map>
#include <vector>
#include <regex>
#include <sstream>
#include <iostream>
# include <cstring>
using namespace std;
const int ALPHABET_SIZE = 26;


struct node{
    struct node * mappedWords[ALPHABET_SIZE]{};
    bool isCompletedWord= false;
    bool ifContainSpaces= false;
    int recentlyUsed{};
};

struct Query{
    string query;
    string phrase;
    int maxCount;
};

struct node *getNode(void);
int fileOperations(struct node *crawl, string filename);
bool isLastNode(struct node* crawl);
int placeOfCharacterOnLevel(char c);
void insert(struct node *pCrawl,  const string key);
int findPosition(int recentUse, vector <int> usage);
void findWordWithPrefix(struct node* pCrawl, string prefix, std::vector <string> &strArr, vector <int> &usage);
int findWordSuggestions(node* pCrawl, const string query, const string phrase, int maxCount);
string funcToLowerAndCheckAlpha(string str);
struct Query funcToXform(struct Query fullQuery, string str, char delimiter);


#endif
