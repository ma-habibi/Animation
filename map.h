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
        double max_spiral, dt, amp, rotated,\
        d_resize, d_rotate, min_resize, max_resize;
        bool rotate, resize_dir;

        void init_animation();

        void put_next_frame_vars();
};

#endif