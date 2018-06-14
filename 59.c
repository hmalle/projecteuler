/*
 * Each character on a computer is assigned a unique code and the preferred 
 * standard is ASCII (American Standard Code for Information Interchange). 
 * For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.
 *
 * A modern encryption method is to take a text file, convert the bytes to 
 * ASCII, then XOR each byte with a given value, taken from a secret key. 
 * The advantage with the XOR function is that using the same encryption key 
 * on the cipher text, restores the plain text; 
 * for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.
 *
 * For unbreakable encryption, the key is the same length as the plain text 
 * message, and the key is made up of random bytes. The user would keep the 
 * encrypted message and the encryption key in different locations, and 
 * without both "halves", it is impossible to decrypt the message.
 *
 * Unfortunately, this method is impractical for most users, so the modified 
 * method is to use a password as a key. If the password is shorter than the 
 * message, which is likely, the key is repeated cyclically throughout the 
 * message. The balance for this method is using a sufficiently long password 
 * key for security, but short enough to be memorable.
 *
 * Your task has been made easy, as the encryption key consists of three lower 
 * case characters. Using cipher.txt (right click and 'Save Link/Target As...'), 
 * a file containing the encrypted ASCII codes, and the knowledge that the plain 
 * text must contain common English words, decrypt the message and find the sum 
 * of the ASCII values in the original text.
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

bool check(int *pher, int size, int p1,int p2,int p3, char *tx)
{
    char x,y,z;
    for(int a=2;a<size;a++)
    {
        x = pher[a-2]^p1;
        y = pher[a-1]^p2;
        z = pher[a]^p3;
        if(x==tx[0] && y==tx[1] && z==tx[2])
        {
            //printf("%c%c%c->%c%c%c\n",p1,p2,p3,x,y,z);
            return true;
        }
   }
   return false; 
}

void print_clear_text(int *cipher_array,int size, char*pass)
{
    int ascii_sum=0;
    for(int d=0;d<size;d++)
    {   
        ascii_sum+=cipher_array[d]^pass[d%3];
        printf("%c",cipher_array[d]^pass[d%3]);
    }
    printf("\n>>>ascii sum=%d\n", ascii_sum);
}

void crack_cipher(int *pher,int size)
{
    char *tx1="as ", *tx2=" of", *tx3="ed ", pw[4];
    for(int p1=97;p1<123;p1++)
    {
        for(int p2=97;p2<123;p2++)
        {
            for(int p3=97;p3<123;p3++)
            {
                if(check(pher,size,p1,p2,p3,tx1)&&check(pher,size,p1,p2,p3,tx2)&&check(pher,size,p1,p2,p3,tx3))
                {
                    printf(">>>Trying  password:%c%c%c\n",p1,p2,p3);
                    pw[0]=(char)p1;
                    pw[1]=(char)p2;
                    pw[2]=(char)p3;
                    pw[3]=0;
                    print_clear_text( pher,size, pw);
                }
            }
        }
    }
}

int countLetters(char * cipher_text, int len)
{
    int letters=0;
    for(int a=0;a<len;a++)
        if(cipher_text[a]==',')
            letters+=1;
    return letters+1;
}

void load_array(int *cipher_array,int sz, char* cipher_text,int len)
{
    int a,b,c=0;
    char tmp[4];
    memset(tmp,0,4);
    for(a=0;a<len;a++)
    {
        for(b=a;b-a<4;b++)
        {
            if(cipher_text[b]!=',')
                tmp[b-a]=cipher_text[b];
            else 
                break;
        }
        if(tmp[0])
        {
            //printf("%d:",atoi(tmp));
            cipher_array[c]=atoi(tmp);
            c++;
            memset(tmp,0,4);
            a=b;
        }
    }
    printf("\n");
}

void print_array(int *cipher_array, int size)
{
    for(int a=0;a<size;a++)
        printf("%d:",cipher_array[a]);
    printf("\n");
}


int main(int argc, char**argv)
{
    char * cipher_text = NULL;
    int len; 
    FILE *f = fopen("59.txt","rb");
    if(f)   
    {
        fseek(f,0,SEEK_END);
        len = ftell(f)+1;
        fseek(f, 0, SEEK_SET);
        cipher_text = malloc(len);
        if(cipher_text)
        {
            fread(cipher_text,1,len,f);
        }
        fclose(f);
    }
    //printf("%s\n",cipher_text);
    int sz=countLetters(cipher_text,len);   //count the number of actual letters.
    int cipher_array[sz];
    load_array(cipher_array,sz,cipher_text,len); 
    crack_cipher(cipher_array,sz);
}
