#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<sstream>;
using namespace std;
using namespace sf;
int main()
{
    RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    window.setFramerateLimit(30);
   
    //Player
    Texture playerText[8];
    playerText[0].loadFromFile("sonic run1.png");
    playerText[1].loadFromFile("sonic run2.png");
    playerText[2].loadFromFile("sonic run3.png");
 playerText[3].loadFromFile("sonic run4.png");
 playerText[4].loadFromFile("sonic run5.png");
 playerText[5].loadFromFile("sonic run6.png");
 playerText[6].loadFromFile("sonic run7.png");
 playerText[7].loadFromFile("sonic run8.png");
   Sprite playerSprite(playerText[0]);
    playerSprite.setPosition(62, 900);
    playerSprite.setScale(2, 2);


    int cntrX = 0; 
    int backpos=0;

    //Background
    Texture Back;
    Back.loadFromFile("backkkk.png");
    Sprite back(Back);
    back.setPosition(0, 0);
    back.setScale(1.006816990036707, 1.006816990036707);
    Sprite back2(Back);
    back2.setPosition(1907, 0);
    back2.setScale(1.006816990036707, 1.000926784059314);
    
    //menu
    Texture Menu;
    Menu.loadFromFile("menuu.png");
    Sprite menu(Menu);
    menu.setPosition(150, 50);
    menu.setScale(1.3, 1.4);
    int boos=0;
    Texture Coin;
    Coin.loadFromFile("Tails jump2.png");
        Sprite coin[30];
        bool coin1[30] = {};
        for (int j = 0; j < 30; ++j)
        {
            coin[j].setTexture(Coin);
            coin[j].setPosition(850+boos, 950);
            boos += 500;
            coin1[j] = 1;
        }
        int game=0;


        //audio
        SoundBuffer beginning;
        beginning.loadFromFile("Ziad-Sins.wav");
        Sound beginning1;
        beginning1.setBuffer(beginning);
        beginning1.setVolume(50);
        beginning1.play();
        beginning1.setLoop(true);
        SoundBuffer beginningcoin;
        beginningcoin.loadFromFile("coin_sound_fx_mp3cut.net.wav");
        Sound beginningcoin1;
        beginningcoin1.setBuffer(beginningcoin);
        beginningcoin1.setVolume(100);


        //message on screen
        Texture Win;
        Win.loadFromFile("you_win.png");
        Sprite win;
        win.setPosition(800, 500);
        win.setTexture(Win);
        Texture Gameover;
        Gameover.loadFromFile("gameover.png");
        Sprite gameover;
        gameover.setPosition(800, 500);
        gameover.setTexture(Gameover);


        //font
   Font myfont;
    myfont.loadFromFile("OpenSans-Italic.ttf");
    Text Score;
    Score.setFont(myfont);
    Score.setString("Score:");
    Score.setFillColor(Color::Red);
    Score.setPosition(10, 10);
    Text Score1;
    Score1.setFont(myfont);
    Score1.setFillColor(Color::Red);
    Score1.setPosition(100, 10);
    int score = 0;
    Text manue;
    int i = 0;


    Texture Flag;
    Flag.loadFromFile("3alam_ziad_sins.png");
    Sprite flag(Flag);
    flag.setPosition(20000, 951);
    flag.setScale(0.1, 0.1);



    int boom = 0;
    int scale = 0;


    Texture Monster;
    Monster.loadFromFile("monster.png");
    Sprite monster[20];
    //monster.setPosition(300, 951);
    //monster.setScale(0.3, 0.3);
    bool monster1[20] = {};
    for (int i = 0; i < 20; ++i)
    {
        monster[i].setTexture(Monster);
        monster[i].setPosition(1000+boom, 950);
       monster[i].setScale(0.3+scale , 0.3+scale);
        boom += 670;
        scale += 0.01;
        monster1[i] = 1;
    }

    /*   Texture Coin;
    Coin.loadFromFile("Tails jump2.png");
        Sprite coin[30];
        bool coin1[30] = {};
        for (int j = 0; j < 30; ++j)
        {
            coin[j].setTexture(Coin);
            coin[j].setPosition(950+boos, 950);
            boos += 500;
            coin1[j] = 1;
        }*/




    //gameover
    int go = 0; 

    //win
    int end = 0;
    
    //jumb
    int cntrg = 20;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

          
        }
  //control
        
        if (Keyboard::isKeyPressed(Keyboard::Key::Up) && cntrg > 20)
            {
           
                cntrg = 0; 
            }
         
            if (Keyboard::isKeyPressed(Keyboard::Key::Right))
            {
              //  cout << "RIGHT" << endl;
                back.move(-10, 0);
                back2.move(-10, 0);
                flag.move(-10, 0);
              //  monster.move(-10, 0);
                playerSprite.setScale(2,2);
                cntrX++;
                for (int j = 0; j < 20; ++j) {
                    coin[j].move(-10, 0);
                }
                for (int i = 0; i < 20; ++i) {
                    monster[i].move(-10, 0);
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::Left))
            {
                back.move(10, 0);
                back2.move(10, 0);
                flag.move(10, 0);
               // monster.move(10, 0);
                for (int j = 0; j < 30; ++j)
                {
                    coin[j].move(10, 0);
                }
                for (int i = 0; i < 20; ++i) {
                    monster[i].move(10, 0);
                }
                 playerSprite.setScale(-2, 2);
                cntrX++;
            }
            if (Keyboard::isKeyPressed(Keyboard::Key::Space) && game == 0)
            {
                game = 1;
            }
            cntrX %= 8;
            playerSprite.setTexture(playerText[cntrX]);
       
        if (cntrg <= 10)
        {
            playerSprite.move(0,-40);
            cntrg++;
        }
        if (cntrg <= 20 && cntrg >10)
        {
            playerSprite.move(0, 44);
            cntrg++;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
        {
            break;
        }
       
        //background loop
        if (back2.getPosition().x < 0)
        {
            back.setPosition(0, 0);
            back2.setPosition(1907, 0);
        }
        if (back.getPosition().x > 0)
        {
            back.setPosition(-1907, 0);
            back2.setPosition(0, 0);
        }


        //intersection
        if (playerSprite.getGlobalBounds().intersects(flag.getGlobalBounds()) && end == 0)
        {
            end = 1;
        }
       /* if (playerSprite.getGlobalBounds().intersects(monster.getGlobalBounds()) && go == 0)
        {
            go = 1;
        }*/
     
        
        
        window.clear();
        if (game == 0) {
            window.draw(menu);
        }
        
        
        if (game == 1)
        {
            window.draw(back);
            window.draw(back2);
           //window.draw(monster);
            window.draw(flag);
            window.draw(playerSprite);
            for (int j = 0; j < 30; ++j)
            {

                if (playerSprite.getGlobalBounds().intersects(coin[j].getGlobalBounds()) &&coin1[j] == 1)
                {
                    score += 50;
                    coin1[j] = 0;
                    beginningcoin1.play();
                }


                if (coin1[j] == 1) {
                    window.draw(coin[j]);
                }
            }
            for (int i = 0; i < 20; ++i)
            {

                if (playerSprite.getGlobalBounds().intersects(monster[i].getGlobalBounds()) && monster1[i] == 1)
                {
                    monster1[i] = 0;
                    go = 1;
                   
                }


                if (monster1[i]) {
                    window.draw(monster[i]);
                }
            }

            window.draw(Score);
            window.draw(Score1);
            //Score1.(window);
            stringstream theScore;
            theScore << score;
            Score1.setString(theScore.str());
        }
        if (go == 1)
        {
            game = 50;
            window.clear();
            window.draw(gameover);
        }
        if (end == 1)
        {
            game = 10;
            window.clear();
            window.draw(win);
        }
        window.display();
    }
    return 0;
}