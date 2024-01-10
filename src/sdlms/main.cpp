#include "sdlms/main.hpp"
#include <SDL2/SDL.h>
#include "main.hpp"

// Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 800;

const int FPS = 60;
const int FRAME_DELAY = 1000 / FPS;

int Main::run(int argc, char **argv)
{
    int mapId = 100000000;

    _graphics.reset(new Graphics());

    _wz_util.reset(new WzUtil());
    _map_util.reset(new MapUtil());

    _map.reset(new Map());
    _camera.reset(new Camera());
    _input.reset(new Input());

    _map->_tile = _map_util->load_tile(mapId);

    while (true)
    {
        auto frameStart = SDL_GetTicks(); // 获取当前帧开始的时间

        if (_input->loop() < 0)
        {
            break;
        }
        // 更新屏幕
        _map->draw();

        auto frameTime = SDL_GetTicks() - frameStart; // 计算当前帧的时间
        if (frameTime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY - frameTime); // 控制帧率
        }
    }

    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return 0;
}