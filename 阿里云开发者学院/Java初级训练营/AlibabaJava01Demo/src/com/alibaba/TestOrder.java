package com.alibaba;

public class TestOrder {

	public static void main(String[] args) {
		//5.�����������
		Order order = new Order();//��������ʵ����
		order.title="Iphone 12";
		order.price=8888;
		order.address="����Ͱͺ���";
		//������Ϊ������
		order.print();
		//6.����TaobaoOrder
		TaoBaoOrder taoBaoOrder = new TaoBaoOrder();
		taoBaoOrder.title = "��˼�ϵĶ���";
		taoBaoOrder.address = "�Ϻ�";
		taoBaoOrder.mobile = "188888888";
		taoBaoOrder.seller = "��è�콢��";
		taoBaoOrder.buyer = "��˼��";
		taoBaoOrder.price = 8888;
		taoBaoOrder.pricelist = new double[] {88,77,888888.88};
		//������Ϊ������.ͬ������Ϊ����ͬ��ʵ�֡�
		taoBaoOrder.print();
		taoBaoOrder.print(1);
		taoBaoOrder.print(9);
	}

}
