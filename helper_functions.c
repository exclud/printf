int _putchar(char c)
{
    return (write(1, &c, 1));
}

int _strlen(const char *s)
{
    int len = 0;

    while (*s)
    {
        len++;
        s++;
    }

    return (len);
}

void _printstr(char *str)
{
    int len = _strlen(str);
    int i;

    for (i = 0; i < len; i++)
        _putchar(str[i]);
}

void _printnum(int n)
{
    unsigned int num;

    if (n < 0)
    {
        _putchar('-');
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num / 10)
        _printnum(num / 10);

    _putchar(num % 10 + '0');
}

