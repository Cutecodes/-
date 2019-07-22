#include<stdio.h>
#include<math.h>
#define PI 3.14159265
/*int main(){
	erfen(10.0,19.0,10.0,30.0,23.5,5.0,12.0,18.0);
	return 0;
}*/
void erfen(double q,double r,double c,double a,double H,double h1,double h2,double h3){
	double ka,kb,ea,eb,e,y,Rb,Rc,Rd,Rf,h,l1,l2,l3,l4,Mb,Mc,Md,Mf;
	l1=h1;
	l2=h2-h1;
	l3=h3-h2;
	l4=H-h3;
	ka=pow(tan((45.0-a/2)/180*PI),2);
	kb=pow(tan((45.0+a/2)/180*PI),2);
	ea=0.25*r*H*ka;
	eb=ka*q;
	e=ea+eb;
	y=e/(r*(kb-ka));
	Rb=(0.25*H*(ka*q+e))/2+(l2/2+l1-0.25*H)*e;
	Rc=e*(l2+l3)/2;
	Rd=e*(l3+l4)/2;
	Rf=e*l4/2+y*e/2;
	h=sqrt(6*Rf/r/(kb-ka));
	Mb=0.5*eb*pow(l1,2)+2*ea*pow(l1,3)/3/H;
	Mc=0.5*e*pow(h2,2)-0.125*ea*H*(h2-H/12)-Rb*l2;
	Md=0.5*e*pow(h3,2)-0.125*ea*H*(h3-H/12)-Rb*(l2+l3)-Rc*l3;
	Mf=0.5*e*pow(H+y,2)-0.125*ea*H*(11*H/12+y)-e*pow(y,2)/6-Rb*(H-h1+y)-Rc*(H-h2+y)-Rd*(H-h3+y);
	printf("二分之一分担法\n");
	printf("您输入的支撑位置为：%.3f %.3f %.3f\n",h1,h2,h3);
	printf("计算结果为：\n");
	printf("第一层锚固力 弯矩:%.3f\t%.3f\n",Rb,Mb);
	printf("第二层锚固力 弯矩:%.3f\t%.3f\n",Rc,Mc);
	printf("第三层锚固力 弯矩:%.3f\t%.3f\n",Rd,Md);
	//printf("0点土压力 插入深度:%.3f\t%.3f\n",Rf,h);
    //printf("插入深度:%.3f\n",h);


}
