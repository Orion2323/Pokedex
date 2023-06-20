#include "Pokedex.h"

using namespace std;

// function prototypes
void menu(Pokedex& p);

int main(int argc, char** argv) {
    Pokedex p(argv[1]);
    p.read_dataset();

    menu(p);
    return 0;
}

void menu(Pokedex& p) {
    std::cout << "Welcome to your pokedex!" << std::endl;

    int option = -1;
    while (option != 0) {
        std::cout << "Please choose an option:" << std::endl;
        std::cout << "1) Search Pokemon" << std::endl;
        std::cout << "2) Search Ability" << std::endl;
        std::cout << "0) Exit" << std::endl;
        std::cout << "Option: ";
        cin >> option;

        if (option == 1) {
            cin.ignore();
            std::string name;
            std::cout << "\nEnter Pokemon Name: ";

            getline(cin, name);
            p.search_pokemon(name);
        } else if (option == 2) {
            std::cout << "Search Ability\n" << std::endl;
        } else if (option == 0) {
            break;
        } else {
            std::cout << "Invalid option. Try again.\n" << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;
}
