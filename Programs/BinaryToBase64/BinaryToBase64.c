#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void setArguments();
int CompareString(const char *string, char* flag);
int SetFlags(const int argc, char *argv[], char file_name[], int *e_flag, int *d_flag, int *o_flag, int *output_flag, int *f_flag, int *h_flag);
int CatchFlagError();
int encode(char *file_name);
int hFlag();
int FileExistsError(char *file_name);
void DecimalToBinary(char three_byte[4]);

int main(const int argc, char *argv[]) {
    char file_name[1024];
    int e_flag = 0;
    int d_flag = 0;
    int o_flag = 0;
    int output_flag = 0;
    int f_flag = 0;
    int h_flag = 0;
    if (argc == 1) setArguments();
    SetFlags(argc, argv, file_name, &e_flag, &d_flag, &o_flag, &output_flag, &f_flag, &h_flag);
    if (h_flag) hFlag();
    if (e_flag && d_flag) CatchFlagError();
    if (!FileExistsError(file_name)) return 1;
    if (e_flag) encode(file_name);
    return 0;
}

void setArguments() {
    printf("enter arguments for program functionality");
    exit(0);
}

int CompareString(const char *string, char* flag) {
    char c[3] = "";
    for (int i = 0; i < 2; i++) {
        c[i] = string[i];
    }
    return strcmp(c, flag);
}

int SetFlags(const int argc, char *argv[], char file_name[], int *e_flag, int *d_flag, int *o_flag, int *output_flag, int *f_flag, int *h_flag) {
    for (int i = 1; i < argc; i++) {
        if (strstr(argv[i], "--expand") || CompareString(argv[i], "-e") == 0) *e_flag = 1;
        else if (strstr(argv[i], "--decode") || CompareString(argv[i], "-d") == 0) *d_flag = 1;
        else if (strstr(argv[i], "--output")) *output_flag = 1;
        else if (CompareString(argv[i], "-o") == 0) *o_flag = 1;
        else if (strstr(argv[i], "--force") || CompareString(argv[i], "-f") == 0) *f_flag = 1;
        else if (strstr(argv[i], "--help") || CompareString(argv[i], "-h") == 0) *h_flag = 1;
        else strcpy(file_name, argv[i]);
    }

    return 0;
}

int CatchFlagError() {
    printf("you can not set both the e and d flag\n");
    exit(0);
}

int hFlag() {
    printf(" e flag encodes \n d flag decodes \n o flag saves output to a file \n f forces output to a file and will write over previous input \n h flag brings up help menu");
    exit(0);
}

int FileExistsError(char *file_name) {
    int exists = 1;
    FILE *file = fopen(file_name, "r");
    if (file == NULL) printf("file %s does not exist", file_name), exists = 0;
    fclose(file);
    return exists;
}

void DecimalToBinary(char three_byte[4]) {
    unsigned char convered_bits[5];
    printf("%d ", three_byte[0]);
    convered_bits[0] = three_byte[0] >> 2;
    convered_bits[1] = ((three_byte[0] << 4) & 0x3F) + (three_byte[1] >> 4);
    convered_bits[2] = ((three_byte[1] << 2) & 0x3F) + (three_byte[2] >> 6);
    convered_bits[3] = three_byte[2] & 0x3F;
   // printf("%d ", convered_bits[1]);

    for (int i = 0; i < strlen(three_byte); i++) {
        three_byte[i] = '\0';
    }
}

int encode(char *file_name) {
    FILE *input = fopen(file_name, "r");
    char character;
    int count = 0;
    unsigned char three_bytes[4] = "";
    while ((character = getc(input)) != EOF) {
        count++;
        strncat(three_bytes, &character, 1);
        if (count % 3 == 0) {
            DecimalToBinary(&three_bytes);
        }
    }

    return 0;
}

