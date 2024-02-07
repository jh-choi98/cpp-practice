#ifndef __WORDSPROCESSOR_H__
#define __WORDSPROCESSOR_H__

#include "abstractWordsList.h"
#include <string>

class WordsProcessor {
  public:
    int countVowels(std::string s);
    bool isSorted(AbstractWordsList *list);
    AbstractWordsList *replaceWord(std::string oldStr, std::string newStr,
                                   AbstractWordsList *list);
    AbstractWordsList *removeDuplicatesExceptFirst(AbstractWordsList *list);
    AbstractWordsList *removeDuplicatesExceptLast(AbstractWordsList *list);
    void print(AbstractWordsList *list);
};

#endif
