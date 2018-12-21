//
// file main.c
// Created by Bartek
//



#include <memory.h>
#include "../src/NDISenderC.h"

extern void pd_ndi_setup();

int main() {
    NDISenderC *sender = NDISender_create(800, 600);


    for (int i = 0; i < 300; ++i) {
        NDISender_send_frame(sender);
        memset(NDISender_p_data(sender), (i & 1) ? 255 : 0, 800 * 600 * 4);
    }

    NDISender_destroy(sender);


}