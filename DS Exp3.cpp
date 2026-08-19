#include <iostream>
#include <string>

using namespace std;

struct Song {
    string title;
    Song* prev;
    Song* next;

    Song(string t)
        : title(t), prev(nullptr), next(nullptr) {}
};

class Playlist {
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    // Constructor
    Playlist()
        : head(nullptr), tail(nullptr), current(nullptr) {}

    // Add a song
    void addSong(string t) {
        Song* newSong = new Song(t);

        if (head == nullptr) {
            head = tail = current = newSong;
        }
        else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
    }

    // Move to next song
    void nextSong() {
        if (current != nullptr && current->next != nullptr) {
            current = current->next;

            cout << "Now playing: "
                 << current->title << endl;
        }
        else {
            cout << "Already at the last song." << endl;
        }
    }

    // Move to previous song
    void previousSong() {
        if (current != nullptr && current->prev != nullptr) {
            current = current->prev;

            cout << "Now playing: "
                 << current->title << endl;
        }
        else {
            cout << "Already at the first song." << endl;
        }
    }

    // Display forward
    void displayForward() {
        Song* temp = head;

        cout << "\nPlaylist (Forward):" << endl;

        while (temp != nullptr) {
            cout << temp->title << endl;
            temp = temp->next;
        }
    }

    // Display backward
    void displayBackward() {
        Song* temp = tail;

        cout << "\nPlaylist (Backward):" << endl;

        while (temp != nullptr) {
            cout << temp->title << endl;
            temp = temp->prev;
        }
    }
    
    //show current
    void showCurrent(){
    	if(current == nullptr){
    		cout<< "No Song Is Currently Playing \n";
		}
		else{
			cout<< "currently Playing:"<<current->title<<endl;
		}
	}

    // Destructor
    ~Playlist() {
        Song* currentSong = head;

        while (currentSong != nullptr) {
            Song* nextSong = currentSong->next;

            delete currentSong;

            currentSong = nextSong;
        }
    }
};

int main() {

    Playlist playlist;

    playlist.addSong("Song 1");
    playlist.addSong("Song 2");
    playlist.addSong("Song 3");
    playlist.addSong("Song 4");
    playlist.addSong("Song 5");

    playlist.displayForward();
    cout<<"\n";
    playlist.showCurrent();
	playlist.displayBackward();
	cout<<"\n";
	playlist.showCurrent();

    cout << "\nMoving Forward";

    playlist.nextSong();
    playlist.nextSong();
	cout<<"\n";
	
    cout << "\nMoving Backward";
    playlist.previousSong();
    playlist.previousSong();
    cout<<"\n";
    
    playlist.nextSong();

    return 0;
}