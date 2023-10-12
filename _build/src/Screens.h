#pragma once

//States of the game
enum GameScreen 
{
	LOGO,
	TITLE,
	GAMEPLAY,
	ENDING
};

//Variable declarations

static GameScreen currentScreen;


//Logo screen declarations
void InitLogoScreen();
void UpdateLogoScreen();

//Title screen declarations
void InitTitleScreen();
void DrawTitle(Texture2D title, int y);

//Gameplay screen declarations
void InitGamePlayScreen();

//Ending screen declarations
void InitEndingScreen();




