#include <iostream>
#include "app.h"

using namespace std;

/**
 * ����������� (������ ���������� ������� � UI)
 */
App::App() {
    _queue = new Queue();
    _ui = new QueueUI(_queue);
}

/**
 * ���������� (������� ���������� ������� � UI)
 */
App::~App() {
    delete(_ui);
    delete(_queue);
}

/**
 * ������ ��������� (�������� � ������� ���������� ����� � UI)
 */
void App::run() {
    cout << "QUEUE DEMO" << endl;
    cout << "==========" << endl << endl;

    _ui->lifecycle();
}
