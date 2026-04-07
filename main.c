#include <stdio.h>
#include "Message.h"
#include "MemScanner.h"

void SensorHandler(Message_t* msg) {
    printf("--- Sensor Handler ---\n");
    printf("Raw 32-bit: 0x%08X\n", msg->payload.raw);
    printf("Temp: %d, Humid: %d\n", msg->payload.sensor.temp, msg->payload.sensor.humid);
    printf("Bytes: %02X %02X %02X %02X\n", msg->payload.bytes[0], msg->payload.bytes[1],
                                          msg->payload.bytes[2], msg->payload.bytes[3]);
}

void CommandHandler(Message_t* msg) {
    printf("--- Command Handler ---\n");
    /* FIX: Added .cmd before .id and .param */
    printf("CMD ID: 0x%02X, Param: 0x%02X\n", msg->payload.cmd.id, msg->payload.cmd.param);
}

s32 main() {
    u8 buffer1[MSG_SIZE], buffer2[MSG_SIZE];
    Payload_t p1 = {0}, p2 = {0};

    /* 1. Register Handlers */
    Msg_RegisterHandler(MSG_SENSOR_READING, SensorHandler);
    Msg_RegisterHandler(MSG_DEVICE_COMMAND, CommandHandler);

    /* 2. Encode Sensor (25.5C -> 255, 60.0% -> 600) */
    p1.sensor.temp = 255;
    p1.sensor.humid = 600;
    Msg_Encode(MSG_SENSOR_READING, 0, p1, buffer1);

    /* 3. Encode Command (ID 0x01, Param 0xFF) */
    p2.cmd.id = 0x01;
    p2.cmd.param = 0xFF;
    Msg_Encode(MSG_DEVICE_COMMAND, 1, p2, buffer2);

    /* 4. Decode each message - this triggers the handlers automatically */
    Message_t res;
    printf("\nDecoding Message 1:\n");
    Msg_Decode(buffer1, &res);

    printf("\nDecoding Message 2:\n");
    Msg_Decode(buffer2, &res);

    /* 5. MemScanner Demonstration */
    printf("\n--- MemScanner Demo ---\n");
    printf("Sensor Buffer:\n");
    MemScanner_HexDump(buffer1, MSG_SIZE);
    printf("Command Buffer:\n");
    MemScanner_HexDump(buffer2, MSG_SIZE);
    printf("Header Byte (Offset 0): 0x%02X\n", MemScanner_ReadByte(buffer1, 0));
    printf("Length Byte (Offset 1): 0x%02X\n", MemScanner_ReadByte(buffer1, 1));
    printf("Payload Word (Offset 2): 0x%08X\n", MemScanner_ReadWord(buffer1, 2));

    /* ReadHalfWord Demo */
    printf("Temperature (Offset 2): %d\n", MemScanner_ReadHalfWord(buffer1, 2));

    /* WriteByte Demo */
    u8 bufferCopy[MSG_SIZE];
    for (u32 i = 0; i < MSG_SIZE; i++) bufferCopy[i] = buffer1[i];
    u8 headerCopy = MemScanner_ReadByte(bufferCopy, 0);
    MemScanner_WriteByte(bufferCopy, 0, headerCopy | 0x08); /* Set priority bit */
    printf("\nOriginal Buffer:\n");
    MemScanner_HexDump(buffer1, MSG_SIZE);
    printf("Modified Priority Buffer:\n");
    MemScanner_HexDump(bufferCopy, MSG_SIZE);

    /* MemFill Demo */
    u8 fillBuffer[MSG_SIZE];
    MemScanner_MemFill(fillBuffer, MSG_SIZE, 0xAA);
    printf("\nFilled Buffer:\n");
    MemScanner_HexDump(fillBuffer, MSG_SIZE);

    /* MemCompare Demo */
    u8 compareBuffer[MSG_SIZE];
    Msg_Encode(MSG_SENSOR_READING, 0, p1, compareBuffer);
    /* Msg_Encode increments the internal sequence number. Sync header for identical test. */
    compareBuffer[0] = buffer1[0];
    printf("\nCompare Identical Buffers result: %d\n", MemScanner_MemCompare(buffer1, compareBuffer, MSG_SIZE));
    compareBuffer[3] = 0xFF; /* Modify one byte */
    printf("Compare Modified Buffers result: %d\n", MemScanner_MemCompare(buffer1, compareBuffer, MSG_SIZE));

    /* FindByte Demo */
    printf("\nFind Length Byte (0x04) Offset: %d\n", MemScanner_FindByte(buffer1, MSG_SIZE, 0x04));
    printf("Find Non-existent Byte (0xDD) Offset: %d\n", MemScanner_FindByte(buffer1, MSG_SIZE, 0xDD));

    return 0;
}


