#include "Message.h"
#include "BIT_MATH.h"

static u8 g_SeqNum = 0; /* [cite: 69] */
static MsgHandler g_Handlers[8] = {0}; /* [cite: 78] */

void Msg_RegisterHandler(MsgType type, MsgHandler handler) {
    if(type < 8) g_Handlers[type] = handler; /* [cite: 75] */
}

void Msg_Encode(MsgType type, u8 priority, Payload_t data, u8* buffer) {
    u8 header = 0;
    WRITE_FIELD(header, 0x07, 0, type);     /* [cite: 47] */
    WRITE_FIELD(header, 0x01, 3, priority); /* [cite: 47] */
    WRITE_FIELD(header, 0x0F, 4, g_SeqNum); /* [cite: 48] */

    buffer[0] = header;
    buffer[1] = 4; /* [cite: 41] */
    for(u8 i = 0; i < 4; i++) buffer[i+2] = data.bytes[i]; /* [cite: 68] */

    g_SeqNum = (g_SeqNum + 1) % 16; /* [cite: 69] */
}

ErrorStatus Msg_Decode(Ptr_t buffer, Message_t* result) {
    u8* raw = (u8*)buffer;
    result->header = raw[0];
    result->length = raw[1];
    for(u8 i = 0; i < 4; i++) result->payload.bytes[i] = raw[i+2]; /* [cite: 72] */

    u8 type = READ_FIELD(result->header, 0x07, 0);
    if(g_Handlers[type]) g_Handlers[type](result); /* [cite: 76] */

    return E_OK; /* [cite: 73] */
}