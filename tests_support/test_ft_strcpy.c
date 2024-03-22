#include "stdio.h"

void	ft_strcpy(char *dst, const char *src)
{
	while (*src != '\0')
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
}

int main(void)
{
    char    src[] = "Hola mundo!";
    char    dst[200];

    int     int_src, int_dst;
    printf("This is the dst string before the strcpy function: %s\n", dst);
    ft_strcpy(dst, src);
    int_src = printf("%s", src);
    printf("Character in src string: %d\n", int_src);
    printf("This is the src string: %s\n", src);
    printf("This is the dst string after the ft_strcpy: %s\n", dst);
    int_dst = printf("%s", dst);
    printf("Character in dst string: %d\n", int_dst);
}