#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Osoba {
	int godine;
	struct Osoba* sljedeci;
};

struct Osoba* novaOsoba(const int godine) {
	struct Osoba* novaOsoba = NULL;
	novaOsoba = malloc(sizeof(struct Osoba));
	novaOsoba->sljedeci = NULL;
	novaOsoba->godine = godine;
	printf("napravljena nova osoba pod %s\n", novaOsoba);
	return novaOsoba;
}

void ispisiOsobu(const struct Osoba* osoba, const char* komentar) {
	if (osoba == NULL)
	{
		printf("%s je NULL\n", komentar);
	}
	else {
		printf("%s: godine:%d adresa:%s\n", komentar, osoba->godine,
			osoba, osoba->sljedeci);
	}


}

int main()
{
	printf("\n\n ** POCETAK LISTE **\n\n");

	struct Osoba *prvi = NULL;
	struct Osoba* drugi = NULL;

	ispisiOsobu(prvi, "prvi");
	ispisiOsobu(drugi, "drugi");

	prvi = novaOsoba(49);
	drugi = novaOsoba(50);

	ispisiOsobu(prvi, "prvi");
	ispisiOsobu(drugi, "drugi");

	prvi->sljedeci = drugi;
	ispisiOsobu(prvi, "prvi");
	ispisiOsobu(prvi->sljedeci, "prvi->sljedeci");
	ispisiOsobu(drugi, "drugi");

	free(prvi);
	free(drugi); 

	prvi = NULL;
	drugi = NULL;

	return 0;
}
