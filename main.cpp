
#include <iostream>
using namespace std;



constexpr auto W = 80;
constexpr auto H = 30;

char map[W][H];

void print_entity(int x, int y, char glyph);


void init_map() {

    for (auto y = 0; y < H; y++)
    {
        for (auto x = 0; x < W; x++) {

            map[y][x] = '.';
        }

        cout << endl;

    }

}

void Clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void clamp(int*, int, int);
void clamp2(int&, int, int);

struct Entity{
    int x;
    int y;
    char glyph;
};

char command_prompt(){

    char cmd;
    cout << endl << "> ";
    cin >> cmd;
    return  cmd;

}

/**
 * @brief muove entità a destra o a sinistra
 * @param entity
 * @param dx
 * @param dy
 */

void  move_entity(Entity& entity ,int dx, int dy ){

    entity.x += dx;
    entity.y += dy;
    clamp2(entity.x,0,W-1);
    clamp2(entity.x,0,H-1);
}

int main()
{

    Entity hero {5,7,'@'};
    Entity orc{10,10,'*'};
    bool running = true;



    //init Mappa
    init_map();


    //posizione eroe sulla mappa

    while (running) {


        Clear();

        //stampa mappa

        for (auto y = 0; y < H; y++)
        {
            for (auto x = 0; x < W; x++)
            {
                if (hero.x == x && hero.y == y)
                {
                    cout << hero.glyph;
                }else if (orc.x == x && orc.y == y){
                    cout << orc.glyph;
                }
                else
                    cout << map[y][x];
            }

            cout << endl;
        }


        char cmd = command_prompt();

        switch (cmd) {
        case 'q':
            running = false;
            break;
        case 'd':
            move_entity(hero,+1,0);
            break;
        case'a':
            move_entity(hero,-1,0);
            break;
        case 'w':
            move_entity(hero,0,-1);
            break;
        case 's':
            move_entity(hero,0,+1);
            break;

        }


    }






}
void clamp(int *value , int min_value, int max_value) {

    if (*value <= min_value)
    {
        *value = min_value;
        return;
    }
    if (*value >= max_value)
    {
        *value = max_value;
        return;
    }

}

void clamp2(int &value , int min_value, int max_value) {

    if (value <= min_value)
    {
        value = min_value;
        return;
    }
    if (value >= max_value)
    {
        value = max_value;
        return;
    }

}



void print_entity(int x, int y, char glyph)
{
    map[y][x] = glyph;

}
