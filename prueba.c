
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_memo(unsigned long long num, int count)
{
	char	*base;

	base = "0123456789abcdef";
	if (num > 15)
		count = ft_memo(num / 16, count);
	num = num % 16;
	write(1, &base[num], 1);
	count++;
	return (count);
}
int    ft_putstr(char *str, int count)
{
   int    i;

    i = 0;
    if (!str)
    {
        write(1, "(null)", 6);
        count = count + 6;
        return (count);
    }
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
        count++;
    }
    return (count);
}

int    ft_putnrb(int i, int count)
{
    long    nb;

    nb = i;
    if (nb < 0)
    {
        nb = -nb;
        write(1, "-", 1);
        count++;
    }
    if (nb > 9)
        count = ft_putnrb((nb / 10), count);
    nb = (nb % 10) + '0';
    write(1, &nb, 1);
    count++;
    return (count);
}

int    ft_puthexaup(unsigned long long num, int count)
{
    char    *base;

    base = "0123456789ABCDEF";
    if (num > 15)
        count = ft_puthexaup(num / 16, count);
    num = num % 16;
    write(1, &base[num], 1);
    count++;
    return (count);
}

int    ft_puthexatit(unsigned long long num, int count)
{
    char    *base;

    base = "0123456789abcdef";
    if (num > 15)
        count = ft_puthexatit(num / 16, count);
    num = num % 16;
    write(1, &base[num], 1);
    count++;
    return (count);
}

int    ft_putchar(char c, int count)
{
    write(1, &c, 1);
    count++;
    return (count);
}

int    ft_printf(char const *str, ...)
{
    va_list    arg;
    int        i;
    int        count;

    i = 0;
    count = 0;
	if (!*str)
		return (-1);
    va_start(arg, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
          if (str[i + 1] == 's')
              count = ft_putstr(va_arg(arg, char *), count);
          if (str[i + 1] == 'd' || str[i + 1] == 'i')
              count = ft_putnrb(va_arg(arg, int), count);
          if (str[i + 1] == 'x')
              count = ft_puthexatit(va_arg(arg, unsigned long long), count);
          if (str[i + 1] == 'X')
              count = ft_puthexaup(va_arg(arg, unsigned long long), count);
          if (str[i + 1] == '%')
              count = ft_putchar('%', count);
          i++;
        }
        else
        { 
            write(1, &str[i], 1);
            count++;
        }
        i++;
    }
    va_end(arg);
    return (count);
}

// int    main(void)
// {
// 	char    *s;
// 	int     v;
// 	int 	t;
// 	s = "\v&)m)";
	
// 	write(1, "a", 1);
// 	t=printf("T_P3z%dBa`NhQ1%da%d ^CG%sKyf#E7r%xx@k7wa%x", 1305536045, 1314177561, 237778768, s, 1435038156, -199251938);
// 	write(1, "\n", 1);
// 	printf("yo %d", t);
// 	write(1, "\n", 1);
// 	v=ft_printf("T_P3z%dBa`NhQ1%da%d ^CG%sKyf#E7r%xx@k7wa%x", 1305536045, 1314177561, 237778768, s, 1435038156, -199251938);
// 		write(1, "\n", 1);

// 	printf("tu %d", v);
// 	write(1, "\n", 1);
// 	return(0);
// }


// int    main(void)
// {
// 	char    *s;
// 	int     v;
// 	int 	t;
// 	s = "hallo";
	
	
// 	t=printf("I%%KxjAc\v2,%cY]\ts%xZgFlb3co*%sd &:]%pd'?%iyF)vj\nF%Xh$\nY2%ps\vJ;CA6Q%i$h@~}qMu", 1424368128, 2027367770, s, (void *)-7722705916397381604, -614294082, -888668674, (void *)-5257757429951958107, -1156152322);
// 	printf("yo %d", t);
// 	write(1, "\n", 1);

// 	v=ft_printf("I%%KxjAc\v2,%cY]\ts%xZgFlb3co*%sd &:]%pd'?%iyF)vj\nF%Xh$\nY2%ps\vJ;CA6Q%i$h@~}qMu", 1424368128, 2027367770, s, (void *)-7722705916397381604, -614294082, -888668674, (void *)-5257757429951958107, -1156152322);
// 	// write(1, "\n", 1);
// 	write(1, "\n", 1);
// 	printf("tu %d", v);
// 	write(1, "\n", 1);
// 	return(0);
// }

int    main(void)
{
	char    *s;
	int     v;
	int 	t;
	s = "hallo";
	
	
	t=ft_printf("i,W[\r%s\vfz~`%d7;8I%X&;dydk{\vx$%%dC8D:6%s/=?%%\fj\nD\r%X89\v<d4'U}k%incnw`>d%io", "M-;-tBxV,\"$6pEq).|\v(_KC~{{jo9BI&>Zm){:3=A^l|gaUulfof',X\f&+K\\>O<", -7154203, 1474349391, "e}zJuS^QJq];3\\D7he#%HdM}i8cc:", 2017985970, -1296736378, 849117734);
	printf("yo %d", t);
	write(1, "\n", 1);

	v=printf("i,W[\r%s\vfz~`%d7;8I%X&;dydk{\vx$%%dC8D:6%s/=?%%\fj\nD\r%X89\v<d4'U}k%incnw`>d%io", "M-;-tBxV,\"$6pEq).|\v(_KC~{{jo9BI&>Zm){:3=A^l|gaUulfof',X\f&+K\\>O<", -7154203, 1474349391, "e}zJuS^QJq];3\\D7he#%HdM}i8cc:", 2017985970, -1296736378, 849117734);
	// write(1, "\n", 1);
	write(1, "\n", 1);
	printf("tu %d", v);
	write(1, "\n", 1);
	return(0);
}