#pragma once

//1.统计一个数二进制中的1的个数。
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

//2.那么你知道两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同么？ 
//输入例子:
//1999 2299
//输出例子:
//6
int func2(int m,int n)
{
	//求出m和n中不同的位
	int ret=m^n;
	//统计
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
	cout<<"1999和2999中"<<func2(1999,2999)<<"个不同的位"<<endl;
}

//3.判断一个数是不是2的n次方。
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

//4.写一个宏定义，实现的功能是将一个int型的数的奇偶位互换，例如6的
//  2进制为0110， 第一位与第二位互换，第三位与第四位互换，得到1001，
//  输出应该为9 .
#define SWAP(X) (((X)&0x55555555)<<1)|(((X)&0xaaaaaaaa)>>1)
void test4()
{
	int c=SWAP(6);
	cout<<"6的奇偶位交换为"<<c<<endl;
}


//5.将一个数的二进制序列逆序，然后输出逆序之后的二进制序所对应的数。
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

//6.编写一个函数，这个函数可以将一个整数的指定位置1或者置0；
//10        ：0000 0000 0000 0000 0000 0000 0000 1010
//第五位置一：0000 0000 0000 0000 0000 0000 0001 0000 相或
//—————————————————————————————
//26
//             num|(1<<4)
//第四位置零：1111 1111 1111 1111 1111 1111 1111 01111 相与
//—————————————————————————————
//2
//            num&(~(1<<3))
void SetSepecPos(int *num,int pos,bool flag)
{
	if(flag)//置一
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


//7.给一组数，只有一个数只出现了一次，其他所有数都是成对出现的。
//  怎么找出这个数。
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

//8.给一组数，只有两个数只出现了一次，其他所有数都是成对出现的。
//  怎么找出这两个数。
void func8(int a[],int size,int *ret1,int *ret2)
{
	//1、求出那两个数的异或结果，确定有几个位是不同的，按照其中一位进行分组
	int ret=0;
	for(int i=0;i<size;i++)
	{
		ret^=a[i];
	}
	//得到第一个位为1的
	int pos=ret&~(ret-1);
	//进行分组并得到两个数
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
//9.给一组数，只有三个个数只出现了一次，其他所有数都是成对出现的。
//  怎么找出这三个数
int findonebit(int num)
{
	return num&~(num-1);
}
void func9(int a[],int size,int *ret1,int *ret2,int *ret3)
{
	//1、求出那两个数的异或结果，确定有几个位是不同的，按照其中一位进行分组
	int xor=0;
	for(int i=0;i<size;i++)
	{
		xor^=a[i];
	}
	//xor=a^b^c
	//a^xor=b^c;b^xor=a^c;c^xor=a^b;
	//(a^xor)^(b^xor)^(c^xor)=0
	//所以一定是有某些位上任意两个是相同的，一个是不同的，且不同的那个为0 011 101 110
	//进行分组并得到两个数
	int bit=0;
	for(int i=0;i<size;i++)
	{
		//xor^a=A xor^b=B xor^c=C
		bit^=findonebit(xor^a[i]);
	}
	//最低为为1的那位---一定是a，b，c中的一个
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