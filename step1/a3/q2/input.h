#ifndef __INPUT_H__
#define __INPUT_H__

#include "rgb.h"

class Input
{
public:
    virtual RGB getRgb() = 0; // client는 이 메소드를 이용해서만 Input을 사용할 수 있음.
    virtual bool isValid() = 0;
    virtual ~Input();
};

// to hold three integers, not to use
// so don't need to identify which one is rgb
// class? structure? 판단기준 => 이 오브젝트가 단순히 데이터만 전달하는가?(struct) 기능을 제공하는가?(class)
// 상황에 따라 implementation이 변화될 가능성이 있기 때문에, flexibility를 위해 기능이 제공될 필요가 있는 경우 class로 define한다.
// 클라이언트가 클래스 오브젝트를 사용할 수 있는 유일한 방법은 클래스에 제공된 public method를 통해서다.
// 개발자 입장에서는 public interface를 class invariant를 유지하는 한 마음대로 바꿀 수 있는 자유도가 주어진다.

#endif
