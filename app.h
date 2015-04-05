#ifndef QUEUE_APP_H
#define QUEUE_APP_H

#include "queue.h"
#include "queue_ui.h"

using namespace std;

/**
 * Класс приложения: инициализация, запуск, финализация
 */
class App {
private:
    /**
     * Ссылка на экземпляр очереди
     */
    Queue* _queue;

    /**
     * Ссылка на экземпляр UI, позволяющий манипулировать экземпляром в ::_queue
     */
    QueueUI* _ui;

public:

    /**
     * Конструктор
     */
    App();
    /**
     * Деструктор (удаляет экземпляры очереди и UI)
     */
    ~App();

    /**
     * Запуск программы
     */
    void run();
};

#endif //QUEUE_APP_H
