#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void gotoxy(int x, int y);
int min, sus, i=0, j=0, n=0, comp, resul, sum, signo=0, *vecm, *vecs, minp, susp, n, m, *resulc, *vecsp, recom, *vecn, res, division, r, num, t;
char resp;

/* 

Calcular Complementos

Presentado por: 
	Edwin González, 
	Rolando Peña, 
	Christian Pinzón 

*/


// Metodo para posicionarse en pantalla
void gotoxy(int x,int y)
{ 
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
	
	// Se encuentra la diferencia entre el sustraendo y la base 10 
	sum=comp-sus;
	// Sumar el minuendo con el complemento obtenido
	resul=sum+min;
	
	// Si el resultado es mayor al resultado natural de la operacion, entonces
	if(resul>comp){
	// Se elimina la unidad de orden superior
		resul=resul-comp;
	}
	signo=0; // Valor ascii sin signo
	
	// Si sustraendo es mayor al minuendo, entonces
	if(sus>min){
		// Se recomplementa (de ser necesario)
		resul=comp-resul;
		signo=45; // Valor ascii del signo negativo
	}
	
	// Se escribe el resultado en pantalla
	gotoxy(20, 3); printf("Base a complementar: %d Complemento de sustraendo: %d", comp, sum);
	gotoxy(2, 6); printf("%c %d", signo, resul);
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
	
	// Calcular el complemento
	sum=comp-sus;
	
	// Sumar  el complemento obtenido al minuendo
	resul=sum+min;
	
	// Si hay una unidad de orden superior se descarta del extremo izquierdo y se suma a las unidades del mismo resultado
	if(resul>(comp+1)){
		resul=(resul+1)-(comp+1);
	}
	
	if(sus>min){
		resul=comp-resul;
		signo=45;
	}
	
	// Se escribe el resultado en pantalla
	gotoxy(20, 3); printf("Base a complementar: %d Complemento de sustraendo: %d", comp, sum);
	gotoxy(2, 6); printf("%c %d", signo, resul);
}

// Transformar numero a binario
void bin(n){
	
	if(n<0)
	{
		printf("Nota: tomare el valor como positivo.");
		n = n*-1;
	}
	
	// Obtener cada uno de los digitos del numero como binario 
	do{
		// Obtener un digito (calculando el residuo) y almacenarlo en el espacio de memoria vecm
		vecm[m]=n%2;
		// Dividir el numero original a la mitad 
		n=n/2;
		// Moverse al siguiente espacio del "vector"
		m++;
		// Se incrementa el tamaño del "vector"
		vecm=(int*) realloc(vecm, (m+1)*sizeof(int));
	}while(n>=2);
	
	// "Redondear" en caso de recibir un decimal
	vecm[m]=floor(n);
	
	// "rellenar" espacios en blanco con 0 hasta obtener un byte 
	if(m<7){
		do{
			m++;
			vecm=(int*) realloc(vecm, (m+1)*sizeof(int));
			vecm[m] = 0;
		}while(m<7);
	}
		
}

// Metodo para calcular el complemento a 1
void a1(){
	// Captura de datos (el numero entero al cual buscar su complemento a 1 como binario)
	printf("Teclee el numero a complementar: ");
	scanf("%d", &num);
	m=0;
	
	// Obtener direccion de memoria donde esta el numero a complementar 
	vecm=(int*) calloc(1, sizeof(int));
	// Transformar el numero introducido en binario
	bin(num);
	// Obtener direccion de memora donde estara el complemento del numero a complementar
	vecs = (int*) calloc((m+1), sizeof(int));
	t=0;
	
	// Se itera sobre cada digito del decimal, escribiendo en un nuevo "vector" el digito contrario (1 si es 0 o 0 si es 1)
	for(r=m;r>=0;r--){
		if(vecm[r]==0){
			vecs[t]=1;
		}
		else{
			vecs[t]=0;
		}
		t++;
	}
	
	// Salida de datos
	printf("\nEl numero %d en binario es: ",num);
	for(r=m;r>=0;r--){
		printf("%d", vecm[r]);
	}
	
	printf("\nSu complemento a 1 es: ");
	for(r=0;r<=m;r++){
		printf("%d", vecs[r]);
	}
	

}

// Metodo para calcular el complemento a 2
void a2(){
	// Captura de Datos
	printf("Teclee el numero a complementar: ");
	scanf("%d", &num);
	m=0;
	// Se obtienen las direcciones de memoria donde se almacenaran los valores binarios
	vecm=(int*) calloc(1, sizeof(int));
	// Se transforma el numereo introducido en binario
	bin(num);
	vecs = (int*) calloc((m+1), sizeof(int));
	t=0;
	
	
	// Se "invierten" los digitos del binario
	for(r=m;r>=0;r--){
		if(vecm[r]==0){
			vecs[r]=1;
		}
		else{
			vecs[r]=0;
		}
	}
	
	// Se busca el valor en decimal del complemento
	resul=0;
	for(r=0;r<=m;r++){
		if(vecs[r]==1){
			resul=resul+pow(2,r);
		}
	}
	
	// Impresión del numero en binario
	printf("\nEl numero %d en binario es: ",num);
	for(r=m;r>=0;r--){
		printf("%d", vecm[r]);
	}
	// Se suma 1 al valor del complemento
	resul=resul+1;
	m=0;
	
	vecm=(int*) calloc(1, sizeof(int));
	// Se regresa el complemento a binario
	bin(resul);
	vecs = (int*) calloc((m+1), sizeof(int));
	t=0;
	
	// Impresión del complemento a 2 al final del proceso
	printf("\nSu complemento a 2 es: ");
	for(r=m;r>=0;r--){
		printf("%d", vecm[r]);
	}
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
