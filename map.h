#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>

class Map {
    public:
        Map(int w, int h);
        ~Map();

        void draw_map(SDL_Renderer *renderer);

    private:
        int width, height;
        double max_spiral, dt, amp;
};

#endif