#include <iostream>
#include <random>
#include <functional>

bool InsideUnitSphere(double x, double y, double z)
{
    return ((x*x + y*y + z*z) <= 1);
}

double IntegrateMonteCarlo3D(int n_points, double min, double max, std::function<bool(double, double, double)> TestPoint)
{
    int count = 0;
    // N.B. std::pow with integer arguments can be less efficient than
    // writing the multiplication explicitly, so be careful about using it
    // inside loops for example!
    double VolCube = std::pow((max - min), 3);

    //set up random number generator here
    std::uniform_real_distribution<double> uniform_real(min, max);
    std::mt19937 rng_mt;
    // bind takes a function as first parameter and then arguments as the next few
    auto generate_uniform_real = std::bind(uniform_real, rng_mt);

    for(int i = 0; i < n_points; i++)
    {
        //generate random points here
        double x = generate_uniform_real();
        double y = generate_uniform_real();
        double z = generate_uniform_real();
        if(TestPoint(x, y, z)) count++;
    }

    return static_cast<double>(count) / n_points * VolCube;
}


int main()
{
    int N_points = 10000;
    
    std::cout << "Enter number of points to sample (default 1000): ";
    std::cin >> N_points;
    if(N_points == 0) N_points == 1000;
    
    // pass in our function as a function pointer
    double UnitSphereVol = IntegrateMonteCarlo3D(N_points, -1.0, 1.0, &InsideUnitSphere);

    std::cout << "Volume estimate of sphere using " << N_points << " points = " << UnitSphereVol << std::endl;
}