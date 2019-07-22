#include<stdio.h>
#include<math.h>
#define PI 3.14159265

void dengzhi(double q,double r,double c,double a,double a2,double H,double h1,double h2,double h3){
	double ka,kb,ea,eb,e,y,Rb,Rc,Rd,Rf,h,l1,l2,l3,l4,Mb,Mc,Md,Mf,Mba,Mcb,Mcd,Mdc,Mdf,Mdd,Mcc;
	l1=h1;
	l2=h2-h1;
	l3=h3-h2;
	l4=H-h3;
	ka=pow(tan((45.0-a/2)/180*PI),2);
	kb=pow(cos(a2/180*PI)/(sqrt(cos(2*a2/3/180*PI))-sqrt(sin((2*a2/3+a2)/180*PI))*sqrt(sin(a2/180*PI))),2);//公式存疑
	ea=r*H*ka;
	eb=ka*q;
	e=ea+eb;
	y=e/(r*(kb-ka));

	Mba=eb*0.5*pow(l1,2)+r*l1*ka/6*pow(l1,2);

	Mcb=(7*(eb+r*ka*h1)+8*(eb+r*h2*ka))*pow(l2,2)/120-0.5*Mba;

	Mcd=-(eb+r*ka*h2)*pow(l3,2)/12-r*ka*l3*pow(l3,2)/30;
	Mdc=(eb+r*ka*h2)*pow(l3,2)/12+r*ka*l3*pow(l3,2)/20;

	Mdf=-(eb+r*ka*h3)*pow(l4,2)/8*pow(2-l4/(l4+y),2)-r*ka*l4/24*pow(l4,2)*(8-9*l4/(l4+y)+2.4*pow(l4/(l4+y),2))-(eb+r*ka*H)*y/6*(1-0.6*pow(y/(l4+y),2));

	//分配弯矩
	Mdd=2.00;
	while(abs(Mdd)>1){
	Mdd=Mdc+Mdf;
	Mdc=Mdc-0.58*Mdd;
	Mdf=Mdf-0.42*Mdd;
	Mcd=Mcd-0.5*0.58*Mdd;

	Mcc=Mcd+Mcb;
	Mcb=Mcb-0.391*Mcc;
	Mcd=Mcd-0.609*Mcc;
	Mdc=Mdc-0.5*0.609*Mcc;
	}
	Mb=-Mba;
	Mc=Mcd;
	Md=Mdf;

	//锚固力
	Rb=(eb/2*pow(l1,2)+r*ka*h1*pow(l1,2)/3-Mb)/l1+((eb+r*ka*h1)/2*pow(l2,2)+r*ka*l2*pow(l2,2)/6+Mb+Mc)/l2;

	Rc=((eb+r*ka*h1)/2*pow(l2,2)+r*ka*l2*pow(l2,2)/3-Mb-Mc)/l2+((eb+r*ka*h2)/2*pow(l3,2)+r*ka*l3*pow(l3,2)/6+Mc+Md)/l3;

	Rd=((eb+r*ka*h2)/2*pow(l3,2)+r*ka*l3*pow(l3,2)/3-Mc-Md)/l3+((eb+r*ka*h3)*l4*(l4/2+y)+r*ka*l4*l4/2*(l4/3+y)+(eb+r*ka*H)*pow(y,2)/3-Md)/(l4+y);

	Rf=((eb+r*ka*h3)*l4*l4/2+r*ka*l4*pow(l4,2)/3+(eb+r*ka*H)*y/2*(y/3+l4))/(l4+y);
	h=sqrt(6*Rf/r/(kb-ka))+y;

	printf("等值梁法\n");
	printf("您输入的支撑位置为：%.3f %.3f %.3f\n",h1,h2,h3);
	printf("计算结果为：\n");
	printf("第一层锚固力 弯矩:%.3f\t%.3f\n",Rb,Mb);
	printf("第二层锚固力 弯矩:%.3f\t%.3f\n",Rc,Mc);
	printf("第三层锚固力 弯矩:%.3f\t%.3f\n",Rd,Md);
	//printf("0点土压力 插入深度:%.3f\t%.3f\n",Rf,h);
}
/*int main(){
	dengzhi(10.0,19.0,10.0,30.0,37.5,23.5,5.0,12.0,18.0);
	return 0;
}*/
