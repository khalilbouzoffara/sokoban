#ifndef MUSIC_H
#define MUSIC_H

#include <SFML/Audio.hpp>

using namespace sf;

class Music
{
private:
    bool playing;
    //Music bmusic;
    SoundBuffer soundBuffer;
    Sound sound;
    int elementtype;
public:
    music(bool, int);
    void switcher();
    void play();
    void stop();
};

#endif // MUSIC_H
