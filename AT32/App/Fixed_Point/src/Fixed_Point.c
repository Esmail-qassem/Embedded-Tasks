#include "../inc/FixedPoint_interface.h"

fixed32_t Fixed_FromFloat(float value)
{
	return FLOAT_TO_FIXP(value);
}
fixed32_t Fixed_FromInt(uint32 integer)
{
	 return INT_TO_FIXP(integer);
}

uint32 Fixed_ToInt(fixed32_t fixed)
{
	return (fixed>>FixedPoint_SHIFT);
}
float Fixed_ToFloat(fixed32_t fixed)
{
	float Ret_Value=0;
	uint32 Fraction=0;
	uint16 Local_Variable=(fixed>>FixedPoint_SHIFT);
	Fraction=(((fixed & 0x0000ffff)*100/(FixedPoint_SCALE)));
	Ret_Value=((float)Local_Variable+((float)Fraction+1.0)/100.0);
	return (Ret_Value);
}

fixed32_t Fixed_Add(fixed32_t a, fixed32_t b);

fixed32_t Fixed_Sub(fixed32_t a, fixed32_t b);

fixed32_t Fixed_Mul(fixed32_t a, fixed32_t b);

fixed32_t Fixed_Div(fixed32_t a, fixed32_t b);
