#ifndef QUEUE_ITERATOR_H
#define QUEUE_ITERATOR_H

/**
 * ��������� ��� ������� ���������� ��� ��������, ������� ����� ��������� ���� �������
 */
class Iterator {
public:
    virtual void reset() = 0;
    virtual int current() = 0;
    virtual bool moveNext() = 0;
};

#endif //QUEUE_ITERATOR_H
