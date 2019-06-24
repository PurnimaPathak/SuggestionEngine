# SuggestionEngine
Suggest phrases based on commonly occurring phrases in the filename.

	•	Titles and internal titles:
	•	Introduction - the project's aim is to suggest phrases based on commonly occurring phrases in the filename
	•	3 Projects as below:
  
	•	Project: SuggestionEngine
	•	To kill use : kill -9 pid
	•	Start the engine: SuggestionEngine <filename>
                main.cpp, imports suggestLib.a, which implements the suggestion algorithm.
	              3 input files
                
	•	Project: Test SuggestionEngine
	              Tests the suggestion engine working with unit tests.
                
	•	Scope of functionalities 
	•	The program is capable of searching and finding auto suggestive words and sentences based on the query.
	•	A normal query should look like “command=complete, phrase = “ba“, maxCount = 2” for eg: complete,ba,2” where the “complete” is the query command, “ba” is the phrase that you wish to search words starting with, and the maximum number of words you wish to output is the “2” or the maxCount.
	•	The program uses Trie DS. 
	•	There are three projects in total. 
  
  
  
♣	Library libSuggestLib.a performs the suggestion algorithm or the static library doing the suggestion.
♣	TestSuggestionEngine does unit testing
♣	SuggestionEngine takes the filename as input parameter and outputs the suggestion. 
•	Sources
	Part 1: SuggestionAlgorithm
♣	Example: “bat”
•	root->b->a->t
•	mappedWords[index of character] = b->children[1] = 1 because the next alphabet to b is a.
♣	Read each line (line-by-line) from the filename
♣	Process lines by converting them into a-z, A-Z, spaces.
♣	Insert the Trie elements:
•	root->mappedWords[index of character] should not be null I.e. if the children to the root is null, then create a new node using getnode() and mark the next alphabet of the word in the new node  using ALPHABET_SIZE. 
•	In other words, for making a trie of word, the mapped words to the root from index 1 to 26 should not be null (for “bat”, b’s 1st index will have a’s information and a’s index will have t’s. if null, then create a new node with all 0-25 indexes, 
•	Set the next char in the word, here “bat” I.e. a in the 0th index of the child to the root.
•	Follow above order recursively to insert the word using trie.
•	When inserted, mark IsCompletedWord as TRUE.
♣	Insert the trie elements for sentences:
•	same word insertion algorithm as above
•	using one more variable “ifContainSpaces”
•	if “ifContainSpaces =true” then the word is a part of a sentence and the insertion is done marking each words in the sentence with “ifContainSpaces =true”
♣	WordSuggestions
•	Two concepts used
o	For sentences- ifContainSpaces =true—> then make a sentence
o	For words - “query.phrase” and “isRecentlyUsed”
o	“isRecentlyUsed” tells the program if the word suggested is common amongst other outputs or not, based on “query.phrase”.
Part 2: Testing
♣	Testing the insert:
•	Check if the words are properly getting converted to lower before insertion
•	Check the insertion properly, with huge set of data, starting from different individual characters.
•	Check proper word reading from the file with white spaces, extra characters and empty lines.
♣	Testing the query “complete,ba,2” 
•	Testing with all possible queries containing non-alphanumeric characters, spaces and all negative and positive cases
•	For example: 
o	{"complete,ba2,2", "com,ba,2", "complete,ba,2,34", "complete,ba.2","complete,ba,2", "complete.ba.2","complete.ba,2", "complete.ba,#", "c,omplete,ba,2", "complete.ba.#", "complete,b#,2", "complete.ba,#"};
•	Testing the most common phrases using “usage”
•	Testing the whole process using SuggestionEngine.exe


Source Code:
// To check if the query is alphanumeric and contains lower characters //
// To check if the query is in the right format of "command,phrase,maxcount" //
struct Query funcToXform(struct Query fullQuery, string str, char delimiter)

// To check if the query is alphanumeric and contains lower characters //
string funcToLowerAndCheckAlpha(string str)

// Checking if the word in the output words is most commonly used based on usage // int findPosition(int recentUse, vector <int> usage)

// Insert the trie elements or nodes // void insert(struct node *pCrawl,  const string key)

// Checking which is the next character in the word // /* Here we check spaces too, because the space index is further used to set the variable "ifContainSpaces" for further processing sentences */ int placeOfCharacterOnLevel(char c)

// Checking if the node is the last node // bool isLastNode(struct node* crawl)

// Making new node // struct node *getNode(void)	
	







