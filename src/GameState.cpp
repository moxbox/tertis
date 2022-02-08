#include "GameState.h"

GameState::GameState() :
    m_score(0),
    m_level(0),
    m_lines(0)
{
    // Seed our random number generator with the current time
    srand(time(NULL));
}

BlockInfo& GameState::GetBlock(int x, int y)
{
    // Check that this request is in bounds, otherwise give tl space
    if (x < 0 || x >= gridWidth || y < 0 || y >= gridHeight) {
        return m_grid[0];
    }

    int index = x + (gridWidth * y);

    return m_grid[index];
}

void GameState::RandomizeGrid()
{
    // This takes 100 random positions in the grid, and randomizes the color of
    // the block there and whether or not it exists
    for (int i = 0; i < 100; i++) {
        int index = rand() % gridSize;
        m_grid[index].exists = rand() % 2;
        m_grid[index].color = cv::Scalar(rand() % 256, rand() % 256, rand() % 256);
    }
}
