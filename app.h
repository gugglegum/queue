#ifndef QUEUE_APP_H
#define QUEUE_APP_H

#include "queue.h"
#include "queue_ui.h"

using namespace std;

/**
 * ����� ����������: �������������, ������, �����������
 */
class App {
private:
    /**
     * ������ �� ��������� �������
     */
    Queue* _queue;

    /**
     * ������ �� ��������� UI, ����������� �������������� ����������� � ::_queue
     */
    QueueUI* _ui;

public:

    /**
     * �����������
     */
    App();
    /**
     * ���������� (������� ���������� ������� � UI)
     */
    ~App();

    /**
     * ������ ���������
     */
    void run();
};

#endif //QUEUE_APP_H
