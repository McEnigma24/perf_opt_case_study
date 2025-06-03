#include "__preprocessor__.h"

void array_of_structures()
{
    struct Point
    {
        float x;
        float y;

        char padding[64];
    };

    size_t size = 100'000'000;

    Point* objects = new Point[size];
    time_stamp("allocation done");
    memset(objects, 0, sizeof(Point) * size);
    time_stamp("memset completed");

    float rn[3] = {rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, rand() / (float)RAND_MAX};
    for (size_t i = 0; i < size; i++)
    {
        objects[i].x += rn[0];
        objects[i].y += rn[1];
    }

    time_stamp("addition done");

    varr(objects[0].x);
    var(objects[0].y);
}

void structure_of_arrays()
{
    struct Point
    {
        float* x;
        float* y;

        char padding[64];
    };

    size_t size = 100'000'000;

    Point points;
    points.x = new float[size];
    points.y = new float[size];
    time_stamp("allocation done");

    memset(points.x, 0, sizeof(float) * size);
    memset(points.y, 0, sizeof(float) * size);
    time_stamp("memset completed");

    float rn[3] = {rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, rand() / (float)RAND_MAX};
    for (size_t i = 0; i < size; i++)
    {
        points.x[i] += rn[0];
        points.y[i] += rn[1];
    }

    time_stamp("addition done");

    var(points.x[0]);
}

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    srand(time(NULL));

    array_of_structures();

    structure_of_arrays();

    return 0;
}
#endif