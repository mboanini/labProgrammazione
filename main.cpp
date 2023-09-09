#include <iostream>
#include "Note.h"
#include "Collection.h"
#include "NotesCollection.h"
#include "ImportantNotes.h"


using namespace std;
int main() {
    Note * note1 = new Note("Viaggi", "Islanda, Egitto, Cuba");
    note1->setImportant(true);
    Note * note2 = new Note("Ricette", "Lasagne, Risotto, Pesce");
    note2->setBlocked(true);
    Note * note3 = new Note("Dentista", "Ore 18, 02/10");
    Note * note4 = new Note("Dottore", "Ore 11, 10/10");
    Note * note5 = new Note("Lista della spesa", "banane, susine");
    NotesCollection * notesCollection1 = new NotesCollection("Svago");
    NotesCollection * notesCollection2 = new NotesCollection("ToDo");
    ImportantNotes * important = new ImportantNotes("Importanti");
    notesCollection1->addNote(note1);
    important->addNote(note1);
    int n = notesCollection1->notesNumber();
    int nImp = important->notesNumber();
    cout<<"Numero note: "<< n <<" nella collezione: "<<notesCollection1->getName()<<"\n\n";

    cout<<"Numero note: "<<nImp<<" nella collezione: "<<important->getName()<<"\n";
    important->addNote(note2);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
