#include <stdio.h>

int power(int base, int power) {
    if (power == 0) {
        return 1;
    }
    int out = 1;
    for(int i=1; i<=power; i++) {
        out *= base; 
    }
    return out;
}

int checkLength(char *input) {
    int counter = 0;
    while(*input != '\0') {
        counter++;
        input++;
    }
    return counter;
}

int toInt(char input[]) {
    int out = 0;
    int len = checkLength(input);
    for(int i=0; i < len; i++) {
        out += (input[i] - '0') * power(10, len-i-1);
    }
    return out;
}

int str2Int(char input[]) {
    char out[10000];
    int lenInput = checkLength(input);
    for(int i=0; i < lenInput; i++) {
        if(input[i] >= '0' && input[i] <= '9') {
            int outLen = checkLength(out);
            out[outLen] = input[i];
            out[outLen+1] = '\0';
        }
    }
    
    int result = toInt(out);
    out[0] = '\0';
    
    return result;
    
}

int main()
{
    char c[] = "2a1a4a7a4a8a3a6a4a7";
    int result1 = str2Int(c);
    printf("result 1: %d \n", result1);
    
    // Exceed integer case
    char over[] = "21a47483648";
    int resultOver = str2Int(over);
    printf("result over: %d \n", resultOver);
    
    char k[] = "2df1dd/A/0k9";
    int result2 = str2Int(k);
    printf("result 2: %d \n", result2);
    
    char s[] = "λέξη Σ-2\tΦ-Σ-ΦΑνά\nλο1γα μ0ε 9τη συσκε";
    int result3 = str2Int(s);
    printf("result 3: %d \n", result3);
    return 0;
}
