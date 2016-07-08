#pragma once

//1.ͳ��һ�����������е�1�ĸ�����
//int func1(int num)
//{
//	
//}
int func1(int num)
{
	int count=0;
	int flag=1;
	while(flag)
	{
		if(num&flag)
		{
			count++;
		}
		flag<<=1;
	}
	return count;
}
//int func1(int num)
//{
//	int count=0;
//	while(num)
//	{
//		count++;
//		num=num&(num-1);
//	}
//	return count;
//}
void test1()
{
	cout<<"-1"<<" "<<func1(-1)<<endl;
	cout<<"15"<<" "<<func1(15)<<endl;
}

//2.��ô��֪������int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬô�� 
//��������:
//1999 2299
//�������:
//6
int func2(int m,int n)
{
	//���m��n�в�ͬ��λ
	int ret=m^n;
	//ͳ��
	int count=0;
	while(ret)
	{
		count++;
		ret=ret&(ret-1);
	}
	return count;
}
void test2()
{
	//cout<<"1999"<<hex(1999)<<endl;
	//cout<<"2999"<<hex(2999)<<endl;
	cout<<"1999��2999��"<<func2(1999,2999)<<"����ͬ��λ"<<endl;
}

//3.�ж�һ�����ǲ���2��n�η���
bool func3(double num)
{
	int count=0;
	if(num<1)
	{
		num=1/num;
	}
	int temp=(int)num;
	while(temp)
	{
		count++;
		temp=temp&(temp-1);
	}
	if(count==1||count==0)
	{
		return true;
	} 
	return false;
	/*if(!(num&(num-1))) 
		return true;
	else
		return false;*/
}

void test3()
{
	cout<<"0.125  "<<func3(0.125)<<endl;
	cout<<"0.25  "<<func3(0.25)<<endl;
	cout<<"0.5  "<<func3(0.5)<<endl;
	cout<<"1  "<<func3(1)<<endl;
	cout<<"2  "<<func3(2)<<endl;
	cout<<"4  "<<func3(4)<<endl;
	cout<<"8  "<<func3(8)<<endl;
	cout<<"6  "<<func3(6)<<endl;
	cout<<"0  "<<func3(0)<<endl;
	cout<<"3  "<<func3(3)<<endl;
}

//4.дһ���궨�壬ʵ�ֵĹ����ǽ�һ��int�͵�������żλ����������6��
//  2����Ϊ0110�� ��һλ��ڶ�λ����������λ�����λ�������õ�1001��
//  ���Ӧ��Ϊ9 .
#define SWAP(X) (((X)&0x55555555)<<1)|(((X)&0xaaaaaaaa)>>1)
void test4()
{
	int c=SWAP(6);
	cout<<"6����żλ����Ϊ"<<c<<endl;
}


//5.��һ�����Ķ�������������Ȼ���������֮��Ķ�����������Ӧ������
//10         :0000 0000 0000 0000 0000 0000 0000 1010
//1342177280 :0101 0000 0000 0000 0000 0000 0000 0000
int func5(int num)
{
	int ret=0;
	for(int i=0;i<sizeof(num)*8;i++)
	{
	    ret=ret<<1;
		ret=ret|((num>>(i))&1);
		//ret=ret<<1;
	}
	return ret;
}
void test5()
{
	cout<<func5(10)<<endl;
}

//6.��дһ������������������Խ�һ��������ָ��λ��1������0��
//10        ��0000 0000 0000 0000 0000 0000 0000 1010
//����λ��һ��0000 0000 0000 0000 0000 0000 0001 0000 ���
//����������������������������������������������������������
//26
//             num|(1<<4)
//����λ���㣺1111 1111 1111 1111 1111 1111 1111 01111 ����
//����������������������������������������������������������
//2
//            num&(~(1<<3))
void SetSepecPos(int *num,int pos,bool flag)
{
	if(flag)//��һ
	{
		*num=*num|(1<<(pos-1));
	}
	else
	{
		*num=*num&~(1<<(pos-1));
	}
}
void test6()
{
	int num1=10;
	SetSepecPos(&num1,5,true);
	cout<<num1<<endl;
	int num2=10;
	SetSepecPos(&num2,4,false);
	cout<<num2<<endl;
}


//7.��һ������ֻ��һ����ֻ������һ�Σ��������������ǳɶԳ��ֵġ�
//  ��ô�ҳ��������
int func7(int a[],int size)
{
	int ret=0;
	for(int i=0;i<size;i++)
	{
       ret^=a[i];
	}
	return ret;
}
void test7()
{
	int a[9]={1,2,4,5,4,2,1,3,3};
	cout<<func7(a,9)<<endl;
}

//8.��һ������ֻ��������ֻ������һ�Σ��������������ǳɶԳ��ֵġ�
//  ��ô�ҳ�����������
void func8(int a[],int size,int *ret1,int *ret2)
{
	//1����������������������ȷ���м���λ�ǲ�ͬ�ģ���������һλ���з���
	int ret=0;
	for(int i=0;i<size;i++)
	{
		ret^=a[i];
	}
	//�õ���һ��λΪ1��
	int pos=ret&~(ret-1);
	//���з��鲢�õ�������
	for(int i=0;i<size;i++)
	{
		if(a[i]&pos)
		{
			*ret1^=a[i];
		}
	}
	*ret2=ret^*ret1;
}
void test8()
{
	int a[10]={1,2,4,5,4,2,1,3,3,6};
	int ret1=0;
	int ret2=0;
	func8(a,10,&ret1,&ret2);
	cout<<ret1<<" "<<ret2<<endl;
}
//9.��һ������ֻ����������ֻ������һ�Σ��������������ǳɶԳ��ֵġ�
//  ��ô�ҳ���������
int findonebit(int num)
{
	return num&~(num-1);
}
void func9(int a[],int size,int *ret1,int *ret2,int *ret3)
{
	//1����������������������ȷ���м���λ�ǲ�ͬ�ģ���������һλ���з���
	int xor=0;
	for(int i=0;i<size;i++)
	{
		xor^=a[i];
	}
	//xor=a^b^c
	//a^xor=b^c;b^xor=a^c;c^xor=a^b;
	//(a^xor)^(b^xor)^(c^xor)=0
	//����һ������ĳЩλ��������������ͬ�ģ�һ���ǲ�ͬ�ģ��Ҳ�ͬ���Ǹ�Ϊ0 011 101 110
	//���з��鲢�õ�������
	int bit=0;
	for(int i=0;i<size;i++)
	{
		//xor^a=A xor^b=B xor^c=C
		bit^=findonebit(xor^a[i]);
	}
	//���ΪΪ1����λ---һ����a��b��c�е�һ��
	bit=findonebit(bit);
	for(int i=0;i<size;i++)
	{
		if(findonebit(xor^a[i])==bit)
		{
			*ret1^=a[i];
		}
	}
	for(int i=0;i<size;i++)
	{
		if(*ret1==a[i])
		{
			swap(a[size-1],*ret1);
		}
	}
	func8(a,size-1,ret2,ret3);
	
}
void test9()
{
	int a[11]={1,2,4,5,4,2,1,3,3,6,7};
	int ret1=0;
	int ret2=0;
	int ret3=0;
	func9(a,11,&ret1,&ret2,&ret3);
	cout<<ret1<<" "<<ret2<<" "<<ret3<<endl;
}