#ifndef APP_FIXED_POINT_INC_FIXEDPOINT_INTERFACE_H_
#define APP_FIXED_POINT_INC_FIXEDPOINT_INTERFACE_H_
#include "../../../BSW/LIB/STD_TYPES.h"
#include "../../../BSW/LIB/BIT_MATH.h"

typedef uint16 fixed16_t; // 32-bit fixed-point representation

#define FixedPoint_SHIFT    8
#define FixedPoint_SCALE    256u
#define FP_SHIFT(n)  ((n)<<FixedPoint_SHIFT)  // Scale factor (e.g., Q8.8 format)
#define INT_TO_FIXP(n) ((fixed16_t)(FP_SHIFT(n)))
#define FLOAT_TO_FIXP(n) ((fixed16_t)((((n)*FixedPoint_SCALE) + 0.5f)))
#define MULT_FIXED(n1,n2)  (fixed16_t)(((uint32)(n1)*(uint32)(n2))>>FixedPoint_SHIFT)

fixed16_t Fixed_Add(float a, float b);

fixed16_t Fixed_Sub(float a, float b);

fixed16_t Fixed_Mul(float a, float b);

fixed16_t Fixed_Div(float a, float b);


#endif /* APP_FIXED_POINT_INC_FIXEDPOINT_INTERFACE_H_ */
