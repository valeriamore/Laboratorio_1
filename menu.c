/* Laboratorio 1 */ 
/*Johnny Vidal - Brayn Ruiz - Valeria Moreno */

#include<stdio.h>   //Librerias.
#include<string.h>
#include<stdlib.h>
#include<math.h>   // Se incluye esta libreria para poder usar el comando 'sqrt'(raíz cuadrada) en la desviación estandar. 
#define MAX 100    //Se define el máximo número de caracteres a ingresar el arreglo.

void menu();	   // Menú donde se inicilizan las  variables de cada opción a elegir.
void ingrese_val(char n[MAX],int* ndatos, int numeros[MAX]);
void promedio(float* prom, int* ndatos, int numeros[MAX]);
void desviacion(float* prom, int* ndatos, float* desvia, int numeros[MAX]);
void maxmin(int* maximo, int* minimo,int* ndatos, int numeros[MAX]);
void mostrartodo(int numeros[MAX]);
void comparacion(char datos[MAX],char datos1[MAX]);
void salir();


int main(){
int  tecla=0,sali=0; char datos[MAX], datos1[MAX];int ndatos=0, ndatos1=0,maximo=0,minimo=0;float prom=0,desvia=0; int numeros[MAX],numeros1[MAX];

while(sali==0){   //Se inicia el ciclo while para dar inicio al programa y que este solo salga si se ingresa la op 7. 
menu();
scanf("%d",&tecla);
switch(tecla){   //se evalua una expresion que puede tomar valores distintos y segun toma el valor se dirige al caso correspondiente.
	
	case 1:   //En este caso se ingresan los valores  seguidos de ';' dados por el usuario.
	ingrese_val(datos,&ndatos,numeros);
	printf("Los datos ingresados son:%s \n",datos);
	break;

	case 2:    //En este caso se halla el promedio de los datos ingresados por el usuario y se muestra el resultado.
	promedio(&prom,&ndatos,numeros);
	break;

	case 3:    //en este caso se halla la desviacion estandar de los datos ingresados por el usuario  mostrando su resultado.
	desviacion(&prom,&ndatos,&desvia,numeros);
	break;

	case 4:  //En este caso se busca el max y min valor de los datos ingresados por el usuario y los muestra.
	maxmin(&maximo,&minimo,&ndatos,numeros);
	break;

	case 5:   //Esta opción es para ver el resultado de los anteriores casos. (promedio, desviacion, max y min).
	promedio(&prom,&ndatos,numeros);
	desviacion(&prom,&ndatos,&desvia,numeros);
	maxmin(&maximo,&minimo,&ndatos,numeros);
	mostrartodo(numeros);
	break;
	
	case 6:  //En este caso ingresa y se compara un arreglo nuevo con el anterior.
	ingrese_val(datos1,&ndatos1,numeros1);
	comparacion(datos,datos1);
	break;

	case 7:   //en este caso se  sale del menú de op.
	sali=1;
	salir();
	break;



	default:   //En caso de que el usuario ingrese un valor no válido.
	printf("Ingrese una tecla válida \n");
	break;
	}
}
}
void menu(){  //Muestra el menú de op en pantalla.

	printf("\n Menú: \n 1.Ingrese valores. \n 2.Mostrar promedio. \n 3.Mostrar desviación estándar. \n 4.Mostrar valores máximo y mínimo.\n 5.Mostrar todo. \n 6.Agregar array y comparar. \n 7.Salir \n ");

}
void ingrese_val(char t[MAX], int* ndatos, int numeros[MAX]){  //Se crea el array t y numeros  de tamaño max y el puntero ndatos.
	
        int u=0,i=0,j=0;
        int d=*ndatos;
        char paso[MAX];

	printf("Ingrese  maximo cinco valores de la siguiente manera: 1;2;3... \n");
	scanf("%s",t);


	for(i=0;i<=strlen(t)+1;i++){    /*se utiliza este ciclo for para recorrer el vector de los datos ingresados*/
	if(t[i]==';'|| t[i]=='\0'){     /*se utiliza este condicional para reconocer los ";" y aplicar la funcion atoi solo a los numeros*/
                numeros[j]=atoi(paso);	
		j++;
		for (u=0; u<MAX; u++){ //este ciclo es utilizado para convertir el vector en vacio en caso de encontrar un ';'.
		paso[u]='\0';
		}
		i++;
		u=0;
		}
	paso[u]=t[i];                 //Guardar en el array paso lo que hay en t.
	u++;
	}
	d=j;
	if (d<=5){
	*ndatos=d;}                    //Guardar en una poscición de memoria.
	else {
	printf("Error, ingrese hasta cinco datos \n");
	printf("Ingrese máximo cinco valores de la siguiente manera:1;2;3... \n");
	scanf("%s",t);
	}
	*ndatos=d;
}
void promedio(float* prom,int* ndatos, int numeros[MAX]){ // se reciben los números del case1 y calcula el promedio.
	float p=*prom;
	int i=0;
	int d=*ndatos;
	p=0;
	
	for (i=0 ; i<d; i++){          //se utiliza para tocar cada numero y almacenarlo en 'p' e ir sumando uno a uno.
	p=p+numeros[i];
	}

	p=p/d;                         //se divide sobre el numero de datos para halla el promedio.
	printf("El promedio es: %0.3f \n",p);   //se muestra el promedio.  
	*prom=p;			//Guardar en una posición de memoria.
	*ndatos=d;
}

void desviacion(float* prom,int* ndatos, float* desvia,int numeros[MAX]){ //Se  calcula la desviacion, se utiliza el promedio hallado y los numeros ingresados.
	float p=*prom;
	int d=*ndatos;
	int i=0;
	float sum=0, v=*desvia;
	v=0;

	for(i=0;i<d;i++){            //se utiliza este ciclo para recorrer el vector numeros y asignar a la variable sum.
	sum= sum + ((numeros[i]-p)*(numeros[i]-p));
	}
	sum=sum/d;                   //se divide sobre el numero de digitos.

	v = sqrt(sum);	      	    //se utiliza el comando 'sqrt' de la libreria math.h para calcular la raíz cuadrada y obtener la desviación estándar.

	printf("La desviación estandar es:%.3f \n",v);

	*desvia=v;		   //Guarda en una paosición de memoria.


}
void maxmin(int* maximo, int* minimo, int* ndatos,int numeros[MAX]){ //se utiliza para hallar el valor maximo y minimo del arreglo de numeros.
int d=*ndatos;
int i=0;
int max=*maximo;
int min=*minimo;
max=numeros[0];
min=numeros[0];

	for (i=0;i<d;i++){        //se utiliza el ciclo para recorer el array y hallar el numero maximo y minimo qu ese compara con el siguiente.
 
		if(numeros[i]>max){ //se compara el valor en la poscición i.
		max=numeros[i];

		}
		if (numeros[i]<min){//se compara el valor en la posicion i.
		min=numeros[i];
		}


	}
	printf("El valor máximo es:%d \n el valor mínimo es:%d \n",max,min);  //muestra el valor maximo y minimo.
	*maximo=max;
	*minimo=min;
	*ndatos=d;          //Guardar en una poscion de memoria.
}

void mostrartodo(int numeros[MAX]){    //Muestra e imprime  el promedio, la desviacion estandar y el valor max y min.

printf("Los números ingresados son: %ls \n",numeros);
}

void comparacion(char datos[MAX], char datos1[MAX]){ //Da la opcion de ingresar un nuevo arreglo y comparar con el anterior
int i=0;
	if (strlen(datos)==strlen(datos1)){          //verificar si los dos arreglos tienen el mismo tamaño

	for(i=0; i<strlen(datos);i++){               //Este ciclo se utiliza para recorrer el array datos y comparar posición a poscicion con el array nuevo.
		if (datos[i]<datos1[i]){
		printf("En la posición %d, el arreglo 1 es menor que el arreglo 2 \n", i);
			}
		else if(datos1[i]<datos[i]){
		printf("En la posición %d, el arreglo 1 es mayor que el arreglo 2 \n",i);
			}
		else{
		printf("En la posición %d, el arreglo 1 es igual al arreglo 2 \n",i);
			} 
		}

	}
	else {
	printf("Error, no se pueden comparar arrays de diferente tamaño");
	}

	if(strcmp(datos, datos1)==0){               //verifica si los arrays tienen el mismo valor
	printf("Los arreglos son iguales \n");
	}
	else if(strcmp(datos,datos1)<0){	   //verifica que la suma de datos tanto del array datos y array datos1  sea mayor o menor 
	printf("La suma de los valores del arreglo 1 es menor que la suma de los valores del arreglo 2 \n");
	}
	else {
	printf("La suma de los valores del arreglo 1 es mayor que la suma de los valores del arreglo 2 \n");
	}
 
}




void salir(){                                     //Fin del ciclo.

printf("Hasta luego\n");

}
