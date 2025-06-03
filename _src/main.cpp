#include "__preprocessor__.h"

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    srand(time(NULL));

    struct Positions
    {
        float x;
        float y;
    };

    struct Objects
    {
        Positions pos;
        float radius;

        char padding[16];
    };

    // size_t size = 800'000'000;
    size_t size = 1'000'000'000;

    Objects* objects = new Objects[size];
    time_stamp("allocation done");
    memset(objects, 0, sizeof(Objects) * size);
    time_stamp("memset completed");

    float rn[3] = {rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, rand() / (float)RAND_MAX};
    for (size_t i = 0; i < size; i++)
    {
        objects[i].pos.x += rn[0];
        objects[i].pos.y += rn[1];
        objects[i].radius += rn[2];
    }

    time_stamp("addition done");

    04 : 15 : 01(+214micro 708nano)

        TIME_STAMP : memset completed 04 : 15 : 18(+16s 300mili 590micro 241nano)

                         TIME_STAMP : addition done 04 : 15 : 54(+36s 579mili 188micro 36nano)

                                          var(objects[0].pos.x);

    return 0;
}
#endif