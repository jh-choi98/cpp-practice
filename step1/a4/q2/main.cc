#include "abstractWordsList.h"
#include "linkedListWordsList.h"
#include "wordsProcessor.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    AbstractWordsList *list = new LinkedListWordsList;
    AbstractWordsList *list2 = new LinkedListWordsList;
    AbstractWordsList *list3 = new LinkedListWordsList;
    AbstractWordsList *list4 = new LinkedListWordsList;
    WordsProcessor wp;

    string str[9] = {"aa", "ab", "ac", "aa", "ad", "aa", "ad", "ad", "ae"};
    int len = 9;
    cout << len << endl;
    for (int i = 0; i < len; ++i) {
        list->addWord(str[i]);
    }

    string str2[3] = {"c", "b", "a"};
    int len2 = 3;
    for (int i = 0; i < len2; ++i) {
        list2->addWord(str2[i]);
    }

    string str3[8] = {"a", "1", "2", "1", "b", "1", "2", "1"};
    int len3 = 8;
    for (int i = 0; i < len3; ++i) {
        list3->addWord(str3[i]);
    }

    // list4->addWord("2");
    // list4->addWord("1");
    // list4->addWord("1");
    // list4->addWord("2");
    // list4->addWord("2");
    // list4->addWord("1");
    // list4->addWord("1");
    list4->addWord("1");
    list4->addWord("1");
    list4->addWord("1");
    list4->addWord("1");
    list4->addWord("1");
    list4->addWord("1");

    cout << "********** CountVowels **********" << endl;
    cout << wp.countVowels("the qUick brOwn fox jumped Over the lAzy dog")
         << endl;

    cout << "********** isSorted **********" << endl;
    cout << wp.isSorted(list) << endl;
    cout << wp.isSorted(list2) << endl;

    cout << "********** replaceWord **********" << endl;
    list->print();
    wp.replaceWord("ae", "hello", list)->print();
    wp.replaceWord("aa", "hello", list)->print();
    wp.replaceWord("aa", "hello", list)->print();
    wp.replaceWord("hello", "aa", list)->print();

    // cout << "********** removeDuplicatesExceptFirst **********" << endl;
    // list3->print();
    // wp.removeDuplicatesExceptFirst(list3)->print();
    // list4->print();
    // wp.removeDuplicatesExceptFirst(list4)->print();

    cout << "********** removeDuplicatesExceptLast **********" << endl;
    list3->print();
    wp.removeDuplicatesExceptLast(list3)->print();

    // list3->print();
    // wp.removeDuplicatesExceptLast(list3)->print();
}
