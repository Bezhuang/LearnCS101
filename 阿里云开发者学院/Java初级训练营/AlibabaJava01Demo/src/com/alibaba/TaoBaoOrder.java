package com.alibaba;
//继承父类订单Order
public class TaoBaoOrder extends Order{
	//1.数据 变量 字段
	public String buyer; //买家
	public String seller; //卖家
	public String mobile; //手机买家
	public double[] pricelist; //多个商品价格列表
	
	//多态的一种实现，方法重载，同一个类型的同名方法
	//2.行为扩展，求和所有商品的价格。
	//父子类同名方法同名方法，重写
	public void print(int num) {
		//求和
		for (int i = 0; i < pricelist.length; i++) {
			price += pricelist[i];
		}
		//打印订单总价
		System.out.println(buyer + "的第" + num + "个订单总价:" + price);
	}
}
