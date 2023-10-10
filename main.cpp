#include "cell.hpp"
#include <SFML/Graphics.hpp>

class FPS
{
public:
    /// @brief Constructor with initialization.
    ///
    FPS() : mFrame(0), mFps(0) {}

    /// @brief Update the frame count.
    ///

    /// @brief Get the current FPS count.
    /// @return FPS count.
    const unsigned int getFPS() const { return mFps; }

private:
    unsigned int mFrame;
    unsigned int mFps;
    sf::Clock mClock;

public:
    void update()
    {
        if (mClock.getElapsedTime().asSeconds() >= 1.f)
        {
            mFps = mFrame;
            mFrame = 0;
            mClock.restart();
        }

        ++mFrame;
    }
};


    
std::vector<cell> cells{};
std::vector<cell> cells2;

const int screen = 32;
int neighborsCount(int x, int y)
{
    int count = 0;
    if (y - 1 >= 0)
    {
        count += cells2.at(x + (y - 1) * screen).enabled;
        if (x - 1 >= 0)
        {
            count += cells2.at(x - 1 + (y - 1) * screen).enabled;
        }
        if (x + 1 < screen)
        {
            count += cells2.at(x + 1 + (y - 1) * screen).enabled;
        }
    }
    if (y + 1 < screen)
    {
        count += cells2.at(x + (y + 1) * screen).enabled;
        if (x - 1 >= 0)
        {
            count += cells2.at(x - 1 + (y + 1) * screen).enabled;
        }
        if (x + 1 < screen)
        {
            count += cells2.at(x + 1 + (y + 1) * screen).enabled;
        }
    }
    if (x - 1 >= 0)
    {
        count += cells2.at(x - 1 + (y)*screen).enabled;
    }
    if (x + 1 < screen)
    {
        count += cells2.at(x + 1 + (y)*screen).enabled;
    }
    return count;
}
const int cell_size = 16;


int main(int argc , char **argv)
{
    // create the window
    int Fps = 10;
    if (argc > 1) {
        Fps = std::stoi(argv[1]);
    }
    sf::RenderWindow window(sf::VideoMode(screen * cell_size, screen * cell_size), "My window");
    // run the program as long as the window is open
    bool active = false;
    window.setFramerateLimit(Fps);
    for (int y = 0; y < screen; y += 1)
    {
        for (int x = 0; x < screen; x += 1)
        {
            cells.push_back(cell(x * cell_size, y * cell_size));
        }
    }
    FPS fps;
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Left mouse button clicked
                    float mouseX = static_cast<float>(event.mouseButton.x);
                    float mouseY = static_cast<float>(event.mouseButton.y);
                    if (!active)
                    {
                        int x = mouseX / cell_size;
                        int y = mouseY / cell_size;
                        cells.at(x + y * screen).enabled = !cells.at(x + y * screen).enabled;
                    }
                    // You can now use mouseX and mouseY to handle the click position
                    // For example, you can check if a point was clicked within a rectangle, etc.
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    float mouseX = static_cast<float>(event.mouseButton.x);
                    float mouseY = static_cast<float>(event.mouseButton.y);
                    int x = mouseX / cell_size;
                    int y = mouseY / cell_size;
                }
            }
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Enter)
                    active = !active;

                else if (event.key.code == sf::Keyboard::Escape)

                    window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw();
        if (active)
        {
            cells2 = cells;

            for (int y = 0; y < screen; y += 1)
            {
                for (int x = 0; x < screen; x += 1)
                {
                    int nCount = neighborsCount(x, y);
                    if (nCount < 2 || nCount > 3)
                    {
                        cells.at(x + y * screen).enabled = false;
                    }
                    if (nCount == 3)
                    {
                        cells.at(x + y * screen).enabled = true;
                    }
                }
            }
        }
        for (auto &cell : cells)
        {
            cell.draw(window);
        }

        // end the current frame
        window.display();
    }
    return 0;
}
