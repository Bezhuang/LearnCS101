package com.alibaba;

public class Order {
	// 1.数据
	String title;// 标题
	double price;// 价格
	String address;// 地址

	// 2.0行为.,打印标题和订单金额
	public void print() {
		System.out.println(title + " : " + price);
	}
}
