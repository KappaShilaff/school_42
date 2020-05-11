#include "libft.h"
#include <stdio.h>

char    *ft_chsum(char *str1, char *str2)
{
    int     i[5];
    char    *res;

    ft_bzero(i, sizeof(int[5]));
    while (str1[i[1]] && str1[i[1]] != '.')
        i[1]++;
    while (str2[i[2]] && str2[i[2]] != '.')
        i[2]++;
    if (i[1] > i[2])
        i[0] = i[1];
    else
        i[0] = i[2];
    while (str1[i[1] + i[3]])
        i[3]++;
    while (str2[i[2] + i[4]])
        i[4]++;
    if (i[3] > i[4])
        i[0] += i[3];
    else
        i[0] += i[4];
    res = malloc(i[0] + 1);
    ft_bzero(res, i[0]);
    i[3]--;
    i[4]--;
    res[0] = '0';
    if (i[3] > i[4])
        while (i[3] > i[4])
            res[i[0]--] = str1[i[1] + i[3]--];
    else
        while (i[4] > i[3])
            res[i[0]--] = str2[i[2] + i[4]--];
    while (i[0] > 0) {
        if (i[3] == 0)
        {
            if (res[i[0]] != 0)
                res[i[0] - 1] = res[i[0]];
            res[i[0]--] = '.';
            i[3]--;
            i[4]--;
        } else {
            res[i[0]] += '0';
            if (i[1] + i[3] > -1) {
                res[i[0]] += str1[i[1] + i[3]--] - '0';
            }
            if (i[2] + i[4] > -1) {
                res[i[0]] += str2[i[2] + i[4]--] - '0';
            }
            if (res[i[0]] - '0' > 9) {
                res[i[0] - 1] += (res[i[0]] - '0') / 10;
                res[i[0]] = (res[i[0]] - '0') % 10 + '0';
            }
            i[0]--;
        }
    }
    return (res);
}