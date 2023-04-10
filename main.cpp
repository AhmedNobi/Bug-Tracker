#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a Bug struct to hold information about each bug
struct Bug {
    string title;
    string description;
    string status;
    string priority;
    string severity;
    string assignee;
};

// Define a BugTracker class to manage the bugs
class BugTracker {
public:
    // Method to add a new bug to the system
    void addBug(const string& title, const string& description,
                const string& status, const string& priority,
                const string& severity) {
        Bug bug = {title, description, status, priority, severity};
        m_bugs.push_back(bug);
    }

    // Method to update the status of an existing bug
    void updateBugStatus(int index, const string& newStatus) {
        m_bugs[index].status = newStatus;
    }

    // Method to assign a bug to a team member
    void assignBug(int index, const string& assignee) {
        m_bugs[index].assignee = assignee;
    }

    // Method to search for bugs based on various criteria
    vector<Bug> searchBugs(const string& status, const string& priority,
                                const string& severity) {
        vector<Bug> results;
        for (const auto& bug : m_bugs) {
            if ((status.empty() || bug.status == status) &&
                (priority.empty() || bug.priority == priority) &&
                (severity.empty() || bug.severity == severity)) {
                results.push_back(bug);
            }
        }
        return results;
    }

    // Method to generate a report on the bugs in the system
    void generateReport() {
        cout << "Bug report:" << endl;
        for (const auto& bug : m_bugs) {
            cout << "Title: " << bug.title << endl;
            cout << "Description: " << bug.description << endl;
            cout << "Status: " << bug.status << endl;
            cout << "Priority: " << bug.priority << endl;
            cout << "Severity: " << bug.severity << endl;
            cout << endl;
        }
    }

private:
    vector<Bug> m_bugs;
};

int main() {
    BugTracker tracker;

    while (true) {
        // Print the menu
        cout << "Bug Tracker Menu:" << endl;
        cout << "1. Add bug" << endl;
        cout << "2. Update bug status" << endl;
        cout << "3. Assign bug" << endl;
        cout << "4. Search bugs" << endl;
        cout << "5. Generate report" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        // Get the user's choice
        int choice;
        cin >> choice;

        // Process the user's choice
        switch (choice) {
            case 1: {
                string title, description, status, priority, severity;
                cout << "Enter bug";
                cout << "Title: ";
                cin.ignore(); // Ignore any leftover newline character
                getline(cin, title);
                cout << "Description: ";
                getline(cin, description);
                cout << "Status: ";
                getline(cin, status);
                cout << "Priority: ";
                getline(cin, priority);
                cout << "Severity: ";
                getline(cin, severity);
                tracker.addBug(title, description, status, priority, severity);
                cout << "Bug added successfully!" << endl;
                break;
            }
            case 2: {
                int index;
                string newStatus;
                cout << "Enter the index of the bug to update: ";
                cin >> index;
                cout << "Enter the new status: ";
                cin.ignore(); // Ignore any leftover newline character
                getline(cin, newStatus);
                tracker.updateBugStatus(index, newStatus);
                cout << "Bug status updated successfully!" << endl;
                break;
            }
            case 3: {
                int index;
                string assignee;
                cout << "Enter the index of the bug to assign: ";
                cin >> index;
                cout << "Enter the name of the assignee: ";
                cin.ignore(); // Ignore any leftover newline character
                getline(cin, assignee);
                tracker.assignBug(index, assignee);
                cout << "Bug assigned successfully!" << endl;
                break;
            }
            case 4: {
                string status, priority, severity;
                cout << "Enter status (leave blank to ignore): ";
                getline(cin, status);
                cout << "Enter priority (leave blank to ignore): ";
                getline(cin, priority);
                cout << "Enter severity (leave blank to ignore): ";
                getline(cin, severity);
                vector<Bug> results = tracker.searchBugs(status, priority, severity);
                cout << "Search results:" << endl;
                for (const auto& bug : results) {
                    cout << "Title: " << bug.title << endl;
                    cout << "Description: " << bug.description << endl;
                    cout << "Status: " << bug.status << endl;
                    cout << "Priority: " << bug.priority << endl;
                    cout << "Severity: " << bug.severity << endl;
                    cout << endl;
                }
                break;
            }
            case 5: {
                tracker.generateReport();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
    return 0;
}
