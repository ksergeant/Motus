#include <iostream>     						// Bibliothèque 
#include <stdlib.h> 
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define max 50         							 // Directive  
#define taille_mot 6      
#define nb_tentative_max 6
using namespace std;         
char solution[max];      						// Déclaration des Variables Globales  Char = Caractères, Int = Entier, Bool = Booléen ;     
char essais[max];
char aux[max];
char affichage[max];
char copie[max];
int nbtentative=0;
bool bon_mot;                      
bool jeu_fini=false;
int i=-1;
#define NOIR 30
#define ROUGE 31
#define	VERT  32
#define JAUNE 33
#define	BLEU  34
#define MAGENTA 35
#define BLANC 37

#define FRouge 41
#define	FVert  42
#define FJaune 43
#define	FBleu  44
#define FMagenta 45
// Fonction permettant de Saisir le mot de 6 lettres 

void  saisie_sol()
{
	cout<<"Taper un mot de 6 lettres\n"; 		//Affiche le "cout"
	cin>>solution; 								//Récupère le mot saisie (solution)
	system("clear"); 							// Efface l'écran pour cacher le mot saisie
while(strlen(solution)!=taille_mot)				/*boucle "tant que" le mot saisie n'est pas égal à la variable "taille_mot" 
												alors le programmes exécute les instructions suivante;*/
{	system("clear");							// Efface l'écran lors de l'erreur
	cout<<"Erreur taper Ã  nouveau un mot de 6 lettres" <<endl; //Affiche le message a l'utilisateur
	cin>>solution; 								// récupère le mot saisie
	}	
}
// Fonction permettant de tester un mot de lettres de 6 lettres 

void saisie_essais()
{	int n; 													//variable locale declare "n"
	cout<<"Essayer de retrouver le mot"<<endl; 				//Affiche un message sur l'ecran
	cin>>essais;
	strcpy(copie,essais); 											//récupère les donnees de l'essais
	n=strlen(essais); 										/*la variable "n" declare la taille du mot 
															et test le nombre de caractere qui est defini taille_mot*/                      
while(n!=taille_mot) 										/* Boucle tant que la variables "n" ne defini pas la taille_mot 
															alors le programmes execute les instructions suivantes*/
{	system("clear"); 											// Efface l'ecran lors de l'erreur
	cout<<"Erreur taper a nouveau un mot de 6 lettres" <<endl; // Affiche le message saisie
	cin>>essais;
	strcpy(copie,essais);  												//Récupère les donnees de l'"essais"
	n=strlen(essais);											/*la variable "n" declare la taille du mot 
													et test le nombre de caractère qui est defini taille_mot, si le mot est faux
													la boucle continue*/
}  		
}


// Fonction permetttant de vérifier si il y a des lettres bien placées

bool verif_bien_place (char c, int num) 		/*Déclaration des variables locales Char "c" et Int "num"*/
{if (c==solution[num]) 	// Si la variable "C" est égale a la variable "num" alors la fonction retourne "true" sinon elle retourne "false"
	return true;
else
	return false;
}	



// Fonction permettant de verifier si il y a des lettres mal placees 
 

int verif_mal_place (char c)       						//Declaration de la variable locale char "c"
{	int i=0;       										// variable locale int "i"
	while ((i<taille_mot)&&(aux[i]!=c))i++;  // Boucle tant que "i" est inferieur Ã  "taille_mot" ou que "aux[i]" est different de "c"
	if (i==taille_mot) return -1; 			// si "i" est egal Ã  "taille_mot" alors la fonction renvoie "-1" sinon elle renvoie "i"
else return i;	

}
// Fonction permettant de verifier le mot 
bool verif_mot ()
{ 
	if (strcmp(essais,solution)==0)/* Si les chaÃ®nes de caractÃ¨res "essais" et "solution" sont Ã©gales, alors la variable "bon_mot" =true
										sinon "bon_mot" = false*/
	
	bon_mot=true; 					// le mot est vrai
	else
	bon_mot=false; 					// le mot est faux
	
	return bon_mot; 				// la fonction retourne bon_mot 
}
// Fonction qui copie le tableau solution dans le tableau aux

void initAux() 
{strcpy(aux, solution);

}

// Fonction qui tri les lettres 

void initAffichage(){
	bool present;       					// variable bool "present" locale
	int pos;           					 // variable int "pos" locale
	affichage[6]='\0'; 					// le tableau affichage s'arrÃ©te Ã  6
	initAux();        					// lance la fonction initAux()

	// Partie qui s'occupe des lettres bien placÃ©es
	for (int i=0;i<taille_mot;i++) 					//  Boucle qui continue tant que "i" est inferieur Ã  la variable "taille_mot"
	{
		present=verif_bien_place(essais[i],i); 			// test si la lettre de essais [i] est presente dans le tableau "solution" 
		if (present==true)   				// si elle est presente alors dans le le tableaux "aux" on remplace cette lettre par "_"
		{
			aux[i]='_';
		 affichage[i]=essais[i]; 							// copie de la lettre dans le tableau "affichage" 
		 essais[i]='_'; 									// remplace la lettre par "_" dans le tableau "essais" 
		 } else {
			  affichage[i]='_'; 						// sinon affecte "_" Ã  la place de [i] dans le tableau "affichage"
		 }		 
		 
	 }

	
	// Partie qui s'occupe des autres lettres
	for (int i=0;i<taille_mot;i++) 				// Boucle qui continue tant que "i" est inferieur Ã  la variable "taille de mot"
		if (essais[i]!='_') 
		{	
		pos=verif_mal_place(essais[i]);
		if(pos!=-1){
		affichage[i]='*';
		aux[pos]='_';
		
		}
	}


}
	void changeCouleurTexte(int code){
	cout<< "\033[";
	cout<<code;
	cout<<"m",1;	
}
	
	void changeCouleurFond(int code){
	cout<< "\033[";
	cout<<code+10;
	cout<<"m",1;
	}
	void afficheCar(int codeT, int codeF, char c)
	{
	changeCouleurTexte(codeT);
	changeCouleurFond(codeF);
	cout<<c;
	}
	
	//Fonction qui affiche le rÃ©sultat
	
	void affiche(){ 
		               
		cout<<affichage;              // Affichage 
		cout<<"\n";
		
		for (int i=0; i<6; i++){
		if(affichage[i]=='_')
		afficheCar(BLANC,BLEU,copie[i]);
		else if (affichage[i]=='*')
		afficheCar(BLANC,JAUNE,copie[i]);
		else afficheCar(BLANC,ROUGE,solution[i]);
		}
		cout<<"\n";
		changeCouleurTexte(0);
	}

	

	
// Fontion Main

int main()
{

	saisie_sol();                     // lance la fonction saisie_sol()
	initAux();                        // lance la fonction initAux()
	while(jeu_fini==false){           // Boucle qui test si le jeu est fini 
	saisie_essais();                  // lance saisie_essais()
	
	
		
	bon_mot=verif_mot();            // Test si le mot est bon   
	if (bon_mot==true)
		jeu_fini=true;              // si le test est bon le jeu est fini
	
	if (!bon_mot){                    
	initAffichage();                // lance la fonction initAffichage  
	affiche();                      // lance la fonction affiche()
	}
	
	nbtentative=nbtentative+1;               // Compteur pour le nombre d'essais 
	if(nbtentative==nb_tentative_max)        // Test si le nombre de tentatives est atteind si oui le jeu est fini
		jeu_fini=true;
		
	
		
}
	 cout << "le jeu est fini\n";            // Affichage 
if (bon_mot)                        
cout<<"Vous avez Gagner\n";
else
cout<<"Vous avez Perdu\n";

}
	
	



//Sergeant Kevin 

//Torres Jonathan
	
	

