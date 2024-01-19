#include <memory>
#include <iostream>
#include <vector>

/**
 * A simple class which just reports when it is created (constructor) and when it is destroyed (destructor).
*/
class Reporter
{
    public: 
    Reporter(std::string id_string) : ID(id_string)
    {
        std::cout << "Creating Reporter Object with ID: " << ID << std::endl;
    }

    ~Reporter()
    {
        std::cout << "Destroying Reporter Object with ID: " << ID << std::endl;
    }

    private:
    std::string ID;
};


int main()
{
    Reporter* p_int = new Reporter("Raw Pointer Reporter");
    std::unique_ptr<Reporter> p_int1 = std::make_unique<Reporter>("Unique Pointer Reporter");
    
    return 0;
}
