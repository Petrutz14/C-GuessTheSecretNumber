//GUESSING GAME
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <Windows.h>
#include <MMSystem.h>
#include <fstream>
using namespace std;

//Variables
int num;
int guesses=0;
int maxGuess=0;
int gamemode;
int x;
int logStat;
string lang;
string z;

void error(int y){
while (cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "You can only enter numbers smaller than 10 digits:";
        cin >> y;}
}

void fin(string m){
    system("cls");
    Sleep(1000);

    for(int i=0;i<m.length();i++){
        cout<<m[i];
        Sleep(150);}

    Sleep(500);
    cout<<endl;
}

int main(){
//Win Log
fstream Guess;
Guess.open("WinLog.txt",ofstream::app);
if(!Guess.is_open()){
    cout<<"LOG ERROR.UNABLE TO KEEP TRACK OF ACTIVITY"<<endl;
}

//PlaySound(TEXT("sound.wav"),NULL,SND_ASYNC);
system("color 3f");
srand(time(NULL));

//!Language
cout<<"Chose your language(EN;RO):";
cin>>lang;
cout<<endl;

//Invalid language
while(lang != "en" && lang != "En" && lang != "EN" && lang != "english" && lang != "English" && lang != "ro" && lang != "Ro" && lang != "RO" && lang != "romana" && lang != "Romana" && lang != "romanian" && lang != "Romanian"){
    cout<<"Invalid language"<<endl<<endl;
    cout<<"Chose your language(EN;RO):";
    cin>>lang;
    cout<<endl;
}

//!English
if(lang == "en" || lang == "En" || lang == "EN" || lang == "english" || lang == "English"){

cout<<"Working on the program";
for(int i=0;i<3;i++){
    cout<<".";
    Sleep(500);
}
system("cls");


//Artwork
cout<<"THE"<<endl;
cout<<"  GUESSING"<<endl;
cout<<"GAME"<<endl<<endl;
//Instructions +Design box
cout<<char(201);

for(int i=0;i<=75;i++){
    cout<<char(205);
}
cout<<char(187);

cout<<""<<endl;
cout<<char(186)<<"How to play:                                                                "<<char(186)<<endl;

cout<<char(186)<<"1.Enter a range that your number to be in(ex:101 for numbers from 0 to 100)."<<char(186)<<endl;
cout<<char(186)<<"2.Enter your gamemode that you want to play.                                "<<char(186)<<endl;
cout<<char(186)<<"3.If you chose gamemode 0 enter the limit of guesses you want to have.      "<<char(186)<<endl;
cout<<char(186)<<"4.Guess the number! If you give up enter -99.                               "<<char(186)<<endl;
cout<<char(200);

for(int i=0;i<=75;i++){
    cout<<char(205);
}
cout<<char(188);
cout<<""<<endl;



//Initializing the secret number
cout<<"Press ENTER to play";
cin.get();
cin.get();
cout<<endl;

cout<<"Enter your number range:";
cin>>x;error(x);
cout<<endl;

while(x==0){
    cout<<"Must enter a number higher or lower than 0:";
    cin>>x;error(x);
    cout<<endl;
}
int sNum=rand()%x+1;

//Gamemode choser
cout<<"Enter your gamemode(0-Guess limit,1-No guess limit):";
cin>>gamemode;error(gamemode);
cout<<endl;

while(gamemode > 1 || gamemode < 0){
    cout<<gamemode<<" is not a gamemode.Enter your gamemode:";
    cin>>gamemode;error(gamemode);
    cout<<endl;
    }

if(gamemode == 0){
cout<<"Enter the guesses limit:";
cin>>maxGuess;error(maxGuess);
cout<<endl;
    while(maxGuess<=0){
        cout<<"You can only enter a positive value(+):";
        cin>>maxGuess;error(maxGuess);
        cout<<endl;
    }
maxGuess -= 1;
}

//!Gamemode 0
if(gamemode==0){


cout<<"Guess the secret number:";
cin>>num;error(num);
cout<<endl;
//The main while
while(num != sNum && guesses<maxGuess){
//Give up
    if(num == -99){
        z="You gave up...";
        fin(z);

        Guess<<"State:Lost(Gave up)(Gamemode 0)"<<endl;
        break;
    }
//Admin comands
    else if(num == -101){
        cout<<"Admin comands(Comands):"<<endl;
        cout<<"Values:-333"<<endl;
        cout<<"Secret Number:-909"<<endl;
        cout<<"System:-12345"<<endl<<endl;
        cout<<"Guess the secret number:";
        cin>>num;error(num);
        cout<<endl;
    }
    else if(num == -333){
        cout<<"Admin comands(Values):"<<endl;
        cout<<"1.Secret number: "<<sNum<<endl;
        cout<<"2.Number: "<<num<<endl;
        cout<<"3.Guess range: "<<x<<endl;
        cout<<"4.Max guesses: "<<maxGuess<<endl;
        cout<<"5.Gamemode: "<<gamemode<<endl;
        cout<<"6.Language: "<<lang<<endl<<endl;
        cout<<"Guess the secret number:";
        cin>>num;error(num);
        cout<<endl;
    }
        else if(num == -909){
        cout<<"Admin comands(Secret Number):"<<endl;
        cout<<"Secret number:"<<sNum<<endl;
        cout<<"Guess the secret number:";
        cin>>num;error(num);
        cout<<endl;
    }
        else if(num == -12345){
        cout<<"Admin comands(System):"<<endl;
            if(system(NULL)){
                cout<<"Command processor exists"<<endl<<endl;
                cout<<"Guess the secret number:";
                cin>>num;error(num);
                cout<<endl;
            }
            else{
                cout<<"Command processor doesn't exists"<<endl;
                cout<<"Guess the secret number:";
                cin>>num;error(num);
                cout<<endl;
            }
        }
//Too low

    else if(num<sNum){
        cout<<"Too low.Guess the secret number:";
        cin>>num;error(num);
        cout<<endl;
        guesses++;
    }
//Too high
    else if(num>sNum){
        cout<<"Too high.Guess the secret number:";
        cin>>num;error(num);
        cout<<endl;
        guesses++;
    }
}
//Out of guesses
    if(guesses >= maxGuess && sNum != num && num != -99){
        z="Too many guesses.You lost...";
        fin(z);

        Guess<<"Lost(Too Many Guesses)(Gamemode 0)"<<endl;
    }
    else if(num == -99 && guesses==maxGuess){
        z="You gave up...";
        fin(z);

        Guess<<"State:Lost(Gave up)(Gamemode 0)"<<endl;
    }
//Correct


}
//!Gamemode 1
else if(gamemode==1){

cout<<"Guess the secret number:";
cin>>num;error(num);
cout<<endl;

//Main while
while(num != sNum){
//Give up
    if(num == -99){

    z="You gave up...";
    fin(z);

    Guess<<"State:Lost(Gave up)(Gamemode 1)"<<endl;
    break;}
//Admin comand
    else if(num == -101){
        cout<<"Admin comands(Comands):"<<endl;
        cout<<"Values:-333"<<endl;
        cout<<"Secret Number:-909"<<endl;
        cout<<"System:-12345"<<endl<<endl;
        cout<<"Guess the secret number:";
        cin>>num;error(num);
        cout<<endl;
    }
    else if(num == -333){
        cout<<" "<<endl;
        cout<<"Admin comands(Values):"<<endl;
        cout<<"1.Secret number: "<<sNum<<endl;
        cout<<"2.Number: "<<num<<endl;
        cout<<"3.Guess range: "<<x<<endl;
        cout<<"4.Max guesses: "<<maxGuess<<endl;
        cout<<"5.Gamemode: "<<gamemode<<endl;
        cout<<"6.Language: "<<lang<<endl<<endl;
        cout<<"Guess the secret number:";
        cin>>num;error(num);
        cout<<endl;
    }
    else if(num == -909){
        cout<<""<<endl;
        cout<<"Admin comands(Secret Number):"<<endl;
        cout<<"Secret number: "<<sNum<<endl<<endl;
        cout<<"Guess the secret number:";
        cin>>num;error(num);
        cout<<endl;
    }
    else if(num == -12345){
        cout<<""<<endl;
        cout<<"Admin comands(System):"<<endl;
            if(system(NULL)){
                cout<<"Command processor exists"<<endl<<endl;
                cout<<"Guess the secret number:";
                cin>>num;error(num);
                cout<<endl;
            }
            else{
                cout<<"Command processor doesn't exists"<<endl;
                cout<<"Guess the secret number:";
                cin>>num;error(num);
                cout<<endl;
            }
    }
//Too low
    else if(num<sNum){
        cout<<"Too low.Guess the secret number:";
        cin>>num;error(num);
        cout<<endl;
    }
//Too high
    else if(num>sNum){
        cout<<"Too high.Guess the secret number:";
        cin>>num;error(num);
        cout<<endl;
    }
}

}

//Correct
if(num==sNum){
    z="Correct! You guessed the secret number!";
    fin(z);

    Guess<<"State:Won"<<endl;
}



//Feedback
cout<<endl;
cout<<"I hope you liked my game!"<<endl<<endl;
cout<<"Press ENTER to exit";
cin.get();
cin.get();
Guess.close();
}

//--------------------------------------------------------------------------------

//!Romanian
else if(lang == "ro" || lang == "Ro" || lang == "RO" || lang == "romanian" || lang == "Romanian" || lang == "romana" || lang == "Romana"){

cout<<"Lucrand la program";
for(int i=0;i<3;i++){
    cout<<".";
    Sleep(500);
}
system("cls");

//Artwork
cout<<"GHICESTE"<<endl;
cout<<"    NUMARUL"<<endl;
cout<<"SECRET"<<endl<<endl;
//Instructions +Design box
cout<<char(201);

for(int i=0;i<=75;i++){
    cout<<char(205);
}
cout<<char(187);

cout<<""<<endl;
cout<<char(186)<<"Cum se joaca:                                                               "<<char(186)<<endl;

cout<<char(186)<<"1.Introduceti unde vrei numarul sa fie(ex:100 pentru numere intre 0 si 100) "<<char(186)<<endl;
cout<<char(186)<<"2.Introduceti modul de joc care il doriti                                   "<<char(186)<<endl;
cout<<char(186)<<"3.Daca ati ales modul 0 introduceti limita de incercari                     "<<char(186)<<endl;
cout<<char(186)<<"4.Ghiceste numarul!Daca va dati batut introdu -99 la numar                  "<<char(186)<<endl;
cout<<char(200);

for(int i=0;i<=75;i++){
    cout<<char(205);
}
cout<<char(188);
cout<<""<<endl;

//Initializing the secret number
cout<<"Apasa ENTER pentru a juca:"<<endl;
cin.get();
cin.get();

cout<<"Introduceti raza unde doriti numarul sa fie:"<<endl;
cin>>x;
while (cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Puteti introduce doar numere:\n";
        cin >> x;}
while(x==0){
    cout<<"Introduceti un numar mai mare sau mai mic decat 0:"<<endl;
    cin>>x;
        while (cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Puteti introduce doar numere:\n";
        cin >> x;}
    }
int sNum=rand()%x+1;

//Gamemode choser
cout<<"Introduceti modul de joc(0-Cu limita de incercari,1-Fara limita):"<<endl;
cin>>gamemode;
while (cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Puteti introduce doar numere:\n";
        cin >> gamemode;}

while(gamemode > 1 || gamemode < 0){
    cout<<gamemode<<" nu este un mod de joc.Introduceti modul de joc:"<<endl;
    cin>>gamemode;
    while (cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Puteti introduce doar numere:\n";
        cin >> gamemode;}
    }

if(gamemode == 0){

cout<<"Introduceti limita de incercari:"<<endl;
cin>>maxGuess;
while (cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Puteti introduce doar numere:\n";
        cin >> maxGuess;}
    while(maxGuess<0){
        cout<<"Puteti introduce doar valori pozitive(+):"<<endl;
        cin>>maxGuess;
    }
maxGuess += 1;
}

//!Gamemode 0
if(gamemode==0){

cout<<"Ghiciti numarul secret"<<endl;
cin>>num;
while (cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Puteti introduce doar numere:\n";
        cin >> num;}
//The main while
while(num != sNum && guesses<maxGuess){
//Give up
    if(num == -99){
        cout<<"V-ati dat batut...Numarul secret era "<<sNum<<endl;
        break;
    }
//Admin comands
    else if(num == -101){
        cout<<"Comenzi admin(Comenzi):"<<endl;
        cout<<"Valori:-333"<<endl;
        cout<<"Numarul secret:-909"<<endl;
        cout<<"Sistem:-12345"<<endl<<endl;
        cout<<"Ghiciti numarul secret:"<<endl;
        cin>>num;
    }
    else if(num == -333){
        cout<<" "<<endl;
        cout<<"Comenzi admin(Valori):"<<endl;
        cout<<"1.Numarul secret: "<<sNum<<endl;
        cout<<"2.Numarul introdus: "<<num<<endl;
        cout<<"3.Raza: "<<x<<endl;
        cout<<"4.Incercarile maxime: "<<maxGuess<<endl;
        cout<<"5.Mod de joc: "<<gamemode<<endl;
        cout<<"6.Limba "<<lang<<endl<<endl;
        cout<<"Ghiciti numarul secret:"<<endl;
        cin>>num;
    }
        else if(num == -909){
        cout<<""<<endl;
        cout<<"Comenzi admin(Numarul secret):"<<endl;
        cout<<"Numarul secret:"<<sNum<<endl;
        cout<<"Ghiciti numarul secret:"<<endl;
        cin>>num;
    }
        else if(num == -12345){
        cout<<""<<endl;
        cout<<"Comenzi admin(Sistem):"<<endl;
            if(system(NULL)){
                cout<<"Procesorul de comenzi exista"<<endl<<endl;
                cout<<"Ghiciti numarul secret:"<<endl;
                cin>>num;
            }
            else{
                cout<<"Procesorul de comenzi nu exista"<<endl;
                cout<<"Ghiciti numarul secret:"<<endl;
                cin>>num;
            }
        }
//Too low

    else if(num<sNum){
        cout<<"Prea mic.Ghiciti numarul secret:"<<endl;
        cin>>num;
            while (cin.fail()){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Puteti introduce doar numere:\n";
            cin >> num;}
        guesses++;
    }
//Too high
    else if(num>sNum){
        cout<<"Prea mare.Ghiciti numarul secret:"<<endl;
        cin>>num;
            while (cin.fail()){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Puteti introduce doar numere:\n";
            cin >> num;}
        guesses++;
    }
}
//Out of guesses
    if(guesses >= maxGuess && sNum != num && num != -99){
        cout<<"Prea multe incercari.Ati pierdut...Numarul era "<<sNum<<endl;
}
    else if(num == -99 && guesses==maxGuess){
        cout<<"V-ati dat batut...Numarul era "<<sNum<<endl;
    }
//Correct


}
//!Gamemode 1
else if(gamemode==1){

cout<<"Ghiciti numarul secret:"<<endl;
cin>>num;
    while (cin.fail()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Puteti introduce doar numere:\n";
        cin >> num;}

//Main while
while(num != sNum){
//Give up
    if(num == -99){
        cout<<"V-ati dat batut...Numarul era "<<sNum<<endl;
        break;}
//Admin comand
    else if(num == -101){
        cout<<"Comenzi admin(Comenzi):"<<endl;
        cout<<"Valori:-333"<<endl;
        cout<<"Numarul secret:-909"<<endl;
        cout<<"Sistem:-12345"<<endl<<endl;
        cout<<"Ghiciti numarul secret:"<<endl;
        cin>>num;
    }
    else if(num == -333){
        cout<<" "<<endl;
        cout<<"Comenzi admin(Valori):"<<endl;
        cout<<"1.Numarul secret: "<<sNum<<endl;
        cout<<"2.Numarul introdus: "<<num<<endl;
        cout<<"3.Raza: "<<x<<endl;
        cout<<"4.Incercarile maxime: "<<maxGuess<<endl;
        cout<<"5.Mod de joc: "<<gamemode<<endl;
        cout<<"6.Limba "<<lang<<endl<<endl;
        cout<<"Ghiciti numarul secret:"<<endl;
        cin>>num;
    }
        else if(num == -909){
        cout<<""<<endl;
        cout<<"Comenzi admin(Numarul secret):"<<endl;
        cout<<"Numarul secret:"<<sNum<<endl;
        cout<<"Ghiciti numarul secret:"<<endl;
        cin>>num;
    }
        else if(num == -12345){
        cout<<""<<endl;
        cout<<"Comenzi admin(Sistem):"<<endl;
            if(system(NULL)){
                cout<<"Procesorul de comenzi exista"<<endl<<endl;
                cout<<"Ghiciti numarul secret:"<<endl;
                cin>>num;
            }
            else{
                cout<<"Procesorul de comenzi nu exista"<<endl;
                cout<<"Ghiciti numarul secret:"<<endl;
                cin>>num;
            }
        }
//Too low
    else if(num<sNum){
        cout<<"Prea mic.Ghiciti numarul secret:"<<endl;
        cin>>num;
            while (cin.fail()){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Puteti introduce doar numere:\n";
            cin >> num;}
    }
//Too high
    else if(num>sNum){
        cout<<"Prea mare.Ghiciti numarul secret:"<<endl;
        cin>>num;
            while (cin.fail()){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Puteti introduce doar numere:\n";
            cin >> num;}
    }
}

}

//Correct
if(num==sNum){
    cout<<"Corect!Ati ghicit numarul!"<<endl;
}



//Feedback
cout<<" "<<endl;
cout<<"Sper ca va placut jocul!"<<endl<<endl;
cout<<"Apasati ENTER pentru a iesi"<<endl;
cin.get();
cin.get();

}
delete &num;
delete &guesses;
delete &maxGuess;
delete &gamemode;
delete &x;
delete &lang;
delete &z;

    return 0;
}


//Code created by Craciunoiu Petru.DO NOT DELTE THIS COMMENT!
