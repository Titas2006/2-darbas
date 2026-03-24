#include <iostream>
using namespace std;

const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;


int main() {
    string vardai[MAX_MOKINIU];
    int pazymiai[MAX_MOKINIU][MAX_PAZYMIU];
    int pazKiekis[MAX_MOKINIU];
    int mokKiekis = 0;

    int pasirinkimas;

    do {
        cout << "\n1 - Ivesti\n";
        cout << "2 - Perziureti visu mokiniu pazymius\n";
        cout << "3 - Perziureti vieno mokinio pazymius\n";
        cout << "4 - Atnaujinti pazymi mokiniui\n";
        cout << "5 - Pasalinti mokini is saraso\n";
        cout << "0 - Iseiti\n";
        cout << "Pasirink: ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                cout << "Kiek mokiniu? ";
                cin >> mokKiekis;

                for (int i = 0; i < mokKiekis; i++) {
                    cout << "Vardas: ";
                    cin >> vardai[i];

                    cout << "Kiek pazymiu: ";
                    cin >> pazKiekis[i];

                    for (int j = 0; j < pazKiekis[i]; j++) {
                        cout << "Pazymys: ";
                        cin >> pazymiai[i][j];
                    }
                    cout << endl;
                }
                break;
            case 2:
                for (int i = 0; i < mokKiekis; i++) {
                    cout << vardai[i] << " ";

                    for (int j = 0; j < pazKiekis[i]; j++) {
                        cout << pazymiai[i][j] << " ";
                    }
                    cout << endl;
                }
                break;

            case 3: {
                    string vardas;
                    cout << "Iveskite mokinio varda: ";
                    cin >> vardas;

                    bool rastas = false;

                    for(int i = 0; i < mokKiekis; i++) {
                        if(vardai[i] == vardas) {
                            cout << vardai[i] << ": ";

                            for(int j = 0; j < pazKiekis[i]; j++) {
                                cout << pazymiai[i][j] << " ";
                            }

                            cout << endl;
                            rastas = true;
                        }
                    }

                    if(!rastas) {
                        cout << "Mokinys nerastas\n";
                    }

                    break;
                }

            case 4: {
                string vardas;
                cout << "Iveskite mokinio varda: ";
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

                        break;
                    }
                }

                break;
            }
            case 5: {
                string vardas;
                cout << "Iveskite mokinio varda: ";
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
                        cout << "Mokinys pasalintas!\n";
                        break;
                    }
                }

                break;
            }
        }
    } while (pasirinkimas != 0);

    return 0;
}
