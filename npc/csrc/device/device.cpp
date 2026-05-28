#include <SDL2/SDL.h>
#include "common.h"
#include "device.h"

#define POLL_INTERVAL 1000

void send_key(uint8_t scancode, bool is_keydown);
void vga_update_screen();

void device_poll() {
    static uint64_t last = 0;
    uint64_t now = sim_time;
    if (now - last < POLL_INTERVAL) return;
    last = now;

    vga_update_screen();

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                npc_state = NPC_END;
                Verilated::gotFinish(true);
                break;
            case SDL_KEYDOWN:
            case SDL_KEYUP: {
                uint8_t k = event.key.keysym.scancode;
                bool is_keydown = (event.key.type == SDL_KEYDOWN);
                send_key(k, is_keydown);
                break;
            }
            default: break;
        }
    }
}
