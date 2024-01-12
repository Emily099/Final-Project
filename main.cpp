#include <iostream>
#include"raylib.h"

using namespace std;

int main(){
    int totalFrames = 8, totalActions = 10, actionNum = 4;
    Rectangle screen = {0, 0, 800, 500};

    //SET UP WINDOW
    // int windowWidth = 800;
    // int windowHeight = 500;
    
    InitWindow(screen.width, screen.height, "YOUR GAME");
    SetTargetFPS(60);
    
    //char/img import and dimensions
    Texture2D hero = LoadTexture("D:/Emily/Grade 12/Computer Studies/Final Project/catSpriteSheet.png");
    
    Rectangle heroRec;
    heroRec.width = hero.width / totalFrames;
    heroRec.height = hero.height / totalActions;
    heroRec.x = 0;
    heroRec.y = 0;
    
    Vector2 heroCenter = {(hero.width / 2.0), (hero.height / 2.0)};
    //heroPos.x = (screen.width) / 2;// + 100 - heroRec.width;
    //heroPos.y = (screen.height) / 2;//+100 - heroRec.height/2;
    
    Vector2 heroPos = {(screen.width / 2), (screen.height / 2)};

    int frame = 0;
    
    float updateTime = 1.0 / 12.0;
    float runningTime = 0.0;

    //GAME LOOP

    heroRec.y = hero.height/totalActions * actionNum;

    while(!WindowShouldClose())
    {
        const float dT = GetFrameTime();
        BeginDrawing();
        ClearBackground(WHITE);

        //updating the frame for the animation
        runningTime += dT;
        if(runningTime >= updateTime)
        {
            runningTime = 0;
            
            heroRec.x = hero.width/totalFrames * frame;
            frame++;
            if(frame == totalFrames) // when frame == totalFrames, means is past last frame (since "frame" starts count at 0), so must reset "frame" to 0 again. NOT frame > totalFrames since "frame" starts counting at 0, unlike "totalFrames".
            {
                frame = 0;
            }
        }
        
        //draw texture
        DrawTexturePro
        (
            hero, 
            heroRec, 
            (Rectangle) {heroPos.x, heroPos.y, (5 * heroRec.width), (5 * heroRec.height)}, 
            heroCenter, 
            0, 
            WHITE
        );
             
        EndDrawing();
    }
    UnloadTexture(hero);
    CloseWindow();
}

// - tabs or spaces
// - snake or camel case
// - nice to have are challenges 

