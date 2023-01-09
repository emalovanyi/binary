# Binary work
<strong>Implementation of the project</strong><br>
The main goal of this work was to understand <strong>how numbers are stored in computer memory</strong> and <strong>to learn 2d arrays</strong> in practice.<br>
Below I will separately explain the meaning of each function that is presented in this project.<br>
# (De)encoding a character
<strong>Highlighting the problem of function <i>void encode_char</i></strong><br>
The idea behind this function was to write a program that does not return values, but fills the <strong>bits array</strong> with <strong>true</strong> or <strong>false</strong> values.<br>
The field will contain the value of the <strong>character</strong> in the binary system.<br>
<strong>Functions Call Example</strong>
```c
bool bits1[8];
encode_char('A', bits1);
for(int i = 0; i < 8; i++){
    printf("%d", bits1[i]);
}
printf("\n");
// prints: 01000001
```
<strong>Highlighting the problem of function <i>char decode_byte</i></strong><br>
The idea behind this function was to write a program that returns a character that has the same value in the ASCII table (in the decimal system) as written in the <strong>bits</strong> array in binary format.<br>
<strong>Functions Call Example</strong>
```c
bool bits2[8] = {0,1,0,0,0,0,0,1};
printf("%c\n", decode_byte(bits2));
// prints: A
```
# (De)Encoding a string
<strong>Highlighting the problem of function <i>void encode_string</i></strong><br>\
The idea behind this function was to write a program that does not return any value, but fills the <strong>bytes</strong> array with <strong>true</strong> or <strong>false</strong> values.<br>
The array will contain the ASCII character values from the <strong>string</strong> in binary, including the line terminator.<br>
<strong>Functions Call Example</strong>
```c
char* text = "Hello, how are you?";
const int len = strlen(text);
bool bytes1[len+1][8];
encode_string(text, bytes1);
for(int j = 0; j <= len; j++){
    printf("%c: ", text[j]);
    for(int i = 0; i < 8; i++){
        printf("%d", bytes1[j][i]);
    }
    printf("\n");
}
// prints:
// H: 01001000
// e: 01100101
// l: 01101100
// l: 01101100
// o: 01101111
// ,: 00101100
//  : 00100000
// h: 01101000
// o: 01101111
// w: 01110111
//  : 00100000
// a: 01100001
// r: 01110010
// e: 01100101
//  : 00100000
// y: 01111001
// o: 01101111
// u: 01110101
// ?: 00111111
// : 00000000
```
<strong>Highlighting the problem of function <i>void decode_bytes</i></strong><br>
The idea behind this function was to write a program that does not return any value, but fills the <strong>string</strong> with characters by decoding the data from bytes.<br>
The bytes array contains exactly 1 byte (8 bits) per row, consisting of <strong>true</strong> or <strong>false</strong> values that represent the ASCII value of the characters in binary, including the line terminator.<br>
<strong>Functions Call Example</strong>
```c
bool bytes2[7][8] = {
    {0,1,0,0,1,0,0,0},
    {0,1,1,0,0,1,0,1},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,1,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,0,0,0,0,0}
};
char string[7];
decode_bytes(7, bytes2, string);
printf("%s\n", string);
// prints: Hello!
```

