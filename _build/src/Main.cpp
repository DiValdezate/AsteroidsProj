

/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Example originally created with raylib 4.5, last time updated with raylib 4.5
*
*   Example contributed by <user_name> (@<user_github>) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2023 <user_name> (@<user_github>)
*
********************************************************************************************/

#include "raylib.h"
#include "Entities.h"
#include "Screens.h"


static int gameTime;
Image titleImg;
Texture2D titleText;


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;


    InitWindow(screenWidth, screenHeight, "Asteroids");
    gameTime = 0;
    titleImg = LoadImage("resources/textures/Title.png");
    titleText = LoadTextureFromImage(titleImg);
    

    // TODO: Load resources / Initialize variables at this point
    

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update variables / Implement example logic at this point
        //----------------------------------------------------------------------------------
        switch (currentScreen)
        {
        case LOGO:
            InitLogoScreen();
            if (gameTime >= 120)
                currentScreen = TITLE;

            break;
        case TITLE:
            InitTitleScreen();
            DrawText("hey", GetScreenWidth() / 2, GetScreenHeight() / 2,50,YELLOW);

            break;
        case GAMEPLAY:
            break;

        case ENDING:
            break;

        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        switch (currentScreen)
        {
        case LOGO:
            

            break;
        case TITLE:
            DrawTitle(titleText);

            break;
        case GAMEPLAY:
            break;

        case ENDING:
            break;

        }

        ClearBackground(LIGHTGRAY);

        // TODO: Draw everything that requires to be drawn at this point:


        EndDrawing();
        //----------------------------------------------------------------------------------
        gameTime++;
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // TODO: Unload all loaded resources at this point

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}