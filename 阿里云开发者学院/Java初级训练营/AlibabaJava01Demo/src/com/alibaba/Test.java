package com.alibaba;
//����Javaѵ��Ӫ��ϰ
public class Test {
	//����ִ����ڵ�
	public static void main(String[] args) {
		//1.��ӡ�ַ���
		System.out.println("Hello World");
		//2.��������18��
		int age = 18;
		System.out.println(age);
		//3.��ӡ�ַ�����ѵ��Ӫ
		String s1 = "����Ͱ�Javaѵ��Ӫ";
		System.out.println(s1);
		//4.8���������
		int x = 1;
		int y = 1;
		int z = x + y;
		System.out.println(z);

		double a = 111.11;
		double b = 222.22;
		double c = a - b;
		System.out.println(c);
		
		char c1 = 'a';
		char c2 = 'b';
		boolean IsOK = false;
		
		//5.�����������
		Order order = new Order();//��������ʵ����
		order.title="Iphone 12";
		order.price=8888;
		order.address="����Ͱͺ���";
		//������Ϊ������
		order.print();
	}
}
