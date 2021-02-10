package com.alibaba;

import java.util.Scanner;

public class TestCalculator2 {

	public static void main(String[] args) {
		// 1.带输入数据的计算器
		System.out.println("欢迎使用Java计算器");
		System.out.println("请输入数1：");
		// 2.读取数1
		Scanner scanner = new Scanner(System.in);
		double d1 = scanner.nextDouble();
		// 3.用户输入加减乘除符号
		System.out.println("请输入运算符号（+-*/）之一：");
		String s1 = scanner.next();
		char c1 = s1.charAt(0);   //取字符串的第0个元素
		// 4.读取数2
		System.out.println("请输入数2：");
		double d2 = scanner.nextDouble();
		scanner.close();
		// 5.计算结构
		double d3 = 0;
		System.out.println(s1);
		if (c1 == '+') {
			d3 = d1 + d2;
		} else if (c1 == '-') {
			d3 = d1 - d2;
		} else if (c1 == '*') {
			d3 = d1 * d2;
		} else if (c1 == '/') {
			d3 = d1 / d2;
		}
		System.out.println("计算结果是：" + d3);
	}

}
