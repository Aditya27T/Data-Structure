#include <iostream>
#include <stack>
#include <string>
#include <limits>

using namespace std;

struct Note {
    string name;
    string content;
};

typedef stack<Note> NoteStack;

void push(NoteStack& notes) {
    if (notes.size() >= 10) {
        cout << "The stack is full. Cannot add more notes." << endl;
        return;
    }

    Note newNote;
    cout << "Enter a name for the note: ";
    getline(cin, newNote.name);
    cout << "Enter the note content: ";
    getline(cin, newNote.content);
    notes.push(newNote);
    cout << "Note added successfully." << endl;
}

void pop(NoteStack& notes) {
    if (notes.empty()) {
        cout << "The stack is empty. Cannot remove any note." << endl;
        return;
    }

    notes.pop();
    cout << "Note removed successfully." << endl;
}

void display(NoteStack& notes) {
    if (notes.empty()) {
        cout << "The stack is empty. No notes to display." << endl;
        return;
    }

    NoteStack temp;
    int count = 1;
    while (!notes.empty()) {
        temp.push(notes.top());
        notes.pop();
    }

    while (!temp.empty()) {
        Note note = temp.top();
        cout << "Note " << count << ":" << endl;
        cout << "Name: " << note.name << endl;
        cout << "Content: " << note.content << endl;
        cout << endl;
        notes.push(note);
        temp.pop();
        count++;
    }
}

int main() {
    NoteStack notes;
    int choice;

    do {
        cout << "1. Add a note" << endl;
        cout << "2. Remove a note" << endl;
        cout << "3. Display all notes" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                push(notes);
                break;
            case 2:
                pop(notes);
                break;
            case 3:
                display(notes);
                break;
            case 4:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}