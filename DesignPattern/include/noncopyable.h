#ifndef _DESIGN_PATTERN_NONCOPYABLE_
#define _DESIGN_PATTERN_NONCOPYABLE_

class noncopyable
{
protected:
    // 默认构造函数和析构函数
    noncopyable() = default;
    ~noncopyable() = default;

public:
    // 拷贝构造函数和拷贝赋值运算符 delete
    noncopyable(const noncopyable &) = delete;
    void operator=(const noncopyable &) = delete;
};

#endif