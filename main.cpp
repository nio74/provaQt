
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

int main()
{

    char hero_glyph = '@';

    int hero_x = 5;
    int hero_y = 7;
    bool running = true;

    cout << "Il nostro eroe " << hero_glyph << " ti saluta \n";
    cout << "The End \n";

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
                    if (hero_x == x && hero_y == y)
                    {
                        cout << hero_glyph;
                    }else

                        cout << map[y][x];
                }

                cout << endl;

            }
            char cmd;
            cout << endl << "> ";
            cin >> cmd;
            if (cmd == 'q')//quit command
            {
                running = false;
            }
            else if(cmd == 'd')
            {
                hero_x++;
                clamp(&hero_x, 0, W-1);
            }
            else if (cmd == 'a')
            {
                hero_x--;
                clamp(&hero_x, 0, W - 1);
            }
            else if (cmd == 'w')
            {
                hero_y--;
                clamp(&hero_y, 0, H - 1);
            }
            else if (cmd == 's')
            {
                hero_y++;
                clamp(&hero_y, 0, H - 1);
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



void print_entity(int x, int y, char glyph)
    {
        map[y][x] = glyph;

    }
