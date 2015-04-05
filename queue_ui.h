#ifndef QUEUE_QUEUE_UI_H
#define QUEUE_QUEUE_UI_H

#include "iqueue.h"

using namespace std;

class QueueUI {
private:

    /**
     * Ссылка на экземпляр очереди, С которой предстоит производить манипуляции
     */
    IQueue* _queue;

    /**
     * Выводит список доступных команд
     */
    void _printHelp();

    /**
     * Запрашивает ввод числа пользователем и возвращает это число
     */
    int _inputNumber();

public:

    /**
     * Конструктор. Принимает на вход экземпляр очереди, с которой предстоит производить манипуляции,
     * и сохраняет его во внутреннее свойство _queue.
     */
    QueueUI(IQueue* queue);

    /**
     * Основной жизненный цикл: опрос ввода с клавиатуры, выполнение команд, вывод результатов
     */
    void lifecycle();

};

#endif //QUEUE_QUEUE_UI_H
