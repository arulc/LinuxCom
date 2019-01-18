#ifndef LC_DEBUG_H
#define LC_DEBUG_H

//
// printf_error
// printf_succ
#define _printf(...) printf(__VA_ARGS__)

#define printV(v) _printf("===>" #v " = %d\n", v);
#define printVV(v1, v2) _printf("===>" #v1 " = %d," #v2 "=%d\n", v1, v2);

#define printS(_string) _printf("===>" #_string "= %s\n", _string);
#define printSV(_string, _int) _printf("===>" #_string " = %s, " #_int " = %d\n", _string, _int);

#define printFV(_int) _printf("===>%s(), " #_int " = %d\n", __FUNCTION__, _int);
#define printLV(_int) _printf("===>L:%d, " #_int " = %d\n", __LINE__, _int);
#define printFLV(_int) _printf("===>%s()--L:%d " #_int " = %d\n", __FUNCTION__, __LINE__, _int);
#define printLN _printf("===>%s()--L:%d \n", __FUNCTION__, __LINE__)
#define PRINTHead _printf("==> Function : %s Started ----------Line:%d \n",__FUNCTION__, __LINE__)

#endif
