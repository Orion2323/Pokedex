#include "Pokedex.h"

int main(int argc, char** argv) {
    Pokedex p(argv[1]);

    p.read_dataset();
    return 0;
}
