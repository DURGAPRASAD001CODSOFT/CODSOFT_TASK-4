#include <iostream>
#include <vector>
using namespace std;
#include <string>

struct Task {
   string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.emplace_back(description);
        cout << "Task added: " << description <<endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks found." <<endl;
        } else {
            cout << "Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
              cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << endl;
            }
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed: " << tasks[index - 1].description << std::endl;
        } else {
             cout << "Invalid task index." << endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            cout << "Task removed: " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
               cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    ToDoList toDoList;

    while (true) {
        cout << "\nMenu:\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        int choice;
          cout << "Enter your choice: ";
          cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore();
                getline(std::cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                size_t index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                toDoList.markTaskAsCompleted(index);
                break;
            }
            case 4: {
                size_t index;
                cout << "Enter task index to remove: ";
                cin >> index;
                toDoList.removeTask(index);
                break;
            }
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
