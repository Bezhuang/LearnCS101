package com.alibaba;

public class TestArray {

	public static void main(String[] args) {
		// ������ϰ
		// 1.�������� ����5���������͵�����
		int[] array1 = new int[5];
		array1[0] = 88;
		array1[1] = 1;
		array1[2] = 32;
		array1[3] = 45;
		array1[4] = 67;
		// 2.������������Ԫ�صĺ�
		int sum = 0;
		for (int i = 0; i < array1.length; i++) {
			System.out.println(array1[i]);
			sum = sum + array1[i];
		}
		System.out.println("����ĺͣ�" + sum);
		// 3.�ַ�������
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
