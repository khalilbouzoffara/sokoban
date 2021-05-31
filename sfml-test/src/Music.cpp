/*#include "Music.h"
#include <iostream>
Music::Music(bool sounds, int element)
{

    elementtype = element;
    if (elementtype == 1)
    {
        if (!bmusic.openFromFile("audio/sanfara-jay-yeh-ft-ala.mp3"))
        {
            std::cout << "Error loading background music file" << std::endl;
        }
        playing = sounds;
        bmusic.setLoop(true);
        bmusic.setPosition(0, 0, 0); // change its 3D position
        bmusic.setVolume(50);
        if (playing) play();
    }
    else if (elementtype == 2)
    {
        if (!soundBuffer.loadFromFile("audio/slide.ogg"))
        {
            std::cout << "Error opening slide music file" << std::endl;
        }
        playing = sounds;
        sound.setBuffer(soundBuffer);
        sound.setLoop(false);
        sound.setPosition(0, 0, 0); // change its 3D position
        sound.setVolume(50);
    }
}

void Music::switcher()
{
    if (playing)
    {
        //Switch to off
        playing = false;
        stop();
    }
    else
    {
        //Switch to on
        playing = true;
        if (elementtype == 1)
            play();
    }
}

void Music::play()
{
    if (elementtype == 1 && playing)
        bmusic.play();
    else if (elementtype == 2 && playing)
        sound.play();
}

void Music::stop()
{
    if (elementtype == 1)
        bmusic.stop();
    else if (elementtype == 2)
        sound.stop();
}

Music::~Music()
{
    //dtor
}
*/
