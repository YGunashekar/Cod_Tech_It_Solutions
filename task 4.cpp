#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function prototypes
void addTask(vector<Task>& taskList, const string& description);
void viewTasks(const vector<Task>& taskList);
void markTaskAsCompleted(vector<Task>& taskList, int index);
void removeTask(vector<Task>& taskList, int index);

int main() {
    vector<Task> taskList;
    string input;

    while (true) {
        cout << "Options:" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Mark task as completed" << endl;
        cout << "4. Remove task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        getline(cin, input);

        if (input == "1") {
            cout << "Enter task description: ";
            getline(cin, input);
            addTask(taskList, input);
        } else if (input == "2") {
            viewTasks(taskList);
        } else if (input == "3") {
            int index;
            cout << "Enter the index of the task to mark as completed: ";
            cin >> index;
            cin.ignore(); // Ignore the newline character left in the input buffer
            markTaskAsCompleted(taskList, index);
        } else if (input == "4") {
            int index;
            cout << "Enter the index of the task to remove: ";
            cin >> index;
            cin.ignore(); // Ignore the newline character left in the input buffer
            removeTask(taskList, index);
        } else if (input == "5") {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void addTask(vector<Task>& taskList, const string& description) {
    taskList.push_back(Task(description));
    cout << "Task added successfully." << endl;
}

void viewTasks(const vector<Task>& taskList) {
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < taskList.size(); ++i) {
        cout << i + 1 << ". " << taskList[i].description << " - " << (taskList[i].completed ? "Completed" : "Pending") << endl;
    }
}

void markTaskAsCompleted(vector<Task>& taskList, int index) {
    if (index >= 1 && index <= taskList.size()) {
        taskList[index - 1].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void removeTask(vector<Task>& taskList, int index) {
    if (index >= 1 && index <= taskList.size()) {
        taskList.erase(taskList.begin() + index - 1);
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

