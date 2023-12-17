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
int convertToDecimal(char* num);
int inputCount(char* operand1, char* operand2, char oper, char* input, char** rett);

void convertToHex(int num);
void convertToOct(int num);
void convertToDuo(int num);
void rev(char* mass);
void output(char* operand1, char* operand2, char oper, int operand1Dec, int operand2Dec);
void outputDenial(char* operand1, char oper, int operand1Dec);
void tilda(long int num);
void tildaOct(long int num);
void tildaHex(long int num);

char* convertToOctrev(int num);
char* convertToHexrev(int num);
char* convertToDuoret(int num);
char** denial(char* mass);

bool check(char* operand1, char* operand2, char oper);
bool checkDenial(char* operand1, char oper);
bool checkOperator(char* oper);


#endif // CALC

