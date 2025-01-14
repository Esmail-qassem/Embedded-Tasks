
#ifndef APP_FIXED_POINT_INC_FIXEDPOINT_PRIVATE_H_
#define APP_FIXED_POINT_INC_FIXEDPOINT_PRIVATE_H_

typedef uint32 fixed32_t; // 32-bit fixed-point representation

#define FixedPoint_SHIFT    16
#define FixedPoint_SCALE    65535u
#define FP_SHIFT(n)  (n<<FixedPoint_SHIFT)  // Scale factor (e.g., Q16.16 format)
#define INT_TO_FIXP(n) ((fixed32_t)(FP_SHIFT(n)))
#define FLOAT_TO_FIXP(n) ((fixed32_t)((float)(n*FixedPoint_SCALE)))

#endif /* APP_FIXED_POINT_INC_FIXEDPOINT_PRIVATE_H_ */
