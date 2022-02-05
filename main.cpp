/*
 * 1. Структурное, функциональное, ООП, обобщенное (a.k.a. imperative, procedural, object-oriented, generic)
 * 2. Для групповой разработки, а также для безопасной модификации кода без создания копий
 * 3. git pull, git commit, git push
 * 4. Гомогенные:
 *      а. На основе массива: array, vector, deque, string
 *      б. На основе узлов: list, forward_list
 *      в. На основе деревьев: set, multiset, map, multimap
 *      г. На основе хэш-функций: unordered_set, unordered multiset, unordered_map, unordered multimap
 *    Гетерогенные:
 *      turple, pair
 *    Aдаптеры:
 *      stack, queue, priority_queue
 */

#include <iostream>
#include <chrono>
#include <cmath>

using namespace std::chrono;


template<typename Unit>
class Timer
{
private:
    steady_clock::time_point start = steady_clock::now();
    int duration = 0;

public:
    Timer(){};
    ~Timer()
    {
        Pause();
        std::cout<< "Duration is: "<<duration<<"\n";
    };

    void Pause()
    {
        duration += duration_cast<Unit>(steady_clock::now()-start).count();
    }

    void Resume()
    {
        start = steady_clock::now();
    }

};

int main()
{
    double res = 0.f;
    {
        Timer<std::chrono::milliseconds> myTimer;
        for (int i = 0; i<10000000; i++) res+=std::sin(i)+std::cos(i);
        myTimer.Pause();
        for (int i = 0; i<10000000; i++) res+=std::sin(i)+std::cos(i);
        myTimer.Resume();
        for (int i = 0; i<10000000; i++) res+=std::sin(i)+std::cos(i);
    }
    std::cout<<res;

    return 0;
}
