#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 128
#define MAX_LINE 1024

typedef struct studenti {
	char ime[MAX_SIZE];
	char prezime[MAX_SIZE];
	double bodovi;

}student;

int broji_retke(char* imedatoteke);
student* AlocirajMemorijuProcitajStudente(int brojStudenata, char* imedatoteke);
int ispis(char* imedatoteke);

int main()
{
	char* datoteka;
	datoteka = "Popis.txt";
	int brojStudenata = 0;
	student* stud;

	brojStudenata = broji_retke(datoteka);
	printf("%d\n", brojStudenata);

	stud= AlocirajMemorijuProcitajStudente(brojStudenata, datoteka);

	ispis(datoteka);

	return 0;



}

int broji_retke(char* imedatoteke) {

	int brojac = 0;
	FILE* datoteka = NULL;
	char buffer[MAX_LINE] = { 0 };
	datoteka = fopen(imedatoteke, "r");
	if (!datoteka)
	{
		printf("Greska\n");
		return -1;
	}

	while (!feof(datoteka)) {
		fgets(buffer, MAX_LINE, datoteka);
		brojac++;
	}

	fclose(datoteka);

	return brojac;
}

student* AlocirajMemorijuProcitajStudente(int brojStudenata, char* imedatoteke) {

	int brojac = 0;
	FILE* datoteka = NULL;
	student* popis = NULL;

	popis = (student*)malloc(brojStudenata * sizeof(student));
	datoteka = fopen(imedatoteke, "r");

	if (!datoteka) {
		printf("Greska!\n");
		free(popis);
		return NULL;
							//ili fclose(imedatoteke);
	}

	while (!feof(datoteka)) 
	{
		fscanf(datoteka, " %s	%s	%lf", popis[brojac].ime, popis[brojac].prezime, popis[brojac].bodovi);
	}

	fclose(datoteka);

	return popis;
}


int ispis(char* imedatoteke)
{
	int i = 0;
	int brojStudenata = 0;

	student* stud = NULL;

	brojStudenata = broji_retke(imedatoteke);
	stud = AlocirajMemorijuProcitajStudente(brojStudenata, imedatoteke);

	double max = stud[0].bodovi;
	for (i = 0;i < brojStudenata;i++) {
		if (stud[i].bodovi > max)
			max = stud[i].bodovi;
	}

	for (i = 0;i < brojStudenata;i++)
		printf("Ime: %s\tPrezime: %s\tApsolutni bodovi: %lf\n", stud[i].ime, stud[i].prezime, stud[i].bodovi, (stud[i].bodovi / max) * 100);
	return 0;
}
