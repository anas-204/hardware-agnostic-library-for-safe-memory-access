#ifndef STD_TYPES_H
#define STD_TYPES_H

#include <stdint.h>

/* Fixed-width unsigned integer types [cite: 8] */
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;

/* Fixed-width signed integer types [cite: 8] */
typedef int8_t   s8;
typedef int16_t  s16;
typedef int32_t  s32;

/* Boolean type [cite: 9] */
typedef enum {
    FALSE = 0,
    TRUE  = 1
} bool;

/* Standard function return type [cite: 10] */
typedef enum {
    E_OK,
    E_NOT_OK
} ErrorStatus;

/* Generic pointer for raw memory access [cite: 11] */
typedef void* Ptr_t; //test

#endif /* STD_TYPES_H [cite: 12] */