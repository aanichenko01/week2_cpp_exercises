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
    Reporter *raw_ptr = new Reporter("Raw");
    std::unique_ptr<Reporter> smart_ptr = std::make_unique<Reporter>("Unique");
    
    return 0;
}
