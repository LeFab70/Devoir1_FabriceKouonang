/*
     Programmer: Fabrice Kouonang
     Date:       24/09/2024
     But:        Demander les informations du nombre de verre consomme, age debut de la consommation et age actuel de l'utilisateur 
                    puis calculer le nombre de jours de vie perdus selon la consommation de vin ainsi que les montants mensuels et annuels
                    de depenses engagees sur la periode de conssommation

*/

#include <iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;

//Liste des constantes du programme
unsigned short JOUR_EN_MIN = 24 * 60;
double NBRE_JOUR_ANNEE = 365.25;
unsigned short CONTENANCE_BTE = 750;
unsigned short VERRE_EN_ML = 152;  //consommation recommandee
unsigned short NBRE_MIN_PERDU = 15;
unsigned short SURPLUS_CONSO = 76;
double  PRIX_BTE = 14.99;


int main()
{
    //Liste des inputs du programmes
    string userName = "";
    unsigned short verParJour = 0;
    unsigned short  ageUser= 0;
    unsigned short  ageDebutConso= 0;

    //Listes des variables intermediaires
    unsigned short nbreAnneeConso = 0;

    //listes des outputs du programme
    char displayCarac = '='; //pour affichage des separations
    unsigned short nbreTotalBte = 0;
    unsigned short nbreSurplusBte = 0;
    unsigned short jourPerdu = 0;
    double montAnnuel = 0.0;
    double montMensuel = 0.0;

    //Entree des valeurs par l'utilisateur

    cout << "\t\tCALCUL DU NOMBRE DE JOURS DE VIE PERDUS"
        << endl
        << "\t\tSELON VOTRE CONSOMMATION DE VIN."
        << endl
        << setw(70)<< setfill(displayCarac)<<displayCarac
        << endl<<endl
        << "Pour debuter merci de fournir vos informations :"
        <<endl
        << "\tQuel est votre nom svp: ";
    getline(cin, userName);

    cout << "\tCombien de petit verre de vin (environ 152ml) buvez-vous par jour : ";
    cin >> verParJour;
    cout << "\tDonnez l'age ou vous avez commerce a consommer : ";
    cin >> ageUser;
    cout << "\tDonnez votre age actuel : ";
    cin >> ageDebutConso;
        
    /*
    ********************************
                Traitements
    *********************************
    */
    nbreAnneeConso = abs(ageUser - ageDebutConso);
    nbreTotalBte =ceil( (verParJour* nbreAnneeConso * NBRE_JOUR_ANNEE * VERRE_EN_ML) / CONTENANCE_BTE);
    montAnnuel = nbreTotalBte * PRIX_BTE;
    montMensuel = montAnnuel / (nbreAnneeConso * 12);  //12 represente le nombre de mois dans 1 an.
    nbreSurplusBte = ceil(nbreTotalBte*(1 - 1 / (double)verParJour));  //le surplus est donne par nbretotal-nbretotal/verParjour
    jourPerdu = ceil((nbreSurplusBte * CONTENANCE_BTE * NBRE_MIN_PERDU) / (double)(SURPLUS_CONSO*JOUR_EN_MIN));
    

    /*
    ***********************************
              Affichage des resultats
    ***********************************
    */
    cout << endl << endl
        << setw(70)<<displayCarac
        <<endl
        << userName
        << " Voici le compte rendu de la situation"
        << endl
        <<setw(70)
        <<endl<<endl
        <<"\"En moyenne, il ne faut pas boir plus de 152 ml "
        <<endl
        <<"(76 ml x 2 = 152 ml = 1 petit verre) de vin par jour,"
        <<endl
        <<"D'apres l'etude, un buveau perd en moyenne 15 min de vie pour"
        <<endl
        <<"chaque 76 ml de vin consomme au dessus du guide recommande\""
        <<endl<<endl
        <<"Nombre de bouteille de vin (750ml) consomme a jour: "
        <<nbreTotalBte
        <<endl
        <<"Nombre de bouteille de vin (750ml) consomme en TROP: "
        <<nbreSurplusBte
        <<endl<<endl
        <<"Nombre jours vie perdu: "
        <<jourPerdu
        << endl << endl;
    //changement du caractere de seperation de = en -
    displayCarac = '-';
    cout<< setw(70) << setfill(displayCarac) << displayCarac
        <<endl
        <<"En assumant, qu'une bouteille de vin standard coute 14.99$"
        <<endl
        <<setw(70)<<displayCarac
        <<endl
        <<"Le cout mensuel moyen de votre consommation de vin est de : "
        <<fixed<<setprecision(2)<<montMensuel<<" $"
        <<endl
        <<"Le cout total de votre consommation de vin est de: "
        << fixed << setprecision(2)<<montAnnuel<<" $"
        <<endl;
    //changement du caractere de seperation de - en =
    displayCarac = '=';
    cout << setw(70)<<setfill(displayCarac)<<displayCarac
         <<endl<<endl;

    system("pause");
    return 0;
}
