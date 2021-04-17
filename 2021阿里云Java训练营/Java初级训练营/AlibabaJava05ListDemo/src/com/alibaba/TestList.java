package com.alibaba;

import java.util.List;
import java.util.ArrayList;

public class TestList {

	public static void main(String[] args) {
		// 1.新建了一个对象，List，存储整数元素
		List<Integer> listNum = new ArrayList<Integer>();
		listNum.add(12);
		listNum.add(13);
		listNum.add(4);
		listNum.add(65);
		listNum.add(78);
		// 2.求和、遍历列表
		int sum = 0;
		for (Integer num : listNum) {
			System.out.println(num);
			sum = sum + num;
		}
		System.out.println("求和结果：" + sum);
		// 3.新建了一个对象，List，存储String元素
		List<String> listNum2 = new ArrayList<String>();
		listNum2.add("Java");
		listNum2.add("C");
		listNum2.add("C++");
		listNum2.add("Python");
		listNum2.add("MySQL");
		// 4.求和、遍历列表
		String sum2 = "";
		for (String num2 : listNum2) {
			System.out.println(num2);
			sum2 = sum2 + num2;
		}
		System.out.println("求和结果：" + sum2);
	}
}
