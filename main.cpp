// #include <iostream>
// #include <raylib.h>

// using namespace std;

// int main () {

//     const int screenWidth = 800;
//     const int screenHeight = 600;
//     int ball_x = 100;
//     int ball_y = 100;
//     int ball_speed_x = 5;
//     int ball_speed_y = 5;
//     int ball_radius = 15;

//     InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
//     SetTargetFPS(60);

//     while (WindowShouldClose() == false){
//         BeginDrawing();
//         ClearBackground(BLACK);
//         ball_x += ball_speed_x;
//         ball_y += ball_speed_y;

//         if(ball_x + ball_radius >= screenWidth  || ball_x - ball_radius <= 0)
//         {
//             ball_speed_x *= -1;
//         }

//         if(ball_y + ball_radius >= screenHeight  || ball_y - ball_radius <= 0)
//         {
//             ball_speed_y *= -1;
//         }

//         DrawCircle(ball_x,ball_y,ball_radius, WHITE);
//         EndDrawing();
//     }

//     CloseWindow();
//     return 0;
// }

#include"raylib.h"

int main(){
    
    int windowWidth = 800;
    int windowHeight = 500;
    
    InitWindow(windowWidth,windowHeight,"YOUR GAME");
    SetTargetFPS(60);
    
    
    //character import and dimensions
    Texture2D hero = LoadTexture("textures/hero.png");
    
         //dimensions of hero
    Rectangle heroRec;
    heroRec.width = hero.width/8;   //dividing by 8 because there are 8 frames
    heroRec.height = hero.height;
    heroRec.x = 0;
    heroRec.y = 0;
        //position of hero
    Vector2 heroPos;
    heroPos.x = windowWidth/2 - heroRec.width/2;
    heroPos.y = windowHeight/2 - heroRec.height;
    
    
    
    
    while(WindowShouldClose()==false){
         BeginDrawing();
        ClearBackground(WHITE);
        
          //draws the image on the screen 
         DrawTextureRec(hero,heroRec,heroPos,WHITE);
       
        ClearBackground(BLACK);
        EndDrawing();
    }
    UnloadTexture(hero);
    CloseWindow();
}

// - tabs or spaces
// - snake or camel case
// - nice to have are challenges 

