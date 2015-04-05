#include <iostream>
#include <c++/stdexcept>
#include "queue_ui.h"

using namespace std;

/**
 * �����������. ��������� �� ���� ��������� �������, � ������� ��������� ����������� �����������,
 * � ��������� ��� �� ���������� �������� _queue.
 */
QueueUI::QueueUI(IQueue* queue) {
_queue = queue;
}

/**
 * ������� ������ ��������� ������
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
 * ����������� ���� ����� ������������� � ���������� ��� �����. ���� ������������
 * ��� �� �����, �� ������� ��������� �� ������ � ����� ����������� �����. ���
 * ������������ �� ��� ���, ���� ������������ ������� �� ����� �����.
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
 * �������� ��������� ����: ����� ����� � ����������, ���������� ������, ����� �����������
 */
void QueueUI::lifecycle() {
    // � ������ ���������� ����� ������� ������� ������������ ��������� �� ��������� ��������
    _printHelp();

    // ����������� ���� ��������� � ��������� ������ �� ������������
    while (true) {
        string cmd;
        cout << "Enter command: ";
        cin >> cmd;

        try {
            // ������� "put"
            if (cmd == "put") {
                _queue->put(_inputNumber());
                continue;
            }

            // ������� "get"
            if (cmd == "get") {
                int number = _queue->get();
                cout << "Next number is: " << number << endl;
                continue;
            }

            // ������� "dump"
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

            // ������� "clear"
            if (cmd == "clear") {
                _queue->clear();
                cout << "The queue has been cleared" << endl;
                continue;
            }

            // ������� "help"
            if (cmd == "help") {
                _printHelp();
                continue;
            }

            // ������� "exit"
            if (cmd == "exit") {
                break;
            }

            // ���� �� ����� �� ���� -- ������ ���� �� ��������� ��� ��������� �������
            throw runtime_error("Unrecognized command \"" + cmd + "\"");
        } catch (exception& e) {
            // ���� �������� ���������� -- ������� ����� ���������� � stderr
            cerr << "ERROR: " << e.what() << endl;
        }
    }
}
