#include "kantenListe.h"

int main() {
    KantenListe klFile("data.in");
    KantenListe klEmpty;
    KantenListe klCopy(klFile);

    klFile.print();

    KantenListe klKomplement = klFile.komplement();
    klKomplement.print();

    return 0;
}
