#ifndef _FUNCTION_TYPE_HEADER
#define _FUNCTION_TYPE_HEADER

enum FunctionType {
    FUNCTION_COS,       //  cos(x)
    FUNCTION_SIN,       //  sin(x)
    FUNCTION_TG,        //  tg(x)
    FUNCTION_CTG,       //  ctg(x)
    FUNCTION_LOG,       //  log(base, x)
    FUNCTION_LN,        //  ln(x)
    FUNCTION_SQRT,      //  sqrt(x)
    FUNCTION_POW,       //  pow(x)
    FUNCTION_ABS,       //  abs(x)
    FUNCTION_EXP,       //  exp(x)
    FUNCTION_REAL,      //  real(x)
    FUNCTION_IMAG,      //  imag(x)
    FUNCTION_MAG,       //  ????(x)
    FUNCTION_PHASE,     //  ????(x)
    FUNCTION_NULL       // Not assigned function
};
typedef enum FunctionType FunctionType;

int globalGetFunctionTypeNumber();
char* globalGetFunctionByIndex(int index);

#endif