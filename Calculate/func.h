#ifndef CALC
#define CALC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


int isHexdigit(char c);
int isOctdigit(char c);
int isDuodigit(char c);
long int convertToDecimal(char* num);
int inputCount(char* operand1, char* operand2, char oper, char* input, char** rett);

void convertToHex(long int num);
void convertToOct(long int num);
void convertToDuo(long int num);
void rev(char* mass);
void output(char* operand1, char* operand2, char oper, long int operand1Dec, long int operand2Dec);
void outputDenial(char* operand1, char oper, long int operand1Dec);
void tilda(long int num);
void tildaOct(long int num);
void tildaHex(long int num);

char* convertToOctrev(long int num);
char* convertToHexrev(long int num);
char* convertToDuoret(long int num);

bool check(char* operand1, char* operand2, char oper);
bool checkDenial(char* operand1, char oper);
bool checkOperator(char* oper);


#endif // CALC

