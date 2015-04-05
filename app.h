#ifndef QUEUE_APP_H
#define QUEUE_APP_H

#include "queue.h"
#include "queue_ui.h"

using namespace std;

/**
 *  ласс приложени€: инициализаци€, запуск, финализаци€
 */
class App {
private:
    /**
     * —сылка на экземпл€р очереди
     */
    Queue* _queue;

    /**
     * —сылка на экземпл€р UI, позвол€ющий манипулировать экземпл€ром в ::_queue
     */
    QueueUI* _ui;

public:

    /**
     *  онструктор
     */
    App();
    /**
     * ƒеструктор (удал€ет экземпл€ры очереди и UI)
     */
    ~App();

    /**
     * «апуск программы
     */
    void run();
};

#endif //QUEUE_APP_H
