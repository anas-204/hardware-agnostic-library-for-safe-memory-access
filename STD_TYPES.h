#ifndef STD_TYPES_H
#define STD_TYPES_H

#include <stdint.h>

/* Fixed-width unsigned integer types */
typedef uint8_t  u8;  /* [cite: 8] */
typedef uint16_t u16; /* [cite: 8] */
typedef uint32_t u32; /* [cite: 8] */

/* Fixed-width signed integer types */
typedef int8_t   s8;  /* [cite: 8] */
typedef int16_t  s16; /* [cite: 8] */
typedef int32_t  s32; /* [cite: 8] */

/* Boolean type */
typedef enum {
    FALSE = 0,
    TRUE  = 1
} bool; /* [cite: 9] */

/* Standard function return type */
typedef enum {
    E_OK,
    E_NOT_OK
} ErrorStatus; /* [cite: 10] */

/* Generic pointer for raw memory access */
typedef void* Ptr_t; /* [cite: 11] */

#endif /* STD_TYPES_H */