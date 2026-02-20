#include <iostream>
using namespace std;
// Complex System Components
class TV {
public:
   void on() {
      cout << "TV is ON" << endl;
   }
   void off() {
      cout << "TV is OFF" << endl;
   }
};
class SoundSystem {
public:
   void on() {
      cout << "Sound System is ON" << endl;
   }
   void off() {
      cout << "Sound System is OFF" << endl;
   }
};
class DVDPlayer {
public:
   void on() {
      cout << "DVD Player is ON" << endl;
   }
   void off() {
      cout << "DVD Player is OFF" << endl;
   }
   void play(string movie) {
      cout << "Playing movie: " << movie << endl;
   }
};
// Facade
class HomeTheaterFacade {
private:
   TV* tv;
   SoundSystem* soundSystem;
   DVDPlayer* dvdPlayer;
public:
   HomeTheaterFacade(TV* t, SoundSystem* s, DVDPlayer* d
) : tv(t), soundSystem(s), dvdPlayer(d) {}
   void watchMovie(string movie) {
      cout << "Get ready to watch a movie..." << endl;
      tv->on();
      soundSystem->on();
      dvdPlayer->on();
      dvdPlayer->play(movie);
   }
   void endMovie() {
      cout << "Shutting down the home theater..." << endl;
      dvdPlayer->off();
      soundSystem->off();
      tv->off();
   }
};
// Client
int main() {
   TV* tv = new TV();
   SoundSystem* soundSystem = new SoundSystem();
   DVDPlayer* dvdPlayer = new DVDPlayer();
   HomeTheaterFacade* homeTheater = new HomeTheaterFacade(tv, soundSystem, dvdPlayer);
   homeTheater->watchMovie("Inception");
   homeTheater->endMovie();
   delete homeTheater;
   delete tv;
   delete soundSystem;
   delete dvdPlayer;
   return 0;
}