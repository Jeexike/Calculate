#ifndef CALC
#define CALC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int isHexdigit(char c);
int isOctdigit(char c);
int isDuodigit(char c);
int convertToDecimal(char* num);
void convertToHex(int num);
char* convertToHexrev(int num);
void convertToOct(int num);
char* convertToOctrev(int num);
void convertToDuo(int num);
char* convertToDuoret(int num);
void rev(char* mass);
void chek(char* operand1, char* operand2, char* oper);
char** operandsOper(char* operand1, char* operand2, char oper, char* token);

#endif // CALC

