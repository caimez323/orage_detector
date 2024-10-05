/*

A  ameillorer 
  OK Rajouter le calcul de la distance
  OK Rajouter le fait de rester alerte pendant un certain temps
  Ajouter le capteur de température
  OK Rajouter la température dans le calcul
  OK Compter le nombre d'éclair

  Rajouter le bluetooth => module hc-O5 hc-06
  On peut 
  Direction ?

*/


int Led = PA5 ;

int nbrEclair = 0;

int pinSon = A0;
int valSon = 0;

int pinLumiere= A1;
int valLumiere = 0;
bool lumiereDetecte = false;
bool resetLumiere = false;

const int SEUIL_SON = 500;
const int SEUIL_LUMIERE = 670;

int debutLumiere = 0;
const int MAX_WAIT_LUM = 20*1000; //20 s
int debutBruit = 0;

int temperature = 0;


void setup ()
{
  pinMode (Led, OUTPUT) ;
  pinMode (pinSon, INPUT) ;
  pinMode (pinLumiere, INPUT);
  Serial.begin(9600);
}

void loop ()
{
  int valSon = analogRead(pinSon);
  int valLumiere = analogRead(pinLumiere);
  int distanceOrage = 0;
  //if lumière : 
  //Voir millis pour faire en sorte de rester alerte pendant un certain temps après la lumière
  //calcul de la distance avec des millis également

  //Si on detecte une lumère et qu'on en a pas déjà detecté
  if(valLumiere > SEUIL_LUMIERE && lumiereDetecte != true){
    Serial.println("Lumière détectée");
    lumiereDetecte = true;
    debutLumiere = millis();
  }

  //Si on a détecté de la lumière et qu'on detecte du son
  if(lumiereDetecte && valSon > SEUIL_SON ){
    Serial.println("Il y a eu un orage");
    //Calcul de la distance de l'orage
    int tempsSeconde = (millis() - debutLumiere)/1000;
    temperatureK = temperature+275;
    float vitesse = 20.05*sqrt(temperatureK)
    distanceOrage = temps * vitesse;
    Serial.print("L'orage a eu lieu à ");
    Serial.print(distanceOrage);
    Serial.println(" mètres");
    resetLumiere = true;
    nbrEclair++;
  }


  // Si on viens déjà de detecter un orage ou qu'on a attendu trop longtemps, on reset les variables
  if(resetLumiere || (millis() - debutLumiere) > MAX_WAIT_LUMIERE )){
    lumiereDetecte = false;
    debutLumiere = 0;
    resetLumiere = false;
  }

}
