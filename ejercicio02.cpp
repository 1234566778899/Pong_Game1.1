#include<iostream>
using namespace std;
int menor(int a){
	int min=999;
	while(a<min){
		min=a;
	}
	return min;
}
int mayor(int a,int b,int c,int d){
	int max=0;
	if(a>max)
	max=a;
	else if(b>max)
	max=b;
	else if(c>max)
	max=c;
	else
	max=d;
	return max;
}
int main(){
	int edad,min;
	char apli,gen,eco;
	int i=0,p=0,s=0,max,x;
	float j=0,c1=0,c2=0;
	int A=0,B=0,C=0,D=0;
	setlocale(LC_ALL, "spanish");
	while(1){
do{

cout<<"Ingrese su edad: ";cin>>edad;
}while(!((edad>=18&&edad<=75)||(edad==-1)));
if(edad==-1)
break;
do{
cout<<"Aplicación debe ser (O: obligatoria; V: voluntaria): ";cin>>apli;
}while(!(apli=='O'||apli=='o'||apli=='V'||apli=='v'));
switch(apli){
	case 'O':
		case'o':
		c1++;
	break;
	case 'V':
		case 'v':
		c2++;
	break;
}
j++;
do{
cout<<"Genero (F: femenino; M: masculino): ";cin>>gen;
}while(!(gen=='F'||gen=='f'||gen=='M'||gen=='m'));
switch(gen){
	case'F':
		case 'f':
		if(apli=='V')
	min=menor(edad);
	break;
	case 'M':
		case 'm':
	s=s+edad;
	i++;
	break;
}
do{
cout<<"Nivel socio económico (A, B, C, D): ";cin>>eco;
}while(!(eco=='A'||eco=='a'||eco=='B'||eco=='b'||eco=='C'||eco=='c'||eco=='D'||eco=='d'));
switch(eco){
	case 'A':
		case 'a':
		A++;
	break;
	case 'B':
		case 'b':
		B++;
	break;
	case 'C':
		case 'c':
		C++;
	break;
	case 'D':
		case 'd':
		D++;
	break;
}

}
  max=mayor(A,B,C,D);
  if(max=A)
  x=65;
  else if(max==B)
  x=66;
  else if(max==C)
  x=67;
  else
  x=68;
  

cout<<"***RESULTADOS***"<<endl<<endl;
cout<<"Porcentaje que se vacunarían voluntariamente: "<<(c2/j)*100<<endl;
cout<<"Porcentaje que se vacunarían obligatoriamente.: "<<(c1/j)*100<<endl;
cout<<"¿Cuál es el promedio de edad de los hombres encuestados?: "<<(s/i)<<endl;
cout<<"¿Cuál es el nivel o niveles socios económicos más frecuentes entre los encuestados?: "<<char(x)<<endl;
cout<<"¿Cuál es la edad de la mujer más joven que se aplicaría la vacuna voluntariamente?: "<<min<<endl;
	return 0;
}
