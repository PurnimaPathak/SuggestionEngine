#include "suggestLib.h"

// Making new node //
struct node *getNode(void)
{
    struct node *pNode =  new node;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->mappedWords[i] = NULL;

    pNode->isCompletedWord = false;
    pNode->recentlyUsed =0;
    return pNode;
}

// File Operations //
int fileOperations(struct node *root, string filename) {
    fstream fileName;
    string line;
    fileName.open(filename, ios::in);
    if (!fileName) {
        cout << "Please enter a valid filename" << endl;
        exit(EXIT_FAILURE);
    } else {
        while (fileName.is_open()) {
            while (getline(fileName, line)) {
                if (!(line == "")) {
                    insert(root, line);
                }
                if (fileName.eof()) {
                    fileName.close();
                    return 1;
                }
            }
        }
    }
}

// Checking if the node is the last node //

bool isLastNode(struct node* crawl)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (crawl->mappedWords[i])
            return 0;
    return 1;
}

// Checking which is the next character in the word //
/* Here we check spaces too, because the space index is further
used to set the variable "ifContainSpaces" for further
processing sentences */

int placeOfCharacterOnLevel(char c){
    if(c==32 or (c>64 and c<91) or (c>96 and c <123)){
        return (c - (int)'a');
    }
}

// Insert the trie elements or nodes //
void insert(struct node *pCrawl,  const string key)
{
    for (int level = 0; level < key.length(); level++) {
        int index = placeOfCharacterOnLevel(std::tolower(key[level]));
        if (index == -65)
            pCrawl->ifContainSpaces = true;
        else {
            if (pCrawl->mappedWords[index] == nullptr) {
                pCrawl->mappedWords[index] = getNode();
            }
            pCrawl = pCrawl->mappedWords[index];
        }
    }
    pCrawl->isCompletedWord = true;
}

// Checking if the word in the output words is most commonly used based on usage //
int findPosition(int recentUse, vector <int> usage){
    std::vector<int>::iterator it;
    for(it = usage.begin(); it != usage.end(); ++it) {
        if (*it>recentUse)
            break;
    }
    return it-usage.begin();
}

// Finding the word with the prefix //
void findWordWithPrefix(struct node* pCrawl, string prefix, std::vector <string> &strArr, vector <int> &usage) {
    string pre_bk = prefix;
    int i;
    if (pCrawl->isCompletedWord)
    {
        int n = findPosition(++pCrawl->recentlyUsed, usage);
        strArr.insert(strArr.begin()+n, prefix);
        usage.insert(usage.begin()+n, pCrawl->recentlyUsed);
    }
    if (isLastNode(pCrawl))
        return;

    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        if (pCrawl->mappedWords[i])
        {
            if(pCrawl->ifContainSpaces) prefix.push_back(32);
            prefix.push_back(97 + i);
            findWordWithPrefix(pCrawl->mappedWords[i], prefix, strArr, usage);
        }
        prefix = pre_bk;
    }
}


int findWordSuggestions(node* pCrawl, const string query, const string phrase, int maxCount)
{
    struct node* crawl = pCrawl;
    int count =0;
    if (query == "complete"){
        for (int level=0; level<phrase.length(); level++)
        {
            int index = placeOfCharacterOnLevel(phrase[level]); //bea
            if (!(crawl->mappedWords[index] == nullptr)) {
                crawl = crawl->mappedWords[index];
                count++;
            }else if(count<=1){
                return 0;
            }
        }
        bool isLast = isLastNode(pCrawl);
        std::vector <string> strArray;
        std::vector <int> useArray;
        if (!isLast)
        {
            findWordWithPrefix(crawl, phrase, strArray, useArray);
            int i = strArray.size();
            while(maxCount>=0 and i>-1){
                cout<<strArray[i]<<endl;
                i--;
                maxCount--;
            }
            return 1;
        }
    }else {
        cout << "Print a valid query"<<endl;
        return 0;
    }
    delete crawl;
}
// To check if the query is alphanumeric and contains lower characters //
string funcToLowerAndCheckAlpha(string str) { //com,ba,2
    bool start = true;
    for (int i = 0; i < str.length(); i++) {
        if(isalpha(str[i]) && start)
            str[i] = std::tolower(str[i]);
        else if (str[i] == ',' && start)
            str[i] = str[i];
        else if(isnumber(str[i])){
            start = false;
            str[i] = str[i];
        }
        else {
            cout << "enter the valid query using comma and commands" << endl;
            return ""; // when query in invalid
        }
    }
    return str;
}

// To check if the query is alphanumeric and contains lower characters //
// To check if the query is in the right format of "command,phrase,maxcount" //
struct Query funcToXform(struct Query fullQuery, string str, char delimiter) {
    int pos = 0;
    int count = 0;
    int position = str.find(delimiter);
    if (position > 0 && count >= 0 && count < 2) {
        if (str.substr(0, str.find(delimiter)).compare("complete") == 0) {
            fullQuery.query = str.substr(0, str.find(delimiter));
            count++;
            str = str.substr(fullQuery.query.length() + 1, str.length());
            pos = str.find(delimiter);
            if (pos > 0) {
                fullQuery.phrase = str.substr(0, str.find(delimiter));
                count++;
            }
            if (count == 2) {
                str = str.substr(fullQuery.phrase.length() + 1, str.length());
                fullQuery.maxCount = atoi(str.substr(0, str.length()).c_str());
            }
        } else {
            cout << "Use proper command \"complete\"" << endl;
            fullQuery.phrase="";
            fullQuery.query="";
            fullQuery.maxCount =0;
            return fullQuery;
        }
    } else {
        cout << "Use proper delimiter" << endl;
        fullQuery.phrase="";
        fullQuery.query="";
        fullQuery.maxCount =0;
        return fullQuery;
    }
    return fullQuery;
}




