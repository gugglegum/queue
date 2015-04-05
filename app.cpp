#include <iostream>
#include "app.h"

using namespace std;

/**
 * Конструктор (создаёт экземпляры очереди и UI)
 */
App::App() {
    _queue = new Queue();
    _ui = new QueueUI(_queue);
}

/**
 * Деструктор (удаляет экземпляры очереди и UI)
 */
App::~App() {
    delete(_ui);
    delete(_queue);
}

/**
 * Запуск программы (сводится к запуску жизненного цикла в UI)
 */
void App::run() {
    cout << "QUEUE DEMO" << endl;
    cout << "==========" << endl << endl;

    _ui->lifecycle();
}
