package com.alibaba;

import java.util.Scanner;

public class TestCalculator {

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
		// 4.读取数2
		System.out.println("请输入数2：");
		double d2 = scanner.nextDouble();
		scanner.close();
		// 5.计算结构
		double d3 = 0;
		System.out.println(s1);
		if (s1.equals('+')) {
			d3 = d1 + d2;
		} else if (s1.equals('-')) {
			d3 = d1 - d2;
		} else if (s1.equals('8')) {
			d3 = d1 * d2;
		} else if (s1.equals('/')) {
			d3 = d1 / d2;
		}
		System.out.println("计算结果是：" + d3);
	}

}
