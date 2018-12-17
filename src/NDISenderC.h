//
// file NDISenderC.h
// Created by Bartek
//

#ifndef PD_NDI_NDISENDERC_H
#define PD_NDI_NDISENDERC_H

#ifdef __cplusplus
extern "C" {
#endif

struct NDISenderC;
typedef struct NDISenderC NDISenderC;

int NDISender_create();
void NDISender_destroy();
void NDISender_send_frame(void *frame);

#ifdef __cplusplus
}
#endif

#endif //PD_NDI_NDISENDERC_H
