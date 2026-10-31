/*
  AUTHOR: Juan Camilo Rivera

  Name: guerra de caballos
  fecha:09/03/08
  Description: programa de ajedrez con dos caballos que se mueven de forma aleatoria
  License: MIT
*/
//librerias necesarias para el programa
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<time.h>
//variables,vectores y prototipos de funciones usadas en el programa
char simcab1=21,simcab2=156,sep=219,pisadas2;//simbolos usados para imprimir el tablero
int  vectab[64],vecjugadas[8];//vector que almacena la informacion del tablero de juego y el vector que almacena el orden en el que se deben evaluar los posibles movimientos 
int  cab1,cab2,jugada=1,orden,ganador=1;//variables para identificar la posicion del caballo 1, del caballo 2 y la jugada actual
void inicializacion();//inicializa el vector ke kontiene los datos del tablero en cero 
void cabubicacion(char pisadas); // designa aleatoriamente que caballo empieza y en que posicion
void impresion(char &pisadas);//imprime el tablero 
void conversionvm();// convierte los datos de vector en filas y kolumnas de matriz 
int conversionmv(int cf,int cc);//convierte los datos de filas y kolumnas (matriz) en una ubicacion especifica en el vector
void vecjug();// establece el vector de posibles jugadas que se debe usar,el orden en el que se deben analizar las posibles jugadas dependiendo de un numero aleatorio que es tomado como primera opcion
void imprevecjug();//imprime el vector jugadas 
int movcab(int &cf, int &cc,char &pisadas);//Es la funcion en la que se evaluan las opciones de movimiento del caballo dependiendo del vector de jugadas, evalua si es valido el movimiento, si es valido lo realiza, o de lo contrario no.
int ordenjuego(int &tirocab1,int &tirocab2,char &pisadas);//dependiendo de que caballo saque el numero mayor organiza quien juega primero de ahi hasta que termine el juego
void impresionorden(char pisadas);//imprime algunos anuncios y controla que las impresiones se realicen con las condiciones adecuadas, ademas llama a la funcion encargada de realizar los movimientos de los cabllos y de imprimir el tablero 
int cf1,cc1,cf2,cc2,cab;//variables usadas para la ubicacion en terminos de matriz y para determinar que caballo esta haciendo su movimiento
void impresion0(char &pisadas);//en caso de que un caballo se coma al otro imprime evitando la impresion de los dos caballos en la misma posicion
struct movimiento {
	 char nombre[250];
		
};
	struct movimiento nom;

void  main()//funcion principal 

{

	

	system("color 1f");//cambia el color de fondo de la consola y la fuente para hacer un entorno mas agradable 
			
	cout<<endl<<"  digite su nombre  "<<endl;
	cin>>nom.nombre;
	
	pisadas2=nom.nombre[0];
    const char pisadas=pisadas2 ;   
    inicializacion();//inicializa el vector en 0
	cabubicacion(pisadas);// // designa aleatoriamente que caballo empieza y en que posicion
	cout<<endl;
	getch();//permite visualizar el tablero y la informacion impresa en pantalla 
	system("cls");//borra lo que este en pantalla 
	while (jugada!=0)//ciclo que evalua cuando termina el juego
	{
		if(jugada!=0)
		{
	vecjug();//actualiza el vector jugada en cada movimiento
	impresionorden(pisadas);//imprime algunos anuncios y controla que las impresiones se realicen con las condiciones adecuadas, ademas llama a la funcion encargada de realizar los movimientos de los cabllos y de imprimir el tablero
		}

}

	
}

void inicializacion()//inicializa el vector ke kontiene los datos del tablero en cero 
{
	int i;
	
for (i=0;i<=64;i++)
	{
		vectab[i]=0;
		
	}

}

void cabubicacion(char pisadas)//funcion que indica de forma aleatoria que caballo empieza y en que posicion 
{
	int i=1,tirocab1,tirocab2;

	while  (i==1)
	{

	srand(time(NULL));// cambia la semilla
	
	tirocab1= rand() % 51;//realiza un tiro aleatorio para el caballo 2
	tirocab2= rand() % 51;//realiza un tiro aleatorio para el caballo 2

	cab1= rand() % 64;//ubica de forma aletoria el caballo 1
	cab2= rand() % 64;//ubica de forma aletoria el caballo 2
	if(cab1 != cab2 && tirocab1 != tirocab2)//evalua ke los caballos no saquen l mismo numero para poder definir quien empieza y que no empiecen en la misma posicion
	{
		i++;//permite salir del ciclo
	}
	}
	
	orden=ordenjuego(tirocab1,tirocab2,pisadas);//usa la funcion orden juego para saber quien empieza  y le envia como informacion el tiro de cada caballo
	
	
	conversionvm();//convierte elvalor en terminos de vector de la ubicacion de cada caballo a terminos de matriz (filas y columnas)
	cout<<"El tiro del caballo de "<<nom.nombre<<" "<<simcab1<<" fue:\n\n"<<tirocab1<<endl<<endl;//muestra en pantalla los tiros de los caballo para definir quien empieza y el numero aleatorio que permite ubicar en la primera jugada a los caballos
	cout<<"El tiro del caballo de la maquina "<<simcab2<<" fue:\n\n"<<tirocab2<<endl<<endl;
	cout<<"El numero aleatorio para ubicar el caballo de "<<nom.nombre<<" "<<simcab1<<" fue:  "<<cab1<<endl<<endl;
	cout<<"En terminos de filas y columnas es: fila:"<<cf1+1<<" columna:"<<cc1+1<<endl<<endl;
	cout<<"El numero aleatorio para ubicar el caballo de la maquina "<<simcab2<<" fue:  "<<cab2<<endl<<endl;
	cout<<"En terminos de filas y columnas es: fila:"<<cf2+1<<" columna:"<<cc2+1<<endl<<endl;


	
}

void conversionvm()//// convierte los datos de vector en filas y kolumnas de matriz 
{
	cf1=cab1/8;
	cc1=cab1%8;
	cf2=cab2/8;
	cc2=cab2%8;


}

void impresion0(char &pisadas)//en caso de que un caballo se coma al otro imprime evitando la impresion de los dos caballos en la misma posicion
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
            if (orden==2)
            {
                        if(vectab[k]%2==0)
                        {
             if (vectab[k]<=9)
		{
			cout<<pisadas<<" "<<vectab[k]<<pisadas<<"  ";
		}
		else{
		
		cout<<pisadas<<vectab[k]<<pisadas<<"  ";
		} 
                        } 
                        else
                        {
                                         if (vectab[k]<=9)
		                                 {
			cout<<sep<<" "<<vectab[k]<<sep<<"  ";
		                                   }
		else{
		
		cout<<sep<<vectab[k]<<sep<<"  ";
		     }
                        }  
           }
            else
            {
                if(vectab[k]%2==0)
                {
                 if (vectab[k]<=9)
                 {
			cout<<sep<<" "<<vectab[k]<<sep<<"  ";
                 }
		else{
		
		cout<<sep<<vectab[k]<<sep<<"  ";
		     }                 
                                  }
                                  else
                                  {
       if (vectab[k]<=9)
       {
			cout<<pisadas<<" "<<vectab[k]<<pisadas<<"  ";
       }
		else{
		
		cout<<pisadas<<vectab[k]<<pisadas<<"  ";
		} 
                                       }
                }                                                                 
            }                  
             if(vectab[k]==vectab[cab1]&&cab==1)
         {      
                     
		if (vectab[k]<=9)
		{
			cout<<simcab1<<" "<<vectab[k]<<simcab1<<"  ";
		}
		else{
		
		cout<<simcab1<<vectab[k]<<simcab1<<"  ";
		}
         }
        if(vectab[k]==vectab[cab2]&&cab==2)
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

void vecjug()//establece el vector de posibles jugadas que se debe usar en cada turno
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

void imprevecjug()//imprime el vector jugadas
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

int movcab(int &cf,int &cc,char &pisadas)//Es la funcion en la que se evaluan las opciones de movimiento del caballo dependiendo del vector de jugadas, evalua si es valido el movimiento, si es valido lo realiza, o de lo contrario no.
{
	int ccab,i=0;
	while(i!=-1)
	{
                switch(vecjugadas[i])//evalua las posibles jugadas que debe realizar dependiendo del vector jugda
               {
            case 1://2 a la derecha 1 arriba

         if(vecjugadas[i]==1&&jugada!=0)          
         {
	if (cf-1>=0&&cf-1<=7&&cc+2>=0&&cc+2<=7)//verifica que el caballo no salga del tablero
	{
			ccab=conversionmv(cf-1,cc+2);

			 if ( cab==1 )//verifica que caballo es el que esta realizando el movimiento
			 {
                  
                  if(vectab[ccab]==0||vectab[ccab]==vectab[cab2])//verifica que el caballo no haya estado en esa posicion antes 
                  {
                    if(vectab[ccab]==vectab[cab2])//evalua si hay un ganador 
                    {
                                                   
                                                    ganador=0;
                                                    }                          
                                                
                  
				                   
    cout<<" 1.";
    i=-1;//permite salir del ciclo

	cf=cf-1;//realiza el movimeinto 
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
                  
				                   
    cout<<" 1.";
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
	case 2://2 hacia arriba 1 a la derecha

            if(vecjugadas[i]==2&&jugada!=0)  
         {
	if (cf-2>=0&&cf-2<=7&&cc+1>=0&&cc+1<=7)//verifica que el caballo no salga del tablero
	{
			ccab=conversionmv(cf-2,cc+1);

			 if ( cab==1 )//verifica que el caballo no haya estado en esa posicion antes 
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
	case 3://2 hacia arriba 1 hacia la izquierda 
               if(vecjugadas[i]==3&&jugada!=0)  
         {  
	if (cf-2 >= 0 && cf-2 <= 7 && cc-1 >= 0 && cc-1 <= 7 )//verifica que el caballo no salga del tablero
	{
			ccab=conversionmv(cf-2,cc-1);

			 if ( cab==1 )//verifica que el caballo no haya estado en esa posicion antes 
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
	case 4://2 a la izquierda 1 hacia arriba
         if(vecjugadas[i]==4&&jugada!=0)  
         {
	if (cf-1>=0&&cf-1<=7&&cc-2>=0&&cc-2<=7)//verifica que el caballo no salga del tablero
	{
			ccab=conversionmv(cf-1,cc-2);

			 if ( cab==1 )//verifica que el caballo no haya estado en esa posicion antes 
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
	case 5://2 a la izquierda 1 hacia abajo
         if(vecjugadas[i]==5&&jugada!=0)  
         {
	if (cf+1>=0&&cf+1<=7&&cc-2>=0&&cc-2<=7)//verifica que el caballo no salga del tablero
	{
			ccab=conversionmv(cf+1,cc-2);

			 if ( cab==1 )//verifica que el caballo no haya estado en esa posicion antes 
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
    case 6://2 hacia abajo 1 a la izquierda
          if(vecjugadas[i]==6&&jugada!=0)  
         {
	if (cf+2>=0&&cf+2<=7&&cc-1>=0&&cc-1<=7)//verifica que el caballo no salga del tablero
	{
			ccab=conversionmv(cf+2,cc-1);

			 if ( cab==1 )
             //verifica que el caballo no haya estado en esa posicion antes 
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
    case 7://2hacia abajo 1 a la derecha
         if(vecjugadas[i]==7&&jugada!=0)  
         {
	if (cf+2>=0&&cf+2<=7&&cc+1>=0&&cc+1<=7)//verifica que el caballo no salga del tablero
	{
			ccab=conversionmv(cf+2,cc+1);

			 if ( cab==1 )//verifica que el caballo no haya estado en esa posicion antes 
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
   case 8://2 a la derecha 1 hacia abajo
           if(vecjugadas[i]==8&&jugada!=0)  
         {
	if (cf+1>=0&&cf+1<=7&&cc+2>=0&&cc+2<=7)//verifica que el caballo no salga del tablero
	{
			ccab=conversionmv(cf+1,cc+2);

			 if ( cab==1 )//verifica que el caballo no haya estado en esa posicion antes 
			 {
                  
                  if(vectab[ccab]==0||vectab[ccab]==vectab[cab2])
                  {
                    if(vectab[ccab]==vectab[cab2])  
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
                      if(jugada!=0)  
         {
           cout<<" "<<vecjugadas[i]<<",";
           }
            i++;
            if( i==8&&cab==1)
            {
                cout<<"No hay movimientos posibles \n\n el caballo de "<<nom.nombre<<" "<<simcab1<<" quedo encerrado";
                impresion(pisadas);
				i=-1;
				
               jugada=0;
                }
                            if( i==8&&cab==2)
            {
                cout<<"No hay movimientos posibles \n\n el caballo de la maquina "<<simcab2<<" quedo encerrado";
                impresion(pisadas);
				i=-1;
				
               jugada=0;
                }
            break;
 }

}
		return ccab;
    
}

int ordenjuego(int &tirocab1,int &tirocab2,char &pisadas)
{
	

if(tirocab1>tirocab2)
	{
		vectab[cab1] = jugada;
		jugada++;
		vectab[cab2] = jugada;
		jugada++;
		impresion(pisadas);
		cout<<"Juega primero el caballo de "<<nom.nombre<<" "<<simcab1<<" porque:\n\n";
		return 1;
	}
	else
	{
		vectab[cab2] = jugada;
		jugada++;
		vectab[cab1] = jugada;
		jugada++;
		impresion(pisadas);
		cout<<"Juega primero el caballo de la maquina "<<simcab2<<" porque:\n\n";
		return 2;

	}
}

void impresionorden(char pisadas)
{

if(orden==1&&jugada!=0)
	{

cout<<"Acaba de mover el caballo de "<<nom.nombre<<" "<<simcab1<<" \n\n";
imprevecjug();
		if(jugada!=0)
	{
cout<<"evaluo los casos:";

    cab=1;
    cab1=movcab(cf1,cc1,pisadas);
	
	if(ganador==0)
	{
		cout<<"El  CABALLO  DE "<<nom.nombre<<" "<<simcab1<<" HA GANADO \n\n";
		impresion0(pisadas);
		jugada=0;
		
	}
		if(jugada!=0&&jugada!=2)
	{
    impresion(pisadas);
    jugada++;
	
}}
	getch();
	if(jugada!=0)
	{
system("cls");
	
	cout<<"Acaba de mover el caballo de la maquina "<<simcab2<<" \n\n";
    vecjug();
	imprevecjug();
	cout<<"evaluo los casos:";
    cab=2;
	cab2=movcab(cf2,cc2,pisadas);

	if(ganador==0)
	{
		cout<<"El  CABALLO DE LA MAQUINA "<<simcab2<<" HA GANADO \n\n";
		impresion0(pisadas);
		jugada=0;
	}
}
		if(jugada!=0&&jugada!=2)
	{
    impresion(pisadas);
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
		cout<<"Acaba de mover el caballo de la maquina "<<simcab2<<" \n\n";

		imprevecjug();
		cout<<"evaluo los casos:";
		cab=2;
		cab2=movcab(cf2,cc2,pisadas);
		
	if(ganador==0)
	{
		cout<<"El  CABALLO DE LA MAQUINA "<<simcab2<<" HA GANADO \n\n";
		impresion0(pisadas);
			jugada=0;
	}
			if(jugada!=0&&jugada!=2)
	{
    impresion(pisadas);
    jugada++;
	
}}
			getch();
	if(jugada!=0)
	{
system("cls");
	
	cout<<"Acaba de mover el caballo de "<<nom.nombre<<" "<<simcab1<<" \n\n";
    vecjug();
    
	imprevecjug();
	cout<<"evaluo los casos:";
cab=1;

		cab1=movcab(cf1,cc1,pisadas);
		
	if(ganador==0)
	{
		cout<<"El  CABALLO DE "<<nom.nombre<<" "<<simcab1<<" HA GANADO \n\n";
		impresion0(pisadas);
			jugada=0;
	}
}
			if(jugada!=0&&jugada!=2)
	{
    impresion(pisadas);
    jugada++;
	
}
			getch();
	if(jugada!=0)
	{
system("cls");
	}

	} 
}

void impresion(char &pisadas)
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
            if (orden==2)
            {
                        if(vectab[k]%2==0)
                        {
             if (vectab[k]<=9)
		{
			cout<<pisadas<<" "<<vectab[k]<<pisadas<<"  ";
		}
		else{
		
		cout<<pisadas<<vectab[k]<<pisadas<<"  ";
		} 
                        } 
                        else
                        {
                                         if (vectab[k]<=9)
		                                 {
			cout<<sep<<" "<<vectab[k]<<sep<<"  ";
		                                   }
		else{
		
		cout<<sep<<vectab[k]<<sep<<"  ";
		     }
                        }  
           }
            else
            {
                if(vectab[k]%2==0)
                {
                 if (vectab[k]<=9)
                 {
			cout<<sep<<" "<<vectab[k]<<sep<<"  ";
                 }
		else{
		
		cout<<sep<<vectab[k]<<sep<<"  ";
		     }                 
                                  }
                                  else
                                  {
       if (vectab[k]<=9)
       {
			cout<<pisadas<<" "<<vectab[k]<<pisadas<<"  ";
       }
		else{
		
		cout<<pisadas<<vectab[k]<<pisadas<<"  ";
		} 
                                       }
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
cout<<pisadas<<"aqui";
}
