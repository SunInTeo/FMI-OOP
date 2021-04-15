#include "..\Header files\Helpers.h"

int m_strlen(const char *text)
{
    int len = 0;
    if (text) 
    {
        while (text[len])
        {
            ++len;
        }
    }
    return len;
}

void m_strcpy(char *dest, const char *src)
{
    int pos = 0;
    while (src[pos])
    {
        dest[pos] = src[pos];
        ++pos;
    }
    dest[pos] = '\0';
}

int m_strcmp(const char *text1, const char *text2)
{
    while (*text1 && *text1 == *text2)
    {
        ++text1;
        ++text2;
    }

    // return the ASCII difference after converting char* to unsigned char*
    return *(const unsigned char *)text1 - *(const unsigned char *)text2;
}

char *m_strcat(char *destination, char *source)
{
    int c = 0;
    int sc;

    while (destination[c] != 0)
    {
        ++c;
    }

    for (sc = 0; sc < m_strlen(source); ++sc)
    {
        destination[sc + c] = source[sc];
    }

    destination[sc + c] = 0;

    return destination;
}
