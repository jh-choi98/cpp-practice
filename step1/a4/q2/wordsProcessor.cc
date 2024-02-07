#include "wordsProcessor.h"
#include <iostream>
using namespace std;

int WordsProcessor::countVowels(std::string s) {
    int count = 0;
    int len = s.length();
    std::string allVowels = "aeiouAEIOU";
    for (int i = 0; i < len; ++i) {
        if (allVowels.find(s[i]) != std::string::npos) {
            ++count;
        }
    }
    return count;
}

bool WordsProcessor::isSorted(AbstractWordsList *list) {
    return list->isSorted();
}

AbstractWordsList *WordsProcessor::replaceWord(std::string oldStr,
                                               std::string newStr,
                                               AbstractWordsList *list) {
    list->updateWord(oldStr, newStr);
    return list;
}

AbstractWordsList *
WordsProcessor::removeDuplicatesExceptFirst(AbstractWordsList *list) {
    list->removeDuplicatesExceptFirst();
    return list;
}
AbstractWordsList *
WordsProcessor::removeDuplicatesExceptLast(AbstractWordsList *list) {
    list->removeDuplicatesExceptLast();
    return list;
}

void WordsProcessor::print(AbstractWordsList *list) {
    list->print();
    return;
}
// int main() {
//     string str = "the qUick brOwn fox jumped Over the lAzy dog";
//     cout << countVowels(str) << endl;
// }
