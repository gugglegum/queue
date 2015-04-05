#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <iostream>
#include "iqueue.h"

using namespace std;

/**
 * Внутренняя структура элемента очереди
 *
 * Хранит в себе число (основная сущность очереди) и ссылку на следующий элемент
 */
struct QueueItem {
    /**
     * Число, основная сущность элемента очереди
     */
    int number;

    /**
     * Ссылка на следующий элемент очереди. Первоначально равен NULL, заполняется при добавлении
     * следующего элемента в очередь.
     */
    QueueItem* nextItem = NULL;
};

/**
 * Класс очереди, реализует интерфейс очереди
 */
class Queue : public IQueue {

private:

    /**
     * Ссылка на первый элемент в очереди (используется для получения следующего элемента из очереди)
     */
    QueueItem* _firstItem = NULL;

    /**
     * Ссылка на последний элемент в очредеи (используется при добавлении в конец очереди нового элемента)
     */
    QueueItem* _lastItem = NULL;

    /**
     * Ссылка на текущий элемент в очереди, используемый в итераторе
     */
    QueueItem* _currentItem = NULL;

public:

    Queue();
    ~Queue();

    /**
     * Добавляет в конец очереди новый элемент (число)
     */
    void put(int number);

    /**
     * Возвращает из начала очереди первый (следующий) элемент (число) и удаляет его из очереди
     */
    int get();

    /**
     * Очищает очередь
     */
    void clear();

    /**
     * Возвращает TRUE, если очередь в данный момент пуста
     */
    bool isEmpty();

    /**
     * Сбрасывает внутренний указатель текущего элемента. Сброшенный указатель ссылается на NULL, что
     * как бы соответствует элементу, предшествующему первому. Для обращения к первому элементу нужно
     * один раз вызвать ::moveNext()
     */
    void reset();

    /**
     * Возвращает число из текущего элемента в итераторе
     */
    int current();

    /**
     * Перемещает внутренний указатель на следующий элемент, если он есть, и возвращает TRUE. Если
     * следующего элемента нет, то возвращает FALSE. При этом внутренний указатель начинает ссылаться
     * на NULL.
     */
    bool moveNext();
};

#endif //QUEUE_QUEUE_H
