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
 * ��������� � ����� ������� ����� ������� (�����)
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
 * ���������� �� ������ ������� ������ (���������) ������� (�����) � ������� ��� �� �������
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
 * ������� �������
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
 * ���������� TRUE, ���� ������� � ������ ������ �����
 */
bool Queue::isEmpty() {
    return _firstItem == NULL;
}

/**
 * ���������� ���������� ��������� �������� ��������. ���������� ��������� ��������� �� NULL, ���
 * ��� �� ������������� ��������, ��������������� �������. ��� ��������� � ������� �������� �����
 * ���� ��� ������� ::moveNext()
 */
void Queue::reset() {
    _currentItem = NULL;
}

/**
 * ���������� ����� �� �������� �������� � ���������
 */
int Queue::current() {
    if (_currentItem == NULL) {
        throw runtime_error("There's no current item");
    }
    return _currentItem->number;
}

/**
 * ���������� ���������� ��������� �� ��������� �������, ���� �� ����, � ���������� TRUE. ����
 * ���������� �������� ���, �� ���������� FALSE. ��� ���� ���������� ��������� �������� ���������
 * �� NULL.
 */
bool Queue::moveNext() {
    _currentItem = _currentItem != NULL ? _currentItem->nextItem : _firstItem;
    return _currentItem != NULL;
}
