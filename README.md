# Binary work
<strong>Implementation of the project</strong><br>
The main goal of this work was to understand <strong>how numbers are stored in computer memory</strong> and <strong>to learn 2d arrays</strong> in practice.<br>
Below I will separately explain the meaning of each function that is presented in this project.<br>
# (De)encoding a character
<strong>Highlighting the problem</strong><br>
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

bool bits2[8] = {0,1,0,0,0,0,0,1};
printf("%c\n", decode_byte(bits2));
// prints: A
```
