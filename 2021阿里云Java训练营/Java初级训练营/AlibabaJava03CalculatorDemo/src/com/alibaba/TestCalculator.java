package com.alibaba;

import java.util.Scanner;

public class TestCalculator {

	public static void main(String[] args) {
		// 1.���������ݵļ�����
		System.out.println("��ӭʹ��Java������");
		System.out.println("��������1��");
		// 2.��ȡ��1
		Scanner scanner = new Scanner(System.in);
		double d1 = scanner.nextDouble();
		// 3.�û�����Ӽ��˳�����
		System.out.println("������������ţ�+-*/��֮һ��");
		String s1 = scanner.next();
		// 4.��ȡ��2
		System.out.println("��������2��");
		double d2 = scanner.nextDouble();
		scanner.close();
		// 5.����ṹ
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
		System.out.println("�������ǣ�" + d3);
	}

}
