#include <stdio.h>
#include <stdbool.h>

unsigned char xs[4]={0};
bool mio[32]={0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1};
void bitarrayTo4byte(unsigned char *, bool[]);

void bitarrayTo4byte(unsigned char*c, bool b[32])
{
    int i=0,k=0;    
    
     for (i=0; i < 8; ++i)
        if (b[i])
            c[0] |= 1 << i;
            
    for (k=1;k<4;k++)
     for (i=8*k; i < 8*(k+1); ++i)
        if (b[i])
            c[k] |= 1 << i%(8*k);
    
   /* 
    //old version!
    int i=0;
        for (i=0; i < 8; ++i)
        if (b[i])
            c[0] |= 1 << i;
            
        for (i=8; i < 16; ++i)
        if (b[i])
            c[1] |= 1 << i%8;
            
        for (i=16; i < 24; ++i)
        if (b[i])
            c[2] |= 1 << i%16;
        
        for (i=24; i < 32; ++i)
        if (b[i])
            c[3] |= 1 << i%24;
            
            */
}





int main(void){
    printf("%d %d %d %d \t",xs[3],xs[2],xs[1],xs[0]);
    bitarrayTo4byte(&xs[0],mio);
    printf("%d %d %d %d",xs[3],xs[2],xs[1],xs[0]);
    
    
    return 0;
}