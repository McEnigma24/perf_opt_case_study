#include "__preprocessor__.h"

void func1()
{
    int tab[100];
    for (int i = 0; i < 100; i++)
    {
        tab[i] = rand() % 100;
    }
    var(tab[0]);
}

void func2()
{
    int tab[100];
    for (int i = 0; i < 100; i++)
    {
        tab[i] = rand() % 100;
    }
    var(tab[1]);
}

void func3()
{
    int tab[100];
    for (int i = 0; i < 100; i++)
    {
        tab[i] = rand() % 100;
    }
    var(tab[2]);
}

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    srand(time(NULL));
    // CORE::clear_terminal(); // tests will NOT be VISIBLE with this line

    CORE::str::split_string("Hello World!", ' ');
    cout << CORE::str::to_lower_case("Hello, World!") << endl;

    for (int i = 0; i < 100; i++)
    {
        func1();
        func2();
        func3();
    }

    return 0;
}
#endif