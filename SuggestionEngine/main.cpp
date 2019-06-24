#include "suggestLib.h"
#include <signal.h>
#include <zconf.h>

struct node *root = new node;
struct Query structQuery;

static void SignalHandler(int num){
    cout<<"Process ID"<<::getpid()<<endl;
    delete root;
    exit(num);
}

void RegisterSignals(){
    try{
        signal(SIGINT, SignalHandler);
        signal(SIGKILL, SignalHandler);
    }catch (int ex){
        exit(1);
    }

}
int main(int argc, char *argv[]) {
    RegisterSignals();
    string fullQuery, line;
    fstream fileName;
    vector <string> words;

    try {
        if (argc==2) {
            fileName.open(argv[1], ios::in);
            while (fileName.is_open()) {
                while (getline(fileName, line)) {
                    if (!(line == "")) {
                        insert(root, line);
                    }
                    if (fileName.eof()) {
                        fileName.close();
                    }
                }
            }
        }else{
            cout<<"Pass file name as input parameter"<<endl;
            return 0;
        }
    }catch (int ex) {
        cout << "Error: File Operation.\n";
        exit(1);
    }
    int comp;
    while(1){
        cout << "\n If you want to search a word? \n Enter the query"
                "=complete, the search phrase and the maximum count of words you wish to \n "
                "view. Each information separated by commas \n"<<endl;
        cin >> fullQuery; //complete,ba,2 // query, phrase, max_count

        fullQuery = funcToLowerAndCheckAlpha(fullQuery); //n
        if (fullQuery!="")
            structQuery = funcToXform(structQuery,fullQuery, ',');
        if (structQuery.query!="" and structQuery.phrase!="" and structQuery.maxCount>0)
            comp = findWordSuggestions(root, structQuery.query, structQuery.phrase, structQuery.maxCount);
        if (comp <=0) {
            cout << "\n"<<endl;
        }
    }
    delete root;
}

