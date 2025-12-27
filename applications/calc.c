#include "tty.h"
//conv string 2 integer
int string_to_int(const char* str, int length) {
    int result = 0;
    for (int i = 0; i < length; i++) {
        result = result * 10 + (str[i] - '0');  //char to int
    }
    return result;
}

char* int_to_string(int num) {
    static char buffer[12];
    int i = 0;
    int is_negative = 0;
    
    if (num < 0) {
        is_negative = 1;
        num = -num;
    }
    
    if (num == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return buffer;
    }
    
    while (num > 0) {
        buffer[i] = '0' + (num % 10);
        num = num / 10;
        i++;
    }
    
    if (is_negative) {
        buffer[i] = '-';
        i++;
    }
    
    buffer[i] = '\0';
    
    // Reverse
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = temp;
        start++;
        end--;
    }
    
    return buffer;
}

char* calc(const char* string) {
    char firstnum[20];
    int firstnumsize = 0;
    char operator;
    char secondnum[20];
    int secondnumsize = 0;
    
    int pos = 5;  // Skip "calc "
    
    // Get first number
    while (string[pos] != ' ' && string[pos] != '\0') {
        firstnum[firstnumsize] = string[pos];  // Fixed index!
        firstnumsize++;
        pos++;
    }
    firstnum[firstnumsize] = '\0';  // Null terminate
    
    // Skip space
    pos++;
    
    // Get operator
    operator = string[pos];
    pos++;
    
    // Skip space
    pos++;
    
    // Get second number
    while (string[pos] != '\0') {
        secondnum[secondnumsize] = string[pos];
        secondnumsize++;
        pos++;
    }
    secondnum[secondnumsize] = '\0';  // Null terminate
    
    // Convert to integers (fixed!)
    int fn = string_to_int(firstnum, firstnumsize);
    int sn = string_to_int(secondnum, secondnumsize);
    
    // Calculate
    int result;
    if (operator == '+') result = fn + sn;
    else if (operator == '-') result = fn - sn;
    else if (operator == '*') result = fn * sn;
    else if (operator == '/') {
        if (sn == 0) return "Error: Division by zero";
        result = fn / sn;
    }
    else return "Error: Invalid operator";
    
    return int_to_string(result);
}