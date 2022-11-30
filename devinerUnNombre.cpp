/*
 Programme : devinerUnNombre
 But :  l'utilisateur doit deviner un nombre aléatoir decidé par l'ordinateur
 Date de dernière modification : 08/09/2021
 Auteur : T.Lauriou/Q.Robert
 Remarques : Code conforme aux spécification internes données en cours
*/
#include<random>
#include <iostream>
#include <ctime>
using namespace std;
int main(void)
{
//declaration
int nbr_essai = 0;//nombre d'essai que l'utilisateur s'accorde pour trouver le bon nombre.
unsigned long nbr_chercher;//nbr aléatoire décidé par l'ordinateur se trouvant entre les bornes.
bool W_L;//indicateur de la victoire ou de la défaite de l'utilisateur false=défaite true=victoire.
unsigned long nbr_propose;//nombre que le joueur a proposé.
unsigned int borneInf;//La plus petite borne dans laquelle peut se trouver le nombre à chercher
unsigned int borneSup;//la plus grande borne dans laquelle peut se trouver le nombre à chercher



//présentation du jeu au joueur
cout << "JEU DU NOMBRE A DEVINER" <<endl;
cout << "vous allez choisir 2 nombre qui seront les limites possible puis un nombre sera choisi aleatoirement et vous devrez le trouver."<<endl;

//INITIALISATION************************************************************************************************************************************************************************************************************************************************
//**************************************************************************************************************************************************************************************************************************************************************

cout << "veuillez saisir le plus petit nombre que vous souhaitez deviner " <<endl;//l'utilisateur saisi la borne inférieur du nombre à deviner
cin >> borneInf;
cout << "veuillez saisir le plus grand nombre que vous souhaitez deviner " <<endl;//l'utilisateur saisi la borne supérieure du nombre à deviner
cin >> borneSup;

while (nbr_essai <=0)//verification que le nombre d'essai saisi est bel est bien positif et supérieur à 0
{
  cout << "combien d'essai souhaitez vous avoir ?" <<endl;
cin >> nbr_essai; 
}

   srand((unsigned int)time(0));//ici on utilise le temps afin que le random soit différent à chaque fois
nbr_chercher = rand()% (borneSup - borneInf +1) + borneInf;//on affecte à nbr_chercher une valeur aléatoire entre la borne inférieur et la borne supérieure






//JEU***********************************************************************************************************************************************************************************************************************************************************
//************************************************************************************************************************************************************************************************************************************************************

do//boucle qui permet au joueur de jouer tant qu'il lui reste des essais.
{
   //saisie du nombre supposé par le joueur
   cout <<"veuillez saisir un nombre entre "<<borneInf<< " et "<<borneSup << " il vous reste "<<nbr_essai<<" essai"<<endl;
   cin >> nbr_propose;

   //comparaison du nombre suppose avec le vrai avec affichage en conséquence
   if (nbr_propose > borneSup || nbr_propose < borneInf)//le joueur a rentré une valeur en dehors des bornes 
   {
       cout <<"Veuillez saisir un nombre dans l'intervalle donnee"<<endl;
       nbr_essai = nbr_essai + 1;
   }
   else if(nbr_chercher > nbr_propose)//le nombre proposé par le joueur est inférieur au nombre à deviner
   {
       cout << "Votre nombre est inferieur de celui a decouvrir"<<endl;
   }
   else if(nbr_propose > nbr_chercher)//le nombre deviner par le joueur est inférieur au nombre à proposé
   {
       cout << "Votre nombre est superieur de celui a decouvrir"<<endl;
   }
   else//le joueur a trouvé le bon nombre il a gagné youpla boom
   {
       W_L = true;//on change le bool à true pour signifier que le joueur a gagné
       break;//on break pour sortir de la boucle
   }
   nbr_essai = nbr_essai-1;//a chaque fin de tour on enlève 1 essai

} while (nbr_essai > 0);//quand il reste plus d'essai on sort de la boucle



//SITUATION FINALE*************************************************************************************************************************************************************************************************************************************************
//*********************************************************************************************************************************************************************************************************************************************************

//affichage de la victoire ou de la défaite

if(W_L == false)//si le joueur à perdu
{
    cout << "perdu le nombre a deviner etait "<<nbr_chercher;
}
else//si le joueur à gagné
{
    cout << "bravo il te restait encore "<<nbr_essai<<" essai";
}
}