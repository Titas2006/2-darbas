#include <iostream>
using namespace std;

const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;

// Funkcijos
void ivesti(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazKiekis[], int &mokKiekis);
void rodytiVisus(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazKiekis[], int mokKiekis);
void rodytiViena(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazKiekis[], int mokKiekis);
void keistiPazymi(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazKiekis[], int mokKiekis);
void salinti(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazKiekis[], int &mokKiekis);

int main() {
    string vardai[MAX_MOKINIU];
    int pazymiai[MAX_MOKINIU][MAX_PAZYMIU];
    int pazKiekis[MAX_MOKINIU];
    int mokKiekis = 0;

    int pasirinkimas;

    do {
        cout << "\n--- MENIU ---\n";
        cout << "1 - Ivesti mokinius\n";
        cout << "2 - Rodyti visus\n";
        cout << "3 - Rodyti viena\n";
        cout << "4 - Keisti pazymi\n";
        cout << "5 - Pasalinti mokini\n";
        cout << "0 - Iseiti\n";
        cout << "Pasirink: ";
        cin >> pasirinkimas;

        switch(pasirinkimas) {
            case 1: ivesti(vardai, pazymiai, pazKiekis, mokKiekis); break;
            case 2: rodytiVisus(vardai, pazymiai, pazKiekis, mokKiekis); break;
            case 3: rodytiViena(vardai, pazymiai, pazKiekis, mokKiekis); break;
            case 4: keistiPazymi(vardai, pazymiai, pazKiekis, mokKiekis); break;
            case 5: salinti(vardai, pazymiai, pazKiekis, mokKiekis); break;
        }

    } while(pasirinkimas != 0);

    return 0;
}

// ================= FUNKCIJOS =================

void ivesti(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazKiekis[], int &mokKiekis) {
    cout << "Kiek mokiniu? ";
    cin >> mokKiekis;

    if(mokKiekis > MAX_MOKINIU) mokKiekis = MAX_MOKINIU;

    for(int i = 0; i < mokKiekis; i++) {
        cout << "Vardas: ";
        cin >> vardai[i];

        cout << "Kiek pazymiu (max 10): ";
        cin >> pazKiekis[i];

        if(pazKiekis[i] > MAX_PAZYMIU) pazKiekis[i] = MAX_PAZYMIU;

        for(int j = 0; j < pazKiekis[i]; j++) {
            cout << "Pazymys: ";
            cin >> pazymiai[i][j];
        }
    }
}

void rodytiVisus(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazKiekis[], int mokKiekis) {
    if(mokKiekis == 0) {
        cout << "Nera duomenu!\n";
        return;
    }

    for(int i = 0; i < mokKiekis; i++) {
        cout << vardai[i] << ": ";
        for(int j = 0; j < pazKiekis[i]; j++) {
            cout << pazymiai[i][j] << " ";
        }
        cout << endl;
    }
}

void rodytiViena(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazKiekis[], int mokKiekis) {
    string vardas;
    cout << "Ivesk varda: ";
    cin >> vardas;

    for(int i = 0; i < mokKiekis; i++) {
        if(vardai[i] == vardas) {
            cout << vardai[i] << ": ";
            for(int j = 0; j < pazKiekis[i]; j++) {
                cout << pazymiai[i][j] << " ";
            }
            cout << endl;
            return;
        }
    }

    cout << "Mokinys nerastas!\n";
}

void keistiPazymi(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazKiekis[], int mokKiekis) {
    string vardas;
    cout << "Ivesk varda: ";
    cin >> vardas;

    for(int i = 0; i < mokKiekis; i++) {
        if(vardai[i] == vardas) {
            int nr;
            cout << "Kurio pazymio nr (nuo 0): ";
            cin >> nr;

            if(nr >= 0 && nr < pazKiekis[i]) {
                cout << "Naujas pazymys: ";
                cin >> pazymiai[i][nr];
            } else {
                cout << "Blogas numeris!\n";
            }
            return;
        }
    }

    cout << "Mokinys nerastas!\n";
}

void salinti(string vardai[], int pazymiai[][MAX_PAZYMIU], int pazKiekis[], int &mokKiekis) {
    string vardas;
    cout << "Ivesk varda: ";
    cin >> vardas;

    for(int i = 0; i < mokKiekis; i++) {
        if(vardai[i] == vardas) {

            for(int j = i; j < mokKiekis - 1; j++) {
                vardai[j] = vardai[j + 1];
                pazKiekis[j] = pazKiekis[j + 1];

                for(int k = 0; k < MAX_PAZYMIU; k++) {
                    pazymiai[j][k] = pazymiai[j + 1][k];
                }
            }

            mokKiekis--;
            cout << "Pasalinta!\n";
            return;
        }
    }

    cout << "Mokinys nerastas!\n";
}