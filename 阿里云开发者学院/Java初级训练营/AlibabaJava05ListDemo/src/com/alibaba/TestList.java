package com.alibaba;

import java.util.List;
import java.util.ArrayList;

public class TestList {

	public static void main(String[] args) {
		// 1.�½���һ������List���洢����Ԫ��
		List<Integer> listNum = new ArrayList<Integer>();
		listNum.add(12);
		listNum.add(13);
		listNum.add(4);
		listNum.add(65);
		listNum.add(78);
		// 2.��͡������б�
		int sum = 0;
		for (Integer num : listNum) {
			System.out.println(num);
			sum = sum + num;
		}
		System.out.println("��ͽ����" + sum);
		// 3.�½���һ������List���洢StringԪ��
		List<String> listNum2 = new ArrayList<String>();
		listNum2.add("Java");
		listNum2.add("C");
		listNum2.add("C++");
		listNum2.add("Python");
		listNum2.add("MySQL");
		// 4.��͡������б�
		String sum2 = "";
		for (String num2 : listNum2) {
			System.out.println(num2);
			sum2 = sum2 + num2;
		}
		System.out.println("��ͽ����" + sum2);
	}
}
