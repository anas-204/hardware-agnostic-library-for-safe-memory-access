#include <stdio.h>
#include "MemScanner.h"

u8 MemScanner_ReadByte(Ptr_t addr, u32 offset) {
    return *((u8*)addr + offset); /* [cite: 24] */
}

void MemScanner_WriteByte(Ptr_t addr, u32 offset, u8 value) {
    *((u8*)addr + offset) = value; /* [cite: 27] */
}

u16 MemScanner_ReadHalfWord(Ptr_t addr, u32 offset) {
    u8* ptr = (u8*)addr + offset;
    return (u16)(ptr[0] | (ptr[1] << 8)); /* [cite: 25] */
}

u32 MemScanner_ReadWord(Ptr_t addr, u32 offset) {
    u8* ptr = (u8*)addr + offset;
    return (u32)(ptr[0] | (ptr[1] << 8) | (ptr[2] << 16) | (ptr[3] << 24)); /* [cite: 26] */
}

void MemScanner_HexDump(Ptr_t addr, u32 count) {
    u8* ptr = (u8*)addr;
    printf("[HexDump] ");
    for(u32 i = 0; i < count; i++) {
        printf("%02X ", ptr[i]); /* [cite: 28] */
    }
    printf("\n");
}

void MemScanner_MemFill(Ptr_t addr, u32 size, u8 value) {
    u8* ptr = (u8*)addr;
    for(u32 i = 0; i < size; i++) ptr[i] = value; /* [cite: 30] */
}

s32 MemScanner_MemCompare(Ptr_t addr1, Ptr_t addr2, u32 size) {
    u8* p1 = (u8*)addr1;
    u8* p2 = (u8*)addr2;
    for(u32 i = 0; i < size; i++) {
        if(p1[i] != p2[i]) return (s32)(i + 1); /* [cite: 33] */
    }
    return 0; /* [cite: 33] */
}

s32 MemScanner_FindByte(Ptr_t addr, u32 size, u8 value) {
    u8* ptr = (u8*)addr;
    for(u32 i = 0; i < size; i++) {
        if(ptr[i] == value) return (s32)i; /* [cite: 35] */
    }
    return -1; /* [cite: 35] */
}