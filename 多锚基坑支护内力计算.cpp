#include<stdio.h>
#include"erfen.h"
#include"zhuceng.h"
#include"dengzhiliang.h"
#include"shanjian.h"
int main(){
	double q,r,c,a,a1,H,h1,h2,h3;
	printf("多锚基坑支护内力计算程序\n");
	printf("请设置土参数及开挖深度：\n");
	printf("地表荷载 土的重度 土内聚力 开挖面以上内摩擦角 开挖面以下内摩擦角 开挖深度\n");
	scanf("%lf %lf %lf %lf %lf %lf",&q,&r,&c,&a,&a1,&H);

    do{
    printf("请设置各层锚杆位置：\n");
    printf("第一层 第二层 第三层\n");
    scanf("%lf %lf %lf",&h1,&h2,&h3);
    erfen(q,r,c,a,H,h1,h2,h3);
    printf("\n");
    zhuceng(q,r,c,a,H,h1,h2,h3);
    printf("\n");
    dengzhi(q,r,c,a,a1,H,h1,h2,h3);
    printf("\n");
    shanjian(q,r,c,a,H,h1,h2,h3);
    printf("\n");
    printf("输入q退出，其他任意键继续...");
    getchar();
    }while(getchar()!='q');
	return 0;

}
