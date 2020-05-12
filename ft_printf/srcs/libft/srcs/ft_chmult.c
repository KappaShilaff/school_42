#include "libft.h"
#include <stdio.h>

char    *ft_chmult(char *str1, char *str2)
{
    int     i[8];
    char    *res;
    char    buf;
    char    *del;

    ft_bzero(i, sizeof(int[8]));
    while (str1[i[1]] && str1[i[1]] != '.')
        i[1]++;
    while (str2[i[2]] && str2[i[2]] != '.')
        i[2]++;
    while (str1[i[1] + i[3]])
        i[3]++;
    while (str2[i[2] + i[4]])
        i[4]++;
    i[0] = i[1] + i[2] + i[3] + i[4] - 1;
    res = malloc(i[0] + 2);
    ft_bzero(res, i[0] + 3);
    i[5] = i[3] + i[4] - 1;
    res[i[0] - i[5]] = 100;
    i[1] += i[3] - 1;
    i[2] += i[4] - 1;
    i[0]--;
    i[6] = i[0];
    i[7] = i[1];
    i[8] = i[0];
    while(i[2] >= 0)
    {
        i[0] = i[6];
        if (res[i[0]] == 100) {
            i[0]--;
            i[6]--;
        }
        if (str2[i[2]] == '.')
            i[2]--;
        i[1] = i[7];
        while (i[1] >= 0)
        {
            if (str1[i[1]] == '.')
                i[1]--;
            buf = (str1[i[1]] - '0') * (str2[i[2]] - '0') + res[i[0]];
            res[i[0]] = buf % 10;
            if (res[--i[0]] == 100)
                i[0]--;
            res[i[0]] += buf / 10;
            i[1]--;
        }
        i[6]--;
        i[2]--;
    }
    i[0] = 0;
    while (res[i[0]] == '\0')
        res[i[0]++] = '0';
    while(i[0] <= i[8]) {
        if (res[i[0]] == 100)
            res[i[0]++] = '.';
        res[i[0]++] += '0';
    }
    if (res[0] == '0' && res[1] != '.') {
        del = res;
        res = ft_strdup(res + 1);
        free(del);
        i[8]--;
    }
    while(res[i[8]] == '0' && res[i[8] - 1] != '.')
        res[i[8]--] = '\0';
    return (res);
}