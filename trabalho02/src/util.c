#include <stdio.h>

void
parse_social_network_file(FILE *fd)
{
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];

    while (fgets(buffer, MAX_LENGTH, fd))
        printf("%s", buffer);
}
