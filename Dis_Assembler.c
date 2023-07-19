#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int k = 0;
int m = 1;
char Finals[25][30];
int a = 0;

char temp1[6];
char temp2[6];
char temp3[6];
char f3[4];
char f7[8];

char *Strrev(char *str)
{
    char str1[33];
    for (int i = 0; i <= 31; i++)
    {
        str1[i] = str[31 - i];
    }
    str1[32] = '\0';
    char *str2 = str1;
    return str2;
}

int DecConvert(char *str)
{
    int c = 0;
    int sum = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        c = (int)(str[i] - '0');
        sum = sum + c * pow(2, i);
    }
    return sum;
}

int DecConvertIL(char *str)
{
    int c = 0;
    int sum = 0;
    int n = strlen(str);
    if (str[n - 1] == '0')
    {
        for (int i = 0; i < n; i++)
        {
            c = (int)(str[i] - '0');
            sum = sum + c * pow(2, i);
        }
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            c = (int)(str[i] - '0');
            sum = sum + c * pow(2, i);
        }
        sum = sum - pow(2, n - 1);
    }
    return sum;
}

int DecConvertf6(char *str)
{
    int c = 0;
    int sum = 0;
    for (int i = 0; i <= 5; i++)
    {
        c = (int)(str[i] - '0');
        sum = sum + c * pow(2, i);
    }
    return sum;
}

char *BinHexConvert(char *str)
{
    int c = 0;
    int sum = 0;
    int m[5];
    int j = 0;
    int a = 0;
    for (int i = 0; i <= 19; i++)
    {
        c = (int)(str[i] - '0');
        sum = sum + c * pow(2, a);
        a++;
        if ((i + 1) % 4 == 0)
        {
            m[j] = sum;
            sum = 0;
            a = 0;
            j++;
        }
    }
    char hex[5];
    for (int i = 0; i <= 4; i++)
    {
        c = m[4 - i];
        if (c < 10)
        {
            hex[i] = c + '0';
        }
        else
        {
            c = c - 10;
            hex[i] = c + 'a';
        }
    }
    char *hex1 = hex;
    return hex1;
}

int Strcmp(char *s, char *t)
{
    int c = 0;
    for (int i = 0; i <= 5; i++)
    {
        if (s[11 - i] == t[i])
        {
            c++;
        }
    }
    if (c == 6)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void RFormat()
{
    int rd = DecConvert(temp1);
    int rs1 = DecConvert(temp2);
    int rs2 = DecConvert(temp3);
    char temp[4];
    if (strcmp(f3, "000") == 0 && strcmp(f7, "0000000") == 0)
    {
        strcpy(temp, "add");
    }
    else if (strcmp(f3, "000") == 0 && strcmp(f7, "0000010") == 0)
    {
        strcpy(temp, "sub");
    }
    else if (strcmp(f3, "001") == 0 && strcmp(f7, "0000000") == 0)
    {
        strcpy(temp, "xor");
    }
    else if (strcmp(f3, "011") == 0 && strcmp(f7, "0000000") == 0)
    {
        strcpy(temp, "or");
    }
    else if (strcmp(f3, "111") == 0 && strcmp(f7, "0000000") == 0)
    {
        strcpy(temp, "and");
    }
    else if (strcmp(f3, "100") == 0 && strcmp(f7, "0000000") == 0)
    {
        strcpy(temp, "sll");
    }
    else if (strcmp(f3, "101") == 0 && strcmp(f7, "0000000") == 0)
    {
        strcpy(temp, "srl");
    }
    else if (strcmp(f3, "101") == 0 && strcmp(f7, "0000010") == 0)
    {
        strcpy(temp, "sra");
    }
    else
    {
        printf("Invalid Entry\n");
        return;
    }
    char ptr1[45];
    sprintf(ptr1, "%s x%d, x%d, x%d", temp, rd, rs1, rs2);
    strcat(Finals[k], ptr1);
    k++;
}

void IFormat()
{
    char temp[5];
    char Imm[12];
    strcpy(Imm, temp3);
    strcat(Imm, f7);
    int rd = DecConvert(temp1);
    int rs1 = DecConvert(temp2);
    int imm = DecConvertIL(Imm);
    if (strcmp(f3, "000") == 0)
    {
        strcpy(temp, "addi");
    }
    else if (strcmp(f3, "001") == 0)
    {
        strcpy(temp, "xori");
    }
    else if (strcmp(f3, "011") == 0)
    {
        strcpy(temp, "ori");
    }
    else if (strcmp(f3, "111") == 0)
    {
        strcpy(temp, "andi");
    }
    else if (strcmp(f3, "100") == 0 && Strcmp(Imm, "000000") == 0)
    {
        strcpy(temp, "slli");
        imm = DecConvertf6(Imm);
    }
    else if (strcmp(f3, "101") == 0 && Strcmp(Imm, "000000") == 0)
    {
        strcpy(temp, "srli");
        imm = DecConvertf6(Imm);
    }
    else if (strcmp(f3, "101") == 0 && Strcmp(Imm, "010000") == 0)
    {
        strcpy(temp, "srai");
        imm = DecConvertf6(Imm);
    }
    else
    {
        printf("Invalid Entry\n");
    }
    char ptr1[45];
    sprintf(ptr1, "%s x%d, x%d, %d", temp, rd, rs1, imm);
    strcat(Finals[k], ptr1);
    k++;
}

void ILFormat()
{
    char temp[5];
    char Imm[12];
    strcpy(Imm, temp3);
    strcat(Imm, f7);
    int rd = DecConvert(temp1);
    int rs1 = DecConvert(temp2);
    int imm = DecConvertIL(Imm);
    if (strcmp(f3, "000") == 0)
    {
        strcpy(temp, "lb");
    }
    else if (strcmp(f3, "100") == 0)
    {
        strcpy(temp, "lh");
    }
    else if (strcmp(f3, "010") == 0)
    {
        strcpy(temp, "lw");
    }
    else if (strcmp(f3, "110") == 0)
    {
        strcpy(temp, "ld");
    }
    else if (strcmp(f3, "001") == 0)
    {
        strcpy(temp, "lbu");
    }
    else if (strcmp(f3, "101") == 0)
    {
        strcpy(temp, "lhu");
    }
    else if (strcmp(f3, "011") == 0)
    {
        strcpy(temp, "lwu");
    }
    char ptr1[45];
    sprintf(ptr1, "%s x%d, %d(x%d)", temp, rd, imm, rs1);
    strcat(Finals[k], ptr1);
    k++;
}

void SFormat()
{
    char temp[5];
    char Imm[12];
    strcpy(Imm, temp1);
    strcat(Imm, f7);
    int rs1 = DecConvert(temp2);
    int rs2 = DecConvert(temp3);
    int imm = DecConvertIL(Imm);
    if (strcmp(f3, "000") == 0)
    {
        strcpy(temp, "sb");
    }
    else if (strcmp(f3, "100") == 0)
    {
        strcpy(temp, "sh");
    }
    else if (strcmp(f3, "010") == 0)
    {
        strcpy(temp, "sw");
    }
    else if (strcmp(f3, "110") == 0)
    {
        strcpy(temp, "sd");
    }
    char ptr1[45];
    sprintf(ptr1, "%s x%d, %d(x%d)", temp, rs2, imm, rs1);
    strcat(Finals[k], ptr1);
    k++;
}

void BFormat()
{
    char temp[5];
    char Imm[13];
    Imm[0] = '0';
    for (int i = 1; i < 5; i++)
    {
        Imm[i] = temp1[i];
    }
    Imm[11] = temp1[0];
    for (int i = 5; i <= 10; i++)
    {
        Imm[i] = f7[i - 5];
    }
    Imm[12] = f7[6];
    int rs1 = DecConvert(temp2);
    int rs2 = DecConvert(temp3);
    int imm = DecConvertIL(Imm);
    if (strcmp(f3, "000") == 0)
    {
        strcpy(temp, "beq");
    }
    else if (strcmp(f3, "100") == 0)
    {
        strcpy(temp, "bne");
    }
    else if (strcmp(f3, "001") == 0)
    {
        strcpy(temp, "blt");
    }
    else if (strcmp(f3, "101") == 0)
    {
        strcpy(temp, "bge");
    }
    else if (strcmp(f3, "011") == 0)
    {
        strcpy(temp, "bltu");
    }
    else if (strcmp(f3, "111") == 0)
    {
        strcpy(temp, "bgeu");
    }
    a = imm / 4;
    char tra[5];

    if (Finals[k + a][0] != 'L')
    {
        sprintf(tra, "L%d", m);
        char ptr[45];
        sprintf(ptr, "L%d: %s", m, Finals[k + a]);
        Finals[k + a][0] = '\0';
        strcat(Finals[k + a], ptr);
        m++;
    }
    else
    {
        strncpy(tra, Finals[k + a], 2);
    }
    tra[2] = '\0';
    char ptr1[45];
    sprintf(ptr1, "%s x%d, x%d, %s\n", temp, rs1, rs2, tra);
    strcat(Finals[k], ptr1);
    k++;
}

void JFormat()
{
    char temp[20];
    char Imm[32];
    strcpy(temp, f3);
    strcat(temp, temp2);
    strcat(temp, temp3);
    strcat(temp, f7);
    int rd = DecConvert(temp1);
    for (int i = 0; i <= 31; i++)
    {
        Imm[i] = '0';
    }
    for (int i = 12; i <= 19; i++)
    {
        Imm[i] = temp[12 - i];
    }
    for (int i = 1; i <= 10; i++)
    {
        Imm[i] = temp[i + 8];
    }
    Imm[11] = temp[8];
    Imm[20] = temp[19];
    int imm = DecConvertIL(Imm);
    a = imm / 4;
    char tra[5];
    if (Finals[k + a][0] != 'L')
    {
        sprintf(tra, "L%d", m);
        char ptr[45];
        sprintf(ptr, "L%d: %s", m, Finals[k + a]);
        Finals[k + a][0] = '\0';
        strcat(Finals[k + a], ptr);
        m++;
    }
    else
    {
        strncpy(tra, Finals[k + a], 2);
    }
    tra[2] = '\0';
    char ptr1[45];
    sprintf(ptr1, "jal x%d, %s\n", rd, tra);
    strcat(Finals[k], ptr1);
    k++;
}

void JIFormat()
{
    char temp[4];
    char Imm[12];
    strcpy(Imm, temp3);
    strcat(Imm, f7);
    int rd = DecConvert(temp1);
    int rs1 = DecConvert(temp2);
    int imm = DecConvertIL(Imm);
    char ptr1[45];
    sprintf(ptr1, "jalr x%d, x%d, %d\n", rd, rs1, imm);
    strcat(Finals[k], ptr1);
    k++;
}

void UFormat()
{
    char temp[20];
    char Imm[20];
    char imm[5];
    strcpy(temp, f3);
    strcat(temp, temp2);
    strcat(temp, temp3);
    strcat(temp, f7);
    for (int i = 0; i <= 19; i++)
    {
        Imm[i] = temp[i];
    }
    int rd = DecConvert(temp1);
    strcpy(imm, BinHexConvert(Imm));
    char ptr1[45];
    sprintf(ptr1, "lui x%d, 0x%s\n", rd, imm);
    strcat(Finals[k], ptr1);
    k++;
}

char *BinConvert(char *str, char str1[][5])
{
    char *temp;
    temp = (char *)malloc(34 * sizeof(char));
    int c = 0;
    for (int i = 0; i < 8; i++)
    {
        c = (int)(str[i]);
        if (c <= 57)
        {
            c = c - 48;
            strncat(temp, str1[c], 4);
        }
        else
        {
            c = c - 87;
            strncat(temp, str1[c], 4);
        }
    }
    return Strrev(temp);
}

char *HexConvert(int i)
{
    char s[5];
    for (int j = 0; j < 4; j++)
    {
        s[3 - j] = i % 2 + '0';
        i = i / 2;
    }
    s[4] = '\0';
    char *str = s;
    return str;
}

int main()
{
    char str[8];
    while (1)
    {
        scanf("%s", str);
        if (strcmp(str, "-1") == 0)
        {
            break;
        }
        char str1[16][5];
        for (int i = 0; i < 16; i++)
        {
            strcpy(str1[i], HexConvert(i));
        }

        char str2[33];
        strncpy(str2, BinConvert(str, str1), 33);
        strncpy(temp1, str2 + 7, 5);
        strncpy(temp2, str2 + 15, 5);
        strncpy(temp3, str2 + 20, 5);
        strncpy(f3, str2 + 12, 3);
        strncpy(f7, str2 + 25, 7);
        if (strncmp(str2, "1100110", 7) == 0)
        {
            RFormat();
        }
        else if (strncmp(str2, "1100100", 7) == 0)
        {
            IFormat();
        }
        else if (strncmp(str2, "1100000", 7) == 0)
        {
            ILFormat();
        }
        else if (strncmp(str2, "1100010", 7) == 0)
        {
            SFormat();
        }
        else if (strncmp(str2, "1100011", 7) == 0)
        {
            BFormat();
        }
        else if (strncmp(str2, "1111011", 7) == 0)
        {
            JFormat();
        }
        else if (strncmp(str2, "1110011", 7) == 0 && strcmp(f3, "000") == 0)
        {
            JIFormat();
        }
        else if (strncmp(str2, "1110110", 7) == 0)
        {
            UFormat();
        }
        else
        {
            printf("Invalid entry\n");
        }
    }
    for (int i = 0; i <= k; i++)
    {
        printf("%s\n", Finals[i]);
    }
    return 0;
}

/*//Note: The below code is only using offset without using label(if labelling doesn't work, this can be used)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int k = 0;
char Finals[25][30];

char temp1[6];
char temp2[6];
char temp3[6];
char f3[4];
char f7[8];

char * Strrev(char * str)
{
char str1[33];
for(int i=0; i<=31; i++)
{
str1[i] = str[31-i];
}
str1[32] = '\0';
char * str2 = str1;
return str2;
}

int DecConvert(char * str)
{
int c = 0;
int sum = 0;
for(int i = 0; i < strlen(str); i++)
{
c = (int)(str[i] - '0');
sum = sum + c*pow(2, i);
}
return   sum;
}

int DecConvertIL(char * str)
{
int c = 0;
int sum = 0;
int n = strlen(str);
if(str[n-1] == '0')
{
for(int i = 0; i < n; i++)
{
c = (int)(str[i] - '0');
sum = sum + c*pow(2, i);
}
}
else
{
for(int i = 0; i < n-1; i++)
{
c = (int)(str[i] - '0');
sum = sum + c*pow(2, i);
}
sum = sum - pow(2, n-1);
}
return   sum;
}

int DecConvertf6(char * str)
{
int c = 0;
int sum = 0;
for(int i = 0; i <= 5; i++)
{
c = (int)(str[i] - '0');
sum = sum + c*pow(2, i);
}
return   sum;
}

char * BinHexConvert(char * str)
{
int c = 0;
int sum = 0;
int m[5];
int j = 0;
int a = 0;
for(int i=0; i<=19; i++)
{
c = (int)(str[i] - '0');
sum = sum + c*pow(2, a);
a++;
if((i+1)%4 == 0)
{
m[j] = sum;
sum = 0;
a = 0;
j++;
}
}
char hex[5];
for(int i=0; i<=4; i++)
{
c = m[4-i];
if(c < 10)
{
hex[i] = c + '0';
}
else
{
c = c - 10;
hex[i] = c + 'a';
}
}
char * hex1 = hex;
return   hex1;
}

int Strcmp(char * s, char * t)
{
    int c = 0;
    for(int i=0; i<=5; i++)
    {
        if(s[11-i] == t[i])
        {
            c++;
        }
    }
    if(c == 6)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void RFormat()
{
int rd = DecConvert(temp1);
int rs1 = DecConvert(temp2);
int rs2 = DecConvert(temp3);
char temp[4];
if(strcmp(f3, "000") == 0 && strcmp(f7, "0000000") == 0)
{
strcpy(temp, "add");
}
else if(strcmp(f3, "000") == 0 && strcmp(f7, "0000010") == 0)
{
strcpy(temp, "sub");
}
else if(strcmp(f3, "001") == 0 && strcmp(f7, "0000000") == 0)
{
strcpy(temp, "xor");
}
else if(strcmp(f3, "011") == 0 && strcmp(f7, "0000000") == 0)
{
strcpy(temp, "or");
}
else if(strcmp(f3, "111") == 0 && strcmp(f7, "0000000") == 0)
{
strcpy(temp, "and");
}
else if(strcmp(f3, "100") == 0 && strcmp(f7, "0000000") == 0)
{
strcpy(temp, "sll");
}
else if(strcmp(f3, "101") == 0&& strcmp(f7, "0000000") == 0)
{
strcpy(temp, "srl");
}
else if(strcmp(f3, "101") == 0&& strcmp(f7, "0000010") == 0)
{
strcpy(temp, "sra");
}
else
{
printf("Invalid Entry\n");
return   ;
}
sprintf(Finals[k], "%s x%d, x%d, x%d", temp, rd, rs1, rs2);
k++;
}

void IFormat()
{
char temp[5];
char Imm[12];
strcpy(Imm, temp3);
strcat(Imm, f7);
int rd = DecConvert(temp1);
int rs1 = DecConvert(temp2);
int imm = DecConvertIL(Imm);
if(strcmp(f3, "000") == 0)
{
strcpy(temp, "addi");
}
else if(strcmp(f3, "001") == 0)
{
strcpy(temp, "xori");
}
else if(strcmp(f3, "011") == 0)
{
strcpy(temp, "ori");
}
else if(strcmp(f3, "111") == 0)
{
strcpy(temp, "andi");
}
else if(strcmp(f3, "100") == 0 && Strcmp(Imm, "000000") == 0)
{
strcpy(temp, "slli");
imm = DecConvertf6(Imm);
}
else if(strcmp(f3, "101") == 0 && Strcmp(Imm, "000000") == 0)
{
strcpy(temp, "srli");
imm = DecConvertf6(Imm);
}
else if(strcmp(f3, "101") == 0 && Strcmp(Imm, "010000") == 0)
{
strcpy(temp, "srai");
imm = DecConvertf6(Imm);
}
else
{
printf("Invalid Entry\n");
}
sprintf(Finals[k], "%s x%d, x%d, %d", temp, rd, rs1, imm);
k++;
}

void ILFormat()
{
char temp[5];
char Imm[12];
strcpy(Imm, temp3);
strcat(Imm, f7);
int rd = DecConvert(temp1);
int rs1 = DecConvert(temp2);
int imm = DecConvertIL(Imm);
if(strcmp(f3, "000") == 0)
{
strcpy(temp, "lb");
}
else if(strcmp(f3, "100") == 0)
{
strcpy(temp, "lh");
}
else if(strcmp(f3, "010") == 0)
{
strcpy(temp, "lw");
}
else if(strcmp(f3, "110") == 0)
{
strcpy(temp, "ld");
}
else if(strcmp(f3, "001") == 0)
{
strcpy(temp, "lbu");
}
else if(strcmp(f3, "101") == 0)
{
strcpy(temp, "lhu");
}
else if(strcmp(f3, "011") == 0)
{
strcpy(temp, "lwu");
}
sprintf(Finals[k], "%s x%d, %d(x%d)", temp, rd, imm, rs1);
k++;
}

void SFormat()
{
char temp[5];
char Imm[12];
strcpy(Imm, temp1);
strcat(Imm, f7);
int rs1 = DecConvert(temp2);
int rs2 = DecConvert(temp3);
int imm = DecConvertIL(Imm);
if(strcmp(f3, "000") == 0)
{
strcpy(temp, "sb");
}
else if(strcmp(f3, "100") == 0)
{
strcpy(temp, "sh");
}
else if(strcmp(f3, "010") == 0)
{
strcpy(temp, "sw");
}
else if(strcmp(f3, "110") == 0)
{
strcpy(temp, "sd");
}
sprintf(Finals[k], "%s x%d, %d(x%d)", temp, rs2, imm, rs1);
k++;
}

void BFormat()
{
char temp[5];
char Imm[13];
Imm[0] = '0';
for(int i=1; i<5; i++)
{
Imm[i] = temp1[i];
}
Imm[11] = temp1[0];
for(int i=5; i<=10; i++)
{
Imm[i] = f7[i-5];
}
Imm[12] = f7[6];
int rs1 = DecConvert(temp2);
int rs2 = DecConvert(temp3);
int imm = DecConvertIL(Imm);
if(strcmp(f3, "000") == 0)
{
strcpy(temp, "beq");
}
else if(strcmp(f3, "100") == 0)
{
strcpy(temp, "bne");
}
else if(strcmp(f3, "001") == 0)
{
strcpy(temp, "blt");
}
else if(strcmp(f3, "101") == 0)
{
strcpy(temp, "bge");
}
else if(strcmp(f3, "011") == 0)
{
strcpy(temp, "bltu");
}
else if(strcmp(f3, "111") == 0)
{
strcpy(temp, "bgeu");
}
sprintf(Finals[k], "%s x%d, x%d, %d\n", temp, rs1, rs2, imm);
k++;
}

void JFormat()
{
char temp[20];
char Imm[32];
strcpy(temp, f3);
strcat(temp, temp2);
strcat(temp, temp3);
strcat(temp, f7);
int rd = DecConvert(temp1);
for(int i=0;i<=31; i++)
{
Imm[i] = '0';
}
for(int i=12;i<=19; i++)
{
Imm[i] = temp[12-i];
}
for(int i=1;i<=10; i++)
{
Imm[i] = temp[i+8];
}
Imm[11] = temp[8];
Imm[20] = temp[19];
int imm = DecConvertIL(Imm);
sprintf(Finals[k], "jal x%d, %d\n", rd, imm);
k++;
}

void JIFormat()
{
char temp[4];
char Imm[12];
strcpy(Imm, temp3);
strcat(Imm, f7);
int rd = DecConvert(temp1);
int rs1 = DecConvert(temp2);
int imm = DecConvertIL(Imm);
sprintf(Finals[k], "jalr x%d, x%d, %d\n", rd, rs1, imm);
k++;
}

void UFormat()
{
char temp[20];
char Imm[20];
char imm[5];
strcpy(temp, f3);
strcat(temp, temp2);
strcat(temp, temp3);
strcat(temp, f7);
for(int i=0; i<=19; i++)
{
Imm[i] = temp[i];
}
int rd = DecConvert(temp1);
strcpy(imm, BinHexConvert(Imm));
sprintf(Finals[k], "lui x%d, 0x%s\n", rd, imm);
k++;
}

char * BinConvert(char * str, char str1[][5])
{
char * temp;
temp = (char*)malloc(34*sizeof(char));
int c = 0;
for(int i=0; i<8; i++)
{
c = (int)(str[i]);
if(c<=57)
{
c = c - 48;
strncat(temp, str1[c], 4);
}
else
{
c = c - 87;
strncat(temp, str1[c], 4);
}
}
return Strrev(temp);
}

char * HexConvert(int i)
{
char s[5];
for(int j = 0; j<4; j++)
{
s[3-j] = i%2 + '0';
i = i/2;
}
s[4] = '\0';
char * str = s;
return str;
}

int main()
{
char str[8];
while(1)
{
scanf("%s", str);
if(strcmp(str, "-1")==0)
{
break   ;
}
char str1[16][5];
for(int i=0; i<16; i++)
{
strcpy(str1[i], HexConvert(i));
}

char str2[33];
strncpy(str2, BinConvert(str, str1), 33);
strncpy(temp1, str2+7, 5);
strncpy(temp2, str2+15, 5);
strncpy(temp3, str2+20, 5);
strncpy(f3, str2+12, 3);
strncpy(f7, str2+25, 7);
if(strncmp(str2, "1100110", 7) == 0)
{
RFormat();
}
else if(strncmp(str2, "1100100", 7) == 0)
{
IFormat();
}
else if(strncmp(str2, "1100000", 7) == 0)
{
ILFormat();
}
else if(strncmp(str2, "1100010", 7) == 0)
{
SFormat();
}
else if(strncmp(str2, "1100011", 7) == 0)
{
BFormat();
}
else if(strncmp(str2, "1111011", 7) == 0)
{
JFormat();
}
else if(strncmp(str2, "1110011", 7) == 0 && strcmp(f3, "000") == 0)
{
JIFormat();
}
else if(strncmp(str2, "1110110", 7) == 0)
{
UFormat();
}
else
{
printf("Invalid entry\n");
}
}
for(int i=0; i<=k; i++)
{
printf("%s\n", Finals[i]);
}
return    0;
}
*/
