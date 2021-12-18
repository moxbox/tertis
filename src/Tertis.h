#pragma once
#include "GameState.h"
#include "VideoDisplay.h"


class Tertis
{
public:
    Tertis();
    ~Tertis();

    void Run();


private:
    VideoDisplay m_videoDisplay;

    //Only GameState object in existence
    GameState m_gameState;
    // GameEngine m_gameEngine;
};
