#include <iostream>

int main(){
    std::cout << "\n=== Beginning Docker - Makefile - Tests ===\n\n";
    
    std::cout << "Please enter your name: ";
    std::string* name = new std::string();
    std::getline(std::cin, *name);

    std::cout << "\nPlease enter your degree: ";
    std::string* degree = new std::string();
    std::getline(std::cin, *degree);

    std::cout << "\n\nHi " << *name << " nice to meet you\n";
    std::string* choice = new std::string();

    while(true)
    {
        std::cout << "\nPlease select a number:\n";
        std::cout << "1 - Get my status\n";
        std::cout << "2 - Update name\n";
        std::cout << "3 - Update degree\n";
        std::cout << "4 or q - Exit program\n";
        std::cin >> *choice;

        if(*choice == "1")
        {
            std::cout << "\n== Status ==\n";
            std::cout << "Name: " << *name;
            std::cout << "\nDegree: " << *degree;
            std::cout << "\nYear: 2nd year\n";
        }
        else if(*choice == "2")
        {
            std::getline(std::cin, *name); //dummy cin
            std::cout << "\nPlease enter a new name: ";
            std::getline(std::cin, *name);

            std::cout << "\nName updated successfully to: " << *name << std::endl;
        }
        else if(*choice == "3")
        {
            std::getline(std::cin, *degree); //dummy cin
            std::cout << "\nPlease enter a new degree: ";
            std::getline(std::cin, *degree);

            std::cout << "\nDegree updated successfully to: " << *degree << std::endl;
        }
        else if(*choice == "4" || *choice == "q")
        {
            std::cout << "\n=== Completed Docker - Makefile - Tests successfully===";
            std::cout << "\nExiting the program. Goodbye!\n";
            break;
        }
        else
        {
            std::cout << "\nInvalid input. Please try again.\n";
        }
    }

    delete name;
    delete degree;
    delete choice;

    return 0;
}

//To run in docker run the command:
//docker compose run --rm campusguard
