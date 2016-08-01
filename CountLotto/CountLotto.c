//
//  main.c
//  CountLotto
//
//  Created by Yong Hwan Ho on 2016. 7. 17..
//  Copyright © 2016년 Yong Hwan Ho. All rights reserved.
//

#include <stdio.h>

#define MAXLOTTONUM 2000
#define MINLOTTONUM 1

#define MAXLOTTOCOUNT 10
#define MINLOTTOCOUNT 1

int getCountfrom(int, int);

int maxnum=1;

int main(int argc, const char * argv[]) {
    // insert code here...
    int lottocount=1;
    int count = 0;
    int testnum = 0;
    
    printf ("Enter Number of Test: ");
    scanf("%d",&testnum);
    while (testnum-- > 0)
    {
        printf("Enter Max Number of Lotto: ");
        scanf("%d",&maxnum);
        printf("Enter Lotto Count: ");
        scanf("%d",&lottocount);
    
        count = getCountfrom(1, lottocount);
    
        printf("maxnum is %d, maxcount is %d, count is %d\n", maxnum, lottocount, count);
    }
    return 0;
}

// 10 4 -> 4
int getCountfrom(int startnum, int lottocount)
{
    int count = 0;
    
    if (lottocount == 1)
        return (maxnum - startnum + 1);
    
    while (startnum <= maxnum) {
        if (startnum*2 > maxnum)
            break;
        count += getCountfrom(startnum*2, lottocount-1);
        startnum++;
    }
    
    return count;

}