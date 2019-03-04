#include<stdio.h>
#include<math.h>
#define m 0.0000000001
#define pi 3.14159265
double qm(double x, int p) {//p��x�΃�ָ��
	int i = 1;
	double r = 1.0;
	while (i <= p) {
		r = r*x;
		i++;
	}
	return r;
}
int jc(int i) {//�����v�����A�\��Ӌ�㤹�롡I���A��
	int n = 1;
	while (i) {
		n = n*i;
		i--;
	}
	return n;
}

double jd(double x) {
	double r;
	if (x > 0.000000000001)
		r = x;
	else
		r = -x;
	return r;
}
double qgen(double a, int n) {
	double y, f, x = 1, g;
	do
	{
		y = x;
		f = qm(x, n) - a;
		g = n*qm(x, n - 1);
		x = y - f / g;
	} while (jd(x - y) >= m);
	return x;
}

double qarctan(double x) {
	double r = 0.0;//�Y������
	int i = 50;//��`�׻���max
	int s = 1;//��ؓ��䤨��
	int p = 1;//��ָ��
	int ds = 1;
	long double t = 1.0;//�v����Ӌ���ä���

	while (i) {

		t = qm(x, p) / ds;
		//printf("%lf", t);
		t = t*s;
		r += t;
		p += 2;
		i--;
		ds += 2;
		s = s*-1;



	}
	return r;
}
double qsin(double x) {
	double r = 0.0;//�Y������
	int i = 6;//��`�׻���
	int s = 1;//��ؓ��䤨��
	int p = 1;//��ָ��
	long double t;//�v����Ӌ���ä���
	while (x >= pi) {
		x = x - 2 * pi;
	}
	while (i) {
		t = qm(x, p) / jc(p);
		if (t >= 0.000001 || t<-0.000001) {
			t = t*s;
			r += t;
			p += 2;
			i--;
			s = s*-1;
		}
		else {
			break;
		}
	}
	return r;
}

double qcos(double x) {
	double r = 0.0;//�Y������
	int i = 6;//��`�׻���max
	int s = -1;//��ؓ��䤨��
	int p = 2;//��ָ��
	long double t;//�v����Ӌ���ä���
	while (x >= pi) {
		x = x - 2 * pi;
	}
	while (i) {
		t = qm(x, p) / jc(p);
		if (t >= 0.000001 || t<-0.000001) {//��������
			t = t*s;
			r += t;
			p += 2;
			i--;
			s = s*-1;
		}
		else {
			break;
		}
	}
	return 1 + r;
}
void qgenhao(double a, double b, int n) {
	double r1, r2, r3, g;
	g = a*a + b*b;
	r1 = qgen(qgen(g, 2), n);
	//printf("%lf %f",g, r1);
	for (int k = 0; k <= n - 1; k++) {
		r2 = qcos((atan(b / a) + 2 * k*pi) / n);
		r3 = qsin((atan(b / a) + 2 * k*pi) / n);
		r2 *= r1;
		r3 *= r1;
		if (r3 > 0.0) {
			printf("�Y��%d :   %lf + %lf i\n", k + 1, r2, r3);
		}
		else
		{
			printf("�Y��%d :   %lf  %lf i\n", k + 1, r2, r3);
		}
		//printf("%lf", b);
	}



}

int main()
{
	double a, b;
	int n;
	char si, s2;
	printf("z���������Ƥ������� eg: 1.2 + 2.4 i\n");
	scanf("%lf %c %lf %c", &a, &si, &b, &s2);
	if (a == 0.0 || b == 0.0)
		printf("�}��������ʤ�");
	switch (si) {
	case'+':
		b = b;
		break;
	case'-':
		b = b*-1;
		break;
	default:printf("�����`���ޤ�");
	}
	printf("�_������n���������Ƥ�������\n");
	scanf("%d", &n);
	qgenhao(a, b, n);

	double rpi;
	rpi = (qarctan(1.0 / 2.0) + qarctan(1.0 / 3.0)) * 4;
	//printf("pi��: %lf", rpi);


	return 0;
}