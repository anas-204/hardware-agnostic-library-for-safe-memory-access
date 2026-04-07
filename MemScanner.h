#ifndef MEM_SCANNER_H
#define MEM_SCANNER_H

#include "STD_TYPES.h"

u8  MemScanner_ReadByte(Ptr_t addr, u32 offset); /* [cite: 23] */
u16 MemScanner_ReadHalfWord(Ptr_t addr, u32 offset); /* [cite: 25] */
u32 MemScanner_ReadWord(Ptr_t addr, u32 offset); /* [cite: 26] */
void MemScanner_WriteByte(Ptr_t addr, u32 offset, u8 value); /* [cite: 27] */
void MemScanner_HexDump(Ptr_t addr, u32 count); /* [cite: 28] */
void MemScanner_MemFill(Ptr_t addr, u32 size, u8 value); /* [cite: 30] */
s32  MemScanner_MemCompare(Ptr_t addr1, Ptr_t addr2, u32 size); /* [cite: 32] */
s32  MemScanner_FindByte(Ptr_t addr, u32 size, u8 value); /* [cite: 34] */

#endif