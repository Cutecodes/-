#include<stdio.h>
#include<math.h>
#define PI 3.14159265
/*int main(){
	zhuceng(10.0,18.0,20.0,30.0,23.5,6.0,12.0,18.0);
	return 0;
}*/
void zhuceng(double q,double r,double c,double a,double H,double h1,double h2,double h3){
	double ka,kb,ea,eb,e,y,Rb,Rc,Rd,Rf,h,l1,l2,l3,l4,Mb,Mc,Md,Mf,H1,H2,k,E1,E2,E3;
	l1=h1;
	l2=h2-h1;
	l3=h3-h2;
	l4=H-h3;
	ka=pow(tan((45.0-a/2)/180*PI),2);
	kb=pow(tan((45.0+a/2)/180*PI),2);
	eb=ka*q;
	if(a<=15)k=0.3;
	else if(k>15 && k<=20)k=0.3-0.01*(a-15);
	else if(k>20 && k<=25)k=0.25-0.018*(a-20);
	else if(k>25 && k<=30)k=0.16-0.016*(a-25);
	else if(k>30)k=0.08-0.009*(a-30);
	if(k<0)k==0;


	H1=h2+0.5;
	ea=r*H1*ka;
	e=ea+eb;
	y=k*H1;
	Mb=eb*H1*(H1*0.5+y)+ea*H1*0.5*(H1/3+y)+e*pow(y,2)/3;
	Rb=Mb/(l2+0.5+y);
	E1=eb*H1+ea*H1*0.5+e*y*0.5;

	H2=h3+0.5;
	ea=r*H2*ka;
	e=ea+eb;
	y=k*H2;
	Mc=eb*H2*(H2*0.5+y)+ea*H2*0.5*(H2/3+y)+e*pow(y,2)/3;
	Rc=(Mc-(l2+l3+0.5+y)*Rb)/(l3+0.5+y);
	E2=eb*H2+ea*H2*0.5+e*y*0.5;

	ea=r*H*ka;
	e=ea+eb;
	y=k*H;
	Md=eb*H*(H*0.5+y)+ea*H*0.5*(H/3+y)+e*pow(y,2)/3;
	Rd=(Md-Rb*(l2+l3+l4+y)-Rc*(l3+l4+y))/(l4+y);
	E3=eb*H+ea*H*0.5+e*y*0.5;

	Rf=E3-Rb-Rc-Rd;

	Mb=ka*q*pow(l1,2)*0.5+r*ka*pow(l1,3)/6;
	Mc=ka*q*pow(l1+l2,2)*0.5+r*ka*pow(l1+l2,3)/6-Rb*l2;
    Md=ka*q*pow(l1+l2+l3,2)*0.5+r*ka*pow(l1+l2+l3,3)/6-Rb*(l2+l3)-Rc*l3;

	printf("逐层开挖支撑力不变法\n");
	printf("您输入的支撑位置为: %.3f %.3f %.3f\n",h1,h2,h3);
	printf("计算结果为：\n");
	printf("第一层锚固力 弯矩:%.3f\t%.3f\n",Rb,Mb);
	printf("第二层锚固力 弯矩:%.3f\t%.3f\n",Rc,Mc);
	printf("第三层锚固力 弯矩:%.3f\t%.3f\n",Rd,Md);



}
