#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


void gotoxy(int x, int y);
int min, sus, dif, i=0, j=0, n=0, comp, resul, sum, signo=0, vecTor[20],vecUno[20], vecm[20], vecs[20], vecc[20], vecr[20], r, t;
char resp;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* 
	Calcular Complementos v2

	Presentado por: 
		Edwin González, 
		Rolando Peña, 
		Christian Pinzón 
		
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* 
	Cambios con respecto a versión original sustentada:
		- Se cambiaron los "vectores dinámicos" hechos con punteros por vectores estáticos para mayor comodidad.
		- Se eliminaron algunas variables sin usar.
		- Se crearon algunos métodos y funciones adicionales para completar los requerimientos solicitados.
		
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Metodo para posicionarse en pantalla
void gotoxy(int x,int y){ 
 HANDLE hcon; 
 hcon = GetStdHandle(STD_OUTPUT_HANDLE); 
 COORD dwPos; 
 dwPos.X = x;
 dwPos.Y= y; 
 SetConsoleCursorPosition(hcon,dwPos); 
}

// Metodo para calcular el complemento a 10
void a10(){
	// Captura de Datos
	printf("Teclee la resta: ");
	gotoxy(2, 4); printf("- ");
	// Captura de Minuendo
	gotoxy(4, 2); scanf("%d", &min);
	// Captura de Sustraendo
	gotoxy(4, 4); scanf("%d", &sus);
	gotoxy(2, 5); printf("--------");
	
	// Base del complemento es 10
	comp=10;
	// Se inicia con una sola unidad de orden superior
	i=1;
	
	// Se aumenta en las unidades de orden superior necesarios para complementar el minuendo
	do{
		comp=pow(comp, i); // Se calcula la potencia de base 10 que es complemento del minuendo introducido
		i++;
	}while(min>comp);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Se encuentra la diferencia entre el sustraendo y la base 10 
	sum=comp-sus;
	
	gotoxy(14, 4); printf("- ");
	// Impresión de Minuendo
	gotoxy(16, 2); printf("%d", comp);
	// Impresión de Sustraendo
	gotoxy(16, 4); printf("%d", sus);
	gotoxy(12, 5); printf("--------");
	gotoxy(16, 6); printf("%d", sum);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Sumar el minuendo con el complemento obtenido
	resul=sum+min;
	 gotoxy(24, 4); printf("+ ");
	// Impresión de Minuendo
	gotoxy(28, 2); printf("%d", min);
	// Impresión de Sustraendo
	gotoxy(28, 4); printf("%d", sum);
	gotoxy(22, 5); printf("--------");
	gotoxy(28, 6); printf("%d", resul);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Si el resultado tiene una unidad de orden superior, entonces
	if(resul>comp){
	// Se elimina la unidad de orden superior
		resul=resul-comp;
		gotoxy(34, 6); printf("--> %d", resul);
	}
	signo=0; // Valor ascii sin signo
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Si sustraendo es mayor al minuendo, entonces
	if(sus>min){
		
		gotoxy(46, 4); printf("-");
		gotoxy(50, 4); printf("%d", resul);
		
		resul=comp-resul;
		signo=45; // Valor ascii del signo negativo
		
		gotoxy(50, 2); printf("%d", comp);
		gotoxy(44, 5); printf("--------");
		gotoxy(50, 6); printf("%d", resul);
	}
	
	gotoxy(2, 6); printf("%c %d", signo, resul);
	gotoxy(60, 6); printf("--> %c %d", signo, resul);
	
	// Se escribe el resultado en pantalla
	gotoxy(20, 20); printf("Base a complementar: %d Complemento de sustraendo: %d", comp, sum);
	
}

// Metodo para calcular el complemento a 9
void a9(){
	// Captura de Datos
	printf("Teclee la resta: ");
	gotoxy(2, 4); printf("- ");
	gotoxy(4, 2); scanf("%d", &min);
	gotoxy(4, 4); scanf("%d", &sus);
	gotoxy(2, 5); printf("--------");
	
	//
	i=1;
	signo=0; // Se inicia sin signo
	
	// Encontrar la base a complementar
	do{
    	comp=(pow(10, i))-1; // Se encuentra la base 10, que menos 1 resultara en una base con valores 9
		i++;
	}while(min>comp);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Calcular el complemento
	sum=comp-sus;
	
	gotoxy(14, 4); printf("- ");
	// Impresión de Minuendo
	gotoxy(16, 2); printf("%d", comp);
	// Impresión de Sustraendo
	gotoxy(16, 4); printf("%d", sus);
	gotoxy(12, 5); printf("--------");
	gotoxy(16, 6); printf("%d", sum);
	
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Sumar  el complemento obtenido al minuendo
	resul=sum+min;
	
	gotoxy(24, 4); printf("+ ");
	// Impresión de Minuendo
	gotoxy(28, 2); printf("%d", min);
	// Impresión de Sustraendo
	gotoxy(28, 4); printf("%d", sum);
	gotoxy(22, 5); printf("--------");
	gotoxy(28, 6); printf("%d", resul);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Si hay una unidad de orden superior se descarta del extremo izquierdo y se suma a las unidades del mismo resultado
	if(resul>(comp+1)){
		resul=(resul+1)-(comp+1);
		gotoxy(34, 6); printf("--> %d", resul);
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	if(sus>min){
		
		gotoxy(46, 4); printf("-");
		gotoxy(50, 4); printf("%d", resul);
		
		resul=comp-resul;
		signo=45;
		
		gotoxy(50, 2); printf("%d", comp);
		gotoxy(44, 5); printf("--------");
		gotoxy(50, 6); printf("%d", resul);
		
	}
	
	// Se escribe el resultado en pantalla
	gotoxy(20, 20); printf("Base a complementar: %d Complemento de sustraendo: %d", comp, sum);
	gotoxy(2, 6); printf("%c %d", signo, resul);
}

// Metodo para inicializar los vectores que almace
void vaciarVectores(){
	int x;
	for(x=0;x<20;x++)
	{
		vecm[x] = 0; 
		vecs[x] = 0; 
		vecc[x] = 0; 
		vecr[x] = 0;
		vecUno[x] = 0;
	}
	vecUno[0] = 1;
}

// Transformar numero a binario
int bin(int n, int *vec){
	
	int tamano = 0;
	if(n<0)
	{
		printf("Nota: tomare el valor como positivo.");
		n = n*-1;
	}
	
	// Obtener cada uno de los digitos del numero como binario 
	do{
		// Obtener un digito (calculando el residuo) y almacenarlo en el espacio de memoria vecm
		*vec=n%2;
		// Dividir el numero original a la mitad 
		n=n/2;
		// Moverse al siguiente espacio del "vector"
		tamano++;
		vec++;
	}while(n>=1);
	
	return tamano;
}

// Metodo para transformar un binario a decimal
int decimal(int vec[], int tamano){
	int x, decimal;
	for(x=0;x<=tamano;x++){	
		if(vec[x]==1)
		{
			decimal=decimal+pow(2,x);
		}
	}
	return decimal;
}

// Metodo para sumar dos numeros binarios (puntero al vector del primer binario, el numero de digitos del primer binario, ... , ... , vector que recibe el resultado) 
int sumaBin(int *bin1 , int tBin1, int *bin2, int tBin2, int *resultado){
	
	int lleva=0;
	int masGrande, tamanoResultado=0;
	int x;
	if( tBin1<=tBin2)
	{
		masGrande= tBin2;
	}else
	{
		masGrande = tBin1;
	}
	
	for(x=0; x<masGrande+1; bin1++,bin2++,resultado++, x++)
	{
		switch(*bin1 + *bin2 + lleva)
		{
			case 0:
				*resultado = 0;
				lleva = 0;
				break;
			case 1:
				*resultado = 1;
				lleva = 0;
				break;
			case 2:
				*resultado = 0;
				lleva = 1;
				break;
			case 3:
				*resultado = 1;
				lleva = 1;
				break;
				
			default:
				printf("Algo anda mal :c");
				break;	
		}
		tamanoResultado++;

	}
		
	return tamanoResultado;
}

// Metodo para calcular el complemento a 1
void a1(){
	 
	int sizeMin, sizeSus, sizeComp, sizeR, sizeComprobacion, size;
	
	// Captura de Datos
	printf("Teclee la resta: ");
	gotoxy(2, 4); printf("- ");
	gotoxy(4, 2); scanf("%d", &min);
	gotoxy(4, 4); scanf("%d", &sus);
	gotoxy(2, 5); printf("--------");
	dif=min-sus;
	gotoxy(2, 6); printf("%d \n",dif );

	vaciarVectores();
	
	// Se transforman los operandos en binario
	sizeMin = bin(min, &vecm[0]);

	sizeSus = bin(sus, &vecs[0]);
	
	if(sizeMin>=sizeSus)
	{
		size = sizeMin;
	}
	else
	{
		size = sizeSus;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Obtener complemento a 1
	// Se itera sobre cada digito del decimal, escribiendo en un nuevo "vector" el digito contrario (1 si es 0 o 0 si es 1)
	t=0;

	for(r=0;r<size;r++)
	{
		if(vecs[r]==0){
			vecc[t]=1;
		}
		else{
			vecc[t]=0;
		}
		t++;
	}
	
	gotoxy(16, 2); printf("A1");
	gotoxy(10, 4); printf("---->");

	for(r=size-1;r>=0;r--)
	{
		printf("%d", vecc[r]);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Se suma el minuendo  con el complemento del sustraendo
	
	sizeR = sumaBin(&vecm[0],sizeMin,&vecc[0],sizeSus, &vecr[0]);
	
	// Se imprime la operación
	
	gotoxy(22+size, 4); printf("---->");
	gotoxy(28+size, 2);
	
	for(r=size-1;r>=0;r--)
	{
		printf("%d", vecm[r]);
	}
	
	gotoxy(27+size, 3);printf("+");
	
	
	for(r=size-1;r>=0;r--)
	{
		
		gotoxy(31+(-r)+size, 4); printf("%d", vecc[r]);
		gotoxy(27+r+size, 5); printf("----");
	}
	
	gotoxy(28+size, 6); 
	
	int x;
	for(x=sizeR-1;x>=0;x--)
	{
		printf("%d", vecr[x]);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Salida de datos relevantes para el usuario
	
	gotoxy(20, 18); printf("\nEl minuendo %d en binario es: ", min);
	for(r=size-1;r>=0;r--){
		printf("%d", vecm[r]);
	}
	
	gotoxy(20, 20); printf("\nEl sustraendo %d en binario es: ", sus);
	for(r=size-1;r>=0;r--){
		printf("%d", vecs[r]);
	}
	
	gotoxy(20, 22);	printf("\nEl complemento del sustraendo a 1 es: ");
	for(r=size-1;r>=0;r--)
	{
		printf("%d", vecc[r]);
	}

	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	if(min>=sus)
	{
		// Si el minuendo es mayor al sustraendo
		
		int y;
		for(y=1;y<8;y++)
		{
			gotoxy(55,y);printf("%c",186);
			
		}
		
		// Se elimina la unidad de orden superior y se suma 1 al numero obtenido
		
		sizeComprobacion= sumaBin(&vecr[0],sizeR,&vecUno[0],1, &vecTor[0]);
		
		// Se imprime la operación
		
		gotoxy(60, 2);	
		for(r=sizeR-2;r>=0;r--){
			printf("%d", vecr[r]);
		}
		
		gotoxy(60, 3);printf("+");
		gotoxy(60, 4);
		
		for(r=sizeR-2;r>=0;r--){
			
			 printf("%d", vecUno[r]);
		}
		gotoxy(59, 5); printf("----");
		gotoxy(60, 6); 
		
		for(x=sizeComprobacion-3;x>=0;x--)
		{
			printf("%d", vecTor[x]);
		}
	}
	else
	{	
		// Si el minuendo es menor al sustraendo
		
		if(dif<0)
		{
			dif=dif*(-1);
		}
		
		// Se verifica si es necesario recomplementar y en caso tal, se recomplementa
		
		if(decimal(vecr,sizeR)==dif)
		{
			t=0;
				for(r=0;r<sizeR;r++)
				{
					if(vecr[r]==0)
					{
						vecr[t]=1;
					
					}
					else
					{
						vecc[t]=0;
					}
					
				t++;
				}
		}
		
		// Se muestra el resultado final
		
		int y;
		for(y=1;y<8;y++)
		{
			gotoxy(55,y);printf("%c",186);
			
		}
		
		gotoxy(60, 6); printf("-");
		for(r=size-1;r>=0;r--)
		{
			printf("%d", vecc[r]);
		}
	
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


}

// Metodo para calcular el complemento a 2
void a2(){
	
	 
	int sizeMin, sizeSus, sizeComp, sizeR, sizeComprobacion, size;
	
	// Captura de Datos
	printf("Teclee la resta: ");
	gotoxy(2, 4); printf("- ");
	gotoxy(4, 2); scanf("%d", &min);
	gotoxy(4, 4); scanf("%d", &sus);
	gotoxy(2, 5); printf("--------");
	dif=min-sus;
	gotoxy(2, 6); printf("%d \n",dif );

	vaciarVectores();
		
	// Se transforman los operandos en binario
	sizeMin = bin(min, &vecm[0]);

	sizeSus = bin(sus, &vecs[0]);
	
	if(sizeMin>=sizeSus)
	{
		size = sizeMin;
	}
	else
	{
		size = sizeSus;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Obtener complemento a 1
	// Se itera sobre cada digito del decimal, escribiendo en un nuevo "vector" el digito contrario (1 si es 0 o 0 si es 1)
	t=0;

	for(r=0;r<size;r++)
	{
		if(vecs[r]==0){
			vecc[t]=1;
		}
		else{
			vecc[t]=0;
		}
		t++;
	}
	
	gotoxy(16, 1); printf("A1");
	gotoxy(10, 4); printf("---->");

	for(r=size-1;r>=0;r--)
	{
		printf("%d", vecc[r]);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Sumar 1 al complemento A1 (Calcular complemento A2)
	
	for(r=size-1;r>=0;r--)
	{
		gotoxy(34+(-r)+size, 2);printf("%d", vecc[r]);
	}
	
	
	sizeComp = sumaBin(&vecc[0],size,&vecUno[0],1, &vecc[0]);
	
	// Mostrar la  operación
	
	gotoxy(36, 1); printf("A2");
	
	
	for(r=size-1;r>=0;r--)
	{
			
		gotoxy(34+(-r)+size, 4); printf("%d", vecUno[r]);
		gotoxy(32+(-r)+size, 5); printf("----");
	}
	gotoxy(29+size, 3);printf("+");
	gotoxy(18+size, 4); printf("---->");
	
	for(r=size-1;r>=0;r--)
	{
		gotoxy(34+(-r)+size, 6);printf("%d", vecc[r]);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Se suma el minuendo  con el complemento obtenido
	
	sizeR = sumaBin(&vecm[0],sizeMin,&vecc[0],sizeSus, &vecr[0]);
	
	// Se imprime la operación
	
	gotoxy(45+size, 4); printf("---->");
	
	
	for(r=size-1;r>=0;r--)
	{
		gotoxy(60+(-r)+size, 2); printf("%d", vecm[r]);
	}
	
	gotoxy(54+size, 3);printf("+");
	
	
	for(r=size-1;r>=0;r--)
	{
		
		gotoxy(60+(-r)+size, 4); printf("%d", vecc[r]);
		gotoxy(54+r+size, 5); printf("----");
	}
	
	gotoxy(56+size, 6); 
	
	int x;
	for(x=sizeR-1;x>=0;x--)
	{
		printf("%d", vecr[x]);
	}
	


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// Salida de datos relevantes para el usuario
	
	gotoxy(20, 18); printf("\nEl minuendo %d en binario es: ", min);
	for(r=size-1;r>=0;r--){
		printf("%d", vecm[r]);
	}
	
	gotoxy(20, 20); printf("\nEl sustraendo %d en binario es: ", sus);
	for(r=size-1;r>=0;r--){
		printf("%d", vecs[r]);
	}
	
	gotoxy(20, 22);	printf("\nEl complemento del sustraendo a 2 es: ");
	for(r=size-1;r>=0;r--)
	{
		printf("%d", vecc[r]);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	if(min>=sus)
	{
		// Si el minuendo es mayor al sustraendo
		
		int y;
		for(y=1;y<8;y++)
		{
			gotoxy(85,y);printf("%c",186);
			
		}
		
		// Se elimina la unidad de orden superior y se sustituye por un signo positivo
		// Se imprime la operación
		
		gotoxy(87, 6);printf("+");	
		for(r=sizeR-2;r>=0;r--)
		{
			printf("%d", vecr[r]);
		}

	}
	else
	{	
		// Si el minuendo es menor al sustraendo
		
		if(dif<0)
		{
			dif=dif*(-1);
		}
		
		// Se recomplementa el resultado obtenido
			t=0;
				for(r=0;r<sizeR;r++)
				{
					if(vecr[r]==0)
					{
						vecc[t]=1;
					}
					else
					{
						vecc[t]=0;
					}	
				t++;
				}

		// Se muestra el resultado final		
		int y;
		for(y=1;y<8;y++)
		{
			gotoxy(70,y);printf("%c",186);
			
		}
		
		for(r=size-1;r>=0;r--)
		{
			gotoxy(87+(-r)+size, 2);printf("%d", vecc[r]);
		}
		
	
		sizeComp = sumaBin(&vecc[0],size,&vecUno[0],1, &vecc[0]);
		
		gotoxy(89, 1); printf("A2");
		
		
		for(r=size-1;r>=0;r--)
		{
				
			gotoxy(87+(-r)+size, 4); printf("%d", vecUno[r]);
			gotoxy(85+(-r)+size, 5); printf("----");
		}
		
		gotoxy(81+size, 3);printf("+");
		gotoxy(81+size, 6); printf("-");
		
		for(r=size-1;r>=0;r--)
		{
			gotoxy(87+(-r)+size, 6);printf("%d", vecc[r]);
		}

	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

// Metodo principal
int main(){

	system("cls");
	system("color f4");
	printf("*****MENU*****");
	printf("\nSeleccione una opcion:\n1. Complemento A10 \n2. Complemento A9\n3. Complemento A2\n4. Complemento A1\n5. Salir\n\n\nOpci%cn: ",162);
	scanf("%d", &min);
	
	system("cls");
	switch(min){
		case 1:
			a10();
			break;
		case 2:
			a9();
			break;
		case 3:
			a2();
			break;
		case 4:
			a1();
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("Valor erroneo, intentelo de nuevo.");
			Sleep(2000);
			main();
			break;
	}
	printf("\n\nDesea volver al menu principal? S/N");
	resp = getch();
	if(resp=='s'||resp=='S'){
		system("cls");
		main();
	}
	else{
		exit(0);
	}
	
	system("PAUSE");
	return 0;
}
