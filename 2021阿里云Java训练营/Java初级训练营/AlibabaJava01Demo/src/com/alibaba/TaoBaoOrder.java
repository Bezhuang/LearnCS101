package com.alibaba;
//�̳и��ඩ��Order
public class TaoBaoOrder extends Order{
	//1.���� ���� �ֶ�
	public String buyer; //���
	public String seller; //����
	public String mobile; //�ֻ����
	public double[] pricelist; //�����Ʒ�۸��б�
	
	//��̬��һ��ʵ�֣��������أ�ͬһ�����͵�ͬ������
	//2.��Ϊ��չ�����������Ʒ�ļ۸�
	//������ͬ������ͬ����������д
	public void print(int num) {
		//���
		for (int i = 0; i < pricelist.length; i++) {
			price += pricelist[i];
		}
		//��ӡ�����ܼ�
		System.out.println(buyer + "�ĵ�" + num + "�������ܼ�:" + price);
	}
}
