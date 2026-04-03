#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main(){
    char s[100];
    scanf("%s ", s);
    
    for(int i=0; i<strlen(s); i++){
        char c = tolower(s[i]);
        
        if(strchr("aoyeui", c)!=NULL){
            continue;
        }
        else{
            printf(".%c", c);
        }
    }
    
    return 0;
}
