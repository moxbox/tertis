#include "GameState.h"

GameState::GameState() :
    m_score(0),
    m_level(0),
    m_lines(0)
{
    randomize();
}

BlockInfo& GameState::getBlock(int x, int y)
{
    // Check that this request is in bounds, otherwise give tl space
    if (x < 0 || x >= gridWidth || y < 0 || y >= gridHeight) {
        return m_grid[0];
    }

    int index = x + (gridWidth * y);

    return m_grid[index];
}

void GameState::randomize() {
    BlockInfo a{ true, cv::Scalar(128, 215, 0), false };
    BlockInfo b{ true, cv::Scalar(0, 128, 255), false };
    BlockInfo c{ true, cv::Scalar(240, 240, 240), false };
    BlockInfo d{ true, cv::Scalar(128, 0, 128), false };
    BlockInfo e{ true, cv::Scalar(25, 240, 25), false };

    std::array <BlockInfo, 5> these = { a,b,c,d,e };

    srand(time(NULL));
    for (int i = 0; i < 50; i++) {
        int index = rand() % gridSize;
        int c = rand() % 5;
        m_grid[index] = these[c];
    }
}
