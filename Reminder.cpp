#include <iostream>
#include <ctime>
#include <vector>

struct Reminder {
    std::tm datetime;
    std::string message;
};

std::vector<Reminder> reminders;

void showCurrentDateTime() {
    std::time_t now = std::time(nullptr);
    std::tm currentDateTime = *std::localtime(&now);
    
    std::cout << "Current Date and Time: ";
    std::cout << currentDateTime.tm_year + 1900 << '-'
              << currentDateTime.tm_mon + 1 << '-'
              << currentDateTime.tm_mday << ' '
              << currentDateTime.tm_hour << ':'
              << currentDateTime.tm_min << ':'
              << currentDateTime.tm_sec << std::endl;
}

void setReminder() {
    Reminder reminder;
    
    std::cout << "Enter date and time for the reminder (YYYY MM DD HH MM SS): ";
    std::cin >> reminder.datetime.tm_year >> reminder.datetime.tm_mon
             >> reminder.datetime.tm_mday >> reminder.datetime.tm_hour
             >> reminder.datetime.tm_min >> reminder.datetime.tm_sec;
    
    std::cin.ignore(); // Clear newline character from the input buffer
    
    std::cout << "Enter reminder message: ";
    std::getline(std::cin, reminder.message);
    
    reminders.push_back(reminder);
    
    std::cout << "Reminder set successfully!" << std::endl;
}

void listReminders() {
    if (reminders.empty()) {
        std::cout << "No reminders set." << std::endl;
        return;
    }
    
    std::cout << "Reminders:" << std::endl;
    int index = 1;
    for (const Reminder& reminder : reminders) {
        std::cout << index << ". Date and Time: " << reminder.datetime.tm_year + 1900 << '-'
                  << reminder.datetime.tm_mon + 1 << '-'
                  << reminder.datetime.tm_mday << ' '
                  << reminder.datetime.tm_hour << ':'
                  << reminder.datetime.tm_min << ':'
                  << reminder.datetime.tm_sec << std::endl;
        std::cout << "   Message: " << reminder.message << std::endl;
        index++;
    }
}

int main() {
    int choice;
    
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Show Current Date and Time\n";
        std::cout << "2. Set Reminder\n";
        std::cout << "3. List Reminders\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                showCurrentDateTime();
                break;
            case 2:
                setReminder();
                break;
            case 3:
                listReminders();
                break;
            case 4:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
    
    return 0;
}
