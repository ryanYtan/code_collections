#include <random>
#include <cmath>
#include <iostream>
#include <thread>
#include <vector>

double arr[6] = {0};

double square(double x)
{
    return x * x;
}

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(square(y2 - y1) + square(x2 - x1));
}

void monte_carlo(int i)
{
    int npoints = 1000000000;
    int inside = 0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<>dis(-1.0, 1.0);

    for (int i = 0; i < npoints; i++) {
        double rx = dis(gen);
        double ry = dis(gen);

        if (distance(0.0, 0.0, rx, ry) <= 1.0) {
            inside++;
        }
    }
    arr[i] = (double)inside / (double)npoints * 4.0;
}

int main()
{
    int nthreads = 6;

    std::vector<std::thread> threads;

    for (int i = 0; i < nthreads; i++) {
        threads.push_back(std::thread(monte_carlo, i));
    }
    for (int i = 0; i < nthreads; i++) {
        threads[i].join();
    }

    double sum = 0;
    for (int i = 0; i < nthreads; i++) {
        sum += arr[i];
    }

    printf("%.15lf\n", sum / (double)nthreads);
}
