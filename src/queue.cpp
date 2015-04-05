#include <iostream>
#include <stdexcept>
#include "queue.h"

using namespace std;

Queue::Queue() {
    _firstItem = NULL;
    _lastItem = NULL;
    _currentItem = NULL;
    clear();
}

Queue::~Queue() {
    clear();
}

/**
 * Добавляет в конец очереди новый элемент (число)
 */
void Queue::put(int number) {
    QueueItem* item = new QueueItem;
    item->number = number;
    if (_firstItem == NULL) {
        _firstItem = item;
    }
    if (_lastItem != NULL) {
        _lastItem->nextItem = item;
    }
    _lastItem = item;
}

/**
 * Возвращает из начала очереди первый (следующий) элемент (число) и удаляет его из
 * очереди
 */
int Queue::get() {
    if (_firstItem == NULL) {
        throw runtime_error("There's no items in the queue");
    }
    QueueItem* item = _firstItem;
    int number = item->number;
    _firstItem = item->nextItem;
    if (item->nextItem == NULL) {
        _lastItem = NULL;
    }
    if (_currentItem == item) {
        _currentItem = NULL;
    }
    delete item;
    return number;
}

/**
 * Очищает очередь
 */
void Queue::clear() {
    QueueItem* item = _firstItem;
    QueueItem* nextItem;
    while (item != NULL) {
        nextItem = item->nextItem;
        delete item;
        item = nextItem;
    }
    _firstItem = NULL;
    _lastItem = NULL;
    _currentItem = NULL;
}

/**
 * Возвращает TRUE, если очередь в данный момент пуста
 */
bool Queue::isEmpty() {
    return _firstItem == NULL;
}

/**
 * Сбрасывает внутренний указатель текущего элемента. Сброшенный указатель ссылается на
 * NULL, что как бы соответствует элементу, предшествующему первому. Для обращения к
 * первому элементу нужно один раз вызвать ::moveNext()
 */
void Queue::reset() {
    _currentItem = NULL;
}

/**
 * Возвращает число из текущего элемента в итераторе
 */
int Queue::current() {
    if (_currentItem == NULL) {
        throw runtime_error("There's no current item");
    }
    return _currentItem->number;
}

/**
 * Перемещает внутренний указатель на следующий элемент, если он есть, и возвращает TRUE.
 * Если следующего элемента нет, то возвращает FALSE. При этом внутренний указатель
 * начинает ссылаться на NULL.
 */
bool Queue::moveNext() {
    _currentItem = _currentItem != NULL ? _currentItem->nextItem : _firstItem;
    return _currentItem != NULL;
}
