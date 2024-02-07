#ifndef __ABSTRACTWORDSLIST_H__
#define __ABSTRACTWORDSLIST_H__

#include <string>

class AbstractWordsList {
  public:
    virtual void addWord(std::string str) = 0;
    virtual void updateWord(std::string oldStr, std::string newStr) = 0;
    virtual bool isSorted() = 0;
    virtual void removeDuplicatesExceptFirst() = 0;
    virtual void removeDuplicatesExceptLast() = 0;
    virtual void print() = 0;
};

#endif
