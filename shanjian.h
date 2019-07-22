#include<stdio.h>
#include<math.h>
#define PI 3.14159265


double sanci(double a,double b,double c,double d){
	double x1,x2,y1,y2,x,y;
	x1=0;x2=100;//在0-100的解
	y1=a*x1*x1*x1+b*x1*x1+c*x1+d;
	y2=a*x2*x2*x2+b*x2*x2+c*x2+d;
	while(abs(x2-x1)>1e-10){
	x=(x1+x2)/2;
	y=a*x*x*x+b*x*x+c*x+d;
	if(y*y1>0){
		x1=x;
		y1=y;
	}
	else{
		x2=x;
		y2=y;
	}
	}
	return x;
}
void shanjian(double q,double r,double c,double a,double H,double h1,double h2,double h3){
	double ka,kb,ea,eb,e,y,Rb,Rc,Rd,Rf,h,l1,l2,l3,l4,Mb,Mc,Md,Mf,A,B,n,h0k,h1k,h2k,h3k,xm,N1,N2,N3,k1,k2,k3,k4,p1,p2,p3;
	l1=h1;
	l2=h2-h1;
	l3=h3-h2;
	l4=H-h3;
	ka=pow(tan((45.0-a/2)/180*PI),2);
	kb=pow(tan((45.0+a/2)/180*PI),2);

	A=kb*r;
	B=2*c*sqrt(kb);

	h0k=h2;
	h1k=l2;
	n=r*(h0k+q)*ka/h0k;
	k1=A/3;
	k2=-0.5*(n*h0k-B-A*h1k);
	k3=-(n*h0k-B)*h1k;
	k4=-(0.5*n*h1k*h0k*h0k-n*pow(h0k,3)/6);
	xm=sanci(k1,k2,k3,k4);
    N1=0.5*n*h0k*h0k+n*h0k*xm-B*xm-0.5*A*xm*xm;
	Rb=N1;
    //N1=535.4;
	//第二阶段
	h0k=h3;
	h1k=l2+l3;
	h2k=l3;
	n=r*(h0k+q)*ka/h0k;
	k1=A/3;
	k2=-0.5*(n*h0k-B-A*h2k);
	k3=-(n*h0k-B)*h2k;
	k4=-(N1*h1k-h2k*N1+0.5*n*h2k*h0k*h0k-n*pow(h0k,3)/6);
	xm=sanci(k1,k2,k3,k4);
    N2=0.5*n*h0k*h0k+n*h0k*xm-B*xm-0.5*A*xm*xm-N1;
	Rc=N2;
	//N2=679.5;
	//第三阶段
	h0k=H;
	h1k=l2+l3+l4;
	h2k=l3+l4;
	h3k=l4;
	n=r*(h0k+q)*ka/h0k;
	k1=A/3;
	k2=-0.5*(n*h0k-B-A*h3k);
	k3=-(n*h0k-B)*h3k;
	k4=-(N1*h1k+N2*h2k-h3k*(N1+N2)+0.5*n*h3k*h0k*h0k-n*pow(h0k,3)/6);
	xm=sanci(k1,k2,k3,k4);
    N3=0.5*n*h0k*h0k+n*h0k*xm-B*xm-0.5*A*xm*xm-N1-N2;
	Rd=N3;

	p1=(q+r*h1)*ka-2*c*sqrt(ka);
	p2=(q+r*h2)*ka-2*c*sqrt(ka);
	p3=(q+r*h3)*ka-2*c*sqrt(ka);

	Mb=p1*h1*h1/6;
	Mc=p2*h2*h2/6-N1*l2;
	Md=p3*h3*h3/6-N1*(l2+l3)-N2*l3;

	printf("山间邦男法\n");
	printf("您输入的支撑位置为：%.3f %.3f %.3f\n",h1,h2,h3);
	printf("计算结果为：\n");
	printf("第一层锚固力 弯矩:%.3f\t%.3f\n",Rb,Mb);
	printf("第二层锚固力 弯矩:%.3f\t%.3f\n",Rc,Mc);
	printf("第三层锚固力 弯矩:%.3f\t%.3f\n",Rd,Md);


}
/*int main(){
	shanjian(10.0,18.0,20.0,30.0,23.5,6.0,12.0,18.0);
	return 0;
}*/
