#ifndef SIN_H
#define SIN_H

#include "animation.h"
#include <SDL2/SDL.h>

class Sin_animation: public Animation {
    public:
        Sin_animation(int w, int h);

        void draw(SDL_Renderer *renderer);

        void init();

        void update();
    
    private:
        double freq, amp, dt, d_freq;

};

#endif // SIN_H