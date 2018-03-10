/* Somador de numeros
 * RA: 138014
 * Nome: Ana Ting
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char *argv[]) {

	int i;
	float n, aux, sum = 0;	
	char buf[64], caux, c, flag, w;

	while((c = getchar()) != EOF){			//EOF no lugar de '\n'
		n = 0;
		flag = 0;
		memset(buf, '\0', sizeof(buf));


		if (!isalpha(c)){
			switch(c){
				case '.':
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					i = 2;
					buf[0] = '0';
					buf[1] = c;
					while(isdigit(c)){ 
						printf("\nbuf = %s \n", buf);
						caux = c;
						c = getchar();
						if(!isdigit(c)){break;}
						buf[i] = c;
						i++;
					}
					//if (flag == 1) {break;}					//se flag == 1, ocorreu algo tipo 123PARA (ou seja, dígito seguido de caractere e, portanto, inválido para a conta)
					if (c == ' '){
						sscanf(buf, "%f", &n);					//se flag == 0, significa que terminou de adicionar os digitos encontrados ao buffer, que são transformados em float pelo sscanf()
						sum = sum + n;							//a variável global soma-se ao novo número
						printf("sum = %f \n", sum);
					} else if (c == '!'){
						sscanf(buf, "%f", &aux);
						int fat = 1;
						for(int j = 1; j <= aux; j++){
							fat = fat * j;
							printf("fat = %d\n", fat);
						}
						c = getchar();
						if(c == ' '){
							sum = sum + fat;
							printf("sum fat = %f\n", sum);
						}
					}
					break;	
			}
		} else {
			while(c != ' ' && c != '\n'){
				c = getchar();
			} 
		} 
		w = c;
	}
	sscanf(buf, "%f", &n);
	sum = sum + n;
	printf("%.2f\n", sum);
  	return 0;
}
