package com.alibaba;

import java.util.Scanner;

public class TestCalculator2 {

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
		char c1 = s1.charAt(0);   //ȡ�ַ����ĵ�0��Ԫ��
		// 4.��ȡ��2
		System.out.println("��������2��");
		double d2 = scanner.nextDouble();
		scanner.close();
		// 5.����ṹ
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
		System.out.println("�������ǣ�" + d3);
	}

}
