//compila $gcc cpf.c -o cpf

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define TRUE  1
#define FALSE 0

short validando_cpf(char *str)
{
  	short n[9];
  	int d1,d2;
  	char strdig[3],strcalc[3],strd1[2],strd2[2],dig[3],cpfinal[11];
  
  	for(short i = 0;i < 9;i++)
  	{
      		strcpy(cpfinal,str);
      		cpfinal[i+1] = '\n';
      		n[i] = atoi(&cpfinal[i]);
  	}
   
  	d1 = n[8]*2 + n[7]*3 + n[6]*4 + n[5]*5 + n[4]*6 + n[3]*7 + n[2]*8 + n[1]*9 + n[0]*10;
  	d1 = 11 - (d1 % 11);
  
  	if( d1 >= 10 ) d1 = 0;
  
  	d2 = d1*2 + n[8]*3 + n[7]*4 + n[6]*5 + n[5]*6 + n[4]*7 + n[3]*8 + n[2]*9 + n[1]*10 + n[0]*11;
  	d2 = 11 - (d2 % 11);
  
  	if(d2 >= 10) d2 = 0;
  
  	sprintf(strd1,"%d",d1);
  	sprintf(strd2,"%d",d2);
  	//printf("\nde1: %s\nde2: %s\n",strd1,strd2);
  	strcalc[0] =strd1[0];
  	strcalc[1] =strd2[0];
  	strcalc[2]='\0';
  	strdig[0] = str[9];
  	strdig[1] = str[10];
  	strdig[2] = '\0';

  	if(strcmp(strcalc,strdig) == 0)
     		return TRUE;
  	else
     		return FALSE;

  	return FALSE;
}

void gerando_cpf(int n_cpf)
{
    int i = 0;
    int r1,r2;
    char strand1[7],strand2[6], cpf_t[13];
   
    srand(time(NULL));
    do{
       do{
          do{
              r1 = rand() % 999999;
              r2 = rand() % 99999;
              sprintf(strand1,"%d",r1);
              sprintf(strand2,"%d",r2);
              strcpy(cpf_t,"");
              strcat(cpf_t,strand1);
              strcat(cpf_t,strand2);
            }while(strlen(cpf_t) != 11);
         }while( !validando_cpf(cpf_t) );
         i++;
         printf("%d = %s\n",i,cpf_t);
         //getchar();
    }while(i < n_cpf);			
}
void main(int argc,char* arg[])
{
    char num[11];
    
    if(argc > 1)
    {   
        //printf("%s",arg[0]);
  	if(strcmp(arg[1],"-v") == 0)
 	 {
    		printf("\nDigite o número do seu CPF: ");
    		scanf("%s",&num);
    		//strcpy(num,"12345678910");
   		// strcpy(num,"43494088195");
    		if(strlen(num) == 11)
    		{
    			if( validando_cpf(num) )
       		       printf("\n\n:::CPF %s Válido\n\n",num);
    			else   printf("\n\n:::CPF %s Inválido\n\n",num);
    		}
    		else printf("\n:::CPF Inválido:::\n\n");
  	}else
  	if(strcmp(arg[1],"-g") == 0)
  	{
  	     if(arg[2] == '\0'){
  	          printf("\nPasse o argumento correto.\n");
  	     }else
  	     {
     	       int n = atoi(arg[2]);
     		if(n > 0)
        	     	gerando_cpf(n);
     		else    printf("\n:::Digite um valor maior do que zero:::\n");
             }
  	}else printf("\nParâmetros incorretos\n");
    }else printf("\nPasse os argumentos -g(gerar certo número de cpfs) ou -v(validar número de cpf)\n");
}
