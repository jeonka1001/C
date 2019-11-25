//
//  main.c
//  HW37_20190710
//
//  Created by 전경안 on 10/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
#define x 10//행의수
#define y 10//열의수

int main() {
    int i,j,num;
    for(i=0;i<x;i++){
        
        for(j=1;j<=y;j++){
            
            num=(i*x)+j;
            
            if(num%3!=0&&num%5!=0){
                printf("%3d",num);
            }
            else if(num%3==0&&num%5!=0){
                printf("%3c",'*');
            }
            else if(num%3!=0&&num%5==0){
                printf("%3c",'#');
            }
            else{
                printf("%3d",num);
            }
            
        }
        printf("\n");
    }
    
    return 0;
}
