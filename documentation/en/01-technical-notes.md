# TECHNICAL NOTES

> Translator's note: this is an English translation of the original 2008 Spanish
> document, which is an annotated source listing. The explanatory prose and every
> code comment have been translated; the code itself is preserved as code, and
> only its comments changed. String literals printed by the program remain in
> Spanish, as in the original. The Spanish transcription preserves the
> word-processor line breaks; this English version reflows those lines for
> readability. The code token stream is identical after whitespace normalization.

The program consists of 708 lines of code, one main function and 10 procedures
and functions that allow the program to meet all the requirements demanded by
the user.

This is the code, explaining each procedure, function and variable used.

```c
/*
  Author: Juan Camilo Rivera

  Name: guerra de caballos
  fecha:09/03/08
  Description: chess program with two horses that move randomly
*/
// libraries required by the program
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<time.h>
// variables, arrays and prototypes of the functions used in the program
const char simcab1=21,simcab2=156,sep=219;// symbols used to print the board
int   vectab[64],vecjugadas[8];// array that stores the game board information, and the array that stores the order in which the possible moves must be evaluated
int   cab1,cab2,jugada=1,orden,ganador=1;// variables to identify the position of horse 1, of horse 2, and the current move
void inicializacion();// initializes the array that holds the board data to zero
void cabubicacion(); // randomly designates which horse starts and in which position
void impresion();// prints the board
void conversionvm();// converts the array data into matrix rows and columns
int conversionmv(int cf,int cc);// converts the row and column data (matrix) into a specific location in the array
void vecjug();// sets the array of possible moves to be used and the order in which the possible moves must be analyzed, depending on a random number taken as the first option
void imprevecjug();// prints the moves array
int movcab(int &cf, int &cc);// This is the function where the horse's move options are evaluated according to the moves array: it checks whether the move is valid and, if it is, performs it; otherwise it does not.
int ordenjuego(int &tirocab1,int  &tirocab2);// depending on which horse rolls the higher number, it arranges who plays first, from then on until the game ends
void  impresionorden();// prints some announcements and controls that printing happens under the proper conditions; it also calls the function in charge of performing the horses' moves and printing the board
int cf1,cc1,cf2,cc2,cab;// variables used for the location in matrix terms and to determine which horse is making its move
void impresion0();// if one horse eats the other, prints while avoiding drawing both horses in the same position

void  main()// main function

{

      system("color 1f");// changes the console background and font colors to make a nicer environment
      inicializacion();// initializes the array to 0
      cabubicacion();// randomly designates which horse starts and in which position
      cout<<endl;
      getch();// allows viewing the board and the information printed on screen
      system("cls");// clears whatever is on screen
      while (jugada!=0)// loop that evaluates when the game ends
      {
            if(jugada!=0)
            {
      vecjug();// updates the moves array on every move
       impresionorden();// prints some announcements and controls that printing happens under the proper conditions; it also calls the function in charge of performing the horses' moves and printing the board
            }

}

}

void inicializacion()// initializes the array that holds the board data to zero
{
      int i;

for (i=0;i<=64;i++)
      {
            vectab[i]=0;

      }

}

void cabubicacion()// function that randomly indicates which horse starts and in which position
{
      int i=1,tirocab1,tirocab2;

      while  (i==1)
      {

      srand(time(NULL));// changes the seed

      tirocab1= rand() % 51;// makes a random roll for horse 2
      tirocab2= rand() % 51;// makes a random roll for horse 2

      cab1= rand() % 64;// randomly places horse 1
      cab2= rand() % 64;// randomly places horse 2
      if(cab1 != cab2 && tirocab1 != tirocab2)// checks that the horses do not roll the same number, so that it is possible to decide who starts, and that they do not start in the same position
      {
            i++;// allows leaving the loop
      }
      }

      orden=ordenjuego(tirocab1,tirocab2);// uses the ordenjuego function to know who starts, passing each horse's roll as information

       conversionvm();// converts each horse's location from array terms to matrix terms (rows and columns)
          cout<<"El     tiro      del      caballo      1      "<<simcab1<<"
fue:\n\n"<<tirocab1<<endl<<endl;// shows on screen the horses' rolls, used to decide who starts, and the random number that places the horses on the first move
          cout<<"El     tiro      del      caballo      2      "<<simcab2<<"
fue:\n\n"<<tirocab2<<endl<<endl;
      cout<<"El numero aleatorio para  ubicar  el  caballo  1  "<<simcab1<<"
fue:  "<<cab1<<endl<<endl;
       cout<<"En  terminos  de  filas  y   columnas   es:   fila:"<<cf1+1<<"
columna:"<<cc1+1<<endl<<endl;
      cout<<"El numero aleatorio para  ubicar  el  caballo  2  "<<simcab2<<"
fue:  "<<cab2<<endl<<endl;
       cout<<"En  terminos  de  filas  y   columnas   es:   fila:"<<cf2+1<<"
columna:"<<cc2+1<<endl<<endl;

}

void conversionvm()// converts the array data into matrix rows and columns
{
      cf1=cab1/8;
      cc1=cab1%8;
      cf2=cab2/8;
      cc2=cab2%8;

}

void impresion0()// if one horse eats the other, prints while avoiding drawing both horses in the same position
{
      int i,j,k=0,norepetir=0;
      cout<<endl<<endl;
      for(i=0;i<=7;i++){
      for(j=0;j<=7;j++)
      {

            if(vectab[k]==0)
            {
                 cout<<sep<<sep<<sep<<sep<<"  ";
            }
            else
        {
            if(vectab[k]!=vectab[cab1]&&vectab[k]!=vectab[cab2])
            {
             if (vectab[k]<=9)
            {
                 cout<<sep<<" "<<vectab[k]<<sep<<"  ";
            }
            else{

            cout<<sep<<vectab[k]<<sep<<"  ";
            }

            }

        if(vectab[k]==vectab[cab1]&&norepetir==0)
         {
                norepetir=1;
            if (vectab[k]<=9)
            {
                 cout<<simcab1<<" "<<vectab[k]<<simcab1<<"  ";
            }
            else{

            cout<<simcab1<<vectab[k]<<simcab1<<"  ";
            }
         }
        if(vectab[k]==vectab[cab2]&&norepetir==0)
         {
         norepetir=1;
            if (vectab[k]<=9)
            {
                 cout<<simcab2<<" "<<vectab[k]<<simcab2<<"  ";
            }
            else{

            cout<<simcab2<<vectab[k]<<simcab2<<"  ";
            }
         }

        }

            k++;
      }
      cout<<endl<<endl;
      }

}

void vecjug()// sets the array of possible moves to be used on each turn
{
      int i,aux,opcion;

      opcion=(rand() % 8)+1;

      aux=opcion;

      for (i=0;i<8;i++)
      {
            if(aux<=8)
            {
                 vecjugadas[i]=aux++;

            }
      }

      aux=opcion-1;
      for (i=7;i>=0;i--)
      {

            if(aux<opcion&&aux>0)
            {
                 vecjugadas[i]=aux--;

            }
      }

}

void imprevecjug()// prints the moves array
{
      int i;
      cout<<endl<<"El vector de movimiento es: ";

      for (i=0;i<8;i++)
      {
            if(i!=7)
            {
            cout<<vecjugadas[i]<<",";
            }
            else
            {
                 cout<<vecjugadas[i]<<".";
            }
      }
      cout<<endl<<endl;
}

int conversionmv(int cf,int cc)
{
      int ccab;
      ccab=cf * 8 +cc;
      return ccab;

}

int movcab(int &cf,int  &cc)// This is the function where the horse's move options are evaluated according to the moves array: it checks whether the move is valid and, if it is, performs it; otherwise it does not.
{
      int ccab,i=0;
      while(i!=-1)
      {
                switch(vecjugadas[i])// evaluates the possible moves to perform, according to the moves array
               {
            case 1:// 2 to the right, 1 up

          if(vecjugadas[i]==1&&jugada!=0)     // checks that the moves array is evaluating this case and that the game has not ended
         {
      if (cf-1>=0&&cf-1<=7&&cc+2>=0&&cc+2<=7)// checks that the horse does not leave the board
      {
                 ccab=conversionmv(cf-1,cc+2);

                  if ( cab==1 )// checks whose turn it is, i.e. which horse is playing, by calling the movcab function
                  {

                   if(vectab[ccab]==0||vectab[ccab]==vectab[cab2])// checks that the horse has not been in that position before, but allows entering it when the opposing horse is currently in the position it is about to move to
                  {
                      if(vectab[ccab]==vectab[cab2])// checks whether there is a winner
                    {

                                                    ganador=0;
                                                                           }

    cout<<" 1.";// shows whether this case was executed
    i=-1;// allows leaving the loop

      cf=cf-1;// performs the move in terms of rows
      cc=cc+2;// performs the move in terms of columns
      ccab=conversionmv(cf,cc);// converts the row and column data into a location in the array

      vectab[ccab]=jugada;// assigns the move number to the array position the horse is moving to
      break;// leaves the switch so that no more cases are evaluated
}

                  }
                  else// checks whose turn it is, i.e. which horse is playing, by calling the movcab function
                  {
      if(vectab[ccab]==0||vectab[ccab]==vectab[cab1])// checks that the horse has not been in that position before
                  {

                            if(vectab[ccab]==vectab[cab1])
                    {

                                                    ganador=0;
                                                                           }

    cout<<" 1.";// shows whether this case was executed
    i=-1;

      cf=cf-1;
      cc=cc+2;
      ccab=conversionmv(cf,cc);

      vectab[ccab]=jugada;
      break;
}

                 }
      }
}

              // the remaining cases have the same structure as the one explained in case 1
      case 2:// 2 up, 1 to the right

            if(vecjugadas[i]==2&&jugada!=0)
         {
      if (cf-2>=0&&cf-2<=7&&cc+1>=0&&cc+1<=7)// checks that the horse does not leave the board
      {
                 ccab=conversionmv(cf-2,cc+1);

                  if ( cab==1 )// checks that the horse has not been in that position before
                  {

                  if(vectab[ccab]==0||vectab[ccab]==vectab[cab2])
                  {
                    if(vectab[ccab]==vectab[cab2])
                    {

                                                    ganador=0;
                                                                           }

    cout<<" 2.";
    i=-1;
      cf=cf-2;
      cc=cc+1;
      ccab=conversionmv(cf,cc);

      vectab[ccab]=jugada;
      break;
}

                  }
                  else
                  {
    if(vectab[ccab]==0||vectab[ccab]==vectab[cab1])
                  {

                                      if(vectab[ccab]==vectab[cab1])
                    {

                                                    ganador=0;
                                                                           }

    cout<<" 2.";
    i=-1;
      cf=cf-2;
      cc=cc+1;
      ccab=conversionmv(cf,cc);

      vectab[ccab]=jugada;
      break;
}

                 }
      }
}
      case 3:// 2 up, 1 to the left
               if(vecjugadas[i]==3&&jugada!=0)
         {
      if (cf-2 >= 0 && cf-2 <= 7 && cc-1 >= 0 && cc-1 <= 7  )// checks that the horse does not leave the board
      {
                 ccab=conversionmv(cf-2,cc-1);

                  if ( cab==1 )// checks that the horse has not been in that position before
                  {

                  if(vectab[ccab]==0||vectab[ccab]==vectab[cab2])
                  {
                    if(vectab[ccab]==vectab[cab2])
                    {

                                                    ganador=0;
                                                                           }

          cout<<" 3.";
    i=-1;
      cf=cf-2;
      cc=cc-1;
      ccab=conversionmv(cf,cc);

      vectab[ccab]=jugada;
      break;
}

                  }
                  else
                  {
    if(vectab[ccab]==0||vectab[ccab]==vectab[cab1])
                  {

                                      if(vectab[ccab]==vectab[cab1])
                    {

                                                    ganador=0;
                                                                           }

          cout<<" 3.";
    i=-1;
      cf=cf-2;
      cc=cc-1;
      ccab=conversionmv(cf,cc);

      vectab[ccab]=jugada;
      break;
}

                 }
      }
}
      case 4:// 2 to the left, 1 up
         if(vecjugadas[i]==4&&jugada!=0)
         {
      if (cf-1>=0&&cf-1<=7&&cc-2>=0&&cc-2<=7)// checks that the horse does not leave the board
      {
                 ccab=conversionmv(cf-1,cc-2);

                  if ( cab==1 )// checks that the horse has not been in that position before
                  {

                  if(vectab[ccab]==0||vectab[ccab]==vectab[cab2])
                  {
                    if(vectab[ccab]==vectab[cab2])
                    {

                                                    ganador=0;
                                                                           }

          cout<<" 4.";
    i=-1;
      cf=cf-1;
      cc=cc-2;
      ccab=conversionmv(cf,cc);

      vectab[ccab]=jugada;
      break;
}

                  }
                  else
                  {
    if(vectab[ccab]==0||vectab[ccab]==vectab[cab1])
                  {

                                      if(vectab[ccab]==vectab[cab1])
                    {

                                                    ganador=0;
                                                                           }

          cout<<" 4.";
    i=-1;
      cf=cf-1;
      cc=cc-2;
      ccab=conversionmv(cf,cc);

      vectab[ccab]=jugada;
      break;
}

                 }
      }
}
      case 5:// 2 to the left, 1 down
         if(vecjugadas[i]==5&&jugada!=0)
         {
      if (cf+1>=0&&cf+1<=7&&cc-2>=0&&cc-2<=7)// checks that the horse does not leave the board
      {
                 ccab=conversionmv(cf+1,cc-2);

                  if ( cab==1 )// checks that the horse has not been in that position before
                  {

                  if(vectab[ccab]==0||vectab[ccab]==vectab[cab2])
                  {
                    if(vectab[ccab]==vectab[cab2])
                    {

                                                    ganador=0;
                                                                           }

          cout<<" 5.";
    i=-1;
      cf=cf+1;
      cc=cc-2;
      ccab=conversionmv(cf,cc);

      vectab[ccab]=jugada;
      break;
}

                  }
                  else
                  {
    if(vectab[ccab]==0||vectab[ccab]==vectab[cab1])
                  {

                                      if(vectab[ccab]==vectab[cab1])
                    {

                                                    ganador=0;
                                                                           }

          cout<<" 5.";
    i=-1;
      cf=cf+1;
      cc=cc-2;
      ccab=conversionmv(cf,cc);

      vectab[ccab]=jugada;
      break;
}

                 }
      }
}
    case 6:// 2 down, 1 to the left
          if(vecjugadas[i]==6&&jugada!=0)
         {
      if (cf+2>=0&&cf+2<=7&&cc-1>=0&&cc-1<=7)// checks that the horse does not leave the board
      {
                 ccab=conversionmv(cf+2,cc-1);

                  if ( cab==1 )
             // checks that the horse has not been in that position before

                  {

                  if(vectab[ccab]==0||vectab[ccab]==vectab[cab2])
                  {
                    if(vectab[ccab]==vectab[cab2])
                    {

                                                    ganador=0;
                                                                           }

          cout<<" 6.";
    i=-1;
      cf=cf+2;
      cc=cc-1;
      ccab=conversionmv(cf,cc);

      vectab[ccab]=jugada;
      break;
}

                  }
                  else
                  {
    if(vectab[ccab]==0||vectab[ccab]==vectab[cab1])
                  {

                                      if(vectab[ccab]==vectab[cab1])
                    {

                                                    ganador=0;
                                                                           }

          cout<<" 6.";
    i=-1;
      cf=cf+2;
      cc=cc-1;
      ccab=conversionmv(cf,cc);

      vectab[ccab]=jugada;
      break;
}

                 }
      }
}
    case 7:// 2 down, 1 to the right
         if(vecjugadas[i]==7&&jugada!=0)
         {
      if (cf+2>=0&&cf+2<=7&&cc+1>=0&&cc+1<=7)// checks that the horse does not leave the board
      {
                 ccab=conversionmv(cf+2,cc+1);

                  if ( cab==1 )// checks that the horse has not been in that position before
                  {

                  if(vectab[ccab]==0||vectab[ccab]==vectab[cab2])
                  {
                    if(vectab[ccab]==vectab[cab2])
                    {

                                                    ganador=0;
                                                                           }

          cout<<" 7.";
    i=-1;
      cf=cf+2;
      cc=cc+1;
      ccab=conversionmv(cf,cc);

      vectab[ccab]=jugada;
      break;
}

                  }
                  else
                  {
    if(vectab[ccab]==0||vectab[ccab]==vectab[cab1])
                  {

                                      if(vectab[ccab]==vectab[cab1])
                    {

                                                    ganador=0;
                                                                           }

          cout<<" 7.";
    i=-1;
      cf=cf+2;
      cc=cc+1;
      ccab=conversionmv(cf,cc);

      vectab[ccab]=jugada;
      break;
}

                 }
      }
}
   case 8:// 2 to the right, 1 down
           if(vecjugadas[i]==8&&jugada!=0)
         {
      if (cf+1>=0&&cf+1<=7&&cc+2>=0&&cc+2<=7)// checks that the horse does not leave the board
      {
                 ccab=conversionmv(cf+1,cc+2);

                  if ( cab==1 )// checks whose turn it is, i.e. which horse is playing, by calling the movcab function
                  {

                   if(vectab[ccab]==0||vectab[ccab]==vectab[cab2])// checks that the horse has not been in that position before, but allows entering it when the opposing horse is currently in the position it is about to move to
                  {
                      if(vectab[ccab]==vectab[cab2])    // checks whether one horse kills the other and reports it by assigning 0 to the ganador variable
                    {

                                                    ganador=0;
                                                                           }

          cout<<" 8."; // shows whether this case was executed
    i=-1;//
      cf=cf+1;
      cc=cc+2;
      ccab=conversionmv(cf,cc);

      vectab[ccab]=jugada;
      break;
}

                  }
                  else
                  {
    if(vectab[ccab]==0||vectab[ccab]==vectab[cab1])
                  {

                                      if(vectab[ccab]==vectab[cab1])
                    {

                                                    ganador=0;
                                                                           }

          cout<<" 8.";
    i=-1;
      cf=cf+1;
      cc=cc+2;
      ccab=conversionmv(cf,cc);

      vectab[ccab]=jugada;
      break;
}

                 }
      }
}
   default :
                       if(jugada!=0)   // checks that the game has not ended
         {
            cout<<"   "<<vecjugadas[i]<<",";// if the move could not be performed, prints that this case was evaluated
           }
            i++;
            if( i==8&&cab==1)// checks whether all the cases have been evaluated in the order of the moves array and none could be executed, which means the horse was left trapped
            {
                 cout<<"No  hay  movimientos  posibles   \n\n   el   caballo
1"<<simcab1<<" quedo  encerrado";// tells the user which horse was left trapped
                impresion();// prints a final board
                       i=-1;// allows leaving the loop

               jugada=0;// signals that the game is over
                }
                            if( i==8&&cab==2)// checks whether all the cases have been evaluated in the order of the moves array and none could be executed, which means the horse was left trapped
            {
                 cout<<"No  hay  movimientos  posibles   \n\n   el   caballo
2"<<simcab2<<" quedo  encerrado";// tells the user which horse was left trapped
                impresion();// prints a final board
                       i=-1;// allows leaving the loop

               jugada=0;// signals that the game is over
                }
            break;// leaves the switch
 }

}
            return ccab;// returns the position in the board array where the horse that called the function is located

}

int ordenjuego(int  &tirocab1,int  &tirocab2)// depending on which horse rolls the higher number, it arranges who plays first, from then on until the game ends
{

if(tirocab1>tirocab2)// checks which horse rolled the higher number to know who starts
      {
            vectab[cab1] = jugada;// lets horse 1 play first
            jugada++;// increments the move counter
            vectab[cab2] = jugada;// lets horse 2 play
            jugada++;// increments the move counter
            impresion();// prints the board
              cout<<"Juega    primero    el    caballo    1    "<<simcab1<<"
porque:\n\n";// tells the user who plays first
            return 1;// this tells the main function which horse rolled the higher number
      }
      else// this else applies when horse 2 plays first and follows the same logic as the if it is nested in
      {
            vectab[cab2] = jugada;
            jugada++;
            vectab[cab1] = jugada;
            jugada++;
            impresion();
            cout<<"Juega primero el caballo 2 "<<simcab2<<" porque:\n\n";
            return 2;

      }
}

void  impresionorden()// prints some announcements and controls that printing happens under the proper conditions; it also calls the function in charge of performing the horses' moves and printing the board
{

if(orden==1&&jugada!=0)// checks that the game has not ended and indicates who is playing, depending on the order they started with
      {

cout<<"Acaba de mover el caballo 1 "<<simcab1<<" \n\n";
imprevecjug();
            if(jugada!=0)
      {
cout<<"evaluo los casos:";

    cab=1;
    cab1=movcab(cf1,cc1);

      if(ganador==0)// checks whether there was a winner
      {
            cout<<"El  CABALLO 1 "<<simcab1<<" HA GANADO \n\n";
            impresion0();// prints a special board for when only one horse is left on the board
            jugada=0;// signals that the game is over

      }
            if(jugada!=0&&jugada!=2)//
      {
    impresion();
    jugada++;

}}
      getch();// lets the user see everything printed on screen until they press enter
      if(jugada!=0)
      {
system("cls");

      cout<<"Acaba de mover el caballo 2 "<<simcab2<<" \n\n";

      imprevecjug();// calls the function that prints the moves array
      cout<<"evaluo los casos:";
    cab=2;
      cab2=movcab(cf2,cc2);

      if(ganador==0)
      {
            cout<<"El  CABALLO 2 "<<simcab2<<" HA GANADO \n\n";
            impresion0();
            jugada=0;
      }
}
            if(jugada!=0&&jugada!=2)
      {
    impresion();
    jugada++;

}
            getch();
      if(jugada!=0)
      {
system("cls");
      }
    }
      if(orden==2&&jugada!=0)
      {
                            if(jugada!=0)
      {
            cout<<"Acaba de mover el caballo 2 "<<simcab2<<" \n\n";

            imprevecjug();
            cout<<"evaluo los casos:";
            cab=2;
            cab2=movcab(cf2,cc2);

      if(ganador==0)
      {
            cout<<"El  CABALLO 2 "<<simcab2<<" HA GANADO \n\n";
            impresion0();
                 jugada=0;
      }
                 if(jugada!=0&&jugada!=2)
      {
    impresion();
    jugada++;

}}
                 getch();
      if(jugada!=0)
      {
system("cls");

      cout<<"Acaba de mover el caballo 1 "<<simcab1<<" \n\n";

      imprevecjug();
      cout<<"evaluo los casos:";
cab=1;

            cab1=movcab(cf1,cc1);

      if(ganador==0)
      {
            cout<<"El  CABALLO 1 "<<simcab1<<" HA GANADO \n\n";
            impresion0();
                 jugada=0;
      }
}
                 if(jugada!=0&&jugada!=2)
      {
    impresion();
    jugada++;

}
                 getch();
      if(jugada!=0)
      {
system("cls");
      }

      }
}

void impresion()// prints the board
{
      int i,j,k=0;
      cout<<endl<<endl;
      for(i=0;i<=7;i++){
      for(j=0;j<=7;j++)
      {

            if(vectab[k]==0)
            {
                 cout<<sep<<sep<<sep<<sep<<"  ";
            }
            else
        {
            if(vectab[k]!=vectab[cab1]&&vectab[k]!=vectab[cab2])
            {
             if (vectab[k]<=9)
            {
                 cout<<sep<<" "<<vectab[k]<<sep<<"  ";
            }
            else{

            cout<<sep<<vectab[k]<<sep<<"  ";
            }

            }

        if(vectab[k]==vectab[cab1])
         {

            if (vectab[k]<=9)
            {
                 cout<<simcab1<<" "<<vectab[k]<<simcab1<<"  ";
            }
            else{

            cout<<simcab1<<vectab[k]<<simcab1<<"  ";
            }
         }
        if(vectab[k]==vectab[cab2])
         {

            if (vectab[k]<=9)
            {
                 cout<<simcab2<<" "<<vectab[k]<<simcab2<<"  ";
            }
            else{

            cout<<simcab2<<vectab[k]<<simcab2<<"  ";
            }
         }

        }

            k++;
      }
      cout<<endl<<endl;
      }

}


```
