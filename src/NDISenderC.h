//
// file NDISenderC.h
// Created by Bartosz Sobol
//

#ifndef PD_NDI_NDISENDERC_H
#define PD_NDI_NDISENDERC_H

#ifdef __cplusplus
extern "C" {
#endif

struct NDISenderC;
typedef struct NDISenderC NDISenderC;

NDISenderC *NDISender_create(int screen_width, int screen_height);
void NDISender_destroy(NDISenderC *sender_ptr);
void NDISender_send_frame(NDISenderC *sender_ptr);
void *NDISender_p_data(NDISenderC *sender_ptr);
void NDISender_resize_frame(NDISenderC *sender_ptr, int screen_width, int screen_height);
void NDISender_set_framerate(NDISenderC *sender_ptr, int max_fps);

#ifdef __cplusplus
}
#endif

#endif //PD_NDI_NDISENDERC_H
