#include<stdio.h>
#include"erfen.h"
#include"zhuceng.h"
#include"dengzhiliang.h"
#include"shanjian.h"
int main(){
	double q,r,c,a,a1,H,h1,h2,h3;
	printf("��ê����֧�������������\n");
	printf("��������������������ȣ�\n");
	printf("�ر���� �����ض� ���ھ��� ������������Ħ���� ������������Ħ���� �������\n");
	scanf("%lf %lf %lf %lf %lf %lf",&q,&r,&c,&a,&a1,&H);

    do{
    printf("�����ø���ê��λ�ã�\n");
    printf("��һ�� �ڶ��� ������\n");
    scanf("%lf %lf %lf",&h1,&h2,&h3);
    erfen(q,r,c,a,H,h1,h2,h3);
    printf("\n");
    zhuceng(q,r,c,a,H,h1,h2,h3);
    printf("\n");
    dengzhi(q,r,c,a,a1,H,h1,h2,h3);
    printf("\n");
    shanjian(q,r,c,a,H,h1,h2,h3);
    printf("\n");
    printf("����q�˳����������������...");
    getchar();
    }while(getchar()!='q');
	return 0;

}
