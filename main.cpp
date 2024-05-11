#include <level.h>
#include <Personnage.h>
#include <Objet.h>
#include <bits/stdc++.h>
#include <Game.h>


using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Level lvl(6,10);

    lvl.loadcarte();
    Game s(lvl);
    s.mainloop();




    return 0;
}
