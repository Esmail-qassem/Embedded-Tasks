#include "../inc/FixedPoint_interface.h"

fixed16_t static Fixed_FromFloat(float value)
{
	return FLOAT_TO_FIXP(value);
}
fixed16_t static Fixed_FromInt(uint8 integer)
{
	 return INT_TO_FIXP(integer);
}

uint32 static Fixed_ToInt(fixed16_t fixed)
{
	return (fixed>>FixedPoint_SHIFT);
}
float static Fixed_ToFloat(fixed16_t fixed)
{
	float Ret_Value=0;
	uint32 Fraction=0;
	uint16 Local_Variable=(fixed>>FixedPoint_SHIFT);
	Fraction=(((fixed & 0x0000ffff)*100/(FixedPoint_SCALE)));
	Ret_Value=((float)Local_Variable+((float)Fraction+1.0)/100.0);
	return (Ret_Value);
}


fixed16_t Fixed_Add(float a, float b)
{
	fixed16_t Val1=0;
	fixed16_t Val2=0;
	Val1=Fixed_FromFloat(a);
	Val2=Fixed_FromFloat(b);

	return (Val1+Val2);
}

fixed16_t Fixed_Sub(float a, float b)
{
	fixed16_t Val1=0;
	fixed16_t Val2=0;
	Val1=Fixed_FromFloat(a);
	Val2=Fixed_FromFloat(b);

	return (Val1-Val2);


}

fixed16_t Fixed_Mul(float a, float b)
{
	fixed16_t Val1=0;
	fixed16_t Val2=0;
	uint32 Result=0;
	Val1=Fixed_FromFloat(a);
	Val2=Fixed_FromFloat(b);
	Result= MULT_FIXED(Val1,Val2);
return (Result);
}

fixed16_t Fixed_Div(float a, float b)
{


}
