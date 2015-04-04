#include <iostream>
#include <c++/stdexcept>

using namespace std;

/**
 * Интерфейс очереди
 */
class IQueue {
public:
    virtual void put(int number) = 0;
    virtual int get() = 0;
    virtual void clear() = 0;
};

class Queue : public IQueue
{
private:
    int* _nextItem = NULL;

    void put(int number) {

    }

    int get() {
        return 1;
    }

    void clear() {

    }

};

class QueueUI {
private:
    IQueue* _queue;

    /**
     * Выводит список доступных команд
     */
    void _printHelp() {
        cout << "put      Push number to queue" << endl;
        cout << "get      Pop number from queue" << endl;
        cout << "dump     Dump current queue" << endl;
        cout << "clear    Clear queue" << endl;
        cout << "help     Print help" << endl;
        cout << "exit     Exit (or press Ctrl-C)" << endl;
    };
public:
    QueueUI(IQueue* queue) {
        _queue = queue;
    }

    void lifecycle() {
        _printHelp();
        string cmd;
        while (true) {
            cout << "Enter command: ";
            cin >> cmd;

            try {
                if (cmd == "put") {
                    cout << "Number: ";
                    int number;
                    cin >> number;
                    _queue->put(number);
                    continue;
                }
                if (cmd == "get") {
                    int number = _queue->get();
                    cout << "Next number is " << number << endl;
                    continue;
                }
                if (cmd == "dump") {
//                    int count = _stack->getCount();
//                    if (count != 0) {
//                        for (int i = 0; i < count; i++) {
//                            cout << i << ": " << *_stack->getItem(i) << endl;
//                        }
//                    } else {
//                        cout << "There's no items in the stack" << endl;
//                    }
                    continue;
                }
                if (cmd == "clear") {
                    _queue->clear();
                    continue;
                }
                if (cmd == "help") {
                    _printHelp();
                    continue;
                }
                if (cmd == "exit") {
                    break;
                }

                throw runtime_error("Unrecognized command \"" + cmd + "\"");
            } catch (exception& e) {
                cerr << "ERROR: " << e.what() << endl;
            }
        }
    }
};

class App {
private:
    Queue* _queue;
    QueueUI* _ui;

public:
    App() {
        _queue = new Queue();
        _ui = new QueueUI(_queue);
    }
    void run() {
        (*_ui).lifecycle();
    }
    ~App() {
        delete(_ui);
        delete(_queue);
    }
};

int main() {
    App app;
    app.run();
    return 0;
}
