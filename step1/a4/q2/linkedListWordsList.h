#ifndef __LINKEDLISTWORDSLIST_H__
#define __LINKEDLISTWORDSLIST_H__

#include "abstractWordsList.h"

struct Node {
    std::string data;
    Node *next;

  public:
    Node(std::string data);
    Node(std::string data, Node *node);
};

class LinkedListWordsList : public AbstractWordsList {
    Node *head;
    Node *tail;

  public:
    LinkedListWordsList();
    ~LinkedListWordsList();

    void addWord(std::string str) override;
    void updateWord(std::string oldStr, std::string newStr) override;
    bool isSorted() override;                    // application 담당
    void removeDuplicatesExceptFirst() override; // application 담당
    void removeDuplicatesExceptLast() override;  // application 담당
    void print() override;
};

#endif

/*
WordsProcessor -> Abstraction

virtual bool isSorted() = 0;
virtual void removeDuplicatesExceptFirst() = 0;
virtual void removeDuplicatesExceptLast() = 0;
가 AbstractWordsList 메소드로 있어서 코드 재사용성이 떨어짐.

따라서 이 메소드들을 AbstractWordsProcessor로 옮겨서 코드 재사용성이 극대화됨

DataStructure를 디자인할 때는 어디서든지 사용할 수 있도록 만들어야한다.
특정한 기능을 수행하는 클래스들을 만들 때도 마찬가지이다.
특정 프로젝트를 넘어서 언제어디서든지 사용할 수 있도록 만들어야 한다.


DataStructure는 레고 조각
Application은 레고 조각을 사용해서 작품을 만듦
이 때 래고 조각은 다른 작품을 위해서도 사용될 수 있음. 따라서 범용적임.
DataStructure를 디자인할 때도 이처럼 해야함.


LinkedListWordsList의 Node를 template로 만들기
*/
