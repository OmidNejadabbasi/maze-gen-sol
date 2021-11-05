#include <stack>
#include <vector>
#include <random>

std::vector<int> getNeigburs(int *maze, int width, int i)
{
    std::vector<int> neighburs;
    int x = i % width;
    int y = i / width;
    if ((y - 2) > 0 && maze[(y - 2) * width + x] == 1)
    {
        neighburs.push_back((y - 2) * width + x);
    }
    if ((y + 2) < width && maze[(y + 2) * width + x] == 1)
    {
        neighburs.push_back((y + 2) * width + x);
    }
    if ((x - 2) > 0 && maze[y * width + x - 2] == 1)
    {
        neighburs.push_back(y * width + x - 2);
    }
    if ((x + 2) < width && maze[y * width + x + 2] == 1)
    {
        neighburs.push_back(y * width + x + 2);
    }
    return neighburs;
}

int rand_range(int a, int b)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(a, b); // distribution in range [1, 6]

    return dist6(rng);
}

extern "C" int *generate_maze(int width)
{
    // 0 = wall
    // 1 = empty area
    // 2 = visited area
    width = width * 2;

    int *maze = new int[width * width];
    for (int i = 0; i < width * width; i++)
        if ((i * width) % 2 == 1 && i % 2 == 1)
        {
            maze[i * width + i] = 1;
        }
        else
        {
            maze[i * width + i] = 0;
        }

    std::stack<int> stck;
    maze[1 * width + 1] = 2;
    stck.push(width + 1);
    while (!stck.empty())
    {
        std::vector<int> neighburs = getNeigburs(maze, width, stck.top());
        if (neighburs.size() == 0)
        {
            stck.pop();
            continue;
        }
        stck.pop();
        int nextI = neighburs[rand_range(0, neighburs.size())];
        maze[nextI] = 2;
        stck.push(nextI);
    }

    return maze;
}
