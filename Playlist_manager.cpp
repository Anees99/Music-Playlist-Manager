#include <iostream>
#include <string>

using namespace std;

// Node structure for doubly linked list
struct Node {
    string title;   // Song title
    Node* prev;     // Pointer to the previous node
    Node* next;     // Pointer to the next node
};

// Music Playlist Manager class
class MusicPlaylistManager {
private:
    Node* head;     // Pointer to the head of the list
    Node* tail;     // Pointer to the tail of the list

public:
    // Constructor to initialize an empty playlist
    MusicPlaylistManager() {
        head = NULL;
        tail = NULL;
    }

    // Insert a new song at the end of the playlist
    void insert(const string& title) {
        Node* newNode = new Node();
        newNode->title = title;
        newNode->prev = tail;
        newNode->next = NULL;

        if (tail != NULL) {
            tail->next = newNode;
        } else {
            head = newNode;
        }

        tail = newNode;
        cout << "Inserted: " << title << endl;
    }

    // Delete a song from the playlist
    void deleteSong(const string& title) {
        Node* curr = head;
        while (curr != NULL) {
            if (curr->title == title) {
                if (curr->prev != NULL) {
                    curr->prev->next = curr->next;
                } else {
                    head = curr->next;
                }

                if (curr->next != NULL) {
                    curr->next->prev = curr->prev;
                } else {
                    tail = curr->prev;
                }

                delete curr;
                cout << "Deleted: " << title << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "Song not found: " << title << endl;
    }

    // Play the current song
    void play() {
        if (head != NULL) {
            cout << "Playing: " << head->title << endl;
        } else {
            cout << "Playlist is empty." << endl;
        }
    }

    // Print the playlist
    void print() {
        Node* curr = head;
        if (curr == NULL) {
            cout << "Playlist is empty." << endl;
            return;
        }

        cout << "Current Playlist:" << endl;
        while (curr != NULL) {
            cout << " - " << curr->title << endl;
            curr = curr->next;
        }
    }

    // Destructor to clean up the memory
    ~MusicPlaylistManager() {
        Node* curr = head;
        while (curr != NULL) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        cout << "Playlist cleared." << endl;
    }
};

int main() {
    MusicPlaylistManager playlist;

    cout << "==================================" << endl;
    cout << "Adding songs to the playlist..." << endl;
    cout << "==================================" << endl;
    playlist.insert("Song 1");
    playlist.insert("Song 2");
    playlist.insert("Song 3");

    cout << "\n==================================" << endl;
    cout << "Printing the playlist:" << endl;
    cout << "==================================" << endl;
    playlist.print();

    cout << "\n==================================" << endl;
    cout << "Deleting 'Song 2' from the playlist..." << endl;
    cout << "==================================" << endl;
    playlist.deleteSong("Song 2");

    cout << "\n==================================" << endl;
    cout << "Printing the playlist after deletion:" << endl;
    cout << "==================================" << endl;
    playlist.print();

    cout << "\n==================================" << endl;
    cout << "Playing the current song:" << endl;
    cout << "==================================" << endl;
    playlist.play();

    return 0;
}

