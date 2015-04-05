#ifndef QUEUE_QUEUE_UI_H
#define QUEUE_QUEUE_UI_H

#include "iqueue.h"

using namespace std;

class QueueUI {
private:

    /**
     * ������ �� ��������� �������, � ������� ��������� ����������� �����������
     */
    IQueue* _queue;

    /**
     * ������� ������ ��������� ������
     */
    void _printHelp();

    /**
     * ����������� ���� ����� ������������� � ���������� ��� �����
     */
    int _inputNumber();

public:

    /**
     * �����������. ��������� �� ���� ��������� �������, � ������� ��������� ����������� �����������,
     * � ��������� ��� �� ���������� �������� _queue.
     */
    QueueUI(IQueue* queue);

    /**
     * �������� ��������� ����: ����� ����� � ����������, ���������� ������, ����� �����������
     */
    void lifecycle();

};

#endif //QUEUE_QUEUE_UI_H
