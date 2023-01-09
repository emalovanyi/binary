#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

//function_1
void encode_char(const char character, bool bits[8]){
    int i; //about bits
    int char_2;

    int alph = character;
    char_2 = alph;
    bits[0] = 0;

    for(i = 7; i >= 0; i--, char_2 = char_2 / 2){
        bits[i] = char_2 & 1;
    }
}
//function_1

//function_2
char decode_byte(const bool bits[8]){
    int a;
    int b = 0;

    for(a = 0; a < 7; a++){
        b += ((1 << a) * bits [7 - a]);
    }
    return b;
}
//function_2

//function_3
void encode_string(const char string[], bool bytes[strlen(string)+1][8]){
    int i = 0;

    int a;
    int b;

    int tb;
    int tb_2;

    int z;
    int w;

    const int str = strlen(string);

    for(a = 0; a <= str; a++){
        tb = string[a];
        tb_2 = tb;
        for(b = 7; b > 0; b--){
            z = tb_2 / 2;
            w = tb_2 % 2;
            if(w != i){
                bytes[a][b] = 1;
            }
            if(w == i){
                bytes[a][b] = 0;
            }
            tb_2 = z;
        }
        bytes[a][0] = i;
    }
}
//function_3

//function_4
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]){
    int i;
    int j;
    int r = rows;

    for(i = 0; i < r; i++){
        string[i] = 0;
        for(j = 0; j <= 7 ; j++){
            double result = pow(2,7 - j);
            string[i] += (bytes[i][j] * result);
        }
    string[r] = '\0';
    }
}
//function_4

//function_5
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
    int a;
    int b;
    int c;
    int d = 0;

    for(a = 0; a < offset * 8; a++){
        for(b = 0; b < cols; b++){
            blocks[a][b] = 0;

            if(a < 8){
                blocks[a][b] = bytes[b][a];
            }
            else if(a > 8 && a < 16){
                blocks[a][b] = bytes[b + cols][a - 8];
                if(blocks[a][b] == '\0'){
                    for(c = 8; c < offset * 8; c++){
                        blocks[a][b] = '\0';
                    }
                }
            }

            while(a > 80 && b < 160){
                d = cols * 1;
                blocks[a][b] = bytes[d + b][a - 80];
                if(blocks[a][b] == '\0'){
                    for(c = 80; c < 160; c++){
                        blocks[a][b] = '\0';
                    }
                }
            }
        }
    }
}
//function_5

//function_6
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
    int a;
    int b;

    for(a = 0; a < rows; a++){
        for(b = 0; b < 8; b++){
            bytes[a][b] = 0;
        }
    }

    for(a = 0; a < offset * 8; a++){
        for(b = 0; b < cols; b++){

            if(a < 8){
                bytes[b][a] = blocks[a][b];
            }
            else if(a > 8 && a < 16){
                bytes[cols + b][a - 8] = blocks[a][b];
            }

            while(a > 80 && a < 160){
                bytes[cols + b][a - 80] = blocks[a][b];
            }
        }
    }
}
//function_6

//main_function
int main(){
    return 0;
}
//main_function
