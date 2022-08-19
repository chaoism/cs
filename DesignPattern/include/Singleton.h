#include "noncopyable.h"

template <typename T>
class Singleton : noncopyable
{
    // 数据成员
private:
    static pthread_once_t ponce_;
    static T *value_;

private:
    static void init()
    {
        value_ = new T();
        if (!has_no_destroy<T>::value)
        {
            ::atexit(destroy);
        }
    }

    static void destroy()
    {
        typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1];
        T_must_be_complete_type dummy;
        (void)dummy;

        delete value_;
        value_ = NULL;
    }

public:
    Singleton() = delete;
    ~Singleton() = delete;
};

template <typename T>
pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;

template <typename T>
T *Singleton<T>::value_ = NULL;
