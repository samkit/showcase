#include <vector>
#include <algorithm>

int main()
{
    std::vector<int*> is;
    for (int i = 0; i < 10; ++i)
    {
        is.push_back(new int(i));
    }
    std::for_each(is.begin(), is.end(), (void (*)(void*))operator delete);
}
