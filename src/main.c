#include <stdio.h>
#include "dfs.h"

int main(int argc, char const *argv[])
{
    int *maze = generate_maze(10);
    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            printf("%d", maze[i*20 + j]);
        }
        puts("");
    }
    
    return 0;
}
