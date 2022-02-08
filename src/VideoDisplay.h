#pragma once
#include "GameState.h"
#include <thread>
#include "opencv2/opencv.hpp"

class VideoDisplay
{
public:
    VideoDisplay();

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    void Start();
    void DrawGrid();
    void DrawBoard();
    void RegisterGameState(GameState* pGameState);

    void DisplayLoop();

private:
    GameState* m_pGameState;
    cv::Mat m_displayFrame;
    std::thread m_displayThread;
};