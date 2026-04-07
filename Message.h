#ifndef MESSAGE_H
#define MESSAGE_H

#include "STD_TYPES.h"

#define MSG_SIZE 6 /* [cite: 43] */

typedef enum {
    MSG_SENSOR_READING = 0, /* [cite: 52] */
    MSG_DEVICE_COMMAND = 1  /* [cite: 53] */
} MsgType;

/* Payload Union for different interpretations [cite: 57, 72] */
typedef union {
    u32 raw;
    struct { u16 temp; u16 humid; } sensor;
    struct { u8 id; u8 param; u16 unused; } cmd;
    u8 bytes[4];
} Payload_t;

/* Message Structure [cite: 62] */
typedef struct {
    u8 header;  /* [cite: 41] */
    u8 length;  /* [cite: 41] */
    Payload_t payload; /* [cite: 41] */
} __attribute__((packed)) Message_t;

_Static_assert(sizeof(Message_t) == 6, "Message_t must be exactly 6 bytes"); /* [cite: 63, 65] */

typedef void (*MsgHandler)(Message_t* msg); /* [cite: 75] */

void Msg_RegisterHandler(MsgType type, MsgHandler handler); /* [cite: 75] */
void Msg_Encode(MsgType type, u8 priority, Payload_t data, u8* buffer); /* [cite: 67] */
ErrorStatus Msg_Decode(Ptr_t buffer, Message_t* result); /* [cite: 71, 73] */

#endif