#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int reg[8]={0};
int mem[16]={0};
int equal=0,less=0;//condition code
int dest[10]={0};  //jump destination
FILE *fp;

void addq(char *operand1,char *operand2);
void subq(char *operand1,char *operand2);
void cmpq(char *operand1,char *operand2);
void je(char *operand1);
void jne(char *operand1);
void jg(char *operand1);
void jl(char *operand1);
void rrmovq(char *operand1,char *operand2);
void irmovq(char *operand1,char *operand2);
void rmmovq(char *operand1,char *operand2);
void mrmovq(char *operand1,char *operand2);
double return_int(char *operand);  //change the read characters to integers
int find_address(char *operand);   //find the memory address
char *ltrim(char *str);            //delete the spaces at the beginning
char *del_tag(char *str);          //delete L tag at the beginning of instruction
char *format(char *str,char *instruction,char *operand1, char *operand2);  //assign instruction, operand1, operand2

int main(int argc,char *argv[]) 
{  
    char temp[256];
    char instruction[256]="",operand1[256]="",operand2[256]="";
    int count=0;
    fp=fopen(argv[1],"r");
    while (fgets(temp,255,fp))  //record each tag's position
    {
        if(temp[0]=='L'){
           if(dest[temp[1]-'0']==0)
              dest[temp[1]-'0']=count;
        }
        count++;
    }
    count=0;
    
    fp=fopen(argv[1],"r");
    while(fgets(temp, 255, fp))
    {
        ltrim(temp); //delete the spaces before the instruction
    
        if(temp[0]=='L'){
           if(dest[temp[1]-'0']==0)
              dest[temp[1]-'0']=count;
           del_tag(temp);
        }//if temp begin with Ln，the delete the tag
        
        int tempLength = strlen(temp);
        char *tempCopy = (char*) calloc(tempLength+1,sizeof(char));
        temp[tempLength]='\0';
        strcpy(tempCopy,temp);
        format(tempCopy,instruction,operand1,operand2);

        if (strcmp(instruction, "halt") == 0) break;
        
        if(strcmp(instruction, "addq")==0) addq(operand1,operand2);
        if(strcmp(instruction, "subq")==0) subq(operand1,operand2);
        if(strcmp(instruction, "cmpq")==0) cmpq(operand1,operand2);
        if(strcmp(instruction, "je")==0) je(operand1);
        if(strcmp(instruction, "jne")==0) jne(operand1);
        if(strcmp(instruction, "jg")==0) jg(operand1);
        if(strcmp(instruction, "jl")==0) jl(operand1);
        if(strcmp(instruction, "rrmovq")==0) rrmovq(operand1,operand2);
        if(strcmp(instruction, "irmovq")==0) irmovq(operand1,operand2);
        if(strcmp(instruction, "rmmovq")==0) rmmovq(operand1,operand2);
        if(strcmp(instruction, "mrmovq")==0) mrmovq(operand1,operand2);       

        count++;
    } 
    printf("%%r0..7: ");
    for(int i=0;i<8;i++)
    {
        printf("%d ",reg[i]);
    }
    printf("\n");

    printf("M0..15: ");
    for(int i=0;i<16;i++)
    {
        printf("%d ",mem[i]);
    } 
    printf("\n");

    return 0;
}

char *ltrim(char *str)
{
    int len = 0;
	char *p = str;
	while (*p != '\0' && isspace(*p))
	{
		++p;
		++len;
	}
	memmove(str, p, strlen(str) - len + 1);
	return str;
}

char *del_tag(char *str){
    int j=0,k=0;
    for(j=4,k=0;str[j]!='\0'; j++)
        str[k++]=str[j];
    str[k]='\0';
    return str;
}

char *format(char *str,char *instruction,char *operand1, char *operand2)
{
    int len;
    char *str_p=str;
    char copy[256];
    sscanf(str,"%s",instruction);
    len=strlen(instruction);
    memmove(operand1,str_p+len, strlen(str) - len + 1);

    for(int i=0,j=0;i<strlen(operand1);i++)
    {
        if(operand1[i]!=' ')
        {
            copy[j]=operand1[i];
            j++;
        }
    }
    
    sscanf(copy,"%[^,],%s",operand1,operand2);
}
void addq(char *operand1,char *operand2){
    reg[operand2[2]-'0']+=reg[operand1[2]-'0'];     
}

void subq(char *operand1,char *operand2){
    reg[operand2[2]-'0']-=reg[operand1[2]-'0'];       
}

void cmpq(char *operand1,char *operand2){
    int diff=0;
    diff=reg[operand2[2]-'0']-reg[operand1[2]-'0'];
    if(diff==0) {equal=1;less=0;}
    else{
        equal=0;
        if(diff>0) less=0;
        else less=1;
    }
}

void je(char *operand1){
    if(equal==1&&less==0)
    {
        int d=0;char buf[256];
        d=operand1[1]-'0';
        fseek(fp, 0, SEEK_SET);
        for(int i=0;i<dest[d];i++)
           fgets(buf,255,fp);
    }
}

void jne(char *operand1){
    if(equal==0)
    {
        int d=0;char buf[256];
        d=operand1[1]-'0';
        fseek(fp, 0, SEEK_SET);
        for(int i=0;i<dest[d];i++)
           fgets(buf,255,fp);
    }
}

void jg(char *operand1){
    if(equal==0&&less==0)
    {
        int d=0;char buf[256];
        d=operand1[1]-'0';
        fseek(fp, 0, SEEK_SET);
        for(int i=0;i<dest[d];i++)
           fgets(buf,255,fp);
    }
}

void jl(char *operand1){
    if(equal==0&&less==1)
    {
        int d=0;char buf[256];
        d=operand1[1]-'0';
        fseek(fp, 0, SEEK_SET);
        for(int i=0;i<dest[d];i++)
           fgets(buf,255,fp);
    }
}

void rrmovq(char *operand1,char *operand2){
    reg[operand2[2]-'0']=reg[operand1[2]-'0'];
}

void irmovq(char *operand1,char *operand2){
    reg[operand2[2]-'0']=return_int(operand1);
}

void rmmovq(char *operand1,char *operand2){
    mem[find_address(operand2)]=reg[operand1[2]-'0'];
}

void mrmovq(char *operand1,char *operand2){
    reg[operand2[2]-'0']=mem[find_address(operand1)];
}

double return_int(char *operand)
{
    int j=0,k=0;
    for(j=0,k=0; operand[j]!='\0'; j++)
        if(operand[j]!='%'&&operand[j]!='$'&&operand[j]!=',')
            operand[k++]=operand[j];
        operand[k]='\0';
    return atoi(operand);
}

int find_address(char *operand)
{
    int address=0,r=0;
    char imm[256];
    for(int i=0;operand[i]!='\0';i++)
    {
        if(operand[i]!='('&&operand[i]!=')'&&operand[i]!='%')
        {
            if(i-1>0&&operand[i-1]=='r')
                {r=operand[i]-'0';break;}
            else imm[i]=operand[i];
        }
    }
    address=atoi(imm)+reg[r];
    return address;
    
}
//END
