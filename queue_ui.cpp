#include <iostream>
#include <c++/stdexcept>
#include "queue_ui.h"

using namespace std;

/**
 * Конструктор. Принимает на вход экземпляр очереди, с которой предстоит производить манипуляции,
 * и сохраняет его во внутреннее свойство _queue.
 */
QueueUI::QueueUI(IQueue* queue) {
_queue = queue;
}

/**
 * Выводит список доступных команд
 */
void QueueUI::_printHelp() {
    cout << "Available commands:" << endl << endl;
    cout << "put      Put number to queue" << endl;
    cout << "get      Pop number from queue" << endl;
    cout << "dump     Dump current queue" << endl;
    cout << "clear    Clear queue" << endl;
    cout << "help     Print help" << endl;
    cout << "exit     Exit (or press Ctrl-C)" << endl << endl;
};

/**
 * Запрашивает ввод числа пользователем и возвращает это число. Если пользователь
 * ввёл не число, то выводит сообщение об ошибке и снова запрашивает число. Так
 * продолжается до тех пор, пока пользователь наконец не введёт число.
 */
int QueueUI::_inputNumber() {
    int number;
    do {
        cout << "Number: ";
        cin >> number;
        if (cin.fail()) {
            cerr << "Invalid input, try again." << endl;
            cin.clear();
            cin.sync();
        } else {
            break;
        }
    } while (true);
    return number;
}

/**
 * Основной жизненный цикл: опрос ввода с клавиатуры, выполнение команд, вывод результатов
 */
void QueueUI::lifecycle() {
    // В начале жизненного цикла неплохо вывести пользователю подсказку по доступным командам
    _printHelp();

    // Бесконечный цикл получения и обработки команд от пользователя
    while (true) {
        string cmd;
        cout << "Enter command: ";
        cin >> cmd;

        try {
            // Команда "put"
            if (cmd == "put") {
                _queue->put(_inputNumber());
                continue;
            }

            // Команда "get"
            if (cmd == "get") {
                int number = _queue->get();
                cout << "Next number is: " << number << endl;
                continue;
            }

            // Команда "dump"
            if (cmd == "dump") {
                if (! _queue->isEmpty()) {
                    int counter = 1;
                    _queue->reset();
                    while (_queue->moveNext()) {
                        cout << counter << ": " << _queue->current() << endl;
                        counter++;
                    }
                } else {
                    cout << "There's no items in the queue" << endl;
                }
                continue;
            }

            // Команда "clear"
            if (cmd == "clear") {
                _queue->clear();
                cout << "The queue has been cleared" << endl;
                continue;
            }

            // Команда "help"
            if (cmd == "help") {
                _printHelp();
                continue;
            }

            // Команда "exit"
            if (cmd == "exit") {
                break;
            }

            // Если мы дошли до сюда -- значит ввод не распознан как известная команда
            throw runtime_error("Unrecognized command \"" + cmd + "\"");
        } catch (exception& e) {
            // Если возникло исключение -- выводим текст исключения в stderr
            cerr << "ERROR: " << e.what() << endl;
        }
    }
}
