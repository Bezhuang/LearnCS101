package com.alibaba;
//阿里Java训练营练习
public class Test {
	//代码执行入口点
	public static void main(String[] args) {
		//1.打印字符串
		System.out.println("Hello World");
		//2.整数变量18岁
		int age = 18;
		System.out.println(age);
		//3.打印字符串：训练营
		String s1 = "阿里巴巴Java训练营";
		System.out.println(s1);
		//4.8大基本类型
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
		
		//5.测试面向对象
		Order order = new Order();//创建对象，实例化
		order.title="Iphone 12";
		order.price=8888;
		order.address="阿里巴巴杭州";
		//调用行为，功能
		order.print();
	}
}
