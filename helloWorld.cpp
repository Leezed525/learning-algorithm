#include <stdio.h>

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
//    float c, f;
//    scanf("%f", &c);
//    f = c * 1.8 + 32;
//    printf("%.2f\n", f);
//    return 0;
//    int x, y, r, m;
//    printf("x = %d, y = %d\n", x, y);
//    printf("r = %d, m = %d\n", r, m);
//    scanf("%d%d", &x, &y);
//    if (x < y)
//        m = y;
//    y = x;
//    printf("init m = %d\n", m);
//    x = m;
//
//    printf("init r = %d\n", r);
//    while (r != 0) {
//        r = x % y;
//        x = y;
//        y = r;
//    }
//    printf("%d\n", x);
    printf("ÄãºÃÊÀ½ç\n");
    return 0;
}