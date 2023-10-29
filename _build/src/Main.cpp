

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
#include <iostream>
#include "Entities.h"
#include "Screens.h"
#include "GameplayManager.h"
#include <vector>


//Variables declaration
int gameTime;
int titleYAxis;
int timeToWin;

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
    InitAudioDevice();

    //Textures initialization
    //--------------------------------------------------------------------------------------

    gamePlayManager.LoadTextures(); 

    //Audio initialization
    //--------------------------------------------------------------------------------------
    gamePlayManager.LoadAudio();


    //Variables initialization
    //--------------------------------------------------------------------------------------
    gameTime = 0;
    titleYAxis = -250;    

    Player player(3);  
    PowerUp powerUp;
    std::vector<Meteor> meteors;
    std::vector<Bullet> bullets;

    player.SetTexture(&gamePlayManager.playerTexture);

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // UPDATE
        //----------------------------------------------------------------------------------
        
        switch (currentScreen)
        {
        case LOGO:
            
            if (gamePlayManager.gameTime >= 120) //Changes screen after 120 frames (2 seconds since 60 fps)
                currentScreen = TITLE;

            break;

        case TITLE:           

            PlayMusicStream(gamePlayManager.menu);
            UpdateMusicStream(gamePlayManager.menu);
            

            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = GAMEPLAY;                
            }            
            break;

        case GAMEPLAY:            
            StopMusicStream(gamePlayManager.menu);//Stop the previous music

            PlayMusicStream(gamePlayManager.game);
            UpdateMusicStream(gamePlayManager.game);

            if (gamePlayManager.gameTime % 60 == 0) //An asteroid will spawn every second
            {
                gamePlayManager.MeteorSpawner(&meteors);
            }

            gamePlayManager.MoveMeteors(&meteors); //We move the meteors every frame
            gamePlayManager.PowerUpSpawn(&powerUp);
            

            //PLAYER INPUT
            //----------------------------------------------------------------------------------
            //Movement
            if (IsKeyDown(KEY_UP))
            {
                player.Moving(true);
                player.Move();
            }
            else
            {
                player.Moving(false);
            }            

            if (IsKeyDown(KEY_LEFT))
            {
                player.TurnLeft();
            }
            if (IsKeyDown(KEY_RIGHT))
                player.TurnRight();


            //SHOOT
            //----------------------------------------------------------------------------------
            if (IsKeyPressed(KEY_SPACE))
            {
                PlaySound(gamePlayManager.shoot);
                gamePlayManager.BulletSpawner(&bullets, &player);
            }
            gamePlayManager.MoveBullets(&bullets, player.GetRotation());


            //COLLISIONS
            //----------------------------------------------------------------------------------    
            gamePlayManager.MeteorCollision(&meteors, &player); //Meteor vs player
            gamePlayManager.MeteorCollision(&meteors, &bullets); //Meteor vs bullets
            gamePlayManager.PowerUpCollision(&powerUp, &player); //PowerUp vs player


            //CONDITIONS TO GAMEOVER
            //---------------------------------------------------------------------------------- 
            if (player.GetLives() <= 0)
                currentScreen = LOSE;
            else if (gamePlayManager.LevelCountDown() == -1)
                currentScreen = WIN;


            break;

        case WIN:
            StopMusicStream(gamePlayManager.game);//Stop the previous music
            PlayMusicStream(gamePlayManager.win);
            UpdateMusicStream(gamePlayManager.win);

            gamePlayManager.InitGame(&player, &bullets, &meteors, &powerUp);
            if (IsKeyPressed(KEY_ENTER))
                currentScreen = TITLE;
            break;
        case LOSE:
            StopMusicStream(gamePlayManager.game);//Stop the previous music
            PlayMusicStream(gamePlayManager.lose);
            UpdateMusicStream(gamePlayManager.lose);
            gamePlayManager.InitGame(&player, &bullets, &meteors, &powerUp);
            if (IsKeyPressed(KEY_ENTER))
                currentScreen = GAMEPLAY;
            break;
        }


        // DRAW
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
        switch (currentScreen)
        {
        case LOGO:
            
            InitLogo(gamePlayManager.logoTexture);
            break;
        case TITLE:            
            DrawBackground(gamePlayManager.backgroundTexture);
            DrawTitle(titleYAxis,gamePlayManager.titleText);
            if(gamePlayManager.gameTime > 240)
                BlinkingMessage(gamePlayManager.gameTime, "Press START to play the game");

            if (titleYAxis < -75)//This is the limit on the Y axis, when reached, the title texture stops moving. 
                titleYAxis++;          

            break;
        case GAMEPLAY:
            DrawBackground(gamePlayManager.backgroundTexture);
            DrawPlayer(&player);
            DrawAsteroids(&meteors);
            DrawBullets(&bullets);
            DrawPowerUp(&powerUp);
            DrawHUD(&gamePlayManager, &player);     
            break;

        case WIN:

            DrawBackground(gamePlayManager.backgroundTexture);
            DrawWinScreen(&gamePlayManager);
            BlinkingMessage(gamePlayManager.gameTime, "Press START to go to main menu");

            break;

        case LOSE:

            DrawBackground(gamePlayManager.backgroundTexture);
            DrawLoseScreen(&gamePlayManager);
            BlinkingMessage(gamePlayManager.gameTime, "Press START to try again");
            break;

        }

        ClearBackground(LIGHTGRAY);

        // TODO: Draw everything that requires to be drawn at this point:


        EndDrawing();
        //----------------------------------------------------------------------------------
        
        gamePlayManager.gameTime++;
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // TODO: Unload all loaded resources at this point
    gamePlayManager.UnloadTextures();
    gamePlayManager.UnloadAudio();

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}