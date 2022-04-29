#include <stdio.h>
#include <string.h>
#include <ctype.h>
int name(char* str, int l)
{
    int i, a = 0;
    char c[l];
    switch (l) {
    case 6:
        strcpy(c, "circle");
        break;
    case 8:
        strcpy(c, "triangle");
        break;
    }
    for (i = 0; i < l; i++) {
        if (str[i] != c[i] && str[i] != toupper(c[i])) {
            a++;
        }
    }
    if (a != 0) {
        printf("Error in input data  >>%s\n", str);
        return 0;
    } else {
        return 1;
    }
}

int hooks1(char* str, int l)
{
    if (l >= 8) {
        if (str[l] != '(' && str[l + 1] != '(') {
            printf("Error in input data >> %s \n", str);
            return 0;
        } else {
            return 1;
        }
    } else {
        if (str[l] != '(') {
            printf("Error in input data >> %s \n", str);
            return 0;
        } else {
            return 1;
        }
    }
}

int hooks2(char* str, int l)
{
    if (str[l] != ')' && str[l + 1] != ')') {
        printf("Error in input data >> %s \n", str);
        return 0;
    } else {
        return l;
    }
}

int probel(char* str, int l)
{
    int i = l;
    while (str[i] == ' ') {
        i++;
    }
    if (isdigit(str[i]) || str[i] == '-' || str[i] == '(') {
        return i;
    } else {
        printf("Error in input data >> %s \n", str);
        return i;
    }
}

int number(char* str, int l)
{
    int i, p, n = 0, s = 1;
    for (i = l + 1; i < 100; i++) {
        if (str[i] == ' ' || str[i] == ',' || str[i] == ')') {
            s++;
            break;
        }
        if (isdigit(str[i]) || str[i] == '.' || str[i] == '-') {
        } else {
            n = 1;
        }
        s++;
    }
    p = l + s;
    if (n != 0) {
        printf("Error in input data >> %s \n", str);
        return 0;
    } else {
        return p;
    }
}
void unx(char* str, int l)
{
    int i;
    i = l;
    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != ')') {
            printf("Error in input data >> %s \n", str);
        }
        i++;
        break;
    }
}

int main()
{
    int d, l, p;
    char str[] = "triangle((3 -2.0, 3.0 2, 1.0 0, 3.0 -2))";
    switch (str[0]) {
    case 'c':
        l = 6;
        name(str, l);
        d = probel(str, l);
        hooks1(str, l);
        p = number(str, d);
        d = probel(str, p);
        p = number(str, d) + 1;
        d = number(str, p);
        unx(str, d);
        break;
    case 't':
        l = 8;
        name(str, l);
        hooks1(str, l);
        d = probel(str, l);
        p = number(str, d + 1);
        d = probel(str, p);
        p = number(str, d) + 1;
        d = probel(str, p);
        p = number(str, d);
        d = probel(str, p);
        p = number(str, d) + 1;
        d = probel(str, p);
        p = number(str, d);
        d = probel(str, p);
        p = number(str, d) + 1;
        d = probel(str, p);
        p = number(str, d);
        d = probel(str, p);
        p = number(str, d);
        d = hooks2(str, p);
        unx(str, d);
        break;
    default:
        printf("Error in input data >> %s \n", str);
    }
    return 0;
}
