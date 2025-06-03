#include "__preprocessor__.h"

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    srand(time(NULL));

    struct Positions
    {
        float x;
        float y;
    }

    struct Objects
    {
        Positions pos;
        float radius;
    };

    for (int i = 0; i < 1'000; i++) {}

    return 0;
}
#endif