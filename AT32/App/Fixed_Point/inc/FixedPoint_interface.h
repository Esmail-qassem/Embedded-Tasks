#ifndef APP_FIXED_POINT_INC_FIXEDPOINT_INTERFACE_H_
#define APP_FIXED_POINT_INC_FIXEDPOINT_INTERFACE_H_
#include "../../../BSW/LIB/STD_TYPES.h"
#include "../../../BSW/LIB/BIT_MATH.h"
#include "../inc/FixedPoint_private.h"
#include "../inc/FixedPoint_config.h"



fixed32_t Fixed_Add(fixed32_t a, fixed32_t b);

fixed32_t Fixed_Sub(fixed32_t a, fixed32_t b);

fixed32_t Fixed_Mul(fixed32_t a, fixed32_t b);

fixed32_t Fixed_Div(fixed32_t a, fixed32_t b);

fixed32_t Fixed_FromInt(uint32 integer);

uint32 Fixed_ToInt(fixed32_t fixed);

fixed32_t Fixed_FromFloat(float value);

float Fixed_ToFloat(fixed32_t fixed);


#endif /* APP_FIXED_POINT_INC_FIXEDPOINT_INTERFACE_H_ */
