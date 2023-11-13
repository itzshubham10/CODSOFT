#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

// Function prototypes
void displayMenu();
void addTask(std::vector<Task>& taskList);
void viewTasks(const std::vector<Task>& taskList);
void markAsCompleted(std::vector<Task>& taskList);
void removeTask(std::vector<Task>& taskList);

int main() {
    std::vector<Task> taskList;

    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(taskList);
                break;
            case 2:
                viewTasks(taskList);
                break;
            case 3:
                markAsCompleted(taskList);
                break;
            case 4:
                removeTask(taskList);
                break;
            case 5:
                std::cout << "Exiting the to-do list manager. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
        }

    } while (choice != 5);

    return 0;
}

void displayMenu() {
    std::cout << "TO-DO LIST MANAGER" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. View Tasks" << std::endl;
    std::cout << "3. Mark Task as Completed" << std::endl;
    std::cout << "4. Remove Task" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

void addTask(std::vector<Task>& taskList) {
    std::string description;
    std::cout << "Enter task description: ";
    std::cin.ignore(); // Ignore any previous newline character
    std::getline(std::cin, description);

    taskList.push_back(Task(description));
    std::cout << "Task added successfully!" << std::endl;
}

void viewTasks(const std::vector<Task>& taskList) {
    std::cout << "TO-DO LIST:" << std::endl;

    for (size_t i = 0; i < taskList.size(); ++i) {
        std::cout << i + 1 << ". " << (taskList[i].completed ? "[X] " : "[ ] ") << taskList[i].description << std::endl;
    }

    if (taskList.empty()) {
        std::cout << "No tasks found." << std::endl;
    }
}

void markAsCompleted(std::vector<Task>& taskList) {
    viewTasks(taskList);

    if (!taskList.empty()) {
        int index;
        std::cout << "Enter the task number to mark as completed: ";
        std::cin >> index;

        if (index >= 1 && static_cast<size_t>(index) <= taskList.size()) {
            taskList[index - 1].completed = true;
            std::cout << "Task marked as completed!" << std::endl;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }
}

void removeTask(std::vector<Task>& taskList) {
    viewTasks(taskList);

    if (!taskList.empty()) {
        int index;
        std::cout << "Enter the task number to remove: ";
        std::cin >> index;

        if (index >= 1 && static_cast<size_t>(index) <= taskList.size()) {
            taskList.erase(taskList.begin() + index - 1);
            std::cout << "Task removed successfully!" << std::endl;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }
}
