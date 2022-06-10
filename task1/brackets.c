#include <string.h>
#include "brackets.h"


bool check_pair(char left, char right) {
    if (
        (left == '(' && right == ')') ||
        (left == '[' && right == ']') ||
        (left == '{' && right == '}')
    ) {
        return true;
    }
    return false;
}


/*
 * Function: is_cbs
 *
 * Uses stack to remember previous opening brackets and
 * match with current closing brackets.
 *
 * Returns true if brackets expression is balanced,
 * false otherwise
 *
 */

bool is_cbs(const char *expr) {

    unsigned size = strlen(expr);

    char stack[size];
    int top = -1;

    for (int i = 0; i < size; i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            top++;
            stack[top] = expr[i];
        } else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            if (top == -1) {
                return false;
            }
            if (!check_pair(stack[top], expr[i])) {
                return false;
            }
            top--;
        }
    }

    if (top > -1) {
        return false;
    }

    return true;
}
