#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definicija strukture osoba
typedef struct {
    char ime[32];
    char prezime[32];
    int god_rod;
} osoba;


void dodaj_osobu_na_pocetak(osoba** lista, osoba* nova_osoba);
void ispisi_listu_osoba(osoba* lista);
void dodaj_osobu_na_kraj(osoba* lista, osoba* nova_osoba);
osoba* pronadi_po_prezimenu(osoba* lista, char* prezime);
void izbrisi_osobu(osoba** lista, osoba* osoba_za_izbrisat);

int main(void) {
    // Napravi praznu listu osoba
    osoba* lista = NULL;

    // Napravi novu osobu i dodaj je na pocetak liste
    osoba* nova_osoba = malloc(sizeof(osoba));
    strcpy(nova_osoba->ime, "Miljenko");
    strcpy(nova_osoba->prezime, "Miljić");
    nova_osoba->god_rod = 1990;
    dodaj_osobu_na_pocetak(&lista, nova_osoba);

    // Ispisi listu
    ispisi_listu_osoba(lista);

    // Napravi jos jednu novu osobu i dodaj je na kraj liste
    nova_osoba = malloc(sizeof(osoba));
    strcpy(nova_osoba->ime, "Ante");
    strcpy(nova_osoba->prezime, "Antić");
    nova_osoba->god_rod = 1995;
    dodaj_osobu_na_kraj(lista, nova_osoba);

    // Ispisi listu
    ispisi_listu_osoba(lista);

    // Pronadi osobu u listi po prezimenu
    osoba* pronadena_osoba = pronadi_po_prezimenu(lista, "Miljić");
    if (pronadena_osoba) {
        printf("Pronadena osoba: %s %s %d\n", pronadena_osoba->ime, pronadena_osoba->prezime, pronadena_osoba->god_rod);
    }
    else {
        printf("Osoba nije pronadena\n");
    }

    // Izbrisi osobu iz liste
    izbrisi_osobu(&lista, pronadena_osoba);

    // Ispisi listu
    ispisi_listu_osoba(lista);

    return 0;
}

// Dodaje novu osobu na pocetak liste
void dodaj_osobu_na_pocetak(osoba** lista, osoba* nova_osoba) {
    nova_osoba->next = *lista;
    *lista = nova_osoba;
}

// Ispisuje listu osoba
void ispisi_listu_osoba(osoba* lista) {
    osoba* trenutna = lista;
    while (trenutna) {
        printf("%s %s %d\n", trenutna->ime, trenutna->prezime, trenutna->god_rod);
        trenutna = trenutna->next;
    }
}

// Dodaje novu osobu na kraj liste
void dodaj_osobu_na_kraj(osoba* lista, osoba* nova_osoba) {
    osoba* trenutna = lista;
    while (trenutna->next)
}
