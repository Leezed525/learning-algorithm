#include<bits/stdc++.h>

int main(){

    //��ʼ�����������

    //����100������������
    for(int i = 0; i < 100; i += 1){
        srand((unsigned)time(NULL));
        
        printf("%d ", rand() % 100);
    }
}
