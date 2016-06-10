#include <iostream>
#include <array>
#include <thread>
#include <chrono>
#include <random>

void pause_thread(int n)
{
  std::this_thread::sleep_for (std::chrono::seconds(n));
  std::cout << "pause of " << n << " seconds ended" << std::endl;
}

int main(int argc, char *argv[])
{
    std::cout << "Hello World!" << std::endl;

    auto threads = std::array<std::thread, 5>();
    auto generator = std::default_random_engine();
    auto distribution = std::uniform_int_distribution<int>(1, 20);

    for (auto& thread : threads)
    {
        thread = std::thread(pause_thread, distribution(generator));
    }

    for (auto& thread : threads)
    {
        thread.join();
    }

    return 0;
}
