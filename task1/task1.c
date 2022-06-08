#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char *read_input() {
    const int chunk = 200;
    char *input = NULL;
    char temp_buf[chunk];
    size_t input_len = 0, temp_len = 0;
    do {
        fgets(temp_buf, chunk, stdin);
        temp_len = strlen(temp_buf);
        input = realloc(input, input_len + temp_len + 1);
        strcpy(input + input_len, temp_buf);
        input_len += temp_len;
    } while (temp_len == chunk - 1 && temp_buf[chunk - 2] != '\n');
    return input;
}

bool check_pair(char element1, char element2) {
    if (element1 == '(' && element2 == ')') {
        return true;
    } else if (element1 == '[' && element2 == ']') {
        return true;
    } else if (element1 == '{' && element2 == '}') {
        return true;
    }
    return false;
}

int main() {
    char *brackets = read_input();
    unsigned size = strlen(brackets) - 1;
    brackets[size] = '\0';

    char stack[strlen(brackets)];
    int top = -1;
    bool correctness = true;

    for (int i = 0; i < size; i++) {
        if (brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{') {
            top++;
            stack[top] = brackets[i];
        } else {
            if (strlen(stack) == 0) {
                correctness = false;
                break;
            }
            if (!check_pair(stack[top], brackets[i])) {
                correctness = false;
                break;
            }
            top--;
        }
    }

    if (top > -1) {
        correctness = false;
    }
    if (correctness) {
        printf("OKAY");
    } else {
        printf("NOT OKAY");
    }
    free(brackets);

    return 0;
}
