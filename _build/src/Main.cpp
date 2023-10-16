

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
#include "GameplayManager.h"
#include <vector>


//Variables declaration
int gameTime;
int titleYAxis;

GameplayManager gamePlayManager;



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

    //Textures initialization
    //--------------------------------------------------------------------------------------
    LoadTextTextures();
    LoadGameTextures();
    gamePlayManager.LoadTextures();


    

    //Variables initialization
    //--------------------------------------------------------------------------------------
    gameTime = 0;
    titleYAxis = -250;

    Player player(3);
    std::vector<Meteor> meteors;
    
    player.SetPosition(new Vector2({ screenWidth / 2, screenHeight / 2 }));
    player.SetTexture(&gamePlayManager.playerTexture);

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

            if (gameTime >= 360 && gameTime % 60 == 0) //Text starts blinking at 6 seconds time.
                DrawText("PRESS [ENTER] TO START", GetScreenWidth() / 2 - 200, GetScreenHeight() / 2,30,YELLOW);  

            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = GAMEPLAY;
                gamePlayManager.MeteorSpawner(&meteors);
            }

            
            break;
        case GAMEPLAY:
            DrawText("GAMEPLAY", GetScreenWidth() / 2 - 200, GetScreenHeight() / 2, 30, YELLOW);

            if(gameTime % 120 == 0)
                gamePlayManager.MeteorSpawner(&meteors);



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
            DrawTitle(titleYAxis);

            if (titleYAxis < -75)//This is the limit on the Y axis, when reached, the title texture stops moving. 
                titleYAxis++;          

            break;
        case GAMEPLAY:
            DrawPlayer(&player);
            DrawAsteroids(&meteors);


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