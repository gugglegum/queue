#ifndef QUEUE_IQUEUE_H
#define QUEUE_IQUEUE_H

using namespace std;

#include "iterator.h"

/**
 * Интерфейс очереди, включает в себя интерфейс итератора
 */
class IQueue : public Iterator {
public:
    virtual void put(int number) = 0;
    virtual int get() = 0;
    virtual void clear() = 0;
    virtual bool isEmpty() = 0;
};

#endif //QUEUE_IQUEUE_H
