#include <iostream>
#include <cstdlib> //random 
#include <windows.h>  //couleur
#include <iomanip> // set width
#include<bits/stdc++.h> //fonctions mathematiques
#include<conio.h> // fleches
using namespace std;

int board[4][4];
int direction_Ligne[] = {1, 0, -1, 0};
int direction_Colone[] = {0, 1, 0, -1};

pair<int, int> tireDeuxOuQuatre(){
    int compteur = 1, ligne, colone, deuxouquatre;
    deuxouquatre = rand() % 10; 
    if (deuxouquatre == 0) {
        while(compteur == 1){
            ligne = rand() % 4;
            colone = rand() % 4;
            if (board[ligne][colone] == 0){
                board[ligne][colone] = 4;
                compteur = 0;
            }
        }   
    }
    else {
        while(compteur == 1){
            ligne = rand() % 4;
            colone = rand() % 4;
            if (board[ligne][colone] == 0){
                board[ligne][colone] = 2;
                compteur = 0;
            }
        }
    }
    return make_pair(ligne, colone);
} 

void SetColor(int Couleur) { //NIVEAU 1 COULEUR POUR TOUTE LA FONCTION
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, Couleur);
}

void Jeu () {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++){
            board[i][j] = 0;
        }
    }
    tireDeuxOuQuatre();
    tireDeuxOuQuatre();
}

void Score(){
    int score = 0;
    for (int i = 0; i>=0 && i < 4; i++){
        for (int j = 0; j>=0 && j < 4; j++) {
            if (board[i][j] != 2) {
                score += board[i][j];
            }
        }
    }
    SetColor(7); //NIVEAU 1 COULEUR
    cout << "Votre score est: ";
    SetColor(12); //NIVEAU 1 COULEUR
    cout << score << "\n";
}

bool Gagnant() {
    for (int i = 0; i>=0 && i < 4; i++){
        for (int j = 0; j>=0 && j < 4; j++){
            if (board[i][j] >= 2048){
                SetColor(11); //NIVEAU 1  COULEUR
                cout << "VOUS AVEZ GAGNEZ!!!!! CONTINUEZ A JOUER";
                return true;
            }
        }          
    }
    return false;
}

bool Perdant() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            // Verifie si il existe des movement possibles vers la droite
            if (j < 3 && (board[i][j] == 0 || board[i][j] == board[i][j + 1])) {
                return true;
            }
            // Verifie si il existe des movement possibles vers la gauche
            if (j > 0 && (board[i][j] == 0 || board[i][j] == board[i][j - 1])) {
                return true;
            }
            // Verifie si il existe des movement possibles vers le bas
            if (i < 3 && (board[i][j] == 0 || board[i][j] == board[i + 1][j])) {
                return true;
            }
            // Verifie si il existe des movement possibles vers le haut
            if (i > 0 && (board[i][j] == 0 || board[i][j] == board[i - 1][j])) {
                return true;
            }
            if (board[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}

void ImprimeInterface(){
    system("cls"); //NIVEAU 1 rafraishissement de l'ecran
    SetColor(2); //NIVEAU 1 COULEUR
    cout << "*************************\n";
    for (int i = 0; i < 4; i++){
        SetColor(2);
        cout << "*";
        for (int j = 0; j < 4; j++){
            if (board[i][j]==0) {
                SetColor(2); //NIVEAU 1 COULEUR
                cout << setw(6) << "  *";
                }
            else if (board[i][j] == 2) {
                SetColor(1); //NIVEAU 1 COULEUR
                cout << setw(3) << board[i][j] << setw(3);
                SetColor(2); //NIVEAU 1 COULEUR
                cout << "*";
            }
            else if (board[i][j] == 4) {
                SetColor(3); //NIVEAU 1 COULEUR
                cout << setw(3) << board[i][j] << setw(3);
                SetColor(2); //NIVEAU 1 COULEUR
                cout << "*";
            }
            else if (board[i][j] == 8) {
                SetColor(4); //NIVEAU 1 COULEUR
                cout << setw(3) << board[i][j] << setw(3);
                SetColor(2); //NIVEAU 1 COULEUR
                cout << "*";
            }
            else if (board[i][j] == 16) {
                SetColor(5); //NIVEAU 1 COULEUR
                cout << setw(3) << board[i][j] << setw(3);
                SetColor(2); //NIVEAU 1 COULEUR
                cout << "*";
            }
            else if (board[i][j] == 32) {
                SetColor(6); //NIVEAU 1 COULEUR
                cout << setw(3) << board[i][j] << setw(3);
                SetColor(2); //NIVEAU 1 COULEUR
                cout << "*";
            }
            else if (board[i][j] == 64) {
                SetColor(7); //NIVEAU 1 COULEUR
                cout << setw(3) << board[i][j] << setw(3);
                SetColor(2); //NIVEAU 1 COULEUR
                cout << "*";
            }
            else if (board[i][j] == 128) {
                SetColor(8); //NIVEAU 1 COULEUR
                cout << setw(3) << board[i][j] << setw(3);
                SetColor(2); //NIVEAU 1 COULEUR
                cout << "*";
            }
            else if (board[i][j] == 256) {
                SetColor(9); //NIVEAU 1 COULEUR
                cout << setw(3) << board[i][j] << setw(3);
                SetColor(2); //NIVEAU 1 COULEUR
                cout << "*";
            }
            else if (board[i][j] == 512) {
                SetColor(10); //NIVEAU 1 COULEUR
                cout << setw(3) << board[i][j] << setw(3);
                SetColor(2); //NIVEAU 1 COULEUR
                cout << "*";
            }
            else if (board[i][j] == 1024) {
                SetColor(11); //NIVEAU 1 COULEUR
                cout << setw(3) << board[i][j] << setw(3);
                SetColor(2); //NIVEAU 1 COULEUR
                cout << "*";
            }
            else if (board[i][j] == 2048) {
                SetColor(12); //NIVEAU 1 COULEUR
                cout << setw(3) << board[i][j] << setw(3);
                SetColor(2); //NIVEAU 1 COULEUR
                cout << "*";
            }
            else if (board[i][j] > 2048) {
                SetColor(13); //NIVEAU 1 COULEUR
                cout << setw(3) << board[i][j] << setw(3);
                SetColor(2); //NIVEAU 1 COULEUR
                cout << "*";
            }
        }
        cout << "\n";
    }
    cout << "*************************\n";
    SetColor(15); //NIVEAU 1 COULEUR
    cout << "Le but du jeu est d'obtenir un score de 2048. Utilizer les fleches pour naviguer sur le plateau et les touches N, Q pour lancer un Nouveau Jeu et Quitter la partie, respectivement.\n";
    int maximum = 0;
    for (int i = 0; i<=4 ; i++){
        for (int j = 0; j<=4 ; j++){
            if (board[i][j] > maximum) {
                maximum = board[i][j];
            }
        }
    }
    Score();
    SetColor(7); //NIVEAU 1 COULEUR
    cout << "Votre Bloc le plus grand est: "; 

    if (maximum == 2) {SetColor(1); cout << maximum << "\n";}
    if (maximum == 4) {SetColor(13); cout << maximum<< "\n";}
    if (maximum == 8) {SetColor(3); cout << maximum<< "\n";}
    if (maximum == 16) {SetColor(4); cout << maximum<< "\n";}
    if (maximum == 32) {SetColor(5); cout << maximum<< "\n";}
    if (maximum == 64) {SetColor(6); cout << maximum<< "\n";}
    if (maximum == 128) {SetColor(7); cout << maximum<< "\n";}
    if (maximum == 256) {SetColor(8); cout << maximum<< "\n";}
    if (maximum == 512) {SetColor(9); cout << maximum<< "\n";}
    if (maximum == 1024) {SetColor(10); cout << maximum<< "\n";}
    if (maximum == 2048) {SetColor(11); cout << maximum<< "\n";}
    if (maximum > 2048) {SetColor(12); cout << maximum << "\n";}
    Gagnant();
}

bool MovementPossible(int ligne, int colone, int nextLigne, int nextColone) {
    if (nextLigne < 0 || nextColone < 0 || nextLigne >= 4 || nextColone >= 4 || (board[nextLigne][nextColone] != 0 && board[ligne][colone] != board[nextLigne][nextColone])) {
        return false;
    }
    return true;
}

void AppliquerMovement(int direction){
    int startLigne = 0, startColone = 0, ligneStep = 1, coloneStep = 1;
    if (direction == 0){
        startLigne = 3;
        ligneStep = -1;
    }
    if (direction == 1){
        startColone = 3;
        coloneStep = -1;
    }
    int movePossible, canAddPiece = 0;
    do {
        movePossible = 0;
        for (int i = startLigne; i>=0 && i < 4; i += ligneStep){
            for (int j = startColone; j>=0 && j < 4; j += coloneStep){
                int nextI = i + direction_Ligne[direction], nextJ = j + direction_Colone[direction];
                if (board[i][j] != 0 && MovementPossible(i, j, nextI, nextJ)){
                    board[nextI][nextJ] += board[i][j];
                    board[i][j] = 0;
                    movePossible = canAddPiece = 1;
                }    
            }
        }
    } while(movePossible);
    if (canAddPiece){
        tireDeuxOuQuatre();
    }
}
    
void IA() {
    int a = 0;
    while (a != 100){
        // Evalue les direction possible et le meilleur score
        int bestScore = -1;
        int bestDirection = -1;

        // Fait une copie du tableau
        int tempBoard[4][4];
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                tempBoard[i][j] = board[i][j];
            }
        }
        // Fait une simulation des movement 
        for (int direction = 0; direction < 4; ++direction) {
            // Simulate the move
            AppliquerMovement(direction);
            
            // Evalue le meilleur score
            int score = 0; 
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    score += tempBoard[i][j];
                }
            }

            // Bouge en fonction du meilleur tableau, ou si il n'ya pas de movement possible bouge aleatoirement
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if (board[i][j] == tempBoard[i][j]){
                        int aleatoire = rand() %4;
                        AppliquerMovement(aleatoire);
                    }
                }
            }

            // Choisi le meilleur score
            if (score > bestScore) {
                bestScore = score;
                bestDirection = direction;
            }
        }

        // appliquer la meilleur direction 
        if (bestDirection != -1) {
            AppliquerMovement(bestDirection);
        }
        ImprimeInterface();
        if (Perdant() == false){
            break;
        }
        a = a + 1;
    }
}

int main(){
    SetColor(15); //NIVEAU 1 COULEUR
    cout<<"\n\n\n\n\t\t\t\tVoici le jeu 2048\n\n\n\t\tPresser n'importe quelle touche pour commencer!";
	getch(); //permet d'attendre qu'une touche soit presser
    //srand(time(0));
    char commandToDir[128]; //les lettres n,q,w,a,s,d sont dans la table ASCII entre 0 et 128 
    commandToDir['s'] = 0;
    commandToDir['d'] = 1;
    commandToDir['w'] = 2;
    commandToDir['a'] = 3;
    Jeu();
    int ch;
    while (true){
        if (Perdant() == false) break;
        ImprimeInterface();        
        ch = getch();   
        if(ch==72) AppliquerMovement(commandToDir['w']); //move up  //NIVEAU 1 FLECHES!!!
    	if(ch==80) AppliquerMovement(commandToDir['s']); //move down  //NIVEAU 1 FLECHES!!!
    	if(ch==75) AppliquerMovement(commandToDir['a']); //move left  //NIVEAU 1 FLECHES!!!
    	if(ch==77) AppliquerMovement(commandToDir['d']); //move right  //NIVEAU 1 FLECHES!!!
        if (ch == 110) Jeu(); // New game
        if (ch == 113) break; // End game
        if (ch == 97) IA(); //AI
    }
    SetColor(15);  //NIVEAU 1 COULEUR
    cout<<"\n\n\t\t\tLE JEU EST FINI!!!\n\n\n";
    return 0;
}






