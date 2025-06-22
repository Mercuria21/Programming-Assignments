#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::vector;

class Task {
private:
    string description;
    bool completed;
public:
    Task(const string& desc) : description(desc), completed(false) {}

    void markComplete() { completed = true; }
    bool isComplete() const { return completed; }

    string getDescription() const { return description; }

    void display(int index) const {
        cout << index << ". [" << (completed ? 'X' : ' ') << "] " << description << "\n";
    }
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(const string& desc) {
        tasks.emplace_back(desc);
        cout << "Task added.\n";
    }


void completeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markComplete();
            cout << "Task marked as completed.\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }

    void listTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }
        for (int i = 0; i < tasks.size(); ++i) {
            tasks[i].display(i);
        }
    }
};

int main() {
    TaskManager manager;
    int choice;
    string input;

    do {
        cout << "\n==== Task Manager ====\n";
        cout << "1. Add Task\n";
        cout << "2. Complete Task\n";
        cout << "3. List Tasks\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // clear newline

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(std::cin, input);
                manager.addTask(input);
                break;
            case 2:
                cout << "Enter task number to complete: ";
                int index;
                cin >> index;
                manager.completeTask(index);
                break;
            case 3:
                manager.listTasks();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 0);

    return 0;
}
