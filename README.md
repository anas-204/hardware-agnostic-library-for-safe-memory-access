# Embedded Communication Link & Memory Scanner

## Objective

Develop a reusable, hardware-agnostic library for safe memory access, and use it to build a simple message encoder/decoder for a simulated embedded communication link. This project demonstrates core embedded systems concepts including bit manipulation, pointer arithmetic, memory inspection, and data serialization.

## Features

### 1. Foundation Library

- **Portable Types (`STD_TYPES.h`)**  
  Maps all project types to `<stdint.h>` to ensure hardware-agnostic sizes (8, 16, 32-bit integers) without using raw C types.

- **Bit Manipulation (`BIT_MATH.h`)**  
  A MISRA-C compliant macro library for safe bitwise operations (Set, Clear, Toggle, Read, and Write into bit-fields).

### 2. Memory Scanner (`MemScanner`)

An embedded debugger simulation module capable of:

- Reading 8-bit, 16-bit (Little-Endian), and 32-bit (Little-Endian) values from raw memory.
- Writing bytes directly to memory offsets.
- Providing a formatted Hex Dump of memory regions.
- Filling, comparing, and searching byte-by-byte within memory blocks.

### 3. Message Encoder / Decoder (`Message`)

A communication simulation that packs and unpacks structured data into a fixed 6-byte contiguous buffer.

- **Header (1 byte)**: Bit-packed with Message Type, Priority flag, and an auto-incrementing Sequence Number.
- **Payload (4 bytes)**: Uses unions to interpret the same 4 bytes as single 32-bit values, two 16-bit values, or an array of bytes depending on the message type (Sensor Reading vs. Device Command).
- **Callback Registration**: Uses function pointers to register handlers that automatically trigger upon successful message decoding.

## Project Structure

```plaintext
├── BIT_MATH.h       # Bit manipulation macros
├── STD_TYPES.h      # Hardware-agnostic type definitions
├── MemScanner.h     # Memory scanner function prototypes
├── MemScanner.c     # Memory scanner implementation
├── Message.h        # Message structures, payload unions, and enums
├── Message.c        # Encoder/Decoder and sequence number logic
└── main.c           # Demonstration and testing script

