#ifndef BIT_MATH_H
#define BIT_MATH_H

/* Set a bit to 1 [cite: 16] */
#define SET_BIT(VAR, BIT)          ((VAR) |=  (1ULL << (BIT)))

/* Clear a bit to 0 [cite: 16] */
#define CLR_BIT(VAR, BIT)          ((VAR) &= ~(1ULL << (BIT)))

/* Toggle a bit [cite: 16] */
#define TOGGLE_BIT(VAR, BIT)       ((VAR) ^=  (1ULL << (BIT)))

/* Read the value of a single bit [cite: 16] */
#define GET_BIT(VAR, BIT)          (((VAR) >> (BIT)) & 0x01ULL)

/* Write a value into a bit-field region [cite: 18] */
#define WRITE_FIELD(VAR, MASK, BIT, VAL) \
((VAR) = ((VAR) & ~((u8)(MASK) << (BIT))) | (((u8)(VAL) & (u8)(MASK)) << (BIT)))

/* Read a value from a bit-field region [cite: 19] */
#define READ_FIELD(VAR, MASK, BIT) (((VAR) >> (BIT)) & (MASK))

/* Set multiple bits via a mask [cite: 17] */
#define SET_MASK(VAR, MASK)        ((VAR) |= (MASK))

/* Clear multiple bits via a mask [cite: 17] */
#define CLR_MASK(VAR, MASK)        ((VAR) &= ~(MASK))

#endif /* BIT_MATH_H */