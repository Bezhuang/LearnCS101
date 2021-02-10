package com.alibaba;

public class TestOrder {

	public static void main(String[] args) {
		//5.测试面向对象
		Order order = new Order();//创建对象，实例化
		order.title="Iphone 12";
		order.price=8888;
		order.address="阿里巴巴杭州";
		//调用行为，功能
		order.print();
		//6.测试TaobaoOrder
		TaoBaoOrder taoBaoOrder = new TaoBaoOrder();
		taoBaoOrder.title = "王思聪的订单";
		taoBaoOrder.address = "上海";
		taoBaoOrder.mobile = "188888888";
		taoBaoOrder.seller = "天猫旗舰店";
		taoBaoOrder.buyer = "王思聪";
		taoBaoOrder.price = 8888;
		taoBaoOrder.pricelist = new double[] {88,77,888888.88};
		//调用行为，功能.同样的行为，不同的实现。
		taoBaoOrder.print();
		taoBaoOrder.print(1);
		taoBaoOrder.print(9);
	}

}
