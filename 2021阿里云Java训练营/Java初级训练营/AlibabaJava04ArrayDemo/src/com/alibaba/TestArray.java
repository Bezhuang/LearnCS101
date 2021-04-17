package com.alibaba;

public class TestArray {

	public static void main(String[] args) {
		// 数组练习
		// 1.定义数组 长度5，整数类型的数组
		int[] array1 = new int[5];
		array1[0] = 88;
		array1[1] = 1;
		array1[2] = 32;
		array1[3] = 45;
		array1[4] = 67;
		// 2.求数组中所有元素的和
		int sum = 0;
		for (int i = 0; i < array1.length; i++) {
			System.out.println(array1[i]);
			sum = sum + array1[i];
		}
		System.out.println("数组的和：" + sum);
		// 3.字符串数组
		  String[] arrayName = new String[5];
		  arrayName[0] = "Java";
		  arrayName[1] = "C";
		  arrayName[2] = "C++";
		  arrayName[3] = "Python";
		  arrayName[4] = "MySQL";
		  for (int i = 0; i < arrayName.length; i++) {
		   System.out.println(arrayName[i]);
		  }
	}

}
