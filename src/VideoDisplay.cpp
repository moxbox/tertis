#include "VideoDisplay.h"
#include "GameState.h"
#include <iostream>
#include <chrono>

using namespace std::chrono_literals;

VideoDisplay::VideoDisplay()
{
    m_displayFrame = cv::Mat(screenHeight, screenWidth, CV_8UC3, cv::Scalar(0, 215, 225));
}

void VideoDisplay::Start()
{
    m_displayThread = std::thread(&VideoDisplay::DisplayLoop, this);
}

void VideoDisplay::DrawGrid()
{
    // pixel math
    int gridHeight = screenHeight - 200;
    int gridWidth = gridHeight / 2;
    int gridX = screenWidth / 2 - gridWidth / 2;
    int gridY = screenHeight / 2 - gridHeight / 2;
    int outerSquareSize = gridHeight / 20;
    int innerSquareSize = outerSquareSize - 2;

    cv::Mat temp(gridHeight, gridWidth, CV_8UC3, cv::Scalar(0, 0, 0));

    // Iterate over gamestate grid
    // For each row,
    for (int row = 0; row < GameState::gridHeight; row++) {
        for (int col = 0; col < GameState::gridWidth; col++) {
            auto& block = m_pGameState->getBlock(col, row);
            // if exists, draw box with color
            if (block.exists) {
                cv::Rect region;
                region.x = col * outerSquareSize;
                region.y = row * outerSquareSize;
                region.height = outerSquareSize;
                region.width = outerSquareSize;

                cv::Mat(region.height, region.width, CV_8UC3, block.color).copyTo(temp(region));
            }
        }
    }

    cv::Rect roi(gridX, gridY, gridWidth, gridHeight);
    temp.copyTo(m_displayFrame(roi));
}

void VideoDisplay::DrawBoard()
{
}

void VideoDisplay::RegisterGameState(GameState* pGameState)
{
    m_pGameState = pGameState;
}

void VideoDisplay::DisplayLoop()
{
    cv::String windowName = "Tertis";
    cv::namedWindow(windowName, cv::WINDOW_AUTOSIZE);

    while (true)
    {
        m_pGameState->randomize();
        DrawGrid();
        cv::imshow(windowName, m_displayFrame);
        cv::waitKey(15);
    }
}