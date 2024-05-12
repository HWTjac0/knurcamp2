/* NIE DOTYKAJ */
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void weryfikacja1(void *ss, int sz) {
    char *st = (char *)ss;
    int wiek = *st;
    if (wiek != 105) {
        printf("Błędne rozwiązanie\n");
        return;
    }
    st += sz / 3;
    uint64_t imiePtr = (*(uint64_t *)st);
    char *imie = (char *)imiePtr;
    st += sz / 3;

    if (strcmp(imie, "Jan") != 0) {
        printf("Błędne rozwiązanie\n");
        return;
    }
    float wzrost = *(float *)st;
    if (wzrost < 2.138 && wzrost > 2.136) {
        printf("Brawo poprawne rozwiązanie\n");
    } else {
        printf("Ups, błędne rozwiązanie\n");
    }
}
/* KONIEC SEKCJI NIE DOTYKAJ */

/*
 Treść zadania:

 Stwórz strukturę o nazwie `czlowiek`.
 Zrób żeby zawierała następujące pola:
 - `wiek` <- liczba całkowita (rozmiar standardowy)
 - `imie` <- no jego imie a co xD (ptr do stringa)
 - `wzrost` <- liczba zmiennoprzecinkowa w metrach amerykańskich np 1.234

 Stwórz człowieka o imieniu `Jan`, wieku 105 lat, wzroście 2 m 137 cm (w metrach
 amerykańskich - 1 metr = 1000 cm - 2m 137cm = 2.137) Pola wiek, imie, i wzrost
 muszą mieć taką samą koleność.

 Uruchom funckje `weryfikacja1` ze swojej funkcji main podając wskaźnik do
 człowieka oraz rozmiar struktury człowiek jako drugi parametr.

 ***** Zadanie na 6 albo gwiazdke jak zwał tak zwał *****
 Opisz co robi po kolei funckja `void weryfikacja1(void* ss, int sz)`

W pierwszej linijce wskazujemy na typ char na offsecie zerowym structa który podaliśmy tj. na bajt z wiekiem
potem robimy dereferencje tego adresu i castujemy na typ int więc zamiast 'i' mamy 105 tak jak w struct'cie.
Instrukcja if do weryfikacji zadanka dalej przesuwamy offset w pamięci o 8 bo rozmiar structa jest równy 24. Czemu 8
bo alignment (tak mi sie wydaje) i te słowo procesora na 64bitach ma 8 bajtów więc ten int i float zamiast 4 mają padding do 8.
Tego z wyciąganiem imienia nie jestem pewien, ale najpierw tak jak na początku bierzemy na jaki typ wskazujemy w pamięci uint64 bo
ten char pointer ma 8 bajtów i potem robimy jego dereferencje? i mamy liczbe jakby adres tego char pointer potem robimy z tego stringa.
Dalej znowu przesunięcie do kolejnego offsetu w pamięci czyli do floata znowu wyciąganie danych tak jak wcześniej od razu z dereferencją.
No i w if'ie czemu warunek "wzrost < 2.138 && wzrost > 2.136" bo ten float nie jest dokładnie równy 2.137 tylko chyba będzie 2.13700008 albo coś takiego,
Wynika to z reprezentacji floatów binarnie zgodnie z ieee 754 więc te 2.137 by było przedstawione jako 2137 * 10^-3 czyli więc no nie dostaniemy dokładnego wyniku.
No i koniec ;]
*/

int main(void) {
    // Miejce na twój kod
    typedef struct czlowiek {
        uint32_t wiek;
        char *imie;
        float wzrost;
    } czlowiek;

    czlowiek Jan = {.wiek = 105, .imie = "Jan", .wzrost = 2.137};
    weryfikacja1(&Jan, sizeof(czlowiek));
}