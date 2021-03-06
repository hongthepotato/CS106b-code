/** This file is the source file of wordladder
    that two words are given, find one of the shortest
    path between these two words. Path mean a series of 
    words that differ one and only one letter.*/

// The condition that no path existed between two words is not 
// tested yet.

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "set.h"
#include "queue.h"
#include "stack.h"

using namespace std;

/** The whole functionality of this function is composed of several help functions listed below.*/
void welcome();

/** Function: userPromptFileName
    Prompt message for user to input the name of input file and open the file.
    Actually, i don't use its return value in this implimentation
    */
string userPromptFileName(ifstream & infile, string prompt);

/** Function: readWordsInFile
    Call function userPromptFileName.
    Open a file user specified and store all words one at a line
    in a SET words*/
void readWordsInFile(ifstream & infile, Set<string> & words);

/** Function: findShortestPath
 *  This function is used to find one of the shortest paths between two given words
 *  in the words bank user given. Every step differ one letter
*/
Stack<string> findShortestPath(Set<string> & words, string word1, string word2);

/** Function: isNeighbor
 *  This function is used to decide whether two words differ one letter. If so, 
 *  returns true, returns false otherwise.
*/
bool isNeighbor(string word1, string word2);

/** Function: getWordFromUser
 *  This function prompt and get the two words given by user to find A shortest path 
 *  between them
*/
string getWordFromUser(int index);
void output(Stack<string> finalStack, string word1, string word2);

int main() {
    welcome();
    ifstream infile;
    Set<string> words;
    string word1, word2;
    readWordsInFile(infile, words);
    while (true) {
        word1= getWordFromUser(1);
        word2 = getWordFromUser(2);
        if (!words.contains(word1) || !words.contains(word2)) {
            cout << "The two words must be found in the dictionary." << endl;
            cout << endl;
        } else if (word1.size() != word2.size()){
            cout << "The two words must be the same length." << endl;
            cout << endl;
        } else if (word1 == word2){
            cout << "The two words must be different." << endl;
            cout << endl;
        } else {
            break;
        }
    }
    Stack<string> finalStack;
    finalStack = findShortestPath(words, word1, word2);
    output(finalStack, word1, word2);


    cout << "Have a nice day." << endl;
    return 0;
}


void welcome() {
    cout << "Welome to CS 106B Word Ladder." << endl;
    cout << "Please give me two English words, and I will change the" << endl;
    cout << "first into the second by changing ont letter at a time." << endl;
    cout << endl;
}

string userPromptFileName(ifstream & infile, string prompt=""){
    while (true) {
        cout << prompt;
        string fileName;
        getline(cin, fileName);
        infile.open(fileName);
        if (!infile.fail()) return fileName;
        cout << "Unable to open that file.  Try again." << endl;
        prompt = "Dictionary file name? ";
    }
}

void readWordsInFile(ifstream & infile, Set<string> & words){
    userPromptFileName(infile, "Dictionary file name? ");
    string word;
    while (true) {
        getline(infile, word);
        if (!infile.fail()) {
            words.insert(word);
        } else if (!infile.eof()){
            cout << "Illeagle input file format. Each word must in an individual line!" << endl;
            break;
        } else {
            break;
        }
    }
    infile.close();
}

/** This function is very inefficient now, a more efficient implementation
 *  is needed!
*/
Stack<string> findShortestPath(Set<string> & words, string word1, string word2){
    Queue<Stack<string>> queueOfStacks;
    Stack<string> originalStack{word1};
    Stack<string> nextStepStack;
    Stack<string> frontOfQueue;
    Stack<string> shortestPath;
    string wordGiven;
    int lengthOfPath = words.size();
    Set<string> usedWords{word1};
    queueOfStacks.add(originalStack);
    while (!queueOfStacks.isEmpty()) {
        frontOfQueue = queueOfStacks.dequeue();
        wordGiven = frontOfQueue.peek();
        for (string wordInSet:words){
            if (wordGiven.size() == wordInSet.size() && isNeighbor(wordGiven, wordInSet) && !usedWords.contains(wordInSet)) {
                usedWords.add(wordInSet);
                if (wordInSet == word2) {
                    nextStepStack = frontOfQueue;
                    nextStepStack.add(wordInSet);
                    if (nextStepStack.size() < lengthOfPath){
                        lengthOfPath = nextStepStack.size();
                        shortestPath = nextStepStack;
                    }
                    break;
                } else {
                    nextStepStack = frontOfQueue;
                    nextStepStack.add(wordInSet);
                    queueOfStacks.add(nextStepStack);
                }
            }
        }
    }
    return shortestPath;
}

bool isNeighbor(string wordGiven, string wordInSet){
    string::size_type cnt = wordGiven.size();
    for (string::size_type i = 0; i < wordGiven.size(); ++ i){
        if (wordGiven[i] == wordInSet[i]) {
            cnt--;
        }
    }
return (cnt == 1);
}

string getWordFromUser(int index){
    cout << "Word #" << index << " (or Enter to quit): ";
    string word;
    getline(cin, word);
    return word;
}

void output(Stack<string> finalStack, string word1, string word2){
    cout << "A ladder from " << word2 << " back to " << word1 <<": " << endl;
    while (!finalStack.isEmpty()) {
        cout << finalStack.pop() << " " ;
    }
    cout << endl;
}

/* The following functions are test functions for above ones */

int main_isNeighborTest() {
    bool result1 = isNeighbor("date", "data");
    bool expected1 = true;
    bool result2 = isNeighbor("date", "love");
    bool expected2 = false;
    if (result1 == expected1) {
        cout << "TEST1 PASSED" << endl;
    } else {
        cout << "TEST1 FAILED" << endl;
    }
    if (result2 == expected2) {
        cout << "TEST2 PASSED" << endl;
    } else {
        cout << "TEST2 FAILED" << endl;
    }

    return 0;
}
