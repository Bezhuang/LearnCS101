package com.alibaba;

public class Java003IFDemo {

	public static void main(String[] args) {
		// IF判断语句
		int num = 9000;
		if (num >= 10000000) {
			System.out.println("超级富豪程序员");
		} else if (num >= 1000000) {
			System.out.println("富豪程序员");
		}
		else if (num >= 100000) {
			System.out.println("中产程序员");
		}
		else if (num >= 10000) {
			System.out.println("码农");
		}
		else {
		      System.out.println("码畜");
		}
	}

}
