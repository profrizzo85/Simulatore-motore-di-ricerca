#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

fstream apriFileL(char *fileDaLeggere); //apre in lettura
fstream apriFileS(char *fileDaScrivere); //apre in scrittura
int contaRigheFile(fstream& file);
void daFileAdArray(fstream& file, string arrayDaGenerare[], int dimArray);
void scriviSuFile(fstream& fileDestinazione, string parolaDaScrivere);
string estraiParola(string arrayParole[], int dimArray);
int main()
{
    srand(time(NULL));
    int scelta=5, uscita=2, totRigheDizionario, i=0, j=0;
    char *percorsoDizionario="dizionario.txt";
    char cartellaFilePagina[]="pagine/";
    int nomeFilePagina=0;
    char *cNomeFilePagina;
    char estensioneFilePagina[]=".txt";
    char percorsoCompletoFilePagina[16];
    string contenuto, parolaEstratta, sNomeFilePagina;
    static string arrayDizionario[300000];
    fstream fileDizionario, filePagina;
    char vuoto[]="";

    do{
        do{
        cout << "**************MENU'**************" << endl;
        cout << "1. Crea pagine" << endl;
        cout << "2. Visualizza indice occorrenze" << endl;
        cout << "3. Visualizza indice" << endl;
        cout << "4. Cerca una parola" << endl;
        cout << "5. Esci" << endl;
        cout << "********************************" << endl;
        cin >> scelta;
        }while(scelta<1 || scelta>5);
        switch (scelta){
        case 1:
            fileDizionario = apriFileL(percorsoDizionario); //apre il dizionario in lettura
            totRigheDizionario = contaRigheFile(fileDizionario); //conta le righe del file Dizionario
            daFileAdArray(fileDizionario, arrayDizionario, totRigheDizionario);//carica il Dizionario nel vettore
            //concateno ogni volta con un numero che si incrementa e genero la pagina con le parole casuali
            //PROVARE A TRASFORMARLA IN FUNZIONE
            for (i=0; i<10; i++){
                strcat(percorsoCompletoFilePagina, cartellaFilePagina);
                sNomeFilePagina=to_string(nomeFilePagina); //converto da int a string
                cNomeFilePagina = &sNomeFilePagina[0];
                strcat(percorsoCompletoFilePagina, cNomeFilePagina);
                strcat(percorsoCompletoFilePagina, estensioneFilePagina);
                cout << percorsoCompletoFilePagina;
                filePagina = apriFileS(percorsoCompletoFilePagina);
                nomeFilePagina++;
                for (j=0; j<100; j++){
                    parolaEstratta = estraiParola(arrayDizionario, totRigheDizionario); //estraggo una parola
                    scriviSuFile(filePagina, parolaEstratta);//scrivo la parola estratta su file
                }
                strcpy(percorsoCompletoFilePagina, vuoto);
            }



            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            uscita=1;
            break;
        }


        if(scelta!=5){
            cout << "Vuoi uscire? (1.Si; 2.No)";
            cin >> uscita;
        }

    }while(uscita==2 );
    return 0;
}

fstream apriFileL(char *fileDaLeggere){
    fstream file(fileDaLeggere, ios::in);
    return file;
}
fstream apriFileS(char *fileDaScrivere){
    fstream file(fileDaScrivere, ios::out);
    return file;
}
//restituisce il numero di righe di un file
int contaRigheFile(fstream& file){
    string rigaLetta;
    int cont=0;
    while(!file.eof()){
        getline(file, rigaLetta);
        cont++;
    }
    file.seekg(0); //riporta in posizione iniziale lo stream
    return cont;
}
void daFileAdArray(fstream& file, string arrayDaGenerare[], int dimArray){
    string rigaLetta;
    for(int i=0; i<dimArray; i++){
        getline(file, rigaLetta);
        arrayDaGenerare[i]=rigaLetta;
    }
    file.seekg(0, ios::beg); //mi posiziono all'inizio del file, mi muovo di 0 byte dall'inizio (begin)
}
string estraiParola(string arrayParole[], int dimArray){
    arrayParole[1]="cazzabubbola";
    return arrayParole[rand()*(dimArray/RAND_MAX)%dimArray];
}
void scriviSuFile(fstream& fileDestinazione, string parolaDaScrivere){
    fileDestinazione << parolaDaScrivere << " ";
}

