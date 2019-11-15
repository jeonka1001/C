//
//  main.c
//  HW8_20190628
//
//  Created by 전경안 on 28/06/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>

int main() {
    int history,literature,artistic,total;
    double average;
    printf("역사,문학,예술 점수를 입력해 주세요(,입력 필수):");
    scanf("%d,%d,%d",&history,&literature,&artistic);
    
    total = history + literature + artistic;
    average = (double)total/3;
    
    printf("총점은 %d 이고 평균은 %.2lf 입니다.\n",total,average);
    
    return 0;
}
