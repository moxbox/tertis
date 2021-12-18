#pragma once
#include "opencv2/core.hpp"

struct BlockInfo
{
    bool exists = false;
    cv::Scalar color = cv::Scalar(0, 0, 0);
    bool isFalling = false;
};

class GameState
{
public:
    GameState();

    // Define our grid dimensions
    static const int gridWidth = 10;
    static const int gridHeight = 20;
    static const int gridSize = gridWidth * gridHeight;

    BlockInfo& GetBlock(int x, int y);
    
    void RandomizeGrid();

private:
    std::array<BlockInfo, gridSize> m_grid;

    int m_score;
    int m_level;
    int m_lines;
    
    //Todos:
    // Current falling tertonimo
    // Next block
    // Animation info

};
