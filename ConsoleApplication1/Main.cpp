#include <iostream>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<sstream>
#include<stdlib.h>
#include<stdio.h>
#include<ctime>
#include<time.h>
#include<string>
#include<random>
#include<iomanip>
#include<fstream>
#include<math.h>
#include <iomanip>
#include<SFML/Window/Event.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<Windows.h>
#include"Menu.h"
#include"SoundManager.h"
#include "Graph.h"


using namespace std;
using namespace sf;


/*
**************************************************************
*      page number        *       fun                        *
**************************************************************
*       1000              *         mainmenu                 *
*        -1               *         close=Exit               *
*         0               *         Game_Play                *
*         1               *         instruction              *
*         2               *         Designers                *
**************************************************************
*/

int Design(RenderWindow& window);
int instruction(RenderWindow& window);
int Game_Play(RenderWindow& window);
void drawMenu(RenderWindow& window, Menu& menu, Sprite& bg);
void handleEvents(RenderWindow& window, Menu& menu, int& pagenum);
void numphoto_checkMouseHover(RenderWindow& window, RectangleShape numplay[], int& selectedOption);

RenderWindow window(VideoMode(1920, 1080), "Game", Style::Fullscreen);

int main() {
    SoundManager soundManagerr;
    if (!soundManagerr.initialize()) {
        cout << "ERROR: Can't load sounds\n";
        system("pause");
        return -1;
    }

    int pagenum = 1000; // Index for choosing
    Menu menu(1920, 1080);
    Texture mainmenubg;
    if (!mainmenubg.loadFromFile("Assets/images/menu main.png")) {
        cout << "ERROR: Can't load menu main.jpg\n";
        window.close();
        return -1;
    }
    Sprite bg;
    bg.setPosition(0, -200);
    bg.setTexture(mainmenubg);

    soundManagerr.sound[0].setLoop(true);
    soundManagerr.sound[0].play();
    while (true) {

        if (pagenum == 1000) {
            while (window.isOpen()) {
                handleEvents(window, menu, pagenum);
                if (pagenum != 1000) {
                    break;
                }

                drawMenu(window, menu, bg);
            }
            if (pagenum == 0) {
                soundManagerr.sound[0].stop();
                pagenum = Game_Play(window);
                soundManagerr.sound[0].play();
            }
            if (pagenum == -1) {
                soundManagerr.sound[0].stop();
                window.close();
                break;
            }
            if (pagenum == 2) {
                pagenum = Design(window);
            }
            if (pagenum == 1) {
                pagenum = instruction(window);
            }

            for (int i = 1; i < 8; i++)
            {
                soundManagerr.sound[i].stop();
            }
        }
    }
    return 0;
}

void handleEvents(RenderWindow& window, Menu& menu, int& pagenum) {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
            break;
        }
        if (event.type == Event::KeyPressed) {
            if (event.key.code == Keyboard::Up) {
                menu.MoveUp();
            }
            if (event.key.code == Keyboard::Down) {
                menu.MoveDown();
            }
            if (event.key.code == Keyboard::Return) {
                if (menu.pressed() == 0) {
                    pagenum = 0;
                }
                if (menu.pressed() == 1) {

                    pagenum = 1;
                }
                if (menu.pressed() == 2) {

                    pagenum = 2;
                }
                if (menu.pressed() == 3) {
                    pagenum = -1;
                }
            }
        }

        if (event.type == Event::MouseMoved) {
            menu.checkMouseHover(window);
        }

        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == Mouse::Left)
            {
                int selectedItemIndex = menu.getHoveredIndex(window);
                if (selectedItemIndex != -1 && selectedItemIndex == menu.pressed()) {
                    if (menu.pressed() == 0) {
                        pagenum = 0;
                    }
                    if (menu.pressed() == 1) {

                        pagenum = 1;
                    }
                    if (menu.pressed() == 2) {

                        pagenum = 2;
                    }
                    if (menu.pressed() == 3) {
                        pagenum = -1;
                    }
                }
            }
        }
    }
}

void drawMenu(RenderWindow& window, Menu& menu, Sprite& bg)
{
    window.clear();
    window.draw(bg);
    menu.draw(window);
    window.display();
}

void numphoto_checkMouseHover(RenderWindow& window, RectangleShape numplay[], int& selectedOption)
{
    bool check = 0;
    for (int i = 0; i < 6; i++)
    {
        if (numplay[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
        {
            selectedOption = i;
            check = 1;
        }
    }
    if (check == 0)
    {
        selectedOption = -1;
    }

}

int Design(RenderWindow& window)
{
    Texture background;
    background.loadFromFile("Assets/images/Designers.jpg");  //background
    Sprite bg;
    bg.setTexture(background);
    Font font;
    font.loadFromFile("Assets/font/Prison Tattoo.ttf");   //font
    Text t[8];
    for (int i = 0; i < 8; i++)
    {
        t[i].setFont(font);                           //language
        t[i].setCharacterSize(70);             //font size 
        t[i].setFillColor(Color::White);
        t[i].setPosition(520, (920));      //( X , Y)
    }
    t[0].setString("Taha Mustafa Abdel Fattah");
    t[1].setString("\t  Reham Maher Roshdy");
    t[2].setString("  Yousab Ashraf Makram");
    t[3].setString("Mohamed Sameh El-Sayed");
    t[4].setString("Asmaa Walid Sayed Moawad");
    t[5].setString("\tYoussef Khaled Hussein");
    t[6].setString("\tRana Mohamad Fattouh ");
    t[7].setString("It was developed by them");


    RectangleShape Photo[6];

    Photo[0].setPosition(70, 210.f);
    Photo[1].setPosition(380.f, 210.f);
    Photo[2].setPosition(690.f, 210.f);
    Photo[3].setPosition(1000.f, 210.f);
    Photo[4].setPosition(1310, 210.f);
    Photo[5].setPosition(1630.f, 210.f);
    for (int i = 0; i < 6; i++)
    {
        Photo[i].setSize(Vector2f(230, 660));
        Photo[i].setFillColor(Color::Green);
    }


    int numphoto = -1;
    int selectedOption = -1;
    int checkphoto = -1;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed())
            {
                window.close();
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            {
                return 1000;
            }
        }
        if (event.type == Event::MouseMoved)
        {
            numphoto_checkMouseHover(window, Photo, selectedOption);
        }
        if (event.type == Event::MouseMoved)
        {
            for (int i = 0; i < 6; i++)
            {
                if (Photo[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
                {
                    checkphoto = i;
                    break;
                }
            }
        }
        if (checkphoto == selectedOption)
        {
            numphoto = checkphoto;
        }
        else
        {
            numphoto = -1;
        }


        window.clear();
        window.draw(bg);   //background
        if (numphoto == -1)
        {
            window.draw(t[7]);
        }
        else
        {
            window.draw(t[numphoto]);
        }

        window.display();
    }
}

int instruction(RenderWindow& window)
{
    Texture background;
    Sprite bg;
    background.loadFromFile("Assets/images/instructions.jpg");  //background

    Sprite KEY;
    Texture key;
    key.loadFromFile("Assets/images/key.png");


    KEY.setPosition(1200, 650);
    KEY.setScale(0.6, 0.6);

    KEY.setTexture(key);
    bg.setTexture(background);

    Sprite Gameimage;
    Texture gameimage;
    gameimage.loadFromFile("Assets/images/Gameimage.png");
    Gameimage.setPosition(900, 100);
    Gameimage.setScale(1.7, 1.7);
    Gameimage.setTexture(gameimage);



    Font font;
    font.loadFromFile("Assets/font/Prison Tattoo.ttf");   //font
    Text t[5];
    for (int i = 0; i < 5; i++)
    {
        t[i].setFont(font);
        t[i].setCharacterSize(150);
        t[i].setFillColor(Color::White);
    }
    t[0].setPosition(200, 200);
    t[1].setPosition(250, 400);
    t[2].setPosition(200, 600);
    t[3].setPosition(1110, 900);
    t[4].setPosition(900, 400);


    t[3].setCharacterSize(60);
    t[4].setCharacterSize(45);



    t[0].setString("HOW");
    t[1].setString("TO");
    t[2].setString("PLAY");
    t[3].setString("Control Buttons");
    t[4].setString("Move Pac-Man using the arrow keys and \n"
        "eat all the dots in the maze. Avoid the \n"
        "ghosts,but if you eat a big dot, the \n"
        "ghosts turn blue and you can eat them. \n"
        "Clear all the dots to go tothe next level.");




    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed())
            {
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                return 1000;   //Return to menu
            }


        }

        window.clear();
        window.draw(bg);
        window.draw(KEY);
        window.draw(Gameimage);

        for (int i = 0; i < 5; i++)
        {
            window.draw(t[i]);
        }
        window.display();
    }
}

void select_checkMouseHover(RenderWindow& window, Sprite difficulty[], int numphoto, int& selectedOption) {
    bool check = 0;
    for (int i = 0; i < 3; i++)
    {
        if (difficulty[i].getGlobalBounds().contains(window.mapPixelToCoords(Mouse::getPosition(window))))
        {
            selectedOption = i;
            check = 1;
        }
    }
    if (check == 0)
    {
        selectedOption = -1;
    }
}
int SelectDifficulty(RenderWindow& window) {
    int selectedOption = -1;
    Texture background;
    Sprite bg;
    background.loadFromFile("Assets/images/select difficulty.png");
    bg.setTexture(background);
    bg.setScale(1.9, 1);
    bg.setPosition(0, 0);

    Texture difficulty[3];
    Sprite df[3];
    difficulty[0].loadFromFile("Assets/images/select easy.png");
    difficulty[1].loadFromFile("Assets/images/select medium.png");
    difficulty[2].loadFromFile("Assets/images/select hard.png");

    for (int i = 0; i < 3; i++)
    {
        df[i].setTexture(difficulty[i]);
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                return 1000;
            }

            if (event.type == Event::MouseMoved)
            {
                select_checkMouseHover(window, df, 3, selectedOption);
            }

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left)
                {
                    if (selectedOption != -1)
                    {
                        return selectedOption;

                    }
                }
            }
        }

        window.clear();
        window.draw(bg);

        for (int i = 0; i < 3; i++)
        {
            if (selectedOption == i)
            {
                df[i].setScale(1.2f, 1.2f);
                df[i].setPosition(400 * i + 400 - 20, 550 - 20);
                df[i].setColor(i == 0 ? Color::Green : (i == 1 ? Color::Yellow : Color::Red));
            }
            else
            {
                df[i].setScale(1.f, 1.f);
                df[i].setColor(Color::White);
                df[i].setPosition(400 * i + 400, 550);
            }

            window.draw(df[i]);
        }

        window.display();
    }
}


int Game_Play(RenderWindow& window) {
	int x = SelectDifficulty(window);
    Graph g;
    int row = g.pacmanMatrix.size();
    int col = g.pacmanMatrix[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int x = i * col + j;
            if (x < 10)
            {
                cout << x << "   ";
                continue;
            }
            if (x < 100)
            {
                cout << x << "  ";
                continue;
            }
            if (x < 1000)
            {
                cout << x << " ";
                continue;
            }


        }
        cout << endl;
    }
    cout << endl;
    cout << endl;



    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int x = g.pacmanMatrix[i][j];
            if (x < 10)
            {
                cout << x << "   ";
                continue;
            }
            if (x < 100)
            {
                cout << x << "  ";
                continue;
            }
            if (x < 1000)
            {
                cout << x << " ";
                continue;
            }


        }
        cout << endl;
    }





    vector<int> path = Graph::bfs(22, 25);

    cout << path.size() << endl << endl << endl << endl;
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    return 1000;
}


