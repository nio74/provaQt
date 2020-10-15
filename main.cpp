
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

void  muve_entuty(Entity& entity ,int dx, int dy ){

    entity.y += dx;
    entity.y += dy;
    clamp2(entity.x,0,W-1);
    clamp2(entity.x,0,H-1);
}

int main()
{

    //char hero_glyph = '@';
    //int hero_x = 5, hero_y = 7;
    Entity hero {5,7,'@'};
    Entity orc{10,10,'*'};
    bool running = true;

    /*
    cout << "Il nostro eroe " << hero.glyph << " ti saluta \n";
    cout << "The End \n";
    */


    //init Mappa
    init_map();


    //posizione eroe sulla mappa





    while (running) {
            Clear();
            //print_entity(hero_x, hero_y, hero_glyph);


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

            if (cmd == 'q')//quit command
            {
                running = false;
            }
            else if(cmd == 'd')
            {
                hero.x++;
                clamp(&hero.x, 0, W-1);
            }
            else if (cmd == 'a')
            {
                hero.x--;
                clamp2(hero.x, 0, W - 1);
            }
            else if (cmd == 'w')
            {
                hero.y--;
                clamp(&hero.y, 0, H - 1);
            }
            else if (cmd == 's')
            {
                hero.y++;
                clamp(&hero.y, 0, H - 1);
            }
    }


    return 0;



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
