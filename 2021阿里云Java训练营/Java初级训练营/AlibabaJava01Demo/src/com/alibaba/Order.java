package com.alibaba;

public class Order {
	// 1.����
	String title;// ����
	double price;// �۸�
	String address;// ��ַ

	// 2.0��Ϊ.,��ӡ����Ͷ������
	public void print() {
		System.out.println(title + " : " + price);
	}
}
