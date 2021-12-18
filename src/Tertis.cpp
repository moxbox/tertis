#include "Tertis.h"

#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

Tertis::Tertis()
{
    m_videoDisplay.RegisterGameState(&m_gameState);
}

Tertis::~Tertis()
{
}

void Tertis::Run()
{
    std::cout << "Tertis is running!" << std::endl;

    m_videoDisplay.Start();

    while (1) {
        std::this_thread::sleep_for(20ms);
    }
}
