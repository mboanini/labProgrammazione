#include <iostream>
#include "Note.h"
#include "NotesCollection.h"
#include "ImportantNotes.h"


using namespace std;
int main() {

    //Inizializzazione
    Note * note1 = new Note("Viaggi", "Islanda, Egitto, Cuba");
    note1->setImportant(true);
    Note * note2 = new Note("Ricette", "Lasagne, Risotto, Pesce");
    note2->setBlocked(true);
    Note * note3 = new Note("Dentista", "Ore 18, 02/10");
    Note * note4 = new Note("Dottore", "Ore 11, 10/10");
    Note * note5 = new Note("Lista della spesa", "banane, susine");
    Note * note6 = new Note("Oculista", "Ore 17, 15/10");
    Note * note7 = new Note("Oculista", "Ore 15, 15/10");
    Note * note8 = new Note("Dentista", "Ore 20, 02/10");

    auto * notesCollection1 = new NotesCollection("Svago");
    auto * notesCollection2 = new NotesCollection("ToDo");
    auto * notesCollection3 = new NotesCollection("Visite");
    auto * important = new ImportantNotes("Importanti");

    //Prova metodi
    //addNote
    notesCollection1->addNote(note1);
    notesCollection2->addNote(note5);
    important->addNote(note1);
    cout<<"C'è "<< notesCollection1->notesNumber() <<" nota nella collezione: "<<notesCollection1->getName()<<"\n";
    cout<<"C'è "<< notesCollection2->notesNumber() <<" nota nella collezione: "<<notesCollection2->getName()<<"\n";
    cout<<"C'è "<< important->notesNumber() <<" nota nella collezione: "<<important->getName()<<"\n";

    //prova addNote per nota non importante
    important->addNote(note2);
    cout<<"C'è "<< important->notesNumber() <<" nota nella collezione: "<<important->getName()<<"\n";
    cout<<endl;

    note3->setImportant(true);
    important->addNote(note3);
    cout<<"Ci sono "<<important->notesNumber()<<" note nella collezione: "<<important->getName()<<"\n";
    cout<<endl;

    notesCollection3->addNote(note3);
    notesCollection3->addNote(note4);
    notesCollection3->addNote(note6);
    cout<<"Ci sono "<<notesCollection3->notesNumber()<<" note nella collezione: "<<notesCollection3->getName()<<"\n";

    //removeNote
    notesCollection3->removeNote("Dottore");
    cout<<"Ci sono "<<notesCollection3->notesNumber()<<" note nella collezione: "<<notesCollection3->getName()<<"\n";
    //removeNote per nota non presente
    notesCollection3->removeNote("Dottore");
    cout<<"Ci sono "<<notesCollection3->notesNumber()<<" note nella collezione: "<<notesCollection3->getName()<<"\n";


    //editNote
    cout<<"\nTesto non modificato: "<<note6->getText();
    notesCollection3->editNote("Oculista", note7);
    cout<<"\nTesto modificato: "<<note6->getText()<<"\n";
    //editNote e removeNote per nota non modificabile
    note6->setBlocked(true);
    notesCollection3->editNote("Oculista", note6);
    notesCollection3->removeNote("Oculista");

    //addNote per nota con titolo uguale a una nota già presente
    note8->setImportant(true);
    important->addNote(note8);
    cout<<endl;

    cout<<"Ci sono "<<notesCollection1->notesNumber()<<" note nella collezione: "<<notesCollection1->getName()<<"\n";
    cout<<"Ci sono "<<notesCollection2->notesNumber()<<" note nella collezione: "<<notesCollection2->getName()<<"\n";
    cout<<"Ci sono "<<notesCollection3->notesNumber()<<" note nella collezione: "<<notesCollection3->getName()<<"\n";
    cout<<"Ci sono "<<important->notesNumber()<<" note nella collezione: "<<important->getName()<<"\n";
}
